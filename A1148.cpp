// A1148.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			vector<int>liar;
			vector<int>human(n+1,1);//1��ʾ���࣬-1��ʾ��
			human[i]=-1;//����������
			human[j]=-1;
			for(int k=1;k<=n;k++){
				if(v[k]*human[abs(v[k])]<0){//�жϼ����Ƿ���ȷ
					liar.push_back(k);
				}
			}
			if(liar.size()==2&&(human[liar[0]]+human[liar[1]]==0)){//��֤����˵���ߣ�����һ�����ˣ�����һ������
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	cout<<"No Solution";
	return 0;
}
