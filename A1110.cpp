// A1110.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
struct node{
	int l,r;
}a[30];
int maxn=-1,ans;
//��ȱ����ҵ�����һ���ڵ��λ�úţ���ڵ������Ƚϣ������ͬ��������ȫ������
void dfs(int root,int index){//rootΪ��ǰ���ڵ����ʾ���ֱ�ţ�indexΪ��ǰ���ڵ��λ�ú�
	if(index>maxn){
		maxn=index;
		ans=root;
	}
	if(a[root].l!=-1)dfs(a[root].l,index*2);
	if(a[root].r!=-1)dfs(a[root].r,index*2+1);
}
int main(){
	int n,root=0,have[30]={0};
	cin>>n;
	for(int i=0;i<n;i++){
		string l,r;
		cin>>l>>r;
		if(l=="-"){//ע��Ҫ��˫����
			a[i].l=-1;
		}else{
			a[i].l=stoi(l);//���ַ���ת����Ϊint
			have[stoi(l)]=1;//have�����ʾ�ýڵ��Ƿ��и��׽ڵ�
		}
		if(r=="-"){
			a[i].r=-1;
		}else{
			a[i].r=stoi(r);
			have[stoi(r)]=1;
		}
	}
	while(have[root]!=0)root++;//��������have���飬�ҵ�û�и��ڵ���Ǹ��ڵ�
	dfs(root,1);
	if(maxn==n)
		cout<<"YES "<<ans<<endl;//ע�����һ���ڵ�ı�Ŵ�ʱΪans
	else
		cout<<"NO "<<root<<endl;
	return 0;
}
