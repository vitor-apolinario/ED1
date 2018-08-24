#include<stdio.h>
#include<stdlib.h>
#define TAM 50

typedef struct _produto{
	int codigo;
	char nome[20];
	float preco;
} TpProduto;

typedef struct _nodo{
	TpProduto info;
	struct _nodo *next;
	struct _nodo *prev;
} TpNodo;

typedef struct _lista{
	int nItens;
	TpNodo *first;
	TpNodo *last;
} TpLista; 

//funcao push
TpLista* push(TpLista *u){
system("clear");
int op;
TpNodo *v = (TpNodo*)malloc(sizeof(TpNodo));	
		if(u->nItens == 0){
			printf("CADASTRO DE PRODUTOS\n\n");
			printf("Insira o código: ");
			scanf("%d",&v->info.codigo);
			getchar();
			printf("Insira o nome do produto: ");
			fgets(v->info.nome,TAM,stdin);
			printf("Insira o preço do produto: ");
			scanf("%f",&v->info.preco);
			u->nItens++;
			v->next = NULL;
			v->prev = NULL;
			u->first = v;
			u->last = v;
			return u;
		}
		
		printf("CADASTRO DE PRODUTOS\n\n");
			printf("Insira o código: ");
			scanf("%d",&v->info.codigo);
			getchar();
			printf("Insira o nome do produto: ");
			fgets(v->info.nome,TAM,stdin);
			printf("Insira o preço do produto: ");
			scanf("%f",&v->info.preco);
			u->nItens++;

do{
	printf("Deseja inserir o elemento ao:\n[1]-inicio\n[2]-final\n");
	scanf("%d",&op);
	switch(op){
		case 1:
		v->prev = NULL;
		v->next = u->first;
		u->first->prev = v;
		u->first = v;
		op = 0; 
		break;
		
		case 2:
		v->next = NULL;
		v->prev = u->last;
		u->last->next = v;
		u->last = v;
		op = 0;
		break;
		
		case 0:
		break;
		
		default:
		printf("Digite um operador correto");
		getchar();
		getchar();
		break;
		}
}while(op!=0);
	return u;
	}
	
void pop(TpLista *u){
	system("clear");
	TpNodo *v = u->first;
	int code;
	
if(v == NULL){
	puts("A lista está vazia!");
	getchar();
	getchar();
	return;
}
	//remove elemento único
	if(v->prev == NULL && v->next == NULL){
		free(u->first);
		u->first = NULL;
		u->last = NULL;
		printf("Primeiro elemento removido!");
		u->nItens--;
		getchar();
		getchar();
		return;
	}
	
	puts("Insira o código do produto que deseja remover:");
	scanf("%d",&code);
		
	for(;v->next != NULL; v = v->next){
		if(v->info.codigo == code){
			//remove primeiro elemento
			if(v->prev == NULL){
				(v->next)->prev = NULL;
				u->first = v ->next;
				free(v);
				u->nItens--;
				return;
			//remove o último elemento
			}else if(v->next == NULL){
				break;
			}
			//remove elemento entre as F & L
			(v->prev)->next = v->next;				
			(v->next)->prev = v->prev;
			free(v);
			u->nItens--;
		return;
		}
	}
	//remove último elemento
	(v->prev)->next = NULL; 
	u->last = v->prev;
	free(v);
	u->nItens--;
	return;
}	
	
void display(TpLista *u){
	TpNodo *v = u->first;
system("clear");
printf("_____PRODUTOS[%d]____\n",u->nItens);	
	for(; v != NULL ; v = v->next){
	if(v->next == NULL)
		puts("último");
	if(v->prev == NULL)
		puts("primeiro");
		
		printf("Code: %d\n",v->info.codigo);
		printf("Nome: %s",v->info.nome);
		printf("Preço: %.2f\n\n",v->info.preco);
	}
	getchar();
	getchar();
	}
		
		


int main(){
int z;

TpLista *lista = (TpLista*)malloc(sizeof(TpLista));

lista->first = NULL;
lista->last = NULL;

do{
	system("clear");
	printf("Digite uma operação: ");
	printf("\n1-Inserir elemento\n2-Excluir elemento\n3-Listar elementos\n0-Finalizar programa\n");
	scanf("%d",&z);
	switch(z){
		
		case 1:
		lista = push(lista);
		break;
		
		case 2:
		pop(lista);
		break;
		
		case 3:
		display(lista);
		break;
		case 0:
		break;
		
		default:
		system("clear");
		printf("Insira um operador válido!");
		getchar();
		getchar();
		break;
		}
}while(z!=0);	
	
	
	return 0;
	}

