#ifndef OBJECT_H
#define OBJECT_H
#define new(Type,...) new_##Type(__VA_ARGS__)
#define set(Type,...) set_##Type(__VA_ARGS__)

typedef enum{
	INDEFINIDO,
	CLIENTE,
	PRODUTO
}TypeObject;

const char* get_type_name(TypeObject tipo) {
    switch (tipo) {
        case CLIENTE: return "CLIENTE";
        case PRODUTO: return "PRODUTO";
        default: return "DESCONHECIDO";
    }
}

typedef struct Node{
	void* item;
	int position;
	TypeObject type;
	void (*print) (void*);
	void (*destroy) (void*);
	int (*get_id) ();
	struct Node* next;
	struct Node* prev;
}Node;


typedef Node* Object;

Object new_Node(){
	Object no = malloc(sizeof(Node));
	no->item = NULL;
	no->type = INDEFINIDO;
	no->print = NULL;
	no->destroy = NULL;
	no->next = NULL;
	no->prev = NULL;
	no->get_id = NULL;
	return no;
}

void destroy_Obj(void* a){
	Object obj = a;
	if(obj->item) free(obj->item);
	if(obj) free(obj);
}

#endif
