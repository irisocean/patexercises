// B1008.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
int main(){
	int n,m,count=0;
	int a[101];
	scanf("%d%d",&n,&m);
	m=m%n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n-m;i<n;i++){
		printf("%d",a[i]);
		count++;
		if(count<n){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	for(int i=0;i<n-m;i++){
		printf("%d",a[i]);
		count++;
		if(count<n){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	return 0;
}


