#include <stdlib.h>

#define TAM_TAB 10   // Tamanho do tabuleiro
#define TAM_HAB 5    // Tamanho das matrizes de habilidade
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda: 0 = Água | 3 = Navio | 5 = Área de Habilidade\n");
}

// Função genérica para sobrepor uma matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int centro = TAM_HAB / 2; // centro da matriz de habilidade

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha - centro + i;
                int coluna = origemColuna - centro + j;

                // Garante que a habilidade não ultrapasse os limites do tabuleiro
                if (linha >= 0 && linha < TAM_TAB && coluna >= 0 && coluna < TAM_TAB) {
                    if (tabuleiro[linha][coluna] == AGUA) { 
                        tabuleiro[linha][coluna] = HABILIDADE;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    inicializarTabuleiro(tabuleiro);

    // 1️⃣ Posiciona alguns navios fixos (como no nível aventureiro)
    tabuleiro[2][3] = NAVIO; tabuleiro[2][4] = NAVIO; tabuleiro[2][5] = NAVIO; // horizontal
    tabuleiro[5][7] = NAVIO; tabuleiro[6][7] = NAVIO; tabuleiro[7][7] = NAVIO; // vertical
    tabuleiro[6][2] = NAVIO; tabuleiro[7][3] = NAVIO; tabuleiro[8][4] = NAVIO; // diagonal ↘
    tabuleiro[3][8] = NAVIO; tabuleiro[4][7] = NAVIO; tabuleiro[5][6] = NAVIO; // diagonal ↙

    // 2️⃣ Criação das matrizes de habilidade (5x5)
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // --- Matriz Cone ---
    // forma de triângulo apontando para baixo
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i >= j && i + j >= TAM_HAB - 1 - i)
                cone[i][j] = 1;
            else if (i >= 2 && j >= 1 && j <= 3) // garante expansão gradual
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // --- Matriz Cruz ---
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // --- Matriz Octaedro (losango) ---
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // 3️⃣ Define pontos de origem das habilidades no tabuleiro
    int origemConeLinha = 1, origemConeColuna = 2;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctaLinha = 8, origemOctaColuna = 3;

    // 4️⃣ Aplica as habilidades sobre o tabuleiro
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaLinha, origemOctaColuna);

    // 5️⃣ Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
