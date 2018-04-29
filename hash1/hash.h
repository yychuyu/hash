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
#include <string>
using namespace std;

class Hash
{
public:
	//int get_password(const unsigned char lock_id[4], const unsigned char mobile_no[11], const unsigned char date[4], const unsigned char time[2], int duration);
	string get_password(string lock_id_s, string mobile_no_s, string date_s , string time_s, int duration);
	int test(const int a,const int b,const int c);
	
private:
	void lh_strhash(const unsigned char buf[], unsigned char len, unsigned char result[8]);
	void get_smtkey_phrase(const unsigned char lock_id[4], const unsigned char mobile_no[11], const unsigned char date[4], const unsigned char time[2], int duration, unsigned char smtkey_phrase[8]);
	
};





#endif /* hash_h */
