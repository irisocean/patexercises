// A1042.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
const int N=54;
char mp[5]={'S','H','C','D','J'};
int start[N+1],end[N+1],next[N+1];//next������ȡ�任���λ��
int main(){
	int K;
	scanf("%d",&K);
	for(int i=1;i<=N;i++){
		start[i]=i;
	}
	for(int i=1;i<=N;i++){
		scanf("%d",&next[i]);
	}
	for(int step=0;step<K;step++){
		for(int i=1;i<=N;i++){
			end[next[i]]=start[i];//�ѵ�i��λ�õ��Ƶı�Ŵ���λ��next[i]
		}
		for(int i=1;i<=N;i++){
			start[i]=end[i];
		}
	}
	for(int i=1;i<=N;i++){
		if(i!=1)printf(" ");
		start[i]--;
		printf("%c%d",mp[start[i]/13],start[i]%13+1);
	}
	return 0;
}
