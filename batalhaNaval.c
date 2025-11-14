#include <stdio.h>

#define TAM 10
#define AGUA 0
#define NAVIO 3

// Função para mostrar o campo
void mostrarCampo(int campo[TAM][TAM]) {
    int coluna = 1; 
    for (int i = 0; i < TAM; i++) {
       
        // verifica espaço por causa de decimal 10 
        if (coluna != 10)
        {
            printf(" %d ", coluna);
            coluna ++;
        }else{
            printf("%d ", coluna);
            coluna ++;
        }

        // mostra o campo
        for (int j = 0; j < TAM; j++) {
            printf("%d ", campo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Verifica se pode colocar um navio horizontalmente (sem colisão)
int podeColocarHorizontal(int campo[TAM][TAM], int linha, int colInicio) {
    if (colInicio + 2 >= TAM) return 0; // evita sair da matriz
    for (int j = colInicio; j < colInicio + 3; j++) {
        if (campo[linha][j] != AGUA) return 0; // já tem navio
    }
    return 1; // está livre
}

// Coloca navio horizontal
void colocarHorizontal(int campo[TAM][TAM], int linha, int colInicio) {
    for (int j = colInicio; j < colInicio + 3; j++) {
        campo[linha][j] = NAVIO;
    }
}

// Verifica se pode colocar navio vertical
int podeColocarVertical(int campo[TAM][TAM], int linInicio, int coluna) {
    if (linInicio + 2 >= TAM) return 0;
    for (int i = linInicio; i < linInicio + 3; i++) {
        if (campo[i][coluna] != AGUA) return 0;
    }
    return 1;
}

// Coloca navio vertical
void colocarVertical(int campo[TAM][TAM], int linInicio, int coluna) {
    for (int i = linInicio; i < linInicio + 3; i++) {
        campo[i][coluna] = NAVIO;
    }
}

// Verifica se pode colocar navio diagonal (↘)
int podeColocarDiagonalPrincipal(int campo[TAM][TAM], int linInicio, int colInicio) {
    if (linInicio + 2 >= TAM || colInicio + 2 >= TAM) return 0;
    for (int i = 0; i < 3; i++) {
        if (campo[linInicio + i][colInicio + i] != AGUA) return 0;
    }
    return 1;
}

// Coloca navio diagonal ↘
void colocarDiagonalPrincipal(int campo[TAM][TAM], int linInicio, int colInicio) {
    for (int i = 0; i < 3; i++) {
        campo[linInicio + i][colInicio + i] = NAVIO;
    }
}

// Verifica se pode colocar navio diagonal (↙)
int podeColocarDiagonalSecundaria(int campo[TAM][TAM], int linInicio, int colInicio) {
    if (linInicio + 2 >= TAM || colInicio - 2 < 0) return 0;
    for (int i = 0; i < 3; i++) {
        if (campo[linInicio + i][colInicio - i] != AGUA) return 0;
    }
    return 1;
}

// Coloca navio diagonal ↙
void colocarDiagonalSecundaria(int campo[TAM][TAM], int linInicio, int colInicio) {
    for (int i = 0; i < 3; i++) {
        campo[linInicio + i][colInicio - i] = NAVIO;
    }
}

int main() {
    int campo[TAM][TAM];
    int i, j;


    // Inicializa o campo com água
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            campo[i][j] = AGUA;
        }
    }

    // Coloca alguns navios com verificação
    if (podeColocarHorizontal(campo, 2, 4))
        colocarHorizontal(campo, 2, 4);

    if (podeColocarVertical(campo, 5, 7))
        colocarVertical(campo, 5, 7);

    if (podeColocarDiagonalPrincipal(campo, 0, 0))
        colocarDiagonalPrincipal(campo, 0, 0);

    if (podeColocarDiagonalSecundaria(campo, 0, 9))
        colocarDiagonalSecundaria(campo, 0, 9);

    printf("TABULEIRO DE BATALHA NATAVAL\n\n");
    printf("   A B C D E F G H I J\n");
    mostrarCampo(campo);

    return 0;
}
