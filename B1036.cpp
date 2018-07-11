#include<stdio.h>
int main(){
	int row,col;
	char c;
	scanf("%d %c",&col,&c);
	if(col%2==0){
		row = col/2;
	}else{
		row = col/2+1;
	}
	for(int i=0;i<col;i++){
		printf("%c",c);
	}
	printf("\n");
	for(int i=1;i<row-1;i++){
		printf("%c",c);
		for(int j=1;j<col-1;j++){
			printf(" ");
		}
		printf("%c\n",c);
	}
	for(int i=0;i<col;i++){
		printf("%c",c);
	}
	printf("\n");
	return 0;
}