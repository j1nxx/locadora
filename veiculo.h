#ifndef __VEICULO_H
#define __VEICULO_H

#include"locadora.h"

  // VERIFICACAO
int buscarPLACA(char *placa);
int buscarStatusVEICULO(int posicao);
float buscarValorDiariaVEICULO(int posicao);
float buscarKmInicialVEICULO(int posicao);
float buscarMultaKmVEICULO(int posicao);
float buscarLimiteKmVEICULO(int posicao);

  // ALTERACAO DE DADOS
void excluirVEICULO(WINDOW *janela, int posicao);
void editarVEICULO(WINDOW *janela, int posicao);
void restaurarVEICULO(WINDOW *janela, int posicao);
void esvaziarVEICULO(WINDOW *janela, int posicao);
void updateKmVEICULO(int posicao, int kmupdate);

#endif
