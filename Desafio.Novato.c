#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[50];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;

    // Campos calculados
    float densidade_populacional;
    float pib_per_capita;
} Carta;

int main() {
    // Definindo duas cartas com dados fixos
    Carta carta1 = {
        "São Paulo",
        "SP01",
        "São Paulo",
        12300000,
        1521.11,
        700000.0,
        20,
        0, 0
    };

    Carta carta2 = {
        "Rio de Janeiro",
        "RJ01",
        "Rio de Janeiro",
        6000000,
        1182.3,
        400000.0,
        15,
        0, 0
    };

    // Calculando densidade populacional e PIB per capita para ambas as cartas
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta1.pib_per_capita = carta1.pib / carta1.populacao;

    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;

    // Escolha do atributo para comparação (alterar aqui para comparar outro atributo)
    // Opções: 1-População, 2-Área, 3-PIB, 4-Densidade Populacional, 5-PIB per capita
    int atributo_escolhido = 1;

    // Variáveis para armazenar os valores dos atributos escolhidos
    float valor_carta1, valor_carta2;

    // Definir valores dos atributos escolhidos
    switch (atributo_escolhido) {
        case 1:
            valor_carta1 = carta1.populacao;
            valor_carta2 = carta2.populacao;
            break;
        case 2:
            valor_carta1 = carta1.area;
            valor_carta2 = carta2.area;
            break;
        case 3:
            valor_carta1 = carta1.pib;
            valor_carta2 = carta2.pib;
            break;
        case 4:
            valor_carta1 = carta1.densidade_populacional;
            valor_carta2 = carta2.densidade_populacional;
            break;
        case 5:
            valor_carta1 = carta1.pib_per_capita;
            valor_carta2 = carta2.pib_per_capita;
            break;
        default:
            printf("Atributo inválido.\n");
            return 1;
    }

    // Nome do atributo para exibir no resultado
    char nome_atributo[30];
    switch (atributo_escolhido) {
        case 1: strcpy(nome_atributo, "População"); break;
        case 2: strcpy(nome_atributo, "Área"); break;
        case 3: strcpy(nome_atributo, "PIB"); break;
        case 4: strcpy(nome_atributo, "Densidade Populacional"); break;
        case 5: strcpy(nome_atributo, "PIB per capita"); break;
    }

    // Exibindo os valores calculados e o atributo
    printf("Comparação de cartas (Atributo: %s):\n\n", nome_atributo);

    if (atributo_escolhido == 1) {
        // População é inteiro, exibir formatado com vírgula
        printf("Carta 1 - %s (%s): %d\n", carta1.nome_cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n\n", carta2.nome_cidade, carta2.estado, carta2.populacao);
    } else {
        // Outros atributos em float
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nome_cidade, carta1.estado, valor_carta1);
        printf("Carta 2 - %s (%s): %.2f\n\n", carta2.nome_cidade, carta2.estado, valor_carta2);
    }

    // Regras de vitória:
    // Para densidade populacional, quem tiver o menor valor vence
    // Para os outros, maior valor vence

    if (atributo_escolhido == 4) {
        // Menor vence
        if (valor_carta1 < valor_carta2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (valor_carta2 < valor_carta1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        // Maior vence
        if (valor_carta1 > valor_carta2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (valor_carta2 > valor_carta1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}
