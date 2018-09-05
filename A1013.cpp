// A1013.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N=1010;
vector<int>G[N];
bool vis[N];
int cd;
void DFS(int v){
	if(v==cd)return;
	vis[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(vis[G[v][i]]==false){
			DFS(G[v][i]);
		}
	}
}
int n,m,k;
int main(){
	int u,v;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<k;i++){
		scanf("%d",&cd);
		memset(vis,false,sizeof(vis));
		int block=0;
		for(int j=1;j<=n;j++){
			if(j!=cd&&vis[j]==false){
				DFS(j);
				block++;
			}
		}
		printf("%d\n",block-1);
	}
	return 0;
}

