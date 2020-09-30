#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iso646.h>
#define N 8
#define M 8
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27
/*
	Author: BARIŞCAN KURTKAYA 
	bariscankurtkaya@gmail.com
	*/
int main()
{
	int skor=0;	//Score 
	int hamle=0;	//Number of moves
	int i,j;	//Elements for while loops
	int e= 0;	//number of e- 
	int E= 0;	//number of e+
	int p= 0;	//number of p-
	int P= 0;	//number of p+
	int t= 0;	//inventory matrix x element
	int c= 0;	//The element used for the getch function
	int x= 1;	//Start x
	int y= 2;	//Start y
	int cx=6;	//Exit x
	int cy=5;	//Exit y
	char k= '0';
	char Lab[N][M]= {
{'1','1','K','0','0','p','0','0'},
{'0','0','e','0','0','0','0','0'},
{'0','G','1','1','1','0','0','1'},
{'p','0','0','0','1','0','1','1'},
{'0','1','P','0','E','0','E','1'},
{'E','1','0','0','1','0','C','1'},
{'0','1','0','0','0','0','0','0'},
{'0','0','p','p','E','1','1','0'}
};
	char inventory[1][N*M]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
	Lab[y][x]= 'X';
	Lab[cy][cx]= 'C';
	
	while((y!=cy) or (x!=cx))  //It will not exit the game unless it reaches the exit coordinates (! Black Hole and ESC key coordinates are equal to direct exit!)
    	{	
    		system ("CLS");
    		if (hamle>=0)
    		{
    			Lab[2][1]='G';
			}
    		for(i=0;i<N;i++)   //Printing the matrix to the screen
			{
				printf("\n");
				for(j=0;j<M;j++)
					{
					printf("%c ", Lab[i][j]);
					}
			}
			printf("\ninventory: ");   //You can see the items you collect in your inventory
			for (i=0;i<N*M;i++)
			{
				printf("%c ", inventory[0][i]);
			}
			printf("\n%d %d", x,y);
    	    c = 0;
		    switch(c=getch()) 
			{
	   		    case KEY_UP:   //Up arrow key
	   		    		if (Lab[y-1][x] != '0' and Lab[y-1][x] != '1' and Lab[y-1][x] != 'K' and y!=0)
	   		    		{
							if(Lab[y-1][x]!='G')
							{
								inventory[0][t] =Lab[y-1][x];
	      					}
							Lab[y][x]='0';
	      					Lab[y-1][x]= 'X';
	      					y--;
	      					t++;
	      					hamle++;
	      					break;
	      				}
	      				else if(Lab[y-1][x]== '1' or y==0)
	      				{
	      					break;
						}
	      				else if(Lab[y-1][x]== 'K')
	      				{
	      					printf("\nYOU DIED\nSEE BELOW ALL ITEMS GONE WASTE");
							y=cy;
	      					x=cx;
	      					break;
						}
	      				else;
	      				{
	      					Lab[y][x]='0';
	      					Lab[y-1][x]= 'X';
	      					y--;
	      					break;
	      				}
	   		        break;
	   		    case KEY_DOWN:   //Down arrow key
	      				if(Lab[y+1][x] != '0' and Lab[y+1][x] != '1' and Lab[y+1][x] != 'K' and y!=7 )
	   		    		{
	   		    			if(Lab[y+1][x]!='G')
							{
								inventory[0][t] =Lab[y+1][x];
	      					}
		      				Lab[y][x]='0';
		      				Lab[y+1][x]= 'X';
		      				y++;
		      				t++;
		      				hamle++;
		      				break;
		      			}
		      			else if(Lab[y+1][x]== '1' or y==7)
	      				{
	      					break;
						}
	      				else if(Lab[y+1][x]== 'K')
	      				{
	      					printf("\nYOU DIED\nSEE BELOW ALL ITEMS GONE WASTE");
							y=cy;
	      					x=cx;
	      					break;
						}
		      			else;
		      			{
		      				Lab[y][x]='0';
		      				Lab[y+1][x]= 'X';
		      				y++;
		      				break;
		      			}
	   		        break;
	   		    case KEY_LEFT:    //Left arrow key
	   		    		if(Lab[y][x-1]!='0' and Lab[y][x-1] != '1' and Lab[y][x-1] != 'K' and x!=0)
	   		    		{
	   		    			if(Lab[y][x-1]!='G')
							{
								inventory[0][t] =Lab[y][x-1];
	      					}
		      				Lab[y][x]='0';
		    	  			Lab[y][x-1]='X';
		      				x--;
		      				t++;
		      				hamle++;
		      				break;
		      			}
	      				else if(Lab[y][x-1]== '1' or x==0)
	      				{
	      					break;
						}
	      				else if(Lab[y][x-1]== 'K')
	      				{
	      					printf("\nYOU DIED\nSEE BELOW ALL ITEMS GONE WASTE");
	      					y=cy;
	      					x=cx;
	      					break;
						}
		   		    	else;
		   		    	{
		      				Lab[y][x]='0';
		    	  			Lab[y][x-1]='X';
		      				x--;
		      				break;
		      			}
	    	        break;
	  		    case KEY_RIGHT:   //Right arrow key
	  		    		if(Lab[y][x+1]!='0' and Lab[y][x+1] != '1' and Lab[y][x+1] !=  'K' and x!=7)
	   		    		{
	   		    			if(Lab[y][x+1]!='G')
							{
								inventory[0][t] =Lab[y][x+1];
	      					}
		      				Lab[y][x]='0';
		      				Lab[y][x+1]= 'X';
		      				x++;
		      				t++;
		      				hamle++;
		      				break;
		      			}
	      				else if(Lab[y][x+1]== '1' or x==7)
	      				{
	      					break;
						}
	      				else if(Lab[y][x+1]== 'K')
	      				{
	      					printf("\nYOU DIED\nSEE BELOW ALL ITEMS GONE WASTE");
							y=cy;
	      					x=cx;
	      					break;
						}
		  		    	else;
		  		    	{
		      				Lab[y][x]='0';
		      				Lab[y][x+1]= 'X';
		      				x++;
		      				break;
		      			}
	   		        break;
	   		    case ESC:   //Escape key
	   		    		printf("\nQUIT\nYOU COLLECTED THESE BEFORE EXIT");
	   		    		y=cy;
	   		    		x=cx;
	   		    	break;
   		    }
   		}
   	for (i=0;i<N*M;i++)    //Counting items collected
   		{
   			if(inventory[0][i]=='P')
   			{
   				P++;
			}
			else if(inventory[0][i]=='p')
			{
				p++;
			}
			if(inventory[0][i]=='e')
			{
				e++;
			}
			if(inventory[0][i]=='E')
			{
				E++;
			}
		}
	if(p>P and E>e)    //The part where we learn whether the opposite substance is formed
	{
		if(p-P>E-e)
		{
			skor=E-e;
		}
		else;
		{
			skor=p-P;
		}
	}
	printf("You collected \n%d e - \n%d  E - \n%d  p - \n%d P ",e,E,p,P);
	printf("\n%d counters of opposite matters were produced ", skor );
	
	return 0;
}	
