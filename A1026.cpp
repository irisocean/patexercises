// A1026.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct person{
	int arrive,start,time;
	bool vip;
}tempperson;
struct tablenode{
	int end,num;//num��ʾ�м�������������̨����
	bool vip;
};
vector<person>player;
vector<tablenode>table;
double round(double r){
	return floor(r+0.5);
}
int cmp1(person a,person b){
	return a.arrive<b.arrive;
}
int cmp2(person a,person b){
	return a.start<b.start;
}
int findnextvip(int vipid){
	vipid++;
	while(vipid<player.size() && player[vipid].vip==false)vipid++;
	return vipid;
}
void allocate(int personid,int tableid){
	if(player[personid].arrive<=table[tableid].end){
		player[personid].start=table[tableid].end;
	}else{
		player[personid].start=player[personid].arrive;
	}
	table[tableid].end=player[personid].start+player[personid].time;
	table[tableid].num++;
}
int main(){
	int n,k,m,viptable;
	scanf("%d",&n);
	for(int i=0;i<n;i++){//����ÿ����ҵ����ݣ����뵽�����У��ų�������ʱ��������ŵ��
		int hh,mm,ss,temptime,flag;
		scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&temptime,&flag);
		tempperson.arrive=hh*3600+mm*60+ss;
		tempperson.start=21*3600;
		if(tempperson.arrive>=21*3600)continue;
		tempperson.time=temptime<=120?temptime*60:7200;
		tempperson.vip=((flag==1)?true:false);
		player.push_back(tempperson);
	}
	scanf("%d%d",&k,&m);
	table.resize(k+1);
	for(int i=1;i<=k;i++){
		table[i].end=8*3600;
	}
	for(int i=0;i<m;i++){//�����Щ������vip
		scanf("%d",&viptable);
		table[viptable].vip=true;
	}
	sort(player.begin(),player.end(),cmp1);//������ҵĵ���ʱ������
	int i=0,vipid=-1;
	vipid=findnextvip(vipid);//�õ���һ��VIP��ҵı��
	while(i<player.size()){
		int index=-1,minendtime=999999999;
		for(int j=1;j<=k;j++){//�ҵ�Ŀǰ����ʱ�������̨����
			if(table[j].end<minendtime){
				minendtime=table[j].end;
				index=j;
			}
		}
		if(table[index].end>=21*3600)break;//�����С���ڵĽ���ʱ�䶼������ŵ㣬���˳�����ѭ��
		if(player[i].vip==true && i<vipid){//������ǰ��VIP����ƽ�ѭ������һ��VIP���
			i++;
			continue;
		}
		if(table[index].vip==true){//���Ŀǰ�ճ�����̨������VIP�������ж��Ƿ���VIP��ң������ֱ��ռ�ã�������ǣ��Ƚ�VIP��Һ͵�ǰ����
			                       //����ʱ�䣬��VIP�ȵ�����VIPռ�ã��������ζ�ſճ���VIP��û������ǰ���ռ��
			if(player[i].vip==true){
				allocate(i,index);
				if(i==vipid)vipid=findnextvip(vipid);
				i++;
			}
			else{
				if(vipid<player.size() && player[vipid].arrive<=table[index].end){//VIP���ռ�ã��ҵ�ǰ��Ҳ���VIP��ҵ�ʱ�򣬲���Ҫi++
					allocate(vipid,index);
					vipid=findnextvip(vipid);
				}else{
					allocate(i,index);
					i++;
				}
			}
		}
		else{//��ͨ��
			if(player[i].vip==false){//��ͨ���������ͨ��ֱ��ռ��
				allocate(i,index);
				i++;
			}else{//VIP���������ͨ����Ҫ���ҵ����������VIP����������VIP��ҵ��ı������VIP�����Ǹ�VIP��һ���ռ��VIP��������ռ����ͨ��
				int vipindex=-1,minvipendtime=999999999;
				for(int j=1;j<=k;j++){
					if(table[j].vip==true&&table[j].end<minvipendtime){
						minvipendtime=table[j].end;
						vipindex=j;
					}
				}
				if(vipindex!=-1 && player[i].arrive>=table[vipindex].end){
					allocate(i,vipindex);
					if(vipid==i)vipid=findnextvip(vipid);
					i++;
				}else{
					allocate(i,index);//ע�⣡����ռ�õ�����ͨ������VIP������ʱ����VIP��ң���ҪѰ����һ��VIP���
					if(vipid==i)vipid=findnextvip(vipid);
					i++;
				}
			}
		}
	}
	sort(player.begin(),player.end(),cmp2);
	for(int i=0;i<player.size()&&player[i].start<21*3600;i++){
		printf("%02d:%02d:%02d ",player[i].arrive/3600,(player[i].arrive%3600)/60,player[i].arrive%60);
		printf("%02d:%02d:%02d ",player[i].start/3600,(player[i].start%3600)/60,player[i].start%60);
		printf("%.0f\n",round((player[i].start-player[i].arrive)/60.0));
	}
	for(int i=1;i<=k;i++){
		if(i!=1)printf(" ");
		printf("%d",table[i].num);
	}
	printf("\n");
	return 0;
}


