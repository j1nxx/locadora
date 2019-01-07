#ifndef __LOCADORA_H
#define __LOCADORA_H

  // Declarando Bibliotecas
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<curses.h>
#include<time.h>

  // Declarando Constantes
#define iniciaLinha 1
#define iniciaColuna 2
#define linha 23
#define coluna 76
#define N 75

  // Estruturas de dados
typedef struct{
	char nome[15];
	int senha;
}STR_USER;

typedef struct{
	char nome[31];
	char cpf[12];
	char rua[20];
	int num;
	char bairro[12];
	char cep[12];
	char cidade[20];
	long int tel;
	int status;
}STR_CLIENTE;

typedef struct{
	char placa[8];
	char modelo[17];
	char marca[17];
	int ano;
	int km;
	int limitekm;
	float diaria;
	float valorkm;
	int status;
}STR_VEICULO;

typedef struct{
	char placa[8];
	char cpf[12];
	char datasaida[14];
	char dataentrega[14];
	int diaslocados;
	float valordiaria;
	float valortotal;
    int kminicial;
}STR_LOCACAO;

typedef struct{
	char placa[8];
	char cpf[12];
	int diaslocadosextras;
	float valormultadia;
	int kmfinal;
    int kminicial;
    int kmlimite;
    float valormultakm;
    float totalanterior;
    float totalfinal;
}STR_DEVOLUCAO;

typedef struct{
	STR_VEICULO* v[N];
}HASH;

   // IMPRESSAO DE MENUS
void destruirJanela(WINDOW *janela);
void printTelaLOGIN(WINDOW *janela);
void printMenuPrincipal(WINDOW *janela, int sombreamento);
void printMenuCLIENTECRUD(WINDOW *janela, int sombreamento);
void printMenuCLIENTELIXEIRA(WINDOW *janela, int sombreamento);
void printMenuVEICULOCRUD(WINDOW *janela, int sombreamento);
void printMenuRELATORIOS(WINDOW *janela, int sombreamento);

	// IMPRESSAO DE TELAS DOS MENUS
void printTelaCadastrarCLIENTE(WINDOW *janela);
void printTelaPesquisarCLIENTE(WINDOW *janela);
void printTelaExcluirCLIENTE(WINDOW *janela);
void printTelaEditarCLIENTE(WINDOW *janela);
void printTelaLixeiraRESTAURARCLIENTE(WINDOW *janela);
void printTelaLixeiraESVAZIARCLIENTE(WINDOW *janela);
void printTelaRelatorioClientesEXCLUIDOS(WINDOW *janela);
void printTelaRelatorioClientesATIVOS(WINDOW *janela);
void printTelaRelatorioClientes(WINDOW *janela);
void printTelaRelatorioVeiculosEXCLUIDOS(WINDOW *janela);
void printTelaRelatorioVeiculosATIVOS(WINDOW *janela);
void printTelaRelatorioVeiculos(WINDOW *janela);
void printTelaRelatorioLocados(WINDOW *janela);

void printTelaCadastrarVEICULO(WINDOW *janela);
void printTelaPesquisarVEICULO(WINDOW *janela);
void printTelaExcluirVEICULO(WINDOW *janela);
void printTelaEditarVEICULO(WINDOW *janela);
void printTelaLixeiraRESTAURARVEICULO(WINDOW *janela);
void printTelaLixeiraESVAZIARVEICULO(WINDOW *janela);
void printTelaLOCACAO(WINDOW *janela);
void printTelaDEVOLUCAO(WINDOW *janela);

	// LEITURA DE DADOS
void scanStringComESPACO(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, char *string);
void scanStringSemESPACO(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, char *string);
void scanStringInteiroSemESPACO(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, char *string);
void scanStringInteiroComESPACO(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, char *string);
void scanLongInteiro(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, long int *inteiro);
void scanInteiro(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, int *inteiro);
void scanFloat(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, float *inteiro);

	// IMPRESSAO DE ERROS E AVISOS
void printMensagemERRO(WINDOW *janela, int posicaolinha, int posicaocoluna, char aviso[50]);
void printMensagemSUCESSO(WINDOW *janela, int posicaolinha, int posicaocoluna, char aviso[50]);
void printMensagemSUCESSONUMERO(WINDOW *janela, int posicaolinha, int posicaocoluna, float numero);

	// IMPRESSAO DE DADOS
void printDadosCLIENTEATIVO(WINDOW *janela, int posicao);
void printDadosCLIENTEINATIVO(WINDOW *janela, int posicao);
void printDadosVEICULO(WINDOW *janela, int posicao);
void printDadosVEICULOINATIVO(WINDOW *janela, int posicao);
void printDadosDEVOLUCAO(WINDOW *janela, int posicao);


	// VERIFICACAO
int buscarUSUARIO(char *nome);
float buscarValorTotalLOCACAO(int posicao);
float calculaValorTotalLOCACAO(float valordiaria, int diaslocados);
float calcularValorTotalDEVOLUCAO(float totalanterior, int diasextras, float valormultadia, int kminicial, int kmfinal, int kmlimite, float valormultakm);
void datasistema(char *datasistema);

	// ALTERACAO DE DADOS
void removerLOCACAO(WINDOW *janela, int posicao);

#endif
