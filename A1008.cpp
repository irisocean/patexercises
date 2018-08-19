// A1008.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
int main(){
	int n,total=0,now=0,to;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&to);
		if(to>now){
			total+=(to-now)*6;
		}else if(to<now){
			total+=(now-to)*4;
		}
		total+=5;
		now=to;
	}
	printf("%d\n",total);
	return 0;
}

