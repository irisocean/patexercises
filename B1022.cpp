// B1022.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
int main(){
	int a,b,d,sum;
	scanf("%d %d %d",&a,&b,&d);
	sum=a+b;
	int ans[31],num=0;
	do{
		ans[num++]=sum%d;
		sum/=d;
	}while(sum!=0);
	for(int i=num-1;i>=0;i--){
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}
