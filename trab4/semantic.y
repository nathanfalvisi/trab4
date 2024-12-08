	%{ 
	/* Para simplificar a notação, S é para sintetizar. A atualizar. V verificar */
	#include "analex.c" 
	#include "codigo.h"
	/* Funcoes auxiliares podem ser declaradas aqui */
	void verifica_var_declarada(int id);
	void verifica_funcao_declarada(int id);
	void verifica_tipos_atrib(int tipo1, int tipo2);
	void verifica_numero_argumentos(int id, int num_args);
	void verifica_indice_valido(int id, int indice);
		
	%}

	%union{
		struct no{
			int place;
			char *code;
			int tipo;
		} node;
		int val;
		struct ids{
			int ids[50];
			int tam;
			char *code;
		} id_list;
	}

	%token <node> NUM
	%token <val> ID 
	%token WHILE
	%token IF 
	%token ELSE
	%token ENDIF
	%token CHAR
	%token INT
	%token FLOAT
	%token VOID
	%token OR
	%token AND
	%token NOT
	%token GE
	%token LE
	%token EQ
	%token NEQ
	%token DO
	%token STRING

	%type <val> Type TypeF
	%type <id_list> IDs ParamList ArgList
	%type <node> Decls Decl
	%type <node> Atribuicao Exp Function Prog Statement Statement_Seq
	%type <node> If While Compound_Stt DoWhile FunctionCall

	%right '='

	%left OR
	%left AND

	%nonassoc EQ NEQ

	%left '>' '<' GE LE

	%left '+' '-'
	%left '*' '/' '%'

	%right NOT

	%right '(' '['


	%start ProgL
	%% 
	ProgL : Prog {printf("%s",$1.code);} /* S código. */
		;
		
	Prog : Prog Function {create_cod(&$$.code); insert_cod(&$$.code,$1.code); insert_cod(&$$.code,$2.code);} /* S código. */
		| Function {} /* S código. */
		;	

	Function :
    TypeF ID '(' ParamList ')' '{' Decls Statement_Seq '}' {
        adiciona_funcao_tabela(obtemNome($2), $1, &$4);
        create_cod(&$$.code);
    }
    | TypeF ID '(' ')' '{' Decls Statement_Seq '}' {
        adiciona_funcao_tabela(obtemNome($2), $1, NULL); 
        Funct(&$$, $2, $7);                
    }
    ;
		
FunctionCall :
    ID '(' ArgList ')' {
        int funcPos = $1; 
        if (funcPos == -1) {
            yyerror("Função não declarada!");
        } else if (Tabela[funcPos].tam_arg_list != $3.tam) {
            yyerror("Número de argumentos incompatível!");
        }
        Call(&$$, funcPos, &$3);
    } /* V declaração, # argumentos. S código*/
    | ID '(' ')' {
        int funcPos = procura(obtemNome($1));
        if (funcPos == -1) {
            yyerror("Função não declarada!");
        } else if (Tabela[funcPos].tam_arg_list != 0) {
            yyerror("Número de argumentos incompatível!");
        }
        Call_blank(&$$);
    } /* V declaração, # argumentos. S código*/
    ;
		
ArgList:
    Exp ',' ArgList {
        create_cod(&$$.code);
        $$.tam = $3.tam + 1; 
        $$.ids[0] = $1.place; 
        for (int i = 0; i < $3.tam; i++) 
        {
            $$.ids[i + 1] = $3.ids[i];
        }
        insert_cod(&$$.code, $1.code);
        insert_cod(&$$.code, $3.code);
    } /* S código e Lista de IDs*/
    | Exp {
        create_cod(&$$.code);
        $$.tam = 1;
        $$.ids[0] = $1.place;
        insert_cod(&$$.code, $1.code);
    } /* S código e Lista de IDs*/
    ;
ParamList: 
    ParamList ',' Type ID {
        $$.ids[$$.tam] = insere(obtemNome($4));
        if(getTipo($4) == -1)
            set_type($$.ids[$$.tam], $3);
        else 
            if(getTipo($4) != $3)
                yyerror("Tipos de argumentos incompatíveis!");
        $$.tam++;
    } /* S Lista de IDs. A Tabela*/
    | Type ID {
        $$.ids[$$.tam] = insere(obtemNome($2));
        if(getTipo($2) == -1)
            set_type($$.ids[$$.tam], $1);
        else 
            if(getTipo($2) != $1)
                yyerror("Tipos de argumentos incompatíveis!");
        } /* S Lista de IDs. A Tabela*/
    ;
		
