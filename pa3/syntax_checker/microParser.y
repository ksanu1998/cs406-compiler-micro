%{
 #include <stdio.h>
 void yyerror(const char* msg)
 {
    //fprintf(stderr, "%s\n", "Not accepted");
 }
 int yylex();
%}
/* declare tokens */

%token _PROGRAM _BEGIN _END _FUNCTION _READ _WRITE _IF _ELSE _FI _FOR _ROF _RETURN _INT _VOID _STRING _FLOAT
%token _IDENTIFIER _STRINGLITERAL _INTLITERAL _FLOATLITERAL _COMMENT
%token _ASSIGNMENT _PLUS _MINUS _MUL _DIV _EQUALS _NEQUALS _LESSTHAN _GREATERTHAN _LEFTPARANTHESIS _RIGHTPARANTHESIS _SEMICOLON _COMMA _LESSOREQUAL _GREATEROREQUAL 
%token _WHITESPACE
%token _EOF
%%

/* Program */
program: _PROGRAM id _BEGIN pgm_body _END;
id: _IDENTIFIER;
pgm_body: decl func_declarations;
decl: string_decl decl | var_decl decl | /* empty */;

/* Global String Declaration */
string_decl: _STRING id _ASSIGNMENT str _SEMICOLON;
str: _STRINGLITERAL;

/* Variable Declaration */
var_decl: var_type id_list _SEMICOLON;
var_type: _FLOAT | _INT;
any_type: var_type | _VOID;
id_list: id id_tail;
id_tail: _COMMA id id_tail | /* empty */;

/* Function Paramater List */
param_decl_list: param_decl param_decl_tail | /* empty */;
param_decl: var_type id;
param_decl_tail: _COMMA param_decl param_decl_tail | /* empty */;

/* Function Declarations */
func_declarations: func_decl func_declarations | /* empty */;
func_decl: _FUNCTION any_type id _LEFTPARANTHESIS param_decl_list _RIGHTPARANTHESIS _BEGIN func_body _END;
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
if_stmt: _IF _LEFTPARANTHESIS cond _RIGHTPARANTHESIS decl stmt_list else_part _FI;
else_part: _ELSE decl stmt_list | /* empty */;
cond: expr compop expr;
compop: _LESSTHAN | _GREATERTHAN | _EQUALS | _NEQUALS | _LESSOREQUAL | _GREATEROREQUAL;
init_stmt: assign_expr | /* empty */;
incr_stmt: assign_expr | /* empty */;
for_stmt: _FOR _LEFTPARANTHESIS init_stmt _SEMICOLON cond _SEMICOLON incr_stmt _RIGHTPARANTHESIS decl stmt_list _ROF;

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