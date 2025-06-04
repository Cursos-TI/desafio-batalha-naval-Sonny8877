#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    // === Parte 1: Movimento das Peças de Xadrez ===
    int movimentoTorre = 5;
    printf("Movimento da Torre:\n");
    for (int i = 0; i < movimentoTorre; i++) {
        printf("Direita\n");
    }
    printf("\n");

    int movimentoBispo = 5;
    int i = 0;
    printf("Movimento do Bispo:\n");
    while (i < movimentoBispo) {
        printf("Cima Direita\n");
        i++;
    }
    printf("\n");

    int movimentoRainha = 8;
    int j = 0;
    printf("Movimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        j++;
    } while (j < movimentoRainha);
    printf("\n");

    // === Parte 2: Posicionamento de Navios no Tabuleiro ===

    // Inicializando o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = VALOR_AGUA;
        }
    }

    // Navio horizontal (tamanho 3)
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int linhaHorizontal = 2;  // linha inicial do navio horizontal
    int colunaHorizontal = 4; // coluna inicial

    // Validação: garantir que o navio cabe horizontalmente e não colide
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int k = 0; k < TAMANHO_NAVIO; k++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + k] != VALOR_AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int k = 0; k < TAMANHO_NAVIO; k++) {
                tabuleiro[linhaHorizontal][colunaHorizontal + k] = navioHorizontal[k];
            }
        } else {
            printf("Erro: sobreposição ao posicionar navio horizontal!\n");
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro!\n");
    }

    // Navio vertical (tamanho 3)
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};
    int linhaVertical = 5;    // linha inicial
    int colunaVertical = 1;   // coluna inicial

    // Validação: garantir que o navio cabe verticalmente e não colide
    if (linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int k = 0; k < TAMANHO_NAVIO; k++) {
            if (tabuleiro[linhaVertical + k][colunaVertical] != VALOR_AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int k = 0; k < TAMANHO_NAVIO; k++) {
                tabuleiro[linhaVertical + k][colunaVertical] = navioVertical[k];
            }
        } else {
            printf("Erro: sobreposição ao posicionar navio vertical!\n");
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro!\n");
    }

    // Exibir o tabuleiro
    printf("Tabuleiro:\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
