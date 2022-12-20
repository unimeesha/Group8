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

void update(){

	shares s1;
	FILE *fp, *fp1;
	int j, sno, found=0;
	fp = fopen ("output.txt","r");
	fp1 = fopen ("temp.txt","w");
	printf("ENTER STOCK_ID TO UPDATE: ");
	scanf("%d",&sno);

	while(fread(&s1,sizeof(shares),1,fp)){

		if (s1.sno == sno){
			found=1;

			fflush(stdin);
			printf("ENTER NEW STOCK NAME: ");
			scanf("%s",s1.name);
			fflush(stdin);
			printf("ENTER STOCK OPEN: ");
			scanf("%d",&s1.open);
			fflush(stdin);
			printf("ENTER STOCK HIGH: ");
			scanf("%d",&s1.high);
			fflush(stdin);
			printf("ENTER STOCK LOW: ");
			scanf("%d",&s1.low);
			fflush(stdin);
			printf("ENTER STOCK PREV_CLOSE: ");
			scanf("%d",&s1.prev_close);
			fflush(stdin);
			printf("ENTER STOCK VOLUME: ");
			scanf("%d",&s1.volume);


		}
		fwrite (&s1,sizeof(shares),1,fp1);

	}
	fclose(fp);
	fclose(fp1);
	if(found) {
		fp1 = fopen("temp.txt","r");
		fp = fopen("output.txt","w");

		while (fread(&s1,sizeof(shares),1,fp1)){
			fwrite(&s1,sizeof(shares),1,fp);
		}
		fclose(fp);
		fclose(fp1);
	}else
		printf("\nRECORD NOT FOUND");
}



