#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 100

typedef struct produto{
	int codigo;
	char nome[TAM];
	float preco;
}tp_produto;


typedef struct nodo{
	tp_produto produto;
	struct nodo *prox;
}tp_nodo;

tp_nodo *push(tp_nodo *u){
		
	tp_nodo *v = (tp_nodo*)malloc(sizeof(tp_nodo));
	system("clear");
	printf("CADASTRO DE PRODUTOS\n\n");
	printf("Insira o código: ");
	scanf("%d",&v->produto.codigo);
	__fpurge(stdin);
	printf("Insira o nome do produto: ");
	fgets(v->produto.nome,TAM,stdin);
	printf("Insira o preço do produto: ");
	scanf("%f",&v->produto.preco);
	v->prox = u;
	
	return v;
	}
	
tp_nodo *pop(tp_nodo *u){
	system("clear");
	if(u == NULL){
		printf("A lista está vazia!");
		getchar();
		getchar();
		return NULL;
		}
	
	int a;
	tp_nodo *aux0,*aux1,*mem;
	printf("Código do elemento que deseja remover:\n");
	scanf("%d",&a);

	mem = u;
	
	
	//busca pelo código
	for(;u != NULL;u = u->prox){
		//quando acha o código
		if(u->produto.codigo == a){
			//remove se o código for o último elemento cadastrado
			if(u == mem){
				free(u);
				u = u->prox;
				return u;
			}
			//caso seja um elemento do meio memoriza para posteriormente remover
			aux0 = u;
			aux1 = u->prox;
			break;
		}
	}
	u = mem;
	//remove com os dados memorizados
	for(;u != NULL;u = u->prox){
		if(u->prox == aux0){
			u->prox = aux1;
		}
	}
		free(aux0);
		return mem;
	}


void display(tp_nodo *u){
	system("clear");
	printf("____PRODUTOS____\n\n");
	for(;u != NULL;u = u->prox){
		printf("Code: %d\n",u->produto.codigo);
		printf("Nome: %s",u->produto.nome);
		printf("Preço: %.2f\n\n",u->produto.preco);
		}
	getchar();
	getchar();
	}

int main(){
int z;

tp_nodo *u = NULL;

do{
	system("clear");
	printf("Digite uma operação: ");
	printf("\n1-Inserir elemento\n2-Excluir elemento\n3-Listar elementos\n0-Finalizar programa\n");
	scanf("%d",&z);
	switch(z){
		
		case 1:
		u = push(u);
		break;
		
		case 2:
		u = pop(u);
		break;
		
		case 3:
		display(u);
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
