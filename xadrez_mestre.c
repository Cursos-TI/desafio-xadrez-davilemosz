#include <stdio.h>
#include <stdlib.h>

/*
 * Mestre/mestre.C
 * Versão avançada do simulador de movimentos de peças de xadrez.
 * Alterações para o desafio final:
 * - Torre e Rainha: implementadas com funções recursivas (substituem loops simples)
 * - Bispo: movimento diagonal para cima-direita usando loops aninhados
 * - Cavalo: movimento em L (agora para cima e direita) usando loops com múltiplas variáveis
 * - Programa jogável com menu interativo e funcionalidades extras (resumo / reset)
 *
 * Observações de implementação:
 * - Apenas tipos inteiros e cadeias literais são utilizados para os contadores e
 *   configurações de movimento.
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

/* Função recursiva para mover a Torre para a direita.
 * Parâmetros: passos_restantes - número de casas ainda a mover
 * Comportamento: imprime "Direita" a cada chamada até chegar a zero.
 */
void moverTorreRec(int passos_restantes) {
    if (passos_restantes <= 0) return;
    printf("Direita\n");
    contador_torre++;
    moverTorreRec(passos_restantes - 1); // chamada recursiva
}

/* Função recursiva para mover a Rainha para a esquerda.
 * Parâmetros: passos_restantes - número de casas ainda a mover
 */
void moverRainhaRec(int passos_restantes) {
    if (passos_restantes <= 0) return;
    printf("Esquerda\n");
    contador_rainha++;
    moverRainhaRec(passos_restantes - 1);
}

/* Movimento do Bispo usando loops aninhados.
 * Implementação constrói cada passo diagonal ("Cima, Direita") usando um loop
 * externo para controlar o número de casas e um loop interno que imprime as
 * partes da direção separadamente — demonstração de loops aninhados.
 */
void moverBispoNested() {
    int i, parte;
    for (i = 0; i < MOVIMENTO_BISPO; i++) {
        // Loop interno: duas "partes" da diagonal (Cima e Direita)
        for (parte = 0; parte < 2; parte++) {
            if (parte == 0) {
                // imprimimos a primeira parte sem quebrar a linha
                printf("Cima");
            } else {
                // segunda parte: adiciona a vírgula e imprime Direita
                printf(", Direita");
            }
        }
        // fim do passo diagonal
        printf("\n");
        contador_bispo++;
    }
}

/* Movimento do Cavalo em L: agora definido como 1 vez para cima e à direita.
 * Requisitos: utilizar loops com múltiplas variáveis/condições, permitir uso de
 * continue e break. Implementamos dois loops aninhados: um for externo que
 * percorre as "fases" do L e um while interno que realiza os passos de cada
 * fase; o código demonstra continue/break conforme solicitado.
 */
void moverCavaloLoops() {
    int fase, passos, j;
    // uma iteração completa em L: primeira fase = vertical (para cima),
    // segunda fase = horizontal (direita)
    for (fase = 0; fase < 2; fase++) {
        passos = (fase == 0) ? MOVIMENTO_CAVALO_VER : MOVIMENTO_CAVALO_HOR;
        j = 0;

        while (1) {
            if (j >= passos) {
                // já completamos os passos desta fase
                break; // sai do while
            }

            // demonstrando continue: se por algum motivo passos forem zero,
            // pula para a próxima iteração (não ocorre aqui, mas demonstra uso)
            if (passos == 0) {
                j++;
                continue;
            }

            if (fase == 0) {
                printf("Cima\n");
            } else {
                printf("Direita\n");
            }

            // atualiza counters
            contador_cavalo++;

            j++;
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
        printf("=== Simulador Mestre (Avançado) ===\n");
        printf("1 - Mover Torre (recursivo, 5 Direita)\n");
        printf("2 - Mover Bispo (loops aninhados, 5 Cima, Direita)\n");
        printf("3 - Mover Rainha (recursivo, 8 Esquerda)\n");
        printf("4 - Mover Cavalo (1x L: Cima,Cima,Direita com loops)\n");
        printf("5 - Mostrar resumo de movimentos\n");
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
                moverTorreRec(MOVIMENTO_TORRE);
                printf("\nPressione Enter para continuar...");
                getchar(); getchar(); // pausa
                break;
            case 2:
                printf("\n=== Movimento do Bispo ===\n");
                moverBispoNested();
                printf("\nPressione Enter para continuar...");
                getchar(); getchar();
                break;
            case 3:
                printf("\n=== Movimento da Rainha ===\n");
                moverRainhaRec(MOVIMENTO_RAINHA);
                printf("\nPressione Enter para continuar...");
                getchar(); getchar();
                break;
            case 4:
                printf("\n=== Movimento do Cavalo ===\n");
                moverCavaloLoops();
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