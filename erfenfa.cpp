// erfenfa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
int binarySearch(int A[],int left,int right,int x){
	int mid;
	while(left<=right){
		mid=(left+right)/2;
		if(A[mid]==x)return mid;
		else if(A[mid]>x){
			right=mid-1;
		}
		else left=mid+1;
	}
	return -1;
}
int main(){
	const int n=10;
	int A[n]={1,3,4,6,7,8,10,11,12,15};
	printf("%d ",binarySearch(A,0,n-1,6));
	printf("%d\n",binarySearch(A,0,n-1,9));
	return 0;
}
