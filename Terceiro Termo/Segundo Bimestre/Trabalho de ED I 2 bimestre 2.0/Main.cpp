//Gustavo Malacrida Mazetti
//Igor Nakamura moretto
//Leonardo Gabriel Santos Mineo

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio2.h>
#include<ctype.h>
#include "TADDeTudo.h"

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

int Menu(void)
{
	printf("[1] Adicionar +1 Servidor\n");
	printf("[2] Remover Servidor\n");
	
	return getche();
}

int main(void)
{
    TpDescritorCluster Cluster;
    char NomeArq[50];
    int op, UT = 0;
    int Qtde_Servidores;

    printf("Digite o nome do Arq:\n");
    gets(NomeArq);
    verificaArq(NomeArq);
    clrscr();

    printf("Quantos Servidores serao utilizados?(max 3)\n");
    scanf("%d", &Qtde_Servidores);
    while(Qtde_Servidores > 3 || Qtde_Servidores <= 0)
    {
        printf("Essa Quantidade nao e valida\n");
        scanf("%d", &Qtde_Servidores);
    }

    InicializarCluster(Cluster);
    AdicionarServidores(Cluster, Qtde_Servidores);

    // abre o arquivo e pula o cabecalho
    FILE *Arq = fopen(NomeArq, "r");
    char Lixo[256];
    fgets(Lixo, sizeof(Lixo), Arq);

    do
    {
        clrscr();
        printf("=== Unidade de Tempo: %d ===\n", UT);
        op = Menu();

        switch(op)
        {
            case '1':
                AdicionarServidores(Cluster, 1);
                break;

            case '2':
                RemoverServidor(Cluster);
                break;
        }

        // a cada unidade de tempo le uma tarefa do arquivo
        LerTarefaDoArquivo(Cluster, Arq);

        UT++;

    } while(op != '0' && !feof(Arq));

    fclose(Arq);
    return 0;
}
