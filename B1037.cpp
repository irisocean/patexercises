// B1037.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
const int Galleon=17*29;
const int Sickle=29;
int main(){
	int a1,a2,a3,b1,b2,b3;
	scanf("%d.%d.%d %d.%d.%d",&a1,&a2,&a3,&b1,&b2,&b3);
	int price = a1*Galleon+a2*Sickle+a3;
	int money = b1*Galleon+b2*Sickle+b3;
	int change = money-price;
	if(change<0){
		printf("-");
		change=-change;
	}
	printf("%d.%d.%d\n",change/(17*29),change%(17*29)/29,change%29);
	return 0;
}
