// B1047.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
const int maxn=1010;
int hashTable[maxn]={0};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int team,member,score;
		scanf("%d-%d %d",&team,&member,&score);
		hashTable[team]+=score;
	}
	int k,MAX=-1;
	for(int i=0;i<maxn;i++){
		if(hashTable[i]>MAX){
			k=i;
			MAX=hashTable[i];
		}
	}
	printf("%d %d\n",k,MAX);
	return 0;
}
