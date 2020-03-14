%{
#include <stdbool.h>
#include <map>
#include <vector>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#define YY_NO_UNPUT
void yyerror(const char* x);
int yylex();
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
%type <stat> Statement ElseStatement Statements
%type <expr> Expressions Expression RelationExpr RelationAndExpr RelationExpr0 MultiplicativeExpression BoolExpr Comp Term




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
	/*std::string tempPname = "main";
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
*/


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

while(init_pars.find(".") != std::string::npos) {
	size_t postion = init_pars.find(".");
	init_pars.replace(postion, 1, "=");
	std::string par = ", $";
	par.append(std::to_string(parsNumber++));
	par.append("\n");
	init_pars.replace(init_pars.find("\n", postion), 1, par);

}

temp.append(init_pars);
temp.append($8.code);
std::string statements($11.code);

//if(statements.find("continue" ) != 

temp.append(statements);
temp.append("endfunc\n");


printf("%s", temp.c_str());
}
; 

Declarations: Declaration SEMICOLON Declarations  {
	std::string temp;
	temp.append($1.code);
	temp.append($3.code);
	$$.code = strdup(temp.c_str());
	$$.place = strdup(nothing);

} | %empty {
	$$.code = strdup(nothing);
	$$.place = strdup(nothing);
}
;

