#include <iostream>
#include <ctime>
using namespace std;
void board(char* spaces);
void p1choice(char* spaces, char playerOne);
void p2choice(char* spaces, char playerTwo);
bool checkWin(char* spaces, char playerOne, char playerTwo);
bool checkDraw(char* spaces);
int main() {
	char spaces[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
	char playerOne = 'X';
	char playerTwo = 'O';
	bool running = true;
	cout << "******** WELCOME TO TIC TAC TOE ********" << endl;
	


	while (running) {
		board(spaces);
		p1choice(spaces, playerOne);
		
		if (checkWin(spaces, playerOne, playerTwo)){
			board(spaces);
			
			break;
		}
		if (checkDraw(spaces)) {
			board(spaces);
			cout << "It's a draw!" << endl;
			break;
		}
		board(spaces);
		p2choice(spaces, playerTwo);
		
		if (checkWin(spaces, playerOne, playerTwo)) {
			board(spaces);
						
						break;
		}
		if (checkDraw(spaces)) {
			board(spaces);
			cout << "It's a draw!" << endl;
			break;
		}
	}


	cout << "******** THANKS FOR PLAYING!!!! ********" << endl;
	
	


	return 0;
}
void board(char* spaces) {
	cout << "     |     |     \n";
	cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "\n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "\n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "\n";
	cout << "     |     |     \n";
}
void p1choice(char* spaces, char playerOne) {
	int choice;
	cout << "Player1 (" << playerOne << "), choose a space(1 - 9): ";
	cin >> choice;

	while (choice < 1 || choice > 9 || spaces[choice - 1] != ' ') {
		cout << "Invalid choice. Try again: ";
		cin >> choice;

	}
	spaces[choice - 1] = playerOne;
}
void p2choice(char* spaces, char playerTwo) {
	int choice;
	cout << "Player2 (" << playerTwo << "), choose a space(1 - 9): ";
	cin >> choice;

	while (choice < 1 || choice > 9 || spaces[choice - 1] != ' ') {
		cout << "Invalid choice. Try again: ";
		cin >> choice;

	}
	spaces[choice - 1] = playerTwo;
}
bool checkWin(char* spaces, char playerOne, char playerTwo) {
	for (int i = 0; i < 3; i++) {
		if ((spaces[i * 3] == playerOne && spaces[i * 3 + 1] == playerOne && spaces[i * 3 + 2] == playerOne) ||
			(spaces[i] == playerOne && spaces[i + 3] == playerOne && spaces[i + 6] == playerOne)) {
			cout << " Player1 Wins\n";
			return true;
			break;
		}
		if ((spaces[0] == playerOne && spaces[4] == playerOne && spaces[8] == playerOne) ||
			(spaces[2] == playerOne && spaces[4] == playerOne && spaces[6] == playerOne)) {
			cout <<"Player1 wins\n";
			return true;
			break;
		}
		if ((spaces[0] == playerTwo && spaces[1] == playerTwo && spaces[2] == playerTwo) ||
			(spaces[3] == playerTwo && spaces[4] == playerTwo && spaces[5] == playerTwo) ||
			(spaces[6] == playerTwo && spaces[7] == playerTwo && spaces[8] == playerTwo) ||
			(spaces[0] == playerTwo && spaces[3] == playerTwo && spaces[6] == playerTwo) ||
			(spaces[1] == playerTwo && spaces[4] == playerTwo && spaces[7] == playerTwo) ||
			(spaces[2] == playerTwo && spaces[5] == playerTwo && spaces[8] == playerTwo) ||
			(spaces[0] == playerTwo && spaces[4] == playerTwo && spaces[8] == playerTwo) ||
			(spaces[2] == playerTwo && spaces[4] == playerTwo && spaces[6] == playerTwo)) {
			cout << "Player2 wins\n";
			return true;
			break;
		}
		return false;
	}



}
bool checkDraw(char* spaces) {
	for (int i = 0; i < 9; i++) {
		if (spaces[i] == ' ') {
			return false;
		}
	}
	return true;
}