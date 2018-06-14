// jinzhizhuanhuan.cpp : Defines the entry point for the console application.
//
//2、8、10、16进制之间互相转化
#include "stdafx.h"
#include<stdio.h>
int main(){
	int x,P,Q;
	while(scanf("%d%d%d",&x,&P,&Q)!=EOF){
		int y=0,product=1;
		while(x!=0){
			y=y+(x%10)*product;
			x=x/10;
			product=product*P;
		}
		char z[40];
		int num=0;
		do{
			int temp = y%Q;
			char a;
			switch(temp){
			case 10: 
				a = 'A';
				break;
			case 11:
				a = 'B';
				break;
			case 12:
				a = 'C';
				break;
			case 13:
				a = 'D';
				break;
			case 14:
				a = 'E';
				break;
			case 15:
				a = 'F';
				break;
			default:
				a = temp + '0';
			}
			z[num++]=a;
			y=y/Q;
		}while(y!=0);
		for(int i=num-1;i>=0;i--){
			printf("%c",z[i]);
		}
	}
	return 0;
}
