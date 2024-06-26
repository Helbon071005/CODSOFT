#include <iostream>
#include <string>
using namespace std;

int main() {
    string operation;
    double num1, num2, result;

    while (true) {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        cout << "Choose an operation (+, -, *, /) or type 'exit' to quit: ";
        cin >> operation;

        if (operation == "exit") {
            cout << "Exiting the calculator. Goodbye!" << endl;
            break; // Exit the loop
        }

        if (operation.length() != 1) {
            cout << "Invalid operation. Please choose +, -, *, or /." << endl;
            continue; // Skip to the next iteration
        }

        char op = operation[0]; // Get the first character of the operation string

        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                    continue; // Skip to the next iteration
                }
                break;
            default:
                cout << "Invalid operation. Please choose +, -, *, or /." << endl;
                continue; // Skip to the next iteration
        }

        cout << "Result: " << result << endl;
    }

    return 0;
}
