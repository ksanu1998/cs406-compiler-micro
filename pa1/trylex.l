ID [a-zA-Z][a-zA-Z0-9]*
INTLITERAL [0-9]
FLOATLITERAL [0-9]+"."[0-9]+|"."[0-9]+
STRINGLITERAL \"[^\"]*\"
COMMENT #[^\n]*
WHITESPACE [\n\t\r\f ]*
%%
PROGRAM {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
BEGIN {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
END {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
FUNCTION {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
READ {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
WRITE {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
IF {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
ELSE {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
FI {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
FOR {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
ROF {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
RETURN {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
INT {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
VOID {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
STRING {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);}
FLOAT {printf("Token Type: KEYWORD\r\nValue: %s\r\n", yytext);} 
{STRINGLITERAL} {printf("Token Type: STRINGLITERAL\r\nValue: %s\r\n", yytext);}
{ID} {printf("Token Type: IDENTIFIER\r\nValue: %s\r\n", yytext);}
{INTLITERAL}+ {printf("Token Type: INTLITERAL\r\nValue: %s\r\n", yytext);}
{FLOATLITERAL} {printf("Token Type: FLOATLITERAL\r\nValue: %s\r\n", yytext);}
{COMMENT} {printf("");}
(:=) {printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(\+) {printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(-)	{printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(\*) {printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(\/) {printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(=)	{printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(!=) {printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(<)	{printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(>)	{printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(\() {printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(\)) {printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(;)	{printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(,)	{printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(<=) {printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
(>=) {printf("Token Type: OPERATOR\r\nValue: %s\r\n", yytext);}
{WHITESPACE} {printf("");}
<<EOF>> {return 0;}
%%
int yywrap(){} 
int main(int c, char* argv[])
{
	FILE* fd = fopen(argv[1], "r");
	yyset_in(fd);
    yylex();
    fclose(fd);
	return 0;
}