#include <stdio.h>
#include <stdlib.h>
#include <pcap.h> /* if this gives you an error try pcap/pcap.h */
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h> /* includes net/ethernet.h */
#include <netinet/tcp.h>
#include<string.h>
#include<linux/ip.h>
int t=0,ip=0;
struct sockaddr_in source,dest;
void process_packet(u_char *args,const struct pcap_pkthdr *hdr,const u_char *buffer)
{
int s=hdr->len;
struct iphdr *i=(struct iphdr *)(buffer+sizeof(struct ethhdr));
++t;
int z=i->protocol;
switch(z)
{
case 6:++ip;
       printf("\nipheaderlenght =%d",i->ihl*4);
       memset(&source,0,sizeof(struct sockaddr_in));
       source.sin_addr.s_addr=i->saddr;
       memset(&dest,0,sizeof(struct sockaddr_in));
       dest.sin_addr.s_addr=i->daddr;
       printf("\nipversion :%d",(unsigned int)i->version);
       printf("\ntypeversion :%d",(unsigned int)i->tos);
       printf("\nTTL :%d",i->ttl);
       printf("\nprotocol :%d",i->protocol);
       printf("\nchecksum :%d",ntohs(i->check));
       printf("\nsource ip:%d",inet_ntoa(source.sin_addr));
       printf("\ndestination ip:%d",inet_ntoa(dest.sin_addr));
       break;
}
printf("\ntotal packets :%d ,tcp pacs :%d",t,ip);
}


int main()
{
int i;
char errbuff[PCAP_ERRBUF_SIZE];
pcap_if_t *inter;
pcap_t *d;
struct pcap_pkthdr hdr;
struct ether_headesr *eptr;

if(pcap_findalldevs(&inter,errbuff)==-1)
{printf("\nerror:%s",errbuff);
 exit(1);
}
printf("device :%s",inter->name);

printf("net mask: %s",inter->addresses);

d=pcap_open_live(inter->name,BUFSIZ,0,100,errbuff);

if(d==NULL)
{
  printf("error while opening %s:",errbuff);
 exit(1);
}


pcap_loop(d, -1,process_packet,NULL);

return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h> /* if this gives you an error try pcap/pcap.h */
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h> /* includes net/ethernet.h */
#include <netinet/tcp.h>
#include<string.h>
#include<linux/ip.h>
int t=0,ip=0;
struct sockaddr_in source,dest;
void process_packet(u_char *args,const struct pcap_pkthdr *hdr,const u_char *buffer)
{
int s=hdr->len;
struct iphdr *i=(struct iphdr *)(buffer+sizeof(struct ethhdr));
++t;
int z=i->protocol;
switch(z)
{
case 6:++ip;
       printf("\nipheaderlenght =%d",i->ihl*4);
       memset(&source,0,sizeof(struct sockaddr_in));
       source.sin_addr.s_addr=i->saddr;
       memset(&dest,0,sizeof(struct sockaddr_in));
       dest.sin_addr.s_addr=i->daddr;
       printf("\nipversion :%d",(unsigned int)i->version);
       printf("\ntypeversion :%d",(unsigned int)i->tos);
       printf("\nTTL :%d",i->ttl);
       printf("\nprotocol :%d",i->protocol);
       printf("\nchecksum :%d",ntohs(i->check));
       printf("\nsource ip:%d",inet_ntoa(source.sin_addr));
       printf("\ndestination ip:%d",inet_ntoa(dest.sin_addr));
       break;
}
printf("\ntotal packets :%d ,tcp pacs :%d",t,ip);
}


int main()
{
int i;
char errbuff[PCAP_ERRBUF_SIZE];
pcap_if_t *inter;
pcap_t *d;
struct pcap_pkthdr hdr;
struct ether_headesr *eptr;

if(pcap_findalldevs(&inter,errbuff)==-1)
{printf("\nerror:%s",errbuff);
 exit(1);
}
printf("device :%s",inter->name);

printf("net mask: %s",inter->addresses);

d=pcap_open_live(inter->name,BUFSIZ,0,100,errbuff);

if(d==NULL)
{
  printf("error while opening %s:",errbuff);
 exit(1);
}


pcap_loop(d, -1,process_packet,NULL);

return 0;
}
