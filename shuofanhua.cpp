// shuofanhua.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
int main(){
	char str[90];
	gets(str);
	int len =strlen(str),r=0,h=0;
	char ans[90][90];
	for(int i=0;i<len;i++){
		if(str[i]!=' '){
			ans[r][h++]=str[i];
		}else{
			ans[r][h] = '\0';
			r++;
			h=0;
		}
	}
	ans[r][h] = '\0';
	for(int i=r;i>=0;i--){
		printf("%s",ans[i]);
		if(i>0){
			printf(" ");
		}
		else{
			printf("\n");
		}
	}
	return 0;
}
