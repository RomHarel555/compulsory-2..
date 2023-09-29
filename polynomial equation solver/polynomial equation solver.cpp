#include <iostream>
#include <cmath>
#include <limits> // Include the <limits> header for clearing input errors

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to solve a 3rd degree polynomial equation
double solvePolynomial(double a, double b, double c, double d, double x) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

int main() {
    int choice;
    do {
        std::cout << "Welcome to my calculator!:" << std::endl;
        std::cout << "1. Calculate Factorial" << std::endl;
        std::cout << "2. Solve 3rd Degree Polynomial Equation" << std::endl;
        std::cout << "3. Perform Simple Math Operation" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Your choce will go here!: ";
        std::cin >> choice;

        // Check for input failure
        if (std::cin.fail()) {
            std::cout << "You cannot do that, try something else next time :)" << std::endl;
            std::cin.clear(); // Clear the input error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard input buffer
            continue; // Skip to the next iteration of the loop
        }

        switch (choice) {
        case 1: {
            int num;
            std::cout << "pick your number friend! ";
            std::cin >> num;

            // Check for input failure and negative number
            if (std::cin.fail() || num < 0) {
                std::cout << "Hint: try entering a non-negative integer ;)" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            int result = factorial(num);
            std::cout << "Factorial of " << num << " is " << result << std::endl;
            break;
        }
        case 2: {
            double a, b, c, d, x;
            std::cout << "Enter coefficients a, b, c, and d for the polynomial (ax^3 + bx^2 + cx + d): ";
            std::cin >> a >> b >> c >> d >> x;

            // Check for input failure
            if (std::cin.fail()) {
                std::cout << "This is not possible friend, please try entering valid coefficients and x value." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            double result = solvePolynomial(a, b, c, d, x);
            std::cout << "Result of the polynomial equation at x = " << x << " is " << result << std::endl;
            break;
        }
        case 3: {
            char operation;
            double operand1, operand2, result;
            std::cout << "Enter a math operation (+, -, *, /): ";
            std::cin >> operation;
            std::cout << "Enter two operands: ";
            std::cin >> operand1 >> operand2;

            // Check for input failure and division by zero
            if (std::cin.fail() || (operation == '/' && operand2 == 0)) {
                std::cout << "again? enter a valid operation and operands please :<." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            switch (operation) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                std::cout << "Please enter +, -, *, or /." << std::endl;
                continue;
            }

            std::cout << "Result: " << result << std::endl;
            break;
        }
        case 4:
            std::cout << "Exiting the calculator. Goodbye friend!!!" << std::endl;
            break;
        default:
            std::cout << "That is not a valid choice. Please select another option~." << std::endl;
        }

    } while (choice != 4);

    return 0;
}