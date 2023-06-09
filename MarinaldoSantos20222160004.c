// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Marinaldo Nunes Santos  
//  email: ti.marinaldo@gmail.com    
//  Matrícula:202221600004 
//  Semestre: 2º semestre 

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "MarinaldoSantos20222160004.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i,j; 

	for (i = 0; data[i] != '/'; i++){
    if (data[i] >= 48 && data[i] <= 57) {
		sDia[i] = data[i];	
	  }else {
		dq.valido = 0;
    return dq;
    }  
  }
  
   if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	   }else {
		dq.valido = 0;
    return dq;
    }  
 
 
	j = j + 1; // anda 1 cada para pular a barra
  i = 0;
  
  for (; data[j] != '\0'; j++) {
    if (data[j] >= 48 && data[j] <= 57) {
      sAno[i] = data[j];
      i++;
    } else {
      dq.valido = 0;
      return dq;
    }
  }

  
	if(i == 2 || i == 4 || i == 1){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
    if (i == 2 || i == 1)
     dq.iAno = atoi(sAno) + 2000;
    if (i == 4)
      dq.iAno = atoi(sAno);
	}else {
		dq.valido = 0;
    return dq;
  }

  

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  DataQuebrada dataQuebrada = quebraData(data);
  if (dataQuebrada.valido == 0)
    return 0;
  return validarData(dataQuebrada.iDia, dataQuebrada.iMes, dataQuebrada.iAno);
  
}

int validarData(int dia, int mes, int ano) {
  int maxDias;
  if (dia < 0 || ano < 0 || mes < 0 || mes > 12)
    return 0;
  
  maxDias = QuantDias(mes, ano);
  
  if (dia > maxDias)
    return 0;

  return 1;
}

int biss(int ano){
  if(((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)){
    return 1;
  }
  return 0;
}

int QuantDias(int mes, int ano) {
 if ((mes == 1 ) || (mes == 3 ) || (mes == 5 ) || (mes == 7 )|| (mes == 8 )|| (mes == 10 )|| (mes == 12 )){
  return 31;
 } else if ((mes == 4 )|| (mes == 6 )|| (mes == 9 )|| (mes == 11 )){
   return 30;
 }else if (mes == 2){
   if (biss(ano)) {
   return 29;
 }else{
   return 28;
 }
}
}
     
/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    dma.retorno = 0;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
       
        DataQuebrada data_inicial, data_final, diferenca;
        data_inicial = quebraData (datainicial);
        data_final = quebraData (datafinal);
        // testando se a data inicial é maior que a final
        if(data_final.iAno < data_inicial.iAno  ){
        dma.retorno = 4;
        return dma;
        }
          if(data_inicial.iAno == data_final.iAno){
          if (data_final.iMes< data_inicial.iMes){
           dma.retorno = 1;
          return dma;
          }
          }
    
    }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
return let ( c, texto, isCaseSensitive);
}

int let (char c, char *texto, int isCaseSensitive){
  int i = 0;
  int qtdOcorrencias = 0;
  

  for (int i = 0; texto[i] != '\0'; i++) {
    if (isCaseSensitive == 1){ 
      if (c == texto[i]) {
        qtdOcorrencias++;
      }
    } else {
        if (toupper(c) == toupper(texto[i]))
       {
        qtdOcorrencias++;
      }
    }
  }
  return qtdOcorrencias;
}

      
/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]) {
   
 return encontrar(strTexto, strBusca, posicoes); 
   
   
}

int encontrar(char *strTexto, char *strBusca, int *posicoes) {
    int qtdOcorrencias = 0;
    int tamTexto = strlen(strTexto);
    int tamBusca = strlen(strBusca);
    
    // Busca pela palavra no texto
    for (int i = 0; i <= tamTexto - tamBusca; i++) {
        if (strncmp(strTexto + i, strBusca, tamBusca) == 0) {
            posicoes[2 * qtdOcorrencias] = i + 1; // posição de início
            posicoes[2 * qtdOcorrencias + 1] = i + tamBusca; // posição de fim
            qtdOcorrencias++;
        }
    }
    
    return qtdOcorrencias;
}



/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
int invert = 0;
  while (num != 0) {
    int digit = num % 10;
    invert = invert * 10 + digit;
    num /= 10; //num/10
  }
 
    return invert;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias = 0;
   
  while (numerobase != 0) {
  int digit = numerobase % 10;
  numerobase /= 10; 
    if (digit == numerobusca){
      qtdOcorrencias++;
    }
  }


  
    return qtdOcorrencias;
}