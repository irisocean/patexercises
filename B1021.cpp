// B1021.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
int main(){
	char str[1010];
	gets(str);
	int len=strlen(str);
	int count[10]={0};
	for(int i=0;i<len;i++){
		count[str[i]-'0']++;
	}
	for(int i=0;i<10;i++){
		if(count[i]!=0){
			printf("%d:%d\n",i,count[i]);
		}
	}
	return 0;
}
