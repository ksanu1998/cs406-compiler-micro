#include <cstdio>
#include <string>
#include <vector>
using namespace std;

// string findDeclarationError();
// bool isDeclarationError();
// string getWronglyDeclaredVariable();

/* AST Nodes for Program */

struct Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
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

};
struct ProgramRootNode : Node
{
	struct IdNode* id;
	struct ProgramBodyNode* pgm_body;
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	/* check if these are required! */
	string _program;
	string _begin;
	string _end;
	void add(IdNode* _id, ProgramBodyNode* _pgm_body) {
		id = _id;
		pgm_body = _pgm_body;
	}
};

struct IdNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	char* _identifier;
	void add(char* input) {
		_identifier = input;
	}
};

struct ProgramBodyNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct DeclarationNode* decl;
	struct FunctionDeclarationsNode* func_declarations;
	void add(DeclarationNode* _decl, FunctionDeclarationsNode* _func_declarations) {
		decl = _decl;
		func_declarations = _func_declarations;
	}
};

struct DeclarationNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct StringDeclarationNode* string_decl;
	struct DeclarationNode* decl;
	struct VariableDeclarationNode* var_decl;
	void add_str(StringDeclarationNode* _string_decl, DeclarationNode* _decl) {
		string_decl = _string_decl;
		decl = _decl;
		// var_decl = _var_decl;
	}
	void add_var(VariableDeclarationNode* _var_decl, DeclarationNode* _decl) {
		// string_decl = _string_decl;
		decl = _decl;
		var_decl = _var_decl;
	}
	// empty
};

/* AST Nodes for Global String Declaration */
struct StringDeclarationNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct IdNode* id;
	struct StringNode* str;
	void add(IdNode* _id, StringNode* _str) {
		id = _id;
		str = _str;
	}
};

struct StringNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	char* _stringliteral;
	void add(char* input) {
		_stringliteral = input;
	}
};

/* AST Nodes for Variable Declaration */
struct VariableDeclarationNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct VariableTypeNode* var_type;
	struct IdListNode* id_list;
	void add(VariableTypeNode* _var_type, IdListNode* _id_list) {
		var_type = _var_type;
		id_list = _id_list;
	}
};

struct VariableTypeNode : Node
{
	string _whoiam;
	string _type;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	char* _type_int;
	void add_int(char* input) {
		_type_int = input;
	}
	char* _type_float;
	void add_float(char* input) {
		_type_float = input;
	}
	void add_type(string input) {
		_type = input;
	}
};

struct AnyTypeNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct VariableTypeNode* var_type;
	char* _void;
	void add_var(VariableTypeNode* _var_type) {
		var_type = _var_type;
	}
	void add_void(char* input) {
		_void = input;
	}
};

struct IdListNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct IdNode* id;
	struct IdTailNode* id_tail;
	void add(IdNode* _id, IdTailNode* _id_tail) {
		id = _id;
		id_tail = _id_tail;
	}
};

struct IdTailNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct IdNode* id;
	struct IdTailNode* id_tail;
	void add(IdNode* _id, IdTailNode* _id_tail) {
		id = _id;
		id_tail = _id_tail;
	}
	// empty
};

/* AST Nodes for Statement List */

struct StatementListNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct StatementNode* stmt;
	struct StatementListNode* stmt_list;
	void add(StatementNode* _stmt, StatementListNode* _stmt_list) {
		stmt = _stmt;
		stmt_list = _stmt_list;
	}
	// empty
};

struct StatementNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct BaseStatementNode* base_stmt;
	struct IfStatementNode* if_stmt;
	struct ForStatementNode* for_stmt;
	void add_base(BaseStatementNode* _base_stmt) {
		base_stmt = _base_stmt;
	}
	void add_if(IfStatementNode* _if_stmt) {
		if_stmt = _if_stmt;
	}
	void add_for(ForStatementNode* _for_stmt) {
		for_stmt = _for_stmt;
	}
	// empty
};

struct BaseStatementNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct AssignmentStatementNode* assign_stmt;
	struct ReadStatementNode* read_stmt;
	struct WriteStatementNode* write_stmt;
	struct ReturnStatementNode* return_stmt;
	void add_assign(AssignmentStatementNode* _assign_stmt) {
		assign_stmt = _assign_stmt;
	}
	void add_read(ReadStatementNode* _read_stmt) {
		read_stmt = _read_stmt;
	}
	void add_write(WriteStatementNode* _write_stmt) {
		write_stmt = _write_stmt;
	}
	void add_return(ReturnStatementNode* _return_stmt) {
		return_stmt = _return_stmt;
	}
	// empty
};

/* AST Nodes for Basic Statements */
struct AssignmentStatementNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct AssignmentExpressionNode* assign_expr;
	void add(AssignmentExpressionNode* _assign_expr)
	{
		assign_expr = _assign_expr;
	}
};

struct AssignmentExpressionNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct IdNode* id;
	struct ExpressionNode* expr;
	void add(IdNode* _id, ExpressionNode* _expr)
	{
		id = _id;
		expr = _expr;
	}
};

