// B1042.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
const int maxn=1010;
int hashTable[30]={0};
int main(){
	char str[maxn];
	gets(str);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]>='A'&&str[i]<='Z'){
			hashTable[str[i]-'A']++;
		}else if(str[i]>='a'&&str[i]<='z'){
			hashTable[str[i]-'a']++;
		}
	}
	int k=0;
	for(int i=0;i<26;i++){
		if(hashTable[i]>hashTable[k])k=i;
	}
	printf("%c %d\n",'a'+k,hashTable[k]);
	return 0;
}