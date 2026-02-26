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
void MostrarTXTString(char NomeArq[50])//lendo linha por linha, sendo mais rapido
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

void gravarCHR(char NomeArq[50])
{
	FILE *PtrTXT =fopen(NomeArq,"a");
	char caracter;
	clrscr();
	printf("Digite o texto e pressione ESC para finalizar: \n");
	caracter = getche(); // getche mostra
	while(caracter != 27)
	{
		if(caracter==13)
		{
			fputc('\n',PtrTXT);
			printf("\n");
		}
		else
			fputc(caracter,PtrTXT);//variavel primeiro e depois o ponteiro
		caracter = getche();
	}
	fclose(PtrTXT);
}

void gravarSTR(char NomeArq[50])
{
	FILE *PtrTXT =fopen(NomeArq,"a");
	char frase[100];
	clrscr();
	printf("Digite o texto e pressione enter em uma linha vazia para finalizar: \n");
	fflush(stdin);
	gets(frase); // getche mostra
	while(strcmp(frase,"\0") != 0)
	{	
		fputs(frase,PtrTXT);//variavel primeiro e depois o ponteiro
		fputs("\n",PtrTXT);
		fflush(stdin);
		gets(frase);
	}
	fclose(PtrTXT);
}

int main (void)
{
	char NomeArq[50];
	printf("\nNome Arquivo: ");
	gets(NomeArq);
	verificaArq(NomeArq);
	//MostrarTXTCaracter(NomeArq);
	//MostrarTXTString(NomeArq);
	//gravarCHR(NomeArq);
	gravarSTR(NomeArq);
	return 0;
}
