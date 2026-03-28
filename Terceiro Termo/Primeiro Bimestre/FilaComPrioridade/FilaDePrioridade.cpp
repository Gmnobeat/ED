#include<stdio.h>
#include<string.h>
#include<conio2.h>
#include<stdlib.h>
#include<ctype.h>
#include"TADFilaPrioridade.h"

struct TpDadosVeiculos
{
	char idVeiculo[100],cor[50],fabrica[50],Prioridade;	
};

void Exercicio7(char NomeArq[50])
{
	TpDadosVeiculos Dados; 
	FILE *PtrArq = fopen(NomeArq,"r");
	fscanf(PtrArq,"%s %s %s %c",Dados.idVeiculo,Dados.cor,Dados.fabrica,Dados.Prioridade);
	while(!feof(PtrArq))
	{
		
		fscanf(PtrArq,"%s %s %s %c",Dados.idVeiculo,Dados.cor,Dados.fabrica,Dados.Prioridade);
	}
	
	
	fclose(PtrArq);
}

int main (void)
{
	char NomeArq[50];
	printf("Digite o nome do arq\n");
	fflush(stdin);
	gets(NomeArq);
	
	return 0;
}
