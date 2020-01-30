minil: compile.lex
        flex phase1.flex
        gcc lex.yy.c -lfl -o minil
        rm -f lex.yy.c

clean:
        rm -f minil *~
