// A1058.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
/*const long long Galleon=17*29;
const long long Sickle=29;
int main(){
	long long  a1,a2,a3;
	long long b1,b2,b3;
	scanf("%lld.%lld.%lld %lld.%lld.%lld",&a1,&a2,&a3,&b1,&b2,&b3);
	long long  a=a1*Galleon+a2*Sickle+a3;
	long long b=b1*Galleon+b2*Sickle+b3;
	long long sum=a+b;
	printf("%lld.%lld.%lld\n",sum/Galleon,(sum%Galleon)/Sickle,sum%Sickle);
	return 0;
}*/
int main(){
	int a[3],b[3],c[3];
	scanf("%d.%d.%d %d.%d.%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
	int carry=0;
	c[2]=(a[2]+b[2])%29;
	carry=(a[2]+b[2])/29;
	c[1]=(a[1]+b[1]+carry)%17;
	carry=(a[1]+b[1]+carry)/17;
	c[0]=a[0]+b[0]+carry;
	printf("%d.%d.%d\n",c[0],c[1],c[2]);
	return 0;
}