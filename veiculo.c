#include"veiculo.h"

int buscarPLACA(char *placa){

	// Definindo variaveis
	int cont = 0;
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){
		DBVEICULO = fopen("DBVEICULO.TXT","w");
	}

	else{

	rewind(DBVEICULO);
	// Lendo arquivos do DBCLIENTE
	fread(&REG,sizeof(REG),1,DBVEICULO);

	// Iniciando condicionais
	while(!feof(DBVEICULO) && (strcmp(REG.placa,placa) != 0)){
		cont++;
		fread(&REG,sizeof(REG),1,DBVEICULO);
		}
	}

	// Fechando o arquivo
	fclose(DBVEICULO);

	// Se encontrar CPF retorna a posicao
	if(strcmp(REG.placa,placa) == 0){
		return(cont);
	}

	// Senao ele retorna -10 que significa que nao encontrou o CPF
	else{
		return(-10);
	}

}

int buscarStatusVEICULO(int posicao){

	// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){
		DBVEICULO = fopen("DBVEICULO.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro da PLACA buscada
	fseek(DBVEICULO,posicao * sizeof(REG), 0);

	// Lendo arquivos do DBVEICULO e printando
	fread(&REG,sizeof(REG),1,DBVEICULO);

	// Fechando o arquivo
	fclose(DBVEICULO);
	}

	// Se Status for significa que o registro esta inativo
	if(REG.status == 0){
		return 0;
		}

	else{
		return 1;
	}
}

float buscarValorDiariaVEICULO(int posicao){
		// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){
		DBVEICULO = fopen("DBVEICULO.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro da PLACA buscada
	fseek(DBVEICULO,posicao * sizeof(REG), 0);

	// Lendo arquivos do DBVEICULO e printando
	fread(&REG,sizeof(REG),1,DBVEICULO);

	// Fechando o arquivo
	fclose(DBVEICULO);

	}
	return(REG.diaria);

}

float buscarKmInicialVEICULO(int posicao){
		// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){
		DBVEICULO = fopen("DBVEICULO.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro da PLACA buscada
	fseek(DBVEICULO,posicao * sizeof(REG), 0);

	// Lendo arquivos do DBVEICULO e printando
	fread(&REG,sizeof(REG),1,DBVEICULO);

	// Fechando o arquivo
	fclose(DBVEICULO);

	}
	return(REG.km);

}

float buscarMultaKmVEICULO(int posicao){
		// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){
		DBVEICULO = fopen("DBVEICULO.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro da PLACA buscada
	fseek(DBVEICULO,posicao * sizeof(REG), 0);

	// Lendo arquivos do DBVEICULO e printando
	fread(&REG,sizeof(REG),1,DBVEICULO);

	// Fechando o arquivo
	fclose(DBVEICULO);

	}
	return(REG.valorkm);

}

float buscarLimiteKmVEICULO(int posicao){
		// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){
		DBVEICULO = fopen("DBVEICULO.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro da PLACA buscada
	fseek(DBVEICULO,posicao * sizeof(REG), 0);

	// Lendo arquivos do DBVEICULO e printando
	fread(&REG,sizeof(REG),1,DBVEICULO);

	// Fechando o arquivo
	fclose(DBVEICULO);

	}
	return(REG.limitekm);

}


