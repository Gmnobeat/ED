#include<stdio.h>
#include<conio2.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void Exercicio1(char NomeArq[50])
{
	FILE * PtrArq = fopen (NomeArq,"r");
	FILE * PtrMai = fopen ("Maiusculo.txt","w");	
	char caracter;
	caracter = toupper(fgetc(PtrArq));
	while(!feof(PtrArq))
	{
	
		fputc(caracter,PtrMai);
		caracter = toupper(fgetc(PtrArq));
	}
	fclose(PtrArq);
	fclose(PtrMai);
}

void Exercicio2 (char NomeArq[50])
{
	FILE * PtrArq = fopen (NomeArq,"r");
	char caracter;
	int contletra=0,contespaco=0;
	caracter = fgetc(PtrArq);
	while(!feof(PtrArq))
	{
		if((caracter >= 65 && caracter <=90) || (caracter >=97 && caracter <= 122))
			contletra++;
		if(caracter == 32)
			contespaco++;
		caracter = fgetc(PtrArq);
	}
	printf("A quantidade de letras foi de: %d\n",contletra);
	printf("A quantidade de espaco foi de: %d\n",contespaco);
	fclose(PtrArq);
}

void Exercicio3(void)
{
	FILE* PtrArq1 = fopen("1Exercicio3.txt","r+");
	FILE* PtrArq2 = fopen("2Exercicio3.txt","r+");
	char car1,car2;
	int cont=0;
	car1 = fgetc(PtrArq1);
	car2 = fgetc(PtrArq2);
	while(!feof(PtrArq1) && !feof(PtrArq2))
	{
		if(car1 != car2)
			cont++;
		car1 = fgetc(PtrArq1);
		car2 = fgetc(PtrArq2);
	}
	if(cont == 0 && feof(PtrArq1) && feof(PtrArq2))
		printf("Os Arquivos Sao iguais\n");
	else
		printf("Os Arquivos Sao diferentes\n");
	fclose(PtrArq1);
	fclose(PtrArq2);
}

void Exercicio4(char NomeArq[50])
{	
	FILE *PtrArq = fopen(NomeArq,"r");
	FILE *PtrPMai = fopen("PrimMaiu","w");
	char caracter;
	caracter = toupper(fgetc(PtrArq));
	while(!feof(PtrArq))
	{
		fputc(caracter,PtrPMai);
		if(caracter == 32)//32 e o espaço da tabela ascii
			caracter = toupper(fgetc(PtrArq));
		else	
			caracter = fgetc(PtrArq);
	}
	fclose(PtrArq);
	fclose(PtrPMai);	
}

void Exercicio5(void)
{	
	
}

int menu (void)	
{
	clrscr();
	printf("   *** Menu ***\n");
	printf("[1] Exercicio 1\n");
	printf("[2] Exercicio 2\n");
	printf("[3] Exercicio 3\n");
	printf("[4] Exercicio 4\n");
	printf("[5] Exercicio 5\n");
	printf("[6] Exercicio 6\n");
	printf("[7] Exercicio 7\n");
	printf("[8] Exercicio 8\n");
	printf("[9] Exercicio 9\n");
	printf("[10] Exercicio 10\n");
	printf("[11] Exercicio 11\n");
	printf("[12] Exercicio 12\n");
	printf("[13] Exercicio 13\n");
	printf("[14] Exercicio 14\n");
	printf("[15] Exercicio 15\n");
	printf("[16] Exercicio 16\n");
	printf("[17] Exercicio 17\n");
	printf("[18] Exercicio 18\n");
	printf("[19] Exercicio 19\n");
	printf("[20] Exercicio 20\n");
	printf("[0] Sair\n");
	return getch();// getch retorna um caracter
}
void VerificaAqr(char NomeArq[50])
{
	FILE * PtrArq = fopen(NomeArq,"r");
	if(PtrArq == NULL)
	{
		printf("Esse arqivo nao existe\n");
		printf("Deseja criar um novo? S/N\n");
		if(toupper(getch()) == 'N')
			printf("Arquivo nao foi aberto\n");	
		else
		{
			FILE * PtrArq = fopen(NomeArq,"w");
			printf("Arquivo criado!!\n");
			fclose(PtrArq);
		}
	}
	else
	{
		printf("Arquivo pronto para uso\n");
		fclose(PtrArq);
	}
}

void Exercicio5(void)
{
	FILE* PtrArq = fopen("Aposta.txt","w");
	int n5=05,n15=15,n8=8,n22=22,n43=43,n53=53,n32=32,n10=10,n23=23,n16=16,n09=9,n44=44,n59=59,n07=07,n21=21,n29=29,n31=31,n1=01;
	fprintf("+-----------------------------------------------------------------\n");
	fprintf("|   Data   | N1 | N2 | N3 | N4 | N5 | N6 | N7 |\n");
	fprintf("|----------|----|----|----|----|----|----|----|\n");
	fprintf("|10/08/2012| %d | %d | %d | %d | %d | %d | %d |\n",n5, n15, n8, n22, n43, n53,n32);
	fprintf("|10/08/2012| %d | %d | %d | %d | %d | %d | %d |\n",n10, n23, n43, n15, n16, n09, n44);
	fprintf("|11/08/2012| %d | %d | %d | %d | %d | %d | %d |\n",n59, n32 ,n07, n8, n21, n29, n31);
	fprintf("|11/08/2012| %d | %d | %d | %d | %d | %d | %d |\n",n23, n43, n15, n32, n07, n8, n01);
	fprintf("+----------+----+----+----+----+----+----+----+\n");
	fclose(PtrArq);
}

int main (void)
{
	char NomeArq[50];
	int op;
	printf("Digite o nome do arq\n");
	fflush(stdin);
	gets(NomeArq);
	VerificaAqr(NomeArq);
	do
	{
		op = menu();
		switch(op)
		{
			case '1': 	clrscr();
						Exercicio1(NomeArq);
						printf("Executado com Sucesso\n");
						getch();
						break; 
			case '2': 	clrscr();
						Exercicio2(NomeArq);
						printf("Executado com Sucesso\n");
						getch();
						break;
			case '3':	clrscr();
						Exercicio3();
						printf("Executado com Sucesso\n");
						getch();
						break;
			case '4':	clrscr();
						Exercicio4(NomeArq);
						printf("Executado com Sucesso\n");
						getch();
						break;
			case '5':	clrscr();
						Exercicio5();
						printf("Executado com Sucesso\n");
						getch();
						break;			
		}
	}while(op != '0');
	return 0;
}
