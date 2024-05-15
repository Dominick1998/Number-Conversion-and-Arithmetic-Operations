/*
Dominick Ferro
Assignment 1
9/05/2023

C++ Program to implement:

Number Conversion:
-Convert DEC, BIN, and HEX among each other.
-Convert Float to DEC or BIN.

Arithmetic Operations:
-Input two numbers.
-Convert the second number to the base of the first.
-Perform the specified arithmetic operation (Addition/Multiplication).
*/

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

// Convert decimal to binary
string decToBin(int dec) {
    if(dec == 0) return "0";
    string bin = "";
    while(dec) {
        bin = (dec % 2 ? "1" : "0") + bin;
        dec /= 2;
    }
    return bin;
}

// Convert binary to decimal
int binToDec(string bin) {
    int dec = 0;
    int len = bin.length();
    for(int i = 0; i < len; i++) {
        if(bin[i] == '1') dec += pow(2, len - 1 - i);
    }
    return dec;
}

// Convert decimal to hex
string decToHex(int dec) {
    if(dec == 0) return "0";
    stringstream ss;
    ss << hex << dec;
    return ss.str();
}

// Convert hex to decimal
int hexToDec(string hex) {
    int dec;
    stringstream ss;
    ss << hex;
    ss >> std::hex >> dec;
    return dec;
}

// Float to binary 
string floatToBin(float f) {
    union {
        float input;
        int output;
    } data;
    data.input = f;
    string binary = decToBin(data.output);
    while(binary.length() < 32) binary = "0" + binary; // make sure it's 32 bits
    return binary;
}

void numberConversion() {
    string type_from, type_to;
    cout << "Enter the number type (DEC, BIN, HEX, FLOAT): ";
    cin >> type_from;
    if(type_from == "FLOAT") {
        cout << "Convert to (DEC, BIN): ";
    } else {
        cout << "Convert to (DEC, BIN, HEX): ";
    }
    cin >> type_to;
    
    if(type_from == "DEC") {
        int dec;
        cout << "Enter DEC number: ";
        cin >> dec;
        if(type_to == "BIN") {
            cout << "Converted number: " << decToBin(dec) << endl;
        } else if(type_to == "HEX") {
            cout << "Converted number: " << decToHex(dec) << endl;
        } else {
            cout << "Invalid conversion type." << endl;
        }
    } else if(type_from == "BIN") {
        string bin;
        cout << "Enter BIN number: ";
        cin >> bin;
        if(type_to == "DEC") {
            cout << "Converted number: " << binToDec(bin) << endl;
        } else if(type_to == "HEX") {
            cout << "Converted number: " << decToHex(binToDec(bin)) << endl;
        } else {
            cout << "Invalid conversion type." << endl;
        }
    } else if(type_from == "HEX") {
        string hex;
        cout << "Enter HEX number: ";
        cin >> hex;
        if(type_to == "DEC") {
            cout << "Converted number: " << hexToDec(hex) << endl;
        } else if(type_to == "BIN") {
            cout << "Converted number: " << decToBin(hexToDec(hex)) << endl;
        } else {
            cout << "Invalid conversion type." << endl;
        }
    } else if(type_from == "FLOAT") {
        float f;
        cout << "Enter FLOAT number: ";
        cin >> f;
        if(type_to == "DEC") {
            cout << "Converted number: " << static_cast<int>(f) << endl;
        } else if(type_to == "BIN") {
            cout << "Converted number: " << floatToBin(f) << endl;
        } else {
            cout << "Invalid conversion type." << endl;
        }
    } else {
        cout << "Invalid input type." << endl;
    }
}

void arithmeticOperations() {
    // Input two numbers of any base
    string base1, base2, number1, number2;
    cout << "Enter base of the first number (DEC, BIN, HEX): ";
    cin >> base1;
    cout << "Enter first number: ";
    cin >> number1;
    cout << "Enter base of the second number (DEC, BIN, HEX): ";
    cin >> base2;
    cout << "Enter second number: ";
    cin >> number2;

    // Convert 2nd number to base of 1st
    int num1, num2;
    if(base1 == "DEC") {
        num1 = stoi(number1);
        if(base2 == "DEC") num2 = stoi(number2);
        else if(base2 == "BIN") num2 = binToDec(number2);
        else if(base2 == "HEX") num2 = hexToDec(number2);
    } else if(base1 == "BIN") {
        num1 = binToDec(number1);
        if(base2 == "DEC") num2 = stoi(number2);
        else if(base2 == "BIN") num2 = binToDec(number2);
        else if(base2 == "HEX") num2 = hexToDec(number2);
    } else if(base1 == "HEX") {
        num1 = hexToDec(number1);
        if(base2 == "DEC") num2 = stoi(number2);
        else if(base2 == "BIN") num2 = binToDec(number2);
        else if(base2 == "HEX") num2 = hexToDec(number2);
    }

    // Ask for arithmetic operation(addition or multiplication)
    char operation;
    cout << "Do you want to add (+) or multiply (*) these numbers? ";
    cin >> operation;

    // Result for arithmetic
    int result;
    if(operation == '+') result = num1 + num2;
    else if(operation == '*') result = num1 * num2;
    else {
        cout << "Invalid operation." << endl;
        return;
    }

    if(base1 == "DEC") {
        cout << "Result: " << result << endl;
    } else if(base1 == "BIN") {
        cout << "Result: " << decToBin(result) << endl;
    } else if(base1 == "HEX") {
        cout << "Result: " << decToHex(result) << endl;
    }
}

int main() {
    numberConversion();
    arithmeticOperations();

    return 0;
}

//End 
