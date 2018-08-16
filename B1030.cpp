// B1030.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int n;
long long p,a[maxn];
int main(){
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	int i=0,j=0,ans=1;
	while(i<n&&j<n){
		while(j<n&&a[j]<=a[i]*p){
			ans=max(ans,j-i+1);
			j++;
		}
		i++;
	}
	printf("%d\n",ans);
	return 0;
}
