/*------------------------*/
/* IP ADRESS MANIUPLATION */
/*------------------------*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
/*Constants*/
#define BUF_SIZE 33
#define PREFIX_LEN 16
/*
char *ip_address = "192.168.2.10";&j
int32_t int_ip = get_ip_integer_equivalent(ip_address);
printf("Integer equivalent for %s is %u\n",ip_adress,int_ip);
*/
uint32_t get_ip_integer_equivalent(char *ip_address);

/*
int32_t int_ip = 2058138165;
char ipadd_buffer[PREFIX_LEN];
memset(ipadd_buffer,0,PREFIX_LEN];
get_abcd_ip_format[int_ip,ipadd_buffer);
printf("IP=%u in A.B.C.D format is = %s\n",int_ip,ipadd_buffer);
*/
void get_abcd_ip_format(uint32_t int_ip,char *ipadd_buffer);

/*
unsigned char mask = 24;
printf("Subnest cardinality for Mask = %u is %u\n",mask,get_subnet_cardinality(char mask));
*/
uint32_t get_subnet_cardinality(int mask);

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
char ipadd_buff[PREFIX_LEN];
memset(ipadd_buffer,0,PREFIX_LEN);
char *ip_add = "192.168.2.10";
int mask = 20;
get_network_id(ip_add,mask,ipadd_buff);
print("Network Id = %s\n",ipadd_buff);
*/
void get_network_id(char *ip_addr,int mask,char* output_buffer);

/*
char *network_id = '192.168.0.0';
unsigned char mask = 24;
char *check_ip = '192.168.0.0';
int32_t result = check_ip_subnet_mebership(char *network_id,char mask, char *check_ip);
*/
int32_t check_ip_subnet_mebership(char *network_id,char mask, char *check_ip);

// Function which convert number to binary
void int2bin(int a, char *buffer, int buf_size);

int main() {

    /*Network key information*/
    char ip_string[] = "128.168.0.10";
    uint32_t ip_integer=2158493706;
    char network_ip_string[] = "128.168.0.0";
    int subnet_prefix= 24;
    uint32_t subnet_mask =  4294967040;
    char broadast_string[] = "128.168.0.255 ";
    char ip_string_min[]= "128.168.0.1";
    int number_of_hosts = 254;
    char ip_string_max[]= "128.168.0.254";

    /*Calculated variables*/
    char buffer[BUF_SIZE];
    char ip_string_calc[PREFIX_LEN];
    char network_ip_string_calc[PREFIX_LEN];
    char broadcast_string_calc[PREFIX_LEN];
    uint32_t ip_integer_calc;
    uint32_t subnet_mask_calc;

    /*
     Test get_ip_integer_equivalent
     input         128.168.0.10
     output        2158493706
     binary output 10000000101010000000000000001010
    */
    ip_integer_calc = get_ip_integer_equivalent(ip_string);
    printf("Test int2bin:                    Output %u:    Correct = %u\n\n",ip_integer_calc,ip_integer);

    /*
     *Test get_abcd_ip_format
     *Input       2158493706
     *Output      128.168.0.10
     */
    get_abcd_ip_format(ip_integer,ip_string_calc);
    printf("Test get_abcd_ip_format:         Output %s:  Correct = %s\n\n",ip_string_calc,ip_string);

     /*
      *Test get_subnet_cardinality
      * Input 24
      * Output 4294967040;
      */
    subnet_mask_calc = get_subnet_cardinality(subnet_prefix);
    printf("Test get_subnet_cardinality:     Output %u:    Correct = %u\n",subnet_mask_calc,subnet_mask);
    /*print subnet cardinality as binary*/
    buffer[BUF_SIZE - 1] = '\0';
    int2bin(subnet_mask_calc,buffer,BUF_SIZE-1);
    printf("Subnet cardinality for mask %d as binary=%s\n\n",subnet_prefix,buffer);
    /*
     *Test get_broadcast_address
     *Input 128.168.0.10
     *Output 128.168.0.255
     */
    get_broadcast_address(ip_string, subnet_prefix ,broadcast_string_calc);
    printf("Test get_broadcast_addresss: Output  %s: Correct = %s\n",broadcast_string_calc,broadast_string);
    return 0;
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
/*
unsigned char mask = 24;
printf("Subnest cardinality for Mask = %u is %u\n",mask,get_subnet_cardinality(char mask));
*/
uint32_t get_subnet_cardinality(int mask){
    return 0xffffffff<<(32-mask);

}

/*
char ipadd_buffer[PREFIX_LEN];
memset(ipadd_buffer,0,PREFIX_LEN);
char *ip_address = "192.168.2.10";
int mask = 20;
get_broadcast_address(ip_address,mask,ipadd_buffer);
print("Broadcast adress = %s\n",ipadd_buffer);
*/
void get_broadcast_address(char *ip_address,int mask,char *output_buffer){
    uint32_t ip_address_integer = get_ip_integer_equivalent(ip_address);
}
/*
char *ip_address = "192.168.2.10";&j
int32_t int_ip = get_ip_integer_equivalent(ip_address);
printf("Integer equivalent for %s is %u\n",ip_adress,int_ip);
*/
uint32_t get_ip_integer_equivalent(char *ip_address){
    uint32_t c1,c2,c3,c4;
    uint32_t ip;
    sscanf(ip_address,"%d.%d.%d.%d",&c1,&c2,&c3,&c4);
    /*printf("c1=%u, c2=%u, c3=%u, c4=%u\n",c1*256*256*256,c2*256*256,c3,c4);*/
    ip = c4+c3*256+c2*256*256+c1*256*256*256;
    return ip;
}

/*
uint32_t int_ip = 2058138165;
char ipadd_buffer[prefix_len];
memset(ipadd_buffer,0,prefix_len];
get_abcd_ip_format[int_ip,ipadd_buffer);
printf("ip=%u in a.b.c.d format is = %s\n",int_ip,ipadd_buffer);
*/
void get_abcd_ip_format(uint32_t int_ip,char *ip_add_buffer){
    uint32_t a,b,c,d;
    d = (int_ip>>8*0) & 0xff;
    c = (int_ip>>8*1) & 0xFF;
    b = (int_ip>>8*2) & 0xFF;
    a = (int_ip>>8*3) & 0xFF;
    sprintf(ip_add_buffer,"%u.%u.%u.%u",a,b,c,d);
}



