%{
#include "../../include/IR.h"
#include "../../include/actions.h"
#include "lex.yy.c"
extern double yylval_doubletmp;
extern int yylval_inttmp;
int yyerror(char*);
YYSTYPE myroot;
%}
%token Id INTEGER FLOAT DELIM WHITESPACE

%left '+' '-'
%left '*' '/' EXACTLYDIVIDE '%'
%nonassoc '='

%%
P :  P S {printf("happy");}
    |S {;}
    ;

S : LHS '=' RHS ';' {myroot=$3;}

LHS : TRef


RHS: RHS '+' RHS {$$=RHS_1($1,$3);}
    |RHS '*' RHS {$$=RHS_2($1,$3);}
    |RHS '-' RHS {$$=RHS_3($1,$3);}
    |RHS '/' RHS {$$=RHS_4($1,$3);} 
    |RHS '%' RHS {$$=RHS_5($1,$3);} 
    |RHS EXACTLYDIVIDE RHS {$$=RHS_6($1,$3);}
    |TRef {$$=RHS_7($1);}
    |SRef {$$=RHS_7($1);}
    |Const {$$=RHS_8($1);}
    |'(' RHS ')' {$$=RHS_9($2);}
    ;
    
TRef : Id '<' Clist '>' '[' Alist ']' {;}

SRef : Id '<' Clist '>' {;}

Clist :  Clist ',' INTEGER {$$=Clist_action_1($1,$3);}
        |INTEGER {$$=Clist_action_2($1);}
        ;
Alist :  Alist ',' IdExpr {$$=Alist_action_1($1,$3);}
        |IdExpr {$$=Alist_action_2($1);}
        ;

IdExpr : Id {$$=$1;}
        |IdExpr '+' IdExpr {;}
        |IdExpr '+' INTEGER {;}
        |IdExpr '*' INTEGER {;}
        |IdExpr EXACTLYDIVIDE INTEGER {;}
        |IdExpr '%' INTEGER {;}
        ;

Const :  FLOAT {$$=$1;}
        |INTEGER {$$=$1;}
        ;

%%
YYSTYPE yyparse_string(char * str)
{
        yy_switch_to_buffer(yy_scan_string(str));
        yyparse();
        return myroot;
}
int yyerror(char* s)
{
    printf("%s",s);
    return 0;
}

