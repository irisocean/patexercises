// A1006.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<cstring>
using namespace std;
struct pNode{
	char id[16];
	int hh,mm,ss;
}temp,ans1,ans2;
bool great(pNode a,pNode b){
	if(a.hh!=b.hh)return a.hh>b.hh;
	else if(a.mm!=b.mm)return a.mm>b.mm;
	else return a.ss>b.ss;
}
int main(){
	int n;
	scanf("%d",&n);
	ans1.hh = 24,ans1.mm = 60,ans1.ss = 60;
	ans2.hh = 0,ans2.mm = 0,ans2.ss = 0;
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d",temp.id,&temp.hh,&temp.mm,&temp.ss);
		if(!great(temp,ans1))ans1=temp;
		scanf("%d:%d:%d",&temp.hh,&temp.mm,&temp.ss);
		if(great(temp,ans2))ans2=temp;

	}
	printf("%s %s\n",ans1.id,ans2.id);
	return 0;
}

