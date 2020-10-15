#include <stdio.h>
#include <stdlib.h>

#include "titulo.h"

typedef struct Contato {
	char nome[80];
	int telefone;
	char email[80];
    Contato *proximo;
	
} CONTATO;

CONTATO * incluirContatoNoInicio(CONTATO *lista, CONTATO *contatoCriado);
CONTATO * remover_Contato(CONTATO *lista);
void listar_Contatos(CONTATO *lista);
void buscar_Contato(CONTATO *lista);
CONTATO * criar_Contato();
CONTATO * criar_Contato();
void menu();

CONTATO *primeiroElemento;
int qtdeItens;


CONTATO * incluirContatoNoInicio(CONTATO *lista, CONTATO *contatoCriado){	

	if (lista == NULL) {
		lista = contatoCriado;
		
		contatoCriado->proximo = NULL;
				
	} else {		
		// e o proximo do novo contato vira o que era o primeiro da lista
		contatoCriado->proximo = lista;		
		lista = contatoCriado;	
	};
	
	return lista;
};

CONTATO * remover_Contato(CONTATO *lista) { 

	CONTATO *aux;
	aux = lista;
	
	char op;
	printf("\nDeseja realmente excluir um Contato\n\--> S\n\--> N\n\n");
	printf("informe a opcao: ");
	scanf(" %c", &op);
	

	if (op == 'S' or op == 's') {
		for (int i = 0; i < qtdeItens; i++){		
			
			// quando o i for igual ao penultimo elemento atribuo null para o proximo, e com isso nao tenho mais a referencia do ultimo
			if (i == (qtdeItens-1)) {
				aux->proximo = NULL;
				printf("Contato %s removido com Sucesso !!!", aux->nome);
				
				qtdeItens--;
				
				return lista;
			};			
			
			aux = aux->proximo;	
		};	
		
		printf("Nenhum registro para remover !!!\n");
		return lista;
					
	} else {
		
		return lista;
	};

};

void listar_Contatos(CONTATO *lista){
	
	CONTATO *aux;
	aux = lista;
	
	printf("\n**************************************\n");
	printf("*           LISTA DE CONTATOS         *\n\n");
	
	
	for (int i = 0; i < qtdeItens; i++){	
	
		printf("-> Nome: %s\n", aux->nome);
		printf("-> Telefone: %d\n", aux->telefone);
		printf("-> E-mail: %s\n", aux->email);
		printf("---------------------------------------\n\n");		 
		aux = aux->proximo;		
	};
};

void buscar_Contato(CONTATO *lista){
	
	CONTATO *aux;
	aux = lista;
	
	int telefone;
	
	printf("Informe o telefone para realizar a Busca: \n");
	scanf("%d", &telefone);
	
	for (int i = 0; i < qtdeItens; i++){	
	
		if (aux->telefone == telefone) {
			
			printf("-- Contato localizado: --\n");
			
			printf("-> Nome: %s\n", aux->nome);
			printf("-> Telefone: %d\n", aux->telefone);
			printf("-> E-mail: %s\n", aux->email);
			return;
		};	
			 
		aux = aux->proximo;		
	};
	
	printf("Telefone nao ENCONTRADO !!!\n");	
};


CONTATO * criar_Contato() {
	
	CONTATO *novoContato = (CONTATO*) malloc(sizeof(CONTATO));
	
	printf("Cadastro de Contatos\n");
	
	printf("----------------------------------------\n");
	printf("Entre com o nome: ");
	scanf("%s", &novoContato->nome);
		
	printf("Entre com o Telefone: ");
	scanf("%d", &novoContato->telefone);
		
	printf("Entre com o E-mail: ");
	scanf("%s", &novoContato->email);
	
	qtdeItens++;

	return novoContato;
}

void gerarTitulo() {
	printf("\n**************************************\n");
	printf("*                AGENDA              *\n");
	printf("**************************************\n");	
	printf("Registro(s): %d                    \n", qtdeItens);	
	
	printf("Opcoes do Sistema:\n");
};

void menu(){
	
	gerarTitulo();
	
	char op;
	printf("\n\t1 - Incluir Contato\n\t2 - Remover Contato (ultimo)\n\t3 - Listar Contatos\n\t4 - Pesquisar Contato por telefone\n\t5 - Sair\n\n");
	printf("informe a opcao: ");
	scanf("%d", &op);  // capturar a opção selecionada

	while(op != 5) {
		system ("CLS");
		switch(op) {			
			
		       case 1:				
		          primeiroElemento = incluirContatoNoInicio(primeiroElemento, criar_Contato()); 
		          menu();
		        break;
			   		       
		       case 2:			
		          primeiroElemento = remover_Contato(primeiroElemento);
		          menu();
		       break;    
			   		       
		       case 3:				
		           listar_Contatos(primeiroElemento);
		           menu();
		       break;
			   		       
		       case 4:				
		         buscar_Contato(primeiroElemento);
				 menu();		            
		       break;
		       
		       case 5:				
		         exit(0);		            
		       break;
		       
			   default:
			       printf("\nOpcao Invalida !!!\n");
			       menu();
			   break;
   	    }; 

  	};
};

int main () {	
	
	assinatura();
	primeiroElemento = NULL;
	
	menu();
	return 0;
	
}


