// A1105.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int cmp1(int a,int b){
	return a>b;
}
int func(int N){//n�Ļ�ð취���Ӹ���N��ʼ���½����ҵ���һ����N���������ӣ�m��ΪN/n��������m�϶�����n��������֮����С
	int i=sqrt((double)N);
	while(i>=1){
		if(N%i==0)return i;
		i--;
	}
	return 1;
}
int main(){
	int N,m,n,t=0;
	scanf("%d",&N);
	n=func(N);
	m=N/n;
	vector<int>a(N);
	vector<vector<int>>b(m,vector<int>(n));
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);//vector������Ҫ��ȡ��ַ��
	}
	sort(a.begin(),a.end(),cmp1);
	for(int i=0;i<(m/2+m%2);i++){//����N����1������m��������Ҳ�����ò�����m%2���+1�����Լ����޷������Ƕ��������N=1�ͱ���Ҫ����m%2�ˣ�Ҳ���Ե���ŪN=1
		for(int j=i;j<=n-1-i && t<N;j++){
			b[i][j]=a[t++];
		}
		for(int j=i+1;j<=m-2-i && t<N;j++){
			b[j][n-1-i]=a[t++];
		}
		for(int j=n-1-i;j>=i && t<N;j--){
			b[m-1-i][j]=a[t++];
		}
		for(int j=m-2-i;j>=i+1 && t<N;j--){
			b[j][i]=a[t++];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d",b[i][j]);
			if(j!=n-1)printf(" ");
			else printf("\n");
		}
	}
	return 0;
}