struct ReadStatementNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct IdListNode* id_list;
	void add(IdListNode* _id_list) {
		id_list = _id_list;
	}
};

struct WriteStatementNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct IdListNode* id_list;
	void add(IdListNode* _id_list) {
		id_list = _id_list;
	}
};

struct ReturnStatementNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct ExpressionNode* expr;
	void add(ExpressionNode* _expr) {
		expr = _expr;
	}
};

/* AST Nodes for Expressions */

struct ExpressionNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct ExpressionPrefixNode* expr_prefix;
	struct FactorNode* factor;
	void add(ExpressionPrefixNode* _expr_prefix, FactorNode* _factor) {
		expr_prefix = _expr_prefix;
		factor = _factor;
	}
};

struct ExpressionPrefixNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct ExpressionPrefixNode* expr_prefix;
	struct FactorNode* factor;
	struct AddOpNode* addop;
	void add(ExpressionPrefixNode* _expr_prefix, FactorNode* _factor, AddOpNode* _addop) {
		expr_prefix = _expr_prefix;
		factor = _factor;
		addop = _addop;
	}
	// empty
};

struct FactorNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct FactorPrefixNode* factor_prefix;
	struct PostFixExpressionNode* postfix_expr;
	void add(FactorPrefixNode* _factor_prefix, PostFixExpressionNode* _postfix_expr) {
		factor_prefix = _factor_prefix;
		postfix_expr = _postfix_expr;
	}

};

struct FactorPrefixNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct FactorPrefixNode* factor_prefix;
	struct PostFixExpressionNode* postfix_expr;
	struct MulOpNode* mulop;
	void add(FactorPrefixNode* _factor_prefix, PostFixExpressionNode* _postfix_expr, MulOpNode* _mulop) {
		factor_prefix = _factor_prefix;
		postfix_expr = _postfix_expr;
		mulop = _mulop;
	}
	// empty 
};

struct PostFixExpressionNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct PrimaryNode* primary;
	struct CallExpressionNode* call_expr;
	void add_pri(PrimaryNode* _primary) {
		primary = _primary;
		// call_expr = _call_expr;
	}
	void add_call(CallExpressionNode* _call_expr) {
		// primary = _primary;
		call_expr = _call_expr;
	}
};

struct CallExpressionNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct IdNode* id;
	struct ExpressionListNode* expr_list;
	void add(IdNode* _id, ExpressionListNode* _expr_list) {
		id = _id;
		expr_list = _expr_list;
	}
};

struct ExpressionListNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct ExpressionNode* expr;
	struct ExpressionListTailNode* expr_list_tail;
	void add(ExpressionNode* _expr, ExpressionListTailNode* _expr_list_tail) {
		expr = _expr;
		expr_list_tail = _expr_list_tail;
	}
	// empty
};

struct ExpressionListTailNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct ExpressionNode* expr;
	struct ExpressionListTailNode* expr_list_tail;
	void add(ExpressionNode* _expr, ExpressionListTailNode* _expr_list_tail) {
		expr = _expr;
		expr_list_tail = _expr_list_tail;
	}
	// empty
};

struct PrimaryNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct ExpressionNode* expr;
	struct IdNode* id;
	char* _type_int;
	char* _type_float;
	string _type;
	void add_expr(ExpressionNode* _expr) {
		expr = _expr;
		// id = _id;
		// _type = input;
	}
	void add_id(IdNode* _id) {
		// expr = _expr;
		id = _id;
		// _type = input;
	}
	void add_int(char* input) {
		// expr = _expr;
		// id = _id;
		_type_int = input;
	}
	void add_float(char* input) {
		// expr = _expr;
		// id = _id;
		_type_float = input;
	}
	void add_type(string input) {
		// expr = _expr;
		// id = _id;
		_type = input;
	}
	// empty
};

struct AddOpNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	string _type;
	void add(string input) {
		_type = input;
	}
};

struct MulOpNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	string _type;
	void add(string input) {
		_type = input;
	}
};

struct Param_Decl  : Node{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	char* type;
	char* id;
	void addType(char* var_type) {
		type = var_type;
	}
	void addID(char* get_id) {
		id = get_id;
	}
};

struct Param_Decl_List : Node {
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	Param_Decl* pd;
	Param_Decl_List* nextpd;
	void addPD(Param_Decl* param_decl) {
		pd = param_decl;
	}
	void nextPD(Param_Decl_List* next) {
		nextpd = next;
	}
};

struct IfStatementNode  : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct ConditionNode* cond;
	struct DeclarationNode* decl;
	struct StatementListNode* stmt_list;
	struct ElsePartNode* else_part;
	void add(ConditionNode* _cond, DeclarationNode* _decl, StatementListNode* _stmt_list, ElsePartNode* _else_part)
	{
		cond = _cond;
		decl = _decl;
		stmt_list = _stmt_list;
		else_part = _else_part;
	}
};

struct ElsePartNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct DeclarationNode* decl;
	struct StatementListNode* stmt_list;
	void add(DeclarationNode* _decl, StatementListNode* _stmt_list)
	{
		decl = _decl;
		stmt_list = _stmt_list;
	}
	//empty
};

