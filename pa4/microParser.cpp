/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "microParser.yy"


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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 250 "microParser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 263 "microParser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    11,    14,    17,    20,    21,    27,
      29,    33,    35,    37,    39,    41,    44,    48,    49,    52,
      53,    56,    60,    61,    64,    65,    75,    78,    81,    82,
      84,    86,    88,    90,    92,    94,    96,    99,   103,   109,
     115,   119,   122,   126,   127,   130,   134,   135,   137,   139,
     144,   147,   148,   152,   153,   157,   159,   161,   163,   165,
     167,   169,   171,   180,   184,   185,   189,   191,   193,   195,
     197,   199,   201,   203,   204,   206,   207
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,     3,    43,     4,    44,     5,    -1,    19,
      -1,    45,    56,    -1,    46,    45,    -1,    48,    45,    -1,
      -1,    17,    43,    24,    47,    35,    -1,    20,    -1,    49,
      51,    35,    -1,    18,    -1,    15,    -1,    49,    -1,    16,
      -1,    43,    52,    -1,    36,    43,    52,    -1,    -1,    54,
      55,    -1,    -1,    49,    43,    -1,    36,    54,    55,    -1,
      -1,    57,    56,    -1,    -1,     6,    50,    43,    33,    53,
      34,     4,    58,     5,    -1,    45,    59,    -1,    60,    59,
      -1,    -1,    61,    -1,    78,    -1,    84,    -1,    62,    -1,
      64,    -1,    65,    -1,    66,    -1,    63,    35,    -1,    43,
      24,    67,    -1,     7,    33,    51,    34,    35,    -1,     8,
      33,    51,    34,    35,    -1,    14,    67,    35,    -1,    68,
      69,    -1,    68,    69,    76,    -1,    -1,    70,    71,    -1,
      70,    71,    77,    -1,    -1,    75,    -1,    72,    -1,    43,
      33,    73,    34,    -1,    67,    74,    -1,    -1,    36,    67,
      74,    -1,    -1,    33,    67,    34,    -1,    43,    -1,    21,
      -1,    22,    -1,    25,    -1,    26,    -1,    27,    -1,    28,
      -1,     9,    33,    80,    34,    45,    59,    79,    11,    -1,
      10,    45,    59,    -1,    -1,    67,    81,    67,    -1,    31,
      -1,    32,    -1,    29,    -1,    30,    -1,    37,    -1,    38,
      -1,    63,    -1,    -1,    63,    -1,    -1,    12,    33,    82,
      35,    80,    35,    83,    34,    45,    59,    13,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   139,   145,   151,   157,   164,   169,   175,
     183,   190,   197,   204,   210,   216,   222,   229,   234,   241,
     244,   250,   256,   262,   269,   272,   278,   286,   293,   296,
     302,   308,   315,   321,   326,   331,   339,   345,   351,   357,
     363,   371,   377,   383,   386,   392,   398,   401,   407,   413,
     419,   426,   429,   436,   439,   445,   451,   458,   465,   471,
     477,   483,   490,   496,   503,   506,   512,   517,   522,   528,
     534,   539,   545,   552,   555,   562,   565
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_PROGRAM", "_BEGIN", "_END",
  "_FUNCTION", "_READ", "_WRITE", "_IF", "_ELSE", "_FI", "_FOR", "_ROF",
  "_RETURN", "_INT", "_VOID", "_STRING", "_FLOAT", "_IDENTIFIER",
  "_STRINGLITERAL", "_INTLITERAL", "_FLOATLITERAL", "_COMMENT",
  "_ASSIGNMENT", "_PLUS", "_MINUS", "_MUL", "_DIV", "_EQUALS", "_NEQUALS",
  "_LESSTHAN", "_GREATERTHAN", "_LEFTPARANTHESIS", "_RIGHTPARANTHESIS",
  "_SEMICOLON", "_COMMA", "_LESSOREQUAL", "_GREATEROREQUAL", "_WHITESPACE",
  "_EOF", "$accept", "program", "id", "pgm_body", "decl", "string_decl",
  "str", "var_decl", "var_type", "any_type", "id_list", "id_tail",
  "param_decl_list", "param_decl", "param_decl_tail", "func_declarations",
  "func_decl", "func_body", "stmt_list", "stmt", "base_stmt",
  "assign_stmt", "assign_expr", "read_stmt", "write_stmt", "return_stmt",
  "expr", "expr_prefix", "factor", "factor_prefix", "postfix_expr",
  "call_expr", "expr_list", "expr_list_tail", "primary", "addop", "mulop",
  "if_stmt", "else_part", "cond", "compop", "init_stmt", "incr_stmt",
  "for_stmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    45,    45,    46,    47,
      48,    49,    49,    50,    50,    51,    52,    52,    53,    53,
      54,    55,    55,    56,    56,    57,    58,    59,    59,    60,
      60,    60,    61,    61,    61,    61,    62,    63,    64,    65,
      66,    67,    68,    68,    69,    70,    70,    71,    71,    72,
      73,    73,    74,    74,    75,    75,    75,    75,    76,    76,
      77,    77,    78,    79,    79,    80,    81,    81,    81,    81,
      81,    81,    82,    82,    83,    83,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     1,     2,     2,     2,     0,     5,     1,
       3,     1,     1,     1,     1,     2,     3,     0,     2,     0,
       2,     3,     0,     2,     0,     9,     2,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     5,     5,
       3,     2,     3,     0,     2,     3,     0,     1,     1,     4,
       2,     0,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     8,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     0,    11
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     7,    12,     0,    11,
       0,    24,     7,     7,     0,     0,     2,     0,     4,    24,
       5,     6,    17,     0,     0,    14,    13,     0,    23,     0,
      15,    10,     9,     0,     0,    17,     8,    19,    16,     0,
       0,    22,    20,     0,     0,    18,     7,    22,    28,     0,
      21,     0,     0,     0,     0,    43,     0,    26,    28,    29,
      32,     0,    33,    34,    35,    30,    31,    25,     0,     0,
      43,    73,     0,    46,    43,    27,    36,     0,     0,     0,
       0,    72,     0,    40,    41,     0,    37,     0,     0,    68,
      69,    66,    67,    70,    71,    43,     7,    43,    58,    59,
      42,    56,    57,    43,    55,    44,    48,    47,    38,    39,
      65,    28,     0,     0,    43,    60,    61,    45,    64,    75,
      54,    53,     0,     7,     0,    74,     0,    43,    50,    49,
      28,    62,     7,    53,    63,    28,    52,     0,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    56,    10,    11,    12,    33,    13,    14,    27,
      23,    30,    40,    41,    45,    18,    19,    49,    57,    58,
      59,    60,    61,    62,    63,    64,    79,    73,    84,    85,
     105,   106,   122,   128,   107,   100,   117,    65,   124,    80,
      95,    82,   126,    66
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int8 yypact[] =
{
       4,    10,    31,   -67,    33,   -67,    -1,   -67,    10,   -67,
      34,    37,    -1,    -1,    10,    21,   -67,    20,   -67,    37,
     -67,   -67,    22,    24,    40,   -67,   -67,    10,   -67,    10,
     -67,   -67,   -67,    26,    29,    22,   -67,    -7,   -67,    10,
      30,    32,   -67,    53,    -7,   -67,    -1,    32,    13,    60,
     -67,    38,    39,    41,    44,   -67,    42,   -67,    13,   -67,
     -67,    43,   -67,   -67,   -67,   -67,   -67,   -67,    10,    10,
     -67,    10,    46,   -67,   -67,   -67,   -67,    45,    48,    17,
      49,   -67,    50,   -67,    16,    -9,   -67,    52,    54,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,    -1,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,    55,    23,   -67,   -67,   -67,   -67,
     -67,    13,    56,    58,    59,   -67,   -67,   -67,    57,    10,
     -67,    61,    62,    -1,    79,   -67,    64,   -67,   -67,   -67,
      13,   -67,    -1,    61,   -67,    13,   -67,    81,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,     1,   -67,   -12,   -67,   -67,   -67,   -11,   -67,
     -50,    65,   -67,    51,    63,    80,   -67,   -67,   -55,   -67,
     -67,   -67,   -66,   -67,   -67,   -67,   -51,   -67,   -67,   -67,
     -67,   -67,   -67,   -60,   -67,   -67,   -67,   -67,   -67,     5,
     -67,   -67,   -67,   -67
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -52
static const yytype_int16 yytable[] =
{
      20,    21,     4,    75,    72,    81,    26,     1,     7,    15,
       3,     9,   101,   102,     7,    22,     8,     9,    77,    78,
      51,    52,    53,    86,   103,    54,    39,    55,    34,     3,
      35,     5,     3,    39,    48,     7,    25,     6,     9,    16,
      42,    98,    99,    17,   110,    24,    89,    90,    91,    92,
     115,   116,   113,   125,    93,    94,   118,    46,    29,    31,
      32,    36,    37,   121,    43,    67,    74,   123,    44,    22,
      22,    68,    69,   136,    70,   134,   133,    71,    76,    87,
     137,    83,    88,    96,   111,    97,   104,   108,   114,   109,
     131,   119,   120,   -51,   138,    47,   129,   127,   132,    28,
      38,     0,   112,     0,     0,     0,     0,     0,     0,     0,
      50,   130,     0,     0,     0,     0,     0,     0,     0,     0,
     135
};

static const yytype_int16 yycheck[] =
{
      12,    13,     1,    58,    55,    71,    17,     3,    15,     8,
      19,    18,    21,    22,    15,    14,    17,    18,    68,    69,
       7,     8,     9,    74,    33,    12,    37,    14,    27,    19,
      29,     0,    19,    44,    46,    15,    16,     4,    18,     5,
      39,    25,    26,     6,    95,    24,    29,    30,    31,    32,
      27,    28,   103,   119,    37,    38,   111,     4,    36,    35,
      20,    35,    33,   114,    34,     5,    24,    10,    36,    68,
      69,    33,    33,   133,    33,   130,   127,    33,    35,    34,
     135,    35,    34,    34,    96,    35,    85,    35,    33,    35,
      11,    35,    34,    34,    13,    44,    34,    36,    34,    19,
      35,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     132
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    42,    19,    43,     0,     4,    15,    17,    18,
      44,    45,    46,    48,    49,    43,     5,     6,    56,    57,
      45,    45,    43,    51,    24,    16,    49,    50,    56,    36,
      52,    35,    20,    47,    43,    43,    35,    33,    52,    49,
      53,    54,    43,    34,    36,    55,     4,    54,    45,    58,
      55,     7,     8,     9,    12,    14,    43,    59,    60,    61,
      62,    63,    64,    65,    66,    78,    84,     5,    33,    33,
      33,    33,    67,    68,    24,    59,    35,    51,    51,    67,
      80,    63,    82,    35,    69,    70,    67,    34,    34,    29,
      30,    31,    32,    37,    38,    81,    34,    35,    25,    26,
      76,    21,    22,    33,    43,    71,    72,    75,    35,    35,
      67,    45,    80,    67,    33,    27,    28,    77,    59,    35,
      34,    67,    73,    10,    79,    63,    83,    36,    74,    34,
      45,    11,    34,    67,    59,    45,    74,    59,    13
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 133 "microParser.yy"
    { 
	(yyval.program) = new ProgramRootNode();
	(yyval.program)->add((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].pgm_body));
	(yyval.program)->whoiam("program");
	root = (yyval.program);
;}
    break;

  case 3:
#line 140 "microParser.yy"
    {
	(yyval.id) = new IdNode();
	(yyval.id)->add((yyvsp[(1) - (1)].s));
	(yyval.id)->whoiam("id");
;}
    break;

  case 4:
#line 146 "microParser.yy"
    {
	(yyval.pgm_body) = new ProgramBodyNode();
	(yyval.pgm_body)->add((yyvsp[(1) - (2)].decl),(yyvsp[(2) - (2)].func_declarations));
	(yyval.pgm_body)->whoiam("pgm_body");
;}
    break;

  case 5:
#line 152 "microParser.yy"
    {
	(yyval.decl) = new DeclarationNode();
	(yyval.decl)->add_str((yyvsp[(1) - (2)].string_decl), (yyvsp[(2) - (2)].decl));
	(yyval.decl)->whoiam("decl");
;}
    break;

  case 6:
#line 158 "microParser.yy"
    {
	(yyval.decl) = new DeclarationNode();
	(yyval.decl)->add_var((yyvsp[(1) - (2)].var_decl),(yyvsp[(2) - (2)].decl));
	(yyval.decl)->whoiam("decl");
;}
    break;

  case 7:
#line 164 "microParser.yy"
    {
	(yyval.decl) = NULL;
;}
    break;

  case 8:
#line 170 "microParser.yy"
    {
	(yyval.string_decl) = new StringDeclarationNode();
	(yyval.string_decl)->add((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].str));
	(yyval.string_decl)->whoiam("string_decl");
;}
    break;

  case 9:
