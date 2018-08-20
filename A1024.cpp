// A1024.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
struct bign{
	int d[1000];
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
	}
	return a;
}
bign reChange(char str[]){
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[i]-'0';
	}
	return a;
}
bign reverse(bign a){
	bign b;
	b.len=a.len;
	for(int i=0;i<a.len;i++){
		b.d[i]=a.d[a.len-i-1];
	}
	return b;
}
bign add(bign a,bign b){
	bign c;
	int carry=0;
	for(int i=0;i<a.len||i<b.len;i++){
		int temp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	if(carry!=0){
		c.d[c.len++]=carry;
	}
	return c;
}
bool judge(bign a){
	for(int i=0;i<=a.len/2;i++){
		if(a.d[i]!=a.d[a.len-i-1]){
			return false;
		}
	}
	return true;
}
void print(bign a){
	for(int i=a.len-1;i>=0;i--){
		printf("%d",a.d[i]);
	}
}
int main(){
	char str[1000];
	int k;
	bign a,b,c;
	scanf("%s%d",str,&k);
	a=change(str);
	if(judge(a)){
		print(a);
		printf("\n0\n");
		return 0;
	}else{
		b=reChange(str);
		c=add(a,b);
		if(judge(c)){
			print(c);
			printf("\n%d\n",1);
			return 0;
		}
		else{
			for(int i=1;i<k;i++){
				a=c;
				b=reverse(c);
				c=add(a,b);
				if(judge(c)){
					print(c);
					printf("\n%d\n",i+1);
					return 0;
				}
			}
			print(c);
			printf("\n%d\n",k);
			return 0;
		}
	}
}