// B1046.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
int main(){
	int n;
	int faila=0,failb=0;
	scanf("%d",&n);
	int a1,a2,b1,b2;
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		if(a1+b1 == a2 && a1+b1!=b2){
			failb++;
		}
		else if(a1+b1 ==b2 && a1+b1!=a2){
			faila++;
		}
	}
	printf("%d %d\n",faila,failb);
	return 0;
}

