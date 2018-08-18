// A1059.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<math.h>
const int maxn=100010;
int prime[maxn],Pnum=0;
bool p[maxn]={0};
void findP(){
	for(int i=2;i<maxn;i++){
		if(p[i]==false){
			prime[Pnum++]=i;
			for(int j=i+i;j<maxn;j+=i){
				p[j]=true;
			}
		}
	}
}
struct factor{
	int x,cnt;
}fac[10];
int main(){
	findP();
	int n,num=0;
	scanf("%d",&n);
	if(n==1)printf("1=1\n");
	else{
		printf("%d=",n);
		int sqr=(int)sqrt(1.0*n);
		for(int i=0;i<Pnum&&prime[i]<=sqr;i++){
			if(n%prime[i]==0){
				fac[num].x=prime[i];
				fac[num].cnt=0;
				while(n%prime[i]==0){
					n/=prime[i];
					fac[num].cnt++;
				}
				num++;
			}
			if(n==1)break;
		}
		if(n!=1){
			fac[num].x=n;
			fac[num].cnt=1;
		}
		if(num==0)printf("%d",n);
		else{
		  for(int i=0;i<num;i++){
			  if(i>0)printf("*");
			  printf("%d",fac[i].x);
			  if(fac[i].cnt>1){
				  printf("^%d",fac[i].cnt);
			  }
		  }
		}
		printf("\n");
	}
	return 0;
}