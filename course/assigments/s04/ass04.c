/*get_broadcast_address(char *ip_addr,char mask,char output_buffer);
get_ip_integer_equivalent(char *ip_address);
char *ip_address = '192.168.0.10";
*/

#include <stdio.h>
#include <stdint.h>

int32_t get_ip_integer_equivalent(char *ip_address);

int main() {

   char ip_string[] = "84.214.6.76";

   int32_t ip_integer;
   ip_integer = get_ip_integer_equivalent(ip_string);

   printf("%s as integer=%d\n",ip_string,ip_integer);
   return 0;
}

int32_t get_ip_integer_equivalent(char *ip_address){
    unsigned int test;
    int32_t per;
    uint32_t c1;
    uint32_t c2;
    uint32_t c3;
    uint32_t c4;


    int32_t ip;
    sscanf(ip_address,"%d.%d.%d.%d",&c1,&c2,&c3,&c4);
    ip = c4+c3*256+c2*256*256+c1*256*256*256;
    return ip;



    return 5;
}