#line 176 "microParser.yy"
    {
	(yyval.str) = new StringNode();
	(yyval.str)->add((yyvsp[(1) - (1)].s));
	(yyval.str)->whoiam("str");
;}
    break;

  case 10:
#line 184 "microParser.yy"
    {
	(yyval.var_decl) = new VariableDeclarationNode();
	(yyval.var_decl)->add((yyvsp[(1) - (3)].var_type), (yyvsp[(2) - (3)].id_list));
	(yyval.var_decl)->whoiam("var_decl");

;}
    break;

  case 11:
#line 191 "microParser.yy"
    {
	(yyval.var_type) = new VariableTypeNode();
	(yyval.var_type)->add_float((yyvsp[(1) - (1)].s));
	(yyval.var_type)->whoiam("var_type");
	(yyval.var_type)->add_type("FLOAT");
;}
    break;

  case 12:
#line 198 "microParser.yy"
    {
	(yyval.var_type) = new VariableTypeNode();
	(yyval.var_type)->add_int((yyvsp[(1) - (1)].s));
	(yyval.var_type)->whoiam("var_type");
	(yyval.var_type)->add_type("INT");
;}
    break;

  case 13:
#line 205 "microParser.yy"
    {
	(yyval.any_type) = new AnyTypeNode();
	(yyval.any_type)->add_var((yyvsp[(1) - (1)].var_type));
	(yyval.any_type)->whoiam("any_type");
;}
    break;

  case 14:
#line 211 "microParser.yy"
    {
	(yyval.any_type) = new AnyTypeNode();
	(yyval.any_type)->add_void((yyvsp[(1) - (1)].s));
	(yyval.any_type)->whoiam("any_type");
;}
    break;

  case 15:
#line 217 "microParser.yy"
    {
	(yyval.id_list) = new IdListNode(); 
	(yyval.id_list)->add((yyvsp[(1) - (2)].id), (yyvsp[(2) - (2)].id_tail));
	(yyval.id_list)->whoiam("id_list");
;}
    break;

  case 16:
#line 223 "microParser.yy"
    {	
	(yyval.id_tail) = new IdTailNode(); 
	(yyval.id_tail)->add((yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].id_tail));
	(yyval.id_tail)->whoiam("id_tail");
;}
    break;

  case 17:
#line 229 "microParser.yy"
    {	
	(yyval.id_tail) = NULL;
;}
    break;

  case 18:
#line 235 "microParser.yy"
    {
	(yyval.param_decl_list) = new ParameterDeclarationListNode();
	(yyval.param_decl_list)->add((yyvsp[(1) - (2)].param_decl),(yyvsp[(2) - (2)].param_decl_tail)); 
	(yyval.param_decl_list)->whoiam("param_decl_list");
;}
    break;

  case 19:
