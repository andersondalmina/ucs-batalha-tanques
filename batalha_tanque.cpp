#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 11
#define TANQUEBRANCO 98
#define TANQUEPRETO 112
#define COMANDANTEBRANCO 66
#define COMANDANTEPRETO 80
#define AREACONTAMINADA 35


char tabuleiroOrigem[TAM][TAM] = {
	176, 176, 176, 176, 176, 158, 0, 0, 0, 0, 0,
	176, 158, 176, 176, 0, 0, 0, 0, 0, 158, 0,
	176, 176, 176, 158, 0, 158, 0, 158, 0, 0, 0,
	176, 176, 158, 0, 0, 0, 0, 0, 158, 0, 0,
	176, 0, 0, 0, AREACONTAMINADA, AREACONTAMINADA, AREACONTAMINADA, 0, 0, 0, 0,
	158, 0, 158, 0, AREACONTAMINADA, AREACONTAMINADA, AREACONTAMINADA, 0, 158, 0, 158,
	0, 0, 0, 0, AREACONTAMINADA, AREACONTAMINADA, AREACONTAMINADA, 0, 0, 0, 178,
	0, 0, 158, 0, 0, 0, 0, 0, 158, 178, 178,
	0, 0, 0, 158, 0, 158, 0, 158, 178, 178, 178,
	0, 158, 0, 0, 0, 0, 0, 178, 178, 158, 178,
	0, 0, 0, 0, 0, 158, 178, 178, 178, 178, 178,
};

//FUNÇÃO PARA IMPRIMIR O TABULEIRO NA TELA
void imprimeTabuleiro(char tabuleiro[][TAM]) {
	printf("%c", 218);
	for (int i = 0; i < TAM; i++) {
		printf("%c%c%c", 196, 196, 194);
	}

	printf("%c%c%c\n", 196, 196, 191);

	printf("%c  ", 179);
	for (int i = 0; i < TAM; i++) {
		printf("%c%d", 179, i);

		if (i < 10) {
			printf(" ");
		}
	}
	printf("%c\n", 179);

	for (int i = 0; i < TAM; i++) {
		if (i == 0) {
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c%d %c",
				195, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196,
				196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 0xb4, 179, i, 179);
		}
		else {
			if (i<10) {
				printf("%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c%d %c",
					179, 195, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196,
					196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 0xb4, 179, i, 179);
			}
			else {
				printf("%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c%d%c",
					179, 195, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196,
					196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 197, 196, 196, 0xb4, 179, i, 179);
			}
		}

		for (int j = 0; j < TAM; j++) {
			if (j < 10) {
				printf("%c %c", tabuleiro[i][j], 179);
			}
			else {
				printf("%c ", tabuleiro[i][j]);
			}
		}
	}

	printf("%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
		179, 0xc0, 196, 196, 0xc1, 196, 196, 0xc1, 196, 196, 0xc1, 196, 196, 0xc1, 196, 196, 0xc1, 196, 196, 0xc1, 196,
		196, 0xc1, 196, 196, 0xc1, 196, 196, 0xc1, 196, 196, 0xc1, 196, 196, 0xc1, 196, 196, 0xd9);

	printf("Legenda: \n");
	printf("%c - Base Tanques Pretos, %c - Base Tanques Brancos\n", 176, 178);
	printf("%c - Tanques Pretos, %c - Tanques Brancos\n", TANQUEPRETO, TANQUEBRANCO);
	printf("%c - Bombas, %c - Area Contaminada\n", 158, AREACONTAMINADA);
	printf("%c - Tanque Especial Preto, %c - Tanque Especial Branco\n\n\n", COMANDANTEPRETO, COMANDANTEBRANCO);
}

// RETORNA O VALOR DA POSICAO INFORMADA
int situacaoPosicao(int linha, int coluna, char tabuleiro[][TAM]) {
	return (int)tabuleiro[linha][coluna];
}