Decls:
    Decl ';' Decls {
        create_cod(&$$.code);
        insert_cod(&$$.code, $1.code);
        insert_cod(&$$.code, $3.code);
    }
    | Decl {
        create_cod(&$$.code);
        insert_cod(&$$.code, $1.code);
    }
    ;

Decl:
    Type IDs {
        int tipo;
        create_cod(&$$.code);
        if ($2.code != NULL)
            insert_cod(&$$.code, $2.code);
        for (int i = 0; i < $2.tam; i++) 
        {
            tipo = getTipo($2.ids[i]);
            if(tipo != $1)
                yyerror("Erro Semântico");
            set_type($2.ids[i], $1);
        }
    } /* A tabela. */
    ;

	
IDs : 
    IDs ',' ID {
        $$.ids[$$.tam] = procura(obtemNome($3));
        $$.tam++;
    }
    | IDs ',' Atribuicao {
        int pos = procura(obtemNome($3.place));
        create_cod(&$$.code);
        insert_cod(&$$.code, $3.code);
        $$.ids[$$.tam] = pos;
        $$.tam++;
    }
    | IDs ',' ID '[' NUM ']' {
        $$.ids[$$.tam] = procura(obtemNome($3));
        $$.tam++;
    }
    | ID '[' NUM ']' {
        $$.ids[$$.tam] = procura(obtemNome($1));
    }
    | ID {
        $$.ids[$$.tam] = procura(obtemNome($1));
    }
    | Atribuicao {
        int pos = procura(obtemNome($1.place));
        create_cod(&$$.code);
        insert_cod(&$$.code, $1.code);
        $$.ids[$$.tam] = pos;
    }
    ;

	
TypeF :
	  VOID {$$ = VOID;} /* S Tipo. */
	| Type {$$ = $1;}
	;

Type :
	  INT {$$ = INT;} /* S Tipo. */
	| CHAR {$$ = CHAR;} /* S Tipo. */
	| FLOAT {$$ = FLOAT;} /* S Tipo. */
	;
			
Statement_Seq :
    Statement Statement_Seq {
        create_cod(&$$.code);
        insert_cod(&$$.code, $1.code);
        insert_cod(&$$.code, $2.code);
    } /* S Codigo. */
    | Statement {
        create_cod(&$$.code);
        insert_cod(&$$.code, $1.code);
    } /* S Codigo. Exemplo */
    ;

		
Statement: 
	  Atribuicao ';' {
        procura(obtemNome($1.place));
        rtd(Tabela[$1.place].tipo, $1.tipo);
    } /* V declaracao, tipos atribuicao. */
	| If  /* S código. */
	| While /* S código. */
	| DoWhile /* S código. */
	| FunctionCall ';'  /* S código. */
	;

Compound_Stt :
	  Statement  /* S código. Exemplo resolvido */
	| '{' Statement_Seq '}' {$$ = $2;}  /* S código. Exemplo resolvido */
	;
		
If :
	  IF '(' Exp ')' Compound_Stt ENDIF { 
		If(&$$, $3,$5);
	} /* S código. Exemplo */
	| IF '(' Exp ')' Compound_Stt ELSE Compound_Stt ENDIF {
		IfElse(&$$, $3, $5, $7);
	} /* S código. */
	;

While:
    WHILE '(' Exp ')' Compound_Stt {
        While(&$$, $3, $5);
    }
    ;

DoWhile:
    DO Compound_Stt WHILE '(' Exp ')' ';' {
        DoWhile(&$$, $2, $5);
    }
    ;

			
