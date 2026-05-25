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

void InicializarCluster (TpDescritorCluster &C)
{
	C.qtde = 0; 
	C.inicio = C.fim = NULL;
}

TpServidores *NovoServidor(int ID) //cria a caixa de um Servidor com o descritor(serve para armazenar a fila de tarefas)
{
    TpServidores *Novo;
    Novo = new TpServidores;
    // Servidor
    Novo->ID_Servidor = ID;
    Novo->ant = Novo->prox = NULL;
    // Descritor da fila
    Novo->FilaTarefas = new TpDescritorFila;  
    Novo->FilaTarefas->inicio = Novo->FilaTarefas->fim = NULL;
    Novo->FilaTarefas->qtde = 0;              
    
    return Novo;
}

TpNoTarefas *NovoTarefas(TpTarefas Tarefas) // cria a caixa de uma tarefa
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
void AdicionarServidores(TpDescritorCluster &C, int QtdServidores)// adiciona a quantidade de servidores desejados no final da fila
{
    for(int i = 1; i <= QtdServidores; i++)
    {
        TpServidores *Novo = NovoServidor(C.qtde + 1); // ID continua de onde parou
        if(C.inicio == NULL)
        {
            C.inicio = C.fim = Novo;
        }
        else
        {
            Novo->ant   = C.fim;
            C.fim->prox = Novo;
            C.fim       = Novo;
        }
        C.qtde++;
        printf("Servidor %d Inicializado e Ligado ao Cluster!\n", Novo->ID_Servidor);
    }
}

void AdicionarTarefaNaFila(TpDescritorCluster &C, TpTarefas Tarefa) //adiciona tarefa na fila com menor quantidade de tarefas
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
    else 
		if(Novo->Tarefas.prioridade < MenorQtde->FilaTarefas->inicio->Tarefas.prioridade)
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

void LerTarefaDoArquivo(TpDescritorCluster &C, FILE *Arq)
{
    if(feof(Arq))
    {
        printf("Sem mais tarefas no arquivo!\n");
        return;
    }

    char TipoRequisicao[50], ID_Cliente[50], OrigemIP[50];
    int TempoProcessamento, TamanhoKB, prioridade;

    if(fscanf(Arq, "%s %d %d %s %s %d", TipoRequisicao, &prioridade,
              &TempoProcessamento, ID_Cliente, OrigemIP, &TamanhoKB) == 6)
    {
        TpTarefas T;
        strcpy(T.TipoRequisicao, TipoRequisicao);
        strcpy(T.ID_Cliente,     ID_Cliente);
        strcpy(T.OrigemIP,       OrigemIP);
        T.TempoProcessamento = TempoProcessamento;
        T.TamanhoKB          = TamanhoKB;
        T.prioridade         = prioridade;

        AdicionarTarefaNaFila(C, T);
    }
}

void RemoverServidor(TpDescritorCluster &C)
{
    if(C.inicio == NULL)
    {
        printf("Nenhum servidor ativo!\n");
        return;
    }

    if(C.qtde == 1)
    {
        printf("Nao e possivel remover o unico servidor!\n");
        return;
    }

    TpServidores *Remover = C.fim;

    // redistribui as tarefas antes de remover
    TpNoTarefas *Tarefa = Remover->FilaTarefas->inicio;
    while(Tarefa != NULL)
    {
        TpNoTarefas *Prox = Tarefa->prox;
        AdicionarTarefaNaFila(C, Tarefa->Tarefas);
        delete Tarefa;
        Tarefa = Prox;
    }

    // desencadeia o ultimo da lista
    C.fim       = Remover->ant;
    C.fim->prox = NULL;

    delete Remover->FilaTarefas;
    delete Remover;
    C.qtde--;

    printf("Servidor removido e tarefas redistribuidas!\n");
}
