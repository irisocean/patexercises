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
//深度遍历找到最有一个节点的位置号，与节点总数比较，如果相同，就是完全二叉树
void dfs(int root,int index){//root为当前根节点的显示数字编号，index为当前根节点的位置号
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
		if(l=="-"){//注意要用双引号
			a[i].l=-1;
		}else{
			a[i].l=stoi(l);//将字符串转换成为int
			have[stoi(l)]=1;//have数组表示该节点是否有父亲节点
		}
		if(r=="-"){
			a[i].r=-1;
		}else{
			a[i].r=stoi(r);
			have[stoi(r)]=1;
		}
	}
	while(have[root]!=0)root++;//遍历整个have数组，找到没有父节点的那个节点
	dfs(root,1);
	if(maxn==n)
		cout<<"YES "<<ans<<endl;//注意最后一个节点的编号此时为ans
	else
		cout<<"NO "<<root<<endl;
	return 0;
}
