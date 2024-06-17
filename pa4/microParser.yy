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
	ProgramRootNode* root;

%}


%union{
	
	char* s;
	struct ProgramRootNode* program;
	struct IdNode* id;
	struct ProgramBodyNode* pgm_body;
	struct DeclarationNode* decl;

	struct StringDeclarationNode* string_decl;
	struct StringNode* str;

	struct VariableDeclarationNode* var_decl;
	struct VariableTypeNode* var_type;
	struct AnyTypeNode* any_type;
	struct IdListNode* id_list;
	struct IdTailNode* id_tail;

	struct StatementListNode* stmt_list;
	struct StatementNode* stmt;
	struct BaseStatementNode* base_stmt;
	struct IfStatementNode* if_stmt;
	struct ElsePartNode* else_part;
	struct ConditionNode* cond;
	struct ComparisonOperationNode* compop;
	struct InitialStatementNode* init_stmt;
	struct IncrementalStatementNode* incr_stmt;
	struct ForStatementNode* for_stmt;


	struct AssignmentStatementNode* assign_stmt;
	struct AssignmentExpressionNode* assign_expr;
	struct ReadStatementNode* read_stmt;
	struct WriteStatementNode* write_stmt;
	struct ReturnStatementNode* return_stmt;

	struct ExpressionNode* expr;
	struct ExpressionPrefixNode* expr_prefix;
	struct FactorNode* factor;
	struct FactorPrefixNode* factor_prefix;
	struct PostFixExpressionNode* postfix_expr;
	struct CallExpressionNode* call_expr;
	struct ExpressionListNode* expr_list;
	struct ExpressionListTailNode* expr_list_tail;
	struct PrimaryNode* primary;
	struct AddOpNode* addop;
	struct MulOpNode* mulop;


	struct ParameterDeclarationListNode* param_decl_list;
	struct ParameterDeclarationNode* param_decl;
	struct ParameterDeclarationTailNode* param_decl_tail;
	struct FunctionDeclarationsNode* func_declarations;
	struct FunctionDeclarationNode* func_decl;
	struct FunctionBodyNode* func_body;

}

%type <program> program;
%type <id> id;
%type <pgm_body> pgm_body;
%type <decl> decl;
%type <string_decl> string_decl;
%type <str> str;
%type <var_decl> var_decl;
%type <var_type> var_type;
%type <any_type> any_type;
%type <id_list> id_list;
%type <id_tail> id_tail;
%type <stmt_list> stmt_list;
%type <stmt> stmt;
%type <base_stmt> base_stmt;
%type <assign_stmt> assign_stmt;
%type <assign_expr> assign_expr;
%type <read_stmt> read_stmt;
%type <write_stmt> write_stmt;
%type <return_stmt> return_stmt;
%type <expr> expr;
%type <expr_prefix> expr_prefix;
%type <factor> factor;
%type <factor_prefix> factor_prefix;
%type <postfix_expr> postfix_expr;
%type <call_expr> call_expr;
%type <expr_list> expr_list;
%type <expr_list_tail> expr_list_tail;
%type <primary> primary;
%type <addop> addop;
%type <mulop> mulop;
%type <if_stmt> if_stmt;
%type <else_part> else_part;
%type <cond> cond;
%type <compop> compop;
%type <init_stmt> init_stmt;
%type <incr_stmt> incr_stmt;
%type <for_stmt> for_stmt;


%type <param_decl_list> param_decl_list;
%type <param_decl> param_decl;
%type <param_decl_tail> param_decl_tail;
%type <func_declarations> func_declarations;
%type <func_decl> func_decl;
%type <func_body> func_body;

/* declare tokens */

