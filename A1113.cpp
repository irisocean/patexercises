// A1113.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	vector<int>a;
	scanf("%d",&n);
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		a.push_back(temp);
	}
	int m=n/2;
	int k=n-m;
	printf("%d ",k-m);
	sort(a.begin(),a.end(),cmp);
	int sum1=0,sum2=0;
	for(int i=0;i<k;i++){
		sum1+=a[i];
	}
	for(int i=k;i<n;i++){
		sum2+=a[i];
	}
	printf("%d\n",sum1-sum2);
	return 0;
}