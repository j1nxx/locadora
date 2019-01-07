#include"locadora.h"

void destruirJanela(WINDOW *janela){
	wclear(janela);
	wrefresh(janela);
	endwin();
}

void printTelaLOGIN(WINDOW *janela){
	// Iniciando Ncurses
    initscr();

	init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_RED);
	init_pair(4,COLOR_WHITE,COLOR_GREEN);

	// Criando borda
	box(janela, ACS_VLINE, ACS_HLINE);
	wattron (janela, COLOR_PAIR(1));
	mvwprintw(janela, 2, 3, "                         ");
	mvwprintw(janela, 3, 3, "  FACA LOGIN NO SISTEMA  ");
	mvwprintw(janela, 4, 3, "                         ");
	wattron (janela, COLOR_PAIR(2));
	mvwprintw(janela, 6, 3, "LOGIN:");
	mvwprintw(janela, 7, 3, "SENHA:");

	wrefresh(janela);

}

void printMenuPrincipal(WINDOW *janela, int sombreamento){

	// Declarando variáveis
	int pos_linha = 7, pos_coluna = 35, contador;
    char *vOpcoes[6] = {
	"1. CLIENTE   ",
	"2. VEICULO   ",
	"3. LOCACAO   ",
	"4. DEVOLUCAO ",
	"5. RELATORIOS",
	"6. SAIR      ",
	};

    // Não ecoar na tela
    noecho();

	// Criando borda
	box(janela, ACS_VLINE, ACS_HLINE);

    //Ocultando cursor do MENU :D
    curs_set(0);

    // Definindo Pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

    // Setando Par 1 para o nome Menu Principal
    wattron (janela, COLOR_PAIR(1));
    mvwprintw(janela,3,25,"                                 ");
    mvwprintw(janela,4,25,"          MENU PRINCIPAL         ");
    mvwprintw(janela,5,25,"                                 ");

	// Setando Par 2 para as opções do Menu
	wattron (janela, COLOR_PAIR(2));

    // Iniciando cliclo for para imprimir vetor opcoes
    for(contador = 0; contador < 6; contador++){
          if(sombreamento == contador + 1)
            {
               wattron(janela,A_REVERSE);
               mvwprintw(janela,pos_linha,pos_coluna,"%s",vOpcoes[contador]);
               wattroff(janela,A_REVERSE);
             }
				else
					mvwprintw(janela,pos_linha,pos_coluna,"%s",vOpcoes[contador]);
					pos_linha++;
        }
        wrefresh(janela);
}

void printMenuCLIENTECRUD(WINDOW *janela, int sombreamento){
	// Declarando variáveis
	int pos_linha = 7, pos_coluna = 35, contador;
    char *vOpcoes[6] = {
	"1. CADASTRAR      ",
	"2. PESQUISAR      ",
	"3. EXCLUIR        ",
	"4. EDITAR         ",
	"5. LIXEIRA        ",
	"6. VOLTAR AO MENU ",
	};

    // Não ecoar na tela
    noecho();

     //Ocultando cursor do MENU :D
    curs_set(0);

	// Criando borda
	box(janela, ACS_VLINE, ACS_HLINE);

    //Ocultando cursor do MENU :D
    curs_set(0);

    // Definindo Pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

    // Setando Par 1 para o nome Menu Principal
    wattron (janela, COLOR_PAIR(1));
    mvwprintw(janela,3,25,"                                 ");
    mvwprintw(janela,4,25,"          MENU CLIENTE           ");
    mvwprintw(janela,5,25,"                                 ");

	// Setando Par 2 para as opções do Menu
	wattron (janela, COLOR_PAIR(2));

    // Iniciando cliclo for para imprimir vetor opcoes
    for(contador = 0; contador < 6; contador++){
          if(sombreamento == contador + 1)
            {
               wattron(janela,A_REVERSE);
               mvwprintw(janela,pos_linha,pos_coluna,"%s",vOpcoes[contador]);
               wattroff(janela,A_REVERSE);
             }
				else
					mvwprintw(janela,pos_linha,pos_coluna,"%s",vOpcoes[contador]);
					pos_linha++;
        }
        wrefresh(janela);
}

void printMenuCLIENTELIXEIRA(WINDOW *janela, int sombreamento){
	// Declarando variáveis
	int pos_linha = 7, pos_coluna = 30, contador;
    char *vOpcoes[4] = {
	"1. EXIBIR LIXEIRA        ",
	"2. RESTAURAR CLIENTE     ",
	"3. ESVAZIAR LIXEIRA      ",
	"4. VOLTAR AO MENU CLIENTE",
	};

    // Não ecoar na tela
    noecho();

     //Ocultando cursor do MENU :D
    curs_set(0);

	// Criando borda
	box(janela, ACS_VLINE, ACS_HLINE);

    //Ocultando cursor do MENU :D
    curs_set(0);

    // Definindo Pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

    // Setando Par 1 para o nome Menu Principal
    wattron (janela, COLOR_PAIR(1));
    mvwprintw(janela,3,25,"                                 ");
    mvwprintw(janela,4,25,"          MENU LIXEIRA           ");
    mvwprintw(janela,5,25,"                                 ");

	// Setando Par 2 para as opções do Menu
	wattron (janela, COLOR_PAIR(2));

    // Iniciando cliclo for para imprimir vetor opcoes
    for(contador = 0; contador < 4; contador++){
          if(sombreamento == contador + 1)
            {
               wattron(janela,A_REVERSE);
               mvwprintw(janela,pos_linha,pos_coluna,"%s",vOpcoes[contador]);
               wattroff(janela,A_REVERSE);
             }
				else
					mvwprintw(janela,pos_linha,pos_coluna,"%s",vOpcoes[contador]);
					pos_linha++;
        }
        wrefresh(janela);
}

void printMenuVEICULOCRUD(WINDOW *janela, int sombreamento){
	// Declarando variáveis
	int pos_linha = 7, pos_coluna = 35, contador;
    char *vOpcoes[6] = {
	"1. CADASTRAR      ",
	"2. PESQUISAR      ",
	"3. EXCLUIR        ",
	"4. EDITAR         ",
	"5. LIXEIRA        ",
	"6. VOLTAR AO MENU ",
	};

    // Não ecoar na tela
    noecho();

     //Ocultando cursor do MENU :D
    curs_set(0);

	// Criando borda
	box(janela, ACS_VLINE, ACS_HLINE);

    //Ocultando cursor do MENU :D
    curs_set(0);

    // Definindo Pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

    // Setando Par 1 para o nome Menu Principal
    wattron (janela, COLOR_PAIR(1));
    mvwprintw(janela,3,25,"                                 ");
    mvwprintw(janela,4,25,"          MENU VEICULO           ");
    mvwprintw(janela,5,25,"                                 ");

	// Setando Par 2 para as opções do Menu
	wattron (janela, COLOR_PAIR(2));

    // Iniciando cliclo for para imprimir vetor opcoes
    for(contador = 0; contador < 6; contador++){
          if(sombreamento == contador + 1)
            {
               wattron(janela,A_REVERSE);
               mvwprintw(janela,pos_linha,pos_coluna,"%s",vOpcoes[contador]);
               wattroff(janela,A_REVERSE);
             }
				else
					mvwprintw(janela,pos_linha,pos_coluna,"%s",vOpcoes[contador]);
					pos_linha++;
        }
        wrefresh(janela);
}

void printMenuRELATORIOS(WINDOW *janela, int sombreamento){
	// Declarando variáveis
	int pos_linha = 7, pos_coluna = 30, contador;
    char *vOpcoes[10] = {
	"1. CLIENTES EXCLUIDOS  ",
	"2. CLIENTES ATIVOS     ",
	"3. CLIENTES CADASTRADOS",
	"4. VEICULOS EXCLUIDOS  ",
	"5. VEICULOS ATIVOS     ",
	"6. VEICULOS CADASTRADOS",
	"7. VEICULOS LOCADOS    ",
	"8. VOLTAR AO MENU      ",
	};

    // Não ecoar na tela
    noecho();

     //Ocultando cursor do MENU :D
    curs_set(0);

	// Criando borda
	box(janela, ACS_VLINE, ACS_HLINE);

    //Ocultando cursor do MENU :D
    curs_set(0);

    // Definindo Pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

    // Setando Par 1 para o nome Menu Principal
    wattron (janela, COLOR_PAIR(1));
    mvwprintw(janela,3,25,"                                 ");
    mvwprintw(janela,4,25,"        MENU RELATORIOS          ");
    mvwprintw(janela,5,25,"                                 ");

	// Setando Par 2 para as opções do Menu
	wattron (janela, COLOR_PAIR(2));

    // Iniciando cliclo for para imprimir vetor opcoes
    for(contador = 0; contador < 8; contador++){
          if(sombreamento == contador + 1)
            {
               wattron(janela,A_REVERSE);
               mvwprintw(janela,pos_linha,pos_coluna,"%s",vOpcoes[contador]);
               wattroff(janela,A_REVERSE);
             }
				else
					mvwprintw(janela,pos_linha,pos_coluna,"%s",vOpcoes[contador]);
					pos_linha++;
        }
        wrefresh(janela);
}

