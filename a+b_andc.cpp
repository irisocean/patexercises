// a+b_andc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
int main(){
	int n;
	int result[10]={0};
	scanf("%d",&n);
	long long a,b,c;
	for(int i=0;i<n;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a+b>c){
			result[i]=1;
		}
	}
	for(int i=0;i<n;i++){
		printf("%s #%d: ","Case",i+1);
		if(result[i] == 1){
			printf("%s\n","true");
		}
		else{
			printf("%s\n","false");
		}
	}
	return 0;
}
