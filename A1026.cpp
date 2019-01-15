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
	int end,num;//num表示有几个玩家用了这个台球桌
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
	for(int i=0;i<n;i++){//读入每个玩家的数据，加入到队列中，排除掉到达时间晚于晚九点的
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
	for(int i=0;i<m;i++){//获得哪些桌子是vip
		scanf("%d",&viptable);
		table[viptable].vip=true;
	}
	sort(player.begin(),player.end(),cmp1);//根据玩家的到达时间排序
	int i=0,vipid=-1;
	vipid=findnextvip(vipid);//拿到下一个VIP玩家的编号
	while(i<player.size()){
		int index=-1,minendtime=999999999;
		for(int j=1;j<=k;j++){//找到目前结束时间最早的台球桌
			if(table[j].end<minendtime){
				minendtime=table[j].end;
				index=j;
			}
		}
		if(table[index].end>=21*3600)break;//如果最小窗口的结束时间都大于晚九点，就退出结束循环
		if(player[i].vip==true && i<vipid){//跳过当前的VIP玩家推进循环到下一个VIP玩家
			i++;
			continue;
		}
		if(table[index].vip==true){//如果目前空出来的台球桌是VIP桌，先判断是否是VIP玩家，如果是直接占用，如果不是，比较VIP玩家和当前桌的
			                       //结束时间，若VIP先到，则VIP占用，否则就意味着空出来VIP还没到，则当前玩家占用
			if(player[i].vip==true){
				allocate(i,index);
				if(i==vipid)vipid=findnextvip(vipid);
				i++;
			}
			else{
				if(vipid<player.size() && player[vipid].arrive<=table[index].end){//VIP玩家占用，且当前玩家不是VIP玩家的时候，不需要i++
					allocate(vipid,index);
					vipid=findnextvip(vipid);
				}else{
					allocate(i,index);
					i++;
				}
			}
		}
		else{//普通桌
			if(player[i].vip==false){//普通玩家遇到普通桌直接占用
				allocate(i,index);
				i++;
			}else{//VIP玩家遇到普通桌需要先找到最早结束的VIP桌，如果这个VIP玩家到的比最早的VIP桌晚，那该VIP玩家还是占用VIP桌，否则占用普通桌
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
					allocate(i,index);//注意！无论占用的是普通桌还是VIP桌，此时都是VIP玩家，需要寻找下一个VIP玩家
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


