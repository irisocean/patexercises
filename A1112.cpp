// A1112.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<map>
#include<set>
using namespace std;
bool sureGood[256];//����Ѿ�ͳ�Ƴ�����k����ĸs��ͬ�����Ǻ����������k��������ĸs����ô��Ҫ����������map�е�boolֵ���ĵ�
int main(){
	int k,cnt=1;
	cin>>k;
	string s;
	cin>>s;
	char pre='#';//��ΪҪ��ǰ����ַ����бȽϣ��������ַ���ǰ��
	s=s+'#';
	map<char,bool>m;
	set<char>printed;//ͳ�ƻ����İ��������ظ���������set����¼��set���ص����Ԫ�ز��ظ�
	for(int i=0;i<s.length();i++){//����ѭ��һ�ߣ����m��sureGood
		if(s[i]==pre)cnt++;
		else{
			if(cnt%k!=0){
				sureGood[pre]=true;
			}
			cnt=1;
		}
		if(i!=s.length()-1)m[s[i]]=(cnt%k==0);
		pre=s[i];
	}
	for(int i=0;i<s.length()-1;i++){//�ٸ���sureGood�޸�һ��m
		if(sureGood[s[i]]==true)m[s[i]]=false;
	}
	for(int i=0;i<s.length()-1;i++){//��������İ�������֤���ظ����
		if(m[s[i]]==true && printed.find(s[i])==printed.end()){
			printf("%c",s[i]);
			printed.insert(s[i]);
		}
	}
	printf("\n");
	for(int i=0;i<s.length()-1;i++){//ȥ���ظ��Ĵ������
		printf("%c",s[i]);
		if(m[s[i]]==true)i=i+k-1;//ֱ�������ظ������
	}
	return 0;
}