struct ConditionNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct ExpressionNode* expr;
	struct ComparisonOperationNode* compop;
	struct ExpressionNode* expr_t;
	void add(ExpressionNode* _expr, ComparisonOperationNode* _compop, ExpressionNode* _expr_t)
	{
		expr = _expr;
		compop = _compop;
		expr_t = _expr_t;
	}
};

struct ComparisonOperationNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	string _type;
	void add(string input) {
		_type = input;
	}
};

struct InitialStatementNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct AssignmentExpressionNode* assign_expr;
	void add(AssignmentExpressionNode* _assign_expr)
	{
		assign_expr = _assign_expr;
	}
	//empty
};

struct IncrementalStatementNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct AssignmentExpressionNode* assign_expr;
	void add(AssignmentExpressionNode* _assign_expr)
	{
		assign_expr = _assign_expr;
	}
	//empty
};

struct ForStatementNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct InitialStatementNode* init_stmt;
	struct ConditionNode* cond;
	struct IncrementalStatementNode* incr_stmt;
	struct DeclarationNode* decl;
	struct StatementListNode* stmt_list;
	void add(InitialStatementNode* _init_stmt, ConditionNode* _cond, IncrementalStatementNode* _incr_stmt, DeclarationNode* _decl, StatementListNode* _stmt_list)
	{
		init_stmt = _init_stmt;
		cond = _cond;
		incr_stmt = _incr_stmt;
		decl = _decl;
		stmt_list = _stmt_list;
	}
};

struct StrEntry  : Node{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	string id;
	string str;
};

struct ID_List  : Node{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	string id;
	ID_List* id_tail;
};

struct VarEntry  : Node{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	string var_type;
	ID_List* id_list;
};



struct Stmt_List : Node {
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	Stmt_List* next_stmt_list;
};

struct Func_Body : Node {
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	Stmt_List* st_list;
};

struct Func_Decl  : Node{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	string any_type;
	string id;
	Param_Decl_List* param_decl_list;
	Func_Body* func_b;
};

struct Func_Declarations : Node {
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	Func_Decl* fd;
	Func_Declarations* next_function;
};

struct ParameterDeclarationListNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct ParameterDeclarationNode* param_decl;
	struct ParameterDeclarationTailNode* param_decl_tail;
	void add(ParameterDeclarationNode* _param_decl, ParameterDeclarationTailNode* _param_decl_tail)
	{
		param_decl = _param_decl;
		param_decl_tail = _param_decl_tail;
	}
};

struct ParameterDeclarationNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct VariableTypeNode* var_type;
	struct IdNode* id;
	void add(VariableTypeNode* _var_type, IdNode* _id)
	{
		var_type = _var_type;
		id = _id;
	}
};

struct ParameterDeclarationTailNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct ParameterDeclarationNode* param_decl;
	struct ParameterDeclarationTailNode* param_decl_tail;
	void add(ParameterDeclarationNode* _param_decl, ParameterDeclarationTailNode* _param_decl_tail)
	{
		param_decl = _param_decl;
		param_decl_tail = _param_decl_tail;
	}
};

struct FunctionDeclarationsNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct FunctionDeclarationNode* func_decl;
	struct FunctionDeclarationsNode* func_declarations;
	void add(FunctionDeclarationNode* _func_decl, FunctionDeclarationsNode* _func_declarations)
	{
		func_decl = _func_decl;
		func_declarations = _func_declarations;
	}
};

struct FunctionDeclarationNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct AnyTypeNode* any_type;
	struct IdNode* id;
	struct ParameterDeclarationListNode* param_decl_list;
	struct FunctionBodyNode* func_body;
	void add(AnyTypeNode* _any_type, IdNode* _id, ParameterDeclarationListNode* _param_decl_list, FunctionBodyNode* _func_body)
	{
		any_type = _any_type;
		id = _id;
		param_decl_list = _param_decl_list;
		func_body = _func_body;
	}
};

struct FunctionBodyNode : Node
{
	string _whoiam;
	void whoiam(string input)
	{
		_whoiam = input;
	}
	struct DeclarationNode* decl;
	struct StatementListNode* stmt_list;
	void add(DeclarationNode* _decl, StatementListNode* _stmt_list)
	{
		decl = _decl;
		stmt_list = _stmt_list;
	}
};

struct IRNode
{
	char* operation;
	char* register1;
	char* register2;
	char* register3;
	void addOp(char* input) {
		operation = input;
	}
	void addReg1(char* input) {
		register1 = input;
	}
	void addReg2(char* input) {
		register2 = input;
	}
	void addReg3(char* input) {
		register3 = input;
	}
};

struct new_threeAC 
{
	string operation;
	string register1;
	string register2;
	string register3;
	void addOp(string input) 
	{
		operation = input;
	}
	void addReg1(string input) 
	{
		register1 = input;
	}
	void addReg2(string input) 
	{
		register2 = input;
	}
	void addReg3(string input) 
	{
		register3 = input;
	}
};
