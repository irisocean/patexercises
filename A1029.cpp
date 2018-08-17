// A1029.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include <iostream>
#include <climits>
#include <queue>
#include<algorithm>
using namespace std;
int main(){
	queue<int>a,b;
	long long tnum,num;
	int n,m,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&tnum);
		a.push(tnum);
	}
	a.push(INT_MAX);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%lld",&tnum);
		b.push(tnum);
		if(cnt == (n + m - 1) / 2) {
            printf("%d", min(a.front(), b.front()));
            return 0;
        }
        if(a.front() < b.front())   a.pop();
        else                        b.pop();
        cnt++;
	}
	b.push(INT_MAX);
    for(; cnt < (n + m - 1) / 2; cnt++) {
        if(a.front() < b.front())    a.pop() ;
        else                         b.pop() ;
    }
    printf("%d", min(a.front(), b.front()));
    return 0;
}