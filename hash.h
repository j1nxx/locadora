#ifndef __USER_H
#define __USER_H

#include"locadora.h"

HASH* hsh_cria(void);
STR_VEICULO* hsh_insere(HASH* tab, char* placa, char*modelo, char* marca, int ano, int km, int limitekm, float diaria, float valorkm, int status);
STR_VEICULO* hsh_busca(HASH* tab, char* placa);
void hsh_libera(HASH* tab);

#endif