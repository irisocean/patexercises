// A1087.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
const int N=210;
const int INF=1e9;
int n,m,st,G[N][N],weight[N];
int d[N],numPath=0,maxW=0;
double maxAvg=0;
bool vis[N]={false};
vector<int>pre[N];
vector<int>tempPath,path;
map<string,int>cTn;
map<int,string>nTc;
void D(int s){
	fill(d,d+N,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=0;v<n;v++){
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
	if(v==st){
		tempPath.push_back(v);
		numPath++;
		int tempW=0;
		for(int i=tempPath.size()-2;i>=0;i--){
			int id=tempPath[i];
			tempW+=weight[id];
		}
		double tempAvg=1.0*tempW/(tempPath.size()-1);
		if(tempW>maxW){
			maxW=tempW;
			maxAvg=tempAvg;
			path=tempPath;
		}else if(tempW==maxW&&tempAvg>maxAvg){
			maxAvg=tempAvg;
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
	string start,c1,c2;
	cin >>n >> m >> start;
	cTn[start]=0;
	nTc[0]=start;
	for(int i=1;i<n;i++){
		cin>>c1>>weight[i];
		cTn[c1]=i;
		nTc[i]=c1;
	}
	fill(G[0],G[0]+N*N,INF);
	for(int i=0;i<m;i++){
		cin>>c1>>c2;
		int cy1=cTn[c1];
		int cy2=cTn[c2];
		cin>>G[cy1][cy2];
		G[cy2][cy1]=G[cy1][cy2];
	}
	D(0);
	int rom=cTn["ROM"];
	DFS(rom);
	printf("%d %d %d %d\n",numPath,d[rom],maxW,(int)maxAvg);
	for(int i=path.size()-1;i>=0;i--){
		cout<<nTc[path[i]];
		if(i>0)printf("->");
	}
	printf("\n");
	return 0;
}