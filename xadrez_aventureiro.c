#include <stdio.h>

/* 
 * Programa: Simulador de Movimento de Peças de Xadrez
 * Descrição: Este programa simula o movimento de quatro peças de xadrez:
 * - Torre: 5 casas para a direita (usando for)
 * - Bispo: 5 casas na diagonal superior direita (usando while)
 * - Rainha: 8 casas para a esquerda (usando do-while)
 * - Cavalo: movimento em L - 2 casas para baixo e 1 para esquerda (usando loops aninhados)
 */

int main() {
    // Constantes para definir o número de movimentos de cada peça
    const int MOVIMENTO_TORRE = 5;
    const int MOVIMENTO_BISPO = 5;
    const int MOVIMENTO_RAINHA = 8;
    const int MOVIMENTO_CAVALO_VERTICAL = 2;   // Movimento vertical do cavalo (para baixo)
    const int MOVIMENTO_CAVALO_HORIZONTAL = 1; // Movimento horizontal do cavalo (para esquerda)
    
    // Variáveis para controle dos loops
    int i;
    
    // Simulação do movimento da Torre (5 casas para a direita)
    printf("\n=== Movimento da Torre ===\n");
    for(i = 0; i < MOVIMENTO_TORRE; i++) {
        printf("Direita\n");
    }
    
    // Simulação do movimento do Bispo (5 casas na diagonal superior direita)
    printf("\n=== Movimento do Bispo ===\n");
    i = 0;
    while(i < MOVIMENTO_BISPO) {
        printf("Cima, Direita\n");
        i++;
    }
    
    // Simulação do movimento da Rainha (8 casas para a esquerda)
    printf("\n=== Movimento da Rainha ===\n");
    i = 0;
    do {
        printf("Esquerda\n");
        i++;
    } while(i < MOVIMENTO_RAINHA);

    // Simulação do movimento do Cavalo (2 casas para baixo e 1 para esquerda)
    printf("\n=== Movimento do Cavalo ===\n");
    printf("Movimento em L: duas casas para baixo e uma para esquerda\n\n");
    
    // Loop externo (for) para controlar as direções do movimento em L
    for(i = 0; i < 2; i++) {  // 2 direções diferentes no movimento em L
        int movimentos = (i == 0) ? MOVIMENTO_CAVALO_VERTICAL : MOVIMENTO_CAVALO_HORIZONTAL;
        int j = 0;
        
        // Loop interno (do-while) para executar os movimentos em cada direção
        do {
            // Primeiro conjunto de movimentos (i=0) é para baixo
            // Segundo conjunto de movimentos (i=1) é para esquerda
            printf("%s\n", (i == 0) ? "Baixo" : "Esquerda");
            j++;
        } while(j < movimentos);
    }
    
    return 0;
}