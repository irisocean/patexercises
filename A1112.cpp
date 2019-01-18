// A1112.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<map>
#include<set>
using namespace std;
bool sureGood[256];//如果已经统计出连续k个字母s相同，但是后面出现少于k个连续字母s，那么就要用这个数组把map中的bool值更改掉
int main(){
	int k,cnt=1;
	cin>>k;
	string s;
	cin>>s;
	char pre='#';//因为要和前面的字符进行比较，所以在字符串前面
	s=s+'#';
	map<char,bool>m;
	set<char>printed;//统计坏掉的按键不能重复，所以用set来记录，set的特点就是元素不重复
	for(int i=0;i<s.length();i++){//初步循环一边，标记m和sureGood
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
	for(int i=0;i<s.length()-1;i++){//再根据sureGood修改一遍m
		if(sureGood[s[i]]==true)m[s[i]]=false;
	}
	for(int i=0;i<s.length()-1;i++){//输出换掉的按键，保证不重复输出
		if(m[s[i]]==true && printed.find(s[i])==printed.end()){
			printf("%c",s[i]);
			printed.insert(s[i]);
		}
	}
	printf("\n");
	for(int i=0;i<s.length()-1;i++){//去除重复的错误输出
		printf("%c",s[i]);
		if(m[s[i]]==true)i=i+k-1;//直接跳过重复的输出
	}
	return 0;
}