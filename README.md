```
# Number Conversion and Arithmetic Operations

## Overview
This project is a C++ program that implements two main functionalities:
1. **Number Conversion**: Converts numbers between different bases (Decimal, Binary, Hexadecimal) and also handles float to binary conversion.
2. **Arithmetic Operations**: Performs addition and multiplication on two numbers input by the user after converting the second number to the base of the first.

## Features
- Convert numbers between Decimal (DEC), Binary (BIN), and Hexadecimal (HEX) formats.
- Convert floating-point numbers to Decimal and Binary formats.
- Perform addition and multiplication on numbers of different bases by converting them to a common base.

## File Description
- `main.cpp`: The main C++ file containing the implementation of the number conversion and arithmetic operations.

## How to Run
1. Ensure you have a C++ compiler installed (e.g., g++, clang++).
2. Compile the `main.cpp` file:
   ```sh
   g++ main.cpp -o num_converter
   ```
3. Run the executable:
   ```sh
   ./num_converter
   ```
4. Follow the prompts in the console to use the number conversion and arithmetic operation features.

## Functionality

### Number Conversion
The program can convert numbers between the following formats:
- **Decimal (DEC) to Binary (BIN)**
- **Decimal (DEC) to Hexadecimal (HEX)**
- **Binary (BIN) to Decimal (DEC)**
- **Binary (BIN) to Hexadecimal (HEX)**
- **Hexadecimal (HEX) to Decimal (DEC)**
- **Hexadecimal (HEX) to Binary (BIN)**
- **Float to Binary (BIN)**
- **Float to Decimal (DEC)**

### Arithmetic Operations
The program allows the user to input two numbers of any base (DEC, BIN, HEX), converts the second number to the base of the first, and performs the specified arithmetic operation (Addition/Multiplication). The result is displayed in the base of the first number.

## Code Structure
- **Number Conversion Functions**:
  - `decToBin(int dec)`: Converts a decimal number to binary.
  - `binToDec(string bin)`: Converts a binary number to decimal.
  - `decToHex(int dec)`: Converts a decimal number to hexadecimal.
  - `hexToDec(string hex)`: Converts a hexadecimal number to decimal.
  - `floatToBin(float f)`: Converts a float to binary representation.

- **Main Functions**:
  - `numberConversion()`: Handles user input and performs the number conversion.
  - `arithmeticOperations()`: Handles user input, performs base conversion, and executes the arithmetic operations.

## License
This project is licensed under the MIT License.

## Author
**Dominick Ferro**

## Date
September 5, 2023
```