void excluirVEICULO(WINDOW *janela, int posicao){

	// Variaveis
	char opcao ='P';

	// Mostrar Cursor
	curs_set(1);

	// Nao ecoar na tela
	echo();

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r+");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO== NULL){
		DBVEICULO = fopen("DBVEICULO.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro do CPF buscado
	fseek(DBVEICULO, posicao * sizeof(REG), SEEK_SET);

	// Lendo Arquivo e gravando na REG
	fread(&REG, sizeof(REG), 1, DBVEICULO);

	// Confirmacao de exclusao
	while((opcao != 'S') && (opcao != 'N') && (opcao != 's') && (opcao != 'n') && (REG.status != 0) ){
		mvwprintw(janela,17,20,"DESEJA REALMENTE EXCLUIR?(S/N)_",posicao);
		opcao = mvwgetch(janela,17,50);

	}

		if((opcao == 'S') || (opcao == 's')){
			// Setando status como inativo 0
			REG.status = 0;

			// Posicionando no CPF buscado
			fseek(DBVEICULO, sizeof(REG) * (posicao), SEEK_SET);

			// Gravando no arquivo
			fwrite(&REG, sizeof(REG), 1, DBVEICULO);

			// Fechando o arquivo
			fclose(DBVEICULO);

			// Mensagem de exclusao Sucesso
			mvwprintw(janela,19,20,"      VEICULO EXCLUIDO COM SUCESSO!     ");
			mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
			wrefresh(janela);
			// Parando tela
			getchar();

		}

	else{
		mvwprintw(janela,20,20,"          EXCLUSAO CANCELADA!     ");
		mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
		wrefresh(janela);
		getchar();
	}
}

// Mostrar Cursor
curs_set(0);

// Nao ecoar na tela
noecho();
}

void editarVEICULO(WINDOW *janela, int posicao){
	// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	int NovoresultadoBuscaPLACA;

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r+");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){
		DBVEICULO = fopen("DBVEICULO.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro do CPF buscado
	fseek(DBVEICULO, sizeof(REG) * (posicao), SEEK_SET);

	// Lendo Arquivo e gravando na REG
	fread(&REG, sizeof(REG), 1, DBVEICULO);

	if(REG.status == 0){
		printMensagemERRO(janela,18,20,"                ERRO!              ");
		printMensagemERRO(janela,19,20,"     O VEICULO ESTA EXCLUIDO!      ");
		printMensagemERRO(janela,20,20,"      ACESSE O MENU LIXEIRA        ");

		getchar();
	}

	else{

	// Printando dados do VEICULO
	mvwprintw(janela,9,9,"%s",REG.placa);
	mvwprintw(janela,10,10,"%s",REG.modelo);
	mvwprintw(janela,11,9,"%s",REG.marca);
	mvwprintw(janela,12,7,"%d",REG.ano);
	mvwprintw(janela,13,16,"%d",REG.km);
	mvwprintw(janela,14,23,"%d",REG.limitekm);
	mvwprintw(janela,15,19,"%.2f",REG.diaria);
	mvwprintw(janela,16,15,"%.2f",REG.valorkm);

	// Chamando Subrotina Verificar PLACA
	scanStringInteiroSemESPACO(janela,9,45,2,8,REG.placa);

	// Verifica se PLACA consta no ARQUIVO
	NovoresultadoBuscaPLACA =  buscarPLACA(REG.placa);

	// Se o resultado da FUNCAO for vazio
	if(strcmp(REG.placa,"") == 0){
		printMensagemERRO(janela,17,20,"               ERRO!               ");
		printMensagemERRO(janela,18,20," O CAMPO PLACA NAO PODE SER VAZIO! ");
		printMensagemERRO(janela,19,20,"       INSIRA UMA NOVA PLACA!      ");
		mvwprintw(janela,20,20,"            EDICAO CANCELADA!           ");
		mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
		wrefresh(janela);
		getchar();
	}

	// Se o resultado da BUSCA CPF for diferente de -10 o CPF Existe
	else if(NovoresultadoBuscaPLACA != -10 && NovoresultadoBuscaPLACA != posicao){
		printMensagemERRO(janela,17,20,"                ERRO!              ");
		printMensagemERRO(janela,18,20,"    A PLACA DIGITADA JA EXISTE!    ");
		printMensagemERRO(janela,19,20,"       INSIRA UMA NOVA PLACA!      ");
		mvwprintw(janela,20,20,"         EDICAO CANCELADA!           ");
		mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
		wrefresh(janela);
		getchar();
	}

	else if(NovoresultadoBuscaPLACA == -10 || NovoresultadoBuscaPLACA == posicao){

	// Chamando Subrotina Verificar STRING MODELO
	scanStringInteiroComESPACO(janela,10,46,2,16,REG.modelo);

	// Chamando Subrotina Verificar STRING MARCA
	scanStringComESPACO(janela,11,45,2,11,REG.marca);

	// Chamando Subrotina Verificar INTEIRO ANO
	scanInteiro(janela,12,43,2,5,&REG.ano);

	// Chamando Subrotina Verificar INT KM
	scanInteiro(janela,13,52,2,7,&REG.km);

	// Chamando Subrotina Verificar INT KM
	scanInteiro(janela,14,58,2,7,&REG.limitekm);

	// Chamando Subrotina Verificar FLOAT DIARIA
	scanFloat(janela,15,55,2,7,&REG.diaria);

	// Chamando Subrotina Verificar FLOAT VALORKM
	scanFloat(janela,16,51,2,11,&REG.valorkm);

	// Posicionando no CPF buscado
	fseek(DBVEICULO, sizeof(REG) * (posicao), SEEK_SET);

	// Gravando no arquivo
	fwrite(&REG, sizeof(REG), 1, DBVEICULO);

	// Fechando o arquivo
	fclose(DBVEICULO);

	mvwprintw(janela,20,24,"CLIENTE EDITADO COM SUCESSO!");
	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	// Atualizando tela
	wrefresh(janela);

	// Esperando pressionar qualquer tecla
	getchar();
	}
	}

 }
// Mostrar Cursor
curs_set(0);

// Nao ecoar na tela
noecho();
}


