// A1050.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
const int maxn=10010;
bool hashTable[128];
char str1[maxn],str2[maxn];
int main(){
	memset(hashTable,true,sizeof(hashTable));
	gets(str1);
	gets(str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	for(int i=0;i<len2;i++){
		hashTable[str2[i]]=false;
	}
	for(int i=0;i<len1;i++){
		if(hashTable[str1[i]]){
			printf("%c",str1[i]);
		}
	}
	printf("\n");
	return 0;
}
