#ifndef CONVERTER_H
#define CONVERTER_H

// Function prototypes
int decimalToBinary(int decimal);
int decimalToOctal(int decimal);
void decimalToHexadecimal(int decimal);
int getUserChoice();
int getDecimalInput();
void clearInputBuffer();
void printMenu();
void displayResult(int result, int base);

#endif  // CONVERTER_H
