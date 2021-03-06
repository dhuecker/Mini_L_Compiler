/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mini_l.y" /* yacc.c:339  */

#include <map>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#define YY_NO_UNPUT
void yyerror(const char* x);
std::string newLabel();
std::string newTemp();
char nothing[1] = "";
extern int LinCol;
extern int LineRow;
extern char* pName;
extern char* yytext;

std::vector<std::string> mapWords = {
"IF", "ENDIF", "ELSE", "THEN", "TRUE", "FALSE", "RETURN", "AND", "OR", "NOT",
"READ", "WRITE", "BEGIN_LOOP", "END_LOOP", "CONTINUE", "IN", "WHILE", "DO", "FOR",
"OF", "BEGIN_BODY", "END_BODY", "INTEGER", "ARRAY", "FUNCTION", "BEGIN_PARMS", "END_PARMS",
"BEGIN_LOCALS", "END_LOCALS", "if", "endif", "else", "then", "true", "false", "return", "and", "or", "not", "read", "write", "beginloop", "endloop", "continue", "in", "while", "do", "for", "of", "beginbody", "endbody", "integer", "array", "function", "beginparms", "endparams", "beginlocals", "endlocals"  };

std::map<std::string, int> functions;
std::map<std::string, int> variables;

#line 92 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    RETURN = 258,
    TRUE = 259,
    FALSE = 260,
    CONTINUE = 261,
    WRITE = 262,
    READ = 263,
    SEMICOLON = 264,
    COLON = 265,
    COMMA = 266,
    R_PAREN = 267,
    L_PAREN = 268,
    R_SQUARE_BRACKET = 269,
    L_SQUARE_BRACKET = 270,
    BEGIN_LOOP = 271,
    END_LOOP = 272,
    IF = 273,
    ENDIF = 274,
    ELSE = 275,
    THEN = 276,
    DO = 277,
    WHILE = 278,
    FOR = 279,
    IN = 280,
    BEGIN_PARAMS = 281,
    BEGIN_LOCALS = 282,
    END_LOCALS = 283,
    END_PARAMS = 284,
    BEGIN_BODY = 285,
    END_BODY = 286,
    ARRAY = 287,
    OF = 288,
    INTEGER = 289,
    FUNCTION = 290,
    NUMBER = 291,
    IDENT = 292,
    NOT = 293,
    ASSIGN = 294,
    AND = 295,
    OR = 296,
    NEQ = 297,
    EQ = 298,
    LTE = 299,
    GTE = 300,
    GT = 301,
    LT = 302,
    MOD = 303,
    MULT = 304,
    DIV = 305,
    ADD = 306,
    SUB = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "mini_l.y" /* yacc.c:355  */

  char* ident_val;
  int number_val;
  struct E {
	char* place; 
	char* code;
	bool array;
 }expr;

 struct S {

	char* code;
 }stat;


