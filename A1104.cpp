// A1104.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
int main(){
	int n;
	double a,ans=0.00;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&a);
		ans+=a*i*(n+1-i);
	}
	printf("%.2f\n",ans);
	return 0;
}

