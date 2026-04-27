#define MAXFILA 5

struct TpFilaVariavel
{
	int inicio,FIM;
	char FILA[MAXFILA];
};

void Inicializar(TpFilaVariavel &f)
{
	f.inicio = 0;
	f.FIM = - 1; 
}

char Vazia (int FIM, int inicio)
{
	return FIM < inicio;
}

char Cheio (int FIM, int inicio)
{
	return inicio == 0 && FIM == MAXFILA-1;
}

char ElementoIni(TpFilaVariavel f)
{
	return f.FILA[f.inicio];
}

char ElementoFim(TpFilaVariavel f)
{
	return f.FILA[f.FIM];
}

void Inserir(TpFilaVariavel &f, char c)
{
	int i;
	if(f.FIM == MAXFILA-1)
	{
		for(i=0;i <(f.FIM - f.inicio);i++)
			f.FILA[i] = f.FILA[f.inicio+i];
		f.FIM -= f.inicio;
		f.inicio = 0;
	}
	else
		f.FILA[++f.FIM] = c;
}

char Retirar(TpFilaVariavel &f)
{
	char x = f.FILA[f.inicio];
	if(f.FIM == f.inicio)
		Inicializar(f);
	else
		f.inicio++;
	return x;

}
// implementar tadfilaCircular
// Qtd      ||      resto(modulo matematico)
//silvio lago ||		ziviani

