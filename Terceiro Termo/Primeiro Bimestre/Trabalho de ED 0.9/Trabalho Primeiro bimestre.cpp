#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio2.h>
#include<stdlib.h>
#include<windows.h>
#include"TADFilaPrioridade.h"

//Igor Nakamura Moretto
// Gustavo Malacrida Mazetti
// Leonardo Gabriel Santos Mineo

struct TpTempTarefa
{
	int TempI, TempF, Quant = 0;
};

struct TpProc
{
	TpTarefas Aux;
	int TempI, TempF, Total = 0;
};

void Cancelar(int CI,int LI,int CF,int LF)
{
    int i;
    gotoxy(CI,LI);
    printf("\\\\");
    gotoxy(CF,LF);
    printf("//");
	for(i=1;i<5;i++){
    //Sleep(50);
	if(CI==CF)
    {
    	printf("%c",206);
    	i++;
	}
	gotoxy(CI+i,LI+i);
  	printf("\\\\");
  	gotoxy(CF-i,LF+i);
  	printf("//");
  }
 
}

void Impressao_Processador(int CI,int LI,int CF,int LF)
{
	int i; 
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	for(i=CI+1; i<CF; i++)
	{
		Sleep(5);
		gotoxy(i,LI);
		printf("%c",205);

		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1; i<LF; i++)
	{
		Sleep(5);
		gotoxy(CI,i);
		printf("%c",186);

		gotoxy(CF,i);
		printf("%c",186);
	}
}
void Moldura_Processador(int CI,int LI,int CF,int LF)
{
	int i; 
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	for(i=CI+1; i<CF; i++)
	{
		Sleep(5);
		gotoxy(i,LI);
		printf("%c",205);

		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1; i<LF; i++)
	{
		Sleep(5);
		gotoxy(CI,i);
		printf("%c",186);

		gotoxy(CF,i);
		printf("%c",186);
	}
}
void Processador(int CI, int LI, int CF, int LF)
{
	int i;// CI = 3, LI = 3, CF = 13, LF = 8;
	
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	for(i=CI+1; i<CF; i++)
	{
		Sleep(10);
		gotoxy(i,LI);
		printf("%c",205);

		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1; i<LF; i++)
	{
		Sleep(10);
		gotoxy(CI,i);
		printf("%c",186);

		gotoxy(CF,i);
		printf("%c",186);
	}
}

void Moldura(void)
{
	
	textcolor(11);//12,11,
	Processador(4,3,22,9);
	Processador(27,3,45,9);
	Processador(50,3,68,9);
	Processador(73,3,91,9);
	textcolor(8);
	Moldura_Processador(2,2,24,29);
	Moldura_Processador(25,2,47,29);
	Moldura_Processador(48,2,70,29);
	Moldura_Processador(71,2,93,29);
	textcolor(11);
	Impressao_Processador(3,11,23,28);
	Impressao_Processador(26,11,46,28);
	Impressao_Processador(49,11,69,28);
	Impressao_Processador(72,11,92,28);
	textcolor(4);
	//Cancelar(10,4,14,4);
	//Cancelar(34,4,38,4);
	//Cancelar(56,4,60,4);
	//Cancelar(79,4,83,4);
	textcolor(8);
	int i, CI = 1, LI = 1, CF = 94, LF = 30;
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	for(i=CI+1; i<CF; i++)
	{
		Sleep(2.5);
		gotoxy(i,LI);
		printf("%c",205);

		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1; i<LF; i++)
	{
		Sleep(2.5);
		gotoxy(CI,i);
		printf("%c",186);
		
		gotoxy(CF,i);
		printf("%c",186);
	}
	
}

void ApagarProc(int CI,int LI,int CF,int LF)
{
  int i;
  gotoxy(CI,LI);
  printf("  ");
  gotoxy(CF,LF);
  printf("  ");
  for(i=1;i<5;i++){
	if(CI==CF)
    {
    	printf("%c",206);
    	i++;
	}
	gotoxy(CI+i,LI+i);
  	printf("  ");
  	gotoxy(CF-i,LF+i);
  	printf("  ");
  }
 
}

