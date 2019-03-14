grammar ExprCppTree;

options {
    language = C;
    output = AST;
    ASTLabelType=pANTLR3_BASE_TREE;
}

@header {
    #include <assert.h>
}

// The suffix '^' means make it a root.
// The suffix '!' means ignore it.
/*
OR : '||';  
AND : '&&';  
EQ : '==';  
NEQ : '!=';  
GT : '>';  
LT : '<';  
GTEQ : '>=';  
LTEQ : '<=';  
PLUS : '+';  
MINUS : '-';  
MULT : '*';  
DIV : '/';  
MOD : '%';  
POW : '^';  
NOT : '!';  
  
SCOL : ';';  
ASSIGN : '=';  
OPAR : '(';  
CPAR : ')';  
OBRACE : '{';  
CBRACE : '}';  
  
TRUE : 'true';  
FALSE : 'false';  
NIL : 'nil';  
IF : 'if';  
ELSE : 'else';  
WHILE : 'while';  
LOG : 'log';  
*/
DOT: ',';
ASSIGN: '=';
PLUS: '+';
DIV: '/';
MINUS: '-';
TIMES: '*';
ID: ('a'..'z'|'A'..'Z')+ ;
INT: '~'? '0'..'9'+ ;
NEWLINE: '\r'? '\n' ;
WS : (' '|'\t')+ {$channel = HIDDEN;}; 

dotExpr: assignExpr ((DOT^) assignExpr)*
    ;
    
assignExpr: expr
    | ID ASSIGN expr -> ^(ASSIGN ID expr)
    ;

expr: multExpr ((PLUS^ | MINUS^) multExpr)*
    ;

multExpr: atom ((TIMES^ | DIV^) atom)*
    ;

atom: INT
    | ID
    | '('! dotExpr ')'!
    ;

//stmt = statement语句解析规则
stmt: dotExpr NEWLINE -> dotExpr  // tree rewrite syntax
    //| ID ASSIGN dot NEWLINE -> ^(ASSIGN ID dot) // tree notation
    | NEWLINE ->   // ignore
    | block
    ;

block: '{' block_body '}' NEWLINE -> ^(BLOCK block_body);

block_body: (stmt)*;

BLOCK: '.';

prog
    : (stmt {pANTLR3_STRING s = $stmt.tree->toStringTree($stmt.tree);
             assert(s->chars);
             printf(" tree \%s\n", s->chars);
            }
        )+
    ;