#line 201 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 218 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   103,   122,   156,   163,   169,   208,   254,
     263,   269,   273,   281,   289,   292,   306,   320,   405,   435,
     475,   504,   543,   547,   553,   567,   582,   588,   600,   617,
     634,   640,   649,   657,   663,   681,   699,   716,   722,   736,
     741,   753,   757,   764,   794,   819,   839,   845,   865,   873,
     876,   893,   896,   900,   904,   909,   914,   918,   922,   926,
     930,   937
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RETURN", "TRUE", "FALSE", "CONTINUE",
  "WRITE", "READ", "SEMICOLON", "COLON", "COMMA", "R_PAREN", "L_PAREN",
  "R_SQUARE_BRACKET", "L_SQUARE_BRACKET", "BEGIN_LOOP", "END_LOOP", "IF",
  "ENDIF", "ELSE", "THEN", "DO", "WHILE", "FOR", "IN", "BEGIN_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "END_PARAMS", "BEGIN_BODY", "END_BODY",
  "ARRAY", "OF", "INTEGER", "FUNCTION", "NUMBER", "IDENT", "NOT", "ASSIGN",
  "AND", "OR", "NEQ", "EQ", "LTE", "GTE", "GT", "LT", "MOD", "MULT", "DIV",
  "ADD", "SUB", "$accept", "Program", "Function", "Declarations",
  "Declaration", "Identifiers", "Statements", "Statement", "ElseStatement",
  "Vars", "Var", "Expression", "Expressions", "MultiplicativeExpression",
  "Term", "BoolExpr", "RelationAndExpr", "RelationExpr", "RelationExpr0",
  "Comp", "Ident", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -34

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-34)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,   -33,    15,   -24,   -34,     9,   -34,   -34,    -2,   -33,
      10,    18,    37,    45,    26,   -33,     2,   -33,   -33,   -34,
      44,   -34,   -34,    35,    28,    39,    58,   111,    47,    -8,
     -34,   -33,   -33,    63,    62,    63,   -33,    60,    87,    59,
      89,    68,    -8,   -34,    -4,   -34,   -34,    -6,   -28,    27,
     -34,    94,   -34,   -34,   -34,    63,    70,    42,    91,    72,
      76,   -34,   111,   104,   114,   -34,   111,    -8,    -8,   -34,
     119,    -8,   -34,   -34,    -8,    -8,    -8,    -8,    -8,    -8,
     -33,    81,   120,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
      -8,   111,    63,    63,   121,   111,   111,   -34,   -34,   122,
     -34,   125,   -34,   -34,   -34,   -34,   -34,   128,   129,   -34,
     -34,   -34,   123,   -34,   -34,   117,   127,   130,   -34,   -34,
      -8,   -34,   111,   126,    63,   -34,   -34,   -34,   -34,   -34,
     -34
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     3,    61,     0,     1,     2,     0,     6,
       0,     0,     0,    10,     0,     6,     0,     0,     6,     5,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,    41,     0,    44,    13,    30,    37,    26,
      15,    25,    16,    53,    52,     0,     0,     0,     0,    46,
      48,    49,     0,     0,     0,     4,    11,     0,     0,     7,
       0,     0,    42,    43,     0,     0,     0,     0,     0,    33,
       0,     0,     0,    50,    59,    60,    56,    55,    57,    58,
       0,     0,     0,     0,     0,     0,     0,    12,    21,     0,
      39,     0,    29,    28,    34,    36,    35,    32,     0,    24,
      51,    54,    23,    45,    47,     0,     0,     0,    27,    40,
      33,    38,     0,     0,     0,    19,    17,    31,    22,    20,
      18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -34,   139,   -34,    -5,   -34,   132,   -14,   -34,   -34,   -31,
     -25,   -17,    30,    33,   -34,   -32,    53,   -34,    95,   -34,
      -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    10,    11,    12,    37,    38,   123,    50,
      45,    57,   108,    47,    48,    58,    59,    60,    61,    90,
      49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       5,    52,    39,    63,     4,    42,    51,    51,    13,    71,
      19,     1,    46,    23,    13,     6,    13,    13,     8,    73,
      76,    77,    78,    82,     9,    70,    40,    15,    43,     4,
      40,    40,    72,     4,    20,    64,    21,    39,    81,    14,
      79,    39,    68,    40,    44,    74,    75,    16,    94,   109,
      98,    99,    97,    18,   101,    51,    17,   102,   103,    24,
     113,    40,   107,    25,    26,    40,    39,    53,    54,    27,
      39,    39,    28,   111,    53,    54,    55,   112,    62,    40,
      41,   116,   117,    55,    84,    85,    86,    87,    88,    89,
      40,    65,   130,   100,    40,    40,    66,    39,    67,    43,
       4,    56,    69,   107,    68,    80,    43,     4,   128,   104,
     105,   106,    91,    92,    29,    44,    93,    30,    31,    32,
      95,    40,    44,    84,    85,    86,    87,    88,    89,    33,
      96,   100,   110,    34,    35,    36,   118,   119,   115,   120,
     124,   121,     7,   122,   125,   129,   114,   126,     4,    22,
     127,    83
};

