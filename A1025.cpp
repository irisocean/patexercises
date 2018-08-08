// A1025.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
struct Stu{
	char id[15];
	int score;
	int location;
	int location_rank;
}stu[30010];
bool cmp(Stu student1,Stu student2){
	if(student1.score!=student2.score)return student1.score>student2.score;
	else return strcmp(student1.id,student2.id)<0;
}
int main(){
	int n,k,num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%s %d",stu[num].id,&stu[num].score);
			stu[num].location=i;
			num++;
		}
		sort(stu+num-k,stu+num,cmp);
		stu[num-k].location_rank=1;
		for(int j=num-k+1;j<num;j++){
			if(stu[j].score==stu[j-1].score){
				stu[j].location_rank=stu[j-1].location_rank;
			}
			else{
				stu[j].location_rank=j-num+k+1;
			}
		}
	}
	printf("%d\n",num);
	sort(stu,stu+num,cmp);
	printf("%s %d %d %d\n",stu[0].id,1,stu[0].location,stu[0].location_rank);
	int temp=1;
	for(int i=1;i<num;i++){
		if(stu[i].score!=stu[i-1].score){
			temp=i+1;
		}
		printf("%s %d %d %d\n",stu[i].id,temp,stu[i].location,stu[i].location_rank);
	}
	return 0;
}