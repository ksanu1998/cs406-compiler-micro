%{
	#include <cstdio>
	#include <string>
	#include <iostream>
	#include "../genfiles/parser.hpp"
	extern char* yytext;

%}

%option noyywrap
%option yylineno

_PROGRAM	PROGRAM
_BEGIN		BEGIN
_END		END
_FUNCTION	FUNCTION
_READ		READ
_WRITE		WRITE
_IF			IF
_ELSE		ELSE
_ENDIF		ENDIF
_WHILE		WHILE
_ENDWHILE	ENDWHILE
_RETURN		RETURN
_INT		INT
_VOID		VOID
_STRING		STRING
_FLOAT		FLOAT
_TRUE		TRUE
_FALSE		FALSE
_ASSIGNMENT	\:=
_PLUS		\+
_MINUS		\-
_MUL		\*
_DIV		\/
_NEQUALS	\!=
_LTHAN		\<
_GTHAN		\>
_EQUALS		\=
_OPENPAR	\(
_CLOSEPAR	\)
_SEMICOLON	\;
_COMMA		\,
_LTEQUALS	\<=
_GTEQUALS	\>=
IDENTIFIER	[A-Za-z][A-Za-z0-9]*
FLOATLITERAL	[0-9]*\.[0-9]+
INTLITERAL	[0-9]+
STRINGLITERAL	\"(\\.|[^"\\])*\"
COMMENT		(\-\-.*)
WHITESPACE	\t|\r|\n|" "
%%
{_PROGRAM} 			return _PROGRAM;
{_BEGIN}			return _BEGIN;
{_END}				return _END;
{_FUNCTION}			return _FUNCTION;
{_READ}				return _READ;
{_WRITE}			return _WRITE;
{_IF}				return _IF;
{_ELSE}				return _ELSE;
{_ENDIF}			return _ENDIF;
{_WHILE}			return _WHILE;
{_ENDWHILE}			return _ENDWHILE;
{_RETURN}			return _RETURN;
{_INT}				{ yylval.s = strdup(yytext); return _INT; }
{_VOID}				return _VOID;
{_STRING}			return _STRING;
{_FLOAT}			{ yylval.s = strdup(yytext); return _FLOAT; }
{_TRUE}				{ yylval.s = strdup(yytext); return _TRUE; }
{_FALSE}			{ yylval.s = strdup(yytext); return _FALSE; }
{_ASSIGNMENT}		return _ASSIGNMENT;
{_PLUS}				{ yylval.s = strdup(yytext); return _PLUS; }
{_MINUS}			{ yylval.s = strdup(yytext); return _MINUS; }
{_MUL}				{ yylval.s = strdup(yytext); return _MUL; }
{_DIV}				{ yylval.s = strdup(yytext); return _DIV; }
{_NEQUALS}			{ yylval.s = strdup(yytext); return _NEQUALS; }
{_GTHAN}			{ yylval.s = strdup(yytext); return _GTHAN; }
{_LTHAN}			{ yylval.s = strdup(yytext); return _LTHAN; }
{_EQUALS}			{ yylval.s = strdup(yytext); return _EQUALS; }
{_OPENPAR}			return _OPENPAR;
{_CLOSEPAR}			return _CLOSEPAR;
{_SEMICOLON}		return _SEMICOLON;
{_COMMA}			return _COMMA;
{_GTEQUALS}			{ yylval.s = strdup(yytext); return _GTEQUALS; }
{_LTEQUALS}		{ yylval.s = strdup(yytext); return _LTEQUALS; }
{IDENTIFIER}		{ yylval.s = strdup(yytext); return IDENTIFIER; }
{FLOATLITERAL} 		{ yylval.s = strdup(yytext); return FLOATLITERAL; }
{INTLITERAL}		{ yylval.s = strdup(yytext); return INTLITERAL; }
{STRINGLITERAL}		{ yylval.s = strdup(yytext); return STRINGLITERAL; }
{COMMENT}
{WHITESPACE}
%%
