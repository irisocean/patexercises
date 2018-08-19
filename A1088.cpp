// A1088.cpp : Defines the entry point for the console application.
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
}m,n;
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
F sum(F a,F b){
	F r;
	r.up=a.up*b.down+a.down*b.up;
	r.down=a.down*b.down;
	return easy(r);
}
F difference(F a,F b){
	F r;
	r.up=a.up*b.down-a.down*b.up;
	r.down=a.down*b.down;
	return easy(r);
}
F product(F a,F b){
	F r;
	r.up=a.up*b.up;
	r.down=a.down*b.down;
	return easy(r);
}
F quotient(F a,F b){
	F r;
	r.up=a.up*b.down;
	r.down=a.down*b.up;
	return easy(r);
}
void showout(F r){
	r=easy(r);
	if(r.up<0)printf("(");
	if(r.down==1)printf("%lld",r.up);
	else if(abs(r.up)>r.down){
		printf("%lld %lld/%lld",r.up/r.down,abs(r.up)%r.down,r.down);
	}else printf("%lld/%lld",r.up,r.down);
	if(r.up<0)printf(")");
}
int main(){
	scanf("%lld/%lld %lld/%lld",&m.up,&m.down,&n.up,&n.down);
	showout(m);
	printf(" + ");
	showout(n);
	printf(" = ");
	showout(sum(m,n));
	printf("\n");
	showout(m);
	printf(" - ");
	showout(n);
	printf(" = ");
	showout(difference(m,n));
	printf("\n");
	showout(m);
	printf(" * ");
	showout(n);
	printf(" = ");
	showout(product(m,n));
	printf("\n");
	showout(m);
	printf(" / ");
	showout(n);
	printf(" = ");
	if(n.up==0)printf("Inf");
	else showout(quotient(m,n));
	printf("\n");
	return 0;
}
