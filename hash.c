#include "hash.h"

//recebe string e devolve valor numerico, calculado a partir da string(soma dos valores numericos dos caracteres)
static int hash(unsigned char a[], int n){
	int k;
	k = strlen(a);
	return (k+1) % N;
}

HASH* hsh_cria(void){
	HASH* tab = (HASH*)malloc(sizeof(HASH));
	int i;
	for(i=0;i<N;i++){
		tab->v[i] = NULL;
	}
	return tab;
}

STR_VEICULO* hsh_insere(HASH* tab, char* placa, char*modelo, char* marca, int ano, int km, int limitekm, float diaria, float valorkm, int status){
	int h = hash(placa,7);
	while(tab->v[h] != NULL){
		h = (h+1) % N;
	}
	STR_VEICULO* v = (STR_VEICULO*)malloc(sizeof(STR_VEICULO));
	strcpy(v->placa,placa);
	strcpy(v->modelo,modelo);
	strcpy(v->marca,marca);
	v->ano = ano;
	v->km = km;
	v->limitekm = limitekm;
	v->diaria = diaria;
	v->valorkm = valorkm;
	v->status = status;
	tab->v[h] = v;
	return v;
}

STR_VEICULO* hsh_busca(HASH* tab, char* placa){
	int h = hash(placa,7);
	while(tab->v[h] != NULL){
		if(tab->v[h]->placa == placa)
			return tab->v[h];
		h = (h+1) % N;
	}
	return NULL;
}

void hsh_libera(HASH* tab){
	int i;
	for(i=0;i<N;i++)
		free(tab->v[i]);
	free(tab);
}
