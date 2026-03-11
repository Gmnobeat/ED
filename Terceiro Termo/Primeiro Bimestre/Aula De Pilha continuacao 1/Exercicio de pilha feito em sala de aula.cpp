#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<ctype.h>
#include "TADPilha.h"

#define MAXPILHA 10

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
	while(!Vazia(Aux.topo) && !Cheio(Pilha1.topo))
		Push(Pilha1,Pop(Aux));
	printf("concatenação das pilhas \n");
	Exibir(Pilha1);
}

void Exercicio2()
{
	
}

int main(void)
{
	TpPilha Pilha;
	char op;
	do
	{
		op = menu();
		switch(op)
		{
			case '1':
	            inicializa(pilha);
	            printf("\nPilha inicializada!\n");
	            getch();
	            break;
	        case '2':
				if( !cheia(pilha.TOPO) )
				{
					printf("\nDigite o elemento: ");
	                fflush(stdin);
					scanf("%c",&elemento);
					insere(pilha,elemento);
					printf("\n\nElemento inserido!\n");
				}
				else
					printf("\nNao e possivel inserir, Pilha esta cheia!\n");
	            getch();
	            break;
	        case '3':
	        	if( !vazia(pilha.TOPO) )
	       			printf("\nElemento [%c] retirado da pilha!\n",retira(pilha));
				else
					printf("\nNao e possivel retirar, pilha esta vazia!\n");
	            getch();
	            break;
	        case '4':
	        	if( !vazia(pilha.TOPO) )
	        		printf("\nElemento [%c] do topo!\n",elementoTopo(pilha));
	        	else
	        		printf("\nA pilha esta vazia!\n");
	            getch();
	            break;
	        case '5':
	        	if( !vazia(pilha.TOPO) )
	        		exibe(pilha);
	        	else
	        		printf("\nA pilha esta vazia!\n");
	            getch();
	            break;
	        case '6':
        }
	}while(op != 27);
	return 0;
}
