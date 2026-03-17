//Letra maiuscula  
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio2.h>  //kbhit
#include<windows.h> //SLEEP
#include<time.h>//time
#include<ctype.h>

#define MAXPILHA 10
#include"TADPilha.h"

void Arqtexto2000(char Nome[50])
{
	FILE *PtrArq = fopen(Nome,"a");
	char letra;
	srand(time(NULL));
	do
	{
		printf("\nOperacao: %d\n",rand()%2 +1);
		letra = rand()%26 + 65;
		Sleep(200);
		printf("Letra : %c -> %d\n",letra,letra);
		fprintf(PtrArq,"%c\n",letra);	
	}while(!kbhit() && !feof(PtrArq));		
}


void VerificaPontero(char Nome[50])
{
	FILE *PtrArq = fopen(Nome,"r");
	if(PtrArq == NULL)
	{
		printf("Erro de abertura\n");
		printf("Deseja criar o arq?\n");
		if(toupper(getche()) == 'N')
			printf("Arquivo nao criado\n");
		else
		{
			FILE *PtrArq = fopen(Nome,"w");
			printf("Arquivo Criado\n");
			fclose(PtrArq);
		}
	}
	else
	{
		printf("Arquivo pronto para uso\n");
		fclose(PtrArq);
	}
}

void ExecucaoDaOperacao(char Nome[50])
{
	FILE *PtrPil = fopen(Nome,"r");
	TpPilha Pilha1;
	fflush(stdin);
	fgets(Pilha1.Pilha,MAXPILHA,PtrPil);
	while(!feof(PtrPil))
	{
		
		fgets(Pilha1.Pilha,50,PtrPil);
	}
}

int main()
{	
	char Nome[50];
	printf("Qual o nome do arq?\n");
	fflush(stdin);
	gets(Nome);
	VerificaPontero(Nome);
	Arqtexto2000(Nome);
	
	return 0;
}
