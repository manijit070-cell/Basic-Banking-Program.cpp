#include <iostream>
#include <cmath>    
using namespace std;

long long factorial(int n) {
    if (n < 0) return -1;
    long long fact = 1;
    for (int i = 1; i <= n; ++i)
        fact *= i;
    return fact;
}

int main() {
    double num1, num2;
    char op;

    cout << "Available operators: +  -  *  /  %  ^  r (sqrt)  ! (factorial)" << endl;
    cout << "Enter operator: ";
    cin >> op;

    if (op == 'r') {
        cout << "Enter number: ";
        cin >> num1;
        if (num1 < 0)
            cout << "Error: Square root of negative number is not real." << endl;
        else
            cout << "Result: " << sqrt(num1) << endl;
    }
    else if (op == '!') {
        int n;
        cout << "Enter an integer: ";
        cin >> n;
        if (n < 0)
            cout << "Error: Factorial of negative number not defined." << endl;
        else
            cout << "Result: " << factorial(n) << endl;
    }
    else {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        switch (op) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error: Division by zero." << endl;
            break;
        case '%':
            cout << "Result: " << static_cast<int>(num1) % static_cast<int>(num2) << endl;
            break;
        case '^':
            cout << "Result: " << pow(num1, num2) << endl;
            break;
        default:
            cout << "Invalid operator!" << endl;
        }
    }

    return 0;
}
