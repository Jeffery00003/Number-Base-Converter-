#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int decimalToBinary(int decimal);
int decimalToOctal(int decimal);
void decimalToHexadecimal(int decimal);
int getUserChoice();
int getDecimalInput();
void clearInputBuffer();
void printMenu();
void displayResult(int result, int base);

int main() {
    int choice, decimal, result;
    char continueConversion;

    do {
        printMenu();
        choice = getUserChoice();

        switch (choice) {
            case 1:
                decimal = getDecimalInput();
                result = decimalToBinary(decimal);
                displayResult(result, 2);  // 2 represents binary
                break;
            case 2:
                decimal = getDecimalInput();
                result = decimalToOctal(decimal);
                displayResult(result, 8);  // 8 represents octal
                break;
            case 3:
                decimal = getDecimalInput();
                decimalToHexadecimal(decimal);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }

        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &continueConversion);

    } while (continueConversion == 'y' || continueConversion == 'Y');

    return 0;
}

int decimalToBinary(int decimal) {
    int binary = 0, base = 1;

    while (decimal > 0) {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }

    return binary;
}

int decimalToOctal(int decimal) {
    int octal = 0, base = 1;

    while (decimal > 0) {
        octal += (decimal % 8) * base;
        decimal /= 8;
        base *= 10;
    }

    return octal;
}

void decimalToHexadecimal(int decimal) {
    printf("Hexadecimal equivalent: %X\n", decimal);
}

int getUserChoice() {
    int choice;
    printf("Enter your choice (1/2/3/4): ");
    scanf("%d", &choice);
    clearInputBuffer();  // Clear any remaining input in the buffer
    return choice;
}

int getDecimalInput() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    clearInputBuffer();  // Clear any remaining input in the buffer
    return decimal;
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

void printMenu() {
    printf("Decimal to Different Base Conversion\n");
    printf("1\tConvert to Binary\n");
    printf("2\tConvert to Octal\n");
    printf("3\tConvert to Hexadecimal\n");
    printf("4\tExit\n");
}

void displayResult(int result, int base) {
    printf("Equivalent in base %d: %d\n", base, result);
}
