#define MAXFILA 10

struct TpElemento
{
	char info;
	int Prioridade;	
};

struct TpFilaPri
{
	int FIM;
	TpElemento FILA[MAXFILA];	
};

int Inicializar (int fim)
{
	return fim = -1;
}

char Cheio(TpFilaPri f)
{
	return f.FIM == MAXFILA;
}

char Vazio(TpFilaPri f)
{
	return f.FIM == -1;
}

void Inserir(TpFilaPri &f,TpElemento Elemento)
{
	TpElemento aux;
	int i;
	f.FILA[++f.FIM] = Elemento;	
	for(i=f.FIM ; i > 0 && (f.FILA[i].Prioridade < Elemento.Prioridade) ;i--)//Ele ja vai jogando para traz ate a comparação 
	{	
		aux = f.FILA[i];
		f.FILA[i] = f.FILA[i-1];
		f.FILA[i-1] = aux;
	}
} 

char Retirar(TpFilaPri f)
{
	TpElemento aux;
	aux = f.FILA[0];
	while(!Cheio(f))
		f.FILA[f.FIM] = f.FILA[++f.FIM];
	f.FIM--; 
	return aux.info;
}

void Exibir(TpFilaPri f)
{
	while(!Vazio(f))
		printf("%c %d",Retirar(f));
}


