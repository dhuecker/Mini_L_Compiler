mini_l: test.lex test2.y
	bison -v -d --file-prefix=y test2.y
	flex test.lex
	gcc -o parser y.tab.c lex.yy.c -lfl

