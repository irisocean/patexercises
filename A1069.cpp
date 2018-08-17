// A1069.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
void to_array(int n,int num[]){
	for(int i=0;i<4;i++){
		num[i]=n%10;
		n/=10;
	}
}
int to_number(int num[]){
	int sum=0;
	for(int i=0;i<4;i++){
		sum=sum*10+num[i];
	}
	return sum;
}
int main(){
	int n,de,in;
	scanf("%d",&n);
	int num[5];
	while(1){
		to_array(n,num);
		sort(num,num+4);
		in=to_number(num);
		sort(num,num+4,cmp);
		de=to_number(num);
		n=de-in;
		printf("%04d - %04d = %04d\n",de,in,n);
		if(n==0||n==6174)break;
	}
	return 0;
}
