// B1010.cpp : 用scanf和EOF的时候需要用CTRL+Z来停止输入，可以用do while来解决
//

#include "stdafx.h"
#include<cstdio>
int main(){
	int a[1010]={0};
	int c,e,count=0;
	char ch;
	while(scanf("%d%d",&c,&e)!=EOF){
		a[e]=c;
	}
	/*do{
		scanf("%d%d",&c,&e);
		a[e]=c;
	}while((ch=getchar())!='\n');*/	
	a[0]=0;
	for(int i=1;i<=1000;i++){
		a[i-1]=a[i]*i;
		a[i]=0;
		if(a[i-1]!=0)count++;
	}
	if(count == 0)printf("0 0");
	else{
		for(int i=1000;i>=0;i--){
			if(a[i]!=0){
				printf("%d %d",a[i],i);
				count--;
				if(count!=0)printf(" ");
			}
		}
	}
	return 0;
}


