// A1044.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
const int maxn=100010;
int sum[maxn];
int n,S;
int nearS=100000010;
int upper_bound(int L,int R,int x){
	int mid;
	while(L<R){
		mid=(L+R)/2;
		if(sum[mid]>x){
			R=mid;
		}else{
			L=mid+1;
		}
	}
	return L;
}
int main(){
	scanf("%d%d",&n,&S);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<=n;i++){
		int j=upper_bound(i,n+1,sum[i-1]+S);
		if(sum[j-1]-sum[i-1]==S){
			nearS=S;
			break;
		}else if(j<=n&&sum[j]-sum[i-1]<nearS){
			nearS=sum[j]-sum[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		int j=upper_bound(i,n+1,sum[i-1]+nearS);
		if(sum[j-1]-sum[i-1]==nearS){
			printf("%d-%d\n",i,j-1);
		}
	}
	return 0;
}