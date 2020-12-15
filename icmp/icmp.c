
#define KBUILD_MODNAME "filter"
#include<linux/bpf.h>
#include<linux/if_ether.h>
#include<linux/ip.h>
#include<linux/in.h>
#include<linux/icmp.h>


int icmpfilter(struct xdp_md *ctx){
    bpf_trace_printk("got a icmp packet\n");

    void *data = (void *)(long) ctx->data;
    void *data_end = (void *)(long) ctx->data_end;

     struct ethhdr *eth = data;

    if((void *)eth + sizeof(*eth) <= data_end) {

        struct iphdr *ip = data + sizeof(*eth);
        if((void*) ip + sizeof(*ip) <= data_end){
            if(ip->protocol == IPPROTO_ICMP){
                struct icmphdr *icmp = (void*) ip + sizeof(*ip);
                bpf_trace_printk("ICMP PACKET INBOUND\n");
            }
        }
    }
    
}