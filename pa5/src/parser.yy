%{
	#include <cstdio>
	#include <string>
	#include <string.h>
	#include <stdio.h>
	#include <cstdlib>
	#include <iostream>
	using namespace std;
	#include <map>
	#include <sstream>
	#include <list>
	#include <vector>
	#include <iterator>

	extern int yylex();
	extern char* yytext;
	void yyerror(const char *p) {};

	#include "../src/parserStruct.hpp"
	int cnt = 1;
	vector <char *> myVector;

	#include "../src/parserFunctions.hpp"

%}

%union{
	struct ID_List* id_l;
	char* s;
	struct Param_Decl* p_decl;
	struct Param_Decl_List* p_list;
	struct ASTNode* AST;
	struct toList* mL;
}

%type <s> id str var_type any_type compop;
%type <id_l> id_list id_tail;
%type <p_decl> param_decl;
%type <p_list> param_decl_list param_decl_tail;
%type <AST> expr expr_prefix factor addop mulop factor_prefix postfix_expr primary call_expr expr_list cond;
%type <mL> assign_expr read_stmt write_stmt return_stmt ;

%token	_PROGRAM
%token	_BEGIN
%token	_END
%token	_FUNCTION
%token	_READ
%token	_WRITE
%token	<s> _IF
%token	_ELSE
%token	_ENDIF
%token	_WHILE
%token	_ENDWHILE
%token	_RETURN
%token	<s> _INT
%token	<s> _VOID
%token	<s> _STRING
%token	<s> _FLOAT
%token	<s> _TRUE
%token	<s> _FALSE
%token	_ASSIGNMENT
%token <s>	_PLUS
%token <s>	_MINUS
%token <s>	_MUL
%token <s>	_DIV
%token	<s> _NEQUALS
%token	<s> _GTHAN
%token	<s> _LTHAN
%token	_OPENPAR
%token  _CLOSEPAR
%token	_SEMICOLON
%token	_COMMA
%token	<s> _GTEQUALS
%token	<s> _LTEQUALS
%token	<s> _EQUALS
%token	<s> IDENTIFIER
%token	<s> FLOATLITERAL
%token	<s> INTLITERAL
%token	<s> STRINGLITERAL
%token	COMMENT
%token	WHITESPACE

%start program

%%
program:	_PROGRAM
			{
				buffer << "\n\n;IR code" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				buffer << ";PUSH" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				buffer << ";PUSHREGS" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				buffer << ";JSR FUNC_main" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
				buffer << ";HALT" << endl;
				threeAC.push_back(buffer.str());
				buffer.str("");
			} id _BEGIN pgm_body _END
			{
				print_toList();
				insert_threeAC();
				print_threeAC();
				addTinyList();
				print_tinylist();
			};
id:		IDENTIFIER ;
pgm_body:	decl func_declarations ;
decl:		string_decl decl | var_decl decl |
			{
				if (link_count_enable == 1) {
					string link_num_string = to_string(link_num);
					buffer << ";LINK " << link_num_string << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
				}
				link_count_enable = 0;
				link_num = 0;
			} ;

/* Global String Declaration */
string_decl:	_STRING id _ASSIGNMENT str _SEMICOLON
		{
			stringList[$2] = $4;
			if (link_count_enable == 1) {
				link_num++;
			}
		};
str:		STRINGLITERAL ;

/* Variable Declaration */
var_decl:	var_type id_list
		{
			if (!strcmp($1,"FLOAT"))
			{
				while ($2 != NULL)
				{
					floatList.push_back($2 -> id);
					$2 = $2 -> id_tail;
					if (link_count_enable == 1) {
						link_num++;
					}
				}
			}
			else
			{
				while ($2 != NULL)
				{
					intList.push_back($2 -> id);
					$2 = $2 -> id_tail;
					if (link_count_enable == 1) {
						link_num++;
					}
				}
			}
		}
		_SEMICOLON ;
var_type:	_FLOAT | _INT ;
any_type:	var_type | _VOID ;
id_list:	id id_tail {$$ = new ID_List(); $$->addID($1); $$->nextID($2);};
id_tail:	_COMMA id id_tail {$$ = new ID_List(); $$->addID($2); $$->nextID($3);}| {$$ = NULL;};

/* Function Paramater List */
param_decl_list:	param_decl param_decl_tail {$$ = new Param_Decl_List(); $$->addPD($1); $$->nextPD($2);} | {$$ = NULL;};
param_decl:			var_type id
					{
						$$ = new Param_Decl();
						$$->addType($1);
						$$->addID($2);
						if (!strcmp($$ -> type, "INT")) {
							param_intList.push_back($2);
						}
						else if (!strcmp($$ -> type, "FLOAT")) {
							param_floatList.push_back($2);
						}
						return_reg_place++;
					};
