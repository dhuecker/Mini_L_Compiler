%{

int LineRow = 1;
int LinCol = 0;



static const char* KeyWords[] = {
"if", "endif", "else", "then", "true", "false", "return", "and", "or", "not", "read", "write", "beginloop", "endloop", "continue", "in", "while", "do", "foreach", "of", "beginbody", "endbody", "integer", "array", "function", "beginparms", "endparams", "beginlocals", "endlocals" };

static const char* MapWords[] = {
"IF", "ENDIF", "ELSE", "THEN", "TRUE", "FALSE", "RETURN", "AND", "OR", "NOT",
"READ", "WRITE", "BEGINLOOP", "ENDLOOP", "CONTINUE", "IN", "WHILE", "DO", "FOREACH",
"OF", "BEGINBODY", "ENDBODY", "INTEGER", "ARRAY", "FUNCTION", "BEGINPARMS", "ENDPARMS",
"BEGINLOCALS", "ENDLOCALS" };

const int NumWords = sizeof(KeyWords)/ sizeof(KeyWords[0]);

%}

NEWLINE [\n]
WHITESPACE [\t]
DIGIT [0-9]
DIGIT_UNDERSCORE [0-9_]
LETTER [a-zA-Z]
LETTER_UNDERSCORE [a-zA-Z_]
ALPHANUMBER [0-9a-zA-Z]
CHAR [0-9a-zA-Z_]

%%

"+"   {printf("ADD\n"); ++LinCol;}
"-"   {printf("SUB\n"); ++LinCol;}
"/"   {printf("DIV\n"); ++LinCol;}
"*"   {printf("MULT\n"); ++LinCol;}
"%"   {printf("MOD\n"); ++LinCol;}
">"   {printf("GT\n"); ++LinCol;}
"<"   {printf("LT\n"); ++LinCol;}

">="   {printf("GTE\n"); ++LinCol;}
"<="   {printf("LTE\n"); ++LinCol;}
"=="   {printf("EQ\n"); ++LinCol;}
"<>"   {printf("NEQ\n"); ++LinCol;}
":="   {printf("ASSIGN\n"); LinCol += 2;}
";"   {printf("SEMICOLON\n"); ++LinCol;}
"("   {printf("L_PAREN\n"); ++LinCol;}
")"   {printf("R_PAREN\n"); ++LinCol;}
"["   {printf("L_SQUARE_BRACKET\n"); ++LinCol;}
"]"   {printf("R_SQUARE_BRACKET\n"); ++LinCol;}
","   {printf("COMMA\n"); ++LinCol;}
":"   {printf("COLON\n"); ++LinCol;}



{NEWLINE}+      {LineRow += yyleng; LinCol = 0;}
{WHITESPACE}+   {LinCol += yyleng;}

"##".*{NEWLINE} {LinCol = 0; ++LineRow;}

{LETTER}({CHAR}*{ALPHANUMBER}+)? {

int i = 0;
//int stop = 0;
char temp = 0;

for(; i < NumWords; ++i){

//if (stop == 0){
if(strcmp(yytext, KeyWords[i]) == 0){
printf("%s\n", MapWords[i]);
temp = 1;
//stop = 1;
  }
//}

}

if (temp == 0){
  printf("IDENT %s\n", yytext);
}
LinCol += yyleng;

 }

{DIGIT}+ {

printf("NUMBER %s\n", yytext);
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

int main(int argc, char ** argv){

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
  yylex();

  return 0;
}


