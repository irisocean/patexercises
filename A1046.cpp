// A1046.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int main(){
	int N;//�ڵ����
	int dis[MAXN],ans[MAXN];
	int sum=0;
	int query,left,right;
	scanf("%d",&N);
	ans[0]=0;//�������Ǹ�ans[0]����ֵ
	for(int i=1;i<=N;i++){
		scanf("%d",&dis[i]);
		sum+=dis[i];
		ans[i]=sum;
	}
	scanf("%d",&query);
	for(int i=1;i<=query;i++){
		scanf("%d%d",&left,&right);
		if(left>right)swap(left,right);
		int temp=ans[right-1]-ans[left-1];//ע������������
		printf("%d\n",min(temp,sum-temp));
	}
	return 0;
}

