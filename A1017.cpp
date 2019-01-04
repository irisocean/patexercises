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
	for(int i=0;i<n;i++){//先去除不在服务范围的数据，将所有时间换算成秒
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&time);
		int cometime=hh*3600+mm*60+ss;
		if(cometime>61200)continue;
		tempcustomer.come=cometime;
		tempcustomer.time=time*60;
		custom.push_back(tempcustomer);
	}
	sort(custom.begin(),custom.end(),cmp1);//按照到达时间从小到大排序
	vector<int>window(k,28800);
	for(int i=0;i<custom.size();i++){
		int tempindex=0,minfinish=window[0];
		for(int j=1;j<k;j++){//对于每一位客户，找到他可以接受服务的窗口
			if(minfinish>window[j]){
				minfinish=window[j];
				tempindex=j;
			}
		}
		if(window[tempindex]<=custom[i].come){//如果有窗口空闲，直接服务，并且无等待时间
			window[tempindex]=custom[i].come+custom[i].time;
		}else{
			result+=window[tempindex]-custom[i].come;//如果没有窗口空闲，需要等待，并将等待时间纳入顾客总等待时间
			window[tempindex]+=custom[i].time;
		}
	}
	if(result==0.0){//极端情况，一天都没有客户来银行，0不能作为分母，但要正确输出0.0
		printf("0.0\n");
	}else{
		printf("%.1f\n",result/60.0/custom.size());//输出一天内客户平均等待时间
	}
	return 0;
}