#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "TADDados.h"
//se nao estiver na mesma pasta tem cque colocar o endereço onde estara
//EX. #include "c/..."
//Funções do Programa
char Menu(void)
{
	clrscr();
	printf("\n *** M E N U *** \n");
	printf("[A] Verifica a existencia de Cidades.dat \n");
	printf("[B] ... \n");
	printf("[C] ... \n");
	printf("[D] ... \n");
	printf("[ESC] Finalizar \n");
	printf("[A] ... \n");
	printf("\n Opcao");
	return toupper(getche());
}
void ArquivoExiste(char NomeArquivo[50])
{
	FILE *PtrCidade = fopen(NomeArquivo,"rb");
	if(PtrCidade != NULL)
	{
		printf("\nArquivo OK\n");
		getch();
		fclose(PtrCidade);
	}
	else
	{
		printf("\nArquivo Nao existe, Deseja cria-lo?");
		if(toupper(getch())=='S')
		{
			PtrCidade = fopen(NomeArquivo,"wb");
			fclose(PtrCidade);
			printf("\nArquivo criado com sucesso");
		}	
	}
	getch();
}


int main (void)
{
	char op;
	do
	{
		op = Menu();
		switch(op)
		{
			case 'A': ArquivoExiste((char *)"Cidades.dat");
					  break;
			case 'B': CadastrarCidades((char *)"Cidades.dat");
			break;
			case 'C': Relatorio((char *)"Cidades.dat");
			break;
			case 'D': break;
		}
		
	}while(op !=27);
}
