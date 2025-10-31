#ifndef TOOLS_H
#define TOOLS_H

#define VERMELHO 31
#define VERDE 32
#define AMARELO 33
#define AZUL 34
#define ROXO 35

void _titulo(int cor, char* texto){
	printf("\t\t\33[1;%dm%s\33[0m\n\n", cor, texto);	
}

int _opt(){
	int opt;
	while(1)	
		if(!scanf(" %d", &opt)){
			printf("\33[1;31mENTRADA INVÁLIDA\33[0m\n");
			printf("\33[1;34mDigite um número: \33[0m");
			while(getchar()!='\n');
		}else
			return opt;
}

void _enter(){
	printf("\nPRESSIONE ENTER PARA CONTINUAR...");
	setbuf(stdin, NULL);
	while(getchar()!='\n');
	system("clear");
}

#endif
