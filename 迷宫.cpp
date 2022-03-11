

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int x,y;
char a[9][12]=
{"@#*********",
 "***###*###*",
 "###**#****#",
 "*#**###**#*",
 "***********",
 "#####*##*##",
 "**#*****#*E",
 "***#*###**#",
 "*#*********",
 };
 void map()//œ‘ æµÿÕº 
 {
 	int i,j;
	for(i=0;i<=8;i++)
	{
		for(j=0;j<=10;j++)
			printf("%c",a[i][j]); 
		printf("\n");
		
	}
 }
 void gx()
 {
	
	char key;
 	key=getch();
 	switch(key)
 	{
	 	case 'd':
		case 'D':if(y<10)
				 if(a[x][y+1]!='#')
				{	
					a[x][y]='*';
				 	a[x][y+1]='@';
				 	y=y+1;
				}
				 	break;
				
		case 'A':
		case 'a':if(y>0)
				if(a[x][y-1]!='#')
				{
					a[x][y]='*';
				 	a[x][y-1]='@'; 
					 y=y-1;
				}
					 break;
				
		case 'w':
	  	case 'W':if(x>0)
	  			 if(a[x-1][y]!='#')
		  		{ 
		  			a[x][y]='*';
	  	         	a[x-1][y]='@';
	  	         	x=x-1;
		  		}
	  	         	break;
	  	case 's':
	  	case 'S':if(x<8)
	  			 if(a[x+1][y]!='#')
		  		{	
				  
					  a[x][y]='*';
	  				 a[x+1][y]='@';	 
					 x=x+1;
		  		}
					 break;
		  		
	 }

		system("cls");
 	
 } 
int main()
 {
	while(1)
	{
		map();
		gx();
	}
	return 0;
 }

