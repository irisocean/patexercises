// A1100.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
string unitDigit[13]={"tret","jan","feb","mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string numToStr[170];
map<string,int>strToNum;
void init(){
	for(int i=0;i<13;i++){
		numToStr[i]=unitDigit[i];
		strToNum[unitDigit[i]]=i;
		numToStr[i*13]=tenDigit[i];
		strToNum[tenDigit[i]]=i*13;
	}
	for(int i=1;i<13;i++){
		for(int j=1;j<13;j++){
			string str=tenDigit[i]+" "+unitDigit[j];
			numToStr[i*13+j]=str;
			strToNum[str]=i*13+j;
		}
	}
}
int main(){
	init();
	int n;
	scanf("%d%*c",&n);
	for(int i=0;i<n;i++){
		string str;
		getline(cin,str);
		if(str[0]>='0'&&str[0]<='9'){
			int num=0;
			for(int j=0;j<str.length();j++){
				num=num*10+(str[j]-'0');
			}
			cout<<numToStr[num]<<endl;
		}else{
			cout<<strToNum[str]<<endl;
		}
	}
	return 0;
}