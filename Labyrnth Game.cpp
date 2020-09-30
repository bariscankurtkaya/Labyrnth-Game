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
	BARIŞCAN KURTKAYA GRUP:2 NUMARA: 17014090
	mail: l1417090@std.yildiz.edu.tr // bariscankurtkaya@gmail.com
	*/
int main()
{
	int skor=0;	//Skorunuz
	int hamle=0;//Hamle sayısı
	int i,j;	//While döngüleri için elemanlar
	int e= 0;	//e- sayısı
	int E= 0;	//e+ sayısı
	int p= 0;	//p- sayısı
	int P= 0;	//p+ sayısı
	int t= 0;	//envanter matris x elamanı
	int c= 0;	//getch fonksiyonu için kullanılan eleman
	int x= 1;	//Başlangıç x
	int y= 2;	//Başlangıç y
	int cx=6;	//cikis x
	int cy=5;	//cikis y
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
	
	while((y!=cy) or (x!=cx))  //Çıkış koordinantlarına gelmediği sürece oyundan çıkmayacak (!Karadelik ve ESC tuşu koordinantları direk çıkışa eşitler!)
    	{	
    		system ("CLS");
    		if (hamle>=0)
    		{
    			Lab[2][1]='G';
			}
    		for(i=0;i<N;i++)   //Matris'i ekrana yazdırma
			{
				printf("\n");
				for(j=0;j<M;j++)
					{
					printf("%c ", Lab[i][j]);
					}
			}
			printf("\ninventory: ");   //Topladığınız eşyaları envanterinizde görebilirsiniz
			for (i=0;i<N*M;i++)
			{
				printf("%c ", inventory[0][i]);
			}
			printf("\n%d %d", x,y);
    	    c = 0;
		    switch(c=getch()) 
			{
	   		    case KEY_UP:   //Yukarı yön tuşu
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
	      					printf("\nYOU DIED\nASAGIDA GORDUGUN BUTUN ESYALAR BOSA GITTI");
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
	   		    case KEY_DOWN:   //Aşağı yön tuşu
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
	      					printf("\nYOU DIED\nASAGIDA GORDUGUN BUTUN ESYALAR BOSA GITTI");
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
	   		    case KEY_LEFT:    //Sol yön tuşu
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
	      					printf("\nYOU DIED\nASAGIDA GORDUGUN BUTUN ESYALAR BOSA GITTI");
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
	  		    case KEY_RIGHT:   //Sağ yön tuşu
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
	      					printf("\nYOU DIED\nASAGIDA GORDUGUN BUTUN ESYALAR BOSA GITTI");
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
	   		    case ESC:   //Escape tuşu
	   		    		printf("\nQUIT\nCIKMADAN ONCE BUNLARI TOPLAMISTIN");
	   		    		y=cy;
	   		    		x=cx;
	   		    	break;
   		    }
   		}
   	for (i=0;i<N*M;i++)    //Toplanan eşyaları sayma kısmı
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
	if(p>P and E>e)    //Karşıt madde oluşup oluşmadığını öğrendiğimiz kısım
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
	printf("\n%d adet e \n%d adet E \n%d adet p \n%d adet P topladiniz",e,E,p,P);
	printf("\n%d adet Karsit madde uretildi. ", skor );
	
	return 0;
}	
