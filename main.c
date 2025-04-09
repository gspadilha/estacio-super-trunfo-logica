#include <stdio.h>

// Define the attribute options as an enum
enum ATRIBUTOS {
    POPULACAO,
    AREA,
    PIB,
    DENSIDADE,
    PIB_PER_CAPITA
};

int main() {
    // Dados da Carta 1 (pré-definidos)
    char estado1[] = "SP";
    char codigo1[] = "A01";
    char cidade1[] = "São Paulo";
    int populacao1 = 12300000;
    float area1 = 1521.11;
    float pib1 = 699.28; // em bilhões de reais
    int pontos_turisticos1 = 50;

    // Dados da Carta 2 (pré-definidos)
    char estado2[] = "RJ";
    char codigo2[] = "B02";
    char cidade2[] = "Rio de Janeiro";
    int populacao2 = 6748000;
    float area2 = 1200.25;
    float pib2 = 300.50; // em bilhões de reais
    int pontos_turisticos2 = 30;

    // Cálculos para ambas as cartas
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pib_per_capita1 = pib1 / populacao1; // Corrigido: não multiplica por 1e9
    float pib_per_capita2 = pib2 / populacao2;

    // Escolha do atributo para comparação
    const int ATRIBUTO_COMPARACAO = POPULACAO;

    // Variáveis para armazenar o resultado
    int carta_vencedora = 0;
    float valor_carta1 = 0, valor_carta2 = 0;

    // Determinar qual atributo será comparado
    switch(ATRIBUTO_COMPARACAO) {
        case POPULACAO:
            valor_carta1 = populacao1;
            valor_carta2 = populacao2;
            // Maior população vence
            carta_vencedora = (populacao1 > populacao2) ? 1 : 2;
            break;

        case AREA:
            valor_carta1 = area1;
            valor_carta2 = area2;
            // Maior área vence
            carta_vencedora = (area1 > area2) ? 1 : 2;
            break;

        case PIB:
            valor_carta1 = pib1;
            valor_carta2 = pib2;
            // Maior PIB vence
            carta_vencedora = (pib1 > pib2) ? 1 : 2;
            break;

        case DENSIDADE:
            valor_carta1 = densidade1;
            valor_carta2 = densidade2;
            // Menor densidade vence
            carta_vencedora = (densidade1 < densidade2) ? 1 : 2;
            break;

        case PIB_PER_CAPITA:
            valor_carta1 = pib_per_capita1;
            valor_carta2 = pib_per_capita2;
            // Maior PIB per capita vence
            carta_vencedora = (pib_per_capita1 > pib_per_capita2) ? 1 : 2;
            break;

        default:
            printf("Atributo inválido para comparação!\n");
            return 1;
    }

    // Exibir informações das cartas
    printf("Carta 1: %s (%s)\n", cidade1, estado1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", pib1);
    printf("Densidade: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: %.2f reais\n", pib_per_capita1);
    printf("Pontos turísticos: %d\n\n", pontos_turisticos1);

    printf("Carta 2: %s (%s)\n", cidade2, estado2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", pib2);
    printf("Densidade: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: %.2f reais\n", pib_per_capita2);
    printf("Pontos turísticos: %d\n\n", pontos_turisticos2);

    // Exibir resultado da comparação
    printf("Comparação de cartas (Atributo: ");

    switch(ATRIBUTO_COMPARACAO) {
        case POPULACAO: printf("População"); break;
        case AREA: printf("Área"); break;
        case PIB: printf("PIB"); break;
        case DENSIDADE: printf("Densidade Populacional"); break;
        case PIB_PER_CAPITA: printf("PIB per Capita"); break;
    }

    printf("):\n");
    printf("Carta 1 - %s (%s): %.2f\n", cidade1, estado1, valor_carta1);
    printf("Carta 2 - %s (%s): %.2f\n", cidade2, estado2, valor_carta2);

    if (carta_vencedora == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    }

    return 0;
}
