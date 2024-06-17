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
READ {yylval.s = strdup(yytext); return _READ;}
WRITE {yylval.s = strdup(yytext); return _WRITE;}
IF {return _IF;}
ELSE {return _ELSE;}
FI {return _FI;}
FOR {return _FOR;}
ROF {return _ROF;}
RETURN {return _RETURN;}
INT { yylval.s = strdup(yytext); return _INT; }
VOID {yylval.s = strdup(yytext); return _VOID;}
STRING {yylval.s = strdup(yytext); return _STRING;}
FLOAT { yylval.s = strdup(yytext); return _FLOAT; }
{STRINGLITERAL} { yylval.s = strdup(yytext); return _STRINGLITERAL; }
{ID} { yylval.s = strdup(yytext); return _IDENTIFIER; }
{INTLITERAL}+ {yylval.s = strdup(yytext); return _INTLITERAL;}
{FLOATLITERAL} {yylval.s = strdup(yytext);return _FLOATLITERAL;}
{COMMENT} {}
(:=) {return _ASSIGNMENT;}
(\+) {yylval.s = strdup(yytext);return _PLUS;}
(-)	{yylval.s = strdup(yytext);return _MINUS;}
(\*) {yylval.s = strdup(yytext);return _MUL;}
(\/) {yylval.s = strdup(yytext);return _DIV;}
(=)	{yylval.s = strdup(yytext);return _EQUALS;}
(!=) {yylval.s = strdup(yytext);return _NEQUALS;}
(<)	{yylval.s = strdup(yytext);return _LESSTHAN;}
(>)	{yylval.s = strdup(yytext);return _GREATERTHAN;}
(\() {yylval.s = strdup(yytext);return _LEFTPARANTHESIS;}
(\)) {yylval.s = strdup(yytext);return _RIGHTPARANTHESIS;}
(;)	{yylval.s = strdup(yytext);return _SEMICOLON;}
(,)	{yylval.s = strdup(yytext);return _COMMA;}
(<=) {yylval.s = strdup(yytext);return _LESSOREQUAL;}
(>=) {yylval.s = strdup(yytext);return _GREATEROREQUAL;}
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
