// A1041.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
const int maxm=10010;
const int maxn=100010;
int a[maxn];
int hashTable[maxm]={0};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		hashTable[a[i]]++;
	}
	int i;
	for(i=0;i<n;i++){
		if(hashTable[a[i]]==1){
			printf("%d\n",a[i]);
			break;
		}
	}
	if(i==n){
		printf("None\n");
	}
	return 0;
}

