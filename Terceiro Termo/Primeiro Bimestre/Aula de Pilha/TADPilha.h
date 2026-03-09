struct TpPilha
{
	int topo;
	char Pilha[MAXPILHA];
}
//
void inicializar (TpPilha &p)
{
	p.Topo = -1;
}

char Vazia(int topo)
{
	return topo == -1;
}

char cheia(int topo)
{
	return topo==MAXPILHA;
}

void Push(TpPilha &p, char elemento)
{
	p.Pilha[++p.topo] = elemento;
}

char Pop (TpPilha &p)
{
	return p.Pilha[p.topo--];
}

char ElementoTopo (TpPilha p)
{
	return p.Pilha[p.topo];
}

void Exibir (TpPilha p)
{
	while (!Vazia(p.topo))
		prinf("\n%c",Pop(p));
}
