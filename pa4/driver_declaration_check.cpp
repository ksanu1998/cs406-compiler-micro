#include <stdio.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include "microParser.hpp"
#include "parserStructures.hpp"

extern int yylex();
extern FILE* yyin;
extern char* yytext;
extern int yyset_in(FILE * in_str);
extern struct ProgramRootNode* root;
list <IRNode*> ir_list;
IRNode* irnode;
list <new_threeAC*> threeAC_list;
vector <string> threeAC;
void add_to_IR(char* operation, char* register1, char* register2, char* register3)
{
	irnode = new IRNode();
	irnode->addOp(operation);
	irnode->addReg1(register1);
	irnode->addReg2(register2);
	irnode->addReg3(register3);
	string temp = ";";
	temp.append(irnode->operation);
	temp.append(irnode->register1);
	temp.append(irnode->register2);
	temp.append(irnode->register3);
	threeAC.push_back(temp);
}
struct CodeObject
{
	struct CodeObject* prev;
	string str;
	int int_val;
	float float_val;
	bool is_stored;
	bool result_type; // true => int and false=>float

};
struct object 
{
	bool is_int;
	bool is_float;
	int int_result;
	float float_result;
	int int_val;
	float float_val;
};
int yyparse();

int main(int argc, char** argv) {
	FILE* file = fopen(argv[1], "r");
	yyin = file;
	freopen(argv[2], "w", stdout);
	// cout<<"where"<<endl;
	// yyparse();
	yyset_in(file);

	if(!yyparse()){
		vector<Node*> v;
		vector<Node*> out;
		vector<Node*> codobj;
		struct Node* node = new Node;
		struct CodeObject* base = new CodeObject;
		node->program = root;
		// cout<<"*********************"<<endl;
		node->whoiam("program");
		v.push_back(node);
		// cout<<root->_whoiam<<endl;
		while(v.size()!=0) // do post order traversal of the AST
		{
			if(v[v.size()-1]->_whoiam=="program")
			{
				// cout<<"here51"<<endl;
				struct Node* node1 = new Node;
				node1->id = v[v.size()-1]->program->id;
				node1->whoiam("id");

				struct Node* node2 = new Node;
				node2->pgm_body = v[v.size()-1]->program->pgm_body;
				node2->whoiam("pgm_body");
				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
			
			}
			else if (v[v.size()-1]->_whoiam=="id")
			{
				// cout<<"here52"<<endl;
				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
			}
			else if (v[v.size()-1]->_whoiam=="pgm_body")
			{
				// cout<<"here30"<<endl;
				struct Node* node1 = new Node;
				node1->decl = v[v.size()-1]->pgm_body->decl;
				node1->whoiam("decl");

				struct Node* node2 = new Node;
				node2->func_declarations = v[v.size()-1]->pgm_body->func_declarations;
				node2->whoiam("func_declarations");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
			}
			else if (v[v.size()-1]->_whoiam=="decl")
			{
				if(v[v.size()-1]->decl!=NULL)
				{
					struct Node* node1 = new Node;
					if(v[v.size()-1]->decl->_whoiam=="string_decl")
					{
						node1->string_decl = v[v.size()-1]->decl->string_decl;
						node1->whoiam("string_decl");
						// cout<<"here53.2.if"<<endl;
					}
					else if(v[v.size()-1]->decl->_whoiam=="var_decl")
					{
						node1->var_decl = v[v.size()-1]->decl->var_decl;
						node1->whoiam("var_decl");
						// cout<<"here53.2.elseif"<<endl;
					}
					else
					{
						// generate IR
						// cout<<v[v.size()-1]->_whoiam<<endl;
						out.push_back(v[v.size()-1]);
						v.pop_back();
						continue;
					}
					struct Node* node2 = new Node;
					node2->decl = v[v.size()-1]->decl->decl;
					node2->whoiam("decl");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
					v.push_back(node2);
				}
				else
				{
					// cout<<"here53.1"<<endl;
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
			}
			else if (v[v.size()-1]->_whoiam=="string_decl")
			{
				// cout<<"here54"<<endl;
				struct Node* node1 = new Node;
				node1->id = v[v.size()-1]->string_decl->id;
				node1->whoiam("id");
				struct Node* node2 = new Node;
				node2->str = v[v.size()-1]->string_decl->str;
				node2->whoiam("str");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
			}
			else if(v[v.size()-1]->_whoiam=="str")
			{
				// cout<<"here55"<<endl;
				// generate IR
				// cout<<"STRING"<<endl;
				cout<<v[v.size()-1]->str->_stringliteral<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
			}
			else if (v[v.size()-1]->_whoiam=="var_decl")
			{
				// cout<<"here56"<<endl;
				struct Node* node1 = new Node;
				node1->var_type = v[v.size()-1]->var_decl->var_type;
				node1->whoiam("var_type");
				struct Node* node2 = new Node;
				node2->id_list = v[v.size()-1]->var_decl->id_list;
				node2->whoiam("id_list");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
				
			}
			else if(v[v.size()-1]->_whoiam=="var_type")
			{
				// cout<<"here57"<<endl;
				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				cout<<v[v.size()-1]->var_type->_type_float<<"**"<<endl;
				cout<<v[v.size()-1]->var_type->_type_int<<"**"<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
			}
			else if (v[v.size()-1]->_whoiam=="any_type")
			{
				// cout<<"here58"<<endl;
				struct Node* node1 = new Node;
				if(v[v.size()-1]->any_type->var_type!=NULL)
				{
					node1->var_type = v[v.size()-1]->any_type->var_type;
					node1->whoiam("var_type");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}
				else
				{
					// generate IR
					// cout<<"VOID"<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();

				}
			}
			else if (v[v.size()-1]->_whoiam=="id_list")
			{
				// cout<<"here59"<<endl;
				struct Node* node1 = new Node;
				node1->id = v[v.size()-1]->id_list->id;
				node1->whoiam("id");
				struct Node* node2 = new Node;
				node2->id_tail = v[v.size()-1]->id_list->id_tail;
				node2->whoiam("id_tail");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
			}
			else if (v[v.size()-1]->_whoiam=="id_tail")
			{
				// cout<<"here40"<<endl;
				if(v[v.size()-1]->id_tail==NULL)
				{
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else
				{
					struct Node* node1 = new Node;
					node1->id = v[v.size()-1]->id_tail->id;
					node1->whoiam("id");
					struct Node* node2 = new Node;
					node2->id_tail = v[v.size()-1]->id_tail->id_tail;
					node2->whoiam("id_tail");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
					v.push_back(node2);
				}
			}
			else if (v[v.size()-1]->_whoiam=="param_decl_list")
			{
				// cout<<"here29"<<endl;
				if(v[v.size()-1]->param_decl_list==NULL)
				{
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else
				{
					struct Node* node1 = new Node;
					node1->param_decl = v[v.size()-1]->param_decl_list->param_decl;
					node1->whoiam("param_decl");
					struct Node* node2 = new Node;
					node2->param_decl_tail = v[v.size()-1]->param_decl_list->param_decl_tail;
					node2->whoiam("param_decl_tail");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
					v.push_back(node2);
				}
				
				
			}
			else if (v[v.size()-1]->_whoiam=="param_decl")
			{

				// cout<<"here50"<<endl;
				struct Node* node1 = new Node;
				node1->var_type = v[v.size()-1]->param_decl->var_type;
				node1->whoiam("var_type");
				struct Node* node2 = new Node;
				node2->id = v[v.size()-1]->param_decl->id;
				node2->whoiam("id");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
			}
			else if (v[v.size()-1]->_whoiam=="param_decl_tail")
			{
				// cout<<"here61"<<endl;
				struct Node* node1 = new Node;
				node1->param_decl = v[v.size()-1]->param_decl_tail->param_decl;
				node1->whoiam("param_decl");
				struct Node* node2 = new Node;
				node2->param_decl_tail = v[v.size()-1]->param_decl_tail->param_decl_tail;
				node2->whoiam("param_decl_tail");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
				
			}
			else if (v[v.size()-1]->_whoiam=="func_declarations")
			{
				// cout<<"here62"<<endl;
				if(v[v.size()-1]->func_declarations==NULL)
				{
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else
				{
					struct Node* node1 = new Node;
					node1->func_decl = v[v.size()-1]->func_declarations->func_decl;
					node1->whoiam("func_decl");
					struct Node* node2 = new Node;
					node2->func_declarations = v[v.size()-1]->func_declarations->func_declarations;
					node2->whoiam("func_declarations");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
					v.push_back(node2);
				}

			}
			else if (v[v.size()-1]->_whoiam=="func_decl")
			{
				// cout<<"here28"<<endl;
				struct Node* node1 = new Node;
				node1->any_type = v[v.size()-1]->func_decl->any_type;
				node1->whoiam("any_type");
				struct Node* node2 = new Node;
				node2->id = v[v.size()-1]->func_decl->id;
				node2->whoiam("id");
				struct Node* node3 = new Node;
				node3->param_decl_list = v[v.size()-1]->func_decl->param_decl_list;
				node3->whoiam("param_decl_list");
				struct Node* node4 = new Node;
				node4->func_body = v[v.size()-1]->func_decl->func_body;
				node4->whoiam("func_body");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				v.push_back(node3);
				v.push_back(node4);
				
			}
			else if (v[v.size()-1]->_whoiam=="func_body")
			{
				// cout<<"here27"<<endl;
				struct Node* node1 = new Node;
				node1->decl = v[v.size()-1]->func_body->decl;
				node1->whoiam("decl");
				struct Node* node2 = new Node;
				node2->stmt_list = v[v.size()-1]->func_body->stmt_list;
				node2->whoiam("stmt_list");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
			}
			else if (v[v.size()-1]->_whoiam=="stmt_list")
			{
				// cout<<"here26"<<endl;
				if(v[v.size()-1]->stmt_list==NULL)
				{
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else
				{
					struct Node* node1 = new Node;
					node1->stmt = v[v.size()-1]->stmt_list->stmt;
					node1->whoiam("stmt");
					struct Node* node2 = new Node;
					node2->stmt_list = v[v.size()-1]->stmt_list->stmt_list;
					node2->whoiam("stmt_list");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
					v.push_back(node2);
				}
				
				
			}
			else if (v[v.size()-1]->_whoiam=="stmt")
			{
				// cout<<"here25"<<endl;
				struct Node* node1 = new Node;
				if(v[v.size()-1]->stmt->base_stmt!=NULL)
				{
					node1->base_stmt = v[v.size()-1]->stmt->base_stmt;
					node1->whoiam("base_stmt");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}
				else if(v[v.size()-1]->stmt->if_stmt!=NULL)
				{
					node1->if_stmt = v[v.size()-1]->stmt->if_stmt;
					node1->whoiam("if_stmt");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}
				else if(v[v.size()-1]->stmt->for_stmt!=NULL)
				{
					node1->for_stmt = v[v.size()-1]->stmt->for_stmt;
					node1->whoiam("for_stmt");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}
			}
			else if (v[v.size()-1]->_whoiam=="base_stmt")
			{
				// cout<<"here24"<<endl;
				struct Node* node1 = new Node;
				if(v[v.size()-1]->base_stmt->assign_stmt!=NULL)
				{
					node1->assign_stmt = v[v.size()-1]->base_stmt->assign_stmt;
					node1->whoiam("assign_stmt");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}
				else if(v[v.size()-1]->base_stmt->read_stmt!=NULL)
				{
					node1->read_stmt = v[v.size()-1]->base_stmt->read_stmt;
					node1->whoiam("read_stmt");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}
				else if(v[v.size()-1]->base_stmt->write_stmt!=NULL)
				{
					node1->write_stmt = v[v.size()-1]->base_stmt->write_stmt;
					node1->whoiam("write_stmt");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}
				else if(v[v.size()-1]->base_stmt->return_stmt!=NULL)
				{
					node1->return_stmt = v[v.size()-1]->base_stmt->return_stmt;
					node1->whoiam("return_stmt");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}

			}
			else if (v[v.size()-1]->_whoiam=="assign_stmt")
			{
				// cout<<"here23"<<endl;
				struct Node* node1 = new Node;
				node1->assign_expr = v[v.size()-1]->assign_stmt->assign_expr;
				node1->whoiam("assign_expr");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				
			}
			else if (v[v.size()-1]->_whoiam=="assign_expr")
			{
				// cout<<"here22"<<endl;
				struct Node* node1 = new Node;
				node1->id = v[v.size()-1]->assign_expr->id;
				node1->whoiam("id");
				struct Node* node2 = new Node;
				node2->expr = v[v.size()-1]->assign_expr->expr;
				node2->whoiam("expr");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
			}
			else if (v[v.size()-1]->_whoiam=="read_stmt")
			{
				// cout<<"here21"<<endl;
				struct Node* node1 = new Node;
				node1->id_list = v[v.size()-1]->read_stmt->id_list;
				node1->whoiam("id_list");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				
			}
			else if (v[v.size()-1]->_whoiam=="write_stmt")
			{
				// cout<<"here20"<<endl;
				struct Node* node1 = new Node;
				node1->id_list = v[v.size()-1]->write_stmt->id_list;
				node1->whoiam("id_list");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				
			}
			else if (v[v.size()-1]->_whoiam=="return_stmt")
			{
				// cout<<"here19"<<endl;
				struct Node* node1 = new Node;
				node1->expr = v[v.size()-1]->return_stmt->expr;
				node1->whoiam("expr");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				
			}
			else if (v[v.size()-1]->_whoiam=="expr")
			{
				// cout<<"here18"<<endl;
				struct Node* node1 = new Node;
				node1->expr_prefix = v[v.size()-1]->expr->expr_prefix;
				node1->whoiam("expr_prefix");
				struct Node* node2 = new Node;
				node2->factor = v[v.size()-1]->expr->factor;
				node2->whoiam("factor");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
			}
			else if (v[v.size()-1]->_whoiam=="expr_prefix")
			{
				// cout<<"here17"<<endl;
				if(v[v.size()-1]->expr_prefix==NULL)
				{
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else
				{
					struct Node* node1 = new Node;
					node1->expr_prefix = v[v.size()-1]->expr_prefix->expr_prefix;
					node1->whoiam("expr_prefix");
					struct Node* node2 = new Node;
					node2->factor = v[v.size()-1]->expr_prefix->factor;
					node2->whoiam("factor");
					struct Node* node3 = new Node;
					node3->addop = v[v.size()-1]->expr_prefix->addop;
					node3->whoiam("addop");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
					v.push_back(node2);
					v.push_back(node3);
				}
				
			}
			else if (v[v.size()-1]->_whoiam=="factor")
			{
				// cout<<"here16"<<endl;
				struct Node* node1 = new Node;
				node1->factor_prefix = v[v.size()-1]->factor->factor_prefix;
				node1->whoiam("factor_prefix");
				struct Node* node2 = new Node;
				node2->postfix_expr = v[v.size()-1]->factor->postfix_expr;
				node2->whoiam("postfix_expr");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
			}
			else if (v[v.size()-1]->_whoiam=="factor_prefix")
			{
				// cout<<"here15"<<endl;
				if(v[v.size()-1]->factor_prefix==NULL)
				{
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else
				{
					struct Node* node1 = new Node;
					node1->factor_prefix = v[v.size()-1]->factor_prefix->factor_prefix;
					node1->whoiam("factor_prefix");
					struct Node* node2 = new Node;
					node2->postfix_expr = v[v.size()-1]->factor_prefix->postfix_expr;
					node2->whoiam("postfix_expr");
					struct Node* node3 = new Node;
					node3->mulop = v[v.size()-1]->factor_prefix->mulop;
					node3->whoiam("mulop");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
					v.push_back(node2);
					v.push_back(node3);
				}
				
				
			}
			else if (v[v.size()-1]->_whoiam=="postfix_expr")
			{
				// cout<<"here14"<<endl;
				struct Node* node1 = new Node;
				if(v[v.size()-1]->postfix_expr->primary!=NULL)
				{
					node1->primary = v[v.size()-1]->postfix_expr->primary;
					node1->whoiam("primary");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}
				else if(v[v.size()-1]->postfix_expr->call_expr!=NULL)
				{
					node1->call_expr = v[v.size()-1]->postfix_expr->call_expr;
					node1->whoiam("call_expr");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}
				
			}
			else if (v[v.size()-1]->_whoiam=="call_expr")
			{
				// cout<<"here13"<<endl;
				struct Node* node1 = new Node;
				node1->id = v[v.size()-1]->call_expr->id;
				node1->whoiam("id");
				struct Node* node2 = new Node;
				node2->expr_list = v[v.size()-1]->call_expr->expr_list;
				node2->whoiam("expr_list");
				
				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
			
			}
			else if (v[v.size()-1]->_whoiam=="expr_list")
			{
				// cout<<"here12"<<endl;
				struct Node* node1 = new Node;
				node1->expr = v[v.size()-1]->expr_list->expr;
				node1->whoiam("expr");
				struct Node* node2 = new Node;
				node2->expr_list_tail = v[v.size()-1]->expr_list->expr_list_tail;
				node2->whoiam("expr_list_tail");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
			}
			else if (v[v.size()-1]->_whoiam=="expr_list_tail")
			{
				// cout<<"here11"<<endl;
				struct Node* node1 = new Node;
				node1->expr = v[v.size()-1]->expr_list_tail->expr;
				node1->whoiam("expr");
				struct Node* node2 = new Node;
				node2->expr_list_tail = v[v.size()-1]->expr_list_tail->expr_list_tail;
				node2->whoiam("expr_list_tail");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				
			}
			else if (v[v.size()-1]->_whoiam=="primary")
			{
				// cout<<"here10"<<endl;
				struct Node* node1 = new Node;
				if(v[v.size()-1]->primary->expr!=NULL)
				{
					node1->expr = v[v.size()-1]->primary->expr;
					node1->whoiam("expr");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}
				else if(v[v.size()-1]->primary->id!=NULL)
				{
					node1->id = v[v.size()-1]->primary->id;
					node1->whoiam("id");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}
				else if(v[v.size()-1]->primary->_type=="INTLITERAL")
				{
					// generate IR
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else if(v[v.size()-1]->primary->_type=="FLOATLITERAL")
				{
					// generate IR
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
			}
			else if (v[v.size()-1]->_whoiam=="addop")
			{
				// cout<<"here9"<<endl;
				struct Node* node1 = new Node;
				if(v[v.size()-1]->addop->_type=="PLUS")
				{
					// generate IR
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else if(v[v.size()-1]->addop->_type=="MINUS")
				{
					// generate IR
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
			
			}
			else if (v[v.size()-1]->_whoiam=="mulop")
			{
				// cout<<"here8"<<endl;
				struct Node* node1 = new Node;
				if(v[v.size()-1]->mulop->_type=="MUL")
				{
					// generate IR
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else if(v[v.size()-1]->mulop->_type=="DIV")
				{
					// generate IR
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				
			}
			else if (v[v.size()-1]->_whoiam=="if_stmt")
			{
				// cout<<"here7"<<endl;
				struct Node* node1 = new Node;
				node1->cond = v[v.size()-1]->if_stmt->cond;
				node1->whoiam("cond");
				struct Node* node2 = new Node;
				node2->decl = v[v.size()-1]->if_stmt->decl;
				node2->whoiam("decl");
				struct Node* node3 = new Node;
				node3->stmt_list = v[v.size()-1]->if_stmt->stmt_list;
				node3->whoiam("stmt_list");
				struct Node* node4 = new Node;
				node4->else_part = v[v.size()-1]->if_stmt->else_part;
				node4->whoiam("else_part");
				
				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				v.push_back(node3);
				v.push_back(node4);
				
				
			}
			else if (v[v.size()-1]->_whoiam=="else_part")
			{
				// cout<<"here6"<<endl;
				struct Node* node1 = new Node;
				node1->decl = v[v.size()-1]->else_part->decl;
				node1->whoiam("decl");
				struct Node* node2 = new Node;
				node2->stmt_list = v[v.size()-1]->else_part->stmt_list;
				node2->whoiam("stmt_list");
				
				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
	
			}
			else if (v[v.size()-1]->_whoiam=="cond")
			{
				// cout<<"here5"<<endl;
				struct Node* node1 = new Node;
				node1->expr = v[v.size()-1]->cond->expr;
				node1->whoiam("expr");
				struct Node* node2 = new Node;
				node2->compop = v[v.size()-1]->cond->compop;
				node2->whoiam("decl");
				struct Node* node3 = new Node;
				node3->expr = v[v.size()-1]->cond->expr;
				node3->whoiam("expr");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				v.push_back(node3);
				
				
			}
			else if (v[v.size()-1]->_whoiam=="compop")
			{
				// cout<<"here4"<<endl;
				struct Node* node1 = new Node;
				if(v[v.size()-1]->compop->_type=="LESSTHAN")
				{
					// generate IR
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else if(v[v.size()-1]->compop->_type=="GREATERTHAN")
				{
					// generate IR
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else if(v[v.size()-1]->compop->_type=="EQUALS")
				{
					// generate IR
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else if(v[v.size()-1]->compop->_type=="NEQUALS")
				{
					// generate IR
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else if(v[v.size()-1]->compop->_type=="LESSOREQUAL")
				{
					// generate IR
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else if(v[v.size()-1]->compop->_type=="GREATEROREQUAL")
				{
					// generate IR
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				
			}
			else if (v[v.size()-1]->_whoiam=="init_stmt")
			{
				// cout<<"here3"<<endl;
				if(v[v.size()-1]->init_stmt==NULL)
				{
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else
				{
					struct Node* node1 = new Node;
					node1->assign_expr = v[v.size()-1]->init_stmt->assign_expr;
					node1->whoiam("assign_expr");
					
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}

			}
			else if (v[v.size()-1]->_whoiam=="incr_stmt")
			{
				// cout<<"here2"<<endl;
				if(v[v.size()-1]->incr_stmt==NULL)
				{
					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
				}
				else
				{
					struct Node* node1 = new Node;
					node1->assign_expr = v[v.size()-1]->incr_stmt->assign_expr;
					node1->whoiam("assign_expr");

					// generate IR
					// cout<<v[v.size()-1]->_whoiam<<endl;
					out.push_back(v[v.size()-1]);
					v.pop_back();
					v.push_back(node1);
				}

			}
			else if (v[v.size()-1]->_whoiam=="for_stmt")
			{
				// cout<<"here1"<<endl;
				struct Node* node1 = new Node;
				node1->init_stmt = v[v.size()-1]->for_stmt->init_stmt;
				node1->whoiam("init_stmt");
				struct Node* node2 = new Node;
				node2->cond = v[v.size()-1]->for_stmt->cond;
				node2->whoiam("cond");
				struct Node* node3 = new Node;
				node3->incr_stmt = v[v.size()-1]->for_stmt->incr_stmt;
				node3->whoiam("incr_stmt");
				struct Node* node4 = new Node;
				node4->decl = v[v.size()-1]->for_stmt->decl;
				node4->whoiam("decl");
				struct Node* node5 = new Node;
				node5->stmt_list = v[v.size()-1]->for_stmt->stmt_list;
				node5->whoiam("stmt_list");

				// generate IR
				// cout<<v[v.size()-1]->_whoiam<<endl;
				out.push_back(v[v.size()-1]);
				v.pop_back();
				v.push_back(node1);
				v.push_back(node2);
				v.push_back(node3);
				v.push_back(node4);
				v.push_back(node5);
				
			}

		}
		// cout<<"Correct!"<<endl;
		// cout<<"****************"<<endl;
		for(int i=out.size()-1;i>0;i--) //postorder traversal
		{
			if(out[i]->_whoiam=="id")
			{
				cout<<out[i]->id->_identifier<<endl;
			}
			else if (out[i]->_whoiam=="str")
			{
				cout<<out[i]->str->_stringliteral<<endl;
			}
			else if (out[i]->_whoiam=="var_type")
			{
				if(out[i]->var_type->_type=="FLOAT")
				{
					cout<<out[i]->var_type->_type_float<<endl;
					
				}
				else
				{
					cout<<out[i]->var_type->_type_int<<endl;
				}
			}
			else if (out[i]->_whoiam=="any_type")
			{
				if(out[i]->any_type->var_type==NULL)
				{
					cout<<out[i]->any_type->_void<<endl;
				}
				else
				{
					cout<<out[i]->var_type->_type_int<<endl;
				}
			}
			else if (out[i]->_whoiam=="primary")
			{
				cout<<out[i]->primary->_type<<endl;
			}
			else if (out[i]->_whoiam=="addop")
			{
				cout<<out[i]->addop->_type<<endl;
			}
			else if (out[i]->_whoiam=="mulop")
			{
				cout<<out[i]->mulop->_type<<endl;
			}
			else if (out[i]->_whoiam=="compop")
			{
				cout<<out[i]->compop->_type<<endl;
			}
			else
			{
				cout<<out[i]->_whoiam<<endl;
			}
		}
	}
	
	// else{
	// 	// cout<<"Error"<<endl;
		
	// 	if (isDeclarationError()) {
	// 		freopen(argv[2], "w", stdout);
	// 		std::cout << "DECLARATION ERROR " << getWronglyDeclaredVariable() << endl;
	// 	}
	
	// }
	
	fclose(file);

	return 0;
}
