// A1097.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct Node{
	int address,data,next;
	int order;
}node[maxn];
bool isExist[maxn]={false};
bool cmp(Node a,Node b){
	return a.order<b.order;
}
int main(){
	int n,begin,address;
	for(int i=0;i<maxn;i++){
		node[i].order=2*maxn;
	}
	scanf("%d%d",&begin,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address=address;
	}
	int cv=0,cr=0,p=begin;
	while(p!=-1){
		if(!isExist[abs(node[p].data)]){
			isExist[abs(node[p].data)]=true;
			node[p].order=cv++;
		}else{
			node[p].order=maxn+cr++;
		}
		p=node[p].next;
	}
	sort(node,node+maxn,cmp);
	int count=cv+cr;
	for(int i=0;i<count;i++){
		if(i!=cv-1&&i!=count-1){
			printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
		}else{
			printf("%05d %d -1\n",node[i].address,node[i].data);
		}
	}
	return 0;
}