#include <stdio.h>
#include <stdlib.h>



void CalculateMoves(int , int);
void Print(int);
char* numberToChar(int);
void PossibleMovesPrint();
char* intToChar(int);
int charToInt(char);

int board[8][8]={
	{2,3,4,5,6,4,3,2},
	{1,1,1,1,1,1,1,1},
	{10,10,10,10,10,10,10,10},
	{10,10,10,10,10,10,10,10},
	{10,10,10,10,10,10,10,10},
	{10,10,10,10,10,10,10,10},
	{11,11,11,11,11,11,11,11},
	{12,13,14,15,16,14,13,12}
};
int moveNumber;

int main(){	
	int i, j, k, turn;
	int turnCount = 0;
	int x,y;
	int status=0;
	
	Print(turnCount);
	
	turn=1;	//1 ise beyaz; 2 ise siyah
	
	
	while(status==0)
	{
		k=0;
		
		while(k==0)
		{
			if(turn==1)
				puts("Player 1 (W): \n");
			else
				puts("Player 2 (B): \n");
			
			i=8;
			j=8;
			int z = 0;
			while(z==0)
			{
				
					printf("Select a piece :\n");
					char str[4];
 					   scanf("%s",str);
					char a= str[0];
					char b= str[1];
					j=charToInt(a);
					i=8-((int)b-'0');
					// i satır & j sütün
					if (i<=7 && i>=0)
					{
						if (j<=7 && j>=0)
						{
							z++;
						}
						else
						{
							printf("\nIncorrect selection, ");
						}
						
					}
					
			}
			
			if(turn==1)
			{
				if(board[i][j]<=10)
				{
					printf("[!] Invalid Taş \n");
					i=0;
				}
				
				else
				{
					k=1;
					turn=2;
					turnCount++;
				}
			}
			
			else
			{
				if(board[i][j]>=10)
				{
					printf("[!] Invalid Taş \n");
					i=0;
				}
				
				else
				{
					k=1;
					turn=1;
					turnCount++;
				}
			}
			
		}
		int m;
		int d = 0;
		CalculateMoves(i,j);
		int moves[100][2];
		while (d==0)
		{
			printf("Press   ");
			PossibleMovesPrint(i,j);
			printf("\n");
			scanf("%d",&m);
			
			
			int countMove=0;
			for (int k = 0; k < 8; k++)
				{
				for (int l = 0; l < 8; l++)
				{
					if (board[k][l]<0)
					{
						moves[countMove][0]=k;
						moves[countMove][1]=l;
						countMove++;
					}
				}
			}
			
			if (m>0)
			{
				if (m<=countMove)
				{
					d++;
				}else
				{
					printf("Please select valid move !\n");
				}
			}else
				{
					printf("Please select valid move !\n");
				}
			
		}
		
		
		x=moves[m-1][0];
		y=moves[m-1][1];
		
		if(turn==1)
		{
			if(board[x][y]<0)
			{
				board[x][y]=board[i][j];
				board[i][j]=10;
			}
			
			
			else
			{
				printf("[!] Invalid Hamle \n");
				turn=2;
			}
			
		}
		
		else
		{
			if(board[x][y]<0)
			{
				board[x][y]=board[i][j];
				board[i][j]=10;
			}
			
			else
			{
				printf("[!] Invalid Hamle \n");
				turn=1;
			}
			
		}
		
		for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		{
			if(board[i][j]<0) board[i][j]=0-board[i][j];
		}
		
		Print(turnCount);
		
	}
	return 0;
}


void Print(int t){
    printf("\n");
    system("clear");
    
    printf(" \n");
	printf("Chess Board: (t = %d)\n",t/2);
    for (int i = 0; i < 8; i++)
    {
        printf("  %d  ",8-i);
        for (int j = 0; j < 8; j++)
        {
            char* s =numberToChar(board[i][j]);
            printf("  %s  ",s);
        }
        printf(" \n \n");
    }
	printf("\n       A     B     C     D     E     F     G     H   \n");
}

