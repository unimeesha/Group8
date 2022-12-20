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

void append(){

	shares *s;

	FILE *fp;
	int n, i, j;
	int total=20;

	printf("ENTER HOW MANY SHARED YOU WANT ADD: ");
	scanf("%d",&n);



	s = (shares*)calloc(n, sizeof(shares));
	fp =fopen("output.txt","a");

	fseek(fp,0,SEEK_END);
	j=ftell(fp)/sizeof(shares);

	int allowed_count=total-j;
	printf("\nNO OF RECORDS=%d",j);
	printf("\nYOU ARE ALLOWED TO ENTER ONLY =%d",allowed_count);
	if (n<=allowed_count){


		for(i=0;i<n;i++){


			printf("\nENTER STOCK ID: ");
			scanf("%d",&s[i].sno);
			fflush(stdin);
			printf("ENTER STOCK NAME: ");
			scanf("%s",s[i].name);
			fflush(stdin);
			printf("ENTER STOCK OPEN: ");
			scanf("%d",&s[i].open);
			fflush(stdin);
			printf("ENTER STOCK HIGH: ");
			scanf("%d",&s[i].high);
			fflush(stdin);
			printf("ENTER STOCK LOW: ");
			scanf("%d",&s[i].low);
			fflush(stdin);
			printf("ENTER STOCK PREV_CLOSE: ");
			scanf("%d",&s[i].prev_close);
			fflush(stdin);
			printf("ENTER STOCK VOLUME: ");
			scanf("%d",&s[i].volume);


			fwrite(&s[i],sizeof(shares),1,fp);
		}
		fclose(fp);
	}else{

		printf("\nYOU ENTERED MORE THAN LIMIT =%d",allowed_count);

		fclose(fp);
	}
}


