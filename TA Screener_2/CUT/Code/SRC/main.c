#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

int main(){
	int ch;
	do{
		printf("\n1.CREATE");
		printf("\n2.DISPLAY");
		printf("\n3.APPEND");
		printf("\n4.UPDATE");
		printf("\n5.DELETE");
		printf("\n6.HEIKIN");
		printf("\n0.EXIST");

		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&ch);

		switch (ch){
			case 1:
				create();
				break;
			case 2:
				display();
				break;

			case 3:
				append();
				break;

			case 4:
				update();
				break;
			case 5:
				delete_rec();
				break;
			case 6:
				heikin();
				break;

		}
	}while(ch!=0);


	return 0;
}

