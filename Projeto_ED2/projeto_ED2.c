#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "object.h"
#include "list.h"
#include "clientes.h"
#include "produtos.h"
#include "interfaceCliente.h"
#include "interfaceProduto.h"
#include "interfaceLista.h"
#include "tools.h"


int interface(){
	system("clear");
	printf("\t\t\33[1;33mMENU PRINCIPAL\n\n\33[0m");
	printf("1 - Área Clientes\n");
	printf("2 - Área Produtos\n");
	printf("3 - Controle Lista\n");
	printf("0 - sair\n");
	printf("-----------------------\n");
	printf("Opção: ");
	return _opt();
}


int main(){
	srand(time(NULL));
	
	List lst = new(List);
	
	do{
		switch(interface()){
			
			case 1:	controle_Cliente(lst); break;
			case 2: controle_Produto(lst); break;
			case 3: controle_Lista(lst); break;
			case 0: if(!lst || !lst->init) return 0;
					printf("Limpando memória antes de sair...\n");
					lst->clear(lst, INDEFINIDO); 
					return 0;
			default: printf("\33[1;31mOPÇÃO INVÁLIDA\33[0m\n"); _enter();
		}
	}while(1);

	return 0;
}