%token <s> _PROGRAM _BEGIN _END _FUNCTION _READ _WRITE _IF _ELSE _FI _FOR _ROF _RETURN _INT _VOID _STRING _FLOAT
%token <s> _IDENTIFIER _STRINGLITERAL _INTLITERAL _FLOATLITERAL _COMMENT
%token <s> _ASSIGNMENT _PLUS _MINUS _MUL _DIV _EQUALS _NEQUALS _LESSTHAN _GREATERTHAN _LEFTPARANTHESIS _RIGHTPARANTHESIS _SEMICOLON _COMMA _LESSOREQUAL _GREATEROREQUAL
%token _WHITESPACE
%token _EOF
%%

/* Program */
program: _PROGRAM id _BEGIN pgm_body _END 
{ 
	$$ = new ProgramRootNode();
	$$->add($2, $4);
	$$->whoiam("program");
	root = $$;
};
id: _IDENTIFIER
{
	$$ = new IdNode();
	$$->add($1);
	$$->whoiam("id");
};
pgm_body: decl func_declarations
{
	$$ = new ProgramBodyNode();
	$$->add($1,$2);
	$$->whoiam("pgm_body");
};
decl: string_decl decl 
{
	$$ = new DeclarationNode();
	$$->add_str($1, $2);
	$$->whoiam("decl");
}
| var_decl decl 
{
	$$ = new DeclarationNode();
	$$->add_var($1,$2);
	$$->whoiam("decl");
}
| /* empty */
{
	$$ = NULL;
};

/* Global String Declaration */
string_decl: _STRING id _ASSIGNMENT str _SEMICOLON 
{
	$$ = new StringDeclarationNode();
	$$->add($2, $4);
	$$->whoiam("string_decl");
};
str: _STRINGLITERAL
{
	$$ = new StringNode();
	$$->add($1);
	$$->whoiam("str");
};

/* Variable Declaration */
var_decl: var_type id_list _SEMICOLON 
{
	$$ = new VariableDeclarationNode();
	$$->add($1, $2);
	$$->whoiam("var_decl");

};
var_type: _FLOAT
{
	$$ = new VariableTypeNode();
	$$->add_float($1);
	$$->whoiam("var_type");
	$$->add_type("FLOAT");
}
| _INT
{
	$$ = new VariableTypeNode();
	$$->add_int($1);
	$$->whoiam("var_type");
	$$->add_type("INT");
};
any_type: var_type 
{
	$$ = new AnyTypeNode();
	$$->add_var($1);
	$$->whoiam("any_type");
}
| _VOID
{
	$$ = new AnyTypeNode();
	$$->add_void($1);
	$$->whoiam("any_type");
};
id_list: id id_tail 
{
	$$ = new IdListNode(); 
	$$->add($1, $2);
	$$->whoiam("id_list");
};
id_tail: _COMMA id id_tail 
{	
	$$ = new IdTailNode(); 
	$$->add($2, $3);
	$$->whoiam("id_tail");
} 
| 
{	
	$$ = NULL;
};
/* Function Paramater List */

param_decl_list: param_decl param_decl_tail
{
	$$ = new ParameterDeclarationListNode();
	$$->add($1,$2); 
	$$->whoiam("param_decl_list");
} 
| /*empty*/
{
	$$ = NULL;
};
param_decl: var_type id 
{
	$$ = new ParameterDeclarationNode(); 
	$$->add($1,$2);
	$$->whoiam("param_decl");
};
param_decl_tail: _COMMA param_decl param_decl_tail 
{
	$$ = new ParameterDeclarationTailNode(); 
	$$->add($2,$3);
	$$->whoiam("param_decl_tail");
}|/*empty*/
{
	$$ = NULL;
};


/* Function Declarations */
func_declarations: func_decl func_declarations 
{
	$$ = new FunctionDeclarationsNode(); 
	$$->add($1,$2);
	$$->whoiam("func_declarations");
}
| /* empty */
{
	$$ = NULL;
};
func_decl: _FUNCTION any_type id _LEFTPARANTHESIS param_decl_list _RIGHTPARANTHESIS _BEGIN func_body _END
{
	$$ = new FunctionDeclarationNode(); 
	$$->add($2,$3,$5,$8);
	$$->whoiam("func_decl");
};
func_body: decl stmt_list
{
	$$ = new FunctionBodyNode(); 
	$$->add($1,$2);
	$$->whoiam("func_body");
};

