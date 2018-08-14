// A1037.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int coupon[maxn],product[maxn];
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&coupon[i]);
	}
	scanf("%d",&m);
	sort(coupon,coupon+n);
	for(int i=0;i<m;i++){
		scanf("%d",&product[i]);
	}
	sort(product,product+m);
	int i=0,j,ans=0;
	while(i<n&&i<m&&coupon[i]<0&&product[i]<0){
		ans+=coupon[i]*product[i];
		i++;
	}
	i=n-1;
	j=m-1;
	while(i>=0&&j>=0&&coupon[i]>0&&product[j]>0){
		ans+=coupon[i]*product[j];
		i--;
		j--;
	}
	printf("%d\n",ans);
	return 0;
}
