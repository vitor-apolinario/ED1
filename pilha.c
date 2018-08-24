#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 50

//criação de uma struct tipo produto
typedef struct _produto{
	int cod;
	char nome[TAM];
	float preco;
}tp_produto;

//criação de uma struct tipo pilha
typedef struct _pilha{
	tp_produto *info;
	int topo,
		max;
}tp_pilha;

void insere(tp_pilha *pilha){
	system("clear");
	
	if(pilha->topo == (pilha->max-1)){
		printf("A pilha está cheia!");
		getchar();
		return;
	}
	
	pilha->topo++;
	int i = pilha->topo;
	printf("Insira o nome do produto: ");
	fgets((pilha->info+i)->nome,TAM,stdin);
	printf("Insira o código do produto: ");
	scanf("%d",&(pilha->info+i)->cod);
	printf("Insira o preço do produto: ");
	scanf("%f",&(pilha->info+i)->preco);
	}

void exclui(tp_pilha *pilha){
	if(pilha->topo == -1){
		printf("A pilha está vazia!");
		getchar();
		return;
	}
	system("clear");
	int i = pilha->topo;
	printf("Produto:%sCódigo:%d foi removido com sucesso!",(pilha->info+i)->nome,(pilha->info+i)->cod);
	getchar();
	(pilha->topo)--;
	}
	
void lista(tp_pilha *pilha){
	system("clear");
	int i;
	printf("PILHA DE PRODUTOS:\n\n");
	for(i=pilha->topo;i>-1;i--){
		printf("Produto: %s",(pilha->info+i)->nome);
		printf("Código: %d\n",(pilha->info+i)->cod);
		printf("Preço: %.2f\n",(pilha->info+i)->preco);
		printf("\n");
		}
	getchar();
	}
	
int main(){
tp_pilha *p = (tp_pilha*)malloc(sizeof(tp_pilha));
int z,produtos;

p->topo = -1;


printf("Quantos produtos serão inseridos: ");
scanf("%d",&produtos);

p->max = produtos;
p->info = (tp_produto*)malloc(produtos*sizeof(tp_produto));

do{
	system("clear");
	printf("Insira um operador:\n1-Adicionar\n2-Excluir\n3-Listar\n0-Sair\n");
	scanf("%d",&z);
	getchar();
	switch(z){
		//inserir elemento
		case 1:
		insere(p);
		break;
		
		//excluir elemento
		case 2:
		exclui(p);
		break;
		
		//listar elementos da pilha
		case 3:
		lista(p);
		break;
		
		//finalizar	
		case 0:
		break;

		default:
		printf("Operação incorreta!");
		getchar();
		getchar();
		break;
		}
	}while(z!=0);


free(p);
return 0;
}