//PREENCHE O NOVO TABULEIRO COM OS TANQUES
void colocarTanques(char tabuleiro[][TAM]) {
	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++) {
			int situacao = situacaoPosicao(i, j, tabuleiro);

			if (situacao == -80) {
				tabuleiro[i][j] = TANQUEPRETO;
			}
			else if (situacao == -78) {
				tabuleiro[i][j] = TANQUEBRANCO;
			}
		}
	}

	tabuleiro[0][0]= COMANDANTEPRETO;
	tabuleiro[10][10] = COMANDANTEBRANCO;
}

void geraMatrizPossibilidades(int linha, int coluna, int equipe, char tabuleiro[][TAM], char possibilidades[][TAM]) {
	int c = 0,
		l = 0,
		parar = 0,
		situacao = 0,
		tipoTanque = 0,
		situacaoOriginal = 0;

	tipoTanque = situacaoPosicao(linha, coluna, tabuleiro);
	situacaoOriginal = situacaoPosicao(linha, coluna, tabuleiroOrigem);

	//VERIFICA POSSIBILIDADES PARA ESQUERDA
	if (coluna > 0) {
		c = coluna - 1;
		parar = 0;
		while (parar == 0) {
			if (c <= 0) {
				parar = 1;
			}

			situacao = situacaoPosicao(linha, c, tabuleiro);

			//MOVIMENTOS DOS TANQUES BRANCOS
			if ((equipe == 0 && situacaoOriginal != -80 && situacao == 0) || (equipe == 0 && situacaoOriginal != -80 && situacao == -78) || (equipe == 0 && situacao == -80)) {
				possibilidades[linha][c] = 1;
				c--;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEPRETO && equipe == 0) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 0)) {
				possibilidades[linha][c] = 1;
				c--;
				parar = 1;

			}

			//MOVIMENTOS DOS TANQUES PRETOS
			else if ((equipe == 1 && situacaoOriginal != -78 && situacao == 0) || (equipe == 1 && situacaoOriginal != -78 && situacao == -80) || (equipe == 1 && situacao == -78)) {
				possibilidades[linha][c] = 1;
				c--;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEBRANCO && equipe == 1) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 1)) {
				possibilidades[linha][c] = 1;
				c--;
				parar = 1;
			
			}
			else if ((tipoTanque == COMANDANTEBRANCO && situacao == AREACONTAMINADA) || (tipoTanque == COMANDANTEPRETO && situacao == AREACONTAMINADA)) {
				possibilidades[linha][c] = 1;
				c--;
				parar = 1;

			} 
			else {
				parar = 1;
			}
		}
	}

	//VERIFICA POSSIBILIDADES PARA DIREITA
	if (coluna < 10) {
		c = coluna + 1;
		parar = 0;
		while (parar == 0 && c < TAM) {
			if (c >= TAM) {
				parar = 1;
			}

			situacao = situacaoPosicao(linha, c, tabuleiro);

			//MOVIMENTOS DOS TANQUES BRANCOS
			if ((equipe == 0 && situacaoOriginal != -80 && situacao == 0) || (equipe == 0 && situacaoOriginal != -80 && situacao == -78) || (equipe == 0 && situacao == -80)) {
				possibilidades[linha][c] = 1;
				c++;

			}

			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEPRETO && equipe == 0) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 0)) {
				possibilidades[linha][c] = 1;
				c++;
				parar = 1;

			}

			//MOVIMENTOS DOS TANQUES PRETOS
			else if ((equipe == 1 && situacaoOriginal != -78 && situacao == 0) || (equipe == 1 && situacaoOriginal != -78 && situacao == -80) || (equipe == 1 && situacao == -78)) {
				possibilidades[linha][c] = 1;
				c++;

			}
			
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEBRANCO && equipe == 1) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 1)) {
				possibilidades[linha][c] = 1;
				c++;
				parar = 1;

			}
			else if ((tipoTanque == COMANDANTEBRANCO && situacao == AREACONTAMINADA) || (tipoTanque == COMANDANTEPRETO && situacao == AREACONTAMINADA)) {
				possibilidades[linha][c] = 1;
				c++;
				parar = 1;

			}
			else {
				parar = 1;
			}
		}
	}

	//VERIFICA POSSIBILIDADES PARA CIMA
	if (linha > 0) {
		l = linha - 1;
		parar = 0;
		while (parar == 0) {
			if (l <= 0) {
				parar = 1;
			}

			situacao = situacaoPosicao(l, coluna, tabuleiro);

			//MOVIMENTOS DOS TANQUES BRANCOS
			if ((equipe == 0 && situacaoOriginal != -80 && situacao == 0) || (equipe == 0 && situacaoOriginal != -80 && situacao == -78) || (equipe == 0 && situacao == -80)) {
				possibilidades[l][coluna] = 1;
				l--;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEPRETO && equipe == 0) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 0)) {
				possibilidades[l][coluna] = 1;
				l--;
				parar = 1;

			}

			//MOVIMENTOS DOS TANQUES PRETOS
			else if ((equipe == 1 && situacaoOriginal != -78 && situacao == 0) || (equipe == 1 && situacaoOriginal != -78 && situacao == -80) || (equipe == 1 && situacao == -78)) {
				possibilidades[l][coluna] = 1;
				l--;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEBRANCO && equipe == 1) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 1)) {
				possibilidades[l][coluna] = 1;
				l--;
				parar = 1;

			}
			else if ((tipoTanque == COMANDANTEBRANCO && situacao == AREACONTAMINADA) || (tipoTanque == COMANDANTEPRETO && situacao == AREACONTAMINADA)) {
				possibilidades[l][coluna] = 1;
				l--;
				parar = 1;

			}
			else {
				parar = 1;
			}
		}
	}

	//VERIFICA POSSIBILIDADES PARA BAIXO
	if (linha < 10) {
		l = linha + 1;
		parar = 0;
		while (parar == 0) {
			if (l >= TAM) {
				parar = 1;
			}

			situacao = situacaoPosicao(l, coluna, tabuleiro);

			//MOVIMENTOS DOS TANQUES BRANCOS
			if ((equipe == 0 && situacaoOriginal != -80 && situacao == 0) || (equipe == 0 && situacaoOriginal != -80 && situacao == -78) || (equipe == 0 && situacao == -80)) {
				possibilidades[l][coluna] = 1;
				l++;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEPRETO && equipe == 0) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 0)) {
				possibilidades[l][coluna] = 1;
				l++;
				parar = 1;

			}

			//MOVIMENTOS DOS TANQUES PRETOS
			else if ((equipe == 1 && situacaoOriginal != -78 && situacao == 0) || (equipe == 1 && situacaoOriginal != -78 && situacao == -80) || (equipe == 1 && situacao == -78)) {
				possibilidades[l][coluna] = 1;
				l++;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEBRANCO && equipe == 1) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 1)) {
				possibilidades[l][coluna] = 1;
				l++;
				parar = 1;

			}
			else if ((tipoTanque == COMANDANTEBRANCO && situacao == AREACONTAMINADA) || (tipoTanque == COMANDANTEPRETO && situacao == AREACONTAMINADA)) {
				possibilidades[l][coluna] = 1;
				l++;
				parar = 1;

			}
			else {
				parar = 1;
			}
		}
	}


	//VERIFICA POSSIBILIDADES DIAGONAL PARA CIMA/DIREITA
	if (linha > 0 && coluna < 10) {
		l = linha - 1;
		c = coluna + 1;
		parar = 0;
		while (parar == 0) {
			if (l <= 0 || c >= TAM) {
				parar = 1;
			}

			situacao = situacaoPosicao(l, c, tabuleiro);
			
			//MOVIMENTOS DOS TANQUES BRANCOS
			if ((equipe == 0 && situacaoOriginal != -80 && situacao == 0) || (equipe == 0 && situacaoOriginal != -80 && situacao == -78) || (equipe == 0 && situacao == -80)) {
				possibilidades[l][c] = 1;
				l--;
				c++;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEPRETO && equipe == 0) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 0)) {
				possibilidades[l][c] = 1;
				l--;
				c++;
				parar = 1;

			}

			//MOVIMENTOS DOS TANQUES PRETOS
			else if ((equipe == 1 && situacaoOriginal != -78 && situacao == 0) || (equipe == 1 && situacaoOriginal != -78 && situacao == -80) || (equipe == 1 && situacao == -78)) {
				possibilidades[l][c] = 1;
				l--;
				c++;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEBRANCO && equipe == 1) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 1)) {
				possibilidades[l][c] = 1;
				l--;
				c++;
				parar = 1;

			}
			else if ((tipoTanque == COMANDANTEBRANCO && situacao == AREACONTAMINADA) || (tipoTanque == COMANDANTEPRETO && situacao == AREACONTAMINADA)) {
				possibilidades[l][c] = 1;
				l--;
				c++;
				parar = 1;

			}
			else {
				parar = 1;
			}
		}
	}

	//VERIFICA POSSIBILIDADES DIAGONAL PARA BAIXO/DIREITA
	if (linha < 10 & coluna < 10) {
		l = linha + 1;
		c = coluna + 1;
		parar = 0;
		while (parar == 0) {
			if (l >= TAM || c >= TAM) {
				parar = 1;
			}

			situacao = situacaoPosicao(l, c, tabuleiro);
			
			//MOVIMENTOS DOS TANQUES BRANCOS
			if ((equipe == 0 && situacaoOriginal != -80 && situacao == 0) || (equipe == 0 && situacaoOriginal != -80 && situacao == -78) || (equipe == 0 && situacao == -80)) {
				possibilidades[l][c] = 1;
				l++;
				c++;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEPRETO && equipe == 0) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 0)) {
				possibilidades[l][c] = 1;
				l++;
				c++;
				parar = 1;

			}

			//MOVIMENTOS DOS TANQUES PRETOS
			else if ((equipe == 1 && situacaoOriginal != -78 && situacao == 0) || (equipe == 1 && situacaoOriginal != -78 && situacao == -80) || (equipe == 1 && situacao == -78)) {
				possibilidades[l][c] = 1;
				l++;
				c++;

			}
			
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEBRANCO && equipe == 1) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 1)) {
				possibilidades[l][c] = 1;
				l++;
				c++;
				parar = 1;

			}
			else if ((tipoTanque == COMANDANTEBRANCO && situacao == AREACONTAMINADA) || (tipoTanque == COMANDANTEPRETO && situacao == AREACONTAMINADA)) {
				possibilidades[l][c] = 1;
				l++;
				c++;
				parar = 1;

			}
			else {
				parar = 1;
			}
		}
	}

	//VERIFICA POSSIBILIDADES DIAGONAL PARA BAIXO/ESQUERDA
	if (linha < 10 && coluna > 0) {
		l = linha + 1;
		c = coluna - 1;
		parar = 0;
		while (parar == 0) {
			if (l >= TAM || c <= 0) {
				parar = 1;
			}

			situacao = situacaoPosicao(l, c, tabuleiro);

			//MOVIMENTOS DOS TANQUES BRANCOS
			if ((equipe == 0 && situacaoOriginal != -80 && situacao == 0) || (equipe == 0 && situacaoOriginal != -80 && situacao == -78) || (equipe == 0 && situacao == -80)) {
				possibilidades[l][c] = 1;
				l++;
				c--;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEPRETO && equipe == 0) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 0)) {
				possibilidades[l][c] = 1;
				l++;
				c--;
				parar = 1;

			}

			//MOVIMENTOS DOS TANQUES PRETOS
			else if ((equipe == 1 && situacaoOriginal != -78 && situacao == 0) || (equipe == 1 && situacaoOriginal != -78 && situacao == -80) || (equipe == 1 && situacao == -78)) {
				possibilidades[l][c] = 1;
				l++;
				c--;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEBRANCO && equipe == 1) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 1)) {
				possibilidades[l][c] = 1;
				l++;
				c--;
				parar = 1;

			}
			else if ((tipoTanque == COMANDANTEBRANCO && situacao == AREACONTAMINADA) || (tipoTanque == COMANDANTEPRETO && situacao == AREACONTAMINADA)) {
				possibilidades[l][c] = 1;
				l++;
				c--;
				parar = 1;

			}
			else {
				parar = 1;
			}
		}
	}

	//VERIFICA POSSIBILIDADES DIAGONAL PARA CIMA/ESQUERDA
	if (linha > 0 && coluna > 0) {
		l = linha - 1;
		c = coluna - 1;
		parar = 0;
		while (parar == 0) {
			if (l <= 0 || c <= 0) {
				parar = 1;
			}

			situacao = situacaoPosicao(l, c, tabuleiro);

			//MOVIMENTOS DOS TANQUES BRANCOS
			if ((equipe == 0 && situacaoOriginal != -80 && situacao == 0) || (equipe == 0 && situacaoOriginal != -80 && situacao == -78) || (equipe == 0 && situacao == -80)) {
				possibilidades[l][c] = 1;
				l--;
				c--;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEPRETO && equipe == 0) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 0)) {
				possibilidades[l][c] = 1;
				l--;
				c--;
				parar = 1;

			}

			//MOVIMENTOS DOS TANQUES PRETOS
			else if ((equipe == 1 && situacaoOriginal != -78 && situacao == 0) || (equipe == 1 && situacaoOriginal != -78 && situacao == -80) || (equipe == 1 && situacao == -78)) {
				possibilidades[l][c] = 1;
				l--;
				c--;

			}
			else if ((situacaoOriginal != AREACONTAMINADA && situacao == TANQUEBRANCO && equipe == 1) || (situacaoOriginal != AREACONTAMINADA && situacao == COMANDANTEPRETO && equipe == 1)) {
				possibilidades[l][c] = 1;
				l--;
				c--;
				parar = 1;

			}
			else if ((tipoTanque == COMANDANTEBRANCO && situacao == AREACONTAMINADA) || (tipoTanque == COMANDANTEPRETO && situacao == AREACONTAMINADA)) {
				possibilidades[l][c] = 1;
				l--;
				c--;
				parar = 1;

			}
			else {
				parar = 1;
			}
		}
	}
}

