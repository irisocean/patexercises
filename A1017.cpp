// A1017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	int come,time;
}tempcustomer;
int cmp1(node a,node b){
	return a.come<b.come;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int hh,mm,ss,time;
	vector<node>custom;
	double result=0.0;
	for(int i=0;i<n;i++){//��ȥ�����ڷ���Χ�����ݣ�������ʱ�任�����
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&time);
		int cometime=hh*3600+mm*60+ss;
		if(cometime>61200)continue;
		tempcustomer.come=cometime;
		tempcustomer.time=time*60;
		custom.push_back(tempcustomer);
	}
	sort(custom.begin(),custom.end(),cmp1);//���յ���ʱ���С��������
	vector<int>window(k,28800);
	for(int i=0;i<custom.size();i++){
		int tempindex=0,minfinish=window[0];
		for(int j=1;j<k;j++){//����ÿһλ�ͻ����ҵ������Խ��ܷ���Ĵ���
			if(minfinish>window[j]){
				minfinish=window[j];
				tempindex=j;
			}
		}
		if(window[tempindex]<=custom[i].come){//����д��ڿ��У�ֱ�ӷ��񣬲����޵ȴ�ʱ��
			window[tempindex]=custom[i].come+custom[i].time;
		}else{
			result+=window[tempindex]-custom[i].come;//���û�д��ڿ��У���Ҫ�ȴ��������ȴ�ʱ������˿��ܵȴ�ʱ��
			window[tempindex]+=custom[i].time;
		}
	}
	if(result==0.0){//���������һ�춼û�пͻ������У�0������Ϊ��ĸ����Ҫ��ȷ���0.0
		printf("0.0\n");
	}else{
		printf("%.1f\n",result/60.0/custom.size());//���һ���ڿͻ�ƽ���ȴ�ʱ��
	}
	return 0;
}