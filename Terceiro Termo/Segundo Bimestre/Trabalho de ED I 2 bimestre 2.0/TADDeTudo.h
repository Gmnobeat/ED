struct TpTarefas
{
	char TipoRequisicao[50], ID_Cliente[50], OrigemIP[50];
	int TempoProcessamento, TamanhoKB, prioridade, TempoInicio;
};

struct TpNoTarefas 
{
	TpTarefas Tarefas;
	TpNoTarefas *prox;
};

struct TpDescritorFila 
{
	TpNoTarefas *inicio, *fim;
	int qtde;
};

struct TpServidores
{
	int ID_Servidor;
	TpDescritorFila *FilaTarefas;
	TpServidores *ant, *prox; 
};

struct TpDescritorCluster
{
	TpServidores *inicio, *fim;
	int qtde;	
};

// --- FUNÇÕES OPERACIONAIS ---

void InicializarCluster (TpDescritorCluster &C)
{
	C.qtde = 0; 
	C.inicio = C.fim = NULL;
}

TpServidores *NovoServidor(int ID)
{
    TpServidores *Novo = new TpServidores;
    Novo->ID_Servidor = ID;
    Novo->ant = Novo->prox = NULL;
    Novo->FilaTarefas = new TpDescritorFila;  
    Novo->FilaTarefas->inicio = Novo->FilaTarefas->fim = NULL;
    Novo->FilaTarefas->qtde = 0;              
    return Novo;
}

TpNoTarefas *NovoTarefas(TpTarefas Tarefas)
{
	TpNoTarefas *Novo = new TpNoTarefas;
	strcpy(Novo->Tarefas.TipoRequisicao, Tarefas.TipoRequisicao);
	strcpy(Novo->Tarefas.ID_Cliente, Tarefas.ID_Cliente);
	strcpy(Novo->Tarefas.OrigemIP,Tarefas.OrigemIP);
	Novo->Tarefas.TempoProcessamento = Tarefas.TempoProcessamento;
	Novo->Tarefas.TamanhoKB = Tarefas.TamanhoKB;
	Novo->Tarefas.prioridade = Tarefas.prioridade;
	Novo->Tarefas.TempoInicio = Tarefas.TempoInicio;
	Novo->prox = NULL;
	return Novo;
}

void AdicionarServidores(TpDescritorCluster &C, int QtdServidores)
{
    for(int i = 1; i <= QtdServidores; i++)
    {
        int proximoID = 1;
        if(C.fim != NULL)
            proximoID = C.fim->ID_Servidor + 1;

        TpServidores *Novo = NovoServidor(proximoID);
        if(C.inicio == NULL)
        {
            C.inicio = C.fim = Novo;
        }
        else
        {
            Novo->ant   = C.fim;
            C.fim->prox = Novo;
            C.fim       = Novo;
        }
        C.qtde++;
        printf("Servidor %d Inicializado e Ligado ao Cluster!\n", Novo->ID_Servidor);
    }
}

void AdicionarTarefaFilaExcluindoID(TpDescritorCluster &C, TpTarefas Tarefa, int IDExcluido)
{
    TpServidores *Atual = C.inicio;
    TpServidores *MenorQtde = NULL;

    while(Atual != NULL)
    {
        if(Atual->ID_Servidor != IDExcluido)
        {
            if(MenorQtde == NULL || Atual->FilaTarefas->qtde < MenorQtde->FilaTarefas->qtde)
                MenorQtde = Atual;
        }
        Atual = Atual->prox;
    }

    if(MenorQtde == NULL) return;

    TpNoTarefas *Novo = NovoTarefas(Tarefa);

    if(MenorQtde->FilaTarefas->inicio == NULL)
    {
        MenorQtde->FilaTarefas->inicio = MenorQtde->FilaTarefas->fim = Novo;
    }
    else if(Novo->Tarefas.prioridade < MenorQtde->FilaTarefas->inicio->Tarefas.prioridade)
    {
        Novo->prox = MenorQtde->FilaTarefas->inicio;
        MenorQtde->FilaTarefas->inicio = Novo;
    }
    else
    {
        TpNoTarefas *Aux = MenorQtde->FilaTarefas->inicio;
        while(Aux->prox != NULL && Aux->prox->Tarefas.prioridade <= Novo->Tarefas.prioridade)
            Aux = Aux->prox;

        Novo->prox = Aux->prox;
        Aux->prox  = Novo;

        if(Novo->prox == NULL)
            MenorQtde->FilaTarefas->fim = Novo;
    }
    MenorQtde->FilaTarefas->qtde++;
}

void AdicionarTarefaNaFila(TpDescritorCluster &C, TpTarefas Tarefa)
{
    AdicionarTarefaFilaExcluindoID(C, Tarefa, -1);
}

void LerTarefaDoArquivo(TpDescritorCluster &C, FILE *Arq, int UT)
{
    if(feof(Arq)) return;

    char TipoRequisicao[50], ID_Cliente[50], OrigemIP[50];
    int TempoProcessamento, TamanhoKB;

    if(fscanf(Arq, "%s %d %s %s %d", TipoRequisicao, &TempoProcessamento, ID_Cliente, OrigemIP, &TamanhoKB) == 5)
    {
        TpTarefas T;
        strcpy(T.TipoRequisicao, TipoRequisicao);
        strcpy(T.ID_Cliente,     ID_Cliente);
        strcpy(T.OrigemIP,       OrigemIP);
        T.TempoProcessamento = TempoProcessamento;
        T.TamanhoKB          = TamanhoKB;
        T.TempoInicio        = UT;
        
        int prioridade = 3;
        if(stricmp(TipoRequisicao, "TempoReal") == 0)
            prioridade = 1;
        else if(stricmp(TipoRequisicao, "RequisicaoAPI") == 0)
            prioridade = 2;
        else if(stricmp(TipoRequisicao, "Background") == 0)
            prioridade = 3;

        T.prioridade = prioridade;
        AdicionarTarefaNaFila(C, T);
    }
}

