%{

int LineRow = 1;
int LinCol = 0;

#include "y.tab.h" 
/*
static const char* KeyWords[] = {
"if", "endif", "else", "then", "true", "false", "return", "and", "or", "not", "read", "write", "beginloop", "endloop", "continue", "in", "while", "do", "for", "of", "beginbody", "endbody", "integer", "array", "function", "beginparms", "endparams", "beginlocals", "endlocals" };
static const char* MapWords[] = {
"IF", "ENDIF", "ELSE", "THEN", "TRUE", "FALSE", "RETURN", "AND", "OR", "NOT",
"READ", "WRITE", "BEGIN_LOOP", "END_LOOP", "CONTINUE", "IN", "WHILE", "DO", "FOR",
"OF", "BEGIN_BODY", "END_BODY", "INTEGER", "ARRAY", "FUNCTION", "BEGIN_PARMS", "END_PARMS",
"BEGIN_LOCALS", "END_LOCALS" };
const int NumWords = sizeof(KeyWords)/ sizeof(KeyWords[0]);
*/
%}

NEWLINE [\n]
WHITESPACE [\t ]
DIGIT [0-9]
DIGIT_UNDERSCORE [0-9_]
LETTER [a-zA-Z]
LETTER_UNDERSCORE [a-zA-Z_]
ALPHANUMBER [0-9a-zA-Z]
CHAR [0-9a-zA-Z_]

%%

"+"   {return ADD; ++LinCol;}
"-"   {return SUB; ++LinCol;}
"/"   {return DIV; ++LinCol;}
"*"   {return MULT; ++LinCol;}
"%"   {return MOD; ++LinCol;}
">"   {return GT; ++LinCol;}
"<"   {return LT; ++LinCol;}

">="   {return GTE; ++LinCol;}
"<="   {return LTE; ++LinCol;}
"=="   {return EQ; ++LinCol;}
"<>"   {return NEQ; ++LinCol;}
":="   {return ASSIGN; LinCol += 2;}
";"   {return SEMICOLON; ++LinCol;}
"("   {return L_PAREN; ++LinCol;}
")"   {return R_PAREN; ++LinCol;}
"["   {return L_SQUARE_BRACKET; ++LinCol;}
"]"   {return R_SQUARE_BRACKET; ++LinCol;}
","   {return COMMA; ++LinCol;}
":"   {return COLON; ++LinCol;}

"function" {return FUNCTION; LinCol += yyleng;}
"continue" {return CONTINUE; LinCol += yyleng;}
"return" {return RETURN; LinCol += yyleng;}
"write" {return WRITE; LinCol += yyleng;}
"read" {return READ; LinCol += yyleng;}
"or" {return OR; LinCol += yyleng;}
"and" {return AND; LinCol += yyleng;}
"not" {return NOT; LinCol += yyleng;}
"false" {return FALSE; LinCol += yyleng;}
"true" {return TRUE; LinCol += yyleng;}
"do" {return DO; LinCol += yyleng;}
"while" {return WHILE; LinCol += yyleng;}
"beginloop" {return BEGIN_LOOP; LinCol += yyleng;}
"endloop" {return END_LOOP; LinCol += yyleng;}
"foreach" {return FOREACH; LinCol += yyleng;}
"in" {return IN; LinCol += yyleng;}
"if" {return IF; LinCol += yyleng;}
"then" {return THEN; LinCol += yyleng;}
"else" {return ELSE; LinCol += yyleng;}
"endif" {return ENDIF; LinCol += yyleng;}
"beginbody" {return BEGIN_BODY; LinCol += yyleng;}
"endbody" {return END_BODY; LinCol += yyleng;}
"beginparams" {return BEGIN_PARAMS; LinCol += yyleng;}
"endparams" {return END_PARAMS; LinCol += yyleng;}
"beginlocals" {return BEGIN_LOCALS; LinCol += yyleng;}
"endlocals" {return END_LOCALS; LinCol += yyleng;}
"array" {return ARRAY; LinCol += yyleng;}
"of" {return OF; LinCol += yyleng;}
"integer" {return INTEGER; LinCol += yyleng;}

{NEWLINE}+      {LineRow += yyleng; LinCol = 0;}
{WHITESPACE}+   {LinCol += yyleng;}

"##".*{NEWLINE} {LinCol = 0; ++LineRow;}

{LETTER}({CHAR}*{ALPHANUMBER}+)? {

yylval.ident_val = yytext;
return IDENT;
LinCol += yyleng;

 }

{DIGIT}+ {

yylval.number_val = atoi(yytext);
return NUMBER;
LinCol += yyleng;
}

{LETTER}({CHAR}*ALPHANUMBER+)?"_" {
printf("Error at line %d, column %d: Identifier %s can't end with an underscore \n", LineRow, LinCol, yytext);
exit(1);
}

({DIGIT}+{LETTER_UNDERSCORE}{CHAR}*)|("_"{CHAR}+) {
printf("Error at line %d, column %d: Identifier %s must begin with a letter \n", LineRow, LinCol, yytext);
exit(1);

}

. {
printf("Error at line %d, column %d: unrecognized symbol %s\n", LineRow, LinCol, yytext);
exit(1);

}

%%
int yyparse();

int main(int argc, char* argv[]){

if (argc == 2){
yyin = fopen(argv[1], "r");
if(yyin == 0){
printf("Error with file: %s\n", argv[1]);
exit(1);
}
}
else {
  yyin = stdin;
}
  yyparse();

  return 0;
}

