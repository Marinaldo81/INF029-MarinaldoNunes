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
//  Matrícula: 20222160004
//  Semestre: 2º Semestre 

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 13-09-2023

// #################################################

#include <stdio.h>
#include "MarinaldoNunes-20222160004.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
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
	int i; 

	for (i = 0; data[i] != '/'; i++){ 
		if(data[i] >= 48 && data[i] <= 57){
        sDia[i] = data[i];  
    }else{
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
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){ 
      if(data[j] >= 48 && data[j] <= 57){
        sMes[i] = data[j];
		    i++;
      }else {
        dq.valido = 0;
        return dq;
      }
		
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	if(data[j]>= 48 && data[i] <= 57){
        sAno[i] = data[j];
	 	 i++;
    } else {
        dq.valido =0;
      return dq;
    }
    
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
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
  int datavalida = 1;
  DataQuebrada dataQuebrada = quebraData(data);
  if(dataQuebrada.valido ==0){
    return 0;
  } 
return ValidacaoDataQuebrada (dataQuebrada); // retorno vai ser direto da função criada!
}

int ValidacaoDataQuebrada (DataQuebrada dataQuebrada){
	if(dataQuebrada.iAno < 100 && dataQuebrada.iAno >=	10){
		dataQuebrada.iAno = dataQuebrada.iAno	+	2000; // isso aqui é para adicionar o 20 na frente ,caso a pessoa ,por exemplo,  digite 95 no ano.
	}
		switch (dataQuebrada.iMes){
			case 1:{
				
				if(dataQuebrada.iDia >= 1 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 2:{
				
			//bissexto	
				if (	(	(dataQuebrada.iAno	%	4	== 0) && (dataQuebrada.iAno	%	100	!=	0)	) || (dataQuebrada.iAno	%	400	==	0)	){    
					if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 29){
						dataQuebrada.valido = 1;
						return dataQuebrada.valido;
					}else{
						dataQuebrada.valido = 0;
						return dataQuebrada.valido;
					}
			}else {
					if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 28){
						dataQuebrada.valido = 1;
						return dataQuebrada.valido;
					}else{
						dataQuebrada.valido = 0;
						return dataQuebrada.valido;
					}
			}
				break;
			}
			case 3:{
				
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 4:{
				
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 30){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 5:{
				//maio
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 6:{
				
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 30){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 7:{
				
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 8:{
        				
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 9:{
				
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 30){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 10:{
				
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 11:{
				 
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 30){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 12:{
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			default:
			dataQuebrada.valido = 0;
			return dataQuebrada.valido;
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

    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2; // aqui já está testando se a data inicial é inválida
      return dma; 
    }else if (q1(datafinal) == 0){
      dma.retorno = 3; // aqui já está testando se a data final é invalida 
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
			DataQuebrada dmai	=	quebraData(datainicial);
			DataQuebrada dmaf	= quebraData(datafinal);

			if(	(dmai.iAno > dmaf.iAno) || (dmai.iAno == dmaf.iAno && dmai.iMes > dmaf.iMes) ||(dmai.iAno == dmaf.iAno && dmai.iMes == dmaf.iMes && dmai.iDia > dmaf.iDia)	){
    dma.retorno = 4;
    return dma;
			}else {
					
				int mes	=	 QdtDiasMes( dmai.iMes, dmai.iAno);
				dma.retorno	=	1; //retorno colocado na struct 
				int datai	=	 QtdDiasAno(dmai.iMes , dmai.iAno) +	dmai.iDia;
				datai	=	datai	+	dmai.iAno	*	365;
				int dataf	=	QtdDiasAno(dmaf.iMes	,	dmaf.iAno)	+	dmaf.iDia;
				dataf	=	dataf	+	dmaf.iAno	*	365;
				int difdata	=	dataf	-	datai;
				dma.qtdAnos	=	difdata/365;
				 difdata +=  QtdDiasAno(dmai.iMes, dmai.iAno) == QtdDiasAno(dmaf.iMes, dmaf.iAno);
					difdata	=	difdata	-	dma.qtdAnos*365;
					dma.qtdMeses	=	difdata	/	mes;
					dma.qtdDias	=	difdata	%	mes;
					
				return dma;
			}
				
			}
						
      dma.retorno = 1;
      return dma;
    }

int QdtDiasMes(int mes, int ano) {
  switch (mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 2:{
      if (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)) {
        return 29;
      } else {
        return 28;
      }
    }
  }
}
int QtdDiasAno(int mes,int ano	){
	int dias	=	0;
	int MESES	=	1;
	while(mes	>	MESES){
		dias	=	dias + QdtDiasMes(MESES, ano);
		MESES++;
	}
	return dias;
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
  int i;  
  int qtdOcorrencias = 0;
  if (isCaseSensitive == 1){
    for (i=0; i<250; i++ ){  
      if (c == texto[i]){
        qtdOcorrencias++;
     
      }
    }
  } else {
    for(i=0; i<250; i++){
      if (toupper(c) == texto[i] || tolower(c) == texto[i]){  
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

int q4(char *strTexto, char *strBusca, int posicoes[])
{
    int tamt = strlen(strTexto);
    int tamp = strlen(strBusca);
    int posicao = 0;
    int qtdOcorrencias = 0;
    int i = 0;
    int j = 0;
    int qtdpal=0;

    while (strTexto[i] != '\0') {
        if (strBusca[j] == strTexto[i]) {
            j++;
        } else {
            j = 0;
        }

        if (j == tamp) {
            j = 0;
          posicoes[posicao]	=	i+1	- (tamp-1); // tampalavra - 1 é pq se fizer o calculo ele diminui sempre uma a menos que a palavra
						posicao++;
						posicoes[posicao]	=	i+1; // essa soma aqui tbm é pra ajustar a posicao do vetor com a posicao q ele deu q é uma posicao a mais
						posicao++;
						qtdOcorrencias++;
        }

        i++;
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
  int digito, inv = 0;
  while (num > 0) {
    digito = num % 10;
    inv = inv * 10 + digito;
    num /= 10;
  }
  
  return inv;
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

int q6(int numerobase, int numerobusca)  //verificar
{
  int contador = 0;
  if (numerobusca == 0){
    return 0;
  }
while (numerobase > 0){
 
  if(numerobase % 100 == numerobusca){
    contador++;
     numerobase /= 100;
  } else {

  numerobase /=10;

  } 
    

}

  return contador;

  
}











