#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>


int main() {
    constexpr int max_rsp = 255; // max devices returned from inquiry
    constexpr int len = 8; // inquiry timeout, x1.28 s

    char addr[19] = { 0 }; // device address
    char name[248] = { 0 }; // device name

    int dev_id = hci_get_route(nullptr);
    int sock = hci_open_dev(dev_id);

    inquiry_info ii[max_rsp * sizeof(inquiry_info)];
    int num_rsp;

    if (dev_id < 0 || sock < 0) {
        perror("opening socket");
        exit(1);
    }

    num_rsp = hci_inquiry(dev_id, len, max_rsp, nullptr, (inquiry_info**)(&ii), IREQ_CACHE_FLUSH);

    if(num_rsp < 0) {
        perror("hci_inquiry");
    }

    for (unsigned i = 0; i < (unsigned)num_rsp; ++i) {
        inquiry_info remote_info = ii[i];
        ba2str(&(remote_info.bdaddr), addr);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sock, &(remote_info.bdaddr), sizeof(name), name, 0) < 0) {
            strcpy(name, "[unknown]");
        }
        printf("%s  %s\n", addr, name);
    }

    close(sock);
    return 0;
}
