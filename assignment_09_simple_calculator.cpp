// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function prototypes
void showMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
int modulo(int a, int b);
double power(double base, double exponent);

int main() {
    int choice;
    double num1, num2;
    int intNum1, intNum2;
    
    // Set precision for output
    cout << fixed << setprecision(2);
    
    do {
        showMenu();
        cin >> choice;
        
        // Handle invalid menu choice
        if (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please enter a number between 1 and 7.\n\n";
            continue;
        }
        
        // Quit option
        if (choice == 7) {
            cout << "Goodbye!\n";
            break;
        }
        
        // Get numbers for operations that need them
        if (choice >= 1 && choice <= 6) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
            
            // Store integer versions for modulus
            intNum1 = static_cast<int>(num1);
            intNum2 = static_cast<int>(num2);
        }
        
        // Perform the selected operation
        switch (choice) {
            case 1:
                cout << "Result: " << num1 << " + " << num2 << " = " 
                     << add(num1, num2) << "\n\n";
                break;
                
            case 2:
                cout << "Result: " << num1 << " - " << num2 << " = " 
                     << subtract(num1, num2) << "\n\n";
                break;
                
            case 3:
                cout << "Result: " << num1 << " * " << num2 << " = " 
                     << multiply(num1, num2) << "\n\n";
                break;
                
            case 4:
                if (num2 == 0) {
                    cout << "Error: Cannot divide by zero.\n\n";
                } else {
                    cout << "Result: " << num1 << " / " << num2 << " = " 
                         << divide(num1, num2) << "\n\n";
                }
                break;
                
            case 5:
                if (intNum2 == 0) {
                    cout << "Error: Cannot calculate modulus with zero.\n\n";
                } else {
                    cout << "Result: " << intNum1 << " % " << intNum2 << " = " 
                         << modulo(intNum1, intNum2) << "\n\n";
                }
                break;
                
            case 6:
                cout << "Result: " << num1 << " ^ " << num2 << " = " 
                     << power(num1, num2) << "\n\n";
                break;
        }
        
    } while (choice != 7);
    
    return 0;
}

// Function to display the menu
void showMenu() {
    cout << "============================\n";
    cout << "     SIMPLE CALCULATOR\n";
    cout << "============================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
    cout << "Select an operation (1-7): ";
}

// Addition function
double add(double a, double b) {
    return a + b;
}

// Subtraction function
double subtract(double a, double b) {
    return a - b;
}

// Multiplication function
double multiply(double a, double b) {
    return a * b;
}

// Division function
double divide(double a, double b) {
    return a / b;
}

// Modulus function
int modulo(int a, int b) {
    return a % b;
}

// Exponentiation function
double power(double base, double exponent) {
    return pow(base, exponent);
}