int pedirJogada(char tabuleiro[][TAM], int equipe) {
	int tanque[2] = { 0, 0 };
	int destino[2] = { 0, 0 };
	char possibilidades[TAM][TAM];

	if (equipe == 0) {
		printf("Jogada dos Tanques Brancos\n");
	}
	else {
		printf("Jogada dos Tanques Pretos\n");
	}

	printf("Escolha o tanque\n");
	printf("Digite o numero da linha:");
	fflush(stdin);
	scanf("%d", &tanque[0]);
	printf("Digite o numero da coluna:");
	fflush(stdin);
	scanf("%d", &tanque[1]);

	int situacao = situacaoPosicao(tanque[0], tanque[1], tabuleiro);
	if (((equipe == 0 && situacao == TANQUEBRANCO) || (equipe == 0 && situacao == COMANDANTEBRANCO)) || ((equipe == 1 && situacao == TANQUEPRETO) || (equipe == 1 && situacao == COMANDANTEPRETO))) {
		geraMatrizPossibilidades(tanque[0], tanque[1], equipe, tabuleiro, possibilidades);

		printf("Escolha o destino\n");
		printf("Digite o numero da linha:");
		fflush(stdin);
		scanf("%d", &destino[0]);
		printf("Digite o numero da coluna:");
		fflush(stdin);
		scanf("%d", &destino[1]);

		if (possibilidades[destino[0]][destino[1]] == 1) {
			tabuleiro[destino[0]][destino[1]] = situacaoPosicao(tanque[0], tanque[1], tabuleiro);
			tabuleiro[tanque[0]][tanque[1]] = situacaoPosicao(tanque[0], tanque[1], tabuleiroOrigem);
			return 0;
		}
		else {
			return 2;
		}
	} else {
		return 1;
	}
}

