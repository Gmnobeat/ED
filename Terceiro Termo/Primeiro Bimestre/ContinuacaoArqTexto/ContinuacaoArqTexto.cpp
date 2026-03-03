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

void LerFormatado(char NomeArq[50])
{
	int Codigo,Estoque;
	float Preco;
	char Descr[25];
	FILE * PtrProd = fopen(NomeArq,"r");
	fscanf(PtrProd,"%d %s %d %f",&Codigo,&Descr,&Estoque,&Preco);
	while(!feof(PtrProd))
	{
		printf("Codigo: %d\n",Codigo);
		printf("Descricao: %s\n",Descr);
		printf("Estoque: %d\n",Estoque);
		printf("Preco: R$ %f\n\n",Preco);
		Sleep(10);
		fscanf(PtrProd,"%d %s %d %f",&Codigo,&Descr,&Estoque,&Preco);
	}
	fclose(PtrProd);
	getch();
}

void ProdutoRelatorio(char NomeArq[50])
{
	int Codigo,Estoque,Qtd=0;
	float Preco,TotalPreco=0;
	char Descr[25];
	FILE * PtrProd = fopen(NomeArq,"r");
	FILE * PtrRel = fopen("Relatorio.txt","w");
	fscanf(PtrProd,"%d %s %d %f",&Codigo,&Descr,&Estoque,&Preco);
	fprintf(PtrRel,"\t\tRelatorio\n");
	fprintf(PtrRel,"---------------------------------\n");
	fprintf(PtrRel,"Codigo\tDescricao\tEstoque\tPreco\n");
	fprintf(PtrRel,"---------------------------------\n");
	while(!feof(PtrProd))
	{
		fprintf(PtrRel,"%d\t",Codigo);
		fprintf(PtrRel,"%s\t",Descr);
		fprintf(PtrRel,"%d\t",Estoque);
		fprintf(PtrRel,"%2.f\n",Preco);
		Qtd+=Estoque;
		TotalPreco += Preco*Estoque;
		Sleep(10);
		fscanf(PtrProd,"%d %s %d %f",&Codigo,&Descr,&Estoque,&Preco);
	}
	fprintf(PtrRel,"---------------------------------\n");
	fprintf(PtrRel,"Quantidade de Produtos: %d\n",Qtd);
	fprintf(PtrRel,"Preco Total de Produtos: R$ %f\n",TotalPreco);
	fclose(PtrProd);
	fclose(PtrRel);
	getch();
}


char Menu(void)
{
	printf("***  MENU  ***\n");
	printf("[A] -----\n");
	printf("[B] -----\n");
	printf("[C] -----\n");
	printf("[D] -----\n");
	printf("[E] -----\n");
	printf("[F] -----\n");
	printf("[G] Ler Produtos \n");
	printf("[H] Relatorio de Produtos\n");
	printf("[ESC] sair\n");
	return toupper(getch());
}

int main (void)
{
	char NomeArq[50],op;
	op = Menu();
	printf("\nNome Arquivo: ");
	gets(NomeArq);
	verificaArq(NomeArq);
	do
	{
		switch(op)
		{
			case 'G': LerFormatado(NomeArq);
						break;
			case 'H': ProdutoRelatorio(NomeArq);
						break;
		}
	}
	while(op!=27);
	
	//MostrarTXTCaracter(NomeArq);
	//MostrarTXTString(NomeArq);
	//gravarCHR(NomeArq);
	//gravarSTR(NomeArq);
	return 0;
}