/* Statement List */
stmt_list: stmt stmt_list 
{
	$$ = new StatementListNode();
	$$->add($1, $2);
	$$->whoiam("stmt_list");
}| 
/* empty */
{
	$$ = NULL;
};
stmt: base_stmt 
{
	$$ = new StatementNode();
	$$->add_base($1);
	$$->whoiam("stmt");
}
| if_stmt 
{
	$$ = new StatementNode();
	$$->add_if($1);
	$$->whoiam("stmt");
}
| for_stmt
{
	$$ = new StatementNode();
	$$->add_for($1);
	$$->whoiam("stmt");
};

base_stmt: assign_stmt
{
	$$ = new BaseStatementNode();
	$$->add_assign($1);
	$$->whoiam("base_stmt");

}| read_stmt 
{
	$$ = new BaseStatementNode();
	$$->add_read($1);
	$$->whoiam("base_stmt");
}| write_stmt
{
	$$ = new BaseStatementNode();
	$$->add_write($1);
	$$->whoiam("base_stmt");
}| return_stmt
{
	$$ = new BaseStatementNode();
	$$->add_return($1);
	$$->whoiam("base_stmt");
};

/* Basic Statements */
assign_stmt: assign_expr _SEMICOLON
{
	$$ = new AssignmentStatementNode;
	$$->add($1);
	$$->whoiam("assign_stmt");
};
assign_expr: id _ASSIGNMENT expr
{
	$$ = new AssignmentExpressionNode;
	$$->add($1, $3);
	$$->whoiam("assign_expr");
};
read_stmt: _READ _LEFTPARANTHESIS id_list _RIGHTPARANTHESIS _SEMICOLON
{
	$$ = new ReadStatementNode;
	$$->add($3);
	$$->whoiam("read_stmt");
};
write_stmt: _WRITE _LEFTPARANTHESIS id_list _RIGHTPARANTHESIS _SEMICOLON
{
	$$ = new WriteStatementNode;
	$$->add($3);
	$$->whoiam("write_stmt");
};
return_stmt: _RETURN expr _SEMICOLON
{
	$$ = new ReturnStatementNode;
	$$->add($2);
	$$->whoiam("return_stmt");
};

