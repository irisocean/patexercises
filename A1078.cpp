// A1078.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int N=11111;
bool isPrime(int n){
	if(n<=1)return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
bool hashTable[N]={0};
int main(){
	int n,Tsize,a;
	scanf("%d%d",&Tsize,&n);
	while(!isPrime(Tsize)){
		Tsize++;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		int M=a%Tsize;
		if(!hashTable[M]){
			hashTable[M]=true;
			if(i==0)printf("%d",M);
			else printf(" %d",M);
		}else{
			int step;
			for(step=1;step<Tsize;step++){
				M=(a+step*step)%Tsize;
				if(!hashTable[M]){
					hashTable[M]=true;
					if(i==0)printf("%d",M);
					else printf(" %d",M);
					break;
				}
			}
			if(step>=Tsize){
				if(i>0)printf(" ");
				printf("-");
			}
		}
	}
	printf("\n");
	return 0;
}
