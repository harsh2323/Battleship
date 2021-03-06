#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iomanip>

using namespace std;

bool shipHit = false;

string player1;
string player2;

int row1 = 0;
int row2 = 0;

int col1 = 0;
int col2 = 0;

int rowcolguess1[2] = {};
int rowcolguess2[2] = {};

int playerPos1[2] = {};
int playerPos2[2] = {};


string fBoard11[12][12] = {};
string fBoard22[12][12] = {};

void drawBoard(){

	string board[12][12] = {};
	cout << "  0 1 2 3 4 5" << endl;
	cout << "____________________" << endl;
	for(int i = 0; i < 6 ; i++){
		cout << i << "|";
		
		for( int j = 0 ; j < 6 ; j++){

			board[i][j] = {"0 "};

			cout << board[i][j] ;
 		}

 		cout << endl;
	}

}

void drawBoardPlayer1(){

	
	cout << "  0 1 2 3 4 5" << endl;
	cout << "_____________" << endl;
	for(int i = 0; i < 6 ; i++){
		cout << i << "|";
		for(int j = 0; j < 12 ; j++){
			if(i == rowcolguess1[0] && j == rowcolguess1[1]){
				fBoard11[i][j] = {"#"};
			}
			cout << fBoard11[i][j] << "  ";

		}
		cout << endl;

	}
}


void drawBoardPlayer2(){


	cout << "  0 1 2 3 4 5" << endl;
	cout << "_____________" << endl;
	for(int i = 0; i < 6 ; i++){
		cout << i << "|";
		for(int j = 0; j < 12 ; j++){
			if(i == rowcolguess2[0] && j == rowcolguess2[1]){
				
				fBoard22[i][j] = {"#"};
			}
			cout << fBoard22[i][j] << "  " ;

		}
		cout << endl;

	}
}



void finalBoard1(){

	string fBoard1[6][6] = {};
	cout << "  0 1 2 3 4 5" << endl;
	cout << "_____________" << endl;
	for(int i = 0; i < 6 ; i++){
		cout << i << "|";
		for(int j = 0; j < 6 ; j++){
			
			if(i == playerPos1[0] && j == playerPos1[1]){
				fBoard1[i][j] = {"#"};
			}
			else{
				fBoard1[i][j] = {"0"};
			}

			cout << fBoard1[i][j] << " ";

		}
		cout << endl;

	}
}

void finalBoard2(){

	string fBoard2[6][6] = {};
	cout << "  0 1 2 3 4 5" << endl;
	cout << "_____________" << endl;
	for(int i = 0; i < 6 ; i++){
		cout << i << "|";
		for(int j = 0; j < 6 ; j++){

			if(i == playerPos2[0] && j == playerPos2[1]){
				fBoard2[i][j] = {"#"};
			}
			else{
				fBoard2[i][j] = {"0"};
			}

			cout << fBoard2[i][j] << " ";

		}
		cout << endl;
	}
}

void playerName(){
	cout << "Enter the name of the first player: ";
	cin >> player1;

	cout << "Enter the name of the second player: ";
	cin >> player2;

}

void playerShip(){


	cout << "Player1 " << "\nEnter the position you want to store your ship in(please provide the row and column number:" << endl;
	cout << "ROW: ";
	cin >> row1;
	cout << "COLUMN: " ;
	cin >> col1;

	playerPos1[0] = row1;
	playerPos1[1] = col1;


	cout << "Player2 " << "\nEnter the position you want to store your ship in(please provide the row and column number:" << endl;
	cout << "ROW: ";
	cin >> row2;
	cout << "COLUMN: " ;
	cin >> col2;

	playerPos2[0] = row2;
	playerPos2[1] = col2;

}


void showPlayerShip(){

	string delim = "";

	cout << "Player 1's ship is at ";
	for( auto a: playerPos1 ){
		cout << delim << a;
		delim = ", ";
	}

	delim = "";

	cout << endl; 

	cout << "Player 2's ship is at ";
	for( auto b: playerPos2 ){
		cout << delim << b ;
		delim = ", ";
	}
 
}


void playerInputs(){


	int rowGuess1;
	int colguess1;

	int rowGuess2;
	int colguess2;

	while(shipHit == false){
//Player 1
		cout << player1 << endl;
		cout << "Enter a guess where you think player 2 has hidden their ship in: ";
		cout << "Row: ";
		cin >> rowGuess1;
		cout << "Column: ";
		cin >> colguess1;

		rowcolguess1[0] = rowGuess1;
		rowcolguess1[1] = colguess1;

 		if(rowGuess1 == playerPos2[0] && colguess1 == playerPos2[1]){
			cout << "Congratulations " << player1 << ", you won" << endl << endl;
			shipHit = true;
		}

		else{
			cout << "You did not hit the target" << endl;
			drawBoardPlayer1();
		}

//Player 2

		cout << player2 << endl;
		cout << "Enter a guess where you think player 2 has hidden their ship in: ";
		cout << "Row: ";
		cin >> rowGuess2;
		cout << "Column: ";
		cin >> colguess2;

		rowcolguess2[0] = rowGuess2;
		rowcolguess2[1] = colguess2;

		if(rowGuess2 == playerPos1[0] && colguess2 == playerPos1[1]){
			shipHit = true;
			cout << "Congratulations " << player2 << ", you won";
		}

		else{
			cout << "You did not hit the target" << endl;
			drawBoardPlayer2();
		}

	}

}



int main(){
	cout << "Welcome to battleship:" << endl;
	cout << "       .  o .. " << endl;
	cout << "       o . o o.o" << endl;
	cout << "    ...oo  " << endl << endl;
	cout << "   __[]__" << endl;
	cout << "__|_o_o_o\\__" << endl;
	cout << "\\^^^^^^^^^^/" << endl;
	cout << " \\. ..  . /" << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^" << endl;

     cout << endl;

	drawBoard();
	playerName();
	playerShip();
	playerInputs();
	//showPlayerShip();
	cout << player1 << "'s ship placement: " << endl;
	finalBoard1();
	cout << player2 << "'s ship placement: " << endl;
	finalBoard2();
	return 0;

}
