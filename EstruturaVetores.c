#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct vetorPrinc{
  int tam;
  int tamvet; // contador da variavel auxiliar 
  int *vetorAux;
}structPrinc; 


structPrinc vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
 if (posicao < 1 || posicao > TAM) {
        return POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[posicao - 1].vetorAux != NULL) {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    else if (tamanho < 1) {
        return TAMANHO_INVALIDO;
    }

    vetorPrincipal[posicao - 1].vetorAux = malloc(tamanho * sizeof(int));
    if (vetorPrincipal[posicao - 1].vetorAux == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }
    
    vetorPrincipal[posicao - 1].tam = tamanho;
    vetorPrincipal[posicao - 1].tamvet = 0;

    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if (posicao<1 || posicao>10)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao-1].vetorAux !=NULL)
        {
            if (vetorPrincipal[posicao-1].tam <vetorPrincipal[posicao-1].tamvet)
            {
               
              vetorPrincipal[posicao-1].vetorAux[vetorPrincipal[posicao-1].tam] = valor;
              vetorPrincipal[posicao -1].tamvet++;
             
                retorno = SUCESSO;
            }
            else if (vetorPrincipal[posicao -1].tam == vetorPrincipal[posicao-1].tamvet)
            {
                retorno = SEM_ESPACO;
            }
        }
        else 
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  
   if(posicao < 1 || posicao > TAM)
     return POSICAO_INVALIDA;
   if(vetorPrincipal[posicao -1].vetorAux == NULL)
      return SEM_ESTRUTURA_AUXILIAR;
    if(vetorPrincipal[posicao -1].tamvet == 0 ){
    return ESTRUTURA_AUXILIAR_VAZIA;
    }else{
     vetorPrincipal[posicao -1].tamvet--;
      return SUCESSO;
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  if(posicao < 1 || posicao > TAM)
    return POSICAO_INVALIDA;
  if(vetorPrincipal[posicao -1].vetorAux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;
  else if(vetorPrincipal[posicao -1].tamvet == 0){
    return ESTRUTURA_AUXILIAR_VAZIA;
  }else {
    int existe = 0;
    for (int i=0; i <(vetorPrincipal[posicao -1].tamvet); i++){
      if(vetorPrincipal[posicao -1].vetorAux[i] == valor){
        existe = 1;
      for(int k=i, j=k+1; j<(vetorPrincipal[posicao-1].tamvet); k++, j++ ){
        vetorPrincipal[posicao-1].vetorAux[i]== vetorPrincipal[posicao -1].vetorAux[j]; 
      }
        vetorPrincipal[posicao -1].tamvet--;
      }
    }
    if(existe ==1)
      return SUCESSO;
  else{
    return NUMERO_INEXISTENTE;
  }
  }
}
    


// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

  int retorno;
  int lugarVet = 0;
  if(posicao <1 || posicao>10){
    return POSICAO_INVALIDA;
  }else if(vetorPrincipal[posicao -1].vetorAux ==  NULL && vetorPrincipal[posicao-1].tam ==0){
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  for(int i=0; i<vetorPrincipal[posicao-1].tamvet; i++)
    {
      vetorAux[lugarVet]= vetorPrincipal[posicao-1].vetorAux[i];
      lugarVet++;   
    }
  return SUCESSO;
    
  
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

void quicksort(int arr[], int low, int high) {
   }
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

  int retorno = 0;
  int lugarVet = 0;
  if(posicao < 1 || posicao >10)
    return POSICAO_INVALIDA;
  if(ehPosicaoValida(posicao)== SUCESSO){
    if(vetorPrincipal[posicao-1].vetorAux != NULL && vetorPrincipal[posicao-1].tam >0){
      for (int i =0; i<vetorPrincipal[posicao-1].tam; i++){
        vetorAux[lugarVet]= vetorPrincipal[posicao -1].vetorAux[i];
        lugarVet++;
      }
    quicksort(vetorAux, 0,  vetorPrincipal[posicao-1].tam-1);
    return SUCESSO;
    }else retorno = ESTRUTURA_AUXILIAR_VAZIA;
  }else retorno = SEM_ESTRUTURA_AUXILIAR;
}
    
  

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    int cont =0;
    for (int i = 0; i <TAM; i++)
    {
        if (vetorPrincipal[i].vetorAux != NULL && vetorPrincipal[i].tam > 0 && vetorPrincipal[i].tamvet > 0)
        {
            vetorAux[cont] = vetorPrincipal[i].vetorAux[0]; // Armazena o primeiro valor da estrutura auxiliar no vetorAux
            cont++;
        }
    }
    if (cont == 0)
    {
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS; // Todas as estruturas auxiliares estão vazias
    }
    else
    {
        retorno = SUCESSO; // Valores recuperados com sucesso
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    int cont = 0;
    int i, j;
    
    // Copiar os elementos das estruturas auxiliares para o vetorAux
    for (i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].vetorAux != NULL && vetorPrincipal[i].tam > 0 && vetorPrincipal[i].tamvet > 0)
        {
            for (j = 0; j < vetorPrincipal[i].tam; j++)
            {
                vetorAux[cont] = vetorPrincipal[i].vetorAux[j];
                cont++;
            }
        }
    }
    
    for (i = 0; i < cont - 1; i++)
    {
        for (j = 0; j < cont - i - 1; j++)
        {
            if (vetorAux[j] > vetorAux[j + 1])
            {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }

    if (cont == 0)
    {
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS; 
    }
    else
    {
        retorno = SUCESSO; 
    }

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

     int retorno = 0;
    int i;

    if (posicao < 0 || posicao >= TAM)
    {
        retorno = POSICAO_INVALIDA; // Posição inválida para estrutura auxiliar
    }
    else if (vetorPrincipal[posicao].vetorAux == NULL)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR; // Não tem estrutura auxiliar
    }
    else if (novoTamanho < -vetorPrincipal[posicao].tam)
    {
        retorno = NOVO_TAMANHO_INVALIDO; // Novo tamanho não pode ser negativo
    }
    else
    {
        int novoTamanhoFinal = vetorPrincipal[posicao].tam + novoTamanho;
        if (novoTamanhoFinal < 1)
        {
            retorno = NOVO_TAMANHO_INVALIDO; // Novo tamanho não pode ser menor que 1
        }
        else
        {
            int *novoVetorAux = realloc(vetorPrincipal[posicao].vetorAux, novoTamanhoFinal * sizeof(int));
            if (novoVetorAux != NULL)
            {
                vetorPrincipal[posicao].vetorAux = novoVetorAux;
                vetorPrincipal[posicao].tam = novoTamanhoFinal;
                retorno = SUCESSO; // Modificado corretamente o tamanho da estrutura auxiliar
            }
            else
            {
                retorno = SEM_ESPACO_DE_MEMORIA; // Erro na alocação do novo valor
            }
        }
    }

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

int retorno = 0;

    if (posicao < 1 || posicao > TAM) {
        retorno = POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[posicao - 1].vetorAux == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else if (vetorPrincipal[posicao - 1].tamvet == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    else {
        retorno = vetorPrincipal[posicao - 1].tamvet;
    }

    return retorno;
}


/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/



No *montarListaEncadeadaComCabecote()
{
  int totalElAux = 0;
	for(int i=0; i	<TAM ;i++){
		totalElAux	+=	vetorPrincipal[i].tamvet;
	} if (totalElAux ==	0){
		return NULL;
	}else {
		No *inicio = (No*)malloc(sizeof(No)); 
		inicio->prox = NULL; 

		int vetor[totalElAux]; 	
	 	
    getDadosDeTodasEstruturasAuxiliares(vetor);
	for(int i = 0	; i	<	totalElAux	; i++)
		{
			No* novo = malloc(sizeof(No));
			novo->conteudo = vetor[i]; 
			novo->prox = NULL; 
			if(inicio->prox == NULL){
				inicio->prox = novo; 
			}else{
				No* atual = inicio;
				while(atual->prox != NULL) 
					atual = atual->prox;
				atual->prox = novo;
			}
		}
	return inicio;
	}
}
  

    


/*
Objetivo: retorna os números da lista encadeda com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
 No* atual = inicio->prox;
  int i = 0;
  while (atual != NULL) {
    vetorAux[i] = atual->conteudo;
    atual = atual->prox;
    i++;
}
}
/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
  No* atual = (*inicio)->prox;

  while (atual != NULL) {
    No* proximo = atual->prox;
    free(atual);
    atual = proximo;
  }

  free(*inicio);
  *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar()
{
  int i=0;
    for(int i=0; i<TAM; i++){
    vetorPrincipal[i].vetorAux = NULL;
    vetorPrincipal[i].tam = 0;
    vetorPrincipal[i].tamvet = 0;
  }
  
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
  int i=0;
  for (int i=0; i<TAM; i++){
    free(vetorPrincipal[i].vetorAux);
  }
  
}