/* Expressions */
expr: expr_prefix factor
{
	$$ = new ExpressionNode;
	$$->add($1, $2);
	$$->whoiam("expr");
};
expr_prefix: expr_prefix factor addop 
{
	$$ = new ExpressionPrefixNode;
	$$->add($1, $2, $3);
	$$->whoiam("expr_prefix");
}| /* empty */
{
	$$ = NULL; 
};
factor: factor_prefix postfix_expr
{
	$$ = new FactorNode;
	$$->add($1, $2);
	$$->whoiam("factor");
};
factor_prefix: factor_prefix postfix_expr mulop 
{
	$$ = new FactorPrefixNode;
	$$->add($1, $2, $3);
	$$->whoiam("factor_prefix");
}| /* empty */
{
	$$ = NULL;
};
postfix_expr: primary 
{
	$$ = new PostFixExpressionNode;
	$$->add_pri($1);
	$$->whoiam("postfix_expr");
}
| call_expr
{
	$$ = new PostFixExpressionNode;
	$$->add_call($1);
	$$->whoiam("postfix_expr");
};
call_expr: id _LEFTPARANTHESIS expr_list _RIGHTPARANTHESIS
{
	$$ = new CallExpressionNode;
	$$->add($1, $3);
	$$->whoiam("call_expr");
};
expr_list: expr expr_list_tail 
{
	$$ = new ExpressionListNode;
	$$->add($1, $2);
	$$->whoiam("expr_list");
}
| /* empty */
{
	$$ = NULL;
};
expr_list_tail: _COMMA expr expr_list_tail 
{
	$$ = new ExpressionListTailNode;
	$$->add($2, $3);
	$$->whoiam("expr_list_tail");
}
| /* empty */
{
	$$ = NULL;
};
primary: _LEFTPARANTHESIS expr _RIGHTPARANTHESIS 
{
	$$ = new PrimaryNode;
	$$->add_expr($2);
	$$->whoiam("primary");
}
| id 
{
	$$ = new PrimaryNode;
	$$->add_id($1);
	$$->whoiam("primary");
}
| _INTLITERAL 
{
	$$ = new PrimaryNode;
	$$->add_int($1);
	$$->whoiam("primary");
	$$->add_type("INTLITERAL");
}
| _FLOATLITERAL
{
	$$ = new PrimaryNode;
	$$->add_float($1);
	$$->whoiam("primary");
	$$->add_type("FLOATLITERAL");
};
addop: _PLUS 
{
	$$ = new AddOpNode;
	$$->add("PLUS");
	$$->whoiam("addop");
}
| _MINUS
{
	$$ = new AddOpNode;
	$$->add("MINUS");
	$$->whoiam("addop");
};
mulop: _MUL 
{
	$$ = new MulOpNode;
	$$->add("MUL");
	$$->whoiam("mulop");
}
| _DIV
{
	$$ = new MulOpNode;
	$$->add("DIV");
	$$->whoiam("mulop");
};
/* Complex Statements and Condition */
if_stmt: _IF _LEFTPARANTHESIS cond _RIGHTPARANTHESIS decl stmt_list else_part _FI
{
	$$ = new IfStatementNode;
	$$->add($3, $5, $6, $7);
	$$->whoiam("if_stmt");
};
else_part: _ELSE decl stmt_list 
{
	$$ = new ElsePartNode;
	$$->add($2, $3);
	$$->whoiam("else_part");
}
| /* empty */
{
	$$ = NULL;
};
cond: expr compop expr
{
	$$ = new ConditionNode;
	$$->add($1, $2, $3);
	$$->whoiam("cond");
};
compop: _LESSTHAN 
{
	$$ = new ComparisonOperationNode;
	$$->add("LESSTHAN");
	$$->whoiam("compop");
}| _GREATERTHAN
{
	$$ = new ComparisonOperationNode;
	$$->add("GREATERTHAN");
	$$->whoiam("compop");
}| _EQUALS
{
	$$ = new ComparisonOperationNode;
	$$->add("EQUALS");
	$$->whoiam("compop");
}
| _NEQUALS
{
	$$ = new ComparisonOperationNode;
	$$->add("NEQUALS");
	$$->whoiam("compop");
}
| _LESSOREQUAL
{
	$$ = new ComparisonOperationNode;
	$$->add("LESSOREQUAL");
	$$->whoiam("compop");
}| _GREATEROREQUAL
{
	$$ = new ComparisonOperationNode;
	$$->add("GREATEROREQUAL");
	$$->whoiam("compop");
};
init_stmt: assign_expr 
{
	$$ = new InitialStatementNode;
	$$->add($1);
	$$->whoiam("init_stmt");
}
| /* empty */
{
	$$ = NULL;
};
incr_stmt: assign_expr 
{
	$$ = new IncrementalStatementNode;
	$$->add($1);
	$$->whoiam("incr_stmt");
}
| /* empty */
{
	$$ = NULL;
};
for_stmt: _FOR _LEFTPARANTHESIS init_stmt _SEMICOLON cond _SEMICOLON incr_stmt _RIGHTPARANTHESIS decl stmt_list _ROF
{
	$$ = new ForStatementNode;
	$$->add($3,$5,$7,$9,$10);
	$$->whoiam("for_stmt");
};

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
