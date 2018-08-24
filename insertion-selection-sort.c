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
	TpNodo *v = u->first,*x = u->last;
system("clear");
printf("_____PRODUTOS[%d]____\n",u->nItens);	
	for(; v != NULL ; v = v->next, x = x->prev){
	/*if(v == u->last)
		puts("último");
	if(v == u->first)
		puts("primeiro");*/
		
		printf("Code: %d 	||	Code: %d\n",v->info.codigo, x->info.codigo);
		/*printf("Nome: %s 	|| Nome: %s",v->info.nome, x->info.nome);
		printf("Preço: %.2f || Preço: %.2f\n\n",v->info.preco, x->info.preco);*/
	}
	getchar();
	getchar();
	}
		
void insertion_sort(TpLista *u){
	
	TpNodo *aux,*aux0,*key;
	
	if(u->nItens == 0 || 1)
		return;
	
	for(aux = u->first->next; aux != NULL; aux = aux->next){
		key = aux;
		aux0 = key->prev;	

		//acha onde deve ser inserido key
		while(aux0->info.codigo > key->info.codigo && aux0->prev != NULL){
			aux0 = aux0->prev;
		}
		
		printf("key: %d || aux0: %d || ",key->info.codigo, aux0->info.codigo);
	
	//caso o lugar seja diferente do inicial ou aux0 > key
	if(aux0 != aux->prev || aux0->info.codigo > key->info.codigo){	
		
		//retira o nodo key
		if(key->next == NULL){
			key->prev->next = NULL;
			u->last = key->prev;
		}else{
			key->prev->next = key->next;
			key->next->prev = key->prev;
		}
		//caso o auxiliar pare no primeiro elemento e key deverá ser o primeiro
		if(aux0->prev == NULL && aux0->info.codigo > key->info.codigo){
			u->first = key;	
			key->prev = NULL;
			key->next = aux0;
			aux0->prev = key;
			printf("caso1\n");
		//caso o auxiliar pare no primeiro elemento mas key deverá ser o segundo
		}else if(aux0->prev == NULL && aux0->info.codigo < key->info.codigo){
			key->prev = aux0;
			key->next = aux0->next;	
			if(key->next != NULL)
				key->next->prev = key;
			aux0->next = key;
			printf("caso2\n");	
		//caso key faça a troca no meio
		}else{
			key->next = aux0->next;
			aux0->next = key;
			key->prev = aux0;
			key->next->prev = key;
			printf("caso3\n");
		}
	}else
		printf("ordenado\n");
		
	}
	getchar();
	getchar();
}	

//corrigido
void selection_sort(TpLista *u){
	
	TpNodo *aux, *aux0, *aux1_prev ,*aux1, *aux1_next, *menor_prev,*menor, *menor_next;
	
	for(aux = u->first; aux  != NULL; aux = aux->next){
				
		menor = aux;
		aux0 = aux->next;
		aux1 = aux;
			
			while(aux0 != NULL){
				if(aux0->info.codigo < menor->info.codigo)
					menor = aux0;
			aux0 = aux0->next;
			}
		printf("key: %d  || menor: %d ", aux1->info.codigo, menor->info.codigo);

		
		if(menor->info.codigo < aux1->info.codigo){
			//caso 1 papel
			if(aux1 == u->first && menor == u->last && u->nItens != 2){
				aux1_next = aux1->next;
				menor_prev = menor->prev;
				aux1_next->prev = menor;
				menor->next = aux1_next;
				menor->prev = NULL;
				u->first = menor;
				menor_prev->next = aux1;
				aux1->prev = menor_prev;
				aux1->next = NULL;
				u->last = aux1; 
				printf("caso 1\n");
			//caso 2 papel
			}else if(aux1 == u->first && menor == u->last){
				u->first = menor;
				u->last = aux1;
				menor->prev = NULL;
				aux1->next = NULL;
				menor->next = aux1;
				aux1->prev = menor;
				printf("caso 2\n");
			//caso 3 papel
			}else if(aux1 == u->first && aux1->next == menor){
				aux1->next = menor->next;
				aux1->next->prev = aux1;
				aux1->prev = menor;
				u->first = menor;
				menor->prev = NULL;
				menor->next = aux1;
				printf("caso 3\n");
			//caso 4 papel
			}else if(menor == u->last && aux1 == menor->prev){
				aux1->prev->next = menor;
				menor->prev = aux1->prev;
				menor->next = aux1;
				aux1->prev = menor;
				aux1->next = NULL;
				u->last = aux1;
				printf("caso 4\n");
			//caso 5 papel
			}else if(aux1->prev != NULL && menor->next != NULL && aux1->next == menor){
				aux1_prev = aux1->prev;
				menor_next = menor->next;
				menor->next = aux1;
				aux1->prev = menor;
				aux1_prev->next = menor;
				menor->prev = aux1_prev;
				menor_next->prev = aux1;
				aux1->next = menor_next;
				printf("caso 5\n");				
			//caso 6
			}else if(aux1->prev == NULL){
				menor_prev = menor->prev;
				menor_next = menor->next;
				aux1_next = aux1->next;
				menor_prev->next = menor_next->prev = aux1;
				aux1->next = menor_next;
				aux1->prev = menor_prev;
				aux1_next->prev = menor;
				menor->next = aux1_next;
				menor->prev = NULL;
				u->first = menor;
				printf("caso 6\n");
			//caso 7
			}else if(menor->next == NULL){
				aux1_prev = aux1->prev;
				aux1_next = aux1->next;
				menor_prev = menor->prev;	
				aux1_prev->next = aux1->next->prev = menor;
				menor->prev = aux1_prev;	
				menor->next = aux1_next;	
				menor_prev->next = aux1;
				aux1->prev = menor_prev;
				u->last = aux1;
				aux1->next = NULL;
				printf("caso 7\n");
			//caso 8
			}else{
				aux1_prev = aux1->prev;
				aux1_next = aux1->next;
				menor_prev = menor->prev;
				menor_next = menor->next;
				aux1_prev->next = aux1_next->prev = menor;
				menor->prev = aux1_prev;
				menor->next = aux1_next;
				menor_prev->next = menor_next->prev = aux1;
				aux1->prev = menor_prev;
				aux1->next = menor_next;
				printf("caso 8\n");
			}
		}else
			printf("ordenado/sem caso\n");

		aux = menor;
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
	printf("\n1-Inserir elemento\n2-Excluir elemento\n3-Listar elementos\n4-Insertion sort\n5-Selection sort\n0-Finalizar programa\n");
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
		
		case 4:
		insertion_sort(lista);
		break;

		case 5:
		selection_sort(lista);
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

