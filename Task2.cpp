#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation, choice;

    cout << "===== SIMPLE CALCULATOR =====";

        cout << "\nEnter first number: ";
    do {
        cin >> num1;

        cout << "Enter an operator (+, -, *, /, %): ";
        cin >> operation;

        cout << "Enter second number: ";
        cin >> num2;

        switch (operation) {
            case '+':
                result = num1 + num2;
                cout << "Addition is : " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << "Subtraction is : " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << "Multiplication is : " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Division is : " << num1 << " / " << num2 << " = " << result << endl;
                } else {
                    cout << "Error: Division by zero is not allowed.";
                }
                break;
            case '%':
                if ((int)num2 != 0) {
                    int intN1 = (int)num1;
                    int intN2 = (int)num2;
                    int modResult = intN1 % intN2;
                    cout << "Modules is : " << intN1 << " % " << intN2 << " = " << modResult << endl;
                } else {
                    cout << "Error: Division by zero is not allowed.";
                }
                break;
            default:
                cout << "Invalid operator! Please use +, -, *, /, or %.\n";
        }

        cout << "Would you like to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

cout << "Thank you for using the calculator.";

    return 0;
}
