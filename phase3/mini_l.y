%{
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
%}

%union {
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

}


%error-verbose
%start Program

%type <ident_val> IDENT
%type <number_val> NUMBER

%type <expr> FunctionIdent LocalIdent Ident
%type <expr> Vars Var Declarations Declaration Identifiers
%type <stat> Statement ElseStatment Statements
%type <expr> Expressions Expression RelationExp RelationExpr0 MultiplicativeExpression BoolExp Comp Term




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
%token FOR
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
%left AND OR NEQ EQ LTE GTE GT LT
%left MOD
%left MULT DIV
%left ADD SUB

%%

Program: Function Program | %empty {
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
;

Function: FUNCTION Ident SEMICOLON BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statements END_BODY {
	std::string temp = "func ";
	temp.append($2.place);
	temp.append("\n");
	temp.append($2.code);
	temp.append($5.code);

int parsNumber = 0;
std::string init_pars = $5.code;

while(init_pars.find(".") != std::string kPos) {
	size_t postion = init_pars.find(".");
	init_pars.replace(postion, 1, "=");
	std::string par = ", $";
	par.apppend(std::to_string(parsNumber++));
	parappend("\n");
	init_pars.replace(init_pars.find("\n", postion), 1, par);

}

temp.append(init_pars);
temp.append($8.code);
std::string statements($11.code)

//if(statements.find("continue" ) != 

temp.append(statements);
temp.append("endfunc\n");


printf("%s", temp.c_str());
; 

Declarations: Declaration SEMICOLON Declarations  {
	std::strind temp;
	temp.append($1.code);
	temp.append($3.code);
	$$.code = strdup(temp.c_str());
	$$.place = strdup(nothing);

} | %empty {
	$$.code = strdup(nothing);
	$$.place = strdup(nothing);
}
;

Declaration: Identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER  {printf("Declaration --> Identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");} | Identifiers COLON INTEGER  {printf("Declaration --> Identifiers COLON INTEGER\n");}
;

Identifiers: Ident COMMA Identifiers {printf("Identifiers --> Ident COMMA Identifiers\n");} | Ident {
	$$.place = strdup($1.place);
	$$.code = strdup(nothing);
}
;

Statements: Statement SEMICOLON {printf("Statements --> Statement SEMICOLON\n");} | Statement SEMICOLON Statements {printf("Statements --> Statement SEMICOLON Statements\n");}
;

Statement: RETURN Expression {printf("Statement --> RETURN Expression\n");} | 
CONTINUE {printf("Statement --> CONTINUE\n");} | WRITE Vars {printf("Statement --> WRITE Vars \n");} | READ Vars {printf("Statement --> READ Vars\n");} | FOREACH Ident BEGIN_LOOP Statements END_LOOP {printf("Statement --> FOREACH Ident BEGINLOOP Statements ENDLOOP\n");} | DO BEGIN_LOOP Statements END_LOOP WHILE BoolExpr {printf("Statement --> DO BEGINLOOP Statements ENDLOOP WHILE BoolExpr\n");} | WHILE BoolExpr BEGIN_LOOP Statements END_LOOP {printf("Statement -->WHILE BoolExpr BEGINLOOP Statements ENDLOOP\n");} | IF BoolExpr THEN Statements ElseStatement ENDIF {printf("Statement --> IF BoolExpr THEN Statements ElseStatement ENDIF\n");} | Var ASSIGN Expression {printf("Statement --> Var ASSIGN Expression\n");}
;

ElseStatement: ELSE Statements {printf("ElseStatement --> ELSE Statement\n");} | %empty {printf("ElseStatement --> epsilon\n");}
;


Vars: Var COMMA Vars {printf("Vars --> Var COMMA Vars\n");} | Var {printf("Vars --> Var\n");}
;

Var: Ident {printf("Var --> Ident \n");} | Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {printf("Var --> Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET\n");}
;

Expression: MultiplicativeExpression SUB Expression {printf("Expression --> MultiplicativeExpression SUB Expression\n");} | MultiplicativeExpression ADD Expression {printf("Expression --> MultiplicativeExpression ADD Expression\n");} | MultiplicativeExpression  {printf("Expression --> MultiplicativeExpression\n");}
;

Expressions: Expression COMMA Expressions {printf("Expressions --> Expression COMMA Expressions\n");} | Expression {printf("Expressions --> Expression\n");} | %empty {printf("Expressions --> epsilon\n");}
;

MultiplicativeExpression: Term MOD MultiplicativeExpression {printf("MultiplicativeExpression --> Term MOD MultiplicativeExpression\n");} | Term DIV MultiplicativeExpression {printf("MultiplicativeExpression --> Term DIV MultiplicativeExpression\n");} | Term MULT MultiplicativeExpression {printf("MultiplicativeExpression --> Term MULT MultiplicativeExpression\n");} | Term {printf("MultiplicativeExpression --> Term\n");}
;

Term: Ident L_PAREN Expressions R_PAREN {printf("Term --> Ident L_PAREN Expressions R_PAREN\n");} | L_PAREN Expression R_PAREN {printf("Term -->L_PAREN Expression R_PAREN\n");} | SUB L_PAREN Expression R_PAREN {printf("Term -->SUB L_PAREN Expression R_PAREN\n");} | NUMBER {printf("Term --> NUMBER\n");} | SUB NUMBER {printf("Term --> SUB NUMBER\n");} | SUB Var {printf("Term --> SUB Var\n");} | Var {printf("Term --> Var\n");}
;


BoolExpr: RelationAndExpr OR BoolExpr {printf("BoolExpr --> RelationAndExpr OR BoolExpr\n");} | RelationAndExpr {printf("BoolExpr --> RealtionAndExpr\n");}
;

RelationAndExpr: RelationExpr AND RelationAndExpr {printf("RelationAndExpr --> RelationExpr AND RelationAndExpr\n");} | RelationExpr {printf("RelationAndExpr --> RealtionExpr\n");}
;

RelationExpr: RelationExpr0 {printf("RelationExpr --> RealtionExpr0\n");} | NOT RelationExpr0 {printf("RelationExpr --> NOT RealtionExpr0\n");}
;

RelationExpr0: L_PAREN BoolExpr R_PAREN {printf("RelationExpr0 -->  L_PAREN BoolExpr R_PAREN\n");} | FALSE {printf("RelationExpr0 --> FALSE\n");} | TRUE {printf("RelationExpr0 --> TRUE\n");} | Expression Comp Expression {printf("RelationExpr0 --> Expression Comp Expression\n");}
;

Comp: GTE {printf("comp --> GTE\n");} | LTE {printf("comp --> LTE\n");} | GT {printf("comp --> GT\n");} | LT {printf("comp --> LT\n");} | NEQ {printf("comp --> NEQ\n");} | EQ {printf("comp --> EQ\n");}
;






Ident: IDENT {printf("Ident --> IDENT %s\n", $1);}
;








%%

int yyerror(const char* x) {
  extern char* yytext;
  extern int LineRow;

  printf("Error: %s at symbol on line %d\n", x, LineRow);
  exit(1);
}
