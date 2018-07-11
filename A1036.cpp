// A1036.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
struct person{
	char name[11];
	char id[11];
	int score;
}M,F,temp;
void init(){
	M.score=101;
	F.score=-1;
}
int main(){
	init();
	int n;
	char gender;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %c %s %d",temp.name,&gender,temp.id,&temp.score);
		if(gender=='M'&&temp.score<M.score)M=temp;
		if(gender=='F'&&temp.score>F.score)F=temp;

	}
	if(F.score==-1)printf("Absent\n");
	else printf("%s %s\n",F.name,F.id);
	if(M.score==101)printf("Absent\n");
	else printf("%s %s\n",M.name,M.id);
	if(F.score==-1||M.score==101)printf("NA\n");
	else printf("%d\n",F.score-M.score);
	return 0;
}

