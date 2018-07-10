// B1004.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
struct Student{
	char name[15];
	char id[15];
	int score;
}temp,ans_max,ans_min;
//temp存放临时数据，ans_max为最高分数的学生，ans_min为最低分数的学生
int main(){
	int n;
	scanf("%d",&n);
	//最高的分数初值反而最低！
	ans_max.score = -1;
	ans_min.score = 101;
	for(int i=0;i<n;i++){
		scanf("%s%s%d",temp.name,temp.id,&temp.score);
		if(temp.score>ans_max.score)ans_max = temp;
		if(temp.score<ans_min.score)ans_min = temp;
	}
	printf("%s %s\n",ans_max.name,ans_max.id);
	printf("%s %s\n",ans_min.name,ans_min.id);
	return 0;
}