void verificaArq(char NomeArq[50])
{
	FILE * PtrTxt = fopen(NomeArq,"r");
	int i,sorteio;
	if(PtrTxt == NULL)
	{
		printf("\nErro de abertura!\n\nDeseja criar?");
		if(toupper(getche())=='S')
		{
			PtrTxt = fopen(NomeArq,"w");
			char tiposTarefas[4][20] = {"GRAVACAO_INTERNA", "GRAVACAO_EXTERNA", "LEITURA", "IMPRESSAO"};
			//O programa utiliza um vetor de strings com quatro tipos de tarefas. Em um laço de repetição, sorteia um tipo aleatório usando rand() e grava no arquivo com fprintf, uma tarefa por linha.
			// não tem coluna no arquivo por isso no na hora de printar coloco somente a linha
			for(i = 0 ; i < 1000; i++)
			{
				sorteio = rand() % 4;//sorteia  um numero de 0 a 3
				fprintf(PtrTxt,"%s\n",tiposTarefas[sorteio]);
			}
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

void ExtrairArq(char NomeArq[50], TpFilaPri &Rg)
{
	FILE* PtrArq = fopen(NomeArq,"r");
	TpTarefas Aux;
	fflush(stdin);
	fscanf(PtrArq,"%s",Aux.Tarefa);  
	while(!feof(PtrArq))
	{
		if(strcmp(Aux.Tarefa, "IMPRESSAO") == 0)
		{
			Aux.Prioridade = 4;
			Aux.UT = 3;
		}
		else
		{
			if(strcmp(Aux.Tarefa, "LEITURA") == 0)
			{
				Aux.Prioridade = 3;
				Aux.UT = 4;
			}
			else
			{
				if(strcmp(Aux.Tarefa, "GRAVACAO_INTERNA") == 0 )
				{
					Aux.Prioridade = 1;
					Aux.UT = 5;
				}
				else
					if(strcmp(Aux.Tarefa, "GRAVACAO_EXTERNA") == 0 )
					{
						Aux.Prioridade = 2;
						Aux.UT = 8;
					}
			}
		}	
		Aux.TempoChegada = 0;
		Inserir(Rg,Aux);
		fflush(stdin);
		fscanf(PtrArq,"%s",Aux.Tarefa);
	}
	fclose(PtrArq);
}

int main (void)
{
	TpProc Proc1,Proc2,Proc3,Proc4;
	TpTempTarefa Impre, Leit, Interna, Externa;
	TpFilaPri Fila, Prox1,Prox2,Prox3,Prox4;
	int UTTotal=0, pos =0, i, flag[4];
	int TempoTotalProc[4] = {0,0,0,0};
	// Vetor 4 para usar os indices 1, 2, 3 e 4 das prioridades
	float SomaEspera[4] = {0, 0, 0, 0}; 
	int QtdTipo[4] = {0, 0, 0, 0}; // Para saber quando o TXT acabou
	float Tot1,Tot2,Tot3,Tot4;
	// E ZERE OS PROCESSADORES AQUI ANTES DO DO...WHILE:
	Proc1.Aux.UT = 0; Proc2.Aux.UT = 0; Proc3.Aux.UT = 0; Proc4.Aux.UT = 0;//Zerar o UT dos processadores evita que eles comecem com lixo de memória.
	char NomeArq[50], TC1[50],TC2[50],TC3[50],TC4[50];
	printf("\nNome Arquivo: ");
	fflush(stdin);
	gets(NomeArq);
	verificaArq(NomeArq);
	clrscr();
	FILE* PtrArq = fopen(NomeArq,"r");
	Inicializar(Fila);
	Inicializar(Prox1);
	Inicializar(Prox2);
	Inicializar(Prox3);
	Inicializar(Prox4);
	Moldura();
	ExtrairArq(NomeArq,Fila);
	for(i=0; i<MAXFILA && !Vazio(Fila); i++)
	{
		if(!Vazio(Fila))
			Inserir(Prox1,Retirar(Fila));
		if(!Vazio(Fila))
			Inserir(Prox2,Retirar(Fila));
		if(!Vazio(Fila))
			Inserir(Prox3,Retirar(Fila));
		if(!Vazio(Fila))
			Inserir(Prox4,Retirar(Fila));
	}
	for(i=0;i<4;i++)
		flag[i]= 0;
	
	textcolor(7);
//	Exibir(Fila);
	do
	{
		if(UTTotal % 4 == 0)
		{
			if(!Vazio(Prox1))
			{
				if(Proc1.Aux.UT == 0)
				{
					if(flag[0] != 0)
						flag[0] ++;
					else{
						gotoxy(97, 10);
						printf("                ");
						gotoxy(97, 10);
						printf("%s",TC1);
					}
					Proc1.Aux = Retirar(Prox1);
					strcpy(TC1,Proc1.Aux.Tarefa);
					Proc1.TempI = UTTotal;
					TempoTotalProc[0] += Proc1.Aux.UT;
					SomaEspera[Proc1.Aux.Prioridade-1] += (UTTotal - Proc1.Aux.TempoChegada) + Proc1.Aux.UT;
					QtdTipo[Proc1.Aux.Prioridade -1]++;//Incrementa em 1 a posição do vetor correspondente à prioridade.
					
					gotoxy(5,6);
					printf("                ");
					ApagarProc(10,4,14,4);
					gotoxy(5,6);
					printf("%s",Proc1.Aux.Tarefa);
				}
			}	
			else
			{
				gotoxy(5,6);
				printf("                ");
				Cancelar(10,4,14,4);
			}
			
			if(!Vazio(Prox2))
			{
				if(Proc2.Aux.UT == 0)
				{
					if(flag[1] != 0)
						flag[1] ++;
					else{
						gotoxy(97, 14);
						printf("                ");
						gotoxy(97, 14);
						printf("%s",TC2);
					}
					Proc2.Aux = Retirar(Prox2); 
					strcpy(TC2,Proc2.Aux.Tarefa);
					TempoTotalProc[1] += Proc2.Aux.UT;
					SomaEspera[Proc2.Aux.Prioridade-1] += (UTTotal - Proc2.Aux.TempoChegada) + Proc2.Aux.UT;
					QtdTipo[Proc2.Aux.Prioridade-1]++;
					
					gotoxy(28,6);
					printf("                ");
					ApagarProc(34,4,38,4);
					gotoxy(28,6);
					printf("%s",Proc2.Aux.Tarefa);
				}
			}		
			else
			{
				gotoxy(28,6);
				printf("                ");
				Cancelar(34,4,38,4);
			}
			
			if(!Vazio(Prox3))
			{
				if(Proc3.Aux.UT == 0)
				{
					if(flag[2] != 0)
						flag[2] ++;
					else{
						gotoxy(97, 17);
						printf("                ");
						gotoxy(97, 17);
						printf("%s",TC3);
					}
					Proc3.Aux = Retirar(Prox3); 
					strcpy(TC3,Proc3.Aux.Tarefa);
					TempoTotalProc[2] += Proc3.Aux.UT;
					SomaEspera[Proc3.Aux.Prioridade-1] += (UTTotal - Proc3.Aux.TempoChegada) + Proc3.Aux.UT;
					QtdTipo[Proc3.Aux.Prioridade-1]++;
					
					gotoxy(51,6);
					printf("                ");
					ApagarProc(56,4,60,4);
					gotoxy(51,6);
					printf("%s",Proc3.Aux.Tarefa);
				}
			}	
			else
			{
				gotoxy(51,6);
				printf("                ");
				Cancelar(56,4,60,4);
			}
			
			if(!Vazio(Prox4))
			{
				if(Proc4.Aux.UT == 0)
				{
					if(flag[3] != 0)
						flag[3] ++;
					else{
						gotoxy(97, 21);
						printf("                ");
						gotoxy(97, 21);
						printf("%s",TC4);
					}
					Proc4.Aux = Retirar(Prox4); 
					strcpy(TC4,Proc4.Aux.Tarefa);
					TempoTotalProc[3] += Proc4.Aux.UT;
					SomaEspera[Proc4.Aux.Prioridade-1] += (UTTotal - Proc4.Aux.TempoChegada) + Proc4.Aux.UT;
					QtdTipo[Proc4.Aux.Prioridade-1]++;
					
					gotoxy(74,6);
					printf("                ");
					ApagarProc(79,4,83,4);
					gotoxy(74,6);
					printf("%s",Proc4.Aux.Tarefa);
				}
			}
			else
			{
				gotoxy(74,6);
				printf("                ");
				Cancelar(79,4,83,4);
			}	
			for (i = 0; i < 5; i++)
			{	
			    gotoxy(4, 14 + (i * 3)); 
			    printf("                "); 
			    if (i <= Prox1.FIM)
			    {
			        gotoxy(4, 14 + (i * 3));
			        printf("%s", Prox1.FILA[i].Tarefa);
			    }
			}
			for (i=0;i<5;i++)
			{
				gotoxy(28,14+(i*3));
				printf("                ");
				if(i<= Prox2.FIM)
				{
					gotoxy(28,14+(i*3));
					printf("%s",Prox2.FILA[i].Tarefa);
				}
			}
			for (i=0;i<5;i++)
			{
				gotoxy(51,14+(i*3));
				printf("                ");
				if(i<= Prox3.FIM)
				{
					gotoxy(51,14+(i*3));
					printf("%s",Prox3.FILA[i].Tarefa);
				}
			}
			for (i=0;i<5;i++)
			{
				gotoxy(74,14+(i*3));
				printf("                ");
				if(i<= Prox4.FIM)
				{
					gotoxy(74,14+(i*3));
					printf("%s",Prox4.FILA[i].Tarefa);
				}
			}		
			// printar os 5 proximos numeros e tem que verificar para printar ate o final do vetos caso estiver acabando as tarefas 	
		}
		
		gotoxy(5,4);
		if(Proc1.Aux.UT > 0) 
			printf("%d ut", Proc1.Aux.UT); 
		else 
			printf("      ");
		gotoxy(28,4);
		if(Proc2.Aux.UT > 0) 
			printf("%d ut", Proc2.Aux.UT); 
		else 
			printf("      ");
		gotoxy(51,4);
		if(Proc3.Aux.UT > 0) 
			printf("%d ut", Proc3.Aux.UT); 
		else 
			printf("      ");
		gotoxy(74,4);
		if(Proc4.Aux.UT > 0) 
			printf("%d ut", Proc4.Aux.UT); 
		else 
			printf("      ");
		//
		if(Proc1.Aux.UT == 0)
		{
			gotoxy(5,6);
			printf("                ");
			gotoxy(5,4);
			printf("      ");
			Cancelar(10,4,14,4);	
		}
		if(Proc1.Aux.UT != 0)
			Proc1.Aux.UT--;
		
		if(Proc2.Aux.UT == 0)
		{
			gotoxy(28,6);
			printf("                ");
			gotoxy(28,4);
			printf("      ");
			Cancelar(34,4,38,4);
		}
		if(Proc2.Aux.UT != 0)
			Proc2.Aux.UT--;
		
		
		if(Proc3.Aux.UT == 0)
		{
			gotoxy(51,6);
			printf("                ");
			gotoxy(51,4);
			printf("      ");
			Cancelar(56,4,60,4);
		}
			
		if(Proc3.Aux.UT != 0)
			Proc3.Aux.UT--;
		
		if(Proc4.Aux.UT == 0)
		{
			gotoxy(74,6);
			printf("                ");
			gotoxy(74,4);
			printf("      ");
			Cancelar(79,4,83,4);
		}
			
		if(Proc4.Aux.UT != 0)
			Proc4.Aux.UT--;
		
		
		
		
		UTTotal ++;
		
		gotoxy(97,6);
		printf("Timer");
		gotoxy(97,7);
		printf("                ");
		gotoxy(97,7);
		printf("%d",UTTotal);
		if(Vazio(Prox1))
		{
			gotoxy(5,6);
			printf("                ");
			gotoxy(5,4);
			printf("      ");
			Cancelar(10,4,14,4);	
		}
		
		if(Vazio(Prox2))
		{
			gotoxy(28,6);
			printf("                ");
			gotoxy(28,4);
			printf("      ");
			Cancelar(34,4,38,4);
		}
		
		
		if(Vazio(Prox3))
		{
			gotoxy(51,6);
			printf("                ");
			gotoxy(51,4);
			printf("      ");
			Cancelar(56,4,60,4);
		}
		
		if(Vazio(Prox4))
		{
			gotoxy(74,6);
			printf("                ");
			gotoxy(74,4);
			printf("      ");
			Cancelar(79,4,83,4);
		}
		//Sleep(1000);	
	//		
	} while(!kbhit() && (!Vazio(Prox1) || !Vazio(Prox2) || !Vazio(Prox3) || !Vazio(Prox4) || Proc1.Aux.UT > 0 || Proc2.Aux.UT > 0 || Proc3.Aux.UT > 0 || Proc4.Aux.UT > 0));
	
	Moldura();
	//while(!kbhit() && !Vazio(Fila));
// gotoxy(4,12); p1
// gotoxy(24,12); p2
// gotoxy(44,12); p3
// gotoxy(64,12); p4
	// TELA FINAL DE RESULTADOS
	clrscr();
	textcolor(15);
	printf("\n==== RESULTADOS FINAIS DA SIMULACAO ====\n\n");
	
	printf("* * *  Quantos processos cada processador executou?\n * * * ");
	printf("Proc 1: %d | Proc 2: %d | Proc 3: %d | Proc 4: %d\n\n", flag[0], flag[1], flag[2], flag[3]);

	printf("# # # Qual o tempo medio que cada processador dispende para atender uma tarefa?\n # # # ");
	if(flag[0]>0)
	{
		Tot1=(float)TempoTotalProc[0]/flag[0];
		printf("Proc 1: %.2f UTs\n",Tot1);	
	}
	
	if(flag[1]>0) 
	{
		Tot2 = (float)TempoTotalProc[1]/flag[1];
		printf("Proc 2: %.2f UTs\n",Tot2);	
	}
	if(flag[2]>0) 
	{
		Tot3= (float)TempoTotalProc[2]/flag[2];
		printf("Proc 3: %.2f UTs\n",Tot3);	
	}
	if(flag[3]>0) 
	{
		Tot4=  (float)TempoTotalProc[3]/flag[3];
		printf("Proc 4: %.2f UTs\n\n",Tot4);	
	}

	printf("# # # Qual o tempo medio para atender cada tipo de tarefa? (Espera + Execucao)# # #\n");
	
	
	char nomes[4][20] = {"Gravacao Interna", "Gravacao Externa", "Leitura", "Impressao"};
	
	// O laco roda de 0 a 3, que sao os indices do seu vetor de tamanho 4
	for(int j = 0; j < 4; j++) {
		if(QtdTipo[j] > 0) {
			printf(" - %s: %.2f UTs\n", nomes[j], SomaEspera[j] / QtdTipo[j]);
		}
	}

	printf("\nFINALIZADO \n");
	getch();

	return 0;
}