int terminarJogo(char tabuleiro[][TAM], int pontuacao[]) {
	int terminarPretos = 1;
	int terminarBrancos = 1;

	pontuacao[0] = 0;
	pontuacao[1] = 0;

	//VERIFICA SE TODOS TANQUES PRETOS ESTAO NA BASE INIMIGA
	for (int i = 0; i < TAM; i++) {
		for (int k = 0; k < TAM; k++) {
			if ((situacaoPosicao(i, k, tabuleiro) == TANQUEPRETO) || (situacaoPosicao(i, k, tabuleiro) == COMANDANTEPRETO)) {
				terminarPretos = 0;
				if (situacaoPosicao(i, k, tabuleiroOrigem) == -78) {
					terminarPretos = 1;
					break;
				}
			}
		}

		if (terminarPretos == 0) {
			break;
		}
	}

	//VERIFICA SE TODOS TANQUES BRANCOS ESTAO NA BASE INIMIGA
	for (int i = 0; i < TAM; i++) {
		for (int k = 0; k < TAM; k++) {
			if ((situacaoPosicao(i, k, tabuleiro) == TANQUEBRANCO) || (situacaoPosicao(i, k, tabuleiro) == COMANDANTEBRANCO)) {
				terminarBrancos = 0;
				if (situacaoPosicao(i, k, tabuleiroOrigem) == -80) {
					terminarBrancos = 1;
				}
			}
		}

		if (terminarBrancos == 0) {
			break;
		}
	}

	//PONTUACAO
	//SOMA PONTOS EQUIPE PRETA
	if (situacaoPosicao(TAM - 1, TAM - 1, tabuleiro) == COMANDANTEPRETO) {
		pontuacao[0] += 3;
	}

	for (int i = 0; i < TAM; i++) {
		for (int k = 0; k < TAM; k++) {
			if ((situacaoPosicao(i, k, tabuleiro) == TANQUEPRETO) || (situacaoPosicao(i, k, tabuleiro) == COMANDANTEPRETO)) {
				if (situacaoPosicao(i, k, tabuleiroOrigem) == -78) {
					pontuacao[0] += 2;
				} else {
					pontuacao[0] += 1;
				}
			}
		}
	}

	//SOMA PONTOS EQUIPE BRANCA
	if (situacaoPosicao(0, 0, tabuleiro) == COMANDANTEBRANCO) {
		pontuacao[1] += 3;
	}

	for (int i = 0; i < TAM; i++) {
		for (int k = 0; k < TAM; k++) {
			if ((situacaoPosicao(i, k, tabuleiro) == TANQUEBRANCO) || (situacaoPosicao(i, k, tabuleiro) == COMANDANTEBRANCO)) {
				if (situacaoPosicao(i, k, tabuleiroOrigem) == -80) {
					pontuacao[0] += 2;
				}
				else {
					pontuacao[0] += 1;
				}
			}
		}
	}

	return terminarPretos + terminarBrancos;
}

