#ifndef INTERFACELISTA_H
#define INTERFACELISTA_H

#include "tools.h"
#include "list.h"

int menu_Lista(){
	system("clear");
	printf("\t\t\33[1;33mCONTROLE GERAL\n\n\33[0m");
	printf("1 - List Print\n");
	printf("2 - List Pop\n");
	printf("3 - List Clear\n");
	printf("4 - List Delete\n");
	printf("5 - List Get\n");
	printf("------------------------\n");
	printf("0 - Retornar ao Menu Principal\n\n");
	printf("Opção: ");
	return _opt();
}

void controle_Lista(List lst){
	do{
		switch(menu_Lista()){
			case 1: lst->print(lst, INDEFINIDO); break;
			case 2: Object pop = lst->pop(lst);
						if(!pop) break;
					pop->print(pop->item);
					pop->destroy(pop);
					_enter();
					break;
					
			case 3: lst->clear(lst, INDEFINIDO); break;
			
			case 4: if(!lst->init){ 
						message_error(); 
						break;
					}
					printf("Digite o ID do Objeto: ");
					lst->delete_id(lst, _opt); break;
					
			case 5: { 
						if(!lst->init) { message_error(); break; }
						printf("Digite o índice a ser buscado: ");
						int indice = _opt();
						Object get = lst->get(lst, indice);
						if (get) {
							printf("Item no índice %d:\n", indice);
							get->print(get->item);
						} else {
							printf("Índice inválido.\n");
						}
						_enter();
						break;
					}
					
			default: printf("Inválido\n");
			case 0: return;
		}
	}while(1);
}

#endif
