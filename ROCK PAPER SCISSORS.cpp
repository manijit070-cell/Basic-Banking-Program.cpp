#include <iostream>
#include <ctime>
using namespace std;

char getuserchoice();
char getcomputerchoice();
void showchoice(char choice);
void choosewinner(char player, char computer);

int main() {
    char player;
    char computer;
	

    while (true) {
        player = getuserchoice();
        if (player == 'E') { 
            showchoice(player);
            break;
        }

        cout << "You chose: ";
        showchoice(player);

        computer = getcomputerchoice();
        cout << "Computer chose: ";
        showchoice(computer);

        choosewinner(player, computer);
    }

    return 0;
}

char getuserchoice() {
    char player;
    cout << "ROCK PAPER SCISSORS GAME!" << endl;
    do {
        cout << "Enter choice (R = Rock, P = Paper, S = Scissors, E = Exit): ";
        cin >> player;
        player = toupper(player); 
    } while (player != 'R' && player != 'P' && player != 'S' && player != 'E');

    return player;
}

char getcomputerchoice() {
    srand(time(0));
    int num = rand() % 3 + 1;
    switch (num) {
    case 1: return 'R';
    case 2: return 'P';
    case 3: return 'S';
    default: return 'R';
    }
}

void showchoice(char choice) {
    switch (choice) {
    case 'E': cout << "THANKS FOR PLAYING!!!" << endl; break;
    case 'R': cout << "Rock" << endl; break;
    case 'P': cout << "Paper" << endl; break;
    case 'S': cout << "Scissors" << endl; break;
    default: cout << "Invalid choice!" << endl; break;
    }
}

void choosewinner(char player, char computer) {
    if (player == computer) {
        cout << "It's a tie!" << endl;
    }
    else if ((player == 'R' && computer == 'S') ||
        (player == 'P' && computer == 'R') ||
        (player == 'S' && computer == 'P')) {
        cout << "You win!" << endl;
    }
    else {
        cout << "Computer wins!" << endl;
    }
}
