#include <stdio.h>

int main(){
    int tabuleiro [10][10];
    int coluna = 1;

    //Gera um tabuleiro 10x10 com zero em todas as linhas e colunas
    printf("TABULEIRO DE BATALHA NATAVAL\n\n");
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++)
    {
        // condição pra arrumar o espaço do 10
        if (coluna != 10)
        {
            printf(" %d", coluna);
            coluna ++;
        }else{
            printf("%d", coluna);
            coluna ++;
        }

        for (int j = 0; j < 10; j++)
        {    
            // condição para colocar os navios
            if ((i == 8 && (j >= 3 && j <=5 )) || (j == 2 && (i >= 5 && i <=7 )))
            {
                tabuleiro[i][j] = 3;
                printf(" %d", tabuleiro[i][j]);
            }else{

                tabuleiro[i][j] = 0;
                printf(" %d", tabuleiro[i][j]);
            }           
            
        }   
        printf("\n");
        
    }
     
}