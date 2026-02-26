//Tipos de dados
struct TpCidade
{
	char	Nome[50];
	int    Populacao;
};

//Operações Associadas
void Gravar (FILE *Ptr, TpCidade RegCidade)
{
	fwrite(&RegCidade,sizeof(TpCidade),1,Ptr);
	//...
}

void CadastrarCidades(char NomeArquivo[50])
{
	TpCidade Cidade;
	FILE *PtrCidade = fopen(NomeArquivo,"ab+");
	clrscr();
	printf("\n*** Cadastro de Cidade ***\n");
	fflush(stdin);
	gets(Cidade.Nome);
	while(strcmp(Cidade.Nome,"\0")!=0)
	{
		printf("Populacao: ");
		scanf("%d",&Cidade.Populacao);
		
		Gravar(PtrCidade,Cidade);
		printf("\nNome: ");
		fflush(stdin);
		gets(Cidade.Nome);
	}
	fclose(PtrCidade);
}

int Busca (FILE *Ptr, char NomeCidades[50])
{
	
}

void Relatorio (char NomeCidades[50])
{
	TpCidade R;
	FILE *PtrCidade = fopen(NomeCidades,"rb");
	clrscr();
	printf("\n*** Populacao das Cidades ***\n");
	fread(&R,sizeof(TpCidade),1,PtrCidade);
	while(!feof(PtrCidade))
	{
		printf("Cidade: %s   -   Populacao %d\n",R.Nome,R.Populacao);
		fread(&R,sizeof(TpCidade),1,PtrCidade);
	}
	fclose(PtrCidade);
}