param_decl_tail:	_COMMA param_decl param_decl_tail {$$ = new Param_Decl_List(); $$->addPD($2); $$->nextPD($3);} | {$$ = NULL;};

/* Function Declarations */
func_declarations:	func_decl func_declarations | /* empty */ ;
func_decl:			_FUNCTION any_type id
					{
						clear_varlist();
						return_reg_place = 0;
						buffer << ";LABEL FUNC_" << $3 << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
					} _OPENPAR param_decl_list _CLOSEPAR _BEGIN
					{
						link_count_enable = 1;
					} func_body _END
					{
						buffer << ";UNLINK" << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
						buffer << ";RET" << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
					};
func_body:			decl stmt_list ;

/* Statement List */
stmt_list:			stmt stmt_list | ;
stmt:				base_stmt | if_stmt | loop_stmt ;
base_stmt:			assign_stmt | read_stmt | write_stmt | control_stmt ;

/* Basic Statements */
assign_stmt:		assign_expr _SEMICOLON ;
assign_expr:		id _ASSIGNMENT expr
			{
				if (!from_call_expr) {
					$$ = new toList();
					$$ -> addDestination($1);
					$$ -> addDestType(findType($1));
					$$ -> addNode($3);
					$$ -> addOp((char*)"ASSIGN");
					myList.push_back($$);
				}
				else {
					$$ = new toList();
					$$ -> addDestination($1);
					$$ -> addDestType(findType($1));
					$$ -> addNode($3);
					$$ -> addOp((char*)"ASSIGN");
					myList.push_back($$);
					print_toList();
					clear_toList();
					buffer << ";PUSH" << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					buffer << ";PUSHREGS" << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					list<char*>::iterator it;
					for (it=comp_exprList.begin(); it!=comp_exprList.end();	 ++it) {
						char* match_expr = find_fromList((*it));
						if (!strcmp(match_expr, (*it))) {
							buffer << ";PUSH !T" << to_string(reg_count) << endl;
							threeAC.push_back(buffer.str());
							buffer.str("");
						}
						else {
							buffer << ";PUSH " << match_expr << endl;
							threeAC.push_back(buffer.str());
							buffer.str("");
						}
					}
					buffer << ";JSR FUNC_" << call_expr_id << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					for (it=comp_exprList.begin(); it!=comp_exprList.end(); ++it) {
						buffer << ";POP" << endl;
						threeAC.push_back(buffer.str());
						buffer.str("");
					}
					buffer << ";POPREGS" << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					buffer << ";POP !T" << to_string(++reg_count) << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					char* find_id = find_fromList($1);
					buffer << ";STORE" << $$ -> destination_type[0] << " !T" << to_string(reg_count++) << " " << find_id << endl;
					threeAC.push_back(buffer.str());
					buffer.str("");
					from_call_expr = 0;
				}
			};
read_stmt:		_READ _OPENPAR id_list _CLOSEPAR _SEMICOLON
			{
				$$ = new toList();
				$$ -> addDestination((char*)"READ");
				$$ -> addIDList($3);
				$$ -> addOp((char*)"READ");
				myList.push_back($$);
			};
write_stmt:		_WRITE _OPENPAR id_list _CLOSEPAR _SEMICOLON
			{
				$$ = new toList();
				$$ -> addDestination((char*)"WRITE");
				$$ -> addIDList($3);
				$$ -> addOp((char*)"WRITE");
				myList.push_back($$);
			};
return_stmt:	_RETURN expr _SEMICOLON
			{
				$$ = new toList();
				$$ -> addDestination((char*)"RETURN");
				$$ -> addNode($2);
				$$ -> addOp((char*)"RETURN");
				myList.push_back($$);
				print_toList();
				clear_toList();
			};

/* Expressions */
expr:			expr_prefix factor
			{
				if ($1->sign == NULL && $1->id == NULL && $1->type == NULL && $1->left == NULL && $1->right == NULL)
				{
					$$ = new ASTNode();
					$$ = $2;
					$$ -> addPrimary(prim);
				}
				else
				{
					$$ = new ASTNode();
					$$ = $1;
					$$ -> right = $2;
					$$ -> addPrimary(prim);
				}
				prim++;
			};
expr_prefix:		expr_prefix factor addop
			{
				if ($1->sign == NULL && $1->id == NULL && $1->type == NULL && $1->left == NULL && $1->right == NULL)
				{
					$3 -> left = $2;
					$$ = $3;
				}
				else
				{
					$1 -> right = $2;
					$3 -> left = $1;
					$$ = $3;
				}
			}|
			{
				$$ = new ASTNode();
				$$ -> addPrimary(prim);
			};
