// A1108.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	vector<double>integers;
	char c;
	for(int i=0;i<n;i++){
		vector<char>temp;
		c=getchar();
		while(c!=' ' && c!='\n'){
			temp.push_back(c);
			c=getchar();
		}
		int k=-1;//kΪС����λ��
		int flag=1,tag=0,fu=1;//flag=1Ϊ��Ч���֣�tag=0Ϊ������tag=1ΪС����fu=1Ϊ������fu=-1Ϊ����
		for(int j=0;j<temp.size();j++){
			if(temp[j]=='.'){
				tag=1;
				k=j;
				if(temp.size()>j+3){
					flag=0;
					break;
				}
			}
			else{
				if(temp[j]<'0'||temp[j]>'9'){
					if((j==0) && (temp[j]=='-')){
						fu=-1;
					}else{
						flag=0;
						break;
					}
				}
			}
		}
		double a=0.00;
		int l=1;
		double p=0.10;
		if(flag==1&&tag==1&&k>0&&k<temp.size()){//��Ч��С��
			if(fu==1){//��Ч����С��
				for(int m=k-1;m>=0;m--){
					a+=(temp[m]-'0')*l;
					l=l*10;
				}
				for(int m=k+1;m<temp.size();m++){
					a+=(temp[m]-'0')*p;
					p=p*0.1;
				}
			}else{//��Ч�ĸ�С��
				for(int m=k-1;m>0;m--){
					a+=(temp[m]-'0')*l;
					l=l*10;
				}
				for(int m=k+1;m<temp.size();m++){
					a+=(temp[m]-'0')*p;
					p=p*0.1;
				}
				a=a*fu;
			}
			if(a<=1000&&a>=-1000){//��Ҫ�����Ƿ�����Ч��ֵ��������
				integers.push_back(a);
			}else flag=0;
		}else if(flag==1 && tag==0){//��Ч����
			if(fu==1){//��Ч������
				for(int m=temp.size()-1;m>=0;m--){
					a+=(temp[m]-'0')*l;
					l=l*10;
				}
			}else{//��Ч������
				for(int m=temp.size()-1;m>0;m--){
					a+=(temp[m]-'0')*l;
					l=l*10;
				}
				a=a*fu;
			}
			if(a>=-1000 && a<=1000){integers.push_back(a);}
			else flag=0;
		}
		if(flag==0){
			printf("ERROR: ");
			for(int m=0;m<temp.size();m++){
				printf("%c",temp[m]);
			}
			printf(" is not a legal number\n");
		}
	}
	double b=0.00;
	for(int i=0;i<integers.size();i++){
		b+=integers[i];
	}
	double ave=b/integers.size();
	if(integers.size()==0){
		printf("The average of 0 numbers is Undefined\n");
	}else if(integers.size()==1){
		printf("The average of 1 number is %.2f\n",integers[0]);
	}else{
		printf("The average of %d numbers is %.2f\n",integers.size(),ave);
	}
	return 0;
}