void printTelaCadastrarCLIENTE(WINDOW *janela){

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,3,20,"                                   ");
    mvwprintw(janela,4,20,"           CADASTRAR CLIENTE       ");
    mvwprintw(janela,5,20,"                                   ");

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
    mvwprintw(janela,7,20,"Nome:______________________________");
    mvwprintw(janela,8,20,"CPF:_______________________________");
    mvwprintw(janela,9,20,"Telefone:__________________________");
		mvwprintw(janela,10,20,"Rua:_______________________________");
		mvwprintw(janela,11,20,"Numero:___________________________");
		mvwprintw(janela,12,20,"Bairro:___________________________");
		mvwprintw(janela,13,20,"CEP:______________________________");
		mvwprintw(janela,14,20,"Cidade:___________________________");

	// Atualizando Tela
	wrefresh(janela);
}

void printTelaPesquisarCLIENTE(WINDOW *janela){

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,3,20,"                                   ");
    mvwprintw(janela,4,20,"           PESQUISAR CLIENTE       ");
    mvwprintw(janela,5,20,"                                   ");

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
	mvwprintw(janela,7,20, "INSIRA O CPF:___________");
    mvwprintw(janela,9,20, "Nome:");
    mvwprintw(janela,10,20,"CPF:");
    mvwprintw(janela,11,20,"Telefone:");

	// Atualizando Tela
	wrefresh(janela);
}

void printTelaExcluirCLIENTE(WINDOW *janela){

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,3,20,"                                   ");
    mvwprintw(janela,4,20,"           EXCLUIR CLIENTE         ");
    mvwprintw(janela,5,20,"                                   ");

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
	mvwprintw(janela,7,20, "INSIRA O CPF:___________");
    mvwprintw(janela,9,20, "Nome:");
    mvwprintw(janela,10,20,"CPF:");
    mvwprintw(janela,11,20,"Telefone:");

	// Atualizando Tela
	wrefresh(janela);
}

void printTelaEditarCLIENTE(WINDOW *janela){

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,3,20,"                                   ");
    mvwprintw(janela,4,20,"           EDITAR CLIENTE	       ");
    mvwprintw(janela,5,20,"                                   ");

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
	mvwprintw(janela,7,20, "INSIRA O CPF:___________");
    mvwprintw(janela,9,20, "Nome:");
    mvwprintw(janela,10,20,"CPF:");
    mvwprintw(janela,11,20,"Telefone:");
    wattron (janela, COLOR_PAIR(1));
    mvwprintw(janela,13,20,"                                   ");
    mvwprintw(janela,14,20,"       INSIRA OS NOVOS DADOS       ");
    mvwprintw(janela,15,20,"                                   ");
	wattron (janela, COLOR_PAIR(2));
    mvwprintw(janela,16,20,"Nome:______________________________");
    mvwprintw(janela,17,20,"CPF:_______________________________");
    mvwprintw(janela,18,20,"Telefone:__________________________");

	// Atualizando Tela
	wrefresh(janela);
}

void printTelaLixeiraRESTAURARCLIENTE(WINDOW *janela){

    // Destruindo janela
    destruirJanela(janela);

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,1,2,"                                                                        ");
    mvwprintw(janela,2,2,"                              CLIENTES LIXEIRA                          ");
	mvwprintw(janela,3,2,"                                                                        ");
	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
	mvwprintw(janela,7,20, "DIGITE O CPF A RESTAURAR:___________");

    mvwprintw(janela,9,20, "Nome:");
    mvwprintw(janela,10,20,"CPF:");
    mvwprintw(janela,11,20,"Telefone:");

	// Atualizando Tela
	wrefresh(janela);
}

void printTelaLixeiraESVAZIARCLIENTE(WINDOW *janela){

    // Destruindo janela
    destruirJanela(janela);

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_RED);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,1,2,"                                                                        ");
    mvwprintw(janela,2,2,"                              CLIENTES LIXEIRA                          ");
    mvwprintw(janela,4,2,"                                                                        ");
    // Alterando par de cor
	wattron (janela, COLOR_PAIR(3));
	mvwprintw(janela,4,2,"                    CUIDADO! A EXCLUSAO SERA DEFINITIVA!                ");
	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
	mvwprintw(janela,7,20, "DIGITE O CPF A EXCLUIR:___________");
    mvwprintw(janela,9,20, "Nome:");
    mvwprintw(janela,10,20,"CPF:");
    mvwprintw(janela,11,20,"Telefone:");

	// Atualizando Tela
	wrefresh(janela);
}

void printTelaRelatorioClientesEXCLUIDOS(WINDOW *janela){

    int contlinha = 4;
    int contagemexibicao = 1;
    int numeracao = 1;
    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Definindo variaveis
	STR_CLIENTE REG;

	// Definindo arquivo logico
	FILE *DBCLIENTE;

	// Definindo arquivo fisico como leitura
	DBCLIENTE = fopen("DBCLIENTE.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBCLIENTE == NULL){

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tCLIENTES LIXEIRA                         ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));

		mvwprintw(janela,3,2,"NUMERO");
		mvwprintw(janela,3,10,"NOME");
		mvwprintw(janela,3,42,"CPF");
		mvwprintw(janela,3,55,"TELEFONE");

		DBCLIENTE = fopen("DBCLIENTE.TXT","w");
	}

	else{

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tCLIENTES LIXEIRA                         ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));
		mvwprintw(janela,3,2,"NUMERO");
		mvwprintw(janela,3,10,"NOME");
		mvwprintw(janela,3,42,"CPF");
		mvwprintw(janela,3,55,"TELEFONE");

		// Lendo arquivos do DBCLIENTE
		fread(&REG,sizeof(REG),1,DBCLIENTE);

		// Iniciando condicionais
		while(!feof(DBCLIENTE)){

			if(REG.status == 0){

				if(contagemexibicao <=	15){
					mvwprintw(janela,contlinha,2,"%d",numeracao);
					mvwprintw(janela,contlinha,10,"%s",REG.nome);
					mvwprintw(janela,contlinha,42,"%s",REG.cpf);
					mvwprintw(janela,contlinha,55,"%ld",REG.tel);

					wrefresh(janela);
					contlinha++;
					contagemexibicao++;
					numeracao++;
				}

				else if(contagemexibicao == 16){

				mvwprintw(janela,21,9,"Pressione qualquer tecla para continuar o relatorio");
				wrefresh(janela);
				getchar();

				destruirJanela(janela);

				contlinha = 4;
				contagemexibicao = 1;

				// Criando borda da janela
				box(janela, ACS_VLINE, ACS_HLINE);

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(1));

				// Printando tela
				mvwprintw(janela,1,2,"\t\t\t\tCLIENTES LIXEIRA                         ");

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(2));

				mvwprintw(janela,3,2,"NUMERO");
				mvwprintw(janela,3,10,"NOME");
				mvwprintw(janela,3,42,"CPF");
				mvwprintw(janela,3,55,"TELEFONE");


				mvwprintw(janela,contlinha,2,"%d",numeracao);
				mvwprintw(janela,contlinha,10,"%s",REG.nome);
				mvwprintw(janela,contlinha,42,"%s",REG.cpf);
				mvwprintw(janela,contlinha,55,"%ld",REG.tel);

				wrefresh(janela);
				contlinha++;
				contagemexibicao++;
				numeracao++;
				}

			}
		fread(&REG,sizeof(REG),1,DBCLIENTE);
		}
	}

	// Fechando o arquivo
	fclose(DBCLIENTE);

	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	// Atualizando Tela
	wrefresh(janela);
}

