// A1005.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
char num[10][10]={
	"zero","one","two","three","four","five","six","seven","eight","nine",
};
char s[105];
/*递归写法，不需要考虑sum为零的情况
void dfs(int n){
	if(n/10==0){
		printf("%s",num[n%10]);
		return;
	}
	dfs(n/10);
	printf(" %s",num[n%10]);
}
int main(){
	gets(s);
	int len=strlen(s);
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=s[i]-'0';
	}
	dfs(sum);
	printf("\n");
	return 0;
}*/
char digit[5];
int main(){
	gets(s);
	int len=strlen(s);
	int sum=0,numlen=0;
	for(int i=0;i<len;i++){
		sum+=s[i]-'0';
	}
	if(sum==0){
		printf("%s",num[0]);
	}else{
		sprintf(digit,"%d",sum);//将sum按%d的格式写到数组digit[]中去，但是digit必须是字符型数组
		numlen=strlen(digit);
		for(int i=0;i<numlen;i++){
			printf("%s",num[digit[i]-'0']);
			if(i!=numlen-1)printf(" ");
		}
	}
	printf("\n");
	return 0;
}