Atribuicao : 
	ID '[' NUM ']' '=' Exp {
    	if (procura(obtemNome($1)) != -1)
    		Atrib(&$$, $3);
    	else
    		yyerror("Erro Semântico");

        $$.tipo = rtd(getTipo($1), $6.tipo);
	} /* V tipo indice. S tipo, place, código. */
    | ID '=' Exp {
    	if (procura(obtemNome($1)) != -1)
    		Atrib(&$$, $3);
    	else
    		yyerror("Erro Semântico");

        $$.tipo = rtd(getTipo($1), $3.tipo);
    } /* S tipo, place, código. */
	;
					
	Exp :
		Exp '+' Exp {$$.tipo = rtd($1.tipo, $3.tipo); Exp_Ari(&$$, $1, $3,"add");} /* S tipo, cod */
		| Exp '-' Exp {$$.tipo = rtd($1.tipo, $3.tipo); Exp_Ari(&$$, $1, $3, "sub");} /* S tipo, cod */
		| Exp '*' Exp {$$.tipo = rtd($1.tipo, $3.tipo); Exp_Ari(&$$, $1, $3, "mul");} /* S tipo, cod */
		| Exp '/' Exp {$$.tipo = rtd($1.tipo, $3.tipo);Exp_Ari(&$$, $1, $3, "div");} /* S tipo, cod */
		| Exp '>' Exp {$$.tipo = rtd($1.tipo, $3.tipo); Exp_Rel(&$$, $1, $3, "bgt");} /* S tipo, cod (bgt) */
		| Exp '<' Exp {$$.tipo = rtd($1.tipo, $3.tipo); Exp_Rel(&$$, $1, $3, "blt");} /* S tipo, cod (blt) */
		| Exp GE Exp {$$.tipo = INT;} /*  S tipo. Não precisa implementar código*/
		| Exp LE Exp {$$.tipo = INT;} /*  S tipo. Não precisa implementar código*/
		| Exp EQ Exp {$$.tipo = INT;} /*  S tipo. Não precisa implementar código*/
		| Exp NEQ Exp {$$.tipo = INT;} /*  S tipo. Não precisa implementar código*/
		| Exp OR Exp {$$.tipo = INT; Exp_Log(&$$, $1, $3, "or");} /* S tipo, cod */
		| Exp AND Exp {$$.tipo = INT; Exp_Log(&$$, $1, $3, "and");} /* S tipo, cod */
		| NOT Exp {$$.tipo = INT;} /*  S tipo. Não precisa implementar código*/
		| '(' Exp ')' {
			$$.tipo = $2.tipo;
		} /*  S tipo, cod*/
		| NUM {$$ = $1;} /* S tipo, código */
		| FLOAT {$$.tipo = FLOAT;}
		| ID '[' NUM ']' {}  /* V declaracao, indice. S tipo, codigo  */
		| ID  {
        	$$.tipo = getTipo($1);
        	if($$.tipo == -1)
        {
            yyerror("Erro Semântico, var não declarada");
        } 
	}
		
		
	%%  
	int main(int argc, char **argv) {     
	yyin = fopen(argv[1],"r");
	yyparse();      
	} 

	/* Funcoes auxiliares podem ser implementadas aqui */
	void verifica_var_declarada(int id) {
		if (Tabela[id].tipo == 0) { 
			fprintf(stderr, "Erro: Variável %s não foi declarada.\n", Tabela[id].nome);
			exit(1); 
		}
	}

	void verifica_funcao_declarada(int id) {
		if (Tabela[id].tipo != Funct) {
			fprintf(stderr, "Erro: Função %s não foi declarada.\n", Tabela[id].nome);
			exit(1);
		}
	}

	void verifica_tipos_atrib(int tipo1, int tipo2) {
		if (tipo1 != tipo2) {
			fprintf(stderr, "Erro: Tipos incompatíveis na atribuição.\n");
			exit(1);
		}
	}

	void verifica_numero_argumentos(int id, int num_args) {
		if (Tabela[id].tam_arg_list != num_args) {
			fprintf(stderr, "Erro: Função %s esperava %d argumentos, mas recebeu %d.\n",
					Tabela[id].nome, Tabela[id].tam_arg_list, num_args);
			exit(1);
		}
	}

	void verifica_indice_valido(int id, int indice) {
		if (indice < 0 || indice >= Tabela[id].tam) {
			fprintf(stderr, "Erro: Índice %d fora dos limites do vetor %s.\n", indice, Tabela[id].nome);
			exit(1);
		}
	}