void printTelaRelatorioClientesATIVOS(WINDOW *janela){

    int contlinha = 4;
    int contagemexibicao = 1;
    int numeracao = 1;
    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Definindo variaveis
	STR_CLIENTE REG;

	// Definindo arquivo logico
	FILE *DBCLIENTE;

	// Definindo arquivo fisico como leitura
	DBCLIENTE = fopen("DBCLIENTE.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBCLIENTE == NULL){

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tCLIENTES ATIVOS                          ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));

		mvwprintw(janela,3,2,"NUMERO");
		mvwprintw(janela,3,10,"NOME");
		mvwprintw(janela,3,42,"CPF");
		mvwprintw(janela,3,55,"TELEFONE");

		DBCLIENTE = fopen("DBCLIENTE.TXT","w");
	}

	else{

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tCLIENTES ATIVOS                          ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));
		mvwprintw(janela,3,2,"NUMERO");
		mvwprintw(janela,3,10,"NOME");
		mvwprintw(janela,3,42,"CPF");
		mvwprintw(janela,3,55,"TELEFONE");

		// Lendo arquivos do DBCLIENTE
		fread(&REG,sizeof(REG),1,DBCLIENTE);

		// Iniciando condicionais
		while(!feof(DBCLIENTE)){

			if(REG.status == 1){

				if(contagemexibicao <=	15){
					mvwprintw(janela,contlinha,2,"%d",numeracao);
					mvwprintw(janela,contlinha,10,"%s",REG.nome);
					mvwprintw(janela,contlinha,42,"%s",REG.cpf);
					mvwprintw(janela,contlinha,55,"%ld",REG.tel);

					wrefresh(janela);
					contlinha++;
					contagemexibicao++;
					numeracao++;
				}

				else if(contagemexibicao == 16){

				mvwprintw(janela,21,9,"Pressione qualquer tecla para continuar o relatorio");
				wrefresh(janela);
				getchar();

				destruirJanela(janela);

				contlinha = 4;
				contagemexibicao = 1;

				// Criando borda da janela
				box(janela, ACS_VLINE, ACS_HLINE);

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(1));

				// Printando tela
				mvwprintw(janela,1,2,"\t\t\t\tCLIENTES ATIVOS                          ");

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(2));

				mvwprintw(janela,3,2,"NUMERO");
				mvwprintw(janela,3,10,"NOME");
				mvwprintw(janela,3,42,"CPF");
				mvwprintw(janela,3,55,"TELEFONE");


				mvwprintw(janela,contlinha,2,"%d",numeracao);
				mvwprintw(janela,contlinha,10,"%s",REG.nome);
				mvwprintw(janela,contlinha,42,"%s",REG.cpf);
				mvwprintw(janela,contlinha,55,"%ld",REG.tel);

				wrefresh(janela);
				contlinha++;
				contagemexibicao++;
				numeracao++;
				}

			}
		fread(&REG,sizeof(REG),1,DBCLIENTE);
		}
	}

	// Fechando o arquivo
	fclose(DBCLIENTE);

	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	// Atualizando Tela
	wrefresh(janela);
}

void printTelaRelatorioClientes(WINDOW *janela){

    int contlinha = 4;
    int contagemexibicao = 1;
    int numeracao = 1;
    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Definindo variaveis
	STR_CLIENTE REG;

	// Definindo arquivo logico
	FILE *DBCLIENTE;

	// Definindo arquivo fisico como leitura
	DBCLIENTE = fopen("DBCLIENTE.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBCLIENTE == NULL){

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tCLIENTES CADASTRADOS                      ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));

		mvwprintw(janela,3,2,"NUMERO");
		mvwprintw(janela,3,10,"NOME");
		mvwprintw(janela,3,42,"CPF");
		mvwprintw(janela,3,55,"TELEFONE");

		DBCLIENTE = fopen("DBCLIENTE.TXT","w");
	}

	else{

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tCLIENTES CADASTRADOS                      ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));
		mvwprintw(janela,3,2,"NUMERO");
		mvwprintw(janela,3,10,"NOME");
		mvwprintw(janela,3,42,"CPF");
		mvwprintw(janela,3,55,"TELEFONE");

		// Lendo arquivos do DBCLIENTE
		fread(&REG,sizeof(REG),1,DBCLIENTE);

		// Iniciando condicionais
		while(!feof(DBCLIENTE)){

			if(REG.status == 1 || REG.status == 0){

				if(contagemexibicao <=	15){
					mvwprintw(janela,contlinha,2,"%d",numeracao);
					mvwprintw(janela,contlinha,10,"%s",REG.nome);
					mvwprintw(janela,contlinha,42,"%s",REG.cpf);
					mvwprintw(janela,contlinha,55,"%ld",REG.tel);

					wrefresh(janela);
					contlinha++;
					contagemexibicao++;
					numeracao++;
				}

				else if(contagemexibicao == 16){

				mvwprintw(janela,21,9,"Pressione qualquer tecla para continuar o relatorio");
				wrefresh(janela);
				getchar();

				destruirJanela(janela);

				contlinha = 4;
				contagemexibicao = 1;

				// Criando borda da janela
				box(janela, ACS_VLINE, ACS_HLINE);

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(1));

				// Printando tela
				mvwprintw(janela,1,2,"\t\t\t\tCLIENTES CADASTRADOS                      ");

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(2));

				mvwprintw(janela,3,2,"NUMERO");
				mvwprintw(janela,3,10,"NOME");
				mvwprintw(janela,3,42,"CPF");
				mvwprintw(janela,3,55,"TELEFONE");


				mvwprintw(janela,contlinha,2,"%d",numeracao);
				mvwprintw(janela,contlinha,10,"%s",REG.nome);
				mvwprintw(janela,contlinha,42,"%s",REG.cpf);
				mvwprintw(janela,contlinha,55,"%ld",REG.tel);

				wrefresh(janela);
				contlinha++;
				contagemexibicao++;
				numeracao++;
				}

			}
		fread(&REG,sizeof(REG),1,DBCLIENTE);
		}
	}

	// Fechando o arquivo
	fclose(DBCLIENTE);

	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	// Atualizando Tela
	wrefresh(janela);
}

void printTelaRelatorioVeiculosEXCLUIDOS(WINDOW *janela){

    int contlinha = 4;
    int contagemexibicao = 1;
    int numeracao = 1;
    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tVEICULOS LIXEIRA                         ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));
		// PRINTANDO
		mvwprintw(janela,3,1, "NUM");
		mvwprintw(janela,3,6, "PLACA");
		mvwprintw(janela,3,14,"MODELO");
		mvwprintw(janela,3,30,"MARCA");
		mvwprintw(janela,3,41,"ANO");
		mvwprintw(janela,3,48,"KILOMETRAGEM");
		mvwprintw(janela,3,62,"DIARIA R$");

		DBVEICULO = fopen("DBCLIENTE.TXT","w");
	}

	else{

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tVEICULOS LIXEIRA                         ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));

		// PRINTANDO
		mvwprintw(janela,3,1, "NUM");
		mvwprintw(janela,3,6, "PLACA");
		mvwprintw(janela,3,14,"MODELO");
		mvwprintw(janela,3,30,"MARCA");
		mvwprintw(janela,3,41,"ANO");
		mvwprintw(janela,3,48,"KILOMETRAGEM");
		mvwprintw(janela,3,62,"DIARIA R$");

		// Lendo arquivos do DBCLIENTE
		fread(&REG,sizeof(REG),1,DBVEICULO);

		// Iniciando condicionais
		while(!feof(DBVEICULO)){

			if(REG.status == 0){
				if(contagemexibicao <=	15){
					mvwprintw(janela,contlinha,1,"%d",numeracao);
					mvwprintw(janela,contlinha,6,"%s",REG.placa);
					mvwprintw(janela,contlinha,14,"%s",REG.modelo);
					mvwprintw(janela,contlinha,30,"%s",REG.marca);
					mvwprintw(janela,contlinha,41,"%d",REG.ano);
					mvwprintw(janela,contlinha,48,"%d",REG.km);
					mvwprintw(janela,contlinha,62,"%.2f",REG.diaria);

					wrefresh(janela);
					contlinha++;
					contagemexibicao++;
					numeracao++;
				}

				else if(contagemexibicao == 16){

				mvwprintw(janela,21,9,"Pressione qualquer tecla para continuar o relatorio");
				wrefresh(janela);
				getchar();

				destruirJanela(janela);

				contlinha = 4;
				contagemexibicao = 1;

				// Criando borda da janela
				box(janela, ACS_VLINE, ACS_HLINE);

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(1));

				// Printando tela
				mvwprintw(janela,1,2,"\t\t\t\tCLIENTES VEICULO                        ");

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(2));

				// PRINTANDO
				mvwprintw(janela,3,1, "NUM");
				mvwprintw(janela,3,6, "PLACA");
				mvwprintw(janela,3,14,"MODELO");
				mvwprintw(janela,3,30,"MARCA");
				mvwprintw(janela,3,41,"ANO");
				mvwprintw(janela,3,48,"KILOMETRAGEM");
				mvwprintw(janela,3,62,"DIARIA R$");;

				mvwprintw(janela,contlinha,1,"%d",numeracao);
				mvwprintw(janela,contlinha,6,"%s",REG.placa);
				mvwprintw(janela,contlinha,14,"%s",REG.modelo);
				mvwprintw(janela,contlinha,30,"%s",REG.marca);
				mvwprintw(janela,contlinha,41,"%d",REG.ano);
				mvwprintw(janela,contlinha,48,"%d",REG.km);
				mvwprintw(janela,contlinha,62,"%.2f",REG.diaria);

				wrefresh(janela);
				contlinha++;
				contagemexibicao++;
				numeracao++;
				}

			}
		fread(&REG,sizeof(REG),1,DBVEICULO);
		}
	}

	// Fechando o arquivo
	fclose(DBVEICULO);

	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	// Atualizando Tela
	wrefresh(janela);
}

