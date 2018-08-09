// qujianbuxiangjiao.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
struct Inteval{
	int x,y;
}I[maxn],A[maxn];
bool cmp(Inteval a,Inteval b){
	if(a.x!=b.x)return a.x>b.x;
	else return a.y<b.y;
}
bool cmp1(Inteval a,Inteval b){
	if(a.x!=b.x)return a.x<b.x;
}
int main(){
	int n;
	while(scanf("%d",&n),n!=0){
		for(int i=0;i<n;i++){
			getchar();
			getchar();
			scanf("%d",&I[i].x);
			getchar();
			scanf("%d",&I[i].y);
			getchar();
		}
		sort(I,I+n,cmp);
		int lastX=I[0].x,j=1,ans=1;
		A[0].x=I[0].x;
		A[0].y=I[0].y;
		for(int i=1;i<n;i++){
			if(I[i].y<=lastX){
				lastX=I[i].x;
				ans++;
				A[j].x=I[i].x;
				A[j++].y=I[i].y;
			}
		}
		sort(A,A+ans,cmp1);
		for(int i=0;i<ans;i++){
			printf("(%d,%d)",A[i].x,A[i].y);
			if(i!=ans-1)printf(" ");
			else printf("\n");
		}
	}
	return 0;
}