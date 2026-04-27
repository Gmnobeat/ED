#define MAXFILA 5

struct TpFila
{
	int Inicio, Fim, cont;
	char FILA[MAXFILA];
};

void Inicializar(TpFilaVariavel &f)
{
	f.Inicio = 0;
	f.Fim = - 1;
	cont = 0;
}

char FCVazia(int cont)
{
	return cont == 0;
}

char FCCheia(int inicio, int fim)
{
	return cont == MAXFILA; 
}

void FCInserir(TpFila &f, char elemento)
{
	if(f.Fim == MAXFILA-1)
		f.Fim = -1;
	f.FILA[++f.Fim] = elemento;	
	f.cont++;
}

char FCRetirar(TpFila &f)
{
	char aux = f.FILA[f.Inicio++];
	if(f.Inicio == MAXFILA-1)
		f.Inicio = 0;
	f.cont--;
	return aux;
}
