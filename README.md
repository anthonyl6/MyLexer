# MyLexer
The aim is to develop a custom lexer generator like Flex that takes in a input program, which is a set of rules defining the lexical tokens and input characters from another input program defined by the user. MyLexer will then take those tokens and character pairs and generate a Lexical Analyzer for those specified rules.


## How To Compile
This project uses CMake to generate make files which can be run with make to generate the executable

1. In the project's root directory.
    ```
    mkdir build
    ```
2. Change current directory to the build directory.
    ```
    cd build
    ```
3. Run CMake.
    ```
    cmake ..
    ```
4. Run Make.
    ```
    make
    ```
5. You can then run the executable generated. The default executable should be called MyLexer. Run MyLexer -h to get usage information.

# Contributions

# License
N/A (Not determined yet)