#include <stdio.h>      
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>

#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>

/**
 *使用ioctl获取ens33网卡的ip地址
 */

int main(){

     int sock_get_ip;  
     char ipaddr[50];  
   
     struct   sockaddr_in *sin;  
     struct   ifreq ifr_ip;     
   
     if ((sock_get_ip=socket(AF_INET, SOCK_STREAM, 0)) == -1)  
     {  
          printf("socket create failse...GetLocalIp!\n");  
          return -1;  
     }  
      
     memset(&ifr_ip, 0, sizeof(ifr_ip));     
     strncpy(ifr_ip.ifr_name, "ens33", sizeof(ifr_ip.ifr_name) - 1);     
    
     if( ioctl( sock_get_ip, SIOCGIFADDR, &ifr_ip) < 0 )     
     {     
          return -1;     
     }       
     sin = (struct sockaddr_in *)&ifr_ip.ifr_addr;     
    strcpy(ipaddr,inet_ntoa(sin->sin_addr));         
      
     printf("local ip:%s \n",ipaddr);      
     close( sock_get_ip );  

	return 0;
}
