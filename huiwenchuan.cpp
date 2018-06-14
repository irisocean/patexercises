// huiwenchuan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
int main(){
	char str[256];
	while(gets(str)){
		bool flag = true;
		int len = strlen(str);
		int num = 0;
		for(int i=0;i<len/2;i++){
			num = i;
			if(str[i]!=str[len-1-i]){
				flag = false;
				break;
			}
		}
		if(flag == true){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
