#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Performs basic arithmetic operations (+, -, *, /)
void basic_operations() {
    float num1, num2;
    char op;

    printf("\nEnter the expression (e.g., 10 + 5): ");
    scanf("%f %c %f", &num1, &op, &num2);

    switch (op) {
        case '+': printf("Result: %.2f\n", num1 + num2); break;
        case '-': printf("Result: %.2f\n", num1 - num2); break;
        case '*': printf("Result: %.2f\n", num1 * num2); break;
        case '/':
            if (num2 != 0)
                printf("Result: %.2f\n", num1 / num2);
            else
                printf("Error: Division by zero!\n");
            break;
        default: printf("Invalid operator!\n");
    }
}

// Converts a binary number to decimal
void binary_to_decimal() {
    char bin[33];
    int decimal = 0;

    printf("Enter a binary number: ");
    scanf("%s", bin);

    for (int i = 0; i < strlen(bin); i++) {
        decimal = decimal * 2 + (bin[i] - '0');
    }

    printf("Decimal: %d\n", decimal);
}

// Converts a decimal number to binary
void decimal_to_binary() {
    int num;
    char bin[33];
    int i = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }

    while (num > 0) {
        bin[i++] = (num % 2) + '0';
        num /= 2;
    }
    bin[i] = '\0';

    // Reverse the binary string
    for (int j = 0; j < i / 2; j++) {
        char temp = bin[j];
        bin[j] = bin[i - j - 1];
        bin[i - j - 1] = temp;
    }

    printf("Binary: %s\n", bin);
}

// Converts a decimal number to hexadecimal
void decimal_to_hex() {
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("Hexadecimal: %X\n", num);
}

// Converts a hexadecimal number to decimal
void hex_to_decimal() {
    char hex[20];
    int decimal;

    printf("Enter a hexadecimal number (e.g., 1A3): ");
    scanf("%s", hex);

    sscanf(hex, "%x", &decimal);

    printf("Decimal: %d\n", decimal);
}

// Main program loop with menu
int main() {
    int option;

    do {
        printf("\n===== MULTI-BASE CALCULATOR =====\n");
        printf("1. Basic arithmetic operations\n");
        printf("2. Binary → Decimal\n");
        printf("3. Decimal → Binary\n");
        printf("4. Decimal → Hexadecimal\n");
        printf("5. Hexadecimal → Decimal\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: basic_operations(); break;
            case 2: binary_to_decimal(); break;
            case 3: decimal_to_binary(); break;
            case 4: decimal_to_hex(); break;
            case 5: hex_to_decimal(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid option!\n");
        }

    } while(option != 0);

    return 0;
}