void restaurarVEICULO(WINDOW *janela, int posicao){

	// Variaveis
	char opcao ='P';

	// Mostrar Cursor
	curs_set(1);

	// Nao ecoar na tela
	echo();

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r+");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){
		DBVEICULO = fopen("DBVEICULO.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro do CPF buscado
	fseek(DBVEICULO, posicao * sizeof(REG), SEEK_SET);

	// Lendo Arquivo e gravando na REG
	fread(&REG, sizeof(REG), 1, DBVEICULO);

	// Confirmacao de exclusao
	while((opcao != 'S') && (opcao != 'N') && (opcao != 's') && (opcao != 'n') && (REG.status != 1) ){
		mvwprintw(janela,17,20,"DESEJA REALMENTE RESTAURAR?(S/N)_",posicao);
		opcao = mvwgetch(janela,17,52);

	}

		if((opcao == 'S') || (opcao == 's')){
			// Setando status como ATIVO 1
			REG.status = 1;

			// Posicionando no CPF buscado
			fseek(DBVEICULO, sizeof(REG) * (posicao), SEEK_SET);

			// Gravando no arquivo
			fwrite(&REG, sizeof(REG), 1, DBVEICULO);

			// Fechando o arquivo
			fclose(DBVEICULO);

			// Mensagem de exclusao Sucesso
			printMensagemSUCESSO(janela,18,20,"                                  ");
			printMensagemSUCESSO(janela,19,20," VEICULO RESTAURADO COM SUCESSO!  ");
			printMensagemSUCESSO(janela,20,20,"                                  ");
			mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
			wrefresh(janela);
			// Parando tela
			getchar();

		}

	else{
	mvwprintw(janela,19,20,"       RESTAURACAO CANCELADA!           ");
	mvwprintw(janela,20,20,"    O VEICULO NAO ESTA EXCLUIDO!        ");
	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	wrefresh(janela);
	getchar();
	}
}

// Mostrar Cursor
curs_set(0);

// Nao ecoar na tela
noecho();
}

