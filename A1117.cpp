// A1117.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
int a[1000000];
int cmp1(int a,int b){
	return a>b;
}
int main(){
	int n,e=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp1);
	while(e<n&&a[e]>e+1)e++;
	printf("%d\n",e);
	return 0;
}