#line 241 "microParser.yy"
    {
	(yyval.param_decl_list) = NULL;
;}
    break;

  case 20:
#line 245 "microParser.yy"
    {
	(yyval.param_decl) = new ParameterDeclarationNode(); 
	(yyval.param_decl)->add((yyvsp[(1) - (2)].var_type),(yyvsp[(2) - (2)].id));
	(yyval.param_decl)->whoiam("param_decl");
;}
    break;

  case 21:
#line 251 "microParser.yy"
    {
	(yyval.param_decl_tail) = new ParameterDeclarationTailNode(); 
	(yyval.param_decl_tail)->add((yyvsp[(2) - (3)].param_decl),(yyvsp[(3) - (3)].param_decl_tail));
	(yyval.param_decl_tail)->whoiam("param_decl_tail");
;}
    break;

  case 22:
#line 256 "microParser.yy"
    {
	(yyval.param_decl_tail) = NULL;
;}
    break;

  case 23:
#line 263 "microParser.yy"
    {
	(yyval.func_declarations) = new FunctionDeclarationsNode(); 
	(yyval.func_declarations)->add((yyvsp[(1) - (2)].func_decl),(yyvsp[(2) - (2)].func_declarations));
	(yyval.func_declarations)->whoiam("func_declarations");
;}
    break;

  case 24:
