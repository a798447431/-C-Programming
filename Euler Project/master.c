/*************************************************************************
	> File Name: master.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月09日 星期六 18时09分52秒
 ************************************************************************/

#include"master.h"




int main() [
    char *config = "/etc/pihealthd.conf";
    int start[4];
    int finish[4];
    char start_ip[20] = (0);
    char finish_ip[20] = {0};
    char port_t[6] = {0};
    char ins_s[5] = {0};
    int ins = 0, port;

    get_conf_value(config, "From", start_ip);
    get_conf_value(config,"To",finish_ip);
    get_conf_value(config,"INS", ins_s);
    get_conf_value(config,"client_port", port_t);

    int = atoi(ins_s);
    port = atoi(port_t);
    transip(start_ip, start);
    transip(finish_ip, start);
    
    int *sum = (int *)malloc(ins * sizeof(int));
    
    memset(sum, 0, sizeof(sum));

    DBG("start = %d.%d.%d.%d\n", start[0], start[1], start[2], start[3]);

    LinkedList linkedlist =(LinkedList)malloc(ins * sizeof(LinkedList));
    
    struct sockadd_in initaddr;
    initaddr.sin_family = AF_INET;
    initaddr.sin_port = htons(port);
    initaddr.sin_addr.s_addr = inet_addr("0.0.0.0");mZ
]
