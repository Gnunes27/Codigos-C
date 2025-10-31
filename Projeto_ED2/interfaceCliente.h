#ifndef INTERFACECLIENTE_H
#define INTERFACECLIENTE_H

#include "list.h"
#include "tools.h"

int menu_Cliente(){
	system("clear");
	printf("\t\t\33[1;33mMENU DE CLIENTES\n\n\33[0m");
	printf("1 - Cadastrar Cliente\n");
	printf("2 - Listar Clientes\n");
	printf("3 - Excluir Cliente\n");
	printf("------------------------\n");
	printf("0 - Retornar ao Menu Principal\n\n");
	printf("Opção: ");
	return _opt();
}

void controle_Cliente(List lst){
	do{
		switch(menu_Cliente()){
			case 1: lst->push(lst, set(Cliente));
			break;
			case 2: lst->print(lst, CLIENTE);
			break;
			case 3: lst->clear(lst, CLIENTE);
			break;
			default: printf("Inválido\n");
			case 0: return;
		}
	}while(1);
}



#endif
