// A1092.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
const int maxn=1010;
int hashTable1[128]={0};
int hashTable2[128]={0};
int main(){
	char str1[maxn],str2[maxn];
	gets(str1);
	gets(str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	for(int i=0;i<len1;i++){
		hashTable1[str1[i]]++;
	}
	for(int i=0;i<len2;i++){
		hashTable2[str2[i]]++;
	}
	int over=0,below=0,flag=0;
	for(int i=0;i<128;i++){
		int temp1=hashTable1[i],temp2=hashTable2[i];
		if(temp1<temp2){
			flag=1;
			below+=temp2-temp1;
		}
		else{
			over+=temp1-temp2;
		}
	}
	if(flag==1){
		printf("No %d\n",below);
	}
	else{
		printf("Yes %d\n",over);
	}
	return 0;
}