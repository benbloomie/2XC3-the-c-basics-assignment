# convert - Number Base Conversion Utility  
A command-line tool for converting decimal numbers into other bases, with optional input ranges.

---

## Description  
This program allows users to convert decimal numbers to various bases (from base 2 to base 36). The program supports both direct user input and range-based conversion. Default conversion is to hexadecimal (base 16) unless otherwise specified.

---

## Getting Started

### Dependencies  
- Terminal environment (Linux, macOS, WSL)
- GCC or any C compiler  

### Installing  
1. Clone or download the repository:

    ```bash
    git clone https://github.com/benbloomie/2XC3-the-c-basics-assignment
    cd 2XC3-the-c-basics-assignment
    ```

2. Compile the program using the Makefile:

    ```bash
    make
    ```

3. (Optional) To compile with code coverage enabled:

    ```bash
    make ctest
    ```

---

## Executing the Program

Run the program with desired arguments:

- View the help message:

    ```bash
    ./convert --help
    ```

- Convert user input to base 16 (default):

    ```bash
    ./convert
    ```

- Convert user input to a specified base:

    ```bash
    ./convert -b 2
    ```

- Convert a range of numbers to a specified base:

    ```bash
    ./convert -b 8 -r 1 10
