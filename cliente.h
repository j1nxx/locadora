#ifndef __CLIENTE_H
#define __CLIENTE_H

#include"locadora.h"

// VERIFICACAO
int buscarCPF(char *cpf);
int validarCPF(char *cpf);
int buscarLOCACAO(char *placa);
int buscarStatusCLIENTE(int posicao);

  // ALTERACAO DE DADOS
void excluirCLIENTE(WINDOW *janela, int posicao);
void editarCLIENTE(WINDOW *janela, int posicao);
void restaurarCLIENTE(WINDOW *janela, int posicao);
void esvaziarCLIENTE(WINDOW *janela, int posicao);

#endif