// INICIA JOGO
// EQUIPE 0 = TANQUES BRANCOS
// EQUIPE 1 = TANQUES PRETOS
void jogar() {
	int pontuacao[2] = { 0, 0 };
	int equipe = 1;

	char tabuleiro[TAM][TAM];
	memcpy(tabuleiro, tabuleiroOrigem, TAM*TAM);

	colocarTanques(tabuleiro);

	while (terminarJogo(tabuleiro, pontuacao) == 0) {
		system("cls");
		imprimeTabuleiro(tabuleiro);
		int jogada = pedirJogada(tabuleiro, equipe);
		if (jogada == 1) {
			printf("Coordenadas Invalidas!\n");
			system("pause");
		}
		else if (jogada == 2) {
			printf("Seu tanque nao pode se deslocar para o destino selecionado!\n");
			system("pause");
		}
		else {
			equipe = abs(equipe - 1);
		}
	}

	system("cls");
	printf("Jogo Encerrado!!!\n");
	printf("Pontuacao:\n");
	printf("Equipe Preta: %d pontos\n", pontuacao[0]);
	printf("Equipe Branca: %d pontos\n", pontuacao[1]);
	if (pontuacao[0] > pontuacao[1]) {
		printf("A equipe Preta venceu !!!\n");
	}
	else if (pontuacao[0] < pontuacao[1]) {
		printf("A equipe Branca venceu !!!\n");
	}
	else {
		printf("A partida terminou empatada\n");
	}
}

int main() {
	jogar();
	system("pause");
}
