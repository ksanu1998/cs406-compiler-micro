%{

  #include <cstdio>
	#include <string>
	#include <string.h>
	#include <iostream>
	using namespace std;
	extern int yylex();
	extern char* yytext;
	void yyerror(const char *p) {};
	#include "parserStructures.hpp"
	int cnt = 1;
	vector <char *> myVector;

  #include "parserFunctions.hpp"

%}


%union{
	struct StrEntry* s_entry;
	struct VarEntry* v_entry;
	struct ID_List* id_l;
	char* s;
	struct Param_Decl* p_decl;
	struct Param_Decl_List* p_list;
}

%type <s_entry> string_decl;
%type <v_entry> var_decl;
%type <s> id str var_type any_type;
%type <id_l> id_list id_tail;
%type <p_decl> param_decl;
%type <p_list> param_decl_list param_decl_tail;


/* declare tokens */

%token _PROGRAM _BEGIN _END _FUNCTION _READ _WRITE _IF _ELSE _FI _FOR _ROF _RETURN _INT _VOID _STRING _FLOAT
%token _IDENTIFIER _STRINGLITERAL _INTLITERAL _FLOATLITERAL _COMMENT
%token _ASSIGNMENT _PLUS _MINUS _MUL _DIV _EQUALS _NEQUALS _LESSTHAN _GREATERTHAN _LEFTPARANTHESIS _RIGHTPARANTHESIS _SEMICOLON _COMMA _LESSOREQUAL _GREATEROREQUAL
%token _WHITESPACE
%token _EOF
%%

/* Program */
program: _PROGRAM {cout << "Symbol table GLOBAL" << endl;} id _BEGIN pgm_body _END;
id: _IDENTIFIER;
pgm_body: decl func_declarations;
decl: string_decl decl | var_decl decl | /* empty */;

/* Global String Declaration */
string_decl: _STRING id _ASSIGNMENT str _SEMICOLON {$$ = new StrEntry(); $$->addID($2); $$->addValue($4); print_StrEntry($$);};
str: _STRINGLITERAL;

/* Variable Declaration */
var_decl: var_type id_list _SEMICOLON {$$ = new VarEntry(); $$->addVartype($1); $$->addIDlist($2); print_VarEntry($$);};
var_type: _FLOAT | _INT;
any_type: var_type | _VOID;
id_list: id id_tail {$$ = new ID_List(); $$->addID($1); $$->nextID($2);};
id_tail: _COMMA id id_tail {$$ = new ID_List(); $$->addID($2); $$->nextID($3);} | {$$ = NULL;};

/* Function Paramater List */
param_decl_list: param_decl param_decl_tail {$$ = new Param_Decl_List(); $$->addPD($1); $$->nextPD($2);} | {$$ = NULL;};
param_decl: var_type id {$$ = new Param_Decl(); $$->addType($1); $$->addID($2); printPD($$);};
param_decl_tail: _COMMA param_decl param_decl_tail {$$ = new Param_Decl_List(); $$->addPD($2); $$->nextPD($3);} | {$$ = NULL;};

/* Function Declarations */
func_declarations: func_decl func_declarations | /* empty */;
func_decl: _FUNCTION any_type id {Print_ST($3);} _LEFTPARANTHESIS param_decl_list _RIGHTPARANTHESIS _BEGIN func_body _END;
func_body: decl stmt_list;

/* Statement List */
stmt_list: stmt stmt_list | /* empty */;
stmt: base_stmt | if_stmt | for_stmt;
base_stmt: assign_stmt | read_stmt | write_stmt | return_stmt;

/* Basic Statements */
assign_stmt: assign_expr _SEMICOLON;
assign_expr: id _ASSIGNMENT expr;
read_stmt: _READ _LEFTPARANTHESIS id_list _RIGHTPARANTHESIS _SEMICOLON;
write_stmt: _WRITE _LEFTPARANTHESIS id_list _RIGHTPARANTHESIS _SEMICOLON;
return_stmt: _RETURN expr _SEMICOLON;

/* Expressions */
expr: expr_prefix factor;
expr_prefix: expr_prefix factor addop | /* empty */;
factor: factor_prefix postfix_expr;
factor_prefix: factor_prefix postfix_expr mulop | /* empty */;
postfix_expr: primary | call_expr;
call_expr: id _LEFTPARANTHESIS expr_list _RIGHTPARANTHESIS;
expr_list: expr expr_list_tail | /* empty */;
expr_list_tail: _COMMA expr expr_list_tail | /* empty */;
primary: _LEFTPARANTHESIS expr _RIGHTPARANTHESIS | id | _INTLITERAL | _FLOATLITERAL;
addop: _PLUS | _MINUS;
mulop: _MUL | _DIV;

/* Complex Statements and Condition */
if_stmt: _IF {Print_Block(cnt++);} _LEFTPARANTHESIS cond _RIGHTPARANTHESIS decl stmt_list else_part _FI;
else_part: _ELSE {Print_Block(cnt++);} decl stmt_list | /* empty */;
cond: expr compop expr;
compop: _LESSTHAN | _GREATERTHAN | _EQUALS | _NEQUALS | _LESSOREQUAL | _GREATEROREQUAL;
init_stmt: assign_expr | /* empty */;
incr_stmt: assign_expr | /* empty */;
for_stmt: _FOR {Print_Block(cnt++);} _LEFTPARANTHESIS init_stmt _SEMICOLON cond _SEMICOLON incr_stmt _RIGHTPARANTHESIS decl stmt_list _ROF;

%%
/*
int main(int c, char* argv[])
{

	FILE* fd = fopen(argv[1], "r");
	yyset_in(fd);
   	yyparse();
    fclose(fd);
    fprintf(stderr, "%s\n", "Accepted");
	return 0;
}
*/
