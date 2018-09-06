// A1007.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=10010;
vector<int>pre[N];
int temp[N];
int main(){
	int n;
	scanf("%d",&n);
	int d[N],f=0;
	d[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&temp[i]);
		if(temp[i]<0)f++;
		if(d[i-1]+temp[i]>temp[i]){
			pre[i]=pre[i-1];
			pre[i].push_back(i-1);
			d[i]=d[i-1]+temp[i];
		}else{
			d[i]=temp[i];
		}
	}
	int max=d[0],u=0;
	for(int i=1;i<=n;i++){
		if(d[i]>max){
			max=d[i];
			u=i;
		}
	}
	if(f==n){
		printf("0 %d %d\n",temp[1],temp[n]);
	}else if(pre[u].size()==0){
		printf("%d %d %d\n",max,temp[u],temp[u]);
	}else{
		printf("%d %d %d\n",max,temp[pre[u][0]],temp[u]);
	}
	return 0;
}
