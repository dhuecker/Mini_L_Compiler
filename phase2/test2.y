%{
#include <stdio.h>
#include <stdlib.h>
#define YY_NO_UNPUT
int yyerror(const char* x);
%}

%union {
  char* ident_val;
  int number_val;
}


%error-verbose
%start Program

%type <ident_val> IDENT
%type <number_val> NUMBER

%token RETURN
%token TRUE
%token FALSE
%token CONTINUE
%token WRITE
%token READ
%token SEMICOLON
%token COLON
%token COMMA
%token R_PAREN
%token L_PAREN
%token R_SQUARE_BRACKET
%token L_SQUARE_BRACKET
%token BEGIN_LOOP
%token END_LOOP
%token IF
%token ENDIF
%token ELSE
%token THEN
%token DO
%token WHILE
%token FOREACH
%token IN
%token BEGIN_PARAMS
%token BEGIN_LOCALS
%token END_LOCALS
%token END_PARAMS
%token BEGIN_BODY
%token END_BODY
%token ARRAY
%token OF
%token INTEGER
%token FUNCTION
%token NUMBER
%token IDENT
%right NOT

%left ASSIGN
%left AND
%left OR
%left NEQ
%left EQ
%left LTE
%left GTE
%left GT
%left LT
%left ADD
%left SUB
%left MOD
%left MULT
%left DIV

%%

Var: Ident {printf("Var --> Ident \n");} | Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {printf("Var --> Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET\n");}
;

Vars: Var COMMA Vars {printf("Vars --> Var COMMA Vars\n");} | Var {printf("Vars --> Var\n");}
;

Term: Ident L_PAREN Expressions R_PAREN {printf("Term --> Ident L_PAREN Expressions R_PAREN\n");} | L_PAREN Expression R_PAREN {printf("Term -->L_PAREN Expression R_PAREN\n");} | SUB L_PAREN Expression R_PAREN {printf("Term -->SUB L_PAREN Expression R_PAREN\n");} | NUMBER {printf("Term --> NUMBER %d\n", $1);} | SUB NUMBER {printf("Term --> SUB NUMBER\n");} | SUB Var {printf("Term --> SUB Var\n");} | Var {printf("Term --> Var\n");}
;

MultiplicativeExpression: Term MOD MultiplicativeExpression {printf("MultiplicativeExpression --> Term MOD MultiplicativeExpression\n");} | Term DIV MultiplicativeExpression {printf("MultiplicativeExpression --> Term DIV MultiplicativeExpression\n");} | Term MULT MultiplicativeExpression {printf("MultiplicativeExpression --> Term MULT MultiplicativeExpression\n");} | Term {printf("MultiplicativeExpression --> Term\n");}
;


Expression: MultiplicativeExpression SUB Expression {printf("Expression --> MultiplicativeExpression SUB Expression\n");} | MultiplicativeExpression ADD Expression {printf("Expression --> MultiplicativeExpression ADD Expression\n");} | MultiplicativeExpression  {printf("Expression --> MultiplicativeExpression\n");}
;

Expressions: Expression COMMA Expressions {printf("Expressions --> Expression COMMA Expressions\n");} | Expression {printf("Expressions --> Expression\n");} | {printf("Expressions --> epsilon\n");}
;


Comp: GTE {printf("comp --> GTE\n");} | LTE {printf("comp --> LTE\n");} | GT {printf("comp --> GT\n");} | LT {printf("comp --> LT\n");} | NEQ {printf("comp --> NEQ\n");} | EQ {printf("comp --> EQ\n");}
;

RelationExpr: RelationExpr0 {printf("RelationExpr --> RealtionExpr0\n");} | NOT RelationExpr0 {printf("RelationExpr --> NOT RealtionExpr0\n");}
;

RelationExpr0: L_PAREN BoolExpr R_PAREN {printf("RelationExpr0 -->  L_PAREN BoolExpr R_PAREN\n");} | FALSE {printf("RelationExpr0 --> FALSE\n");} | TRUE {printf("RelationExpr0 --> TRUE\n");} | Expression Comp Expression {printf("RelationExpr0 --> Expression Comp Expression\n");}
;

RelationAndExpr: RelationExpr AND RelationAndExpr {printf("RelationAndExpr --> RelationExpr AND RelationAndExpr\n");} | RelationExpr {printf("RelationAndExpr --> RealtionExpr\n");}
;

BoolExpr: RelationAndExpr OR BoolExpr {printf("BoolExpr --> RelationAndExpr OR BoolExpr\n");} | RelationAndExpr {printf("BoolExpr --> RealtionAndExpr\n");}
;

Statement: RETURN Expression {printf("Statement --> RETURN Expression\n");} | 
CONTINUE {printf("Statement --> CONTINUE\n");} | WRITE Vars {printf("Statement --> WRITE Vars \n");} | READ Vars {printf("Statement --> READ Vars\n");} | FOREACH Ident BEGIN_LOOP Statements END_LOOP {printf("Statement --> FOREACH Ident BEGINLOOP Statements ENDLOOP\n");} | DO BEGIN_LOOP Statements END_LOOP WHILE BoolExpr {printf("Statement --> DO BEGINLOOP Statements ENDLOOP WHILE BoolExpr\n");} | WHILE BoolExpr BEGIN_LOOP Statements END_LOOP {printf("Statement -->WHILE BoolExpr BEGINLOOP Statements ENDLOOP\n");} | IF BoolExpr THEN Statements ElseStatement ENDIF {printf("Statement --> IF BoolExpr THEN Statements ElseStatement ENDIF\n");} | Var ASSIGN Expression {printf("Statement --> Var ASSIGN Expression\n");}
;

Statements: Statement SEMICOLON {printf("Statements --> Statement SEMICOLON\n");} | Statement SEMICOLON Statements {printf("Statements --> Statement SEMICOLON Statements\n");}
;

ElseStatement: ELSE Statements {printf("ElseStatement --> ELSE Statement\n");} | %empty {printf("ElseStatement --> epsilon\n");}
;

Declaration: Identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER  {printf("Declaration --> Identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");} | Identifiers COLON INTEGER  {printf("Declaration --> Identifiers COLON INTEGER\n");}
;

Declarations: Declaration SEMICOLON Declarations  {printf("Declarations --> Declaration SEMICOLON Declarations\n");} | {printf("Declarations --> epsilon\n");}
;

Ident: IDENT {printf("Ident --> IDENT \n");}
;

Identifiers: Ident COMMA Identifiers {printf("Identifiers --> Ident COMMA Identifiers\n");} | Ident {printf("Identifiers --> Ident\n");}
;

Function: Function Ident SEMICOLON BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statements END_BODY {printf("Function --> Function Ident SEMICOLON BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statements END_BODY\n");}
;

Program: Function Program {printf("Program --> Function Program\n");} | {printf("Program --> epsilon\n");}
;


%%

int yyerror(const char* x) {
  extern char* yytext;
  extern int LineRow;

  printf("Error: %s at symbol on line %d\n", x, LineRow);
  exit(1);
}
