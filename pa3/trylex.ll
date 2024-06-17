%{
#include <cstdio>
#include <string>
#include <iostream>
#include "microParser.hpp"
extern char* yytext;
%}

ID [a-zA-Z][a-zA-Z0-9]*
INTLITERAL [0-9]
FLOATLITERAL [0-9]+"."[0-9]+|"."[0-9]+
STRINGLITERAL \"[^\"]*\"
COMMENT #[^\n]*
WHITESPACE [\n\t\r\f ]*
%%
PROGRAM {return _PROGRAM;}
BEGIN {return _BEGIN;}
END {return _END;}
FUNCTION {return _FUNCTION;}
READ {return _READ;}
WRITE {return _WRITE;}
IF {return _IF;}
ELSE {return _ELSE;}
FI {return _FI;}
FOR {return _FOR;}
ROF {return _ROF;}
RETURN {return _RETURN;}
INT { yylval.s = strdup(yytext); return _INT; }
VOID {return _VOID;}
STRING {return _STRING;}
FLOAT { yylval.s = strdup(yytext); return _FLOAT; }
{STRINGLITERAL} { yylval.s = strdup(yytext); return _STRINGLITERAL; }
{ID} { yylval.s = strdup(yytext); return _IDENTIFIER; }
{INTLITERAL}+ {return _INTLITERAL;}
{FLOATLITERAL} {return _FLOATLITERAL;}
{COMMENT} {}
(:=) {return _ASSIGNMENT;}
(\+) {return _PLUS;}
(-)	{return _MINUS;}
(\*) {return _MUL;}
(\/) {return _DIV;}
(=)	{return _EQUALS;}
(!=) {return _NEQUALS;}
(<)	{return _LESSTHAN;}
(>)	{return _GREATERTHAN;}
(\() {return _LEFTPARANTHESIS;}
(\)) {return _RIGHTPARANTHESIS;}
(;)	{return _SEMICOLON;}
(,)	{return _COMMA;}
(<=) {return _LESSOREQUAL;}
(>=) {return _GREATEROREQUAL;}
{WHITESPACE} {}
<<EOF>> {return 0;}
%%
/*
int yywrap(){}
int main(int c, char* argv[])
{

	FILE* fd = fopen(argv[1], "r");
	yyset_in(fd);
    yylex();
    fclose(fd);
	return 0;
}
*/