void RemoverServidor(TpDescritorCluster &C)
{
    if(C.qtde <= 1) return;

    TpServidores *Remover = C.fim;

    C.fim = Remover->ant;
    C.fim->prox = NULL;
    C.qtde--;

    TpNoTarefas *Tarefa = Remover->FilaTarefas->inicio;
    while(Tarefa != NULL)
    {
        TpNoTarefas *Prox = Tarefa->prox;
        AdicionarTarefaFilaExcluindoID(C, Tarefa->Tarefas, Remover->ID_Servidor);
        delete Tarefa;
        Tarefa = Prox;
    }

    delete Remover->FilaTarefas;
    delete Remover;
    printf("\nServidor removido e tarefas redistribuidas!\n");
}

// --- FUNÇÕES DE PROCESSAMENTO E INTERFACE VISUAL ---

// Passando os vetores criados no main por referência (&)
void ExecutarProcessamentoServidores(TpDescritorCluster &C, int UTAtual, int (&TotalProcessados)[4], int (&TempoEsperaTotal)[4])
{
    TpServidores *Serv = C.inicio;
    while(Serv != NULL)
    {
        if(Serv->FilaTarefas->inicio != NULL)
        {
            TpNoTarefas *Executando = Serv->FilaTarefas->inicio;
            Executando->Tarefas.TempoProcessamento--;

            if(Executando->Tarefas.TempoProcessamento <= 0)
            {
                int p = Executando->Tarefas.prioridade;
                TempoEsperaTotal[p] += (UTAtual - Executando->Tarefas.TempoInicio);
                TotalProcessados[p]++;

                Serv->FilaTarefas->inicio = Executando->prox;
                if(Serv->FilaTarefas->inicio == NULL)
                    Serv->FilaTarefas->fim = NULL;

                delete Executando;
                Serv->FilaTarefas->qtde--;
            }
        }
        Serv = Serv->prox;
    }
}

void MostrarSituacaoServidores(TpDescritorCluster &C)
{
    printf("\n======================= ESTADO DO CLUSTER =======================\n");
    TpServidores *Serv = C.inicio;
    if(Serv == NULL)
    {
        printf("Nenhum servidor ativo.\n");
        return;
    }
    while(Serv != NULL)
    {
        printf("Servidor ID: %d | Total de Tarefas: %d\n", Serv->ID_Servidor, Serv->FilaTarefas->qtde);
        TpNoTarefas *Aux = Serv->FilaTarefas->inicio;
        if(Aux == NULL)
        {
            printf("   [ OCIOSO ]\n");
        }
        else
        {
            printf("   => EM EXECUCAO: [%s] Restam: %d UT (Prioridade: %d)\n", 
                   Aux->Tarefas.ID_Cliente, Aux->Tarefas.TempoProcessamento, Aux->Tarefas.prioridade);
            
            Aux = Aux->prox;
            if(Aux != NULL)
            {
                printf("   => FILA DE ESPERA: ");
                while(Aux != NULL)
                {
                    printf("[%s (P:%d)] -> ", Aux->Tarefas.ID_Cliente, Aux->Tarefas.prioridade);
                    Aux = Aux->prox;
                }
                printf("FIM\n");
            }
        }
        printf("-----------------------------------------------------------------\n");
        Serv = Serv->prox;
    }
}

// Passando os vetores criados no main por referência (&) para exibir no relatório
void ExibirEstatisticasFinais(TpDescritorCluster &C, int (&TotalProcessados)[4], int (&TempoEsperaTotal)[4])
{
    clrscr();
    printf("\n=================================================================\n");
    printf("                    RELATORIO ESTATISTICO FINAL                  \n");
    printf("=================================================================\n\n");

    const char* tipos[] = {"", "Tempo Real", "Requisicao API", "Background"};

    printf("1. REQUISICOES PROCESSADAS POR TIPO:\n");
    for(int i = 1; i <= 3; i++)
        printf("   - %s: %d\n", tipos[i], TotalProcessados[i]);

    printf("\n2. TEMPO MEDIO DE ESPERA EM FILA:\n");
    for(int i = 1; i <= 3; i++)
    {
        double media = 0.0;
        if(TotalProcessados[i] > 0)
            media = (double)TempoEsperaTotal[i] / TotalProcessados[i];
        printf("   - %s: %.2f unidades de tempo\n", tipos[i], media);
    }

    printf("\n3. REQUISICOES REMANESCENTES NAS FILAS:\n");
    int totalSobra = 0;
    TpServidores *Serv = C.inicio;
    while(Serv != NULL)
    {
        if(Serv->FilaTarefas->qtde > 0)
        {
            printf("   - Servidor %d possui: %d tarefas pendentes\n", Serv->ID_Servidor, Serv->FilaTarefas->qtde);
            totalSobra += Serv->FilaTarefas->qtde;
        }
        Serv = Serv->prox;
    }
    printf("   TOTAL DE REQUISICOES RETIDAS: %d\n", totalSobra);
    printf("=================================================================\n");
}
