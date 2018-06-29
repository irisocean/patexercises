// B1012.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
int main(){
	int N,temp;
	scanf("%d",&N);
	int count[5]={0};
	int ans[5]={0};
	for(int i=0;i<N;i++){
		scanf("%d",&temp);
		if(temp%5 == 0){
			if(temp%2 == 0){
				ans[0]+=temp;
				count[0]++;
			}
		}
		else if(temp%5 == 1){
			count[1]++;
			if(count[1]%2 == 1){
				ans[1]+=temp;
			}
			else{
				ans[1]-=temp;
			}
			
		}
		else if(temp%5 == 2){
			count[2]++;
			ans[2] = count[2];
		}
		else if(temp%5 == 3){
			count[3]++;
			ans[3]+=temp;
		}
		else {
			count[4]++;
			if(temp>ans[4]){
				ans[4]=temp;
			}
		}
	}
	if(count[0] == 0) printf("N ");
	else printf("%d ",ans[0]);
	if(count[1] == 0) printf("N ");
	else printf("%d ",ans[1]);
	if(count[2] == 0) printf("N ");
	else printf("%d ",ans[2]);
	if(count[3] == 0) printf("N ");
	else printf("%.1f ",(float)ans[3]/count[3]);
	if(count[4] == 0) printf("N");
	else printf("%d",ans[4]);
	return 0;


}