Declaration: Identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER  {
	//if($5 <0) error
	std::string vars($1.place);
	std::string temp;
	std::string variable;
	bool con = true;

	size_t oldk = 0;
	size_t k = 0;
	
	while(con) {
		k = vars.find("|", oldk);
		if(k == std::string::npos){
			temp.append(". [] ");
			variable = vars.substr(oldk, k);
			temp.append(variable);
			temp.append(", ");
			temp.append(std::to_string($5));
			temp.append("\n");
			con = false;
}
		else{
			size_t length = k - oldk;
			temp.append(". [] ");
			variable = vars.substr(oldk, k);
			temp.append(", ");
			temp.append(std::to_string($5));
			temp.append("\n");
}
//if error check if time

		variables.insert(std::pair<std::string,int>(variable, $5));
		oldk = k + 1;

}

	$$.code = strdup(temp.c_str());
	$$.place = strdup(nothing);

} | Identifiers COLON INTEGER  {
	std::string vars($1.place);
	std::string temp;
	std::string variable;
	bool con = true;

	size_t oldk = 0;
	size_t k = 0;
	bool isKey = false;

	while(con){
		k = vars.find("|", oldk);
		if(k == std::string::npos){
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
	for(unsigned int i = 0; i < mapWords.size(); ++i){
		if(mapWords.at(i) == variable) {
			isKey = true;

		}
//more error checking needed
	variables.insert(std::pair<std::string,int>(variable, 0));
	oldk = k + 1;	
	}
}

	$$.code = strdup(temp.c_str());
	$$.place = strdup(nothing);

};


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

Statement: RETURN Expression {
	std::string temp;
	temp.append($2.code);
	temp.append("ret ");
	temp.append($2.place);
	temp.append("\n");
	$$.code = strdup(temp.c_str());
} | 
CONTINUE {
	std::string temp = "continue\n";
	$$.code = strdup(temp.c_str());
} | WRITE Vars {

	std::string temp = $2.code;
	size_t x = 0;

	do{
		x = temp.find("|", x);
		if (x == std::string::npos)
			break;
		temp.replace(x, 1, ">");
	} while(true);

	$$.code = strdup(temp.c_str());

} | READ Vars {

	std::string temp = $2.code;
	size_t x = 0;

	do{
		x = temp.find("|", x);
		if (x == std::string::npos)
			break;
		temp.replace(x, 1, ">");
	} while(true);

	$$.code = strdup(temp.c_str());

} | FOR Ident BEGIN_LOOP Statements END_LOOP {

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
	//while(statement.find("continue") != std::string::kpos){
	//	statements.replace(statement.find("continue"), 8, x);
	//}

//check for errors if time here

	temp.append(". ");
	temp.append($2.place);
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
	//temp.append(std::to_string(variables.find(std::string($4.place))->second));
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
	temp.append($2.place);
	temp.append(", ");
	//temp.append($4.place);
	temp.append(", ");
	temp.append(count);
	temp.append("\n");
	//temp.append(statement);

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

	$$.code = strdup(temp.c_str());

} | DO BEGIN_LOOP Statements END_LOOP WHILE BoolExpr {

	std::string temp;
	std::string startLoop = newLabel();
	std::string startWhile = newLabel();
	std::string statement = $3.code;
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
	temp.append($6.code);
	temp.append("?:= ");
	temp.append(startLoop);
	temp.append(", ");
	temp.append($6.place);
	temp.append("\n");

	$$.code = strdup(temp.c_str());

} | WHILE BoolExpr BEGIN_LOOP Statements END_LOOP {

	std::string temp;
	std::string startLoop = newLabel();
	std::string endLoop = newLabel();
	std::string startWhile = newLabel();
	std::string statement = $4.code;
	std::string x;
	x.append(":= ");
	x.append(startWhile);
	
	while(statement.find("continue") != std::string::npos){
		statement.replace(statement.find("continue"), 8, x);
	}

	temp.append(": ");
	temp.append(startWhile);
	temp.append("\n");
	temp.append($2.code);
	temp.append("?:= ");
	temp.append(startLoop);
	temp.append(", ");
	temp.append($2.place);
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

	$$.code = strdup(temp.c_str());

} | IF BoolExpr THEN Statements ElseStatement ENDIF {

	std::string temp;
	std::string then_do = newLabel();
	std::string next = newLabel();
//if part
	temp.append($2.code);
	temp.append("?:= ");
	temp.append(then_do);
	temp.append(", ");
	temp.append($2.place);
	temp.append("\n");
//else 
	temp.append($5.code);
	temp.append(":= ");
	temp.append(next);
	temp.append("\n");

	temp.append(": ");
	temp.append(then_do);
	temp.append("\n");

	temp.append($4.code);
	temp.append(": ");
	temp.append(next);
	temp.append("\n");
	
	$$.code = strdup(temp.c_str());

} | Var ASSIGN Expression {

	std::string temp;
	temp.append($1.code);
	temp.append($3.code);
	std::string interm = $3.place;

	if($1.array && $3.array) {
		interm = newTemp();
		temp.append(". ");
		temp.append(interm);
		temp.append("\n");
		temp.append("=[] ");
		temp.append(interm);
		temp.append(", ");
		temp.append($3.place);
		temp.append("\n");
		temp.append("[]= ");
	}
	else if ($1.array){
		temp.append("[]= ");
	}
	else if ($3.array){
		temp.append("=[] ");
	}
	else{
		temp.append("= ");
	}

	temp.append($1.place);
	temp.append(", ");
	temp.append(interm);
	temp.append("\n");

	$$.code = strdup(temp.c_str());

}
;

ElseStatement: ELSE Statements { 
	$$.code = strdup($2.code);


} | %empty {
	$$.code = strdup(nothing);
}
;


Vars: Var COMMA Vars {
	std::string temp;
	temp.append($1.code);
	if ($1.array){
		temp.append(".{}| ");}
	else{
		temp.append(".| ");
}
	temp.append($1.place);
	temp.append("\n");
	temp.append($3.code);
	$$.code = strdup(temp.c_str());
	$$.place = strdup(nothing);

} | Var {
	std::string temp;
	temp.append($1.code);
	if ($1.array){
		temp.append(".{}| ");
}
	else{
		temp.append(".| ");
}
	temp.append($1.place);
	$$.code = strdup(temp.c_str());
	$$.place = strdup(nothing);
};


Var: Ident {
		//if and else check for errors if time
	$$.code = strdup(nothing);
	$$.place = strdup($1.place);
	$$.array = false;

} | Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {
		//if and else check for errors if time
	std::string temp;
	temp.append($1.place);
	temp.append(", ");
	temp.append($3.place);
	$$.code = strdup($3.code);
	$$.place = strdup(temp.c_str());
	$$.array = true;
}
;

Expression: MultiplicativeExpression SUB Expression {
	$$.place = strdup(newTemp().c_str());
	std::string temp;
	temp.append($1.code);
	temp.append($3.code);
	temp.append(". ");
	temp.append($$.place);
	temp.append("\n");
	temp.append("- ");
	temp.append($$.place);
	temp.append(", ");
	temp.append($1.place);
	temp.append(", ");
	temp.append($3.place);
	temp.append("\n");
	$$.code = strdup(temp.c_str());

} | MultiplicativeExpression ADD Expression {
	$$.place = strdup(newTemp().c_str());
	std::string temp;
	temp.append($1.code);
	temp.append($3.code);
	temp.append(". ");
	temp.append($$.place);
	temp.append("\n");
	temp.append("+ ");
	temp.append($$.place);
	temp.append(", ");
	temp.append($1.place);
	temp.append(", ");
	temp.append($3.place);
	temp.append("\n");
	$$.code = strdup(temp.c_str());

} | MultiplicativeExpression  {
	$$.code = strdup($1.code);
	$$.place = strdup($1.place);
}
;

Expressions: Expression COMMA Expressions {
	std::string temp;
	temp.append($1.code);
	temp.append("param ");
	temp.append($1.place);
	temp.append("\n");
	temp.append($3.code);
	$$.code = strdup(temp.c_str());
	$$.place = strdup(nothing);
} | Expression {
	std::string temp;
	temp.append($1.code);
	temp.append("param ");
	temp.append($1.place);
	temp.append("\n");
	$$.code = strdup(temp.c_str());
	$$.place = strdup(nothing);
} | %empty {
	$$.code = strdup(nothing);
	$$.place = strdup(nothing);
}
;

MultiplicativeExpression: Term MOD MultiplicativeExpression {

	$$.place = strdup(newTemp().c_str());
	std::string temp;
	temp.append(". ");
	temp.append($$.place);
	temp.append("\n");
	temp.append($1.code);
	temp.append($3.code);
	temp.append("% ");
	temp.append($$.place);
	temp.append(", ");
	temp.append($1.place);
	temp.append(", ");
	temp.append($3.place);
	temp.append("\n");
	$$.code = strdup(temp.c_str());

} | Term DIV MultiplicativeExpression {

	$$.place = strdup(newTemp().c_str());
	std::string temp;
	temp.append(". ");
	temp.append($$.place);
	temp.append("\n");
	temp.append($1.code);
	temp.append($3.code);
	temp.append("/ ");
	temp.append($$.place);
	temp.append(", ");
	temp.append($1.place);
	temp.append(", ");
	temp.append($3.place);
	temp.append("\n");
	$$.code = strdup(temp.c_str());

} | Term MULT MultiplicativeExpression {
	$$.place = strdup(newTemp().c_str());
	std::string temp;
	temp.append(". ");
	temp.append($$.place);
	temp.append("\n");
	temp.append($1.code);
	temp.append($3.code);
	temp.append("* ");
	temp.append($$.place);
	temp.append(", ");
	temp.append($1.place);
	temp.append(", ");
	temp.append($3.place);
	temp.append("\n");
	$$.code = strdup(temp.c_str());

} | Term {
	$$.code = strdup($1.code);
	$$.place = strdup($1.place);
}
;

Term: Ident L_PAREN Expressions R_PAREN {
	std::string temp;
	temp.append($3.code);
	temp.append(". ");
	temp.append($$.place);
	temp.append("\n");
	temp.append("call ");
	temp.append($1.place);
	temp.append(", ");
	temp.append($$.place);
	temp.append("\n");

	$$.code = strdup(temp.c_str());

} | L_PAREN Expression R_PAREN {

	$$.code = strdup($2.code);
	$$.place = strdup($2.place);

} | SUB L_PAREN Expression R_PAREN {
	$$.place = strdup($3.place);
	std::string temp;
	temp.append($3.code);
	temp.append("* ");
	temp.append($3.place);
	temp.append(", ");
	temp.append($3.place);
	temp.append(", -1\n");
	$$.code = strdup(temp.c_str());


} | NUMBER {
	$$.code = strdup(nothing);
	$$.place = strdup(std::to_string($1).c_str());

} | SUB NUMBER {
	std::string temp;
	temp.append("-");
	temp.append(std::to_string($2));
	$$.code = strdup(nothing);
	$$.place = strdup(temp.c_str());

} | SUB Var {
	$$.place = strdup(newTemp().c_str());
	std::string temp;
	temp.append(". ");
	temp.append($$.place);
	temp.append("\n");

	if($2.array) {
		temp.append("=[] ");
		temp.append($$.place);
		temp.append(", ");
		temp.append($2.place);
		temp.append("\n");
	}
	else{
		temp.append("= ");
		temp.append($$.place);
		temp.append(", ");
		temp.append($2.place);
		temp.append("\n");
	}

	temp.append("* ");
	temp.append($$.place);
	temp.append(", ");
	temp.append($$.place);
	temp.append(", -1\n");
	$$.code = strdup(temp.c_str());
	$$.array = false;

} | Var {
	if($$.array == true){
	std::string temp;
	std::string interm = newTemp();
	temp.append($1.code);
	temp.append(". ");
	temp.append(interm);
	temp.append("\n");
	temp.append("=[] ");
	temp.append(interm);
	temp.append(", ");
	temp.append($1.place);
	temp.append("\n");
	$$.code = strdup(temp.c_str());
	$$.place = strdup(interm.c_str());
	$$.array = false;
	}
	else{
	$$.code = strdup($1.code);
	$$.place = strdup($1.place);
}
}
;


BoolExpr: RelationAndExpr OR BoolExpr {

	std::string spot = newTemp();
	std::string temp;
	temp.append($1.code);
	temp.append($3.code);
	temp.append(". ");
	temp.append(spot);
	temp.append("\n");
	temp.append("|| ");
	temp.append(spot);
	temp.append(", ");
	temp.append($1.place);
	temp.append(", ");
	temp.append($3.place);
	temp.append("\n");

	$$.code = strdup(temp.c_str());
	$$.place = strdup(spot.c_str());

} | RelationAndExpr {
	$$.place = strdup($1.place);
	$$.code = strdup($1.code);
}
;

RelationAndExpr: RelationExpr AND RelationAndExpr {

	std::string spot = newTemp();
	std::string temp;
	temp.append($1.code);
	temp.append($3.code);
	temp.append(". ");
	temp.append(spot);
	temp.append("\n");
	temp.append("&& ");
	temp.append(spot);
	temp.append(", ");
	temp.append($1.place);
	temp.append(", ");
	temp.append($3.place);
	temp.append("\n");

	$$.code = strdup(temp.c_str());
	$$.place = strdup(spot.c_str());

} | RelationExpr {

	$$.place = strdup($1.place);
	$$.code = strdup($1.code);

}
;

RelationExpr: RelationExpr0 {
	$$.code = strdup($1.code);
	$$.place = strdup($1.place);
} | NOT RelationExpr0 {
	std::string x = newTemp();
	std::string temp;
	temp.append($2.code);
	temp.append(". ");
	temp.append(x);
	temp.append("\n");
	temp.append("! ");
	temp.append(x);
	temp.append(", ");
	temp.append($2.place);
	temp.append("\n");
	$$.code = strdup(temp.c_str());
	$$.place = strdup(x.c_str());
}
;

RelationExpr0: L_PAREN BoolExpr R_PAREN {
	$$.code = strdup($2.code);
	$$.place = strdup($2.place);
} | FALSE {
	char temp[2] = "0";
	$$.code = strdup(nothing);
	$$.place = strdup(temp);
} | TRUE {
	char temp[2] = "1";
	$$.code = strdup(nothing);
	$$.place = strdup(temp);
} | Expression Comp Expression {
	//still need to finish to be done with RExp0
}
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

LocalIdent:   IDENT {
//check for errors if time

	variables.insert(std::pair<std::string,int>(variable, 0));
	$$.place = strdup($1);
	$$.code = strdup(nothing); 
}
;

FunctionIdent:  IDENT {
//check for errors if time

	functions.insert(std::pair<std::string,int>($1, 0));
	$$.place = strdup($1);
	$$.code = strdup(nothing); 
}
;


%%

void yyerror(const char* x) {
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





