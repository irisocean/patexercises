// A1005.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
char num[10][10]={
	"zero","one","two","three","four","five","six","seven","eight","nine",
};
char s[105];
/*�ݹ�д��������Ҫ����sumΪ������
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
		sprintf(digit,"%d",sum);//��sum��%d�ĸ�ʽд������digit[]��ȥ������digit�������ַ�������
		numlen=strlen(digit);
		for(int i=0;i<numlen;i++){
			printf("%s",num[digit[i]-'0']);
			if(i!=numlen-1)printf(" ");
		}
	}
	printf("\n");
	return 0;
}

