// MyLexer
//
// MyLexer is a custom Lexical Analyzer Generator that allows the user to define a subset of rules in which the
// program would pair those rules with a token and generate a Lexical Analyzer for those specified rules to be used
// in another project. 
//
//
//  Author: Anthony Loria
//
//  License: N/A (At the moment)

#include <iostream>
#include <fstream>
#include <cstring>
#include <memory>
#include "lexer.hpp"

const int MIN_ARG_SIZE = 2;

enum FAILURES {
    ARG_FAIL = -1,
    SYS_FAIL = -2,
    LEX_FAIL = -3
};

std::unique_ptr<Lexer> lexer;

void print_usage() {
    std::cout << "MyLexer Lexical Analyzer Genertor\n"
              << "---Usage---\n"
              << "mlex  <options>  file"
              << "\n\t -o --out \t\t The output directory of the generated code."
              << "\n\t -l --language \t\t Language of the generated code."
              << std::endl;
}

int set_out_file(const char* file) {
    lexer->out_file.open(file);
    return lexer->out_file.fail();
}

int parse_args(int argc, char* argv[]) {
    for(int i = 1; i < argc; i++) {
        if(sizeof(argv[i]) < 2) {
            return ARG_FAIL;
        }
        if(strncmp(argv[i], "-o", MIN_ARG_SIZE))
            return set_out_file(argv[i]) == 0 ? 0 : SYS_FAIL;
    }
    return 0;
}


int main(int argc, char* argv[]) {
    int status = 0;
    lexer = std::make_unique<Lexer>();

    if(status = parse_args(argc, argv) != 0 || argc <= 1) 
        print_usage();
    
    return status;
}