#include <stdio.h>
#include <cstdio>
#include <string>
#include <iostream>
#include "microParser.hpp"
#include "parserStructures.hpp"

extern int yylex();
extern FILE* yyin;
extern char* yytext;
extern int yyset_in(FILE * in_str);
int yyparse();

int main(int argc, char** argv) {
	FILE* file = fopen(argv[1], "r");
	yyin = file;
	freopen(argv[2], "w", stdout);
	yyparse();

	yyset_in(file);

	if(!yyparse()){

	}else{

		if (isDeclarationError()) {
			freopen(argv[2], "w", stdout);
			std::cout << "DECLARATION ERROR " << getWronglyDeclaredVariable() << endl;
		}

	}

	fclose(file);

	return 0;
}
