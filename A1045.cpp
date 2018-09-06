// A1045.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=10010;
const int C=210;
int hashTable[C];
int A[N],dp[N];
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);
	memset(hashTable,-1,sizeof(hashTable));
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		hashTable[x]=i;
	}
	int L,num=0;
	scanf("%d",&L);
	for(int i=0;i<L;i++){
		scanf("%d",&x);
		if(hashTable[x]>=0){
			A[num++]=hashTable[x];
		}
	}
	int ans=-1;
	for(int i=0;i<num;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(A[j]<=A[i]&&dp[j]+1>dp[i]){
				dp[i]=dp[j]+1;
			}
		}
		ans=max(dp[i],ans);
	}
	printf("%d\n",ans);
	return 0;
}