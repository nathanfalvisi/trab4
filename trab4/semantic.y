	%{ 
	/* Para simplificar a notação, S é para sintetizar. A atualizar. V verificar */
	#include "analex.c" 
	#include "codigo.h" 
	#define Funct 4
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
		TypeF ID '(' ParamList ')' '{' Decls Statement_Seq '}'  {} /* A. Tabela. S código. */
		| TypeF ID '(' ')' '{' Decls Statement_Seq '}' {} /* A. Tabela. S código. */
		;
		
	FunctionCall :
		ID '(' ArgList ')' {   
			verifica_funcao_declarada($1);
        	verifica_numero_argumentos($1, $3.tam);
        	create_cod(&$$.code);
        	insert_cod(&$$.code, $3.code);} /* V declaração, # argumentos. S código*/
		| ID '(' ')' {        
			verifica_funcao_declarada($1);
        	verifica_numero_argumentos($1, 0);
        	create_cod(&$$.code);} /* V declaração, # argumentos. S código*/
		;
		
	ArgList:
		Exp ',' ArgList {} /* S código e Lista de IDs*/
		| Exp  {} /* S código e Lista de IDs*/
		;

	ParamList: 
		ParamList ',' Type ID  {} /* S Lista de IDs. A Tabela*/
		| Type ID {} /* S Lista de IDs. A Tabela*/
		; 
			
	Decls:
		Decl ';' Decls  
		| 
		;

	Decl:
		Type IDs {for(int i=0; i< $2.tam; i++) Tabela[$2.ids[i]].tipo = $1;} /* A tabela. */
		; 
		
	IDs :
		IDs ',' ID {} /* S Lista de IDs. */
		| IDs ',' Atribuicao {} /* S Lista de IDs. */
		| IDs ',' ID '[' NUM ']' {} /* S Lista de IDs. */
		| ID '[' NUM ']' {} /* S Lista de IDs. */
		| ID {} /* S Lista de IDs. */
		| Atribuicao {} /* S Lista de IDs. */
		;
		
	TypeF :
		VOID {$$ = VOID;} /* S Tipo. */
		| Type
		;

	Type :
		INT {$$ = INT;} /* S Tipo. */
		| CHAR {$$ = CHAR;} /* S Tipo. */
		| FLOAT {$$ = FLOAT;} /* S Tipo. */
		;
				
	Statement_Seq :
		Statement Statement_Seq {create_cod(&$$.code); insert_cod(&$$.code,$1.code); insert_cod(&$$.code,$2.code);} /* S Codigo. */
		| Statement {create_cod(&$$.code); insert_cod(&$$.code,$1.code);} /* S Codigo. Exemplo */
		;
			
	Statement:
		Atribuicao ';' {verifica_var_declarada($1.place); verifica_tipos_atrib(Tabela[$1.place].tipo, $1.tipo);} /* V declaracao, tipos atribuicao. */		
	  	| If { 
        create_cod(&$$.code); 
        insert_cod(&$$.code, $1.code);  // Copia o código gerado para o If
    	} 
    	| While { 
        create_cod(&$$.code); 
        insert_cod(&$$.code, $1.code);  // Copia o código gerado para o While
    	} 
    	| DoWhile { 
        create_cod(&$$.code); 
        insert_cod(&$$.code, $1.code);  // Copia o código gerado para o DoWhile
    	} 
    	| FunctionCall ';' {}
		;

	Compound_Stt :
		Statement {}/* S código. Exemplo resolvido */
		| '{' Statement_Seq '}' {}  /* S código. Exemplo resolvido */
		;
			
	If :
		IF '(' Exp ')' Compound_Stt ENDIF {If(&$$, $3, $5);} /* S código. Exemplo */
		| IF '(' Exp ')' Compound_Stt ELSE Compound_Stt ENDIF {IfElse(&$$,$3,$5,$7);} /* S código. */
		;

	While:
		WHILE '(' Exp ')' Compound_Stt  {While(&$$, $3, $5);} /* S código. */
		;

	DoWhile:
		DO Compound_Stt WHILE '(' Exp ')' ';' {While(&$$, $2, $5);} /* S código. */
		;
				
	Atribuicao : ID '[' NUM ']' '=' Exp {Atrib(&$$, $1, $6);} /* V tipo indice. S tipo, place, código. */
		| ID '=' Exp {Atrib(&$$, $1, $3);} /* S tipo, place, código. */
		;
					
	Exp :
		Exp '+' Exp {Exp_Ari(&$$, $1, $3,"add");} /* S tipo, cod */
		| Exp '-' Exp {Exp_Ari(&$$, $1, $3, "sub");} /* S tipo, cod */
		| Exp '*' Exp {Exp_Ari(&$$, $1, $3, "mul");} /* S tipo, cod */
		| Exp '/' Exp {Exp_Ari(&$$, $1, $3, "div");} /* S tipo, cod */
		| Exp '>' Exp {Exp_Rel(&$$, $1, $3, "bgt");} /* S tipo, cod (bgt) */
		| Exp '<' Exp {Exp_Rel(&$$, $1, $3, "blt");} /* S tipo, cod (blt) */
		| Exp GE Exp {$$.tipo = INT;} /*  S tipo. Não precisa implementar código*/
		| Exp LE Exp {$$.tipo = INT;} /*  S tipo. Não precisa implementar código*/
		| Exp EQ Exp {$$.tipo = INT;} /*  S tipo. Não precisa implementar código*/
		| Exp NEQ Exp {$$.tipo = INT;} /*  S tipo. Não precisa implementar código*/
		| Exp OR Exp {Exp_Log(&$$, $1, $3, "or");} /* S tipo, cod */
		| Exp AND Exp {Exp_Log(&$$, $1, $3, "and");} /* S tipo, cod */
		| NOT Exp {$2.tipo = INT;} /*  S tipo. Não precisa implementar código*/
		| '(' Exp ')' {$$ = $2;} /*  S tipo, cod*/
		| NUM {Li(&$$, $1.place);} /* S tipo, código */
		| ID '[' NUM ']' {}  /* V declaracao, indice. S tipo, codigo  */
		| ID  {create_cod(&$$.code); $$.place = $1;} /* V declaracao. S tipo, codigo  */
		| STRING {} /* Ignore, não precisa implementar  */
		;   
		
		
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
