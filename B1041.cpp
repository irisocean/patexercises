// B1041.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
const int maxn = 1010;
struct Student{
	long long id;
	int examSeat;
}testSeat[maxn];
int main(){
	int n,m,seat,examSeat;
	long long id;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%d%d",&id,&seat,&examSeat);
		testSeat[seat].id = id;
		testSeat[seat].examSeat = examSeat;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&seat);
		printf("%lld %d\n",testSeat[seat].id,testSeat[seat].examSeat);
	}
	return 0;
}

