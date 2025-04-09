#include <stdio.h>

// Estruturas para armazenar os dados das cartas
struct {
    char estado[2];
    char cidade[30];
    int populacao;
    float area;
    float pib; // em bilhões de reais
    int pontos_turisticos;
    float densidade; // hab/km²
} carta1, carta2;

// Dados da Carta 1 (São Paulo)
void carregar_carta1() {
    carta1.estado[0] = 'S';
    carta1.estado[1] = 'P';
    strcpy(carta1.cidade, "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11f;
    carta1.pib = 699.28f; // em bilhões de reais
    carta1.pontos_turisticos = 50;
    carta1.densidade = carta1.populacao / carta1.area;
}

// Dados da Carta 2 (Rio de Janeiro)
void carregar_carta2() {
    carta2.estado[0] = 'R';
    carta2.estado[1] = 'J';
    strcpy(carta2.cidade, "Rio de Janeiro");
    carta2.populacao = 6748000;
    carta2.area = 1200.25f;
    carta2.pib = 300.50f; // em bilhões de reais
    carta2.pontos_turisticos = 30;
    carta2.densidade = carta2.populacao / carta2.area;
}

// Menu interativo para escolha do atributo a ser comparado
void menu() {
    printf("\n");
    printf("Super Trunfo - Nível Aventureiro\n");
    printf("Por favor, escolha o atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Densidade Demográfica\n");
    printf("5. Pontos Turísticos\n");
    printf("\nOpção: ");
}

// Funções para exibição de informações
void imprimir_carta(struct carta dados, char mensagem[]) {
    printf("%s: %s (%s)\n", dados.cidade, dados.estado[0], dados.estado[1]);
    printf("População: %d\n", dados.populacao);
    printf("Área: %.2f km²\n", dados.area);
    printf("PIB: %.2f bilhões\n", dados.pib);
    printf("Densidade: %.2f hab/km²\n", dados.densidade);
    printf("Pontos turísticos: %d\n\n", dados.pontos_turisticos);
}

// Função para determinar o vencedor
int comparar_attrato(struct carta carta1, struct carta carta2, int atributo) {
    float valor1 = 0, valor2 = 0;
    char ganhador[30];

    switch(attributo) {
        case 1: // População
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            break;
        case 2: // Área
            valor1 = carta1.area;
            valor2 = carta2.area;
            break;
        case 3: // PIB
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            break;
        case 4: // Densidade Demográfica
            valor1 = carta1.densidade;
            valor2 = carta2.densidade;
            if (valor1 < valor2) {
                ganhador[0] = ' ';
                ganhador[1] = '1';
            } else if (valor2 < valor1) {
                ganhador[0] = ' ';
                ganhador[1] = '2';
            } else {
                printf("Empate na densidade!\n");
                return 0;
            }
            break;
        case 5: // Pontos Turísticos
            valor1 = carta1.pontos_turisticos;
            valor2 = carta2.pontos_turisticos;
            if (valor1 > valor2) {
                ganhador[0] = ' ';
                ganhador[1] = '1';
            } else if (valor2 > valor1) {
                ganhador[0] = ' ';
                ganhador[1] = '2';
            } else {
                printf("Empate nos pontos turísticos!\n");
                return 0;
            }
            break;
        default:
            printf("Atributo inválido!\n");
            return -1;
    }

    if (ganhador[0] == ' ') {
        printf("Carta %s venceu!\n", ganhador);
    } else {
        printf("Resultados:\n");
        imprimir_carta(carta1, "Carta 1");
        imprimir_carta(carta2, "Carta 2");
        if (ganhador[0] == '1') {
            printf("Carta 1 (%s) venceu!\n", carta1.cidade);
        } else {
            printf("Carta 2 (%s) venceu!\n", carta2.cidade);
        }
    }

    return ganhador[1] - '0';
}

// Main function
int main() {
    // Carregar dados iniciais
    carregar_carta1();
    carregar_carta2();

    // Escolha do atributo
    int atributo_escolhido;
    do {
        menu();
        scanf("%d", &atributo_escolhido);
        if (attributo_escolhido < 1 || attributo_escolhido > 5) {
            printf("Opção inválida! Digite novamente:\n");
        }
    } while (attributo_escolhido < 1 || attributo_escolhido > 5);

    // Comparar e exibir resultado
    int resultador = comparar_attrato(carta1, carta2, atributo_escolhido);

    return 0;
}
