#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
void insertionSort(int arr[], int n){
   int i, key, j;
   
   for (i = 1; i < n; i++){
       key = arr[i];
       j = i-1;
       
       while (j >= 0 && arr[j] > key){
           arr[j+1] = arr[j];
           j = j-1;
       }
       
       arr[j+1] = key;
   }
}

int buscaBinaria(int vetor[], int valor, int a, int b){
	//compara os extremos
	if(a <= b){
		//acha o meio
		int aux = (a + b) / 2;
		
		//se o valor estiver no meio retorna
		if(valor == vetor[aux]){
			return aux;
		}
		//se o valor for maior que a posição do meio
		if(valor > vetor[aux]){
			//chama a função com a metade maior do vetor que já possui
			return buscaBinaria(vetor, valor, aux + 1, b);
			//senão chama a função com a metade menor do vetor que já possui
		}else if(valor < vetor[aux]){
			return buscaBinaria(vetor, valor, a, aux - 1);
		}
		
	}
	//senao retorna -1
	return -1;
}

int main(){
	int vetor[10];
	int i, n = 10;

	do{
		for(i=0; i<10; i++){
			printf("Posição[%d]: ",(i+1));
			scanf("%d",&vetor[i]);
		}
		printf("\nDigite o valor que deseja buscar: ");
		scanf("%d",&i);
		
		insertionSort(vetor, n);
		
		system("clear");
		
		if(buscaBinaria(vetor, i, 0, n-1) == -1){
			puts("O valor inserido não está no vetor");
		}else
		printf("O valor %d está na posição %d\n",i,(buscaBinaria(vetor, i, 0, n-1)+1));
		
		for(i=0; i<n;i++){
			printf("%d-[%d]\n",i+1,vetor[i]);
		}
		puts("0-Sair");
		scanf("%d",&i);
		system("clear");
	}while(i > 0);
    
    return 0;
}
