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

void heikin()
{
	shares s1;
	FILE *fp, *fp1;
	int i,n,found=0,sno;
	int HA_Open,HA_Close,HA_High,HA_Low,prev_open;
	fp = fopen ("output.txt","r");
	fp1 = fopen ("temp.txt","w");
	printf("ENTER STOCK ID TO CALCULATE HEIKIN ASHI: ");
	scanf("%d",&sno);
	printf("please enter previous open : ");
	scanf("%d",&prev_open);
	while(fread(&s1,sizeof(shares),1,fp))
	{
		if (s1.sno == sno)
		{
			found=1;
			HA_Close=((s1.open+s1.prev_close+s1.high+s1.low)/4);
			printf("Heikin ashi close : %d\n",HA_Close);
			HA_Open=((prev_open+s1.prev_close)/2);
			printf("Heikin ashi open : %d\n",HA_Open);
			HA_High= s1.high > HA_Close ? (s1.high > HA_Open ? s1.high : HA_Open) : (HA_Close > HA_Open ? HA_Close : HA_Open);
			printf("Heikin ashi high : %d\n",HA_High);
			HA_Low= s1.low < HA_Close ? (s1.low < HA_Open ? s1.low : HA_Open) : (HA_Close < HA_Open ? HA_Close : HA_Open);
			printf("Heikin ashi low : %d\n",HA_Low);
			if(HA_High > HA_Low)
			{
				printf("Recommended to buy\n");
			}
			else
			{
				printf("Recommend to sell\n");

			}
		}
	}
}

