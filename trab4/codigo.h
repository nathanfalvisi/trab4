#include "semantic.h"
#include "listacodigo.h"

int temp=-1;
int newTemp() {
	return temp--;
}

void freeTemp() {
	temp++;
}
int label = 0;
int newLabel() {
	return ++label;
}

char reg1[5];
char reg2[5];
char reg_temp[5];
void getName(int num, char *name) {
  if (num >= 0 ) {
    sprintf(name,"$s%d",num);
  }
  else 
    sprintf(name,"$t%d",-(num+1));
}

/* Geração de código para criar uma função. Exemplo */
void Funct(struct no* Funct, int Id, struct no Comandos) {
	create_cod(&Funct->code);
	obtemNome(Id);
	sprintf(instrucao,"%s:\n",nome);
	insert_cod(&Funct->code,instrucao);
	insert_cod(&Funct->code,Comandos.code);
	if (strcmp(nome,"main")==0) {
		sprintf(instrucao,"\tli $v0,10\n"); //Define exit
		insert_cod(&Funct->code,instrucao);
		sprintf(instrucao,"\tsyscall\n\n"); //Call exit
		insert_cod(&Funct->code,instrucao);					
	}
	else {
		sprintf(instrucao,"\tjr $ra\n\n"); //Return to previous function
		insert_cod(&Funct->code,instrucao);

	}
}

/* Função pre-implementada para lidar com argumentos de forma simples */
void adiciona_argumentos(char **code, int id, struct ids Args){
  struct symbol simbolo = Tabela[id];
  char name_param[5];
  char name_arg[5];
  for(int i = 0; i<simbolo.tam_arg_list;i++){
    getName(simbolo.arg_list[i], name_param);
    getName(Args.ids[i], name_arg);
    sprintf(instrucao,"\tmove %s,%s\n",name_param,name_arg);
	  insert_cod(code,instrucao);
  }
}

/* Geração de código para chamada de função */
void Call(struct no* Call, int Id, struct ids Args) {
	???
  	adiciona_argumentos(&Call->code, Id, Args);
	???
}


/* Geração de código para chamada de função sem argumentos */
void Call_blank(?) {
	???
}

/* Geração de código para atribuições */
void Atrib(?) {
	???
}

/* Geração de código para carregar constantes */
void Li(struct no *Exp, int num) {
	char name_dest[5];
	create_cod(&Exp->code);
	Exp->place = newTemp();
	getName(Exp->place,name_dest);
	sprintf(instrucao,"\tli %s,%d\n",name_dest,num);
	insert_cod(&Exp->code,instrucao);
}

/* Geração de código para qualquer expressão aritmética referente parâmetros */
void ExpAri(struct no *Exp, struct no Exp1, struct no Exp2) {
	char name_reg1[5];
	char name_reg2[5];
	char name_temp[5];
	Exp->place = newTemp();
	create_cod(&Exp->code);
	insert_cod(&Exp->code,Exp1.code);
	insert_cod(&Exp->code,Exp2.code);
	getName(Exp1.place,name_reg1);
	getName(Exp2.place,name_reg2);
	getName(Exp->place,name_temp);
	sprintf(instrucao,"\t add %s,%s,%s\n",name_temp,name_reg1, name_reg2);
	insert_cod(&Exp->code,instrucao);
}

/* Geração de código para qualquer expressão relacional referente parâmetros */
void ExpRel(?) { 
	???
}

/* Geração de código para ifs sem else */
void If(?)  {  
	???
}


/* Geração de código para ifs com else */
void IfElse(?) {  
	???
}


/* Geração de código para whiles */
void While(?) {  
	???
}


/* Geração de código para do whiles */
void DoWhile(?) {  
	???
}

/*
void Bgt(struct no *Exp, struct no Exp1, struct no Exp2) {
	char name_reg1[5];
	char name_reg2[5];
	char name_temp[5];
	Exp->place = newTemp();
	getName(Exp->place,name_temp);
	create_cod(&Exp->code);
	insert_cod(&Exp->code,Exp1.code);
	insert_cod(&Exp->code,Exp2.code);
	getName(Exp1.place,name_reg1);
	getName(Exp2.place,name_reg2);
	getName(Exp->place,name_temp);
	sprintf(instrucao,"\tli %s,1\n",name_temp);
	insert_cod(&Exp->code,instrucao);
	newLabel();
	sprintf(instrucao,"\t%s,%s,%s,L%d\n",branch, name_reg1,name_reg2,label);
	insert_cod(&Exp->code,instrucao);
	sprintf(instrucao,"\tli %s,0\n",name_temp);
	insert_cod(&Exp->code,instrucao);
	sprintf(instrucao,"L%d:\n",label);
	insert_cod(&Exp->code,instrucao);
}

int rtd(int t1, int t2){
	if (t1 == DOUBLE || t2 == DOUBLE)
	return DOUBLE;
	if (t1 == FLOAT || t2 == FLOAT)
	return FLOAT;
	if (t1 == INT || t2 == INT)
	return INT;
	if (t1 == CHAR || t2 == CHAR)
	return CHAR;
} */