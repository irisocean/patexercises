// daya_dayb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
int month[13][2] = {//平年和闰年每个月的天数
	{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}
};
bool isLeap(int year){//判断是否是闰年
	return(year % 4 == 0 && year % 100 != 0)||(year%400 == 0);
}
int main(){
	int time1,y1,m1,d1;
	int time2,y2,m2,d2;
	while(scanf("%d%d",&time1,&time2)!=EOF){//可以连续输入多组测试数据
		if(time1>time2){//如果time1比time2晚，则交换
			int temp = time1;
			time1 = time2;
			time2  = temp;
		}
		y1 = time1/10000,m1 = time1%10000/100,d1 = time1%100;
		y2 = time2/10000,m2 = time2%10000/100,d2 = time2%100;
		int ans = 1;//记录结果
		//第一个日期没有达到第二个日期时循环
		while(y1<y2 || m1<m2 || d1<d2){
			d1++;
			if(d1 == month[m1][isLeap(y1)]+1){//满当月天数，月份加一，日期变为下个月一号
				m1++;
				d1 = 1;
			}
			if(m1 == 13){//满12个月，年份加一，月份变为1月
				y1++;
				m1 = 1;
			}
			ans++;//累加天数
		}
		printf("%d\n",ans);
	}
	return 0;
}

