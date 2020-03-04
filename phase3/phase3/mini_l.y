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

Declaration: Identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER  {} | Identifiers COLON INTEGER  {}
;

Identifiers: Ident COMMA Identifiers {
	std::string temp;
	temp.append($1.place);
	temp.append("|");
	temp.append($3.place);

	$$.place = strdup(temp.c_str());
	$$.code = strdup(nothing);

} | Ident {
	$$.place = strdup($1.place);
	$$.code = strdup(nothing);
}
;

Statements: Statement SEMICOLON {
	std::string temp;
	temp.append($1.code);
	$$.code = strdup(temp.c_str());
} | Statement SEMICOLON Statements {
	std::string temp;
	temp.append($1.code);
	temp.append($3.code);
	$$.code = strdup(temp.c_str());
}
;

Statement: RETURN Expression {} | 
CONTINUE {} | WRITE Vars {} | READ Vars {} | FOR Ident BEGIN_LOOP Statements END_LOOP {} | DO BEGIN_LOOP Statements END_LOOP WHILE BoolExpr {} | WHILE BoolExpr BEGIN_LOOP Statements END_LOOP {} | IF BoolExpr THEN Statements ElseStatement ENDIF {} | Var ASSIGN Expression {}
;

ElseStatement: ELSE Statements {} | %empty {}
;


Vars: Var COMMA Vars {} | Var {}
;

Var: Ident {} | Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {}
;

Expression: MultiplicativeExpression SUB Expression {} | MultiplicativeExpression ADD Expression {} | MultiplicativeExpression  {}
;

Expressions: Expression COMMA Expressions {} | Expression {} | %empty {}
;

MultiplicativeExpression: Term MOD MultiplicativeExpression {} | Term DIV MultiplicativeExpression {} | Term MULT MultiplicativeExpression {} | Term {}
;

Term: Ident L_PAREN Expressions R_PAREN {} | L_PAREN Expression R_PAREN {} | SUB L_PAREN Expression R_PAREN {} | NUMBER {} | SUB NUMBER {} | SUB Var {} | Var {}
;


BoolExpr: RelationAndExpr OR BoolExpr {} | RelationAndExpr {}
;

RelationAndExpr: RelationExpr AND RelationAndExpr {} | RelationExpr {}
;

RelationExpr: RelationExpr0 {} | NOT RelationExpr0 {}
;

RelationExpr0: L_PAREN BoolExpr R_PAREN {} | FALSE {} | TRUE {} | Expression Comp Expression {}
;

Comp: GTE {
	std::string temp = ">=";
	$$.place = strdup(temp.c_str());
	$$.code = strdup(nothing);
} 
| LTE {
	std::string temp = "<=";
	$$.place = strdup(temp.c_str());
	$$.code = strdup(nothing);
} | GT {
	std::string temp = ">";
	$$.place = strdup(temp.c_str());
	$$.code = strdup(nothing);
} | LT {
	std::string temp = "<";
	$$.place = strdup(temp.c_str());
	$$.code = strdup(nothing);
} | NEQ {
	std::string temp = "!=";
	$$.place = strdup(temp.c_str());
	$$.code = strdup(nothing);
} | EQ {
	std::string temp = "==";
	$$.place = strdup(temp.c_str());
	$$.code = strdup(nothing);
}
;

Ident: IDENT {
	$$.place = strdup($1);
	$$.code = strdup(nothing); 
}
;








%%

int yyerror(const char* x) {
  extern char* yytext;
  extern int LineRow;

  printf("Error: %s at symbol on line %d\n", x, LineRow);
  exit(1);
}
