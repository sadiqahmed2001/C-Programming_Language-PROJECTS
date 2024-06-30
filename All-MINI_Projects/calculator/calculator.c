#include <stdio.h>

int main() {
    char operator;
    double num1, num2;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch (operator) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error! Division by zero.");
            } else {
                printf("%.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
            }
            break;
        default:
            printf("Error! Invalid operator.");
    }

    return 0;
}      