static const yytype_uint8 yycheck[] =
{
       1,    32,    27,    35,    37,    13,    31,    32,     9,    13,
      15,    35,    29,    18,    15,     0,    17,    18,     9,    44,
      48,    49,    50,    55,    26,    42,    27,     9,    36,    37,
      31,    32,    36,    37,    32,    36,    34,    62,    55,    29,
      13,    66,    15,    44,    52,    51,    52,    10,    62,    80,
      67,    68,    66,    27,    71,    80,    11,    74,    75,    15,
      92,    62,    79,    28,    36,    66,    91,     4,     5,    30,
      95,    96,    14,    90,     4,     5,    13,    91,    16,    80,
      33,    95,    96,    13,    42,    43,    44,    45,    46,    47,
      91,    31,   124,    12,    95,    96,     9,   122,    39,    36,
      37,    38,    34,   120,    15,    11,    36,    37,   122,    76,
      77,    78,    21,    41,     3,    52,    40,     6,     7,     8,
      16,   122,    52,    42,    43,    44,    45,    46,    47,    18,
      16,    12,    12,    22,    23,    24,    14,    12,    17,    11,
      23,    12,     3,    20,    17,    19,    93,    17,    37,    17,
     120,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    54,    55,    37,    73,     0,    54,     9,    26,
      56,    57,    58,    73,    29,     9,    10,    11,    27,    56,
      32,    34,    58,    56,    15,    28,    36,    30,    14,     3,
       6,     7,     8,    18,    22,    23,    24,    59,    60,    63,
      73,    33,    13,    36,    52,    63,    64,    66,    67,    73,
      62,    63,    62,     4,     5,    13,    38,    64,    68,    69,
      70,    71,    16,    68,    73,    31,     9,    39,    15,    34,
      64,    13,    36,    63,    51,    52,    48,    49,    50,    13,
      11,    64,    68,    71,    42,    43,    44,    45,    46,    47,
      72,    21,    41,    40,    59,    16,    16,    59,    64,    64,
      12,    64,    64,    64,    66,    66,    66,    64,    65,    62,
      12,    64,    59,    68,    69,    17,    59,    59,    14,    12,
      11,    12,    20,    61,    23,    17,    17,    65,    59,    19,
      68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      64,    65,    65,    65,    66,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    72,    72,    72,    72,    72,
      72,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,    12,     3,     0,     8,     3,     3,
       1,     2,     3,     2,     1,     2,     2,     5,     6,     5,
       6,     3,     2,     0,     3,     1,     1,     4,     3,     3,
       1,     3,     1,     0,     3,     3,     3,     1,     4,     3,
       4,     1,     2,     2,     1,     3,     1,     3,     1,     1,
       2,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 103 "mini_l.y" /* yacc.c:1646  */
    {
	std::string tempPname = "main";
	if (functions.find(tempPname) == functions.end()) {
		char errorTemp[128];
		snprintf(errorTemp, 128, "Function main not find");
		yyerror(errorTemp);
	}

	if (variables.find(std::string(pName) != variables.end()) {
		char errorTemp[128];
		snprintf(errorTemp, 128, "Made program name a variable");
		yyerror(errorTemp);
	}



}
#line 1410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 122 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp = "func ";
	temp.append((yyvsp[-10].expr).place);
	temp.append("\n");
	temp.append((yyvsp[-10].expr).code);
	temp.append((yyvsp[-7].expr).code);

int parsNumber = 0;
std::string init_pars = (yyvsp[-7].expr).code;

while(init_pars.find(".") != std::string kPos) {
	size_t postion = init_pars.find(".");
	init_pars.replace(postion, 1, "=");
	std::string par = ", $";
	par.apppend(std::to_string(parsNumber++));
	parappend("\n");
	init_pars.replace(init_pars.find("\n", postion), 1, par);

}

temp.append(init_pars);
temp.append((yyvsp[-4].expr).code);
std::string statements((yyvsp[-1].stat).code)

//if(statements.find("continue" ) != 

temp.append(statements);
temp.append("endfunc\n");


printf("%s", temp.c_str());
}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 156 "mini_l.y" /* yacc.c:1646  */
    {
	std::strind temp;
	temp.append((yyvsp[-2].expr).code);
	temp.append((yyvsp[0].expr).code);
	(yyval.expr).code = strdup(temp.c_str());
	(yyval.expr).place = strdup(nothing);

}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 163 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).code = strdup(nothing);
	(yyval.expr).place = strdup(nothing);
}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 169 "mini_l.y" /* yacc.c:1646  */
    {
	//if($5 <0) error
	std::string vars((yyvsp[-7].expr).place);
	std::string temp;
f	std::string variable;
	bool con = true;

	size_t oldk = 0;
	size_t k = 0;
	
	while(con) {
		k = vars.find("|", oldk);
		if(k == std::string::nk){
			temp.append(". [] ");
			variable = vars.substr(oldk, k);
			temp.append(variable);
			temp.append(", ");
			temp.append(std::to_string((yyvsp[-3].number_val)));
			temp.append("\n");
			con = false;
}
		else{
			size_t length = k - oldk;
			temp.append(". [] ");
			variable = vars.substr(oldk, k);
			temp.append(", ");
			temp.append(std::to_string((yyvsp[-3].number_val)));
			temp.append("\n");
}
//if error check if time

		variables.insert(std::pair<std::string,int>(variable, (yyvsp[-3].number_val)));
		oldk = k + 1;

}

	(yyval.expr).code = strdup(temp.c_str());
	(yyval.expr).place = strdup(nothing);

}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 208 "mini_l.y" /* yacc.c:1646  */
    {
	std::string vars((yyvsp[-2].expr).place);
	std::string temp;
	std::string variable;
	bool con = true;

	size_t oldk = 0;
	size_t k = 0;
	bool isKey = false;

	while(con){
		k = vars.find("|", oldk);
		if(k == std::string::nk){
			temp.append(". ");
			variable = vars.substr(oldk, k);
			temp.append(variable);
			temp.append("\n");
			con = false;
}
		else{
			size_t length = k - oldk;
			temp.append(". ");
			variable = vars.substr(oldk, k);
			temp.append(variable);
			temp.append("\n");

}

//if check for errors if time again
	for(unsigned int i = 0; i < mapWords.size(); ++1){
		if(mapWords.at(i) == variable) {
			isKey = true;

		}
//more error checking needed
	variables.insert(std::pair<std::string,int>(variable, 0));
	oldk = k + 1;	
	}
}

	(yyval.expr).code = strdup(temp.c_str());
	(yyval.expr).place = strdup(nothing);

}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 254 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp;
	temp.append((yyvsp[-2].expr).place);
	temp.append("|");
	temp.append((yyvsp[0].expr).place);

	(yyval.expr).place = strdup(temp.c_str());
	(yyval.expr).code = strdup(nothing);

}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 263 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).place = strdup((yyvsp[0].expr).place);
	(yyval.expr).code = strdup(nothing);
}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 269 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp;
	temp.append((yyvsp[-1].stat).code);
	(yyval.stat).code = strdup(temp.c_str());
}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 273 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp;
	temp.append((yyvsp[-2].stat).code);
	temp.append((yyvsp[0].stat).code);
	(yyval.stat).code = strdup(temp.c_str());
}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 281 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp;
	temp.append((yyvsp[0].expr).code);
	temp.append("ret ");
	temp.append((yyvsp[0].expr).place);
	temp.append("\n");
	(yyval.stat).code = strdup(temp.c_str());
}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 289 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp = "continue\n";
	(yyval.stat).code = strdup(temp.c_str());
}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 292 "mini_l.y" /* yacc.c:1646  */
    {

	std::string temp = (yyvsp[0].expr).code;
	size_t x = 0;

	do{
		x = temp.find("|", x);
		if (x == std::string::nx)
			break;
		temp.replace(x, 1, ">");
	} while(true);

	(yyval.stat).code = strdup(temp.c_str());

}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 306 "mini_l.y" /* yacc.c:1646  */
    {

	std::string temp = (yyvsp[0].expr).code;
	size_t x = 0;

	do{
		x = temp.find("|", x);
		if (x == std::string::nx)
			break;
		temp.replace(x, 1, ">");
	} while(true);

	(yyval.stat).code = strdup(temp.c_str());

}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 320 "mini_l.y" /* yacc.c:1646  */
    {

	std::string temp;
	std::string flag = newTemp();
	std::string count = newTemp();
	std::string start = newLabel();
	std::string startLoop = newLabel();
	std::string endLoop = newLabel();
	std::string incre = newLabel();

	//std::string statement = $6.code;
	std::string x;
	
	x.append(":= ");
	x.append(incre);
	while(statement.find("continue") != std::string::kpos){
		statements.replace(statement.find("continue"), 8, x);
	}

//check for errors if time here

	temp.append(". ");
	temp.append((yyvsp[-3].expr).place);
	temp.append("\n");
	temp.append(". ");
	temp.append(flag);
	temp.append("\n");
	temp.append(". ");
	temp.append(count);
	temp.append(", 0 ");
	temp.append("\n");

	temp.append(": ");
	temp.append(start);
	temp.append("\n");
	temp.append("<");
	temp.append(flag);
	temp.append(", ");
	temp.append(count);
	temp.append(", ");
	temp.append(std::to_string(variables.find(std::string((yyvsp[-1].stat).place))->second));
	temp.append("\n");

	temp.append("?:= ");
	temp.append(startLoop);
	temp.append(", ");
	temp.append(flag);
	temp.append("\n");

	temp.append(":= ");
	temp.append(endLoop);
	temp.append("\n");

	temp.append(": ");
	temp.append(startLoop);
	temp.append("\n");

	temp.append("=[] ");
	temp.append((yyvsp[-3].expr).place);
	temp.append(", ");
	temp.append((yyvsp[-1].stat).place);
	temp.append(", ");
	temp.append(count);
	temp.append("\n");
	temp.append(statement);

	temp.append(": ");
	temp.append(incre);
	temp.append("\n");
	temp.append("+ ");
	temp.append(count);
	temp.append(", ");
	temp.append(count);
	temp.append(", 1\n");

	temp.append(":= ");
	temp.append(start);
	temp.append("\n");

	temp.append(": ");
	temp.append(endLoop);
	temp.append("\n");

	(yyval.stat).code = strdup(temp.c_str());

}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 405 "mini_l.y" /* yacc.c:1646  */
    {

	std::string temp;
	std::string startLoop = newLabel();
	std::string startWhile = newLabel();
	std::string statement = (yyvsp[-3].stat).code;
	std::string x;
	x.append(":= ");
	x.append(startWhile);
	
	while(statement.find("continue") != std::string::npos){
		statement.replace(statement.find("continue"), 8, x);
	}

	temp.append(": ");
	temp.append(startLoop);
	temp.append("\n");
	temp.append(statement);
	temp.append(": ");
	temp.append(startWhile);
	temp.append("\n");
	temp.append((yyvsp[0].expr).code);
	temp.append("?:= ");
	temp.append(startLoop);
	temp.append(", ");
	temp.append((yyvsp[0].expr).place);
	temp.append("\n");

	(yyval.stat).code = strdup(temp.c_str());

}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 435 "mini_l.y" /* yacc.c:1646  */
    {

	std::string temp;
	std::string startLoop = newLabel();
	std::string endLoop = newLabel();
	std::string startWhile = newLabel();
	std::string statement = (yyvsp[-1].stat).code;
	std::string x;
	x.append(":= ");
	x.append(startWhile);
	
	while(statement.find("continue") != std::string::npos){
		statement.replace(statement.find("continue"), 8, x);
	}

	temp.append(": ");
	temp.append(startWhile);
	temp.append("\n");
	temp.append((yyvsp[-3].expr).code);
	temp.append("?:= ");
	temp.append(startLoop);
	temp.append(", ");
	temp.append((yyvsp[-3].expr).place);
	temp.append("\n");
	temp.append(":= ");
	temp.append(endLoop);
	temp.append("\n");
	temp.append(": ");
	temp.append(startLoop);
	temp.append("\n");
	temp.append(statement);
	temp.append(":= ");
	temp.append(startWhile);
	temp.append("\n");
	temp.append(": ");
	temp.append(endLoop);
	temp.append("\n");

	(yyval.stat).code = strdup(temp.c_str());

}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 475 "mini_l.y" /* yacc.c:1646  */
    {

	std::string temp;
	std::string then_do = newLabel();
	std::string next = newLabel();
//if part
	temp.append((yyvsp[-4].expr).code);
	temp.append("?:= ");
	temp.append(then_do);
	temp.append(", ");
	temp.append((yyvsp[-4].expr).place);
	temp.append("\n");
//else 
	temp.append((yyvsp[-1].stat).code);
	temp.append(":= ");
	temp.append(next);
	temp.append("\n");

	temp.append(": ");
	temp.append(then_do);
	temp.append("\n");

	temp.append((yyvsp[-2].stat).code);
	temp.append(": ");
	temp.append(next);
	temp.append("\n");
	
	(yyval.stat).code = strdup(temp.c_str());

}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 504 "mini_l.y" /* yacc.c:1646  */
    {

	std::string temp;
	temp.append((yyvsp[-2].expr).code);
	temp.append((yyvsp[0].expr).code);
	std::string interm = (yyvsp[0].expr).place;

	if((yyvsp[-2].expr).array && (yyvsp[0].expr).array) {
		interm = newTemp();
		temp.append(". ");
		temp.append(interm);
		temp.append("\n");
		temp.append("=[] ");
		temp.append(interm);
		temp.append(", ");
		temp.append((yyvsp[0].expr).place);
		temp.append("\n");
		temp.append("[]= ");
	}
	else if ((yyvsp[-2].expr).array){
		temp.append("[]= ");
	}
	else if ((yyvsp[0].expr).array){
		temp.append("=[] ");
	}
	else{
		temp.append("= ");
	}

	temp.append((yyvsp[-2].expr).place);
	temp.append(", ");
	temp.append(interm);
	temp.append("\n");

	(yyval.stat).code = strdup(temp.c_str());

}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 543 "mini_l.y" /* yacc.c:1646  */
    { 
	(yyval.stat).code = strdup((yyvsp[0].stat).code);


}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 547 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.stat).code = strdup(nothing);
}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 553 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp;
	temp.append((yyvsp[-2].expr).code);
	if ((yyvsp[-2].expr).array){
		temp.append(".{}| ");}
	else{
		temp.append(".| ");
}
	temp.append((yyvsp[-2].expr).place);
	temp.append("\n");
	temp.append((yyvsp[0].expr).code);
	(yyval.expr).code = strdup(temp.c_str());
	(yyval.expr).place = strdup(nothing);

}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 567 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp;
	temp.append((yyvsp[0].expr).code);
	if ((yyvsp[0].expr).array){
		temp.append(".{}| ");
}
	else{
		temp.append(".| ");
}
	temp.append((yyvsp[0].expr).place);
	(yyval.expr).code = strdup(temp.c_str());
	(yyval.expr).place = strdup(nothing);
}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 582 "mini_l.y" /* yacc.c:1646  */
    {
		//if and else check for errors if time
	(yyval.expr).code = strdup(nothing);
	(yyval.expr).place = strdup((yyvsp[0].expr).place);
	(yyval.expr).array = false;

}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 588 "mini_l.y" /* yacc.c:1646  */
    {
		//if and else check for errors if time
	std::string temp;
	temp.append((yyvsp[-3].expr).place);
	temp.append(", ");
	temp.append((yyvsp[-1].expr).place);
	(yyval.expr).code = strdup((yyvsp[-1].expr).code);
	(yyval.expr).place = strdup(temp.c_str());
	(yyval.expr).array = true;
}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 600 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).place = strdup(newTemp().c_str());
	std::string temp;
	temp.append((yyvsp[-2].expr).code);
	temp.append((yyvsp[0].expr).code);
	temp.append(". ");
	temp.append((yyval.expr).place);
	temp.append("\n");
	temp.append("- ");
	temp.append((yyval.expr).place);
	temp.append(", ");
	temp.append((yyvsp[-2].expr).place);
	temp.append(", ");
	temp.append((yyvsp[0].expr).place);
	temp.append("\n");
	(yyval.expr).code = strdup(temp.c_str());

}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 617 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).place = strdup(newTemp().c_str());
	std::string temp;
	temp.append((yyvsp[-2].expr).code);
	temp.append((yyvsp[0].expr).code);
	temp.append(". ");
	temp.append((yyval.expr).place);
	temp.append("\n");
	temp.append("+ ");
	temp.append((yyval.expr).place);
	temp.append(", ");
	temp.append((yyvsp[-2].expr).place);
	temp.append(", ");
	temp.append((yyvsp[0].expr).place);
	temp.append("\n");
	(yyval.expr).code = strdup(temp.c_str());

}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 634 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).code = strdup((yyvsp[0].expr).code);
	(yyval.expr).place = strdup((yyvsp[0].expr).place);
}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 640 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp;
	temp.append((yyvsp[-2].expr).code);
	temp.append("param ");
	temp.append((yyvsp[-2].expr).place);
	temp.append("\n");
	temp.append((yyvsp[0].expr).code);
	(yyval.expr).code = strdup(temp.c_str());
	(yyval.expr).place = strdup(nothing);
}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 649 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp;
	temp.append((yyvsp[0].expr).code);
	temp.append("param ");
	temp.append((yyvsp[0].expr).place);
	temp.append("\n");
	(yyval.expr).code = strdup(temp.c_str());
	(yyval.expr).place = strdup(nothing);
}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 657 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).code = strdup(nothing);
	(yyval.expr).place = strdup(nothing);
}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 663 "mini_l.y" /* yacc.c:1646  */
    {

	(yyval.expr).place = strdup(newTemp().c_str());
	std::string temp;
	temp.append(". ");
	temp.append((yyval.expr).place);
	temp.append("\n");
	temp.append((yyvsp[-2].expr).code);
	temp.append((yyvsp[0].expr).code);
	temp.append("% ");
	temp.append((yyval.expr).place);
	temp.append(", ");
	temp.append((yyvsp[-2].expr).place);
	temp.append(", ");
	temp.append((yyvsp[0].expr).place);
	temp.append("\n");
	(yyval.expr).code = strdup(temp.c_str());

}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 681 "mini_l.y" /* yacc.c:1646  */
    {

	(yyval.expr).place = strdup(newTemp().c_str());
	std::string temp;
	temp.append(". ");
	temp.append((yyval.expr).place);
	temp.append("\n");
	temp.append((yyvsp[-2].expr).code);
	temp.append((yyvsp[0].expr).code);
	temp.append("/ ");
	temp.append((yyval.expr).place);
	temp.append(", ");
	temp.append((yyvsp[-2].expr).place);
	temp.append(", ");
	temp.append((yyvsp[0].expr).place);
	temp.append("\n");
	(yyval.expr).code = strdup(temp.c_str());

}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 699 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).place = strdup(newTemp().c_str());
	std::string temp;
	temp.append(". ");
	temp.append((yyval.expr).place);
	temp.append("\n");
	temp.append((yyvsp[-2].expr).code);
	temp.append((yyvsp[0].expr).code);
	temp.append("* ");
	temp.append((yyval.expr).place);
	temp.append(", ");
	temp.append((yyvsp[-2].expr).place);
	temp.append(", ");
	temp.append((yyvsp[0].expr).place);
	temp.append("\n");
	(yyval.expr).code = strdup(temp.c_str());

}
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 716 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).code = strdup((yyvsp[0].expr).code);
	(yyval.expr).place = strdup((yyvsp[0].expr).place);
}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 722 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp;
	temp.append((yyvsp[-1].expr).code);
	temp.append(". ");
	temp.append((yyval.expr).place);
	temp.append("\n");
	temp.append("call ");
	temp.append((yyvsp[-3].expr).place);
	temp.append(", ");
	temp.append((yyval.expr).place);
	temp.append("\n");

	(yyval.expr).code = strdup(temp.c_str());

}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 736 "mini_l.y" /* yacc.c:1646  */
    {

	(yyval.expr).code = strdup((yyvsp[-1].expr).code);
	(yyval.expr).place = strdup((yyvsp[-1].expr).place);

}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 741 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).place = strdup((yyvsp[-1].expr).place);
	std::string temp;
	temp.append((yyvsp[-1].expr).code);
	temp.append("* ");
	temp.append((yyvsp[-1].expr).place);
	temp.append(", ");
	temp.append((yyvsp[-1].expr).place);
	temp.append(", -1\n");
	(yyval.expr).code = strdup(temp.c_str());


}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 753 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).code = strdup(nothing);
	(yyval.expr).place = strdup(std::to_string((yyvsp[0].number_val)).c_str());

}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 757 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp;
	temp.append("-");
	temp.append(std::to_string((yyvsp[0].number_val)));
	(yyval.expr).code = strdup(nothing);
	(yyval.expr).place = strdup(temp.c_str());

}
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 764 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).place = strdup(newTemp().c_str());
	std::string temp;
	temp.append(". ");
	temp.append((yyval.expr).place);
	temp.append("\n");

	if((yyvsp[0].expr).array) {
		temp.append("=[] ");
		temp.append((yyval.expr).place);
		temp.append(", ");
		temp.append((yyvsp[0].expr).place);
		temp.append("\n");
	}
	else{
		temp.append("= ");
		temp.append((yyval.expr).place);
		temp.append(", ");
		temp.append((yyvsp[0].expr).place);
		temp.append("\n");
	}

	temp.append("* ");
	temp.append((yyval.expr).place);
	temp.append(", ");
	temp.append((yyval.expr).place);
	temp.append(", -1\n");
	(yyval.expr).code = strdup(temp.c_str());
	(yyval.expr).array = false;

}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 794 "mini_l.y" /* yacc.c:1646  */
    {
	if((yyval.expr).array == true){
	std::string temp;
	std::string interm = newTemp();
	temp.append((yyvsp[0].expr).code);
	temp.append(". ");
	temp.append(interm);
	temp.append("\n");
	temp.append("=[] ");
	temp.append(interm);
	temp.append(", ");
	temp.append((yyvsp[0].expr).place);
	temp.append("\n");
	(yyval.expr).code = strdup(temp.c_str());
	(yyval.expr).place = strdup(interm.c_str());
	(yyval.expr).array = false;
	}
	else{
	(yyval.expr).code = strdup((yyvsp[0].expr).code);
	(yyval.expr).place = strdup((yyvsp[0].expr).place);
}
}
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 819 "mini_l.y" /* yacc.c:1646  */
    {

	std::string spot = newTemp();
	std::string temp;
	temp.append((yyvsp[-2].expr).code);
	temp.append((yyvsp[0].expr).code);
	temp.append(". ");
	temp.append(spot);
	temp.append("\n");
	temp.append("|| ");
	temp.append(spot);
	temp.append(", ");
	temp.append((yyvsp[-2].expr).place);
	temp.append(", ");
	temp.append((yyvsp[0].expr).place);
	temp.append("\n");

	(yyval.expr).code = strdup(temp.c_str());
	(yyval.expr).place = strdup(spot.c_str());

}
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 839 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).place = strdup((yyvsp[0].expr).place);
	(yyval.expr).code = strdup((yyvsp[0].expr).code);
}
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 845 "mini_l.y" /* yacc.c:1646  */
    {

	std::string spot = newTemp();
	std::string temp;
	temp.append((yyvsp[-2].expr).code);
	temp.append((yyvsp[0].expr).code);
	temp.append(". ");
	temp.append(spot);
	temp.append("\n");
	temp.append("&& ");
	temp.append(spot);
	temp.append(", ");
	temp.append((yyvsp[-2].expr).place);
	temp.append(", ");
	temp.append((yyvsp[0].expr).place);
	temp.append("\n");

	(yyval.expr).code = strdup(temp.c_str());
	(yyval.expr).place = strdup(spot.c_str());

}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 865 "mini_l.y" /* yacc.c:1646  */
    {

	(yyval.expr).place = strdup((yyvsp[0].expr).place);
	(yyval.expr).code = strdup((yyvsp[0].expr).code);

}
#line 2383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 873 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).code = strdup((yyvsp[0].expr).code);
	(yyval.expr).place = strdup((yyvsp[0].expr).place);
}
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 876 "mini_l.y" /* yacc.c:1646  */
    {
	std::string x = newTemp();
	std::string temp;
	temp.append((yyvsp[0].expr).code);
	temp.append(". ");
	temp.append(x);
	temp.append("\n");
	temp.append("! ");
	temp.append(x);
	temp.append(", ");
	temp.append((yyvsp[0].expr).place);
	temp.append("\n");
	(yyval.expr).code = strdup(temp.c_str());
	(yyval.expr).place = strdup(x);
}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 893 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).code = strdup((yyvsp[-1].expr).code);
	(yyval.expr).place = strdup((yyvsp[-1].expr).place);
}
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 896 "mini_l.y" /* yacc.c:1646  */
    {
	char temp[2] = "0";
	(yyval.expr).code = strdup(nothing);
	(yyval.expr).place = strdup(temp);
}
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 900 "mini_l.y" /* yacc.c:1646  */
    {
	char temp[2] = "1";
	(yyval.expr).code = strdup(nothing);
	(yyval.expr).place = strdup(temp);
}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 904 "mini_l.y" /* yacc.c:1646  */
    {
	//still need to finish to be done with RExp0
}
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 909 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp = ">=";
	(yyval.expr).place = strdup(temp.c_str());
	(yyval.expr).code = strdup(nothing);
}
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 914 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp = "<=";
	(yyval.expr).place = strdup(temp.c_str());
	(yyval.expr).code = strdup(nothing);
}
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 918 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp = ">";
	(yyval.expr).place = strdup(temp.c_str());
	(yyval.expr).code = strdup(nothing);
}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 922 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp = "<";
	(yyval.expr).place = strdup(temp.c_str());
	(yyval.expr).code = strdup(nothing);
}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 926 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp = "!=";
	(yyval.expr).place = strdup(temp.c_str());
	(yyval.expr).code = strdup(nothing);
}
#line 2499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 930 "mini_l.y" /* yacc.c:1646  */
    {
	std::string temp = "==";
	(yyval.expr).place = strdup(temp.c_str());
	(yyval.expr).code = strdup(nothing);
}
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 937 "mini_l.y" /* yacc.c:1646  */
    {
	(yyval.expr).place = strdup((yyvsp[0].ident_val));
	(yyval.expr).code = strdup(nothing); 
}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2522 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 962 "mini_l.y" /* yacc.c:1906  */


int yyerror(const char* x) {
  extern char* yytext;
  extern int LineRow;

  printf("Error: %s at symbol on line %d\n", x, LineRow);
  exit(1);
}


std::string newLabel(){
	static int n = 0; 
	std::string temp = 'L' + std::to_string(n++);
	return temp;
}


std::string newTemp(){
	static int n = 0; 
	std::string temp = "_t" + std::to_string(n++);
	return temp;
}