#line 269 "microParser.yy"
    {
	(yyval.func_declarations) = NULL;
;}
    break;

  case 25:
#line 273 "microParser.yy"
    {
	(yyval.func_decl) = new FunctionDeclarationNode(); 
	(yyval.func_decl)->add((yyvsp[(2) - (9)].any_type),(yyvsp[(3) - (9)].id),(yyvsp[(5) - (9)].param_decl_list),(yyvsp[(8) - (9)].func_body));
	(yyval.func_decl)->whoiam("func_decl");
;}
    break;

  case 26:
#line 279 "microParser.yy"
    {
	(yyval.func_body) = new FunctionBodyNode(); 
	(yyval.func_body)->add((yyvsp[(1) - (2)].decl),(yyvsp[(2) - (2)].stmt_list));
	(yyval.func_body)->whoiam("func_body");
;}
    break;

  case 27:
#line 287 "microParser.yy"
    {
	(yyval.stmt_list) = new StatementListNode();
	(yyval.stmt_list)->add((yyvsp[(1) - (2)].stmt), (yyvsp[(2) - (2)].stmt_list));
	(yyval.stmt_list)->whoiam("stmt_list");
;}
    break;

  case 28:
#line 293 "microParser.yy"
    {
	(yyval.stmt_list) = NULL;
;}
    break;

  case 29:
#line 297 "microParser.yy"
    {
	(yyval.stmt) = new StatementNode();
	(yyval.stmt)->add_base((yyvsp[(1) - (1)].base_stmt));
	(yyval.stmt)->whoiam("stmt");
;}
    break;

  case 30:
#line 303 "microParser.yy"
    {
	(yyval.stmt) = new StatementNode();
	(yyval.stmt)->add_if((yyvsp[(1) - (1)].if_stmt));
	(yyval.stmt)->whoiam("stmt");
;}
    break;

  case 31:
#line 309 "microParser.yy"
    {
	(yyval.stmt) = new StatementNode();
	(yyval.stmt)->add_for((yyvsp[(1) - (1)].for_stmt));
	(yyval.stmt)->whoiam("stmt");
;}
    break;

  case 32:
