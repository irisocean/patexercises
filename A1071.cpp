// A1071.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<map>
using namespace std;
bool check(char c){
	if(c>='0'&&c<='9')return true;
	else if(c>='a'&&c<='z')return true;
	else if(c>='A'&&c<='Z')return true;
	return false;
}
int main(){
	map<string,int>count;
	string str;
	getline(cin,str);
	int i=0;
	while(i<str.length()){
		string word;
		while(i<str.length()&&check(str[i])==true){
			if(str[i]>='A'&&str[i]<='Z'){
				str[i]=str[i]-'A'+'a';
			}
			word+=str[i];
			i++;
		}
		if(word!=""){
			if(count.find(word)!=count.end())count[word]++;
			else count[word]=1;
		}
		while(i<str.length()&&check(str[i])==false){
			i++;
		}
	}
	string ans;
	int Max=0;
	for(map<string,int>::iterator it=count.begin();it!=count.end();it++){
		if(it->second>Max){
			ans=it->first;
			Max=it->second;
		}
	}
	cout<<ans<<" "<<Max<<endl;
	return 0;
}

