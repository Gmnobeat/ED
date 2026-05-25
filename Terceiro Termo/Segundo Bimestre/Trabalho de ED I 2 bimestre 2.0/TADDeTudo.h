struct TpTarefas
{
	char TipoRequisicao[50], ID_Cliente[50], OrigemIP[50];
	int TempoProcessamento, TamanhoKB, prioridade;
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

TpTarefas RetirarTarfaArq(char NomeArq[50])
{
	FILE *PtrArq = fopen(NomeArq,"r");
	
}

void InicializarCluster (TpDescritorCluster &C)
{
	C.qtde = 0; 
	C.inicio = C.fim = NULL;
}

TpServidores *NovoServidor(int ID)
{
    TpServidores *Novo;
    Novo = new TpServidores;
    // Servidor
    Novo->ID_Servidor = ID;
    Novo->ant = Novo->prox = NULL;
    // Fila dele — precisa alocar antes de usar
    Novo->FilaTarefas = new TpDescritorFila;  // essa linha faltava
    Novo->FilaTarefas->inicio = Novo->FilaTarefas->fim = NULL;
    Novo->FilaTarefas->qtde = 0;              // -> e nao .
    return Novo;
}

TpNoTarefas *NovoTarefas(TpTarefas Tarefas)
{
	TpNoTarefas *Novo;
	Novo = new TpNoTarefas;
	
	strcpy(Novo->Tarefas.TipoRequisicao, Tarefas.TipoRequisicao);
	strcpy(Novo->Tarefas.ID_Cliente, Tarefas.ID_Cliente);
	strcpy(Novo->Tarefas.OrigemIP, Tarefas.OrigemIP);
	Novo->Tarefas.TempoProcessamento = Tarefas.TempoProcessamento;
	Novo->Tarefas.TamanhoKB = Tarefas.TamanhoKB;
	Novo->Tarefas.prioridade = Tarefas.prioridade;
	Novo->prox = NULL;
	
	return Novo;
}

void AdicionarServidores(TpDescritorCluster &C, int QtdServidores)
{
	for(int i = 1; i <= QtdServidores; i++)
	{
		TpServidores *Novo = NovoServidor(i);
		if(C.inicio == NULL) 
		{
			C.inicio = C.fim = Novo;
		}
		else
		{
			Novo->ant = C.fim;   //inserindo no final
			C.fim->prox = Novo;  
			C.fim = Novo;        
		}
		C.qtde++; 
		printf("Servidor %d Inicializado e Ligado ao Cluster!\n", i);
	}
}

void AdicionarTarefaNaFila(TpDescritorCluster &C, TpTarefas Tarefa)
{
    TpServidores *Atual = C.inicio;
    TpServidores *MenorQtde = C.inicio;

    while(Atual != NULL)
    {
        if(Atual->FilaTarefas->qtde < MenorQtde->FilaTarefas->qtde)
            MenorQtde = Atual;
        Atual = Atual->prox;
    }

    TpNoTarefas *Novo = NovoTarefas(Tarefa);

    // fila vazia
    if(MenorQtde->FilaTarefas->inicio == NULL)
    {
        MenorQtde->FilaTarefas->inicio = MenorQtde->FilaTarefas->fim = Novo;
    }
    // nova tarefa tem prioridade maior que a primeira da fila
    else if(Novo->Tarefas.prioridade < MenorQtde->FilaTarefas->inicio->Tarefas.prioridade)
    {
        Novo->prox = MenorQtde->FilaTarefas->inicio;
        MenorQtde->FilaTarefas->inicio = Novo;
        
        // se tinha so um elemento, atualiza o fim
        if(Novo->prox->prox == NULL)
            MenorQtde->FilaTarefas->fim = Novo->prox;
    }
    else
    {
        // percorre ate achar a posicao certa
        TpNoTarefas *Aux = MenorQtde->FilaTarefas->inicio;
        while(Aux->prox != NULL && Aux->prox->Tarefas.prioridade <= Novo->Tarefas.prioridade)
            Aux = Aux->prox;

        Novo->prox = Aux->prox;
        Aux->prox  = Novo;

        // se inseriu no fim, atualiza o ponteiro fim
        if(Novo->prox == NULL)
            MenorQtde->FilaTarefas->fim = Novo;
    }

    MenorQtde->FilaTarefas->qtde++;
    printf("Tarefa [%s] prioridade %d adicionada ao Servidor %d (fila: %d)\n",Tarefa.ID_Cliente, Tarefa.prioridade, MenorQtde->ID_Servidor, MenorQtde->FilaTarefas->qtde);
}


