// A1023.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
int hashTable[10]={0};
struct bign{
	int d[25];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len=0;
	}
};
bign change(char str[]){
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-i-1]-'0';
		hashTable[a.d[i]]++;
	}
	return a;
}
bign multi(bign a){
	int b=2;
	bign c;
	int carry=0;
	for(int i=0;i<a.len;i++){
		int temp=a.d[i]*b+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	while(carry!=0){
		c.d[c.len++]=carry%10;
		carry/=10;
	}
	return c;
}
void print(bign a){
	for(int i=0;i<a.len;i++){
		hashTable[a.d[i]]--;
	}
	int j;
	for(j=0;j<10;j++){
		if(hashTable[j]!=0){
			printf("No\n");
			break;
		}
	}
	if(j==10)printf("Yes\n");
	for(int i=a.len-1;i>=0;i--){
		printf("%d",a.d[i]);
	}
	printf("\n");
}
int main(){
	char str[25];
	scanf("%s",str);
	bign a=change(str);
	print(multi(a));
	return 0;
}