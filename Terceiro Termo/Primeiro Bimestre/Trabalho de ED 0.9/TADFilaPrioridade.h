#define MAXFILA 1000

struct TpTarefas
{
	char Tarefa[50];
	int Prioridade, UT,TempoChegada; //  Para calcular estatisticas no final;
};

struct TpFilaPri
{
	int FIM;
	TpTarefas FILA[MAXFILA];	
};

void Inicializar (TpFilaPri &f)
{
	f.FIM = -1;
}

char Cheio(TpFilaPri f)
{
	return f.FIM == MAXFILA - 1;
}

char Vazio(TpFilaPri f)
{
	return f.FIM == -1;
}

void Inserir(TpFilaPri &f, TpTarefas Elemento)
{
    TpTarefas aux;
    int i;
    f.FILA[++f.FIM] = Elemento;
    for(i = f.FIM; i > 0 && f.FILA[i].Prioridade < f.FILA[i-1].Prioridade; i--)
    {
        aux = f.FILA[i];
        f.FILA[i] = f.FILA[i-1];
        f.FILA[i-1] = aux;
    }
}

TpTarefas Retirar(TpFilaPri &f)
{
    TpTarefas aux = f.FILA[0];
    int i;
    for(i = 0; i < f.FIM ; i++)
    {
        f.FILA[i] = f.FILA[i+1];
    }
    f.FIM--;
    return aux;
}

void Exibir(TpFilaPri f)
{
    TpTarefas Aux;
	while(!Vazio(f))
    {
    	
        Aux = Retirar(f);
        printf("%s %d\n", Aux.Tarefa, Aux.Prioridade);
    }
}


