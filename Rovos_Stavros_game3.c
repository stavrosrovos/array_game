#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void game_array(void);
void game_menu(void);
int total_tries=0,ROWS,COLS,have_played=0,b=0,a;
int main(void)
{
	srand(time(NULL));
	game_menu();
	return 0;
}
void game_menu(void)
{
	START:
	printf("\nMEMORY CARD GAME MENU\n");
	printf("1) play   2) level   3) stats   4) exit\n");
	printf("Dialeje: ");
	CHOOSE_OPTION:	
	scanf("%d",&a);
	printf("\n");
	switch(a)
	{
		case 1:
		have_played = 1;
		if(b == 0)
		{
			b = 2;
			ROWS = 4;
			COLS = 4;
		}
		game_array();
		goto START; 
		
		case 2:
		printf("1) easy(2x2)   2) medium(4X4)   3) hard(6X6)\n");
		printf("Dialeje level: ");
		CHOOSE_LEVEL:
		scanf("%d",&b);
		printf("\n");
		switch(b)
		{
			case 1:
			ROWS = 2;
			COLS = 2;
			break;
			
			case 2:
			ROWS = 4;
			COLS = 4;
			break;
			
			case 3:
			ROWS = 6;
			COLS = 6;
			break;
			
			default:
			printf("\nDen dialejes swsta!Janadialeje: ");
			goto CHOOSE_LEVEL;
		}
		goto START;
		
		case 3:
		if(have_played == 1)
		{
			if(b == 1)
				printf("To level toy paixnidioy htan to easy(2X2)!\n");
			else if(b == 2)
				printf("To level toy paixnidioy htan to medium(4X4)!\n");
			else
				printf("To level toy paixnidioy htan to hard(6X6)!\n");
				
			printf("\nTa kataferes meta apo %d prospa8eies\n",total_tries+1);
		}
		else
		{
			printf("\nDen yparxoyn stats dioti den exeis paijei akoma!\n");
		}
		goto START;
		
		case 4:
		printf("Eyxaristoyme poy symmeteixes sto paixnidi mas!Kalh synexeia!");
		exit(0);
		
		default:
		printf("\nDen dialejes swsta!Janadialeje: ");
		goto CHOOSE_OPTION;		
	}
}
void game_array(void)
{
	int sum=0,found=0,i,j,a,b,c,d,e,used_num[(ROWS*ROWS/2)+1],arr[ROWS][COLS],print_elements[ROWS][COLS];
	for(i=0; i<=(ROWS*ROWS/2)+1; i++)
	{
		used_num[i] = 0;
	}
	
	for(i=0; i<ROWS; i++)
	{
		for(j=0; j<COLS; j++)
		{	do {
				a = 1 + rand()%(ROWS*ROWS/2);
				arr[i][j] = a;
			} while (used_num[a] == 2);
			used_num[a]++;
		}
	}
	
	for(i=0; i<ROWS; i++)
	{
		for(j=0; j<COLS; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	
	for(i=0; i<ROWS; i++)
	{
		for(j=0; j<COLS; j++)
		{
			print_elements[i][j] = 0;
		}
	}
	while(1) 
	{
		do {
			printf("\nEisagete grammh kai sthlh gia na emfanistei to stoixeio(anamesa pathste space): ");
			scanf("%d %d",&i,&j);
			printf("\n");
			a = i;
			b = j;
			if(print_elements[a-1][b-1] > 0)
				printf("\nTo exete janaeisagei ayto to stoixeio!\n\n");
			else if(a>ROWS || b>COLS)
				printf("\nTo stoixeio poy grapsate einai ektos oriwn toy pinaka!\n\n");
		} while ((print_elements[a-1][b-1] > 0) || (a>ROWS || b>COLS));
		
		for(i=0; i<ROWS; i++)
		{
			for(j=0; j<COLS; j++)
			{
				if((i == a-1 && j == b-1) || (print_elements[i][j] != 0))
				{
					printf("%d ",arr[i][j]);
					print_elements[i][j]++;
					if((found == 0) && (print_elements[i][j] == 1))
					{
						c = arr[i][j];
						d = i;
						e = j;
					}
					sum++;
					if(sum == ROWS*COLS)
					{
						printf("\nSygxarhthria! Kerdises!\n");
						game_menu();
					}
				}
				else
				{
					printf("* ");
				}	
			}
			printf("\n");
		}
		sum = 0;
		found++;
		if(found == 2)
		{
			found = 0;
			total_tries++;
			if(arr[a-1][b-1] == arr[d][e])
				printf("\nTa stoixeia tairiajane!\n");
			else 
			{
				printf("\nTa stoixeia den tairiajane!\n");
				print_elements[a-1][b-1] = 0;
				print_elements[d][e] = 0;	
			}
			d = 0;
			e = 0;
		}
	}
}
