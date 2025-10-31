#ifndef LIST_H
#define LIST_H

#include "tools.h"
#include "object.h"

typedef struct _List{
	Object init;
	Object end;
	int size;
	void (*print)();
	void (*clear)();
	void (*push)();
	void (*enqueue)();
	Object (*pop)();
	void (*delete_id)();
	Object (*get)();
}_List;

typedef _List* List;


void message_error(){
	printf("\33[1;31mLISTA VAZIA...\n\33[0m");
	_enter();
}

//================================================
//FUNÇÕES DE LIST JÁ CRIADAS
void list_enqueue();
void list_push();
Object list_pop();
void list_print();
void list_clear();
void list_delete();
Object list_get();
//================================================

List new_List(){
	List lst = malloc(sizeof(_List));
	lst->init = NULL;
	lst->end = NULL;
	lst->size = 0;
	lst->push = list_push;
	lst->enqueue = list_enqueue;
	lst->pop = list_pop;
	lst->clear = list_clear;
	lst->print = list_print;
	lst->delete_id = list_delete;
	lst->get = list_get;
	return lst;
}



void list_enqueue(List lst, Object item){
	if(!lst->init){
		lst->init = item;
		lst->end = item;
	}else{
		lst->end->next = item;
		item->prev = lst->end;
		lst->end = item;
	}
	lst->size++;
}

void list_push(List lst, Object item){
	if(!lst->init){
		lst->init = item;
		lst->end = item;
	}else{
		lst->init->prev = item;
		item->next = lst->init;
		lst->init = item;
	}
	lst->size++;
}

Object list_pop(List lst) {
    if (!lst->init){
		message_error();
		return NULL;
	}
    Object aux = lst->init;

    lst->init = aux->next;

    if (lst->init) {
        lst->init->prev = NULL;
    } else {
        lst->end = NULL;
    }

    aux->next = NULL;
    aux->prev = NULL;

    lst->size--;
    return aux;
}

void list_print(List lst, TypeObject tpe){
	if(!lst->init){
		message_error();
		return;
	}
	
	Object temp = lst->init;
	
	if(tpe == INDEFINIDO){
		printf("\t\t\33[1;33m--- LISTA GERAL ---\33[0m\n");
		while(temp){
			const char* tipo = get_type_name(temp->type);
            printf("\n\33[1;36mTIPO: %s\33[0m\n", tipo);
			temp->print(temp->item);
			temp = temp->next;
		}
		printf("\33[1;31m------------------\33[0m\n");
		_enter();
		return;
	}
	
	while(temp){
		if(temp->type == tpe)
			temp->print(temp->item);
		temp = temp->next;
	}
	
	_enter();
}

void list_clear(List lst, TypeObject type){
	if(!lst->init){
		message_error();
		return;
	}
	
	Object temp = lst->init;
	Object proximo;
	
	if(type == INDEFINIDO){
		while(temp){
			proximo = temp->next;
			temp->destroy(temp);
			temp = proximo;
		}
	
		lst->init = NULL;
		lst->end = NULL;
		lst->size = 0;
		printf("Lista limpa com sucesso.\n");
		_enter();
		return;
	}
	
	while(temp){
		proximo = temp->next;
		
		if(temp->type == type){
			
			if(temp->prev) temp->prev->next = temp->next;
			else lst->init = temp->next;
			
			if(temp->next) temp->next->prev = temp->prev;
			else lst->end = temp->prev;
			
			temp->destroy(temp);
			lst->size--;
		}
		temp = proximo;
	}

}

void list_delete(List lst, int alvo){
	if(!lst->init){
		message_error();
		return;
	}
	
	Object temp = lst->init;
	
	while(temp){
		if(temp->get_id && temp->get_id(temp->item) == alvo){
		
			if(temp->prev) temp->prev->next = temp->next;
			else lst->init = temp->next;
			
			if(temp->next) temp->next->prev = temp->prev;
			else lst->end = temp->prev;
			
			if(temp->destroy) temp->destroy(temp);
			
			lst->size--;
			printf("\n\33[1;32mItem com ID [%d] excluído com sucesso!\n\33[0m", alvo);
			_enter();
			return;
		}
		
		temp = temp->next;
	}
	  printf("\n\33[1;31mItem com ID [%d] não encontrado.\n\33[0m", alvo);
    _enter();
	
}

Object list_get(List lst, int index){
	if(!lst->init || index >= lst->size){
		_titulo(VERMELHO, "ÍNDICE INEXISTENTE");
		return NULL;
	}
	
	Object temp = lst->init;
	int i = 0;
	while(temp){
		if(index == i){
			return temp;
		}
		i++;
		temp = temp->next;
	}
	printf("Não Encotrado");
	return NULL;
}

//===============================================
//===============================================



#endif