char* numberToChar(int a){
    switch (a)
    {

    case 1:
        return "BP";
        break;
    case 2:
        return "BR";
        break;
    case 3:
        return "BK";
        break;
    case 4:
        return "BB";
        break;
    case 5:
        return "BQ";
        break;
    case 6:
        return "BG";
        break;
    case 11:
        return "WP";
        break;
    case 12:
        return "WR";
        break;
    case 13:
        return "WK";
        break;
    case 14:
        return "WB";
        break;
    case 15:
        return "WQ";
        break;
    case 16:
        return "WG";
        break;
    
    default:
        return "0 ";
        break;
    }
}

void CalculateMoves(int pos_x,int pos_y)
{
	int i, j;
	
	switch(board[pos_x][pos_y])
	{
		case 1: // The Pawn
		{
			if(pos_x<8)
			board[pos_x+1][pos_y]=0-board[pos_x+1][pos_y];
			
			if(pos_x==1)
			board[pos_x+2][pos_y]=0-board[pos_x+2][pos_y];
			
			if(board[pos_x+1][pos_y+1]>10)
			board[pos_x+1][pos_y+1]=0-board[pos_x+1][pos_y+1];
			
			if(board[pos_x+1][pos_y-1]>10)
			board[pos_x+1][pos_y-1]=0-board[pos_x+1][pos_y-1];
			
			break;
		}
		
		case 2: //The Rook
		{
			i=pos_x+1;
			while( (board[i][pos_y]==10) && (i<8) )
			{
				board[i][pos_y]=0-board[i][pos_y];
				i++;
			}
			if(i<8)
			if(board[i][pos_y]>10)
			board[i][pos_y]=0-board[i][pos_y];
			
			
			i=pos_x-1;
			while( (board[i][pos_y]==10) && (i>=0) )
			{
				board[i][pos_y]=0-board[i][pos_y];
				i--;
			}
			if(i>=0)
			if(board[i][pos_y]>10)
			board[i][pos_y]=0-board[i][pos_y];
			
			
			i=pos_y+1;
			while( (board[pos_x][i]==10) && (i<8) )
			{
				board[pos_x][i]=0-board[pos_x][i];
				i++;
			}
			if(i<8)
			if(board[pos_x][i]>10)
			board[pos_x][i]=0-board[pos_x][i];
			
			
			i=pos_y-1;
			while( (board[pos_x][i]==10) && (i>=0) )
			{
				board[pos_x][i]=0-board[pos_x][i];
				i--;
			}
			if(i>=0)
			if(board[pos_x][i]>10)
			board[pos_x][i]=0-board[pos_x][i];
			
			break;
		}
		
		case 3: //The Knight
		{
			if( ( pos_x-1>=0 && pos_x-1<8 ) && ( pos_y+2>=0 && pos_y+2<8 ) )
			if( board[pos_x-1][pos_y+2]>=10 )
			board[pos_x-1][pos_y+2]=0-board[pos_x-1][pos_y+2];//0
			
			if( ( pos_x-2>=0 && pos_x-2<8 ) && ( pos_y+1>=0 && pos_y+1<8 ) )
			if( board[pos_x-2][pos_y+1]>=10 )
			board[pos_x-2][pos_y+1]=0-board[pos_x-2][pos_y+1];//1
			
			if( ( pos_x-2>=0 && pos_x-2<8 ) && ( pos_y-1>=0 && pos_y-1<8 ) )
			if( board[pos_x-2][pos_y-1]>=10 )
			board[pos_x-2][pos_y-1]=0-board[pos_x-2][pos_y-1];//2
			
			if( ( pos_x-1>=0 && pos_x-1<8 ) && ( pos_y-2>=0 && pos_y-2<8 ) )
			if( board[pos_x-1][pos_y-2]>=10 )
			board[pos_x-1][pos_y-2]=0-board[pos_x-1][pos_y-2];//3
			
			if( ( pos_x+1>=0 && pos_x+1<8 ) && ( pos_y-2>=0 && pos_y-2<8 ) )
			if( board[pos_x+1][pos_y-2]>=10 )
			board[pos_x+1][pos_y-2]=0-board[pos_x+1][pos_y-2];//4
			
			if( ( pos_x+2>=0 && pos_x+2<8 ) && ( pos_y-1>=0 && pos_y-1<8 ) )
			if( board[pos_x+2][pos_y-1]>=10 )
			board[pos_x+2][pos_y-1]=0-board[pos_x+2][pos_y-1];//5
			
			if( ( pos_x+2>=0 && pos_x+2<8 ) && ( pos_y+1>=0 && pos_y+1<8 ) )
			if( board[pos_x+2][pos_y+1]>=10 )
			board[pos_x+2][pos_y+1]=0-board[pos_x+2][pos_y+1];//6
			
			if( ( pos_x+1>=0 && pos_x+1<8 ) && ( pos_y+2>=0 && pos_y+2<8 ) )
			if( board[pos_x+1][pos_y+2]>=10 )
			board[pos_x+1][pos_y+2]=0-board[pos_x+1][pos_y+2];//7
			
			break;
		}
		
		case 4://The Bishop
		{
			i=pos_x+1; j=pos_y+1;
			while( (board[i][j]==10) && ( i<8 && j<8 ) )
			{
				board[i][j]=0-board[i][j];
				i++;j++;
			}
			if( i<8 && j<8 )
			if(board[i][j]>10)
			board[i][j]=0-board[i][j];
			
			
			i=pos_x-1; j=pos_y+1;
			while( (board[i][j]==10) && ( i>=0 && j<8 ) )
			{
				board[i][j]=0-board[i][j];
				i--;j++;
			}
			if( i>=0 && j<8 )
			if(board[i][j]>10)
			board[i][j]=0-board[i][j];
			
			
			i=pos_x-1; j=pos_y-1;
			while( (board[i][j]==10) && ( i>=0 && j>=0 ) )
			{
				board[i][j]=0-board[i][j];
				i--;j--;
			}
			if( i>=0 && j>=0 )
			if(board[i][j]>10)
			board[i][j]=0-board[i][j];
			
			
			i=pos_x+1; j=pos_y-1;
			while( ( board[i][j]==10 ) && ( i<8 && j>=0 ) )
			{
				board[i][j]=0-board[i][j];
				i++;j--;
			};
			if( i<8 && j>=0 )
			if(board[i][j]>10)
			board[i][j]=0-board[i][j];
			
			break;
		}
		
		case 5://The Quinn
		{
			i=pos_x+1;
			while( (board[i][pos_y]==10) && (i<8) )
			{
				board[i][pos_y]=0-board[i][pos_y];
				i++;
			}
			if(i<8)
			if(board[i][pos_y]>10)
			board[i][pos_y]=0-board[i][pos_y];
			
			
			i=pos_x-1;
			while( (board[i][pos_y]==10) && (i>=0) )
			{
				board[i][pos_y]=0-board[i][pos_y];
				i--;
			}
			if(i>=0)
			if(board[i][pos_y]>10)
			board[i][pos_y]=0-board[i][pos_y];
			
			
			i=pos_y+1;
			while( (board[pos_x][i]==10) && (i<8) )
			{
				board[pos_x][i]=0-board[pos_x][i];
				i++;
			}
			if(i<8)
			if(board[pos_x][i]>10)
			board[pos_x][i]=0-board[pos_x][i];
			
			
			i=pos_y-1;
			while( (board[pos_x][i]==10) && (i>=0) )
			{
				board[pos_x][i]=0-board[pos_x][i];
				i--;
			}
			if(i>=0)
			if(board[pos_x][i]>10)
			board[pos_x][i]=0-board[pos_x][i];
			
			i=pos_x+1; j=pos_y+1;
			while( (board[i][j]==10) && ( i<8 && j<8 ) )
			{
				board[i][j]=0-board[i][j];
				i++;j++;
			}
			if( i<8 && j<8 )
			if(board[i][j]>10)
			board[i][j]=0-board[i][j];
			
			
			i=pos_x-1; j=pos_y+1;
			while( (board[i][j]==10) && ( i>=0 && j<8 ) )
			{
				board[i][j]=0-board[i][j];
				i--;j++;
			}
			if( i>=0 && j<8 )
			if(board[i][j]>10)
			board[i][j]=0-board[i][j];
			
			
			i=pos_x-1; j=pos_y-1;
			while( (board[i][j]==10) && ( i>=0 && j>=0 ) )
			{
				board[i][j]=0-board[i][j];
				i--;j--;
			}
			if( i>=0 && j>=0 )
			if(board[i][j]>10)
			board[i][j]=0-board[i][j];
			
			
			i=pos_x+1; j=pos_y-1;
			while( ( board[i][j]==10 ) && ( i<8 && j>=0 ) )
			{
				board[i][j]=0-board[i][j];
				i++;j--;
			};
			if( i<8 && j>=0 )
			if(board[i][j]>10)
			board[i][j]=0-board[i][j];
			
			break;
		}
		
		case 6://The King
		{
			if( board[pos_x-1][pos_y-1]>=10 )
			board[pos_x-1][pos_y-1]=0-board[pos_x-1][pos_y-1];
			
			if( board[pos_x-1][pos_y]>=10 )
			board[pos_x-1][pos_y]=0-board[pos_x-1][pos_y];
			
			if( board[pos_x-1][pos_y+1]>=10 )
			board[pos_x-1][pos_y+1]=0-board[pos_x-1][pos_y+1];
			
			if( board[pos_x][pos_y-1]>=10 )
			board[pos_x][pos_y-1]=0-board[pos_x][pos_y-1];
			
			if( board[pos_x][pos_y+1]>=10 )
			board[pos_x][pos_y+1]=0-board[pos_x][pos_y+1];
			
			if( board[pos_x+1][pos_y-1]>=10 )
			board[pos_x+1][pos_y-1]=0-board[pos_x+1][pos_y-1];
			
			if( board[pos_x+1][pos_y]>=10 )
			board[pos_x+1][pos_y]=0-board[pos_x+1][pos_y];
			
			if( board[pos_x+1][pos_y+1]>=10 )
			board[pos_x+1][pos_y+1]=0-board[pos_x+1][pos_y+1];
			
			break;
		}
		
		case 11: 
		{
			if(pos_x>=0)
			board[pos_x-1][pos_y]=0-board[pos_x-1][pos_y];
			
			if(pos_x==6)
			board[pos_x-2][pos_y]=0-board[pos_x-2][pos_y];
			
			if(board[pos_x-1][pos_y+1]<10)
			board[pos_x-1][pos_y+1]=0-board[pos_x-1][pos_y+1];
			
			if(board[pos_x-1][pos_y-1]<10)
			board[pos_x-1][pos_y-1]=0-board[pos_x-1][pos_y-1];
			
			break;
		}
		
		case 12: 
		{
			i=pos_x+1;
			while( (board[i][pos_y]==10) && (i<8) )
			{
				board[i][pos_y]=0-board[i][pos_y];
				i++;
			}
			if(i<8)
			if(board[i][pos_y]<10)
			board[i][pos_y]=0-board[i][pos_y];
			
			
			i=pos_x-1;
			while( (board[i][pos_y]==10) && (i>=0) )
			{
				board[i][pos_y]=0-board[i][pos_y];
				i--;
			}
			if(i>=0)
			if(board[i][pos_y]<10)
			board[i][pos_y]=0-board[i][pos_y];
			
			
			i=pos_y+1;
			while( (board[pos_x][i]==10) && (i<8) )
			{
				board[pos_x][i]=0-board[pos_x][i];
				i++;
			}
			if(i<8)
			if(board[pos_x][i]<10)
			board[pos_x][i]=0-board[pos_x][i];
			
			
			i=pos_y-1;
			while( (board[pos_x][i]==10) && (i>=0) )
			{
				board[pos_x][i]=0-board[pos_x][i];
				i--;
			}
			if(i>=0)
			if(board[pos_x][i]<10)
			board[pos_x][i]=0-board[pos_x][i];
			
			break;
		}
		
		case 13: 
		{
			if( ( pos_x-1>=0 && pos_x-1<8 ) && ( pos_y+2>=0 && pos_y+2<8 ) )
			if( board[pos_x-1][pos_y+2]<=10 )
			{ 
			board[pos_x-1][pos_y+2]=0-board[pos_x-1][pos_y+2];
			}
			
			if( ( pos_x-2>=0 && pos_x-2<8 ) && ( pos_y+1>=0 && pos_y+1<8 ) )
			if( board[pos_x-2][pos_y+1]<=10 )
			{ 
			board[pos_x-2][pos_y+1]=0-board[pos_x-2][pos_y+1];
			}
			
			if( ( pos_x-2>=0 && pos_x-2<8 ) && ( pos_y-1>=0 && pos_y-1<8 ) )
			if( board[pos_x-2][pos_y-1]<=10 )
			{ 
			board[pos_x-2][pos_y-1]=0-board[pos_x-2][pos_y-1];
			}
			
			if( ( pos_x-1>=0 && pos_x-1<8 ) && ( pos_y-2>=0 && pos_y-2<8 ) )
			if( board[pos_x-1][pos_y-2]<=10 )
			{ 
			board[pos_x-1][pos_y-2]=0-board[pos_x-1][pos_y-2];
			}
			
			if( ( pos_x+1>=0 && pos_x+1<8 ) && ( pos_y-2>=0 && pos_y-2<8 ) )
			if( board[pos_x+1][pos_y-2]<=10 )
			{ 
			board[pos_x+1][pos_y-2]=0-board[pos_x+1][pos_y-2];
			}
			
			if( ( pos_x+2>=0 && pos_x+2<8 ) && ( pos_y-1>=0 && pos_y-1<8 ) )
			if( board[pos_x+2][pos_y-1]<=10 )
			{ 
			board[pos_x+2][pos_y-1]=0-board[pos_x+2][pos_y-1];
			}
			
			if( ( pos_x+2>=0 && pos_x+2<8 ) && ( pos_y+1>=0 && pos_y+1<8 ) )
			if( board[pos_x+2][pos_y+1]<=10 )
			{ 
			board[pos_x+2][pos_y+1]=0-board[pos_x+2][pos_y+1];
			}
			
			if( ( pos_x+1>=0 && pos_x+1<8 ) && ( pos_y+2>=0 && pos_y+2<8 ) )
			if( board[pos_x+1][pos_y+2]<=10 )
			{ 
			board[pos_x+1][pos_y+2]=0-board[pos_x+1][pos_y+2];
			}
			
			break;
		}
		
		case 14:
		{
			i=pos_x+1; j=pos_y+1;
			while( (board[i][j]==10) && ( i<8 && j<8 ) )
			{
				board[i][j]=0-board[i][j];
				i++;j++;
			}
			if( i<8 && j<8 )
			if(board[i][j]<10)
			board[i][j]=0-board[i][j];
			
			
			i=pos_x-1; j=pos_y+1;
			while( (board[i][j]==10) && ( i>=0 && j<8 ) )
			{
				board[i][j]=0-board[i][j];
				i--;j++;
			}
			if( i>=0 && j<8 )
			if(board[i][j]<10)
			board[i][j]=0-board[i][j];
			
			
			i=pos_x-1; j=pos_y-1;
			while( (board[i][j]==10) && ( i>=0 && j>=0 ) )
			{
				board[i][j]=0-board[i][j];
				i--;j--;
			}
			if( i>=0 && j>=0 )
			if(board[i][j]<10)
			board[i][j]=0-board[i][j];
			
			
			i=pos_x+1; j=pos_y-1;
			while( ( board[i][j]==10 ) && ( i<8 && j>=0 ) )
			{
				board[i][j]=0-board[i][j];
				i++;j--;
			};
			if( i<8 && j>=0 )
			if(board[i][j]<10)
			board[i][j]=0-board[i][j];
			
			break;
		}
		
		case 15:
		{
			i=pos_x+1;
			while( (board[i][pos_y]==10) && (i<8) )
			{
				board[i][pos_y]=0-board[i][pos_y];
				i++;
			}
			if(i<8)
			if(board[i][pos_y]<10)
			board[i][pos_y]=0-board[i][pos_y];
			
			
			i=pos_x-1;
			while( (board[i][pos_y]==10) && (i>=0) )
			{
				board[i][pos_y]=0-board[i][pos_y];
				i--;
			}
			if(i>=0)
			if(board[i][pos_y]<10)
			board[i][pos_y]=0-board[i][pos_y];
			
			
			i=pos_y+1;
			while( (board[pos_x][i]==10) && (i<8) )
			{
				board[pos_x][i]=0-board[pos_x][i];
				i++;
			}
			if(i<8)
			if(board[pos_x][i]<10)
			board[pos_x][i]=0-board[pos_x][i];
			
			
			i=pos_y-1;
			while( (board[pos_x][i]==10) && (i>=0) )
			{
				board[pos_x][i]=0-board[pos_x][i];
				i--;
			}
			if(i>=0)
			if(board[pos_x][i]<10)
			board[pos_x][i]=0-board[pos_x][i];
			
			
			i=pos_x+1; j=pos_y+1;
			while( (board[i][j]==10) && ( i<8 && j<8 ) )
			{
				board[i][j]=0-board[i][j];
				i++;j++;
			}
			if( i<8 && j<8 )
			if(board[i][j]<10)
			board[i][j]=0-board[i][j];
			
			
			i=pos_x-1; j=pos_y+1;
			while( (board[i][j]==10) && ( i>=0 && j<8 ) )
			{
				board[i][j]=0-board[i][j];
				i--;j++;
			}
			if( i>=0 && j<8 )
			if(board[i][j]<10)
			board[i][j]=0-board[i][j];
			
			
			i=pos_x-1; j=pos_y-1;
			while( (board[i][j]==10) && ( i>=0 && j>=0 ) )
			{
				board[i][j]=0-board[i][j];
				i--;j--;
			}
			if( i>=0 && j>=0 )
			if(board[i][j]<10)
			board[i][j]=0-board[i][j];
			
			
			i=pos_x+1; j=pos_y-1;
			while( ( board[i][j]==10 ) && ( i<8 && j>=0 ) )
			{
				board[i][j]=0-board[i][j];
				i++;j--;
			};
			if( i<8 && j>=0 )
			if(board[i][j]<10)
			board[i][j]=0-board[i][j];
			
			break;
		}
		
		case 16:
		{
			if( board[pos_x-1][pos_y-1]<=10 )
			board[pos_x-1][pos_y-1]=0-board[pos_x-1][pos_y-1];
			
			if( board[pos_x-1][pos_y]<=10 )
			board[pos_x-1][pos_y]=0-board[pos_x-1][pos_y];
			
			if( board[pos_x-1][pos_y+1]<=10 )
			board[pos_x-1][pos_y+1]=0-board[pos_x-1][pos_y+1];
			
			if( board[pos_x][pos_y-1]<=10 )
			board[pos_x][pos_y-1]=0-board[pos_x][pos_y-1];
			
			if( board[pos_x][pos_y+1]<=10 )
			board[pos_x][pos_y+1]=0-board[pos_x][pos_y+1];
			
			if( board[pos_x+1][pos_y-1]<=10 )
			board[pos_x+1][pos_y-1]=0-board[pos_x+1][pos_y-1];
			
			if( board[pos_x+1][pos_y]<=10 )
			board[pos_x+1][pos_y]=0-board[pos_x+1][pos_y];
			
			if( board[pos_x+1][pos_y+1]<=10 )
			board[pos_x+1][pos_y+1]=0-board[pos_x+1][pos_y+1];
			
			break;
		}
	}
	
}

