// A1103.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,p,k,maxD=-1;
vector<int>D,ans,temp;
int power(int x){
	int ans=1;
	for(int i=0;i<p;i++){
		ans*=x;
	}
	return ans;
}
void init(){
	int i=0,temp=0;
	while(temp<=n){
		D.push_back(temp);
		temp=power(++i);
	}
}
void DFS(int index,int nowK,int sum,int DSum){
	if(sum==n&&nowK==k){
		if(DSum>maxD){
			ans=temp;
			maxD=DSum;
		}
		return;
	}
	if(sum>n||nowK>k)return;
	if(index-1>=0){
		temp.push_back(index);
		DFS(index,nowK+1,sum+D[index],DSum+index);
		temp.pop_back();
		DFS(index-1,nowK,sum,DSum);
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&p);
	init();
	DFS(D.size()-1,0,0,0);
	if(maxD==-1){
		printf("Impossible");
	}else{
		printf("%d = %d^%d",n,ans[0],p);
		for(int i=1;i<ans.size();i++){
			printf(" + %d^%d",ans[i],p);
		}
	}
	printf("\n");
	return 0;
}

