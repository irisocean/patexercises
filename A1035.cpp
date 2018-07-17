// A1035.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
struct node{
	char name[12],password[12];
	bool ischange;
}T[10005];
void crypt(node& t,int& cnt){
	int len=strlen(t.password);
	for(int i=0;i<len;i++){
		if(t.password[i]=='1'){
			t.password[i]='@';
			t.ischange=true;
		}else if(t.password[i]=='0'){
			t.password[i]='%';
			t.ischange=true;
		}else if(t.password[i]=='l'){
			t.password[i]='L';
			t.ischange=true;
		}else if(t.password[i]=='O'){
			t.password[i]='o';
			t.ischange=true;
		}
	}
	if(t.ischange)cnt++;
}
int main(){
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %s",T[i].name,T[i].password);
		T[i].ischange=false;
	}
	for(int i=0;i<n;i++){
		crypt(T[i],cnt);
	}
	if(cnt==0){
		if(n==1)printf("There is %d account and no account is modified",n);
		else printf("There are %d accounts and no account is modified",n);
	}else{
		printf("%d\n",cnt);
		for(int i=0;i<n;i++){
			if(T[i].ischange)printf("%s %s\n",T[i].name,T[i].password);
		}
	}
	return 0;
}