#line 316 "microParser.yy"
    {
	(yyval.base_stmt) = new BaseStatementNode();
	(yyval.base_stmt)->add_assign((yyvsp[(1) - (1)].assign_stmt));
	(yyval.base_stmt)->whoiam("base_stmt");

;}
    break;

  case 33:
#line 322 "microParser.yy"
    {
	(yyval.base_stmt) = new BaseStatementNode();
	(yyval.base_stmt)->add_read((yyvsp[(1) - (1)].read_stmt));
	(yyval.base_stmt)->whoiam("base_stmt");
;}
    break;

  case 34:
#line 327 "microParser.yy"
    {
	(yyval.base_stmt) = new BaseStatementNode();
	(yyval.base_stmt)->add_write((yyvsp[(1) - (1)].write_stmt));
	(yyval.base_stmt)->whoiam("base_stmt");
;}
    break;

  case 35:
#line 332 "microParser.yy"
    {
	(yyval.base_stmt) = new BaseStatementNode();
	(yyval.base_stmt)->add_return((yyvsp[(1) - (1)].return_stmt));
	(yyval.base_stmt)->whoiam("base_stmt");
;}
    break;

  case 36:
#line 340 "microParser.yy"
    {
	(yyval.assign_stmt) = new AssignmentStatementNode;
	(yyval.assign_stmt)->add((yyvsp[(1) - (2)].assign_expr));
	(yyval.assign_stmt)->whoiam("assign_stmt");
;}
    break;

  case 37:
#line 346 "microParser.yy"
    {
	(yyval.assign_expr) = new AssignmentExpressionNode;
	(yyval.assign_expr)->add((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].expr));
	(yyval.assign_expr)->whoiam("assign_expr");
;}
    break;

  case 38:
#line 352 "microParser.yy"
    {
	(yyval.read_stmt) = new ReadStatementNode;
	(yyval.read_stmt)->add((yyvsp[(3) - (5)].id_list));
	(yyval.read_stmt)->whoiam("read_stmt");
;}
    break;

  case 39:
#line 358 "microParser.yy"
    {
	(yyval.write_stmt) = new WriteStatementNode;
	(yyval.write_stmt)->add((yyvsp[(3) - (5)].id_list));
	(yyval.write_stmt)->whoiam("write_stmt");
;}
    break;

  case 40:
#line 364 "microParser.yy"
    {
	(yyval.return_stmt) = new ReturnStatementNode;
	(yyval.return_stmt)->add((yyvsp[(2) - (3)].expr));
	(yyval.return_stmt)->whoiam("return_stmt");
;}
    break;

  case 41:
#line 372 "microParser.yy"
    {
	(yyval.expr) = new ExpressionNode;
	(yyval.expr)->add((yyvsp[(1) - (2)].expr_prefix), (yyvsp[(2) - (2)].factor));
	(yyval.expr)->whoiam("expr");
;}
    break;

  case 42:
#line 378 "microParser.yy"
    {
	(yyval.expr_prefix) = new ExpressionPrefixNode;
	(yyval.expr_prefix)->add((yyvsp[(1) - (3)].expr_prefix), (yyvsp[(2) - (3)].factor), (yyvsp[(3) - (3)].addop));
	(yyval.expr_prefix)->whoiam("expr_prefix");
;}
    break;

  case 43:
#line 383 "microParser.yy"
    {
	(yyval.expr_prefix) = NULL; 
;}
    break;

  case 44:
#line 387 "microParser.yy"
    {
	(yyval.factor) = new FactorNode;
	(yyval.factor)->add((yyvsp[(1) - (2)].factor_prefix), (yyvsp[(2) - (2)].postfix_expr));
	(yyval.factor)->whoiam("factor");
;}
    break;

  case 45:
#line 393 "microParser.yy"
    {
	(yyval.factor_prefix) = new FactorPrefixNode;
	(yyval.factor_prefix)->add((yyvsp[(1) - (3)].factor_prefix), (yyvsp[(2) - (3)].postfix_expr), (yyvsp[(3) - (3)].mulop));
	(yyval.factor_prefix)->whoiam("factor_prefix");
;}
    break;

  case 46:
