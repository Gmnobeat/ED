#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

void verificaArq(char NomeArq[50])
{
	FILE * PtrTxt = fopen(NomeArq,"r");
	if(PtrTxt == NULL)
	{
		printf("\nErro de abertura!\n\nDeseja criar?");
		if(toupper(getche())=='S')
		{
			PtrTxt = fopen(NomeArq,"w");
			fclose(PtrTxt);
			printf("\nArquivo criado com sucesso!!");
			getch();
		}
		else
			printf("\nArquivo nao criado");
	}
	else
	{
		printf("\nArquivo Pronto para uso!!\n");
		getch();
		fclose(PtrTxt);
	}
}

void MostrarTXTCaracter(char NomeArq[50])//lendo caracter por caracter, send mais lento
{
	FILE * PtrTxt = fopen(NomeArq,"r");
	char caracter;
	caracter = fgetc(PtrTxt);
	while(!feof(PtrTxt))
	{
		printf("%c",caracter);
		caracter = fgetc(PtrTxt);
		Sleep(100);
	}
	getch();
	fclose(PtrTxt);
}
//ou
void MostrarTXTCaracter2(char NomeArq[50])//lendo linha por linha, sendo mais rapido
{
	FILE * PtrTxt = fopen(NomeArq,"r");
	char linha[100];
	fgets(linha,100,PtrTxt);
	while(!feof(PtrTxt))
	{
		printf("%s",linha);
		fgets(linha,100,PtrTxt);
		Sleep(100);
	}
	getch();
	fclose(PtrTxt);
}

int main (void)
{
	char NomeArq[50];
	printf("\nNome Arquivo: ");
	gets(NomeArq);
	verificaArq(NomeArq);
	MostrarTXTCaracter2(NomeArq);
	return 0;
}
