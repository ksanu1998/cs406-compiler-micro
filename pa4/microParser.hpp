/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _PROGRAM = 258,
     _BEGIN = 259,
     _END = 260,
     _FUNCTION = 261,
     _READ = 262,
     _WRITE = 263,
     _IF = 264,
     _ELSE = 265,
     _FI = 266,
     _FOR = 267,
     _ROF = 268,
     _RETURN = 269,
     _INT = 270,
     _VOID = 271,
     _STRING = 272,
     _FLOAT = 273,
     _IDENTIFIER = 274,
     _STRINGLITERAL = 275,
     _INTLITERAL = 276,
     _FLOATLITERAL = 277,
     _COMMENT = 278,
     _ASSIGNMENT = 279,
     _PLUS = 280,
     _MINUS = 281,
     _MUL = 282,
     _DIV = 283,
     _EQUALS = 284,
     _NEQUALS = 285,
     _LESSTHAN = 286,
     _GREATERTHAN = 287,
     _LEFTPARANTHESIS = 288,
     _RIGHTPARANTHESIS = 289,
     _SEMICOLON = 290,
     _COMMA = 291,
     _LESSOREQUAL = 292,
     _GREATEROREQUAL = 293,
     _WHITESPACE = 294,
     _EOF = 295
   };
#endif
/* Tokens.  */
#define _PROGRAM 258
#define _BEGIN 259
#define _END 260
#define _FUNCTION 261
#define _READ 262
#define _WRITE 263
#define _IF 264
#define _ELSE 265
#define _FI 266
#define _FOR 267
#define _ROF 268
#define _RETURN 269
#define _INT 270
#define _VOID 271
#define _STRING 272
#define _FLOAT 273
#define _IDENTIFIER 274
#define _STRINGLITERAL 275
#define _INTLITERAL 276
#define _FLOATLITERAL 277
#define _COMMENT 278
#define _ASSIGNMENT 279
#define _PLUS 280
#define _MINUS 281
#define _MUL 282
#define _DIV 283
#define _EQUALS 284
#define _NEQUALS 285
#define _LESSTHAN 286
#define _GREATERTHAN 287
#define _LEFTPARANTHESIS 288
#define _RIGHTPARANTHESIS 289
#define _SEMICOLON 290
#define _COMMA 291
#define _LESSOREQUAL 292
#define _GREATEROREQUAL 293
#define _WHITESPACE 294
#define _EOF 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "microParser.yy"
{
	
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
/* Line 1529 of yacc.c.  */
#line 186 "microParser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

