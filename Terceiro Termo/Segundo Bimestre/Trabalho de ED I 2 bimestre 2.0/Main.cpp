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
	printf("\n[1] Adicionar +1 Servidor\n");
	printf("[2] Remover Servidor\n");
	printf("[Espaco] Avancar +1 Unidade de Tempo\n");
	printf("[0] Sair e Exibir Relatorio\n");
	printf("\nEscolha uma opcao: ");
	return getche();
}

int main(void)
{
    TpDescritorCluster Cluster;
    char NomeArq[50];
    int op, UT = 0;
    int Qtde_Servidores;

    // --- VARIÁVEIS DE ESTATÍSTICA ALOCADAS LOCALMENTE NO MAIN ---
    int TotalProcessadosPorTipo[4] = {0, 0, 0, 0}; 
    int TempoEsperaTotalPorTipo[4] = {0, 0, 0, 0};

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
	
    FILE *Arq = fopen(NomeArq, "r");
    char Lixo[256];
    if (Arq != NULL)
        fgets(Lixo, sizeof(Lixo), Arq); // Pula cabeçalho do arquivo

    do
    {
        clrscr();
        printf("=== Unidade de Tempo Atual: %d ===\n", UT);
        
        MostrarSituacaoServidores(Cluster);
        
        op = Menu();

        switch(op)
        {
            case '1':	
                if(Cluster.qtde < 3)
                    AdicionarServidores(Cluster, 1);
                else
                    printf("\n[AVISO] Limite Maximo Excedido!\n");
                printf("\nPressione qualquer tecla..."); getch();
                break;

            case '2':	
                if(Cluster.qtde <= 1)
                    printf("\n[AVISO] Nao pode remover o unico servidor!\n");
                else
                    RemoverServidor(Cluster);
                printf("\nPressione qualquer tecla..."); getch();
                break;

            case ' ': 
                // Passando as variáveis locais criadas no main para a função tratá-las
                ExecutarProcessamentoServidores(Cluster, UT, TotalProcessadosPorTipo, TempoEsperaTotalPorTipo);
                
                if(Arq != NULL && !feof(Arq))
                    LerTarefaDoArquivo(Cluster, Arq, UT);
                
                UT++;
                break;
        }

    } while(op != '0');

    if(Arq != NULL) fclose(Arq);

    // Passando as variáveis locais criadas no main para exibir as estatísticas
    ExibirEstatisticasFinais(Cluster, TotalProcessadosPorTipo, TempoEsperaTotalPorTipo);

    printf("\nSimulacao Terminada. Pressione qualquer tecla para fechar.\n");
    getch();
    return 0;
}


