#include <stdio.h>

/* 
 * Programa: Simulador de Movimento de Peças de Xadrez
 * Descrição: Este programa simula o movimento de três peças de xadrez:
 * - Torre: 5 casas para a direita (usando for)
 * - Bispo: 5 casas na diagonal superior direita (usando while)
 * - Rainha: 8 casas para a esquerda (usando do-while)
 */

int main() {
    // Constantes para definir o número de movimentos de cada peça
    const int MOVIMENTO_TORRE = 5;
    const int MOVIMENTO_BISPO = 5;
    const int MOVIMENTO_RAINHA = 8;
    
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
    
    return 0;
}
