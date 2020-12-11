/*------------------------*/
/* IP ADRESS MANIUPLATION */
/*------------------------*/

/*get_broadcast_address(char *ip_addr,char mask,char output_buffer);
get_ip_integer_equivalent(char *ip_address);
char *ip_address = '192.168.0.10";
*/

#include <stdio.h>
#include <stdint.h>

/*Constants*/
#define BUF_SIZE 33
#define PREFIX_LEN 15

/*
char ipadd_buffer[PREFIX_LEN];
memset(ipadd_buffer,0,PREFIX_LEN);
char *ip_address = "192.168.2.10";
int mask = 20;
get_broadcast_address(ip_address,mask,ipadd_buffer);
print("Broadcast adress = %s\n",ipadd_buffer);
*/
void get_broadcast_address(char *ip_address,int mask,char *output_buffer);

/*
char *ip_address = "192.168.2.10";
int32_t int_ip = get_ip_integer_equivalent(ip_address);
printf("Integer equivalent for %s is %u\n",ip_adress,int_ip);
*/
int32_t get_ip_integer_equivalent(char *ip_address);
/*
int32_t int_ip = 2058138165;
char ipadd_buffer[PREFIX_LEN];
memset(ipadd_buffer,0,PREFIX_LEN];
get_abcd_ip_format[int_ip,ipadd_buffer);
printf("IP=%u in A.B.C.D format is = %s\n",int_ip,ipadd_buffer);
*/
void get_abcd_ip_format(int32_t int_ip,char *ipadd_buffer);

/*char ipadd_buff[PREFIX_LEN];
memset(ipadd_buffer,0,PREFIX_LEN);
char *ip_add = "192.168.2.10";
int mask = 20;
get_network_id(ip_add,mask,ipadd_buff);
print("Network Id = %s\n",ipadd_buff);
*/
void get_network_id(char *ip_addr,int mask,char* output_buffer);
int32_t get_mask_integer_equivalent(int mask);
// Function which convert number to binary
void int2bin(int a, char *buffer, int buf_size);

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
void int2bin(int a, char *buffer, int buf_size) {
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

}

#define BUF_SIZE 33