void printTelaRelatorioVeiculosATIVOS(WINDOW *janela){

    int contlinha = 4;
    int contagemexibicao = 1;
    int numeracao = 1;
    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tVEICULOS ATIVOS                         ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));
		// PRINTANDO
		mvwprintw(janela,3,1, "NUM");
		mvwprintw(janela,3,6, "PLACA");
		mvwprintw(janela,3,14,"MODELO");
		mvwprintw(janela,3,30,"MARCA");
		mvwprintw(janela,3,41,"ANO");
		mvwprintw(janela,3,48,"KILOMETRAGEM");
		mvwprintw(janela,3,62,"DIARIA R$");

		DBVEICULO = fopen("DBCLIENTE.TXT","w");
	}

	else{

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tVEICULOS ATIVOS                         ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));

		// PRINTANDO
		mvwprintw(janela,3,1, "NUM");
		mvwprintw(janela,3,6, "PLACA");
		mvwprintw(janela,3,14,"MODELO");
		mvwprintw(janela,3,30,"MARCA");
		mvwprintw(janela,3,41,"ANO");
		mvwprintw(janela,3,48,"KILOMETRAGEM");
		mvwprintw(janela,3,62,"DIARIA R$");

		// Lendo arquivos do DBCLIENTE
		fread(&REG,sizeof(REG),1,DBVEICULO);

		// Iniciando condicionais
		while(!feof(DBVEICULO)){

			if(REG.status == 1){
				if(contagemexibicao <=	15){
					mvwprintw(janela,contlinha,1,"%d",numeracao);
					mvwprintw(janela,contlinha,6,"%s",REG.placa);
					mvwprintw(janela,contlinha,14,"%s",REG.modelo);
					mvwprintw(janela,contlinha,30,"%s",REG.marca);
					mvwprintw(janela,contlinha,41,"%d",REG.ano);
					mvwprintw(janela,contlinha,48,"%d",REG.km);
					mvwprintw(janela,contlinha,62,"%.2f",REG.diaria);

					wrefresh(janela);
					contlinha++;
					contagemexibicao++;
					numeracao++;
				}

				else if(contagemexibicao == 16){

				mvwprintw(janela,21,9,"Pressione qualquer tecla para continuar o relatorio");
				wrefresh(janela);
				getchar();

				destruirJanela(janela);

				contlinha = 4;
				contagemexibicao = 1;

				// Criando borda da janela
				box(janela, ACS_VLINE, ACS_HLINE);

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(1));

				// Printando tela
				mvwprintw(janela,1,2,"\t\t\t\tVEICULOS ATIVOS                         ");

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(2));

				// PRINTANDO
				mvwprintw(janela,3,1, "NUM");
				mvwprintw(janela,3,6, "PLACA");
				mvwprintw(janela,3,14,"MODELO");
				mvwprintw(janela,3,30,"MARCA");
				mvwprintw(janela,3,41,"ANO");
				mvwprintw(janela,3,48,"KILOMETRAGEM");
				mvwprintw(janela,3,62,"DIARIA R$");;

				mvwprintw(janela,contlinha,1,"%d",numeracao);
				mvwprintw(janela,contlinha,6,"%s",REG.placa);
				mvwprintw(janela,contlinha,14,"%s",REG.modelo);
				mvwprintw(janela,contlinha,30,"%s",REG.marca);
				mvwprintw(janela,contlinha,41,"%d",REG.ano);
				mvwprintw(janela,contlinha,48,"%d",REG.km);
				mvwprintw(janela,contlinha,62,"%.2f",REG.diaria);

				wrefresh(janela);
				contlinha++;
				contagemexibicao++;
				numeracao++;
				}

			}
		fread(&REG,sizeof(REG),1,DBVEICULO);
		}
	}

	// Fechando o arquivo
	fclose(DBVEICULO);

	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	// Atualizando Tela
	wrefresh(janela);
}

void printTelaRelatorioVeiculos(WINDOW *janela){

    int contlinha = 4;
    int contagemexibicao = 1;
    int numeracao = 1;
    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Definindo variaveis
	STR_VEICULO REG;

	// Definindo arquivo logico
	FILE *DBVEICULO;

	// Definindo arquivo fisico como leitura
	DBVEICULO = fopen("DBVEICULO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBVEICULO == NULL){

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tVEICULOS CADASTRADOS                     ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));
		// PRINTANDO
		mvwprintw(janela,3,1, "NUM");
		mvwprintw(janela,3,6, "PLACA");
		mvwprintw(janela,3,14,"MODELO");
		mvwprintw(janela,3,30,"MARCA");
		mvwprintw(janela,3,41,"ANO");
		mvwprintw(janela,3,48,"KILOMETRAGEM");
		mvwprintw(janela,3,62,"DIARIA R$");

		DBVEICULO = fopen("DBCLIENTE.TXT","w");
	}

	else{

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tVEICULOS CADASTRADOS                     ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));

		// PRINTANDO
		mvwprintw(janela,3,1, "NUM");
		mvwprintw(janela,3,6, "PLACA");
		mvwprintw(janela,3,14,"MODELO");
		mvwprintw(janela,3,30,"MARCA");
		mvwprintw(janela,3,41,"ANO");
		mvwprintw(janela,3,48,"KILOMETRAGEM");
		mvwprintw(janela,3,62,"DIARIA R$");

		// Lendo arquivos do DBCLIENTE
		fread(&REG,sizeof(REG),1,DBVEICULO);

		// Iniciando condicionais
		while(!feof(DBVEICULO)){

			if(REG.status == 1 || REG.status == 0){
				if(contagemexibicao <=	15){
					mvwprintw(janela,contlinha,1,"%d",numeracao);
					mvwprintw(janela,contlinha,6,"%s",REG.placa);
					mvwprintw(janela,contlinha,14,"%s",REG.modelo);
					mvwprintw(janela,contlinha,30,"%s",REG.marca);
					mvwprintw(janela,contlinha,41,"%d",REG.ano);
					mvwprintw(janela,contlinha,48,"%d",REG.km);
					mvwprintw(janela,contlinha,62,"%.2f",REG.diaria);

					wrefresh(janela);
					contlinha++;
					contagemexibicao++;
					numeracao++;
				}

				else if(contagemexibicao == 16){

				mvwprintw(janela,21,9,"Pressione qualquer tecla para continuar o relatorio");
				wrefresh(janela);
				getchar();

				destruirJanela(janela);

				contlinha = 4;
				contagemexibicao = 1;

				// Criando borda da janela
				box(janela, ACS_VLINE, ACS_HLINE);

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(1));

				// Printando tela
				mvwprintw(janela,1,2,"\t\t\t\tVEICULOS CADASTRADOS                     ");

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(2));

				// PRINTANDO
				mvwprintw(janela,3,1, "NUM");
				mvwprintw(janela,3,6, "PLACA");
				mvwprintw(janela,3,14,"MODELO");
				mvwprintw(janela,3,30,"MARCA");
				mvwprintw(janela,3,41,"ANO");
				mvwprintw(janela,3,48,"KILOMETRAGEM");
				mvwprintw(janela,3,62,"DIARIA R$");;

				mvwprintw(janela,contlinha,1,"%d",numeracao);
				mvwprintw(janela,contlinha,6,"%s",REG.placa);
				mvwprintw(janela,contlinha,14,"%s",REG.modelo);
				mvwprintw(janela,contlinha,30,"%s",REG.marca);
				mvwprintw(janela,contlinha,41,"%d",REG.ano);
				mvwprintw(janela,contlinha,48,"%d",REG.km);
				mvwprintw(janela,contlinha,62,"%.2f",REG.diaria);

				wrefresh(janela);
				contlinha++;
				contagemexibicao++;
				numeracao++;
				}

			}
		fread(&REG,sizeof(REG),1,DBVEICULO);
		}
	}

	// Fechando o arquivo
	fclose(DBVEICULO);

	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	// Atualizando Tela
	wrefresh(janela);
}

