// A1001.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
int num[10];
int main(){
	int a,b,sum;
	scanf("%d %d",&a,&b);
	sum=a+b;
	if(sum<0){
		printf("-");
		sum=-sum;
	}
	int len=0;
	do{
		num[len++]=sum%10;
		sum/=10;
	}while(sum);
	for(int i=len-1;i>=0;i--){
		printf("%d",num[i]);
		if(i>0&&i%3==0)printf(",");
	}
	printf("\n");
	return 0;
}
