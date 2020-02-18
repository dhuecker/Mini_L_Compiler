/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    FOREACH = 279,
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
    ADD = 303,
    SUB = 304,
    MOD = 305,
    MULT = 306,
    DIV = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 8 "test2.y" /* yacc.c:1909  */

  char* ident_val;
  int number_val;

#line 112 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
