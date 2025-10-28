#include <stdio.h>

#define TAM 10       // Tamanho do tabuleiro
#define TAM_NAVIO 3  // Tamanho dos navios
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 1️⃣ Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // -----------------------------
    // 2️⃣ Definição dos navios
    // -----------------------------

    // Navio 1 - Horizontal
    int linhaH = 1;
    int colunaH = 2;

    // Navio 2 - Vertical
    int linhaV = 4;
    int colunaV = 7;

    // Navio 3 - Diagonal principal (↘)
    int linhaD1 = 6;
    int colunaD1 = 1;

    // Navio 4 - Diagonal secundária (↙)
    int linhaD2 = 2;
    int colunaD2 = 8;

    // -----------------------------
    // 3️⃣ Posiciona o Navio Horizontal
    // -----------------------------
    if (colunaH + TAM_NAVIO <= TAM) {
        for (j = 0; j < TAM_NAVIO; j++) {
            if (tabuleiro[linhaH][colunaH + j] == AGUA) {
                tabuleiro[linhaH][colunaH + j] = NAVIO;
            } else {
                printf("Erro: sobreposição detectada (navio horizontal)!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 1;
    }

    // -----------------------------
    // 4️⃣ Posiciona o Navio Vertical
    // -----------------------------
    if (linhaV + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == AGUA) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            } else {
                printf("Erro: sobreposição detectada (navio vertical)!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: navio vertical fora dos limites!\n");
        return 1;
    }

    // -----------------------------
    // 5️⃣ Posiciona o Navio Diagonal ↘ (principal)
    // -----------------------------
    if (linhaD1 + TAM_NAVIO <= TAM && colunaD1 + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == AGUA) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            } else {
                printf("Erro: sobreposição detectada (navio diagonal ↘)!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: navio diagonal ↘ fora dos limites!\n");
        return 1;
    }

    // -----------------------------
    // 6️⃣ Posiciona o Navio Diagonal ↙ (secundária)
    // -----------------------------
    if (linhaD2 + TAM_NAVIO <= TAM && colunaD2 - (TAM_NAVIO - 1) >= 0) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] == AGUA) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            } else {
                printf("Erro: sobreposição detectada (navio diagonal ↙)!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: navio diagonal ↙ fora dos limites!\n");
        return 1;
    }

    // -----------------------------
    // 7️⃣ Exibe o Tabuleiro
    // -----------------------------
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}