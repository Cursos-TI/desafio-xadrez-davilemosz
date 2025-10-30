#include <stdio.h>
#include <stdlib.h>

/* 
 * Programa: Simulador de Movimento de Peças de Xadrez
 * Descrição: Este programa simula o movimento de quatro peças de xadrez:
 * - Torre: 5 casas para a direita (usando recursão)
 * - Bispo: 5 casas na diagonal superior direita (usando loops aninhados)
 * - Rainha: 8 casas para a esquerda (usando recursão)
 * - Cavalo: movimento em L - 2 casas para cima e 1 para direita (usando loops aninhados)
 */

// Constantes de movimento (definidas em código conforme requerido)
const int MOVIMENTO_TORRE = 5;     // 5 casas para a direita
const int MOVIMENTO_BISPO = 5;     // 5 casas na diagonal superior direita
const int MOVIMENTO_RAINHA = 8;    // 8 casas para a esquerda
const int MOVIMENTO_CAVALO_VER = 2; // Cavalo: 2 casas verticalmente (para cima)
const int MOVIMENTO_CAVALO_HOR = 1; // Cavalo: 1 casa horizontalmente (para direita)

// Contadores de passos realizados (resumo)
int contador_torre = 0;
int contador_bispo = 0;
int contador_rainha = 0;
int contador_cavalo = 0;

// Função para limpar a tela (Windows)
void limparTela() {
    system("cls");
}

/* Função recursiva para mover a Torre */
void moverTorre(int passos) {
    if (passos <= 0) return;
    printf("Direita\n");
    contador_torre++;
    moverTorre(passos - 1);
}

/* Função recursiva para mover a Rainha */
void moverRainha(int passos) {
    if (passos <= 0) return;
    printf("Esquerda\n");
    contador_rainha++;
    moverRainha(passos - 1);
}

/* Movimento do Bispo usando loops aninhados.
 * Implementação constrói cada passo diagonal ("Cima, Direita") usando um loop
 * externo para controlar o número de casas e um loop interno que imprime as
 * partes da direção separadamente — demonstração de loops aninhados.
 */
/* Movimento do Bispo usando loops aninhados */
void moverBispo() {
    // Loop externo: controla número de movimentos diagonais
    for (int i = 0; i < MOVIMENTO_BISPO; i++) {
        // Loop interno: controla as direções do movimento diagonal
        for (int dir = 0; dir < 2; dir++) {
            printf("%s%s", dir == 0 ? "Cima" : ", Direita", dir == 1 ? "\n" : "");
        }
        contador_bispo++;
    }
}

/* Movimento do Cavalo usando loops aninhados e controle de fluxo */
void moverCavalo() {
    int direcoes_completadas = 0;
    
    // Loop externo: controla as fases do movimento em L
    for (int fase = 0; fase < 2 && direcoes_completadas < 3; fase++) {
        int movimentos_necessarios = (fase == 0) ? 2 : 1; // 2 para cima, 1 para direita
        int movimentos_feitos = 0;
        
        // Loop interno: realiza os movimentos de cada fase
        while (1) {
            // Verifica se completou os movimentos desta fase
            if (movimentos_feitos >= movimentos_necessarios) {
                break;
            }
            
            // Se já fez todos os movimentos necessários, sai
            if (direcoes_completadas >= 3) {
                continue;
            }
            
            // Executa o movimento
            printf("%s\n", fase == 0 ? "Cima" : "Direita");
            movimentos_feitos++;
            direcoes_completadas++;
            contador_cavalo++;
        }
    }
}

// Mostra um resumo simples das movimentações realizadas
void mostrarResumo() {
    printf("\n--- Resumo de movimentos realizados ---\n");
    printf("Torre: %d passos\n", contador_torre);
    printf("Bispo: %d passos\n", contador_bispo);
    printf("Rainha: %d passos\n", contador_rainha);
    printf("Cavalo: %d passos\n", contador_cavalo);
    printf("--------------------------------------\n\n");
}

// Reseta os contadores
void resetResumo() {
    contador_torre = contador_bispo = contador_rainha = contador_cavalo = 0;
}



int main() {
    int opcao = 0;

    do {
        limparTela();
        printf("=== Simulador de Xadrez ===\n");
        printf("1 - Mover Torre (recursivo)\n");
        printf("2 - Mover Bispo (loops aninhados)\n");
        printf("3 - Mover Rainha (recursivo)\n");
        printf("4 - Mover Cavalo (loops aninhados)\n");
        printf("5 - Mostrar resumo\n");
        printf("6 - Resetar resumo\n");
        printf("7 - Sair\n");
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1) {
            // entrada inválida: limpa stdin e continua
            int c;
            while ((c = getchar()) != '\n' && c != EOF) ;
            opcao = 0;
        }

        switch (opcao) {
            case 1:
                printf("\n=== Movimento da Torre ===\n");
                moverTorre(MOVIMENTO_TORRE);
                printf("\nPressione Enter para continuar...");
                getchar(); getchar();
                break;
            case 2:
                printf("\n=== Movimento do Bispo ===\n");
                moverBispo();
                printf("\nPressione Enter para continuar...");
                getchar(); getchar();
                break;
            case 3:
                printf("\n=== Movimento da Rainha ===\n");
                moverRainha(MOVIMENTO_RAINHA);
                printf("\nPressione Enter para continuar...");
                getchar(); getchar();
                break;
            case 4:
                printf("\n=== Movimento do Cavalo ===\n");
                moverCavalo();
                printf("\nPressione Enter para continuar...");
                getchar(); getchar();
                break;
            case 5:
                mostrarResumo();
                printf("Pressione Enter para continuar...");
                getchar(); getchar();
                break;
            case 6:
                resetResumo();
                printf("Resumo resetado. Pressione Enter para continuar...");
                getchar(); getchar();
                break;
            case 7:
                printf("\nEncerrando...\n");
                break;
            default:
                if (opcao != 0) {
                    printf("\nOpcao invalida. Pressione Enter para continuar...");
                    getchar(); getchar();
                }
        }

    } while (opcao != 7);

    return 0;
}