void printTelaRelatorioLocados(WINDOW *janela){

    int contlinha = 4;
    int contagemexibicao = 1;
    int numeracao = 1;

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Definindo variaveis
	STR_LOCACAO REG;

	// Definindo arquivo logico
	FILE *DBLOCACAO;

	// Definindo arquivo fisico como leitura
	DBLOCACAO = fopen("DBLOCACAO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBLOCACAO == NULL){

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tVEICULOS LOCADOS                     ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));

		// PRINTANDO
		mvwprintw(janela,3,1, "NUM");
		mvwprintw(janela,3,6, "PLACA");
		mvwprintw(janela,3,15,"CPF");
		mvwprintw(janela,3,27,"DATALOCACAO");
		mvwprintw(janela,3,40,"DATAENTREGA");
		mvwprintw(janela,3,54,"QNTDIAS");
		mvwprintw(janela,3,66,"TOTAL R$");

		DBLOCACAO = fopen("DBLOCACAO.TXT","w");
	}

	else{

		// Criando borda da janela
		box(janela, ACS_VLINE, ACS_HLINE);

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(1));

		// Printando tela
		mvwprintw(janela,1,2,"\t\t\t\tVEICULOS LOCADOS                          ");

		// Alterando par de cor
		wattron (janela, COLOR_PAIR(2));

		// PRINTANDO
		mvwprintw(janela,3,1, "NUM");
		mvwprintw(janela,3,6, "PLACA");
		mvwprintw(janela,3,15,"CPF");
		mvwprintw(janela,3,27,"DATALOCACAO");
		mvwprintw(janela,3,40,"DATAENTREGA");
		mvwprintw(janela,3,54,"QNTDIAS");
		mvwprintw(janela,3,66,"TOTAL R$");

		// Lendo arquivos do DBCLIENTE
		fread(&REG,sizeof(REG),1,DBLOCACAO);

		// Iniciando condicionais
		while(!feof(DBLOCACAO)){

				if(contagemexibicao <=	15){
				mvwprintw(janela,contlinha,1,"%d",numeracao);
				mvwprintw(janela,contlinha,6,"%s",REG.placa);
				mvwprintw(janela,contlinha,15,"%s",REG.cpf);
				mvwprintw(janela,contlinha,26,"%s",REG.datasaida);
				mvwprintw(janela,contlinha,40,"%s",REG.dataentrega);
				mvwprintw(janela,contlinha,54,"%d",REG.diaslocados);
				mvwprintw(janela,contlinha,66,"%.2f",REG.valortotal);

					wrefresh(janela);
					contlinha++;
					contagemexibicao++;
					numeracao++;
				}

				else if(contagemexibicao == 16){

				mvwprintw(janela,21,9,"Pressione qualquer tecla para continuar o relatorio");
				wrefresh(janela);
				getchar();

				destruirJanela(janela);

				contlinha = 4;
				contagemexibicao = 1;

				// Criando borda da janela
				box(janela, ACS_VLINE, ACS_HLINE);

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(1));

				// Printando tela
				mvwprintw(janela,1,2,"\t\t\t\tVEICULOS LOCADOS                     ");

				// Alterando par de cor
				wattron (janela, COLOR_PAIR(2));

				// PRINTANDO
				mvwprintw(janela,3,1, "NUM");
				mvwprintw(janela,3,6, "PLACA");
				mvwprintw(janela,3,15,"CPF");
				mvwprintw(janela,3,27,"DATALOCACAO");
				mvwprintw(janela,3,40,"DATAENTREGA");
				mvwprintw(janela,3,54,"QNTDIAS");
				mvwprintw(janela,3,66,"TOTAL R$");

				mvwprintw(janela,contlinha,1,"%d",numeracao);
				mvwprintw(janela,contlinha,6,"%s",REG.placa);
				mvwprintw(janela,contlinha,15,"%s",REG.cpf);
				mvwprintw(janela,contlinha,26,"%s",REG.datasaida);
				mvwprintw(janela,contlinha,40,"%s",REG.dataentrega);
				mvwprintw(janela,contlinha,54,"%d",REG.diaslocados);
				mvwprintw(janela,contlinha,66,"%.2f",REG.valortotal);

				wrefresh(janela);
				contlinha++;
				contagemexibicao++;
				numeracao++;
				}

			fread(&REG,sizeof(REG),1,DBLOCACAO);
			}
		}


	// Fechando o arquivo
	fclose(DBLOCACAO);

	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	// Atualizando Tela
	wrefresh(janela);
}

void printTelaCadastrarVEICULO(WINDOW *janela){

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,3,20,"                                   ");
    mvwprintw(janela,4,20,"           CADASTRAR VEICULO       ");
    mvwprintw(janela,5,20,"                                   ");

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
    mvwprintw(janela,7,20, "Placa:_____________________________");
    mvwprintw(janela,8,20, "Modelo:____________________________");
    mvwprintw(janela,9,20, "Marca:_____________________________");
	mvwprintw(janela,10,20,"Ano:_______________________________");
	mvwprintw(janela,11,20,"Kilometragem:______________________");
	mvwprintw(janela,12,20,"Limite Kilometragem:_______________");
	mvwprintw(janela,13,20,"Valor Diaria R$:___________________");
	mvwprintw(janela,14,20,"Valor Km R$:_______________________");
	// Atualizando Tela
	wrefresh(janela);
}

void printTelaPesquisarVEICULO(WINDOW *janela){

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,3,20,"                                   ");
    mvwprintw(janela,4,20,"           PESQUISAR VEICULO       ");
    mvwprintw(janela,5,20,"                                   ");

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
	mvwprintw(janela,7,20, "INSIRA A PLACA:_______");
    mvwprintw(janela,9,20, "PLACA:");
    mvwprintw(janela,10,20,"Modelo:");
    mvwprintw(janela,11,20, "Marca:");
	mvwprintw(janela,12,20,"Ano:");
	mvwprintw(janela,13,20,"Kilometragem:");
	mvwprintw(janela,14,20,"Limite Kilometragem:");
	mvwprintw(janela,15,20,"Valor Diaria R$:");
	mvwprintw(janela,16,20,"Valor Km R$:");

	// Atualizando Tela
	wrefresh(janela);
}

void printTelaExcluirVEICULO(WINDOW *janela){

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,3,20,"                                   ");
    mvwprintw(janela,4,20,"           EXCLUIR VEICULO         ");
    mvwprintw(janela,5,20,"                                   ");

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
	mvwprintw(janela,7,20, "INSIRA A PLACA:_______");
    mvwprintw(janela,9,20, "PLACA:");
    mvwprintw(janela,10,20,"Modelo:");
    mvwprintw(janela,11,20, "Marca:");
	mvwprintw(janela,12,20,"Ano:");
	mvwprintw(janela,13,20,"Kilometragem:");
	mvwprintw(janela,14,20,"Limite Kilometragem:");
	mvwprintw(janela,15,20,"Valor Diaria R$:");
	mvwprintw(janela,16,20,"Valor Km R$:");


	// Atualizando Tela
	wrefresh(janela);
}

void printTelaEditarVEICULO(WINDOW *janela){

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_RED);
	init_pair(4,COLOR_WHITE,COLOR_GREEN);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,2,3,"                                   ");
    mvwprintw(janela,3,3,"           EDITAR VEICULO          ");
    mvwprintw(janela,4,3,"                                   ");

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
	mvwprintw(janela,7,3, "INSIRA A PLACA:_______");
    mvwprintw(janela,9,3, "PLACA:");
    mvwprintw(janela,10,3,"Modelo:");
    mvwprintw(janela,11,3, "Marca:");
	mvwprintw(janela,12,3,"Ano:");
	mvwprintw(janela,13,3,"Kilometragem:");
	mvwprintw(janela,14,3,"Limite Kilometragem:");
	mvwprintw(janela,15,3,"Valor Diaria R$:");
	mvwprintw(janela,16,3,"Valor Km R$:");

    wattron (janela, COLOR_PAIR(4));
    mvwprintw(janela,2,39,"                                   ");
    mvwprintw(janela,3,39,"       INSIRA OS NOVOS DADOS       ");
    mvwprintw(janela,4,39,"                                   ");

	wattron (janela, COLOR_PAIR(2));
    mvwprintw(janela,9,39, "PLACA:__________________");
    mvwprintw(janela,10,39,"Modelo:_________________");
    mvwprintw(janela,11,39,"Marca:__________________");
	mvwprintw(janela,12,39,"Ano:____________________");
	mvwprintw(janela,13,39,"Kilometragem:___________");
	mvwprintw(janela,14,39,"LimiteKilometragem:_____");
	mvwprintw(janela,15,39,"Valor Diaria R$:________");
	mvwprintw(janela,16,39,"Valor Km R$:____________");

	// Atualizando Tela
	wrefresh(janela);
}

void printTelaLixeiraRESTAURARVEICULO(WINDOW *janela){

    // Destruindo janela
    destruirJanela(janela);

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,1,2,"                                                                        ");
    mvwprintw(janela,2,2,"                              VEICULOS LIXEIRA                          ");
	mvwprintw(janela,3,2,"                                                                        ");
	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
	mvwprintw(janela,7,20, "DIGITE A PLACA RESTAURAR:_______");

    mvwprintw(janela,9,20, "PLACA:");
    mvwprintw(janela,10,20,"Modelo:");
    mvwprintw(janela,11,20, "Marca:");
	mvwprintw(janela,12,20,"Ano:");
	mvwprintw(janela,13,20,"Kilometragem:");
	mvwprintw(janela,14,20,"Limite Kilometragem:");
	mvwprintw(janela,15,20,"Valor Diaria R$:");
	mvwprintw(janela,16,20,"Valor Km R$:");

	// Atualizando Tela
	wrefresh(janela);
}

void printTelaLixeiraESVAZIARVEICULO(WINDOW *janela){

    // Destruindo janela
    destruirJanela(janela);

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_RED);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,1,2,"                                                                        ");
    mvwprintw(janela,2,2,"                              VEICULOS LIXEIRA                          ");
    mvwprintw(janela,4,2,"                                                                        ");
    // Alterando par de cor
	wattron (janela, COLOR_PAIR(3));
	mvwprintw(janela,4,2,"                    CUIDADO! A EXCLUSAO SERA DEFINITIVA!                ");
	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
	mvwprintw(janela,7,20, "DIGITE A PLACA A EXCLUIR:_______");
    mvwprintw(janela,9,20, "PLACA:");
    mvwprintw(janela,10,20,"Modelo:");
    mvwprintw(janela,11,20, "Marca:");
	mvwprintw(janela,12,20,"Ano:");
	mvwprintw(janela,13,20,"Kilometragem:");
	mvwprintw(janela,14,20,"Limite Kilometragem:");
	mvwprintw(janela,15,20,"Valor Diaria R$:");
	mvwprintw(janela,16,20,"Valor Km R$:");

	// Atualizando Tela
	wrefresh(janela);
}

