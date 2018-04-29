//
//  hash.c
//  test
//
//  Created by laomi on 2018/3/24.
//  Copyright © 2018年 LAOMI. All rights reserved.
//

#include "hash.h"
#include "string.h"
unsigned long rest;
void get_smtkey_phrase(const unsigned char lock_id[4], const unsigned char mobile_no[11], const unsigned char date[4], const unsigned char time[2], int duration, unsigned char smtkey_phrase[8])
{
    unsigned char buf[24];
    
    buf[ 0] = 'X';
    buf[ 1] = 'H';
    buf[ 2] = 'Z';
    buf[ 3] = duration;
    buf[ 4] = 'n';
    buf[ 5] = 'a';
    buf[ 6] = 'C';
    buf[ 7] = time[1];
    
    buf[8] = lock_id[0];
    buf[9] = lock_id[1];
    buf[10] = lock_id[2];
    buf[11] = lock_id[3];
    buf[12] = 'L';
    buf[13] = 'j';
    buf[14] = (mobile_no[0] << 6) | (mobile_no[1] << 4) | mobile_no[2];
    buf[15] = (mobile_no[3] << 4) | mobile_no[4];
    
    buf[16] = (mobile_no[5] << 4) | mobile_no[6];
    buf[17] = (mobile_no[7] << 4) | mobile_no[8];
    buf[18] = (mobile_no[9] << 4) | mobile_no[10];
    buf[19] = date[0];
    buf[20] = date[1];
    buf[21] = date[2];
    buf[22] = date[3];
    buf[23] = time[0];
    printf("\n------buf%s",buf);
    lh_strhash(buf, 24, smtkey_phrase);
//    return 0;
}
void lh_strhash(const unsigned char buf[], unsigned char len, unsigned char result[8])
{
    unsigned long ret = 0;
    unsigned long n;
    unsigned long v;
    unsigned int r;
    unsigned char *c = (unsigned char *)buf;
    n = 0x100;
    unsigned char i;
    for (i=0; i<len; i++)
    {
        v = n | (*c);
        n += 0x100;
        r = (unsigned int)((v >> 2) ^ v) & 0x0f;
        ret = (ret << r) | (ret >> (32 - r));
        ret &= 0x0FFFFFFFFULL;
        ret ^= v * v;
        c++;
    }
    ret = ((ret >> 16) ^ ret);
    result[0] = ret & 0xff;
    result[1] = (ret >> 8) & 0xff;
    result[2] = (ret >> 16) & 0xff;
    result[3] = ret >> 24;
    result[4] = (ret >> 1) & 0xff;
    result[5] = (ret >> 7) & 0xff;
    result[6] = (ret >> 11) & 0xff;
    result[7] = (ret >> 19) & 0xff;
    printf("\n------result:%s",result);
//    return 0;
}
int get_password(const char* lock_id_c, const  char* mobile_no_c, const char* date_c , const  char* time_c, int duration)
//int get_password(const unsigned char lock_id[4], const unsigned char mobile_no[11], const unsigned char date[4], const unsigned char time[2], int duration)
{
    unsigned char phrase[8];
    printf("get_password\n");

    printf("lock_id:%s\n",lock_id_c);

    printf("mobile_no:%s\n",mobile_no_c);
    printf("date:%s\n",date_c);
    printf("time:%s\n",time_c);
     printf("=======================\n");
    char lock_id[4+1];
    char mobile_no[11+1];
    char date[4+1];
    char time[2+1];
    int i;
    for(i=0;i<strlen(lock_id_c);i++){
            char tmp = *(lock_id_c+i);
            printf("==== %c\n", tmp);
            lock_id[i] = tmp;
    }
    lock_id[strlen(lock_id_c)]='\0';
    for(i=0;i<strlen(mobile_no_c);i++){
            char tmp = *(mobile_no_c+i);
            printf("~~~~ %c\n", tmp);
            mobile_no[i] = tmp;
    }
    mobile_no[strlen(mobile_no_c)]='\0';
    for(i=0;i<strlen(date_c);i++){
            char tmp = *(date_c+i);
            date[i] = tmp;
    }
    date[strlen(date_c)]='\0';
    for(i=0;i<strlen(time_c);i++){
            char tmp = *(time_c+i);
            time[i] = tmp;
    }
    time[strlen(time_c)]='\0';

//    strncpy(lock_id, lock_id_c, strlen(lock_id) + 1);
//    strncpy(mobile_no, mobile_no_c, strlen(mobile_no) + 1);
//    strncpy(date, date_c, strlen(date_c) + 1);
//    strncpy(time, time_c, strlen(time_c) + 1);

    printf("lock_id:%s\n",lock_id);

    printf("mobile_no:%s\n",mobile_no);
    printf("date:%s\n",date);
    printf("time:%s\n",time);

    get_smtkey_phrase(lock_id, mobile_no, date, time, duration, phrase);
    
//    password[0] = (unsigned short)(phrase[0]^phrase[5]) % 100u;
//    password[1] = (unsigned short)(~phrase[1]^phrase[6]) % 100u;
//    password[2] = (unsigned short)~(phrase[2]^phrase[4]) % 100u;
//    password[3] = (unsigned short)(phrase[3]^~phrase[7]) % 100u;
//
    unsigned short p1,p2,p3,p4;
    p1 = (unsigned short)(phrase[0]^phrase[5]) % 100u;
    p2 = (unsigned short)(~phrase[1]^phrase[6]) % 100u;
    p3 = (unsigned short)~(phrase[2]^phrase[4]) % 100u;
    p4 = (unsigned short)(phrase[3]^~phrase[7]) % 100u;

//    //转成long丢出来;
    rest = p1*1000000+p2*10000+p3*100+p1;
//    return rest;
    printf("\npass:%d",rest);

    return 0;
//    char chatTotal[13];
//    char dest[] = {p1,p2,p3,p4};
//    int i= 0;
//    char temp[3];
//    while (i<4) {
//        sprintf(temp, "%d", dest[i]);
//        strcat(chatTotal,temp);
//        i++;
//    }
//    strcpy(g_s,chatTotal);
//    return   (char*)g_s;
}

int test(const int a,const int b,const int c){
    return a+b+c;
}
