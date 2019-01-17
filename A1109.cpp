// A1109.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
struct person{
	char name[10];
	int grade;
}tempperson;
int cmp1(person a,person b){//按照成绩从小到大排序，如果成绩相同，则按照名字从大到小排列
	if(a.grade!=b.grade){
		return a.grade<b.grade;
	}else{
		return(strcmp(a.name,b.name)>0);
	}
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<person>people(0);
	for(int i=0;i<n;i++){
		scanf("%s %d",tempperson.name,&tempperson.grade);
		people.push_back(tempperson);
	}
	sort(people.begin(),people.end(),cmp1);
	int m=n/k;
	vector<vector<person>>result(k,vector<person>(2*m-1));
	int t=0;
	for(int i=0;i<k-1;i++){
		int j=i*m+(m-1);
		result[i][m/2]=people[j];
		int q=1;
		while(j>i*m){
			j--;
			result[i][m/2-q]=people[j];
			j--;
			if(j>=i*m){
				result[i][m/2+q]=people[j];
			}
			q++;
		}
	}
	int p=n-m*(k-1);
	result[k-1][p/2]=people[n-1];
	int j=n-1;
	int q=1;
	while(j>(k-1)*m){
		j--;
		result[k-1][p/2-q]=people[j];
		j--;
		if(j>=(k-1)*m){
			result[k-1][p/2+q]=people[j];
		}
		q++;
	}
	for(int i=0;i<p;i++){
		printf("%s",result[k-1][i].name);
		if(i!=p-1)printf(" ");
	}
	printf("\n");
	for(int i=k-2;i>=0;i--){
		for(int j=0;j<m;j++){
			if(result[i][j].name!=" "){
				printf("%s",result[i][j].name);
				if(j!=m-1)printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