factor:		factor_prefix postfix_expr
		{
			if ($1->sign == NULL && $1->id == NULL && $1->type == NULL && $1->left == NULL && $1->right == NULL)
			{
				$$ = new ASTNode();
				$$ = $2;
				$$ -> addPrimary(prim);
			}
			else
			{
				$$ -> left = $2;
			}

		};
factor_prefix:		factor_prefix postfix_expr mulop
			{
				if ($1->sign == NULL && $1->id == NULL && $1->type == NULL && $1->left == NULL && $1->right == NULL)
				{
					$3 -> right = $2;
					$$ = $3;
				}
				else
				{
					$1 -> left = $2;
					$3 -> right = $1;
					$$ = $3;
				}
			} |
			{
				$$ = new ASTNode();
				$$ -> addPrimary(prim);
			};
postfix_expr:		primary
			{
				$$ = new ASTNode();
				$$ = $1;
				$$ -> addPrimary(prim);
			} | call_expr
			{
				$$ = new ASTNode();
				$$ = $1;
				$$ -> addPrimary(prim);
			};
call_expr:		id _OPENPAR expr_list _CLOSEPAR
			{
				$$ = new ASTNode();
				$$ = $3;
				$$ -> addPrimary(prim);
				call_expr_id = $1;
				push_comp_exprList();
				exprList.clear();
				from_call_expr = 1;
			};
expr_list:		expr
			{
				if (!exprList.empty() || !comp_exprList.empty()) {
					exprList.clear();
					comp_exprList.clear();
				}
				exprList.push_back($1);
			} expr_list_tail | {$$ = NULL;};
expr_list_tail:	_COMMA expr
			{
				exprList.push_back($2);
			} expr_list_tail | ;
primary:	_OPENPAR expr _CLOSEPAR
			{
				$$ = new ASTNode();
				$$ = $2;
			}
			| id
			{
				$$ = new ASTNode();
				$$ -> addID($1);
				$$ -> addType(findType($1));
				$$ -> addPrimary(prim);
			} |
			INTLITERAL
			{
				$$ = new ASTNode();
				$$ -> addType((char*)"INTLITERAL");
				$$ -> addID($1);
				$$ -> addPrimary(prim);
			} |
			FLOATLITERAL
			{
				$$ = new ASTNode();
				$$ -> addType((char*)"FLOATLITERAL");
				long double temp = atof($1);
				char* convert = new char[10];
				strcpy(convert, to_string(temp).c_str());
				$$ -> addID(convert);
				$$ -> addPrimary(prim);
			};
addop:			_PLUS
			{
				$$ = new ASTNode();
				$$ -> addSign($1);
				$$ -> addPrimary(prim);
			} |
			_MINUS
			{
				$$ = new ASTNode();
				$$ -> addSign($1);
				$$ -> addPrimary(prim);
			};
mulop:			_MUL
			{
				$$ = new ASTNode();
				$$ -> addSign($1);
				$$ -> addPrimary(prim);
			}|
			_DIV
			{
				$$ = new ASTNode();
				$$ -> addSign($1);
				$$ -> addPrimary(prim);
			};

/* Complex Statements and Condition */
if_stmt:			_IF _OPENPAR cond _CLOSEPAR
					{
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addNode($3);
						temp -> addOp((char*)"IF_COND_START");
						temp -> addDestType($3 -> type);
						myList.push_back(temp);
						print_toList();
						clear_toList();
					}
					decl stmt_list else_part _ENDIF
					{
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"IF_COND_END");
						myList.push_back(temp);
						print_toList();
						clear_toList();
					};
else_part:			_ELSE
					{
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"ELSE_COND");
						myList.push_back(temp);
					} decl stmt_list
					 |
					{
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"ELSE_COND");
						myList.push_back(temp);
					} ;
cond:				expr compop expr
					{
						$$ = new ASTNode();
						$$ -> left = $1;
						$$ -> right = $3;
						$$ -> sign = $2;
						$$ -> type = findType($1 -> id);
					}
					| _TRUE
					{
						$$ = new ASTNode();
						$$ -> id = $1;
					} | _FALSE
					{
						$$ = new ASTNode();
						$$ -> id = $1;
					};
compop:				_LTHAN | _GTHAN | _EQUALS | _NEQUALS | _LTEQUALS | _GTEQUALS ;
while_stmt:			_WHILE _OPENPAR cond _CLOSEPAR
					{
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addNode($3);
						temp -> addOp((char*)"WHILE_COND_START");
						temp -> addDestType($3 -> type);
						myList.push_back(temp);
						print_toList();
						clear_toList();
					} decl stmt_list _ENDWHILE
					{
						print_toList();
						clear_toList();
						toList* temp = new toList();
						temp -> addOp((char*)"WHILE_COND_END");
						myList.push_back(temp);
						print_toList();
						clear_toList();
					};


/*ECE468 ONLY*/
control_stmt:		return_stmt ;
loop_stmt:			while_stmt ;
%%
