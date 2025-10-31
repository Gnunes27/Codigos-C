#ifndef CLIENTES_H
#define CLIENTES_H

#include "object.h"
#include "list.h"

typedef struct{
	char nome[20];
	int idade;
	int id;
}_Cliente;

typedef _Cliente* Cliente;

void print_Cliente();
int get_id_Cliente();

Object new_Cliente(char* nome, int idade, int id){
	
	Cliente p = malloc(sizeof(_Cliente));
	strcpy(p->nome, nome);
	p->idade = idade;
	p->id = id;
	
	Object novo = new(Node);
	if(!novo)
		return NULL;
	
	novo->item = p;
	novo->type = CLIENTE;
	novo->print = print_Cliente;
	novo->destroy = destroy_Obj;
	novo->get_id = get_id_Cliente;
	novo->next = NULL;
	novo->prev = NULL;
	return novo;
}

//========================================================================
//Funções do cliente
//========================================================================

Object set_Cliente(){	
	char nome[20];
	int idade;
	int id;
	
	printf("NOME: ");
	scanf(" %19s", nome);
	printf("IDADE: ");
	scanf(" %d", &idade);
	id = 999 + rand()% 9900;
	printf("\nCLIENTE COM ID: \33[1;33m[%d]\33[0m CADASTRADO COM SUCESSO\n", id);
	_enter();
	return new(Cliente, nome, idade, id);
}

void print_Cliente(void* data){
	Cliente cliente = data;
	printf("Nome: %s\n", cliente->nome);
	printf("Idade: %d\n", cliente->idade);
	printf("ID: %d\n", cliente->id);
}

int get_id_Cliente(void* data){
	if(!data) return 0;
	Cliente cliente = data;
	return cliente->id;
}

#endif
