// B1028.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
struct person{
	char name[10];
	int yy,mm,dd;
}oldest,youngest,left,right,temp;
bool lessEqu(person a,person b){
	if(a.yy!=b.yy)return a.yy<=b.yy;
	else if(a.mm!=b.mm)return a.mm<=b.mm;
	else return a.dd<=b.dd;
}
bool moreEqu(person a,person b){
	if(a.yy!=b.yy)return a.yy>=b.yy;
	else if(a.mm!=b.mm)return a.mm>=b.mm;
	else return a.dd>=b.dd;
}
void init(){
	youngest.yy = left.yy = 1814;
	oldest.yy = right.yy = 2014;
	youngest.mm = oldest.mm = left.mm = right.mm = 9;
	youngest.dd = oldest.dd = left.dd = right.dd = 6;
}
int main(){
	init();
	int n,num=0;//num存放合法日期的人数
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %d/%d/%d",temp.name,&temp.yy,&temp.mm,&temp.dd);
		if(moreEqu(temp,left)&&lessEqu(temp,right)){
			num++;
			if(lessEqu(temp,oldest))oldest = temp;
			if(moreEqu(temp,youngest)) youngest = temp;
		}
	}
	if(num == 0)printf("0\n");
	else printf("%d %s %s\n",num,oldest.name,youngest.name);
	return 0;
}

