// A1081.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
struct F{
	ll up,down;
};
F easy(F r){
	if(r.down<0){
		r.up=-r.up;
		r.down=-r.down;
	}else if(r.up==0){
		r.down=1;
	}else{
		int d=gcd(abs(r.up),abs(r.down));
		r.up/=d;
		r.down/=d;
	}
	return r;
}
F add(F a,F b){
	F r;
	r.up=a.up*b.down+a.down*b.up;
	r.down=a.down*b.down;
	return easy(r);
}
void showout(F r){
	easy(r);
	if(r.down==1)printf("%lld\n",r.up);
	else if(r.up>r.down)printf("%lld %lld/%lld\n",r.up/r.down,abs(r.up)%r.down,r.down);
	else printf("%lld/%lld\n",r.up,r.down);
}
int main(){
	int n;
	scanf("%d",&n);
	F sum,temp;
	sum.up=0,sum.down=1;
	for(int i=0;i<n;i++){
		scanf("%lld/%lld",&temp.up,&temp.down);
		sum=add(sum,temp);
	}
	showout(sum);
	return 0;
}