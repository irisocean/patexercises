// B1002.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
int main(){
	char str[105];
	gets(str);
	int len=strlen(str);
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=str[i]-'0';
	}
	int ans[4],num=0;
	while(sum!=0){
		ans[num++]=sum%10;
		sum/=10;
	}
	char change[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	for(int i=num-1;i>=0;i--){
		printf("%s",change[ans[i]]);
		if(i!=0)printf(" ");
		else printf("\n");
	}
	return 0;
}
