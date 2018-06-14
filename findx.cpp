// findx.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
const int maxn = 210;
int a[maxn];
int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&x);
	int k;
	for(k=0;k<n;k++){
		if(a[k] == x){
			printf("%d\n",k);
			break;
		}
	}
	if(k ==n){
		printf("-1\n");
	}
	return 0;
}


