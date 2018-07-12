// B1006.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int temp[3];
	temp[0]=n/100;
	temp[1]=(n%100)/10;
	temp[2]=n%10;
	for(int i=1;i<=temp[0];i++){
		printf("B");
	}
	for(int i=1;i<=temp[1];i++){
		printf("S");
	}
	for(int i=1;i<=temp[2];i++){
		printf("%d",i);
	}
	printf("\n");
	return 0;
}