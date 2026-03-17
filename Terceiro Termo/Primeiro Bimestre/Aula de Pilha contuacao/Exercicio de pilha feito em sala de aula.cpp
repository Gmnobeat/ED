#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<ctype.h>

#define MAXPILHA 10
#include "TADPilha.h"

char menu (void)
{
	clrscr();
	printf("\n1 - inicializa");
	printf("\n2 - Insere (PUSH)");
	printf("\n3 - Retira (POP)");
	printf("\n4 - Mostra elemento do topo");
	printf("\n5 - Exibe Pilha");
	printf("\n[ESC] - Sair");
	printf("\nDigite a opcao desejada");
	return getch();
}

void Exercicio1 (TpPilha &Pilha1, TpPilha Pilha2)
{
	TpPilha Aux;
	Inicializar(Aux);
	while(!Vazia(Pilha2.topo))
		Push(Aux,Pop(Pilha2));
	while(!Vazia(Aux.topo) && !Cheia(Pilha1.topo))
		Push(Pilha1,Pop(Aux));
	printf("\nconcatenação das pilhas \n");
	Exibir(Pilha1);
	getch();
}

void Exercicio2(TpPilha &Pilha1, char &elemento)
{
	TpPilha aux;
	while(!Vazia(Pilha1))
	{
		if()
	}
	
}

int main(void)
{
	TpPilha Pilha1,Pilha2;
	
	char op, elemento;
	do
	{
		op = menu();
		switch(op)
		{
			case '1':
	            Inicializar(Pilha1);
	            Inicializar(Pilha2);
	            printf("\nPilhas inicializadas!\n");
	            getch();
	            break;
	        case '2':
				if( !Cheia(Pilha1.topo) )
				{
					printf("\nDigite o elemento: ");
	                fflush(stdin);
					scanf("%c",&elemento);
					Push(Pilha1,elemento);
					printf("\n\nElemento inserido Pilha1!\n");
				}
				else
					printf("\nNao e possivel inserir, Pilha1 esta cheia!\n");
	            getch();
	            if( !Cheia(Pilha2.topo) )
				{
					printf("\nDigite o elemento: ");
	                fflush(stdin);
					scanf("%c",&elemento);
					Push(Pilha2,elemento);
					printf("\n\nElemento inserido Pilha2!\n");
				}
				else
					printf("\nNao e possivel inserir, Pilha2 esta cheia!\n");
	            getch();
	            break;
	        case '3':
	        	if( !Vazia(Pilha1.topo) )
	       			printf("\nElemento [%c] retirado da pilha!\n",Pop(Pilha1));
				else
					printf("\nNao e possivel retirar, pilha esta vazia!\n");
	            getch();
	            break;
	        case '4':
	        	if( !Vazia(Pilha1.topo) )
	        		printf("\nElemento [%c] do topo!\n",ElementoTopo(Pilha1));
	        	else
	        		printf("\nA pilha esta vazia!\n");
	            getch();
	            break;
	        case '5':
	        	if( !Vazia(Pilha1.topo) )
	        		Exibir(Pilha1);
	        	else
	        		printf("\nA pilha esta vazia!\n");
	            getch();
	            break;
	        case '6':	Exercicio1(Pilha1,Pilha2);
	        			break;
	        case '7':	printf("Digite o elemento desejado para ser excluido");
	        			scanf("%c",&elemento);
	        			Exercicio2(Pilha1,elemento);
	        			break;
	        
        }
	}while(op != 27);
	return 0;
}
