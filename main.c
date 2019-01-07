#include"locadora.h"
#include"cliente.h"
#include"veiculo.h"

/*
 *   Sistema Empurra_pé | Projeto UFERSA 2017.2
 * 	 Created by Déborah Assunção and Eliomar Rabelo | Date : 19 / 04 / 2018
 */

int main(void){

	// Declarando Variaveis
	int tecla;
	int sombreamento = 1;
	int opcao;
	int resultadoBuscaUSUARIO;
	int resultadoBuscaCPF;
	int resultadoValidaCPF;
	int resultadoBuscaPLACA;
	int resultadoBuscaStatusCLIENTE;
	int resultadoBuscaStatusVEICULO;
	int resultadoBuscaLOCACAO;
	float resultadoValorDiariaVEICULO;
	int resultadoValorKmInicialVEICULO;
	float resultadoValorTotalLOCACAO;
	float resultadoValorMultaKmVEICULO;
	int resultadoLimiteKmVEICULO;
	float resultadoBuscarValorTotalLOCACAO;

	STR_USER USUARIO;
	STR_CLIENTE CLIENTE;
	STR_VEICULO VEICULO;
	STR_LOCACAO LOCACAO;
	STR_DEVOLUCAO DEVOLUCAO;

	// Declarando Janela Menu
	WINDOW *janelaprincipal;
	WINDOW *janelalogin;

	// Declarando Arquivo Logico
	FILE *DBUSUARIO;
	FILE *DBCLIENTE;
	FILE *DBVEICULO;
	FILE *DBLOCACAO;
	FILE *DBDEVOLUCAO;

	// Iniciando Ncurses
    initscr();

	// Iniciando Cores
    start_color();

	// Definindo tamanho da Janela Principal
    janelalogin = newwin(10,30,5,26);

    // Iniciando Setas & Caracteres do Ncurses
    keypad(janelalogin,TRUE);

    // Printando tela LOGIN
    printTelaLOGIN(janelalogin);
    scanStringInteiroSemESPACO(janelalogin,6,9,2,10,USUARIO.nome);
    scanInteiro(janelalogin,7,9,2,10,&USUARIO.senha);

    // Definindo arquivo fisico como leitura
	DBUSUARIO = fopen("DBUSUARIO.TXT","a+");

	// Condicional se o arquivo nao existir ele cria
	if(DBUSUARIO == NULL){
		DBUSUARIO = fopen("DBUSUARIO.TXT","w");
	}

   // Gravando no arquivo
	fwrite(&USUARIO, sizeof(USUARIO), 1, DBUSUARIO);

	// Fechando Arquivo
	fclose(DBUSUARIO);

    // Buscando Usuario
    resultadoBuscaUSUARIO = buscarUSUARIO(USUARIO.nome);

    if(resultadoBuscaUSUARIO != -10){
	mvwprintw(janelalogin, 2, 3, "                          ");
	mvwprintw(janelalogin, 3, 3, "  SEJA BEM VINDO %s  ",USUARIO.nome);
	mvwprintw(janelalogin, 4, 3, "                          ");
	wrefresh(janelalogin);
	getchar();

    // Definindo tamanho da Janela Principal
    janelaprincipal = newwin(linha,coluna,iniciaLinha,iniciaColuna);

	// Iniciando Setas & Caracteres do Ncurses
    keypad(janelaprincipal,TRUE);

    // Iniciando Ciclo
    do{

		// Chamando subrotina print menu principal
		printMenuPrincipal(janelaprincipal, sombreamento);

		// Recebendo valor da tecla
		tecla = wgetch(janelaprincipal);

		// Condicionais
		switch(tecla) {

		   // Se pressionar UP (Cima)
           case KEY_UP:
				if(sombreamento == 1)
					sombreamento = 6;
					else
						sombreamento--;
					break;

			// Se pressionar DOWN(Baixo)
            case KEY_DOWN:
				if(sombreamento == 6)
					sombreamento = 1;
					else
						sombreamento++;
					break;

			// Se pressionar ENTER
			case 10:

				// Recebendo opcao escolhida atraves da contagem sombreamento
				opcao = sombreamento;

				// ****************** CLIENTES ******************
				if (opcao == 1){

					// Destroi a Janela Principal
					destruirJanela(janelaprincipal);

					// Atribuindo valor original do sombreamento
					sombreamento = 1;

					// Iniciando Cliclo do menu CRUD
					do{
						// Chamando a subrotina imprimir tela CRUD
						printMenuCLIENTECRUD(janelaprincipal,sombreamento);

						// Recebendo tecla pressionada
						tecla = wgetch(janelaprincipal);

						// Iniciando condicionais da tecla
						switch(tecla) {

							// Se pressionar UP (Cima)
							case KEY_UP:
								if(sombreamento == 1)
									sombreamento = 6;
									else
										sombreamento--;
							break;

							// Se pressionar DOWN(Baixo)
							case KEY_DOWN:
								if(sombreamento == 6)
									sombreamento = 1;
									else
										sombreamento++;
							break;

							// Se pressionar ENTER
							case 10:

							// Recebendo opcao escolhida atraves da contagem sombreamento
							opcao = sombreamento;

								// Se opcao escolhida for 1	"CADASTRAR"
								if( opcao == 1){
									// Destroi Janela CRUD
									destruirJanela(janelaprincipal);

									// Imprimi a tela de Cadastro do CRUD
									printTelaCadastrarCLIENTE(janelaprincipal);

									// Chamando Subrotina Verificar STRING NOME
									scanStringComESPACO(janelaprincipal,7,25,2,31,CLIENTE.nome);

									// Chamando Subrotina Verificar INTEIRO CPF
									scanStringSemESPACO(janelaprincipal,8,24,2,12,CLIENTE.cpf);

									// Verifica se CPF consta no ARQUIVO
									resultadoBuscaCPF =  buscarCPF(CLIENTE.cpf);

									// Valida CPF
									resultadoValidaCPF = validarCPF(CLIENTE.cpf);

									// Se Resultado da funcao for diferente de -10 encontrou o CPF
									if(resultadoBuscaCPF != -10){
										printMensagemERRO(janelaprincipal,13,20,"                ERRO!              ");
										printMensagemERRO(janelaprincipal,14,20,"      O CPF DIGITADO JA EXISTE     ");
										printMensagemERRO(janelaprincipal,15,20,"         INSIRA UM NOVO CPF!       ");
										getchar();
									}

									// Se validar CPF for diferente de 1 CPF invalido
									else if(resultadoValidaCPF != 1){
										printMensagemERRO(janelaprincipal,13,20,"                ERRO!              ");
										printMensagemERRO(janelaprincipal,14,20,"     O CPF DIGITADO E INVALIDO     ");
										printMensagemERRO(janelaprincipal,15,20,"       INSIRA UM CPF VALIDO!       ");
										getchar();
									}

									// Senao continua o cadastro
									else{

										// Chamando Subrotina Verificar INTEIRO TELEFONE
										scanLongInteiro(janelaprincipal,9,29,2,11,&CLIENTE.tel);

										// Chamando Subrotina Verificar STRING RUA
										scanStringComESPACO(janelaprincipal,10,24,2,19,CLIENTE.rua);

										// Chamando Subrotina Verificar INTEIRO NUMERO
										scanInteiro(janelaprincipal,11,27,2,12,&CLIENTE.num);

										// Chamando Subrotina Verificar STRING BAIRRO
										scanStringComESPACO(janelaprincipal,12,27,2,12,CLIENTE.bairro);

										// Chamando Subrotina Verificar STRING BAIRRO
										scanStringComESPACO(janelaprincipal,13,24,2,12,CLIENTE.cep);

										// Chamando Subrotina Verificar STRING RUA
										scanStringComESPACO(janelaprincipal,14,27,2,19,CLIENTE.cidade);

									// Setando status como ativo
									CLIENTE.status = 1;

									// Abrindo arquivo DATABASE CLIENTE
									DBCLIENTE = fopen("DBCLIENTE.TXT","a+");

									// Gravando nome do Cliente no disco
									fwrite(&CLIENTE,sizeof(CLIENTE), 1,DBCLIENTE);

									// Mensagem de gravado com Sucesso!
									printMensagemSUCESSO(janelaprincipal,16,20,"                                   ");
									printMensagemSUCESSO(janelaprincipal,17,20,"   CADASTRO EFETUADO COM SUCESSO!  ");
									printMensagemSUCESSO(janelaprincipal,18,20,"                                   ");
									getchar();

									// Gravando no disco;
									fclose(DBCLIENTE);
									}

									// Destroi a Janela de Cadastro
									destruirJanela(janelaprincipal);
								}

								// Se opcao escolhida for 2 "PESQUISAR"
								if( opcao == 2){
									// Destroi Janela CRUD
									destruirJanela(janelaprincipal);

									// Imprimi a tela de Cadastro do CRUD
									printTelaPesquisarCLIENTE(janelaprincipal);

									// Chamando Subrotina Verificar INTEIRO CPF
									scanStringSemESPACO(janelaprincipal,7,33,2,12,CLIENTE.cpf);

									// Verifica se CPF consta no ARQUIVO
									resultadoBuscaCPF =  buscarCPF(CLIENTE.cpf);

									// Valida CPF
									resultadoValidaCPF = validarCPF(CLIENTE.cpf);

									// Se busca CPF for diferente de -10 ele encontrou o CPF no arquivo
									if(resultadoBuscaCPF != -10){

									// Imprimindo dados
									printDadosCLIENTEATIVO(janelaprincipal,resultadoBuscaCPF);

									// Imprimindo tecla para pressionar para continuar
									mvwprintw(janelaprincipal,21,18,"Pressione qualquer tecla para continuar!");

									// Atualizando janela
									wrefresh(janelaprincipal);

									// Esperando pressionar qualquer tecla
									getchar();
									}

									// Se validar CPF for diferente de 1, CPF invalido
									else if(resultadoValidaCPF != 1){

										printMensagemERRO(janelaprincipal,13,20,"                ERRO!              ");
										printMensagemERRO(janelaprincipal,14,20,"     O CPF DIGITADO E INVALIDO     ");
										printMensagemERRO(janelaprincipal,15,20,"       INSIRA UM CPF VALIDO!       ");

										// Esperando pressionar qualquer tecla
										getchar();
									}

									// Se busca CPF for igual a -10 cpf nao existe no arquivo
									else if(resultadoBuscaCPF == -10){

										printMensagemERRO(janelaprincipal,13,20,"                ERRO!              ");
										printMensagemERRO(janelaprincipal,14,20,"O CPF DIGITADO NAO ESTA CADASTRADO!");
										printMensagemERRO(janelaprincipal,15,20,"         INSIRA UM NOVO CPF!       ");

										// Esperando pressionar qualquer tecla
										getchar();
									}

									// Destroi a Janela de Cadastro
									destruirJanela(janelaprincipal);
								}

								// Se opcao escolhida for 3 "EXCLUIR"
								if( opcao == 3){
									// Destroi Janela CRUD
									destruirJanela(janelaprincipal);

									// Imprimi a tela de Cadastro do CRUD
									printTelaExcluirCLIENTE(janelaprincipal);

									// Chamando Subrotina Verificar INTEIRO CPF
									scanStringSemESPACO(janelaprincipal,7,33,2,12,CLIENTE.cpf);

									// Verifica se CPF consta no ARQUIVO
									resultadoBuscaCPF =  buscarCPF(CLIENTE.cpf);

									// Valida CPF
									resultadoValidaCPF = validarCPF(CLIENTE.cpf);

									// Se busca CPF for diferente de -10 ele encontrou o CPF no arquivo
									if(resultadoBuscaCPF != -10){
										printDadosCLIENTEATIVO(janelaprincipal, resultadoBuscaCPF);
										excluirCLIENTE(janelaprincipal, resultadoBuscaCPF);

									}

									// Se validar CPF for diferente de 1, CPF invalido
									else if(resultadoValidaCPF != 1){

										printMensagemERRO(janelaprincipal,13,20,"                ERRO!              ");
										printMensagemERRO(janelaprincipal,14,20,"     O CPF DIGITADO E INVALIDO     ");
										printMensagemERRO(janelaprincipal,15,20,"       INSIRA UM CPF VALIDO!       ");

										// Esperando pressionar qualquer tecla
										getchar();
									}

									// Se busca CPF for igual a -10 cpf nao existe no arquivo
									else if(resultadoBuscaCPF == -10){

										printMensagemERRO(janelaprincipal,13,20,"                ERRO!              ");
										printMensagemERRO(janelaprincipal,14,20,"O CPF DIGITADO NAO ESTA CADASTRADO!");
										printMensagemERRO(janelaprincipal,15,20,"         INSIRA UM NOVO CPF!       ");

										// Esperando pressionar qualquer tecla
										getchar();
									}

									// Destroi a Janela de Cadastro
									destruirJanela(janelaprincipal);
								}

								// Se opcao escolhida for 4 "EDITAR"
								if( opcao == 4){
									// Destroi Janela CRUD
									destruirJanela(janelaprincipal);

									// Imprimi a tela de Cadastro do CRUD
									printTelaEditarCLIENTE(janelaprincipal);

									// Chamando Subrotina Verificar INTEIRO CPF
									scanStringSemESPACO(janelaprincipal,7,33,2,12,CLIENTE.cpf);

									// Verifica se CPF consta no ARQUIVO
									resultadoBuscaCPF =  buscarCPF(CLIENTE.cpf);

									// Valida CPF
									resultadoValidaCPF = validarCPF(CLIENTE.cpf);

									// Se busca CPF for diferente de -10 ele encontrou o CPF no arquivo
									if(resultadoBuscaCPF != -10){

										editarCLIENTE(janelaprincipal,resultadoBuscaCPF);

									}

									// Se o resultado da VALIDA CPF for diferente de 1 CPF é invalido
									else if(resultadoValidaCPF != 1){
										printMensagemERRO(janelaprincipal,13,20,"                ERRO!              ");
										printMensagemERRO(janelaprincipal,14,20,"     O CPF DIGITADO E INVALIDO     ");
										printMensagemERRO(janelaprincipal,15,20,"       INSIRA UM CPF VALIDO!       ");
										getchar();
									}

									// Se o resultado da BUSCA CPF for igual a -10 ele não encontrou o CPF
									else if(resultadoBuscaCPF == -10){
										printMensagemERRO(janelaprincipal,13,20,"                ERRO!              ");
										printMensagemERRO(janelaprincipal,14,20,"O CPF DIGITADO NAO ESTA CADASTRADO!");
										printMensagemERRO(janelaprincipal,15,20,"         INSIRA UM NOVO CPF!       ");
											getchar();
									}

									// Destroi a Janela de Cadastro
									destruirJanela(janelaprincipal);
								}

								// Se opcao escolhida for 5 "LIXEIRA"
								if( opcao == 5){

								// Destroi Janela CRUD
								destruirJanela(janelaprincipal);

								// Atribuindo valor original do sombreamento
								sombreamento = 1;

									do{
										printMenuCLIENTELIXEIRA(janelaprincipal,sombreamento);

										// Recebendo tecla pressionada
										tecla = wgetch(janelaprincipal);

										// Iniciando condicionais da tecla
										switch(tecla) {

										// Se pressionar UP (Cima)
											case KEY_UP:
											if(sombreamento == 1)
												sombreamento = 4;
											else
												sombreamento--;
											break;

											// Se pressionar DOWN(Baixo)
											case KEY_DOWN:
											if(sombreamento == 4)
												sombreamento = 1;
												else
												sombreamento++;
											break;

											// Se pressionar ENTER
											case 10:

											// Recebendo opcao escolhida atraves da contagem sombreamento
											opcao = sombreamento;

											// Se opcao Escolhida for EXIBIR LIXEIRA
											if(opcao == 1){
												// Destroi Janela CRUD
												destruirJanela(janelaprincipal);

												// Mostra Relatorio clientes da LIXEIRA
												printTelaRelatorioClientesEXCLUIDOS(janelaprincipal);

												// Espera alguma tecla
												getchar();

												// Destroi janela
												destruirJanela(janelaprincipal);
												}

											// Se opcao Escolhida for RESTAURAR CLIENTE LIXEIRA
											if(opcao == 2){
												printTelaLixeiraRESTAURARCLIENTE(janelaprincipal);

												// Chamando Subrotina Verificar INTEIRO CPF
												scanStringSemESPACO(janelaprincipal,7,45,2,12,CLIENTE.cpf);

												// Verifica se CPF consta no ARQUIVO
												resultadoBuscaCPF =  buscarCPF(CLIENTE.cpf);

												// Valida CPF
												resultadoValidaCPF = validarCPF(CLIENTE.cpf);

												// Se o resultado da VALIDA CPF for diferente de 1 CPF é invalido
												if(resultadoValidaCPF != 1){
													printMensagemERRO(janelaprincipal,13,20,"                ERRO!              ");
													printMensagemERRO(janelaprincipal,14,20,"     O CPF DIGITADO E INVALIDO     ");
													printMensagemERRO(janelaprincipal,15,20,"       INSIRA UM CPF VALIDO!       ");
													getchar();
												}

												// Se o resultado da BUSCA CPF for igual a -10 ele não encontrou o CPF
												else if(resultadoBuscaCPF == -10){
													printMensagemERRO(janelaprincipal,13,20,"                ERRO!              ");
													printMensagemERRO(janelaprincipal,14,20,"O CPF DIGITADO NAO ESTA CADASTRADO!");
													printMensagemERRO(janelaprincipal,15,20,"         INSIRA UM NOVO CPF!       ");
													getchar();
												}

												else if(resultadoBuscaCPF != 10){
													printDadosCLIENTEINATIVO(janelaprincipal,resultadoBuscaCPF);
													restaurarCLIENTE(janelaprincipal,resultadoBuscaCPF);

												}

												destruirJanela(janelaprincipal);

												}

											// Se opcao Escolhida for ESVAZIAR LIXEIRA
											if(opcao == 3){
												printTelaLixeiraESVAZIARCLIENTE(janelaprincipal);

												// Chamando Subrotina Verificar INTEIRO CPF
												scanStringSemESPACO(janelaprincipal,7,43,2,12,CLIENTE.cpf);

												// Verifica se CPF consta no ARQUIVO
												resultadoBuscaCPF =  buscarCPF(CLIENTE.cpf);

												// Valida CPF
												resultadoValidaCPF = validarCPF(CLIENTE.cpf);

												// Se o resultado da VALIDA CPF for diferente de 1 CPF é invalido
												if(resultadoValidaCPF != 1){
													printMensagemERRO(janelaprincipal,13,20,"                ERRO!              ");
													printMensagemERRO(janelaprincipal,14,20,"     O CPF DIGITADO E INVALIDO     ");
													printMensagemERRO(janelaprincipal,15,20,"       INSIRA UM CPF VALIDO!       ");
													getchar();
												}

												// Se o resultado da BUSCA CPF for igual a -10 ele não encontrou o CPF
												else if(resultadoBuscaCPF == -10){
													printMensagemERRO(janelaprincipal,13,20,"                ERRO!              ");
													printMensagemERRO(janelaprincipal,14,20,"O CPF DIGITADO NAO ESTA CADASTRADO!");
													printMensagemERRO(janelaprincipal,15,20,"         INSIRA UM NOVO CPF!       ");
													getchar();
												}

												else if(resultadoBuscaCPF != 10){
													printDadosCLIENTEINATIVO(janelaprincipal,resultadoBuscaCPF);
													esvaziarCLIENTE(janelaprincipal,resultadoBuscaCPF);

												}

												destruirJanela(janelaprincipal);

												}

											// Se opcao Escolhida for RETORNAR AO MENU CLIENTE
											if(opcao == 4){
												sombreamento = 1;
												destruirJanela(janelaprincipal);
												goto retornarMenuCRUDCLIENTE;
											}
										}
										destruirJanela(janelaprincipal);
									}while(1);

								}

								// Se opcao escolhida for 5 "RETORNAR AO MENU"
								if ( opcao == 6){
									sombreamento = 1;
									destruirJanela(janelaprincipal);
									goto retornarMenuPrincipal;
								}
								break;
							}
					// Goto para retornar ao MenuCRUD CLIENTE
					retornarMenuCRUDCLIENTE:
					refresh();
					endwin();

					destruirJanela(janelaprincipal);
					}while(1);
				}

				// ****************** VEICULOS ******************
				if (opcao == 2){

				// Destroi a Janela Principal
					destruirJanela(janelaprincipal);

					// Atribuindo valor original do sombreamento
					sombreamento = 1;

					// Iniciando Cliclo do menu CRUD
					do{
						// Chamando a subrotina imprimir tela CRUD
						printMenuVEICULOCRUD(janelaprincipal,sombreamento);

						// Recebendo tecla pressionada
						tecla = wgetch(janelaprincipal);

						// Iniciando condicionais da tecla
						switch(tecla) {

							// Se pressionar UP (Cima)
							case KEY_UP:
								if(sombreamento == 1)
									sombreamento = 6;
									else
										sombreamento--;
							break;

							// Se pressionar DOWN(Baixo)
							case KEY_DOWN:
								if(sombreamento == 6)
									sombreamento = 1;
									else
										sombreamento++;
							break;

							// Se pressionar ENTER
							case 10:

							// Recebendo opcao escolhida atraves da contagem sombreamento
							opcao = sombreamento;

								// Se opcao escolhida for 1	"CADASTRAR VEICULOS"
								if( opcao == 1){

									destruirJanela(janelaprincipal);

									// Imprimi a tela de Cadastro do CRUD
									printTelaCadastrarVEICULO(janelaprincipal);

									// Chamando Subrotina Verificar STRING PLACA
									scanStringInteiroSemESPACO(janelaprincipal,7,26,2,8,VEICULO.placa);

									// Função verificando se PLACA ja existe
									resultadoBuscaPLACA = buscarPLACA(VEICULO.placa);

									// Campo nao pode ser vazio
									if(strcmp(VEICULO.placa,"") == 0){
										printMensagemERRO(janelaprincipal,16,20,"               ERRO!               ");
										printMensagemERRO(janelaprincipal,17,20," O CAMPO PLACA NAO PODE SER VAZIO! ");
										printMensagemERRO(janelaprincipal,18,20,"       INSIRA UMA NOVA PLACA!      ");
										getchar();

									}

									// Se Resultado da funcao for diferente de -10 encontrou a PLACA
									else if(resultadoBuscaPLACA != -10){
										printMensagemERRO(janelaprincipal,16,20,"                ERRO!              ");
										printMensagemERRO(janelaprincipal,17,20,"    A PLACA DIGITADA JA EXISTE!    ");
										printMensagemERRO(janelaprincipal,18,20,"       INSIRA UMA NOVA PLACA!      ");
										getchar();
									}

									// Senao continua o cadastro
									else if(resultadoBuscaPLACA == -10){
									strcpy(VEICULO.modelo, "NULL");
									strcpy(VEICULO.marca, "NULL");
									VEICULO.ano = 0;
									VEICULO.km =  0;
									VEICULO.diaria = 0;
									VEICULO.limitekm =  0;
									VEICULO.valorkm =  0;
									VEICULO.status = 1;

									// Chamando Subrotina Verificar STRING MODELO
									scanStringInteiroComESPACO(janelaprincipal,8,27,2,16,VEICULO.modelo);

									// Chamando Subrotina Verificar STRING MARCA
									scanStringComESPACO(janelaprincipal,9,26,2,11,VEICULO.marca);

									// Chamando Subrotina Verificar INTEIRO ANO
									scanInteiro(janelaprincipal,10,24,2,5,&VEICULO.ano);

									// Chamando Subrotina Verificar INT KM
									scanInteiro(janelaprincipal,11,33,2,7,&VEICULO.km);

									// Chamando Subrotina Verificar INTLIMITE KM
									scanInteiro(janelaprincipal,12,40,2,7,&VEICULO.limitekm);

									// Chamando Subrotina Verificar FLOAT DIARIA
									scanFloat(janelaprincipal,13,36,2,7,&VEICULO.diaria);

									// Chamando Subrotina Verificar FLOAT VALORKM
									scanFloat(janelaprincipal,14,32,2,11,&VEICULO.valorkm);

									// Abrindo arquivo DATABASE CLIENTE
									DBVEICULO = fopen("DBVEICULO.TXT","a+");

									// Gravando dados VEICULO no disco
									fwrite(&VEICULO,sizeof(VEICULO), 1,DBVEICULO);

									// Mensagem de gravado com Sucesso!
									printMensagemSUCESSO(janelaprincipal,16,20,"                                   ");
									printMensagemSUCESSO(janelaprincipal,17,20,"   VEICULO CADASTRADO COM SUCESSO! ");
									printMensagemSUCESSO(janelaprincipal,18,20,"                                   ");
									getchar();

									// Gravando no disco;
									fclose(DBVEICULO);
									}

									// Destroi a Janela de Cadastro
									destruirJanela(janelaprincipal);
								}

								// Se opcao escolhida for 2 "PESQUISAR VEICULOS"
								if( opcao == 2){
									// Destroi Janela CRUD
									destruirJanela(janelaprincipal);

									// Imprimi a tela de Cadastro do CRUD
									printTelaPesquisarVEICULO(janelaprincipal);

									// Chamando Subrotina Verificar INTEIRO CPF
									scanStringInteiroSemESPACO(janelaprincipal,7,35,2,8,VEICULO.placa);

									// Função verificando se PLACA ja existe
									resultadoBuscaPLACA = buscarPLACA(VEICULO.placa);

									// Se Resultado for vazio mostra mensagem de erro
									if(strcmp(VEICULO.placa,"") == 0){
										printMensagemERRO(janelaprincipal,18,20,"               ERRO!               ");
										printMensagemERRO(janelaprincipal,19,20," O CAMPO PLACA NAO PODE SER VAZIO! ");
										printMensagemERRO(janelaprincipal,20,20,"       INSIRA UMA NOVA PLACA!      ");
										getchar();

										}

									// Se busca PLACA for igual a -10 placa nao existe no arquivo
									else if(resultadoBuscaPLACA == -10){

										printMensagemERRO(janelaprincipal,18,20,"                ERRO!              ");
										printMensagemERRO(janelaprincipal,19,20,"	 A PLACA NAO ESTA CADASTRADA!  ");
										printMensagemERRO(janelaprincipal,20,20,"       INSIRA UMA NOVA PLACA!      ");

										// Esperando pressionar qualquer tecla
										getchar();
									}

									// Se Resultado da funcao for diferente de -10 encontrou a PLACA
									else if (resultadoBuscaPLACA != -10){
										// Imprimindo dados do veiculo
										printDadosVEICULO(janelaprincipal,resultadoBuscaPLACA);

										// Imprimindo tecla para pressionar para continuar
										mvwprintw(janelaprincipal,21,18,"Pressione qualquer tecla para continuar!");

										// Atualizando janela
										wrefresh(janelaprincipal);

										// Esperando pressionar qualquer tecla
										getchar();
									}

									// Destroi a Janela de Cadastro
									destruirJanela(janelaprincipal);
								}

								// Se opcao escolhida for 3 "EXCLUIR VEICULOS"
								if( opcao == 3){
									// Destroi Janela CRUD
									destruirJanela(janelaprincipal);

									// Imprimi a tela de Cadastro do CRUD
									printTelaExcluirVEICULO(janelaprincipal);

									// Chamando Subrotina Verificar INTEIRO CPF
									scanStringInteiroSemESPACO(janelaprincipal,7,35,2,8,VEICULO.placa);

									// Verifica se CPF consta no ARQUIVO
									resultadoBuscaPLACA =  buscarPLACA(VEICULO.placa);

									// Se validar CPF for diferente de 1, CPF invalido
									if(strcmp(VEICULO.placa,"") == 0 ){

										printMensagemERRO(janelaprincipal,17,20,"               ERRO!               ");
										printMensagemERRO(janelaprincipal,18,20," O CAMPO PLACA NAO PODE SER VAZIO! ");
										printMensagemERRO(janelaprincipal,19,20,"       INSIRA UMA NOVA PLACA!      ");;

										wrefresh(janelaprincipal);

										// Esperando pressionar qualquer tecla
										getchar();
									}

									// Se busca CPF for igual a -10 cpf nao existe no arquivo
									else if(resultadoBuscaPLACA == -10){

										printMensagemERRO(janelaprincipal,17,20,"                ERRO!              ");
										printMensagemERRO(janelaprincipal,18,20,"	 A PLACA NAO ESTA CADASTRADA!  ");
										printMensagemERRO(janelaprincipal,19,20,"       INSIRA UMA NOVA PLACA!      ");
										wrefresh(janelaprincipal);

										// Esperando pressionar qualquer tecla
										getchar();
									}

									// Se busca CPF for diferente de -10 ele encontrou o CPF no arquivo
									else if (resultadoBuscaPLACA != -10){
										printDadosVEICULO(janelaprincipal, resultadoBuscaPLACA);
										excluirVEICULO(janelaprincipal, resultadoBuscaPLACA);

									}
									// Destroi a Janela de Cadastro
									destruirJanela(janelaprincipal);
								}

								// Se opcao escolhida for 4 "EDITAR VEICULOS"
								if( opcao == 4){
									// Destroi Janela CRUD
									destruirJanela(janelaprincipal);

									// Imprimi a tela de Cadastro do CRUD
									printTelaEditarVEICULO(janelaprincipal);

									// Chamando Subrotina Verificar INTEIRO E STRING PLACA
									scanStringInteiroSemESPACO(janelaprincipal,7,18,2,8,VEICULO.placa);

									// Verifica se CPF consta no ARQUIVO
									resultadoBuscaPLACA =  buscarPLACA(VEICULO.placa);


									// Se busca CPF for diferente de -10 ele encontrou a PLACA no arquivo
									if(resultadoBuscaPLACA != -10){

										editarVEICULO(janelaprincipal,resultadoBuscaPLACA);

									}

									// Se validar CPF for diferente de 1, CPF invalido
									if(strcmp(VEICULO.placa,"") == 0 ){

										printMensagemERRO(janelaprincipal,18,20,"               ERRO!               ");
										printMensagemERRO(janelaprincipal,19,20," O CAMPO PLACA NAO PODE SER VAZIO! ");
										printMensagemERRO(janelaprincipal,20,20,"       INSIRA UMA NOVA PLACA!      ");

										// Atualiza tela
										wrefresh(janelaprincipal);

										// Esperando pressionar qualquer tecla
										getchar();
									}

									// Se busca CPF for igual a -10 cpf nao existe no arquivo
									else if(resultadoBuscaPLACA == -10){

										printMensagemERRO(janelaprincipal,18,20,"                ERRO!              ");
										printMensagemERRO(janelaprincipal,19,20,"	 A PLACA NAO ESTA CADASTRADA!  ");
										printMensagemERRO(janelaprincipal,20,20,"       INSIRA UMA NOVA PLACA!      ");

										// Atualiza tela
										wrefresh(janelaprincipal);

										// Esperando pressionar qualquer tecla
										getchar();
									}

									// Destroi a Janela de Cadastro
									destruirJanela(janelaprincipal);
								}

								// Se opcao escolhida for 5 "LIXEIRA"
								if( opcao == 5){

								// Destroi Janela CRUD
								destruirJanela(janelaprincipal);

								// Atribuindo valor original do sombreamento
								sombreamento = 1;

									do{
										printMenuCLIENTELIXEIRA(janelaprincipal,sombreamento);

										// Recebendo tecla pressionada
										tecla = wgetch(janelaprincipal);

										// Iniciando condicionais da tecla
										switch(tecla) {

										// Se pressionar UP (Cima)
											case KEY_UP:
											if(sombreamento == 1)
												sombreamento = 4;
											else
												sombreamento--;
											break;

											// Se pressionar DOWN(Baixo)
											case KEY_DOWN:
											if(sombreamento == 4)
												sombreamento = 1;
												else
												sombreamento++;
											break;

											// Se pressionar ENTER
											case 10:

											// Recebendo opcao escolhida atraves da contagem sombreamento
											opcao = sombreamento;

											// Se opcao Escolhida for EXIBIR LIXEIRA
											if(opcao == 1){
												// Destroi Janela CRUD
												destruirJanela(janelaprincipal);

												// Mostra Relatorio clientes da LIXEIRA
												printTelaRelatorioVeiculosEXCLUIDOS(janelaprincipal);

												// Espera alguma tecla
												getchar();

												// Destroi janela
												destruirJanela(janelaprincipal);
												}

											// Se opcao Escolhida for RESTAURAR VEICULO LIXEIRA
											if(opcao == 2){
												printTelaLixeiraRESTAURARVEICULO(janelaprincipal);

												// Chamando Subrotina Verificar INTEIRO STRING PLACA
												scanStringInteiroSemESPACO(janelaprincipal,7,45,2,8,VEICULO.placa);

												// Verifica se PLACA consta no ARQUIVO
												resultadoBuscaPLACA =  buscarPLACA(VEICULO.placa);

												// Se o resultado da PLACA for vazio
												if(strcmp(VEICULO.placa,"") == 0){
													printMensagemERRO(janelaprincipal,17,20,"               ERRO!               ");
													printMensagemERRO(janelaprincipal,18,20," O CAMPO PLACA NAO PODE SER VAZIO! ");
													printMensagemERRO(janelaprincipal,19,20,"       INSIRA UMA NOVA PLACA!      ");
													getchar();
												}

												// Se o resultado da BUSCA PLACA for igual a -10 ele não encontrou a PLACA
												else if(resultadoBuscaPLACA == -10){
													printMensagemERRO(janelaprincipal,17,20,"                ERRO!              ");
													printMensagemERRO(janelaprincipal,18,20,"	 A PLACA NAO ESTA CADASTRADA!  ");
													printMensagemERRO(janelaprincipal,19,20,"       INSIRA UMA NOVA PLACA!      ");
													getchar();
												}

												else if(resultadoBuscaPLACA != 10){
													printDadosVEICULOINATIVO(janelaprincipal,resultadoBuscaPLACA);
													restaurarVEICULO(janelaprincipal,resultadoBuscaPLACA);

												}

												destruirJanela(janelaprincipal);

												}

											// Se opcao Escolhida for ESVAZIAR LIXEIRA
											if(opcao == 3){
												printTelaLixeiraESVAZIARVEICULO(janelaprincipal);

												// Chamando Subrotina Verificar INTEIRO CPF
												scanStringInteiroSemESPACO(janelaprincipal,7,45,2,8,VEICULO.placa);

												// Verifica se CPF consta no ARQUIVO
												resultadoBuscaPLACA =  buscarPLACA(VEICULO.placa);

											// Se o resultado da PLACA for vazio
												if(strcmp(VEICULO.placa,"") == 0){
													printMensagemERRO(janelaprincipal,17,20,"               ERRO!               ");
													printMensagemERRO(janelaprincipal,18,20," O CAMPO PLACA NAO PODE SER VAZIO! ");
													printMensagemERRO(janelaprincipal,19,20,"       INSIRA UMA NOVA PLACA!      ");
													getchar();
												}

												// Se o resultado da BUSCA PLACA for -10 nao encontrou a PLACA
												else if(resultadoBuscaPLACA == -10){
													printMensagemERRO(janelaprincipal,17,20,"                ERRO!              ");
													printMensagemERRO(janelaprincipal,18,20,"	 A PLACA NAO ESTA CADASTRADA!  ");
													printMensagemERRO(janelaprincipal,19,20,"       INSIRA UMA NOVA PLACA!      ");
													getchar();
												}

												else if(resultadoBuscaCPF != 10){
													printDadosVEICULOINATIVO(janelaprincipal,resultadoBuscaPLACA);
													esvaziarVEICULO(janelaprincipal,resultadoBuscaPLACA);

												}

												destruirJanela(janelaprincipal);

												}

											// Se opcao Escolhida for RETORNAR AO MENU CLIENTE
											if(opcao == 4){
												sombreamento = 1;
												destruirJanela(janelaprincipal);
												goto retornarMenuCRUDVeiculo;
											}
										}
										destruirJanela(janelaprincipal);
									}while(1);

								}

								// Se opcao escolhida for 5 "RETORNAR AO MENU"
								if ( opcao == 6){
									sombreamento = 1;
									destruirJanela(janelaprincipal);
									goto retornarMenuPrincipal;
								}
							break;
							}

					retornarMenuCRUDVeiculo:
					refresh();
					endwin();

					}while(1);
				}

				// ****************** LOCACAO  ******************
				if (opcao == 3){
					destruirJanela(janelaprincipal);

					//Imprime tela de LOCACAO
					printTelaLOCACAO(janelaprincipal);

					// Chamando Subrotina Verificar INTEIRO CPF
					scanStringSemESPACO(janelaprincipal,7,34,2,12,LOCACAO.cpf);

					// Verifica se CPF consta no ARQUIVO
					resultadoBuscaCPF =  buscarCPF(LOCACAO.cpf);

					// Valida CPF
					resultadoValidaCPF = validarCPF(LOCACAO.cpf);

					// Buscar Status do CLIENTE
					resultadoBuscaStatusCLIENTE = buscarStatusCLIENTE(resultadoBuscaCPF);

					// Se validar CPF for diferente de 1 CPF invalido
					if(resultadoValidaCPF != 1){
						printMensagemERRO(janelaprincipal,16,20,"                ERRO!              ");
						printMensagemERRO(janelaprincipal,17,20,"     O CPF DIGITADO E INVALIDO     ");
						printMensagemERRO(janelaprincipal,18,20,"       INSIRA UM CPF VALIDO!       ");
						getchar();
					}

					// Se Busca CPF == -10 o CPF nao esta CADASTRADO
					else if(resultadoBuscaCPF == -10){
						printMensagemERRO(janelaprincipal,16,20,"                ERRO!              ");
						printMensagemERRO(janelaprincipal,17,20,"O CPF DIGITADO NAO ESTA CADASTRADO!");
						printMensagemERRO(janelaprincipal,18,20,"         INSIRA UM NOVO CPF!       ");
						getchar();

					}

					// Se status == 0 o CPF esta EXCLUIDO
					else if(resultadoBuscaStatusCLIENTE == 0){
						printMensagemERRO(janelaprincipal,16,20,"                ERRO!              ");
						printMensagemERRO(janelaprincipal,17,20,"   O CPF DIGITADO ESTA EXCLUIDO!   ");
						printMensagemERRO(janelaprincipal,18,20,"       ACESSE O MENU LIXEIRA       ");
						getchar();
					}

					// Senao continua o cadastro da locacao
					else{

						// Chamando Subrotina Verificar STRING PLACA
						scanStringInteiroSemESPACO(janelaprincipal,8,36,2,8,LOCACAO.placa);

						// Chamando funcoes de BUSCA para verificacoes
						resultadoBuscaPLACA = buscarPLACA(LOCACAO.placa);
						resultadoBuscaLOCACAO = buscarLOCACAO(LOCACAO.placa);
						resultadoBuscaStatusVEICULO = buscarStatusVEICULO(resultadoBuscaPLACA);

						// Se campo placa for vazio
						if(strcmp(LOCACAO.placa,"") == 0){
							printMensagemERRO(janelaprincipal,16,20,"               ERRO!               ");
							printMensagemERRO(janelaprincipal,17,20," O CAMPO PLACA NAO PODE SER VAZIO! ");
							printMensagemERRO(janelaprincipal,18,20,"       INSIRA UMA NOVA PLACA!      ");
							getchar();
						}

						// Se busca PLACA == -10 a placa NAO EXISTE no arquivo
						else if(resultadoBuscaPLACA == -10){
							printMensagemERRO(janelaprincipal,16,20,"                ERRO!              ");
							printMensagemERRO(janelaprincipal,17,20,"	 A PLACA NAO ESTA CADASTRADA!  ");
							printMensagemERRO(janelaprincipal,18,20,"       INSIRA UMA NOVA PLACA!      ");
							getchar();
						}

						// Se Busca status VEICULO == 0 o veiculo esta EXCLUIDO
						else if(resultadoBuscaStatusVEICULO == 0){
							printMensagemERRO(janelaprincipal,16,20,"               ERRO!              ");
							printMensagemERRO(janelaprincipal,17,20,"     O VEICULO ESTA EXCLUIDO!     ");
							printMensagemERRO(janelaprincipal,18,20,"  ACESSE O MENU LIXEIRA VEICULO   ");
							getchar();

						}

						// Se Busca LOCACAO != -10 o veiculo esta LOCADO
						else if(resultadoBuscaLOCACAO != -10){
							printMensagemERRO(janelaprincipal,16,20,"               ERRO!              ");
							printMensagemERRO(janelaprincipal,17,20,"    O VEICULO JA ESTA LOCADO!     ");
							printMensagemERRO(janelaprincipal,18,20,"  INSIRA UM VEICULO NAO LOCADO!   ");
							getchar();

						}

						// Se o resultado da Busca PLACA for != -10 continua o cadastro
						else if(resultadoBuscaLOCACAO == -10){

							// Pegando data do sistema
							datasistema(LOCACAO.datasaida);
							mvwprintw(janelaprincipal,10,34,"%s",LOCACAO.datasaida);

							// Lendo data de entrega prevista
							scanStringInteiroComESPACO(janelaprincipal,11,36,2,12,LOCACAO.dataentrega);

							// Lendo Dias Locados
							scanInteiro(janelaprincipal,12,33,2,5,&LOCACAO.diaslocados);

							// Lendo valor Diaria
							resultadoValorDiariaVEICULO = buscarValorDiariaVEICULO(resultadoBuscaPLACA);
							LOCACAO.valordiaria = resultadoValorDiariaVEICULO;
							mvwprintw(janelaprincipal,13,36,"%.2f",LOCACAO.valordiaria);

							// Lendo valor kilometragem inicial
							resultadoValorKmInicialVEICULO = buscarKmInicialVEICULO(resultadoBuscaPLACA);
							LOCACAO.kminicial = resultadoValorKmInicialVEICULO;
							mvwprintw(janelaprincipal,14,31,"%d",LOCACAO.kminicial);

							// Calculando valor total
							resultadoValorTotalLOCACAO = calculaValorTotalLOCACAO(LOCACAO.valordiaria, LOCACAO.diaslocados);
							LOCACAO.valortotal = resultadoValorTotalLOCACAO;
							printMensagemSUCESSONUMERO(janelaprincipal,17,39,LOCACAO.valortotal);

							// Gravar no arquivo DBLOCACAO.TXT
							DBLOCACAO = fopen("DBLOCACAO.TXT","a+");

							// Gravando dados VEICULO no disco
							fwrite(&LOCACAO,sizeof(LOCACAO), 1,DBLOCACAO);

							fclose(DBLOCACAO);
							// Imprimindo tecla para pressionar para continuar
							mvwprintw(janelaprincipal,20,18,"       LOCACAO EFETUADA COM SUCESSO!    ");
							// Imprimindo tecla para pressionar para continuar
							mvwprintw(janelaprincipal,21,18,"Pressione qualquer tecla para continuar!");

							// Atualizando janela
							wrefresh(janelaprincipal);

							// Esperando pressionar qualquer tecla
							getchar();
						}

						// Destruindo janela
						destruirJanela(janelaprincipal);
					}
					destruirJanela(janelaprincipal);
				}

				// ***************** DEVOLUCAO ******************
				if(opcao == 4){

					// Destroi a Janela
					destruirJanela(janelaprincipal);

					//Imprime tela de LOCACAO
					printTelaDEVOLUCAO(janelaprincipal);

					// Chamando Subrotina Verificar STRING PLACA
						scanStringInteiroSemESPACO(janelaprincipal,7,18,2,8,DEVOLUCAO.placa);

						// Chamando funcoes de BUSCA para verificacoes
						resultadoBuscaPLACA = buscarPLACA(DEVOLUCAO.placa);
						resultadoBuscaLOCACAO = buscarLOCACAO(DEVOLUCAO.placa);
						resultadoBuscaStatusVEICULO = buscarStatusVEICULO(resultadoBuscaPLACA);

						// Se campo placa for vazio
						if(strcmp(DEVOLUCAO.placa,"") == 0){
							printMensagemERRO(janelaprincipal,16,20,"               ERRO!               ");
							printMensagemERRO(janelaprincipal,17,20," O CAMPO PLACA NAO PODE SER VAZIO! ");
							printMensagemERRO(janelaprincipal,18,20,"       INSIRA UMA NOVA PLACA!      ");
							getchar();
						}

						// Se busca PLACA == -10 a placa NAO EXISTE no arquivo
						else if(resultadoBuscaPLACA == -10){
							printMensagemERRO(janelaprincipal,16,20,"                ERRO!              ");
							printMensagemERRO(janelaprincipal,17,20,"	 A PLACA NAO ESTA CADASTRADA!  ");
							printMensagemERRO(janelaprincipal,18,20,"       INSIRA UMA NOVA PLACA!      ");
							getchar();
						}

						// Se Busca status VEICULO == 0 o veiculo esta EXCLUIDO
						else if(resultadoBuscaStatusVEICULO == 0){
							printMensagemERRO(janelaprincipal,16,20,"               ERRO!              ");
							printMensagemERRO(janelaprincipal,17,20,"     O VEICULO ESTA EXCLUIDO!     ");
							printMensagemERRO(janelaprincipal,18,20,"  ACESSE O MENU LIXEIRA VEICULO   ");
							getchar();

						}

						// Se Busca LOCACAO != -10 o veiculo nao esta LOCADO
						else if(resultadoBuscaLOCACAO == -10){

							printMensagemERRO(janelaprincipal,16,20,"               ERRO!              ");
							printMensagemERRO(janelaprincipal,17,20,"    O VEICULO NAO ESTA LOCADO!    ");
							printMensagemERRO(janelaprincipal,18,20,"     INSIRA UM VEICULO LOCADO!    ");
							getchar();

						}

						// Se o resultado da Busca PLACA for != -10 continua o cadastro
						else if(resultadoBuscaLOCACAO != -10){

							// Zerando variaveis
							DEVOLUCAO.diaslocadosextras = 0;
							DEVOLUCAO.kmfinal = 0;
							DEVOLUCAO.kminicial = 0;
							DEVOLUCAO.kmlimite = 0;
							DEVOLUCAO.valormultakm = 0;
							DEVOLUCAO.totalanterior = 0;
							DEVOLUCAO.totalfinal = 0;

							// Printando dados da LOCACAO
							printDadosDEVOLUCAO(janelaprincipal,resultadoBuscaLOCACAO);

							// Lendo Dias Locados Extras
							scanInteiro(janelaprincipal,9,51,2,6,&DEVOLUCAO.diaslocadosextras);

							// Lendo Valor da multa por dia EXCEDIDO
							scanFloat(janelaprincipal,10,57,2,7,&DEVOLUCAO.valormultadia);

							// Buscando Valor do KM inicial do VEICULO
							resultadoValorKmInicialVEICULO = buscarKmInicialVEICULO(resultadoBuscaPLACA);
							DEVOLUCAO.kminicial = resultadoValorKmInicialVEICULO;

							// Lendo Dia de Devolucao
							scanInteiro(janelaprincipal,12,48,2,11,&DEVOLUCAO.kmfinal);

							// Atualizando Kilometragem VEICULO ARQUIVO
							updateKmVEICULO(resultadoBuscaPLACA,DEVOLUCAO.kmfinal);

							// Buscando Limite de KM por veiculo
							resultadoLimiteKmVEICULO = buscarLimiteKmVEICULO(resultadoBuscaPLACA);
							DEVOLUCAO.kmlimite = resultadoLimiteKmVEICULO;

							// Buscando valor MULTA por KM do veiculo
							resultadoValorMultaKmVEICULO = buscarMultaKmVEICULO(resultadoBuscaPLACA);
							DEVOLUCAO.valormultakm = resultadoValorMultaKmVEICULO;
							mvwprintw(janelaprincipal,13,56,"%.2f",DEVOLUCAO.valormultakm);

							// Buscando Saldo anterior TOTAL S/ correção
							resultadoBuscarValorTotalLOCACAO = buscarValorTotalLOCACAO(resultadoBuscaLOCACAO);
							DEVOLUCAO.totalanterior = resultadoBuscarValorTotalLOCACAO;

							// Calculando valor TOTAL
							resultadoBuscarValorTotalLOCACAO = calcularValorTotalDEVOLUCAO(DEVOLUCAO.totalanterior,DEVOLUCAO.diaslocadosextras,DEVOLUCAO.valormultadia,DEVOLUCAO.kminicial,DEVOLUCAO.kmfinal,DEVOLUCAO.kmlimite,DEVOLUCAO.valormultakm);
							DEVOLUCAO.totalfinal = resultadoBuscarValorTotalLOCACAO;
							mvwprintw(janelaprincipal,14,47,"%.2f",DEVOLUCAO.totalfinal);

							// Definindo arquivo fisico como leitura
							DBDEVOLUCAO = fopen("DBDEVOLUCAO.TXT","a+");

							// Condicional se o arquivo nao existir ele cria
							if(DBDEVOLUCAO == NULL){
								DBDEVOLUCAO = fopen("DBDEVOLUCAO.TXT","w");
							}

							// Gravando no arquivo
							fwrite(&DEVOLUCAO, sizeof(DEVOLUCAO), 1, DBDEVOLUCAO);

							fclose(DBDEVOLUCAO);

							// Removendo LOCACAO
							removerLOCACAO(janelaprincipal,resultadoBuscaLOCACAO);

							// Imprimindo tecla para pressionar para continuar
							mvwprintw(janelaprincipal,21,18,"Pressione qualquer tecla para continuar!");

							// Atualizando janela
							wrefresh(janelaprincipal);

							// Esperando pressionar qualquer tecla
							getchar();
							}
					// Destroi a Janela
					destruirJanela(janelaprincipal);

				}

				// ***************** RELATORIOS ******************
				if(opcao == 5){

				// Destroi a Janela Principal
					destruirJanela(janelaprincipal);

					// Atribuindo valor original do sombreamento
					sombreamento = 1;

					// Iniciando Cliclo do menu CRUD
					do{
						// Chamando a subrotina imprimir tela CRUD
						printMenuRELATORIOS(janelaprincipal,sombreamento);

						// Recebendo tecla pressionada
						tecla = wgetch(janelaprincipal);

						// Iniciando condicionais da tecla
						switch(tecla) {

							// Se pressionar UP (Cima)
							case KEY_UP:
								if(sombreamento == 1)
									sombreamento = 8;
									else
										sombreamento--;
							break;

							// Se pressionar DOWN(Baixo)
							case KEY_DOWN:
								if(sombreamento == 8)
									sombreamento = 1;
									else
										sombreamento++;
							break;

							// Se pressionar ENTER
							case 10:

							// Recebendo opcao escolhida atraves da contagem sombreamento
							opcao = sombreamento;

								// Se opcao escolhida for 1 CLIENTES EXCLUIDOS
								if( opcao == 1){
									destruirJanela(janelaprincipal);
									printTelaRelatorioClientesEXCLUIDOS(janelaprincipal);
									getchar();
									destruirJanela(janelaprincipal);
								}

								// Se opcao escolhida for 2 CLIENTES ATIVOS
								if( opcao == 2){
									destruirJanela(janelaprincipal);
									printTelaRelatorioClientesATIVOS(janelaprincipal);
									getchar();
									destruirJanela(janelaprincipal);
								}

								// Se opcao escolhida for 3 TODOS CLIENTES
								if( opcao == 3){
									destruirJanela(janelaprincipal);
									printTelaRelatorioClientes(janelaprincipal);
									getchar();
									destruirJanela(janelaprincipal);
								}


								// Se opcao escolhida for 4 VEICULOS EXCLUIDOS
								if( opcao == 4){
									destruirJanela(janelaprincipal);
									printTelaRelatorioVeiculosEXCLUIDOS(janelaprincipal);
									getchar();
									destruirJanela(janelaprincipal);

								}

								// Se opcao escolhida for 5 VEICULOS ATIVOS
								if( opcao == 5){
									destruirJanela(janelaprincipal);
									printTelaRelatorioVeiculosATIVOS(janelaprincipal);
									getchar();
									destruirJanela(janelaprincipal);

								}

								// Se opcao escolhida for 6 TODOS VEICULOS
								if( opcao == 6){
									destruirJanela(janelaprincipal);
									printTelaRelatorioVeiculos(janelaprincipal);
									getchar();
									destruirJanela(janelaprincipal);

								}

								// Se opcao escolhida for 7 VEICULOS EXCLUIDOS
								if( opcao == 7){
									destruirJanela(janelaprincipal);
									printTelaRelatorioLocados(janelaprincipal);
									getchar();
									destruirJanela(janelaprincipal);

								}

								// Se opcao escolhida for 8 "RETORNAR AO MENU PRINCIPAL"
								if ( opcao == 8){
									sombreamento = 1;
									destruirJanela(janelaprincipal);
									goto retornarMenuPrincipal;
								}
							break;
							}

					}while(1);

				}

				// ******************   SAIR   ******************
				if (opcao == 6){
					goto sairPrograma;
					}
			break;
		}

		// Goto para retornar ao MenuPrincipal
		retornarMenuPrincipal:
		refresh();
		endwin();

	}while(1);

    // Goto para SAIR do programa
		sairPrograma:
		refresh();
		endwin();
	}

	else{
	mvwprintw(janelalogin, 2, 3, "                          ");
	mvwprintw(janelalogin, 3, 3, "       ACESSO NEGADO!     ");
	mvwprintw(janelalogin, 4, 3, "                          ");
	wrefresh(janelalogin);
	getchar();
		refresh();
		endwin();
	}

return 0;
}