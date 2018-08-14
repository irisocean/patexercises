// A1048.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm=1010;
int hashTable[maxm]={0};
int main(){
	int n,m,a;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		++hashTable[a];
	}
	for(int i=1;i<m;i++){
		if(hashTable[i]&&hashTable[m-i]){
			if(i==m-i&&hashTable[i]<=1)continue;
			printf("%d %d\n",i,m-i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}

