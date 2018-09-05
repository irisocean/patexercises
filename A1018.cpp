// A1018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=510;
const int INF=1e9;
int Cmax,n,Sp,m,numPath=0,G[N][N],weight[N];
int d[N],mn=INF,mr=INF;
bool vis[N]={false};
vector<int>pre[N];
vector<int>tempPath,path;
void D(int s){
	fill(d,d+N,INF);
	d[s]=0;
	for(int i=0;i<=n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<=n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=0;v<=n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int v){
	if(v==0){
		tempPath.push_back(v);
		int need=0,remain=0;
		for(int i=tempPath.size()-1;i>=0;i--){
			int id=tempPath[i];
			if(weight[id]>0){
				remain+=weight[id];
			}else{
				if(remain>abs(weight[id])){
					remain-=abs(weight[id]);
				}else{
					need+=abs(weight[id])-remain;
					remain=0;
				}
			}
		}
		if(need<mn){
			mn=need;
			mr=remain;
			path=tempPath;
		}else if(need==mn&&remain<mr){
			mr=remain;
			path=tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}
int main(){
	scanf("%d%d%d%d",&Cmax,&n,&Sp,&m);
	int u,v;
	fill(G[0],G[0]+N*N,INF);
	for(int i=1;i<=n;i++){
		scanf("%d",&weight[i]);
		weight[i]-=Cmax/2;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		scanf("%d",&G[u][v]);
		G[v][u]=G[u][v];
	}
	D(0);
	DFS(Sp);
	printf("%d ",mn);
	for(int i=path.size()-1;i>=0;i--){
		printf("%d",path[i]);
		if(i>0)printf("->");
	}
	printf(" %d",mr);
	return 0;
}
