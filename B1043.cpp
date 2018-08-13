// B1043.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
const int maxn=10010;
char str[maxn],dict[6]={'P','A','T','e','s','t'};
int hashTable[6]={0};
int main(){
	gets(str);
	int len=strlen(str),sum=0;
	for(int i=0;i<len;i++){
		for(int j=0;j<6;j++){
			if(str[i]==dict[j]){
				hashTable[j]++;
				sum++;
			}
		}
	}
	while(sum>0){
		for(int i=0;i<6;i++){
			if(hashTable[i]>0){
				printf("%c",dict[i]);
				sum--;
				hashTable[i]--;
			}
		}
	}
	printf("\n");
	return 0;
}