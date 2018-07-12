// A1027.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
char table[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
int main(){
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	printf("#");
	printf("%c%c",table[r/13],table[r%13]);
	printf("%c%c",table[g/13],table[g%13]);
	printf("%c%c\n",table[b/13],table[b%13]);
	return 0;
}

