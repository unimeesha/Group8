#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

typedef struct shares{
	int sno;
	char name[20];
	int open;
	int high;
	int low ;
	int prev_close;
	int volume;

}shares;

void display(){
	int j;
	shares s1;
	FILE *fp;

	fp = fopen ("output.txt","r");
	printf("\n%10s %10s %10s %10s %10s %10s %10s","STOCK_ID|","STOCK_NAME|","STOCK_OPEN|","STOCK_HIGH|","STOCK_LOW|","STOCK_PREV_CLOSE|","STOCK_VOLUME");
	while(fread(&s1,sizeof(shares),1,fp)){
		printf("\n%-10d%-10s%10d%10d%10d%10d%20d",s1.sno,s1.name,s1.open,s1.high,s1.low,s1.prev_close,s1.volume);


	}
	fclose(fp);



}

