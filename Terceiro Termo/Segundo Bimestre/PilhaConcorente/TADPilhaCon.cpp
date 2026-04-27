//Pilhas Múltiplas
// ED´s:

#define MAXPILHA 10

struct TpPilhaM1
{
	int Topo1,Topo2;
	char Pilha[MAXPILHA];
};

//Protótipos das Operações Associadas 

void Inicializar(TpPilhaM1 &PM);
char PMVazia(int Topo,int Np);// Vai depender de que pilha vc quer verificar.
char PMCheia(int Topo1,int Topo2);// Quando estiver cheia, não é a Pilha e sim a estrutura, ou seja, Topo1 do lado do Topo2.
void PMPush(TpPilhaM1 &PM, char Elem, int NP);
char PMPOP(TpPilhaM1 &PM, int NP);
char PMElemPilha(TpPilhaM1 PM,int NP);
void PMExibir(TpPilhaM1 PM,int NP);

void Inicializar(TpPilhaM1 &PM)
{
	PM.Topo1=-1;
	PM.Topo2=MAXPILHA;
}

char PMVazia(int Topo,int NP)
{
	if(NP==1)
		return Topo == -1;
	else
		return Topo == MAXPILHA;
}

char PMCheia(int Topo1,int Topo2)
{
	return (Topo1+1) == Topo2;
}

void PMPush(TpPilhaM1 &PM, char Elem, int NP)//insere
{
	if(NP==1)
		PM.Pilha[++PM.Topo1] = Elem;
	else
		PM.Pilha[--PM.Topo2] = Elem;
}

char PMPOP(TpPilhaM1 &PM, int NP)//retira 
{
	if(NP==1)
		return PM.Pilha[PM.Topo1--];
	else
		return PM.Pilha[PM.Topo2++];
}

char PMElemPilha(TpPilhaM1 PM,int NP)
{
	if(NP==1)
		return PM.Pilha[PM.Topo1];
	else
		return PM.Pilha[PM.Topo2];
}

void PMExibir(TpPilhaM1 PM,int NP)
{
	if(NP==1)
		while(!PMVazia(PM.Topo1,NP))
			printf("%c\n",PMPOP(PM, NP));
	else	
		while(!PMVazia(PM.Topo2, NP))
			printf("%c\n",PMPOP(PM, NP));
		
}

