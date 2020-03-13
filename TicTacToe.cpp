//Developed By Ajay Singh 

#include<stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "loading.h"

using namespace std;

char board[3][3] =  {
	          	   {'1', '2', '3'},
			   {'4', '5', '6'},
			   {'7', '8', '9'}	
		    };
				
	int input;
	int row, column;
	char turn = 'X';
	
	string player1;
	string player2;
	bool draw = false;
	
	// The main playing Board
	void displayBoard()
	{
		system("cls");
	    
		system("color 0A");
	
		cout<<endl<<endl;
	    
		cout<<"\t\t\t\xB2 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Tic Tac Toe Game \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \xB2\n";
	    
		cout<<"\t\t\t _______________________________________________ \n";
	    
		cout<<"\t\t\t|\t\t\t\t\t\t|\n";
	    
		cout<<"\t\t\t|\t\t\t\t\t\t|\n"; 
	    
		cout<<"\t\t\t|\t\t     |     |     \t\t|"<<endl;
	    
		cout<<"\t\t\t|\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \t\t|"<<endl;
	    
		cout<<"\t\t\t|\t\t_____|_____|_____\t\t|"<<endl;
	    
		cout<<"\t\t\t|\t\t     |     |     \t\t|"<<endl;
	    
		cout<<"\t\t\t|\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \t\t|"<<endl;
	    
		cout<<"\t\t\t|\t\t_____|_____|_____\t\t|"<<endl;
	    
		cout<<"\t\t\t|\t\t     |     |     \t\t|"<<endl;
	    
		cout<<"\t\t\t|\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \t\t|"<<endl;
	    
		cout<<"\t\t\t|\t\t     |     |     \t\t|"<<endl;
	    
		cout<<"\t\t\t|\t\t\t\t\t\t|"<<endl<<"\t\t\t|\t\t\t\t\t\t|"<<endl;   
	    
		cout<<"\t\t\t|_______________________________________________|\t";
		
	}
	    
    void choice()
    {
    	cout<<endl<<"\n\n\t\t\t";
		
		if(turn == 'X')
		{
			cout<<player1<<"'s turn [X] : ";
		}
		
		if(turn == 'O')
		{
			cout<<player2<<"'s turn [O] : ";
		}
		
		
		cin>>input;  
		
		switch(input)
    	{
    		case 1 : row = 0 ; column = 0; 
    		break;
    		
			case 2 : row = 0 ; column = 1; 
    		break;
    		
    		case 3 : row = 0 ; column = 2;
			break;
    			
			case 4 : row = 1 ; column = 0;
			break;
		
			case 5 : row = 1 ; column = 1;
			break;
    		
			case 6 : row = 1 ; column = 2;
			break;
    		
			case 7 : row = 2 ; column = 0;
			break;
    		
    		case 8 : row = 2 ; column = 1;
			break;
			
			case 9 : row = 2 ; column = 2;
			break;
    		
			default:
    			cout<<"\t\t\tWrong input\n";
    			    			
		}
	
	   if( turn == 'X' && (board[row][column] != 'X') && (board[row][column] != 'O') )
		{
			board[row][column] ='X';
			turn = 'O';
		}
		
		else if( turn == 'O' && (board[row][column] != 'X') && (board[row][column] != 'O') )
		{
			board[row][column] ='O';
			turn = 'X';
		}
		
		else
		{
			cout<<"\t\t\tposition already filled !, try again";
			choice();
		}
		
		displayBoard();
	}
	
	// to check if the game is over :)

bool gameOver()

{
	for( int i = 0 ; i < 3 ; i++ )	

	if( ( board[i][0] == board[i][1] && board[i][0] == board[i][2] ) || (board[0][i] == board[1][i] && board[0][i] == board[2][i] ) )
	
	return false; //false
			
	if( ( board[0][0] == board[1][1] && board[0][0] == board[2][2] ) || (board[0][2] == board[1][1] && board[0][2] == board[2][0] ) )
	
	return false;	//false
		
	// traversing whole board to check if there are any unfilled positions
	
	for(int i = 0 ; i < 3 ; i++)

	for(int j = 0 ; j < 3 ; j++)

	if( board[i][j] != 'X' && board[i][j] != 'O')

	return true; //false
	
	draw = true; //true
	
	return false;//false		
}

int main()
{
		
 	loadingBar();
	
	system("cls");
	
	system("color 0A");
	
	cout<<"\n\n------------------------------------------\xB2 Welcome To Tic Toe By Ajay Singh \xB2----------------------------------------";
	
	cout<<"\n\n\n\n\t\t\tEnter player 1 name : ";
	cin>>player1;
	
	cout<<"\n\n\t\t\tEnter player 2 name : ";
	cin>>player2;
		
		while(gameOver()) // will execute following  functions until game is over.
		
		{
			displayBoard();
	
			choice();
	
			gameOver();
		}
		
		if( turn == 'O' && draw == false )
		cout<<"\n\n\t\t\t"<<player1 <<" Wins!\a \n\n";
		
		else if( turn == 'X' && draw == false )
		cout<<"\n\n\t\t\t"<<player2 <<" Wins! \a\n\n";
		
		else
		cout<<"\n\n\t\t\t Match Draw! \a \n\n";
	
	getch();
	
	return 0;
}

