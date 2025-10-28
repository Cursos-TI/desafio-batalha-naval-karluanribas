#include <stdio.h>

#define TAM 10       // tamanho do tabuleiro
#define TAM_NAVIO 3  // tamanho dos navios
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 1️⃣ Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2️⃣ Define coordenadas iniciais dos navios
    // Navio horizontal
    int linhaH = 2;  // linha inicial
    int colunaH = 4; // coluna inicial

    // Navio vertical
    int linhaV = 5;  // linha inicial
    int colunaV = 7; // coluna inicial

    // 3️⃣ Valida se os navios cabem no tabuleiro
    if (colunaH + TAM_NAVIO <= TAM && linhaV + TAM_NAVIO <= TAM) {

        // 4️⃣ Posiciona o navio horizontal (mesma linha)
        for (j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linhaH][colunaH + j] = NAVIO;
        }

        // 5️⃣ Posiciona o navio vertical (mesma coluna)
        for (i = 0; i < TAM_NAVIO; i++) {
            // Verifica se já existe navio para evitar sobreposição
            if (tabuleiro[linhaV + i][colunaV] == AGUA) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            } else {
                printf("Erro: sobreposição de navios detectada!\n");
                return 1;
            }
        }

    } else {
        printf("Erro: navios fora dos limites do tabuleiro!\n");
        return 1;
    }

    // 6️⃣ Exibe o tabuleiro
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