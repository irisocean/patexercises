// a_btoC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
int main(){
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF){
		int temp = a+b;
		int z[40],num=0;
		do{
			z[num++]=temp%c;
			temp = temp/c;
		}while(temp!=0);
		for(int i=num-1;i>=0;i--){
			printf("%d",z[i]);
		}
	}
	return 0;
}
