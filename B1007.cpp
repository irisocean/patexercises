// B1007.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<cmath>
bool isPrime(int n){
	if(n<=1)return false;
	else{
		int sqr=(int)sqrt(1.0*n);
		for(int i=2;i<=sqr;i++){
			if(n%i==0)return false;
		}
		return true;
	}
}
int main(){
	int n,count=0;
	scanf("%d",&n);
	for(int i=3;i+2<=n;i+=2){
		if(isPrime(i)&&isPrime(i+2)){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}