#include <iostream>
#include <iomanip>
using namespace std;
void showbalance(double balance);
double deposit();
double withdraw(double balance);
int main() {
	double balance = 0;
	int choice = 0;
	do {
		cout << "Enter choice:";
		cout << "1. Show Balance" << endl;
		cout << "2. Deposit" << endl;
		cout << "3. Withdraw" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			showbalance(balance);
			break;
		case 2:
			balance += deposit();
			
			showbalance(balance);
			break;
		case 3:
			balance -= withdraw(balance);
			
			showbalance(balance);
			break;
		case 4:
			cout << "********THANKS FOR VISITING********" << endl;
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 4);

	return 0;
}

void showbalance(double balance) {
	cout << "Balance is : $" << setprecision(2) << fixed << balance << endl;
}
double deposit() {
	double amount;
	cout << "Enter deposit amount: ";
	cin >> amount;
	if(amount < 0) {
		cout << "Deposit amount cannot be negative." << endl;
		return 0;
	}
	return amount;
}
double withdraw(double balance) {
	cout << "Enter withdrawal amount: ";
	double amount;
	cin >> amount;
	if(amount < 0) {
		cout << "Withdrawal amount cannot be negative." << endl;
		return 0;
	}
	else if(amount > balance) {
		cout << "Insufficient funds. Cannot withdraw more than the current balance." << endl;
		return 0;
	}
	return amount;
}