void printTelaLOCACAO(WINDOW *janela){

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_GREEN);
	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));

    // Printando tela
    mvwprintw(janela,3,20,"                                   ");
    mvwprintw(janela,4,20,"           LOCACAO VEICULO         ");
    mvwprintw(janela,5,20,"                                   ");

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
	mvwprintw(janela,7,20, "INSIRA O CPF:[___________]");
	mvwprintw(janela,8,20, "INSIRA A PLACA:[_______]");
    mvwprintw(janela,10,20,"Data de Saida:            ");
    mvwprintw(janela,11,20,"Data de Entrega:__________");
    mvwprintw(janela,12,20,"Dias Locados:_____________");
    mvwprintw(janela,13,20,"Valor Diaria R$:          ");
	mvwprintw(janela,14,20,"Km Inicial:               ");
	wattron (janela, COLOR_PAIR(3));
	mvwprintw(janela,16,20,"                                   ");
	mvwprintw(janela,17,20,"     VALOR TOTAL:R$                ");
	mvwprintw(janela,18,20,"                                   ");
	wattron (janela, COLOR_PAIR(2));

	// Atualizando Tela
	wrefresh(janela);
}

void printTelaDEVOLUCAO(WINDOW *janela){

    // Mostrar Cursor na tela
    curs_set(1);

    // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_RED);
	init_pair(4,COLOR_WHITE,COLOR_GREEN);

	// Criando borda da janela
	box(janela, ACS_VLINE, ACS_HLINE);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(1));


	// Printando tela
    mvwprintw(janela,2,3,"                                   ");
    mvwprintw(janela,3,3,"           DADOS LOCACAO           ");
    mvwprintw(janela,4,3,"                                   ");

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(2));

	// Printando tela
	mvwprintw(janela,7,3, "INSIRA A PLACA:_______");
    mvwprintw(janela,9,3,"PLACA:                   ");
    mvwprintw(janela,10,3,"CPF:                     ");
    mvwprintw(janela,11,3,"Data Locacao:            ");
    mvwprintw(janela,12,3,"Data Devolucao:          ");
    mvwprintw(janela,13,3,"Dias Locados:            ");
	mvwprintw(janela,14,3,"Km Inicial:              ");
	mvwprintw(janela,15,3,"VALOR TOTAL:             ");

    wattron (janela, COLOR_PAIR(4));
    mvwprintw(janela,2,39,"                                   ");
    mvwprintw(janela,3,39,"        DADOS PARA CORRECAO        ");
    mvwprintw(janela,4,39,"                                   ");

	wattron (janela, COLOR_PAIR(2));
    mvwprintw(janela,9,39, "Dias Extras:______________");
	mvwprintw(janela,10,39,"Valor MULTA Dia:R$________");
	mvwprintw(janela,12,39,"Km Final:_________________");
	mvwprintw(janela,13,39,"Valor MULTA Km:R$_________");
	mvwprintw(janela,14,39,"TOTAL:R$_______");

	wattron (janela, COLOR_PAIR(2));

	// Atualizando Tela
	wrefresh(janela);
}

void scanStringComESPACO(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, char *string){

	// Mostrar Cursor
	curs_set(1);
	// Declarando variavel contador de caracter adicionado
	int cont_caracter;
	// Declarando variavel para verificar cada letra
	char letra = 0;
	// Definindo par de Cor
	wattrset(janela,COLOR_PAIR(PARCOR));

	// Ponteiro recebendo o \0 como final
	 *string = '\0';

	//Não ecoar
    noecho();

	// Iniciando for com condição de parada se der ENTER
     for(cont_caracter = 0; letra!= 10 && letra != 9;){
	  // Lendo o primeiro caracter
      letra = mvwgetch(janela,pos_linha,pos_coluna);

      //mvwprintw(janela,15,25,"VALOR DA TECLA ASCII = %d",letra);

		// Condicional verifica se é apenas LETRAS
		if(((letra >= 65)&&(letra <= 90))||(letra == 32)){
			if(cont_caracter < tamanhostring - 1 ){
				*(string + cont_caracter) = letra;
				mvwaddch(janela,pos_linha,pos_coluna,letra);
				pos_coluna++;
				cont_caracter++;
			}
		}

		//Condicional verifica se tecla pressionada é BACKSPACE
		if(letra == 7 && cont_caracter > 0){
			pos_coluna --;
			mvwaddch(janela,pos_linha,pos_coluna,'_');
			wrefresh(janela);
			cont_caracter--;
		}
	}
	//Atualiza Tela
	wrefresh(janela);

	// Ponteiro recebendo o \0 na ultima posicao, indicar final
	*(string + cont_caracter)= '\0';

	// Ecoar
	noecho();

	// Desligando cursor
	curs_set(0);
}

void scanStringSemESPACO(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, char *string){

	// Mostrar Cursor
	curs_set(1);

	// Declarando variaveis
	int cont_caracter;
	char letra = 0;

	// Definindo par de Cor
	wattrset(janela,COLOR_PAIR(PARCOR));

	// Ponteiro recebendo o \0 como final
	 *string = '\0';

	//Não ecoar
    noecho();

	// Iniciando for com condição de parada se der ENTER
     for(cont_caracter = 0; letra!= 10 && letra != 9;){

	  // Lendo o primeiro caracter
      letra = mvwgetch(janela,pos_linha,pos_coluna);

		// Condicional verifica se é apenas LETRAS
		if((letra >= 48)&&(letra <= 57)){
			if(cont_caracter < tamanhostring - 1 ){
				string[cont_caracter] = letra;
				mvwaddch(janela,pos_linha,pos_coluna,letra);
				pos_coluna++;
				cont_caracter++;
			}
		}

		//Condicional verifica se tecla pressionada é BACKSPACE
		if(letra == 7 && cont_caracter > 0){
			pos_coluna --;
			mvwaddch(janela,pos_linha,pos_coluna,'_');
			wrefresh(janela);
			cont_caracter--;
		}
	}

	// Ponteiro recebendo o \0 na ultima posicao, indicar final
	*(string + cont_caracter)= '\0';


	//Atualiza Tela
	wrefresh(janela);

	// Ocultar Cursor
	curs_set(0);

	// Ecoar
	noecho();

}

void scanStringInteiroSemESPACO(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, char *string){

	// Mostrar Cursor
	curs_set(1);

	// Declarando variaveis
	int cont_caracter;
	char letra = 0;

	// Definindo par de Cor
	wattrset(janela,COLOR_PAIR(PARCOR));

	// Ponteiro recebendo o \0 como final
	 *string = '\0';

	//Não ecoar
    noecho();

	// Iniciando for com condição de parada se der ENTER
     for(cont_caracter = 0; letra!= 10 && letra != 9;){

	  // Lendo o primeiro caracter
      letra = mvwgetch(janela,pos_linha,pos_coluna);

		// Condicional verifica se é apenas LETRAS
		if(((letra >= 48)&&(letra <= 57))||((letra >= 65)&&(letra <= 90))){
			if(cont_caracter < tamanhostring - 1 ){
				string[cont_caracter] = letra;
				mvwaddch(janela,pos_linha,pos_coluna,letra);
				pos_coluna++;
				cont_caracter++;
			}
		}

		//Condicional verifica se tecla pressionada é BACKSPACE
		if(letra == 7 && cont_caracter > 0){
			pos_coluna --;
			mvwaddch(janela,pos_linha,pos_coluna,'_');
			wrefresh(janela);
			cont_caracter--;
		}
	}

	// Ponteiro recebendo o \0 na ultima posicao, indicar final
	*(string + cont_caracter)= '\0';


	//Atualiza Tela
	wrefresh(janela);

	// Ocultar Cursor
	curs_set(0);

	// Nao Ecoar
	noecho();

}

void scanStringInteiroComESPACO(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, char *string){

	// Mostrar Cursor
	curs_set(1);

	// Declarando variaveis
	int cont_caracter;
	char letra = 0;

	// Definindo par de Cor
	wattrset(janela,COLOR_PAIR(PARCOR));

	// Ponteiro recebendo o \0 como final
	 *string = '\0';

	//Não ecoar
    noecho();

	// Iniciando for com condição de parada se der ENTER
     for(cont_caracter = 0; letra!= 10 && letra != 9;){

	  // Lendo o primeiro caracter
      letra = mvwgetch(janela,pos_linha,pos_coluna);

		// Condicional verifica se é apenas LETRAS
		if(((letra >= 48)&&(letra <= 57))||((letra >= 65)&&(letra <= 90)) ||(letra == 32) ||(letra == 46) ){
			if(cont_caracter < tamanhostring - 1 ){
				string[cont_caracter] = letra;
				mvwaddch(janela,pos_linha,pos_coluna,letra);
				pos_coluna++;
				cont_caracter++;
			}
		}

		//Condicional verifica se tecla pressionada é BACKSPACE
		if(letra == 7 && cont_caracter > 0){
			pos_coluna --;
			mvwaddch(janela,pos_linha,pos_coluna,'_');
			wrefresh(janela);
			cont_caracter--;
		}
	}

	// Ponteiro recebendo o \0 na ultima posicao, indicar final
	*(string + cont_caracter)= '\0';


	//Atualiza Tela
	wrefresh(janela);

	// Ocultar Cursor
	curs_set(0);

	// Nao Ecoar
	noecho();

}