void esvaziarVEICULO(WINDOW *janela, int posicao){

	// Variaveis
	char opcao ='P';
	char placaExcluido[8];

	// Mostrar Cursor
	curs_set(1);

	// Nao ecoar na tela
	echo();

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r+");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){
		DBVEICULO = fopen("DBVEICULO.TXT","w");
	}


	// Posicionando no na posicao do registro do CPF buscado
	fseek(DBVEICULO, posicao * sizeof(REG), SEEK_SET);

	// Lendo Arquivo e gravando na REG
	fread(&REG, sizeof(REG), 1, DBVEICULO);

	// Confirmacao de exclusao
	while((opcao != 'S') && (opcao != 'N') && (opcao != 's') && (opcao != 'n') && (REG.status != 1) ){
		mvwprintw(janela,17,13,"DESEJA REALMENTE EXCLUIR DEFINITIVAMENTE?(S/N)_",posicao);
		opcao = mvwgetch(janela,17,59);

	}
		// Se pressionar 'S' ou 's'
		if((opcao == 'S') || (opcao == 's')){

			// Cria um arquivo logico para manipular os dados
			FILE *DBTEMP;

			// Criando arquivo fisico da manipulacao
			DBTEMP = fopen("DBTEMP.TXT","w");

			// Posicionando no na posicao do registro do CPF buscado
			fseek(DBVEICULO, posicao * sizeof(REG), SEEK_SET);

			// Lendo Arquivo e gravando na REG
			fread(&REG, sizeof(REG), 1, DBVEICULO);

			// Pegando cpf a excluir
			strcpy (placaExcluido,REG.placa);

			// Posicionando no inicio do arquivo DBCLIENTE
			rewind(DBVEICULO);

			// Lendo arquivo DBCLIENTE
			fread(&REG, sizeof(REG), 1, DBVEICULO);

			// Enquanto não for final de arquivo e se a placa buscado for igual o do arquivo ele nao grava no temp
			while(!feof(DBVEICULO)){
				if(strcmp(REG.placa,placaExcluido) != 0){
					fwrite(&REG, sizeof(REG), 1, DBTEMP);
				}
				fread(&REG, sizeof(REG), 1, DBVEICULO);
			}

			// Fechando arquivos
			fclose(DBVEICULO);
			fclose(DBTEMP);

			// Abrindo arquivos
			DBVEICULO = fopen("DBVEICULO.TXT","w");
			DBTEMP = fopen("DBTEMP.TXT","r+");

			// Copiando aquivo DBTEMP para DBCLIENTE
			fread(&REG, sizeof(REG), 1, DBTEMP);
			while(!feof(DBTEMP)){
				fwrite(&REG, sizeof(REG), 1, DBVEICULO);
				fread(&REG, sizeof(REG), 1, DBTEMP);
			}

			// Fechando Arquivos e apagando arquivo DBTEMP
			fclose(DBVEICULO);
			fclose(DBTEMP);
			remove("DBTEMP.TXT");

			// Mensagem de exclusao Sucesso
			mvwprintw(janela,19,20,"    CLIENTE EXCLUIDO COM SUCESSO!     ");
			mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
			wrefresh(janela);
			// Parando tela
			getchar();

		}

	else{
	mvwprintw(janela,19,20,"       EXCLUSAO CANCELADA!           ");
	mvwprintw(janela,20,20,"    O CLIENTE NAO ESTA EXCLUIDO!        ");
	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	wrefresh(janela);
	getchar();
	}


// Mostrar Cursor
curs_set(0);

// Nao ecoar na tela
noecho();
}

void updateKmVEICULO(int posicao, int kmupdate){

	// Mostrar Cursor
	curs_set(1);

	// Nao ecoar na tela
	echo();

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r+");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){
		DBVEICULO = fopen("DBVEICULO.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro do CPF buscado
	fseek(DBVEICULO, posicao * sizeof(REG), SEEK_SET);

	// Lendo Arquivo e gravando na REG
	fread(&REG, sizeof(REG), 1, DBVEICULO);

	// Setando status como ATIVO 1
	REG.km = kmupdate;

	// Posicionando no CPF buscado
	fseek(DBVEICULO, sizeof(REG) * (posicao), SEEK_SET);

	// Gravando no arquivo
	fwrite(&REG, sizeof(REG), 1, DBVEICULO);

	// Fechando o arquivo
	fclose(DBVEICULO);
	}
// Mostrar Cursor
curs_set(0);

// Nao ecoar na tela
noecho();
}
