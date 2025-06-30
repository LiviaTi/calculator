#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void operacoes_basicas() {
    float num1, num2;
    char op;

    printf("\nDigite a expressao (ex: 10 + 5): ");
    scanf("%f %c %f", &num1, &op, &num2);

    switch (op) {
        case '+': printf("Resultado: %.2f\n", num1 + num2); break;
        case '-': printf("Resultado: %.2f\n", num1 - num2); break;
        case '*': printf("Resultado: %.2f\n", num1 * num2); break;
        case '/': 
            if (num2 != 0)
                printf("Resultado: %.2f\n", num1 / num2);
            else
                printf("Erro: Divisao por zero!\n");
            break;
        default: printf("Operador invalido!\n");
    }
}

void binario_para_decimal() {
    char bin[33];
    int decimal = 0;

    printf("Digite um numero binario: ");
    scanf("%s", bin);

    for (int i = 0; i < strlen(bin); i++) {
        decimal = decimal * 2 + (bin[i] - '0');
    }

    printf("Decimal: %d\n", decimal);
}

void decimal_para_binario() {
    int num;
    char bin[33];
    int i = 0;

    printf("Digite um numero decimal: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("Binario: 0\n");
        return;
    }

    while (num > 0) {
        bin[i++] = (num % 2) + '0';
        num /= 2;
    }
    bin[i] = '\0';

    // Inverter string
    for (int j = 0; j < i / 2; j++) {
        char temp = bin[j];
        bin[j] = bin[i - j - 1];
        bin[i - j - 1] = temp;
    }

    printf("Binario: %s\n", bin);
}

void decimal_para_hex() {
    int num;

    printf("Digite um numero decimal: ");
    scanf("%d", &num);

    printf("Hexadecimal: %X\n", num);
}

void hex_para_decimal() {
    char hex[20];
    int decimal;

    printf("Digite um numero hexadecimal (ex: 1A3): ");
    scanf("%s", hex);

    sscanf(hex, "%x", &decimal);

    printf("Decimal: %d\n", decimal);
}

int main() {
    int opcao;

    do {
        printf("\n===== CALCULADORA MULTI BASE =====\n");
        printf("1. Operacoes aritmeticas basicas\n");
        printf("2. Binario para Decimal\n");
        printf("3. Decimal para Binario\n");
        printf("4. Decimal para Hexadecimal\n");
        printf("5. Hexadecimal para Decimal\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: operacoes_basicas(); break;
            case 2: binario_para_decimal(); break;
            case 3: decimal_para_binario(); break;
            case 4: decimal_para_hex(); break;
            case 5: hex_para_decimal(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opçao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}