void scanLongInteiro(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, long int *inteiro){

	// Mostrar Cursor
	curs_set(1);

	// Declarando variaveis
	int cont_caracter;
	char letra = 0;
	char string[30];
	*inteiro = 0;

	// Definindo par de Cor
	wattrset(janela,COLOR_PAIR(PARCOR));

	//Não ecoar
    noecho();

	// Iniciando for com condição de parada se der ENTER
     for(cont_caracter = 0; letra!= 10 && letra != 9;){

	  // Lendo o primeiro caracter
      letra = mvwgetch(janela,pos_linha,pos_coluna);

		// Condicional verifica se é apenas LETRAS
		if((letra >= 48)&&(letra <= 57)){
			if(cont_caracter < tamanhostring - 1 ){
				string[cont_caracter] = letra;
				mvwaddch(janela,pos_linha,pos_coluna,letra);
				pos_coluna++;
				cont_caracter++;
			}
		}

		//Condicional verifica se tecla pressionada é BACKSPACE
		if(letra == 7 && cont_caracter > 0){
			pos_coluna --;
			mvwaddch(janela,pos_linha,pos_coluna,'_');
			wrefresh(janela);
			cont_caracter--;
		}
	}

	*(string + cont_caracter)= '\0';


	//Atualiza Tela
	wrefresh(janela);


	// Ponteiro recebendo o \0 na ultima posicao, indicar final
	*inteiro = atoll(string);

	// Ocultar Cursor
	curs_set(0);

	//Nao Ecoar
	noecho();

}

void scanInteiro(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, int *inteiro){

	// Mostrar Cursor
	curs_set(1);

	// Declarando variaveis
	int cont_caracter;
	char letra = 0;
	char string[30];
	*inteiro = 0;

	// Definindo par de Cor
	wattrset(janela,COLOR_PAIR(PARCOR));

	//Não ecoar
    noecho();

	// Iniciando for com condição de parada se der ENTER
     for(cont_caracter = 0; letra!= 10 && letra != 9;){

	  // Lendo o primeiro caracter
      letra = mvwgetch(janela,pos_linha,pos_coluna);

		// Condicional verifica se é apenas LETRAS
		if((letra >= 48)&&(letra <= 57)){
			if(cont_caracter < tamanhostring - 1 ){
				string[cont_caracter] = letra;
				mvwaddch(janela,pos_linha,pos_coluna,letra);
				pos_coluna++;
				cont_caracter++;
			}
		}

		//Condicional verifica se tecla pressionada é BACKSPACE
		if(letra == 7 && cont_caracter > 0){
			pos_coluna --;
			mvwaddch(janela,pos_linha,pos_coluna,'_');
			wrefresh(janela);
			cont_caracter--;
		}
	}

	*(string + cont_caracter)= '\0';


	//Atualiza Tela
	wrefresh(janela);


	// Ponteiro recebendo o \0 na ultima posicao, indicar final
	*inteiro = atoll(string);

	// Ocultar Cursor
	curs_set(0);

	//Nao Ecoar
	noecho();

}

void scanFloat(WINDOW *janela, int pos_linha, int pos_coluna, int PARCOR, int tamanhostring, float *inteiro){

	// Mostrar Cursor
	curs_set(1);

	// Declarando variaveis
	int cont_caracter;
	char letra = 0;
	char string[30];
	*inteiro = 0;

	// Definindo par de Cor
	wattrset(janela,COLOR_PAIR(PARCOR));

	//Não ecoar
    noecho();

	// Iniciando for com condição de parada se der ENTER
     for(cont_caracter = 0; letra!= 10 && letra != 9;){

	  // Lendo o primeiro caracter
      letra = mvwgetch(janela,pos_linha,pos_coluna);

		// Condicional verifica se é apenas LETRAS
		if(((letra >= 48)&&(letra <= 57)) || (letra == 46) ){
			if(cont_caracter < tamanhostring - 1 ){
				string[cont_caracter] = letra;
				mvwaddch(janela,pos_linha,pos_coluna,letra);
				pos_coluna++;
				cont_caracter++;
			}
		}

		//Condicional verifica se tecla pressionada é BACKSPACE
		if(letra == 7 && cont_caracter > 0){
			pos_coluna --;
			mvwaddch(janela,pos_linha,pos_coluna,'_');
			wrefresh(janela);
			cont_caracter--;
		}
	}

	*(string + cont_caracter)= '\0';


	//Atualiza Tela
	wrefresh(janela);


	// Ponteiro recebendo o \0 na ultima posicao, indicar final
	*inteiro = atoll(string);

	// Ocultar Cursor
	curs_set(0);

	//Nao Ecoar
	noecho();

}

void printMensagemERRO(WINDOW *janela, int posicaolinha, int posicaocoluna, char aviso[50]){

	// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	// Definindo Pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_RED);

    // Setando Par 1 para o nome Menu Principal
    wattron (janela, COLOR_PAIR(3));
    mvwprintw(janela,posicaolinha ,posicaocoluna,"%s",                                    aviso);
	wattron (janela, COLOR_PAIR(2));
	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	wrefresh(janela);
}

void printMensagemSUCESSO(WINDOW *janela, int posicaolinha, int posicaocoluna, char aviso[50]){

	// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	// Definindo Pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_GREEN);

    // Setando Par 1 para o nome Menu Principal
    wattron (janela, COLOR_PAIR(3));
    mvwprintw(janela,posicaolinha ,posicaocoluna,"%s",                                    aviso);
	wattron (janela, COLOR_PAIR(2));
	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	wrefresh(janela);
}

void printMensagemSUCESSONUMERO(WINDOW *janela, int posicaolinha, int posicaocoluna, float numero){

	// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	// Definindo Pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_GREEN);

    // Setando Par 1 para o nome Menu Principal
    wattron (janela, COLOR_PAIR(3));
    mvwprintw(janela,posicaolinha ,posicaocoluna,"%.2f",numero);
	wattron (janela, COLOR_PAIR(2));
	mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
	wrefresh(janela);
}

void printDadosCLIENTEATIVO(WINDOW *janela, int posicao){

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

	// Se Status for significa que o registro esta inativo
	if(REG.status == 0){
		printMensagemERRO(janela,13,20,"                ERRO!              ");
		printMensagemERRO(janela,14,20,"   O CPF DIGITADO ESTA EXCLUIDO!   ");
		printMensagemERRO(janela,15,20,"      ACESSE O MENU LIXEIRA        ");
		}

	else{
	mvwprintw(janela,9,25,"%s",REG.nome);
	mvwprintw(janela,10,24,"%s",REG.cpf);
	mvwprintw(janela,11,29,"%ld",REG.tel);
	}

	// Fechando o arquivo
	fclose(DBCLIENTE);

	// Atualizando tela
	wrefresh(janela);
	}
}

void printDadosCLIENTEINATIVO(WINDOW *janela, int posicao){

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

	// Se Status for significa que o registro esta inativo

	mvwprintw(janela,9,25,"%s",REG.nome);
	mvwprintw(janela,10,24,"%s",REG.cpf);
	mvwprintw(janela,11,29,"%ld",REG.tel);


	// Fechando o arquivo
	fclose(DBCLIENTE);

	// Atualizando tela
	wrefresh(janela);
	}
}

void printDadosVEICULO(WINDOW *janela, int posicao){

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


	if(REG.status == 0){
		printMensagemERRO(janela,17,20,"               ERRO!               ");
		printMensagemERRO(janela,18,20,"     O VEICULO ESTA EXCLUIDO!      ");
		printMensagemERRO(janela,19,20,"      ACESSE O MENU LIXEIRA        ");
	}

	else{
    // Printando dados do VEICULO
    mvwprintw(janela,9,26,"%s",REG.placa);
    mvwprintw(janela,10,27,"%s",REG.modelo);
    mvwprintw(janela,11,26,"%s",REG.marca);
    mvwprintw(janela,12,24,"%d",REG.ano);
    mvwprintw(janela,13,33,"%d",REG.km);
    mvwprintw(janela,14,40,"%d",REG.limitekm);
    mvwprintw(janela,15,36,"%.2f",REG.diaria);
    mvwprintw(janela,16,32,"%.2f",REG.valorkm);

    // Fechando o arquivo
    fclose(DBVEICULO);

    // Atualizando tela
    wrefresh(janela);
    }
  }
}

void printDadosVEICULOINATIVO(WINDOW *janela, int posicao){

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

	// Printando dados do VEICULO
	mvwprintw(janela,9,26,"%s",REG.placa);
	mvwprintw(janela,10,27,"%s",REG.modelo);
	mvwprintw(janela,11,26,"%s",REG.marca);
	mvwprintw(janela,12,24,"%d",REG.ano);
	mvwprintw(janela,13,33,"%d",REG.km);
	mvwprintw(janela,14,40,"%d",REG.limitekm);
	mvwprintw(janela,15,36,"%.2f",REG.diaria);
	mvwprintw(janela,16,32,"%.2f",REG.valorkm);

	// Fechando o arquivo
	fclose(DBVEICULO);

	// Atualizando tela
	wrefresh(janela);

	}
}