#line 398 "microParser.yy"
    {
	(yyval.factor_prefix) = NULL;
;}
    break;

  case 47:
#line 402 "microParser.yy"
    {
	(yyval.postfix_expr) = new PostFixExpressionNode;
	(yyval.postfix_expr)->add_pri((yyvsp[(1) - (1)].primary));
	(yyval.postfix_expr)->whoiam("postfix_expr");
;}
    break;

  case 48:
#line 408 "microParser.yy"
    {
	(yyval.postfix_expr) = new PostFixExpressionNode;
	(yyval.postfix_expr)->add_call((yyvsp[(1) - (1)].call_expr));
	(yyval.postfix_expr)->whoiam("postfix_expr");
;}
    break;

  case 49:
#line 414 "microParser.yy"
    {
	(yyval.call_expr) = new CallExpressionNode;
	(yyval.call_expr)->add((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].expr_list));
	(yyval.call_expr)->whoiam("call_expr");
;}
    break;

  case 50:
#line 420 "microParser.yy"
    {
	(yyval.expr_list) = new ExpressionListNode;
	(yyval.expr_list)->add((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr_list_tail));
	(yyval.expr_list)->whoiam("expr_list");
;}
    break;

  case 51:
#line 426 "microParser.yy"
    {
	(yyval.expr_list) = NULL;
;}
    break;

  case 52:
#line 430 "microParser.yy"
    {
	(yyval.expr_list_tail) = new ExpressionListTailNode;
	(yyval.expr_list_tail)->add((yyvsp[(2) - (3)].expr), (yyvsp[(3) - (3)].expr_list_tail));
	(yyval.expr_list_tail)->whoiam("expr_list_tail");
;}
    break;

  case 53:
#line 436 "microParser.yy"
    {
	(yyval.expr_list_tail) = NULL;
;}
    break;

  case 54:
#line 440 "microParser.yy"
    {
	(yyval.primary) = new PrimaryNode;
	(yyval.primary)->add_expr((yyvsp[(2) - (3)].expr));
	(yyval.primary)->whoiam("primary");
;}
    break;

  case 55:
#line 446 "microParser.yy"
    {
	(yyval.primary) = new PrimaryNode;
	(yyval.primary)->add_id((yyvsp[(1) - (1)].id));
	(yyval.primary)->whoiam("primary");
;}
    break;

  case 56:
#line 452 "microParser.yy"
    {
	(yyval.primary) = new PrimaryNode;
	(yyval.primary)->add_int((yyvsp[(1) - (1)].s));
	(yyval.primary)->whoiam("primary");
	(yyval.primary)->add_type("INTLITERAL");
;}
    break;

  case 57:
#line 459 "microParser.yy"
    {
	(yyval.primary) = new PrimaryNode;
	(yyval.primary)->add_float((yyvsp[(1) - (1)].s));
	(yyval.primary)->whoiam("primary");
	(yyval.primary)->add_type("FLOATLITERAL");
;}
    break;

  case 58:
#line 466 "microParser.yy"
    {
	(yyval.addop) = new AddOpNode;
	(yyval.addop)->add("PLUS");
	(yyval.addop)->whoiam("addop");
;}
    break;

  case 59:
#line 472 "microParser.yy"
    {
	(yyval.addop) = new AddOpNode;
	(yyval.addop)->add("MINUS");
	(yyval.addop)->whoiam("addop");
;}
    break;

  case 60:
#line 478 "microParser.yy"
    {
	(yyval.mulop) = new MulOpNode;
	(yyval.mulop)->add("MUL");
	(yyval.mulop)->whoiam("mulop");
;}
    break;

  case 61:
#line 484 "microParser.yy"
    {
	(yyval.mulop) = new MulOpNode;
	(yyval.mulop)->add("DIV");
	(yyval.mulop)->whoiam("mulop");
;}
    break;

  case 62:
