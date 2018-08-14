// B1005.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
using namespace std;
bool hashTable[10000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m,a[110];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		m=a[i];
		while(m!=1){
			if(m%2==0)m/=2;
			else m=(3*m+1)/2;
			hashTable[m]=true;
		}
	}
	int count=0;
	for(int i=0;i<n;i++){
		if(hashTable[a[i]]==false){
			count++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		if(hashTable[a[i]]==false){
			printf("%d",a[i]);
			count--;
			if(count>0)printf(" ");
		}
	}
	printf("\n");
	return 0;
}