void printDadosDEVOLUCAO(WINDOW *janela, int posicao){
		// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	// Definindo variaveis
	STR_LOCACAO REG;

	// Definindo arquivo logico
	FILE *DBLOCACAO;

	// Definindo arquivo fisico como leitura
	DBLOCACAO = fopen("DBLOCACAO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBLOCACAO == NULL){
		DBLOCACAO = fopen("DBLOCACAO.TXT","w");
	}

	else{

	 // Criando pares de cores
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_RED);
	init_pair(4,COLOR_WHITE,COLOR_GREEN);
	init_pair(5,COLOR_CYAN,COLOR_BLACK);

	// Alterando par de cor
	wattron (janela, COLOR_PAIR(5));

	// Posicionando no na posicao do registro da PLACA buscada
	fseek(DBLOCACAO,posicao * sizeof(REG), 0);

	// Lendo arquivos do DBVEICULO e printando
	fread(&REG,sizeof(REG),1,DBLOCACAO);

	// Printando dados do VEICULO
	mvwprintw(janela,9,10,"%s",REG.placa);
	mvwprintw(janela,10,8,"%s",REG.cpf);
	mvwprintw(janela,11,16,"%s",REG.datasaida);
	mvwprintw(janela,12,19,"%s",REG.dataentrega);
	mvwprintw(janela,13,17,"%d",REG.diaslocados);
	mvwprintw(janela,14,15,"%d",REG.kminicial);
	mvwprintw(janela,15,16,"%.2f",REG.valortotal);

	wattron (janela, COLOR_PAIR(2));
	// Fechando o arquivo
	fclose(DBLOCACAO);

	// Atualizando tela
	wrefresh(janela);

	}
}

int buscarUSUARIO(char *nome){

	// Definindo variaveis
	int cont = 0;
	STR_USER REG;

	// Definindo arquivo logico
	FILE *DBUSUARIO;

	// Definindo arquivo fisico como leitura
	DBUSUARIO = fopen("DBUSUARIO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBUSUARIO == NULL){
		DBUSUARIO = fopen("DBUSUARIO.TXT","w");
	}

	else{

	// Lendo arquivos do DBCLIENTE
	fread(&REG,sizeof(REG),1,DBUSUARIO);

	// Iniciando condicionais
	while(!feof(DBUSUARIO) && (strcmp(REG.nome,nome) != 0)){
		cont++;
		fread(&REG,sizeof(REG),1,DBUSUARIO);
		}
	}

	// Fechando o arquivo
	fclose(DBUSUARIO);

	// Se encontrar CPF retorna a posicao
	if(strcmp(REG.nome,nome) == 0){
		return(cont);
	}

	// Senao ele retorna -10 que significa que nao encontrou o CPF
	else{
		return(-10);
	}
}

float buscarValorTotalLOCACAO(int posicao){
		// Mostrar Cursor
	curs_set(0);

	// Nao ecoar na tela
	noecho();

	// Definindo variaveis
	STR_LOCACAO REG;

	// Definindo arquivo logico
	FILE *DBLOCACAO;

	// Definindo arquivo fisico como leitura
	DBLOCACAO = fopen("DBLOCACAO.TXT","r");

	// Condicional se o arquivo nao existir ele cria
	if(DBLOCACAO == NULL){
		DBLOCACAO = fopen("DBLOCACAO.TXT","w");
	}

	else{

	// Posicionando no na posicao do registro da PLACA buscada
	fseek(DBLOCACAO,posicao * sizeof(REG), 0);

	// Lendo arquivos do DBVEICULO e printando
	fread(&REG,sizeof(REG),1,DBLOCACAO);

	// Fechando o arquivo
	fclose(DBLOCACAO);

	}
	return(REG.valortotal);

}

float calculaValorTotalLOCACAO(float valordiaria, int diaslocados){

	float totalpagar = 0;

	totalpagar = diaslocados * valordiaria;

	return (totalpagar);
}

float calcularValorTotalDEVOLUCAO(float totalanterior, int diasextras, float valormultadia, int kminicial, int kmfinal, int kmlimite, float valormultakm){

	float valortotal;
	float calcdias;
	float calckm;


	calcdias = diasextras * valormultadia;
	calckm = (kmfinal - kminicial) - kmlimite;
	if(calckm < kmlimite){
		valortotal = calcdias + totalanterior;
	}

	else if(calckm >= kmlimite){
	calckm = ((kmfinal - kminicial) - kmlimite) * valormultakm;
	valortotal = totalanterior + calcdias + calckm;
	}

return(valortotal);
}

void datasistema(char *datasistema){

	char mes[4], dia[3], ano[5];

    strcpy(mes, ""); //limpa a string mes

    strcpy(dia, ""); //limpa a string dia

    strcpy(ano, "");//limpa a string ano

    strncat(mes, __DATE__ , 3); //a partir da posição zero do vetor da data copie 3 caracteres =  Nov

    strncat(dia, __DATE__ +4, 2);//a partir da posição 4 do vetor da data copie 2 caracteres = 27

    strncat(ano, __DATE__ +7, 4);//a partir da posição 7 do vetor da data copie 4 caracteres = 2013

	//strupr(mes);

	if(strcmp(mes,"FEB") == 0){
		 strcpy(mes,"FEV");
		}

	else if(strcmp(mes,"APR") == 0){
		 strcpy(mes,"ABR");
		}

	else if(strcmp(mes,"MAY") == 0){
		 strcpy(mes,"MAI");
		}

	else if(strcmp(mes,"AUG") == 0){
		 strcpy(mes,"AGO");
		}

	else if(strcmp(mes,"SEP") == 0){
		strcpy(mes,"SET");

	}

	else if(strcmp(mes,"OCT") == 0){
		 strcpy(mes,"OUT");
		}

	else if(strcmp(mes,"DEC") == 0){
		 strcpy(mes,"DEZ");
		}


	sprintf (datasistema,"%s %s %s", dia, mes, ano);

}

void removerLOCACAO(WINDOW *janela, int posicao){

	// Variaveis
	char placaExcluido[8];

	// Mostrar Cursor
	curs_set(1);

	// Nao ecoar na tela
	echo();

	// Definindo variaveis
	STR_LOCACAO REG;

	// Definindo arquivo logico
	FILE *DBLOCACAO;

	// Definindo arquivo fisico como leitura
	DBLOCACAO = fopen("DBLOCACAO.TXT","r+");

	// Condicional se o arquivo nao existir ele cria
	if(DBLOCACAO == NULL){
		DBLOCACAO = fopen("DBLOCACAO.TXT","w");
	}


	// Cria um arquivo logico para manipular os dados
	FILE *DBTEMP;

	// Criando arquivo fisico da manipulacao
	DBTEMP = fopen("DBTEMP.TXT","w");

	// Posicionando no na posicao do registro PLACA buscado
	fseek(DBLOCACAO, posicao * sizeof(REG), SEEK_SET);

	// Lendo Arquivo e gravando na REG
	fread(&REG, sizeof(REG), 1, DBLOCACAO);

	// Pegando cpf a excluir
	strcpy (placaExcluido,REG.placa);

	// Posicionando no inicio do arquivo DBCLIENTE
	rewind(DBLOCACAO);

	// Lendo arquivo DBCLIENTE
	fread(&REG, sizeof(REG), 1, DBLOCACAO);

	// Enquanto não for final de arquivo e se a placa buscado for igual o do arquivo ele nao grava no temp
			while(!feof(DBLOCACAO)){
				if(strcmp(REG.placa,placaExcluido) != 0){
					fwrite(&REG, sizeof(REG), 1, DBTEMP);
				}
				fread(&REG, sizeof(REG), 1, DBLOCACAO);
			}

			// Fechando arquivos
			fclose(DBLOCACAO);
			fclose(DBTEMP);

			// Abrindo arquivos
			DBLOCACAO = fopen("DBLOCACAO.TXT","w");
			DBTEMP = fopen("DBTEMP.TXT","r+");

			// Copiando aquivo DBTEMP para DBCLIENTE
			fread(&REG, sizeof(REG), 1, DBTEMP);
			while(!feof(DBTEMP)){
				fwrite(&REG, sizeof(REG), 1, DBLOCACAO);
				fread(&REG, sizeof(REG), 1, DBTEMP);
			}

			// Fechando Arquivos e apagando arquivo DBTEMP
			fclose(DBLOCACAO);
			fclose(DBTEMP);
			remove("DBTEMP.TXT");

			// Mensagem de exclusao Sucesso
			mvwprintw(janela,19,20,"           VEICULO DEVOLVIDO!          ");
			mvwprintw(janela,21,18,"Pressione qualquer tecla para continuar!");
			wrefresh(janela);


// Ocultar Cursor
curs_set(0);

// Nao ecoar na tela
noecho();
}