#line 491 "microParser.yy"
    {
	(yyval.if_stmt) = new IfStatementNode;
	(yyval.if_stmt)->add((yyvsp[(3) - (8)].cond), (yyvsp[(5) - (8)].decl), (yyvsp[(6) - (8)].stmt_list), (yyvsp[(7) - (8)].else_part));
	(yyval.if_stmt)->whoiam("if_stmt");
;}
    break;

  case 63:
#line 497 "microParser.yy"
    {
	(yyval.else_part) = new ElsePartNode;
	(yyval.else_part)->add((yyvsp[(2) - (3)].decl), (yyvsp[(3) - (3)].stmt_list));
	(yyval.else_part)->whoiam("else_part");
;}
    break;

  case 64:
#line 503 "microParser.yy"
    {
	(yyval.else_part) = NULL;
;}
    break;

  case 65:
#line 507 "microParser.yy"
    {
	(yyval.cond) = new ConditionNode;
	(yyval.cond)->add((yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].compop), (yyvsp[(3) - (3)].expr));
	(yyval.cond)->whoiam("cond");
;}
    break;

  case 66:
#line 513 "microParser.yy"
    {
	(yyval.compop) = new ComparisonOperationNode;
	(yyval.compop)->add("LESSTHAN");
	(yyval.compop)->whoiam("compop");
;}
    break;

  case 67:
#line 518 "microParser.yy"
    {
	(yyval.compop) = new ComparisonOperationNode;
	(yyval.compop)->add("GREATERTHAN");
	(yyval.compop)->whoiam("compop");
;}
    break;

  case 68:
#line 523 "microParser.yy"
    {
	(yyval.compop) = new ComparisonOperationNode;
	(yyval.compop)->add("EQUALS");
	(yyval.compop)->whoiam("compop");
;}
    break;

  case 69:
#line 529 "microParser.yy"
    {
	(yyval.compop) = new ComparisonOperationNode;
	(yyval.compop)->add("NEQUALS");
	(yyval.compop)->whoiam("compop");
;}
    break;

  case 70:
#line 535 "microParser.yy"
    {
	(yyval.compop) = new ComparisonOperationNode;
	(yyval.compop)->add("LESSOREQUAL");
	(yyval.compop)->whoiam("compop");
;}
    break;

  case 71:
#line 540 "microParser.yy"
    {
	(yyval.compop) = new ComparisonOperationNode;
	(yyval.compop)->add("GREATEROREQUAL");
	(yyval.compop)->whoiam("compop");
;}
    break;

  case 72:
#line 546 "microParser.yy"
    {
	(yyval.init_stmt) = new InitialStatementNode;
	(yyval.init_stmt)->add((yyvsp[(1) - (1)].assign_expr));
	(yyval.init_stmt)->whoiam("init_stmt");
;}
    break;

  case 73:
#line 552 "microParser.yy"
    {
	(yyval.init_stmt) = NULL;
;}
    break;

  case 74:
#line 556 "microParser.yy"
    {
	(yyval.incr_stmt) = new IncrementalStatementNode;
	(yyval.incr_stmt)->add((yyvsp[(1) - (1)].assign_expr));
	(yyval.incr_stmt)->whoiam("incr_stmt");
;}
    break;

  case 75:
#line 562 "microParser.yy"
    {
	(yyval.incr_stmt) = NULL;
;}
    break;

  case 76:
#line 566 "microParser.yy"
    {
	(yyval.for_stmt) = new ForStatementNode;
	(yyval.for_stmt)->add((yyvsp[(3) - (11)].init_stmt),(yyvsp[(5) - (11)].cond),(yyvsp[(7) - (11)].incr_stmt),(yyvsp[(9) - (11)].decl),(yyvsp[(10) - (11)].stmt_list));
	(yyval.for_stmt)->whoiam("for_stmt");
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2240 "microParser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 572 "microParser.yy"

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