void PossibleMovesPrint(){
    int moves[100][2];
    int count=0;
    for (int k = 0; k < 8; k++)
    {
        for (int l = 0; l < 8; l++)
        {
            if (board[k][l]<0)
            {
                moves[count][0]=k;
                moves[count][1]=l;
                count++;
            }
            
        }
        
    }

    for (int i = 0; i < count; i++)
    {
        char* ptr_a = intToChar(moves[i][1]);
        char a= *ptr_a;
        printf(" %d: %c%d   ",i+1,a,8-(moves[i][0]));
    }
}

int charToInt(char b){
	int a = (int)b;
	if (a-'a'==0 || a-'A'==0)
	{
		return 0;
	}else if (a-'b'==0||a-'B'==0)
	{
		return 1;
	}
	else if (a-'c'==0||a-'C'==0)
	{
		return 2;
	}
	else if (a-'d'==0||a-'D'==0)
	{
		return 3;
	}else if (a-'e'==0||a-'E'==0)
	{
		return 4;
	}else if (a-'f'==0||a-'F'==0)
	{
		return 5;
	}else if (a-'g'==0||a-'G'==0)
	{
		return 6;
	}else if (a-'h'==0||a-'H'==0)
	{
		return 7;
	}else
	{
		return 33;
	}
	
}

char* intToChar(int a){
    
    switch (a)
    {

    case 0:
        return "A";
        break;
    
    case 1:
        return "B";
        break;
    
    case 2:
        return "C";
        break;
    
    case 3:
        return "D";
        break;
    
    case 4:
        return "E";
        break;
    
    case 5:
        return "F";
        break;
    
    case 6:
        return "G";
        break;
    
    case 7:
        return "H";
        break;
    
    default:
        return "Error";
        break;
    }
}