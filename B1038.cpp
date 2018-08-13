// B1038.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
int main(){
	int n,k,temp;
	int hashTable[110]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		hashTable[temp]++;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&temp);
		printf("%d",hashTable[temp]);
		if(i==k-1)printf("\n");
		else printf(" ");
	}
	return 0;
}
