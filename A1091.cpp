// A1091.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<queue>
using namespace std;
struct Node{
	int x,y,z;
}node;
int n,m,slice,T;
int pixel[1290][130][61];
bool inq[1290][130][61]={false};
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
bool judge(int x,int y,int z){
	if(x>=n||x<0||y>=m||y<0||z>=slice||z<0)return false;
	if(pixel[x][y][z]==0||inq[x][y][z]==true)return false;
	return true;
}
int BFS(int x,int y,int z){
	int tot=0;
	queue<Node>Q;
	node.x=x,node.y=y,node.z=z;
	Q.push(node);
	inq[x][y][z]=true;
	while(!Q.empty()){
		Node top=Q.front();
		Q.pop();
		tot++;
		for(int i=0;i<6;i++){
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			int newZ=top.z+Z[i];
			if(judge(newX,newY,newZ)){
				node.x=newX,node.y=newY,node.z=newZ;
				Q.push(node);
				inq[newX][newY][newZ]=true;
			}
		}
	}
	if(tot>=T)return tot;
	else return 0;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&slice,&T);
	for(int z=0;z<slice;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				scanf("%d",&pixel[x][y][z]);
			}
		}
	}
	int ans=0;
	for(int z=0;z<slice;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(pixel[x][y][z]==1&&inq[x][y][z]==false){
					ans+=BFS(x,y,z);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}