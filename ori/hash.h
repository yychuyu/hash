//
//  hash.h
//  test
//
//  Created by laomi on 2018/3/24.
//  Copyright © 2018年 LAOMI. All rights reserved.
//

#ifndef hash_h
#define hash_h

#include <stdio.h>

#endif /* hash_h */


//int get_password(const unsigned char lock_id[4], const unsigned char mobile_no[11], const unsigned char date[4], const unsigned char time[2], int duration);
int get_password(const char* lock_id, const  char* mobile_no, const char* date, const  char* time, int duration);
void lh_strhash(const unsigned char buf[], unsigned char len, unsigned char result[8]);
void get_smtkey_phrase(const unsigned char lock_id[4], const unsigned char mobile_no[11], const unsigned char date[4], const unsigned char time[2], int duration, unsigned char smtkey_phrase[8]);
int test(const int a,const int b,const int c);