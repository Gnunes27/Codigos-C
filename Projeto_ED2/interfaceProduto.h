#ifndef INTERFACEPRODUTO_H
#define INTERFACEPRODUTO_H

#include "list.h"
#include "tools.h"

int menu_Produto(){
	system("clear");
	printf("\t\t\33[1;33mMENU DE PRODUTOS\n\n\33[0m");
	printf("1 - Cadastrar Produto\n");
	printf("2 - Listar Produtos\n");
	printf("3 - Excluir Produto\n");
	printf("------------------------\n");
	printf("0 - Retornar ao Menu Principal\n\n");
	printf("Opção: ");
	return _opt();
}

void controle_Produto(List lst){
	do{
		switch(menu_Produto()){
			case 1: lst->enqueue(lst, set(Produto));
			break;
			case 2: lst->print(lst, PRODUTO);
			break;
			case 3: lst->clear(lst, PRODUTO);
			break;
			default: printf("Inválido\n");
			case 0: return;
		}
	}while(1);
}

#endif
