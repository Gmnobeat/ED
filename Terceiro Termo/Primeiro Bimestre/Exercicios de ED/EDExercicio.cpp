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

void GerarArqMaiuCHR (char NomeArq[50])
{
	FILE * PtrTexto = fopen(NomeArq,"r");
	FILE * PtrMaiusculo = fopen("Maiusculo.txt","w");
	char caracter;
	int cont1=0,cont2=0,cont3=0,cont4=0,cont5=0;
	caracter = toupper(fgetc(PtrTexto));
	while(!feof(PtrTexto))
	{
		if(caracter==40)//  (
			cont1++;
		if(caracter==41)//  )
			cont2++;
		if(caracter==123)//  {
			cont3++;
		if(caracter==125)//  }
			cont4++;
		if(caracter==10)//  pula linha
			cont5++;
		fputc(caracter,PtrMaiusculo);
		caracter = toupper(fgetc(PtrTexto));
	}
	fprintf(PtrMaiusculo, "Quantidade de (: %d\n", cont1);
	fprintf(PtrMaiusculo, "Quantidade de ): %d\n", cont2);
	fprintf(PtrMaiusculo, "Quantidade de {: %d\n", cont3);
	fprintf(PtrMaiusculo, "Quantidade de }: %d\n", cont4);
	fprintf(PtrMaiusculo, "Quantidade de Linhas: %d\n", cont5);
//	fputs("Quantidade de (",PtrMaiusculo);
//	printf("%d",cont1);
//	fputc('\n',PtrMaiusculo);
//	fputs("Quantidade de )",PtrMaiusculo);
//	printf("%d",cont2);
//	fputc('\n',PtrMaiusculo);
//	fputs("Quantidade de {",PtrMaiusculo);
//	printf("%d",cont3);
//	fputc('\n',PtrMaiusculo);
//	fputs("Quantidade de }",PtrMaiusculo);
//	printf("%d",cont4);
//	fputc('\n',PtrMaiusculo);
//	fputs("Quantidade de Linhas",PtrMaiusculo);
//	printf("%d",cont5);
	getch();
	fclose(PtrTexto);
	fclose(PtrMaiusculo);
}

void GerarArqMaiuSTR (char NomeArq[50])
{
	FILE * PtrTexto = fopen(NomeArq,"r");
	FILE * PtrMaiusculo = fopen("Maiusculo.txt","w");
	char frase[100];
	int i,cont1=0,cont2=0,cont3=0,cont4=0,cont5=0;
	fflush(stdin);
	fgets(frase,100,PtrTexto);
	while(!feof(PtrTexto))
	{
		for(i=0;i<strlen(frase);i++)
		{
			if(frase[i]==40)//  (
			cont1++;
			if(frase[i]==41)//  )
				cont2++;
			if(frase[i]==123)//  {
				cont3++;
			if(frase[i]==125)//  }
				cont4++;
			if(frase[i]==10)//  pula linha
				cont5++;
			frase[i] = toupper(frase[i]);
		}
		fputs(frase,PtrMaiusculo);
		fflush(stdin);
		fgets(frase,100,PtrTexto);
	}
	fprintf(PtrMaiusculo, "Quantidade de (: %d\n", cont1);
	fprintf(PtrMaiusculo, "Quantidade de ): %d\n", cont2);
	fprintf(PtrMaiusculo, "Quantidade de {: %d\n", cont3);
	fprintf(PtrMaiusculo, "Quantidade de }: %d\n", cont4);
	fprintf(PtrMaiusculo, "Quantidade de Linhas: %d\n", cont5);
	getch();
	fclose(PtrTexto);
	fclose(PtrMaiusculo);
	
}

int main (void)
{
	char NomeArq[50];
	printf("\nNome Arquivo: ");
	gets(NomeArq);
	verificaArq(NomeArq);
	//GerarArqMaiuCHR (NomeArq);
	GerarArqMaiuSTR(NomeArq);
	MostrarTXTCaracter("Maiusculo.txt");
	return 0;
}
