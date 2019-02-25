// A1116.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<set>
#include<cmath>
using namespace std;
int ran[10000];
bool isPrime(int x){
	if(x<=1)return false;
	int s=sqrt((double)x);
	for(int i=2;i<=s;i++){
		if(x%i==0)return false;
	}
	return true;
}
int main(){
	int n,k,temp;
	scanf("%d",&n);
	set<int>ss;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		ran[temp]=i+1;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&temp);
		printf("%04d: ",temp);
		if(ran[temp]==0){
			printf("Are you kidding?\n");
			continue;
		}
		if(ss.find(temp)==ss.end()){
			ss.insert(temp);
		}else{
			printf("Checked\n");
			continue;
		}
		if(ran[temp]==1){
			printf("Mystery Award\n");
		}else if(isPrime(ran[temp])){
			printf("Minion\n");
		}else{
			printf("Chocolate\n");
		}
	}
	return 0;
}
