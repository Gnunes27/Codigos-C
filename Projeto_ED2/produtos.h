#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "object.h"

typedef struct _Produto{
	char description[20];
	float price;
	int id;
}_Produto;

typedef _Produto* Produto;

void print_Produto();
int get_id_Produto();

Object new_Produto(char* describe, float preco, int id){
	Produto p = malloc(sizeof(_Produto));
	strcpy(p->description, describe);
	p->price = preco;
	p->id = id;
	
	Object novo = new(Node);
	if(!novo) return NULL;
	
	novo->item = p;
	novo->type = PRODUTO;
	novo->print = print_Produto;
	novo->destroy = destroy_Obj;
	novo->get_id = get_id_Produto;
	novo->next = NULL;
	novo->prev = NULL;
	
	return novo;
	
}

Object set_Produto(){
	char texto[20];
	float preco;
	int id;
	
	printf("Faça a descrição: ");
	scanf(" %19[^\n]s", texto);
	printf("Preço: ");
	scanf(" %f", &preco);
	id = 999 + rand()%9900;
	printf("\nPRODUTO COM ID: \33[1;33m[%d]\33[0m CADASTRADO COM SUCESSO\n", id);
	_enter();
	return new(Produto, texto, preco, id);
}

void print_Produto(void* data){
	Produto produto = data;
	printf("Descrição: %s\n", produto->description);
	printf("Preço: R$ %.2f\n", produto->price);
	printf("ID: %d\n", produto->id);
}

int get_id_Produto(void* data){
	if(!data) return 0;
	Produto produto = data;
	return produto->id;
}

#endif
