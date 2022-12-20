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

void delete_rec(){

	shares s1;
	FILE *fp, *fp1;
	int j, sno, found=0;
	fp = fopen ("output.txt","r");
	fp1 = fopen ("temp.txt","w");
	printf("ENTER STOCK ID TO DELETE: ");
	scanf("%d",&sno);

	while(fread(&s1,sizeof(shares),1,fp)){

		if (s1.sno == sno){
			found=1;


		}else

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

