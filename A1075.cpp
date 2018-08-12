// A1075.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=10010;
struct Student{
	int id;
	int score[6];
	int score_all;
	bool flag;
	int solve;
}stu[maxn];
bool cmp(Student a,Student b){
	if(a.flag!=b.flag)return a.flag>b.flag;
	else if(a.score_all!=b.score_all)return a.score_all>b.score_all;
	else if(a.solve!=b.solve)return a.solve>b.solve;
	else return a.id<b.id;
}
int n;
void init(){
	for(int i=1;i<=n;i++){
		stu[i].id=i;
		stu[i].score_all=0;
		stu[i].flag=false;
		stu[i].solve=0;
		memset(stu[i].score,-1,sizeof(stu[i].score));
	}
}
int main(){
	int k,m;
	int full[6];
	scanf("%d%d%d",&n,&k,&m);
	init();
	for(int i=1;i<=k;i++){
		scanf("%d",&full[i]);
	}
	int u_id,p_id,score_obtained;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u_id,&p_id,&score_obtained);
		if(score_obtained!=-1){
			stu[u_id].flag=true;
		}
		if(score_obtained==-1&&stu[u_id].score[p_id]==-1){
			stu[u_id].score[p_id]=0;
		}
		if(score_obtained==full[p_id]&&stu[u_id].score[p_id]<full[p_id]){
			stu[u_id].solve++;
		}
		if(score_obtained>stu[u_id].score[p_id]){
			stu[u_id].score[p_id]=score_obtained;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(stu[i].score[j]!=-1){
				stu[i].score_all+=stu[i].score[j];
			}
		}
	}
	sort(stu+1,stu+n+1,cmp);
	int rank=1;
	for(int i=1;i<=n&&stu[i].flag==true;i++){
		if(i>1&&stu[i].score_all!=stu[i-1].score_all){
			rank=i;
		}
		printf("%d ",rank);
		printf("%05d ",stu[i].id);
		printf("%d",stu[i].score_all);
		for(int j=1;j<=k;j++){
			if(stu[i].score[j]!=-1){
				printf(" %d",stu[i].score[j]);
			}
			else printf(" -");
		}
		printf("\n");
	}
	return 0;
}

