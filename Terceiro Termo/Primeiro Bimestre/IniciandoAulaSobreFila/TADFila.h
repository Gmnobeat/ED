#define MAXFILA 10
struct TpFila
{
	int FIM;
	char FILA[MAXFILA];
};

int Inicializar(TpFila &f)
{
	return f.FIM = -1;
}

char FilaVazia(int fim)
{
	return fim == -1;
}

char FilaCheia(int fim)
{
	return fim == MAXFILA;
}

void Inserir(TpFila &f,char Elemento)
{
	f.FILA[++f.FIM] = Elemento;
}

char Retirar(TpFila &f)
{
	int i;
	char aux;
	aux = f.FILA[0];
	for(i=0;i<f.FIM;i++)
		f.FILA[i] = f.FILA[i+1];
	f.FIM--;
	return aux;
}

char ElementoInicio(TpFila f)
{
	return f.FILA[0];
}

char ElementoFim(TpFila f)
{
	return f.FILA[f.FIM];
}

char ExibirFila(TpFila f)
{
	while(!FilaVazia(f.FIM))
		printf("%c",Retirar(f));
}
