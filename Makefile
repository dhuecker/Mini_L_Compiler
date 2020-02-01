minil: phase1.lex
        flex mini_l.lex
        gcc -o lexer lex.yy.c
        rm -f lex.yy.c

clean:
        rm -f lexer *~
