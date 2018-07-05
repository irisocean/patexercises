// A1065.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
int main(){
	int T,i=1;
	scanf("%d",&T);
	while(T--){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long res=a+b;
		bool flag;
		if(a>0&&b>0&&res<0)flag = true;
		else if(a<0&&b<0&&res>=0)flag = false;
		else if(res>c)flag = true;
		else flag = false;
		if(flag == true){
			printf("Case #%d: true\n",i++);
		}
		else{
			printf("Case #%d: false\n",i++);
		}

	}
	return 0;
}

