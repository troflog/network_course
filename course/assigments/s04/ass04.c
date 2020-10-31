/*get_broadcast_address(char *ip_addr,char mask,char output_buffer);
get_ip_integer_equivalent(char *ip_address);
char *ip_address = '192.168.0.10";
*/

#include <stdio.h>
#include <stdint.h>
#define BUF_SIZE 33


int32_t get_ip_integer_equivalent(char *ip_address);
int32_t get_mask_integer_equivalent(int mask);
char *int2bin(int a, char *buffer, int buf_size);

int main() {
   char buffer[BUF_SIZE];
   buffer[BUF_SIZE - 1] = '\0';

   char ip_string[] = "128.168.0.10";

   int32_t ip_integer;
   ip_integer = get_ip_integer_equivalent(ip_string);

   int2bin(ip_integer,buffer,BUF_SIZE-1);


   printf("%s as integer=%u\n",ip_string,ip_integer);
   printf("%s as binary=%s\n",ip_string,buffer);
   return 0;
}

int32_t get_ip_integer_equivalent(char *ip_address){
    uint32_t c1,c2,c3,c4;
    uint32_t ip;
    sscanf(ip_address,"%d.%d.%d.%d",&c1,&c2,&c3,&c4);
    printf("c1=%u, c2=%u, c3=%u, c4=%u\n",c1*256*256*256,c2*256*256,c3,c4);
    ip = c4+c3*256+c2*256*256+c1*256*256*256;
    return ip;
}
// buffer must have length >= sizeof(int) + 1
// Write to the buffer backwards so that the binary representation
// is in the correct order i.e.  the LSB is on the far right
// instead of the far left of the printed string
char *int2bin(int a, char *buffer, int buf_size) {
    buffer += (buf_size - 1);

    for (int i = 31; i >= 0; i--) {
        // Ascii code for '0' is 48 and ascii
        // code for '1' is 49. So if rightmost
        // bit is 1 then (a&1) evaluates to 1 and
        // the (a & 1) + '0' will evaluate to 49
        // which evaluate to '1'
        *buffer-- = (a & 1) + '0';
        a >>= 1;
    }

    return buffer;
}

#define BUF_SIZE 33

