// A1101.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
const int INF=0x3fffffff;
int a[maxn],left[maxn],right[maxn];
int ans[maxn],num=0;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	left[0]=0;
	right[n-1]=INF;
	for(int i=1;i<n;i++){
		left[i]=max(left[i-1],a[i-1]);
	}
	for(int i=n-2;i>=0;i--){
		right[i]=min(right[i+1],a[i+1]);
	}
	for(int i=0;i<n;i++){
		if(left[i]<a[i]&&right[i]>a[i]){
			ans[num++]=a[i];
		}
	}
	printf("%d\n",num);
	for(int i=0;i<num;i++){
		printf("%d",ans[i]);
		if(i!=num-1)printf(" ");
	}
	printf("\n");
	return 0;
}

