#include"cliente.h"

int buscarCPF(char *cpf){

	// Definindo variaveis
	int cont = 0;
	STR_CLIENTE REG;

	// Definindo arquivo logico
	FILE *DBCLIENTE;

	// Definindo arquivo fisico como leitura
	DBCLIENTE = fopen("DBCLIENTE.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBCLIENTE == NULL){
		DBCLIENTE = fopen("DBCLIENTE.TXT","w");
	}

	else{

	// Lendo arquivos do DBCLIENTE
	fread(&REG,sizeof(REG),1,DBCLIENTE);

	// Iniciando condicionais
	while(!feof(DBCLIENTE) && (strcmp(REG.cpf,cpf) != 0)){
		cont++;
		fread(&REG,sizeof(REG),1,DBCLIENTE);
		}
	}

	// Fechando o arquivo
	fclose(DBCLIENTE);

	// Se encontrar CPF retorna a posicao
	if(strcmp(REG.cpf,cpf) == 0){
		return(cont);
	}

	// Senao ele retorna -10 que significa que nao encontrou o CPF
	else{
		return(-10);
	}


}

int validarCPF(char *cpf){

	// Declarando variaveis
    int i, j, digito1 = 0, digito2 = 0;

	// Condicional se CPF não conter 11 digitos é invalido
	if(strlen(cpf) != 11)
	   return 0;


	// Condicional se o CPF tiver todos numeros iguais é invalido
    if ((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) ||
       (strcmp(cpf,"22222222222") == 0) || (strcmp(cpf,"33333333333") == 0) ||
       (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
       (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) ||
       (strcmp(cpf,"88888888888") == 0) || (strcmp(cpf,"99999999999") == 0)){
        return 0;
	}

		else{

        // Digito 1 multiplica os números de 10 a 2 e soma os resultados dentro de digito1
			for(i = 0, j = 10; i < (signed) strlen(cpf)-2; i++, j--)
				digito1 += (cpf[i]-48) * j;
				digito1 %= 11;
				if(digito1 < 2)
					digito1 = 0;

					else
						digito1 = 11 - digito1;
						// Se o digito 1 não for o mesmo que o da validação CPF é inválido
						if((cpf[9]-48) != digito1)
							return 0;





        else{

        // Digito 2 multiplica os números de 11 a 2 e soma os resultados dentro de digito2
            for(i = 0, j = 11; i < (signed) strlen(cpf)-1; i++, j--)
                    digito2 += (cpf[i]-48) * j;
					digito2 %= 11;
						if(digito2 < 2)
							digito2 = 0;


						else
							digito2 = 11 - digito2;
							//Se o digito 2 não for o mesmo que o da validação CPF é inválido
							if((cpf[10]-48) != digito2)
								return 0;

			}
		}
    return 1;
}

int buscarLOCACAO(char *placa){

	// Definindo variaveis
	int cont = 0;
	STR_LOCACAO REG;

	strcpy(REG.placa,"");
	// Definindo arquivo logico
	FILE *DBLOCACAO;

	// Definindo arquivo fisico como leitura
	DBLOCACAO = fopen("DBLOCACAO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBLOCACAO == NULL){
		DBLOCACAO = fopen("DBLOCACAO.TXT","w");
	}

	else{

	// Lendo arquivos do DBCLIENTE
	fread(&REG,sizeof(STR_LOCACAO),1,DBLOCACAO);

	// Iniciando condicionais
	while(!feof(DBLOCACAO) && (strcmp(REG.placa,placa) != 0)){
		cont++;
		fread(&REG,sizeof(STR_LOCACAO),1,DBLOCACAO);
		}
	}

	// Fechando o arquivo
	fclose(DBLOCACAO);

	// Se encontrar CPF retorna a posicao
	if(strcmp(REG.placa,placa) == 0){
		return(cont);
	}

	// Senao ele retorna -10 que significa que nao encontrou a PLACA
	else{
		return(-10);
	}


}

int buscarStatusCLIENTE(int posicao){

	// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	// Definindo variaveis
	STR_CLIENTE REG;

	// Definindo arquivo logico
	FILE *DBCLIENTE;

	// Definindo arquivo fisico como leitura
	DBCLIENTE = fopen("DBCLIENTE.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBCLIENTE == NULL){
		DBCLIENTE = fopen("DBCLIENTE.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro do CPF buscado
	fseek(DBCLIENTE,posicao * sizeof(REG), 0);

	// Lendo arquivos do DBCLIENTE e printando
	fread(&REG,sizeof(REG),1,DBCLIENTE);

	// Fechando o arquivo
	fclose(DBCLIENTE);
	}

	// Se Status for significa que o registro esta inativo
	if(REG.status == 0){
		return 0;
		}

	else{
		return 1;
		}

}

void excluirCLIENTE(WINDOW *janela, int posicao){

	// Variaveis
	char opcao ='P';

	// Mostrar Cursor
	curs_set(1);

	// Nao ecoar na tela
	echo();

	// Definindo variaveis
	STR_CLIENTE REG;

	// Definindo arquivo logico
	FILE *DBCLIENTE;

	// Definindo arquivo fisico como leitura
	DBCLIENTE = fopen("DBCLIENTE.TXT","r+");

	// Condicional se o arquivo nao existir ele cria
	if(DBCLIENTE == NULL){
		DBCLIENTE = fopen("DBCLIENTE.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro do CPF buscado
	fseek(DBCLIENTE, posicao * sizeof(REG), SEEK_SET);

	// Lendo Arquivo e gravando na REG
	fread(&REG, sizeof(REG), 1, DBCLIENTE);

	// Confirmacao de exclusao
	while((opcao != 'S') && (opcao != 'N') && (opcao != 's') && (opcao != 'n') && (REG.status != 0) ){
		mvwprintw(janela,16,20,"DESEJA REALMENTE EXCLUIR?(S/N)_",posicao);
		opcao = mvwgetch(janela,16,50);

	}

		if((opcao == 'S') || (opcao == 's')){
			// Setando status como inativo 0
			REG.status = 0;

			// Posicionando no CPF buscado
			fseek(DBCLIENTE, sizeof(REG) * (posicao), SEEK_SET);

			// Gravando no arquivo
			fwrite(&REG, sizeof(REG), 1, DBCLIENTE);

			// Fechando o arquivo
			fclose(DBCLIENTE);

			// Mensagem de exclusao Sucesso
			mvwprintw(janela,19,20,"     CLIENTE EXLUIDO COM SUCESSO!     ");
			mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
			wrefresh(janela);
			// Parando tela
			getchar();

		}

	else{
	mvwprintw(janela,20,20,"           EXCLUSAO CANCELADA!    ");
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

void editarCLIENTE(WINDOW *janela, int posicao){
	// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	int NovoresultadoBuscaCPF;
	int NovoresultadoValidaCPF;

	// Definindo variaveis
	STR_CLIENTE REG;

	// Definindo arquivo logico
	FILE *DBCLIENTE;

	// Definindo arquivo fisico como leitura
	DBCLIENTE = fopen("DBCLIENTE.TXT","r+");

	// Condicional se o arquivo nao existir ele cria
	if(DBCLIENTE == NULL){
		DBCLIENTE = fopen("DBCLIENTE.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro do CPF buscado
	fseek(DBCLIENTE, sizeof(REG) * (posicao), SEEK_SET);

	// Lendo Arquivo e gravando na REG
	fread(&REG, sizeof(REG), 1, DBCLIENTE);

	if(REG.status == 0){

		printMensagemERRO(janela,13,20,"                ERRO!              ");
		printMensagemERRO(janela,14,20,"   O CPF DIGITADO ESTA EXCLUIDO!   ");
		printMensagemERRO(janela,15,20,"      ACESSE O MENU LIXEIRA        ");
		getchar();
		}

	else{

	printDadosCLIENTEATIVO(janela, posicao);

	// Chamando Subrotina Verificar STRING NOME
	scanStringComESPACO(janela,16,25,2,31,REG.nome);

	// Chamando Subrotina Verificar INTEIRO CPF
	scanStringSemESPACO(janela,17,24,2,12,REG.cpf);

	// Valida CPF
	NovoresultadoValidaCPF = validarCPF(REG.cpf);

	// Verifica se CPF consta no ARQUIVO
	NovoresultadoBuscaCPF =  buscarCPF(REG.cpf);

	// Se o resultado da FUNCAO VALIDA CPF for diferente de 1 CPF é invalido
	if(NovoresultadoValidaCPF != 1){
		printMensagemERRO(janela,13,20,"                ERRO!              ");
		printMensagemERRO(janela,14,20,"     O CPF DIGITADO E INVALIDO     ");
		printMensagemERRO(janela,15,20,"       INSIRA UM CPF VALIDO!       ");
		mvwprintw(janela,20,20,"            EDICAO CANCELADA!           ");
		mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
		wrefresh(janela);
		getchar();
	}

	// Se o resultado da BUSCA CPF for diferente de -10 o CPF Existe
	else if(NovoresultadoBuscaCPF != -10 && NovoresultadoBuscaCPF != posicao){
		printMensagemERRO(janela,13,20,"                ERRO!              ");
		printMensagemERRO(janela,14,20,"      O CPF DIGITADO JA EXISTE     ");
		printMensagemERRO(janela,15,20,"         INSIRA UM NOVO CPF!       ");
		mvwprintw(janela,20,20,"            EDICAO CANCELADA!           ");
		mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
		wrefresh(janela);
		getchar();
	}

	else if(NovoresultadoBuscaCPF == -10 || NovoresultadoBuscaCPF == posicao){
	// Chamando Subrotina Scan LONG INT TELEFONE
	scanLongInteiro(janela,18,29,2,11,&REG.tel);

	// Posicionando no CPF buscado
	fseek(DBCLIENTE, sizeof(REG) * (posicao), SEEK_SET);

	// Gravando no arquivo
	fwrite(&REG, sizeof(REG), 1, DBCLIENTE);

	// Fechando o arquivo
	fclose(DBCLIENTE);

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

void restaurarCLIENTE(WINDOW *janela, int posicao){

	// Variaveis
	char opcao ='P';

	// Mostrar Cursor
	curs_set(1);

	// Nao ecoar na tela
	echo();

	// Definindo variaveis
	STR_CLIENTE REG;

	// Definindo arquivo logico
	FILE *DBCLIENTE;

	// Definindo arquivo fisico como leitura
	DBCLIENTE = fopen("DBCLIENTE.TXT","r+");

	// Condicional se o arquivo nao existir ele cria
	if(DBCLIENTE == NULL){
		DBCLIENTE = fopen("DBCLIENTE.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro do CPF buscado
	fseek(DBCLIENTE, posicao * sizeof(REG), SEEK_SET);

	// Lendo Arquivo e gravando na REG
	fread(&REG, sizeof(REG), 1, DBCLIENTE);

	// Confirmacao de exclusao
	while((opcao != 'S') && (opcao != 'N') && (opcao != 's') && (opcao != 'n') && (REG.status != 1) ){
		mvwprintw(janela,16,20,"DESEJA REALMENTE RESTAURAR?(S/N)_",posicao);
		opcao = mvwgetch(janela,16,52);

	}

		if((opcao == 'S') || (opcao == 's')){
			// Setando status como inativo 0
			REG.status = 1;

			// Posicionando no CPF buscado
			fseek(DBCLIENTE, sizeof(REG) * (posicao), SEEK_SET);

			// Gravando no arquivo
			fwrite(&REG, sizeof(REG), 1, DBCLIENTE);

			// Fechando o arquivo
			fclose(DBCLIENTE);

			// Mensagem de exclusao Sucesso
			mvwprintw(janela,19,20,"    CLIENTE RESTAURADO COM SUCESSO!     ");
			mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
			wrefresh(janela);
			// Parando tela
			getchar();

		}

	else{
	mvwprintw(janela,19,20,"       RESTAURACAO CANCELADA!           ");
	mvwprintw(janela,20,20,"    O CLIENTE NAO ESTA EXCLUIDO!        ");
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

void esvaziarCLIENTE(WINDOW *janela, int posicao){

	// Variaveis
	char opcao ='P';
	char cpfExcluido[30];

	// Mostrar Cursor
	curs_set(1);

	// Nao ecoar na tela
	echo();

	// Definindo variaveis
	STR_CLIENTE REG;

	// Definindo arquivo logico
	FILE *DBCLIENTE;

	// Definindo arquivo fisico como leitura
	DBCLIENTE = fopen("DBCLIENTE.TXT","r+");

	// Condicional se o arquivo nao existir ele cria
	if(DBCLIENTE == NULL){
		DBCLIENTE = fopen("DBCLIENTE.TXT","w");
	}


	// Posicionando no na posicao do registro do CPF buscado
	fseek(DBCLIENTE, posicao * sizeof(REG), SEEK_SET);

	// Lendo Arquivo e gravando na REG
	fread(&REG, sizeof(REG), 1, DBCLIENTE);

	// Confirmacao de exclusao
	while((opcao != 'S') && (opcao != 'N') && (opcao != 's') && (opcao != 'n') && (REG.status != 1) ){
		mvwprintw(janela,16,13,"DESEJA REALMENTE EXCLUIR DEFINITIVAMENTE?(S/N)_",posicao);
		opcao = mvwgetch(janela,16,59);

	}
		// Se pressionar 'S' ou 's'
		if((opcao == 'S') || (opcao == 's')){

			// Cria um arquivo logico para manipular os dados
			FILE *DBTEMP;

			// Criando arquivo fisico da manipulacao
			DBTEMP = fopen("DBTEMP.TXT","w");

			// Posicionando no na posicao do registro do CPF buscado
			fseek(DBCLIENTE, posicao * sizeof(REG), SEEK_SET);

			// Lendo Arquivo e gravando na REG
			fread(&REG, sizeof(REG), 1, DBCLIENTE);

			// Pegando cpf a excluir
			strcpy (cpfExcluido,REG.cpf);

			// Posicionando no inicio do arquivo DBCLIENTE
			rewind(DBCLIENTE);

			// Lendo arquivo DBCLIENTE
			fread(&REG, sizeof(REG), 1, DBCLIENTE);

			// Enquanto não for final de arquivo e se o cpf buscado for igual o do arquivo ele nao grava no temp
			while(!feof(DBCLIENTE)){
				if(strcmp(REG.cpf,cpfExcluido) != 0){
					fwrite(&REG, sizeof(REG), 1, DBTEMP);
				}
				fread(&REG, sizeof(REG), 1, DBCLIENTE);
			}

			// Fechando arquivos
			fclose(DBCLIENTE);
			fclose(DBTEMP);

			// Abrindo arquivos
			DBCLIENTE = fopen("DBCLIENTE.TXT","w");
			DBTEMP = fopen("DBTEMP.TXT","r+");

			// Copiando aquivo DBTEMP para DBCLIENTE
			fread(&REG, sizeof(REG), 1, DBTEMP);
			while(!feof(DBTEMP)){
				fwrite(&REG, sizeof(REG), 1, DBCLIENTE);
				fread(&REG, sizeof(REG), 1, DBTEMP);
			}

			// Fechando Arquivos e apagando arquivo DBTEMP
			fclose(DBCLIENTE);
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
