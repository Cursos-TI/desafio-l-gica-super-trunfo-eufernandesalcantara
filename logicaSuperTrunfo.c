#include <stdio.h>
#include <locale.h> // biblioteca para poder usar acentos do portugues
#include <string.h> // biblioteca para manipulação de strings

// Desafio Super Trunfo - Países
// Tema 1 - 🚩 Objetivos:
// Cadastro de Cartas: O sistema permitirá ao usuário cadastrar cartas de cidades, 
// incluindo informações como estado, código da carta, nome da cidade, população, 
//área, PIB e número de pontos turísticos.
//Comparação de Cartas: O sistema comparará os atributos de duas cartas e determinará 
//a vencedora com base em uma propriedade específica (população, área, PIB, etc.), escolhida no código.
// Exibição de Resultados: Após a comparação, o sistema exibirá qual carta venceu 
// com base na regra: maior valor vence, exceto em densidade populacional, onde o menor valor é o vencedor.
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // adiciona suporte à acentuação em português
    setlocale(LC_ALL, "Portuguese");
    
    // Definição das variáveis para armazenar as propriedades das cidades
    
    // variavel da carta 1
    char estado_letra1;
    char codigo_carta1[4];
    char nome_cidade1[100];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;

    // variaveis calculadas

    float densidade_populacional1;
    float pib_per_capita1;

    // variavel da carta 2
    char estado_letra2;
    char codigo_carta2[4];
    char nome_cidade2[100];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;

    // variaveis calculadas

    float densidade_populacional2;
    float pib_per_capita2;

    // variaveis do nivel mestre
    int opcao_batalha1, opcao_batalha2;
    char nome_attr1[100], nome_attr2[100]; // armazena o nome dos atributos escolhidos
    float valor_attr1_carta1 = 0, valor_attr2_carta1 = 0;// valores dos atributos para carta 1
    float valor_attr1_carta2 = 0, valor_attr2_carta2 = 0;// valores dos atributos para carta 2
    float soma_carta1, soma_carta2; // soma finais para comparação

    
    // seção de entrada de dados 

    printf("----Desafio Super Trunfo Logíca----\n");
    printf("----       Nível Mestre----\n\n");

    // Cadastro das Cartas:

    // cadastro da carta 1 
    printf("-----Cadastro da Carta 1 -----\n");
    printf("Digite uma Letra de 'A' a 'H' : ");
    scanf(" %c", &estado_letra1);
    printf("Digite um número de 01 a 04 (ex: A01, H04) : ");
    scanf("%s", codigo_carta1);
    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade1);
    printf("Digite o número de habitantes da cidade:");
    scanf("%lu", &populacao1);
    printf("Digite a Área da cidade (em KM²):");
    scanf("%f", &area1);
     printf("Digite o PIB da cidade (em bilhoes): ");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turisticos: ");
    scanf("%d", &pontos_turisticos1);
    printf("\n");

     // cadastro da carta 2 
    printf("-----Cadastro da Carta 2 -----\n");
    printf("Digite uma Letra de 'A' a 'H' : ");
    scanf(" %c", &estado_letra2);
    printf("Digite um número de 01 a 04 (ex: A01, H04) : ");
    scanf("%s", codigo_carta2);
    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade2);
    printf("Digite o número de habitantes da cidade:");
    scanf("%lu", &populacao2);
    printf("Digite a Área da cidade (em KM²):");
    scanf("%f", &area2);
    printf("Digite o PIB da cidade (em bilhoes): ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turisticos: ");
    scanf("%d", &pontos_turisticos2);
    printf("\n");

    // -- Seção de Cáculo -- 
    
    // Cáculo para a Carta 1

    densidade_populacional1 = populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000) / populacao1;

     // Cáculo para a Carta 2

    densidade_populacional2 = populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000) / populacao2;

    // -- seção de exibição de dados -- 

    // Dados da Carta 1 

    printf("------------------------------\n");
    printf("Dados Cadastrados\n");
    printf("------------------------------\n");
    printf("Carta1:\n");
    printf("Código: %c%s\n", estado_letra1, codigo_carta1);
    printf("Nome da Cidade: %s\n", nome_cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f KM²\n", area1);
    printf("PIB: R$ %.2f bilhões\n", pib1);
    printf("Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/KM²\n", densidade_populacional1);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita1);
 
        // Dados da Carta 2 

    printf("------------------------------\n");
    printf("Dados Cadastrados\n");
    printf("------------------------------\n");
    printf("Carta2:\n");
    printf("Código: %c%s\n", estado_letra2, codigo_carta2);
    printf("Nome da Cidade: %s\n", nome_cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f KM²\n", area2);
    printf("PIB: R$ %.2f bilhões\n", pib2);
    printf("Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/KM²\n", densidade_populacional2);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita2);
    
    
    // batalha de cartas interativa

    printf("\n---- HORA DA BATALHA! ----\n");
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área (KM²)\n");
    printf("3 - PIB (em bilhões)\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("Digite sua escolha (1-5): \n");

    // recebe a opção de batalha da carta 1
    scanf("%d", &opcao_batalha1);

   // escolha do segundo atributo (menu dinamico)
    do {
        printf("Escolha o segundo atributo para comparar (diferente do primeiro):\n");
        if (opcao_batalha1 != 1) printf("1 - População\n");
        if (opcao_batalha1 != 2) printf("2 - Área ( KM²)\n");
        if (opcao_batalha1 != 3) printf("3 - PIB (  em bilhões)\n");
        if (opcao_batalha1 != 4) printf("4 - Pontos Turísticos\n");
        if (opcao_batalha1 != 5) printf("5 - Densidade Populacional (menor vence)\n");
        printf("Digite sua escolha: \n");
        scanf("%d", &opcao_batalha2);
        
        if (opcao_batalha2 == opcao_batalha1){
            printf("Opção inválida! Você já escolheu esse atributo. Tente novamente.\n");
            }
        
       
    } while (opcao_batalha2 == opcao_batalha1);

     // nova logica
     // switch para o atributo
     switch (opcao_batalha1) {
        case 1: strcpy(nome_attr1, "População");
                valor_attr1_carta1 = populacao1;
                valor_attr1_carta2 = populacao2;
                break;
        case 2: strcpy(nome_attr1, "Área");
                valor_attr1_carta1 = area1;
                valor_attr1_carta2 = area2;
                break;
        case 3: strcpy(nome_attr1, "PIB");
                valor_attr1_carta1 = pib1;
                valor_attr1_carta2 = pib2;
                break;
        case 4: strcpy(nome_attr1, "Pontos Turísticos");
                valor_attr1_carta1 = pontos_turisticos1;
                valor_attr1_carta2 = pontos_turisticos2;
                break;
        case 5: strcpy(nome_attr1, "Densidade Populacional");
                valor_attr1_carta1 = densidade_populacional1;
                valor_attr1_carta2 = densidade_populacional2;
                break;
     }
        switch (opcao_batalha2) {
        case 1: strcpy(nome_attr2, "População");
                valor_attr2_carta1 = populacao1;
                valor_attr2_carta2 = populacao2;
                break;
        case 2: strcpy(nome_attr2, "Área");
                valor_attr2_carta1 = area1;
                valor_attr2_carta2 = area2;
                break;
        case 3: strcpy(nome_attr2, "PIB");
                valor_attr2_carta1 = pib1;
                valor_attr2_carta2 = pib2;
                break;
        case 4: strcpy(nome_attr2, "Pontos Turísticos");
                valor_attr2_carta1 = pontos_turisticos1;
                valor_attr2_carta2 = pontos_turisticos2;
                break;
        case 5: strcpy(nome_attr2, "Densidade Populacional");
                valor_attr2_carta1 = densidade_populacional1;
                valor_attr2_carta2 = densidade_populacional2;
                break;
     }
        // soma dos valores dos atributos escolhidos
        soma_carta1 = valor_attr1_carta1 + valor_attr2_carta1;
        soma_carta2 = valor_attr1_carta2 + valor_attr2_carta2;

        // exibição dos resultados
        printf("\n--- Resultado da Batalha ---\n");
        printf("Atributos escolhidos: \n %s e %s\n", nome_attr1, nome_attr2);
        printf("-----------------------------------------------\n");
        printf("Carta 1 - %s\n", nome_cidade1);
        printf("%s: %.2f\n", nome_attr1, valor_attr1_carta1);
        printf("%s: %.2f\n", nome_attr2, valor_attr2_carta1);
        printf(" SOMA TOTAL = %.2f\n", soma_carta1);
        printf("-----------------------------------------------\n");
        printf("Carta 2 - %s\n", nome_cidade2);
        printf("%s: %.2f\n", nome_attr1, valor_attr1_carta2);
        printf("%s: %.2f\n", nome_attr2, valor_attr2_carta2);
        printf(" SOMA TOTAL = %.2f\n", soma_carta2);
        printf("-----------------------------------------------\n");

        // Nova lógica para declaração do vencedor
    
    if (soma_carta1 > soma_carta2) {
        printf("\n Vencedor: Carta 1 (%s) vence com a maior soma! \n", nome_cidade1);
    } else if (soma_carta2 > soma_carta1) {
        printf("\n Vencedor: Carta 2 (%s) vence com a maior soma! \n", nome_cidade2);
    } else {
        printf("\nResultado: Empate!\n");
    }

    printf("\n ------- FIM DE JOGO -------\n");

    /*
       // acões do menu 
    switch (opcao_batalha) {
        case 1: // escolheu População
            printf("\n--- Comparando por: População ---\n");
            printf("Carta 1 (%s): %lu habitantes\n", nome_cidade1, populacao1);
            printf("Carta 2 (%s): %lu habitantes\n", nome_cidade2, populacao2);
        if (populacao1 > populacao2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", nome_cidade1);
        } else if (populacao2 > populacao1) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", nome_cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
        break; // Fim do caso 1  
    
        case 2: // escolheu Área
            printf("\n--- Comparando por: Área ---\n");
            printf("Carta 1 (%s): %.2f KM²\n", nome_cidade1, area1);
            printf("Carta 2 (%s): %.2f KM²\n", nome_cidade2, area2);
        if (area1 > area2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", nome_cidade1);
        } else if (area2 > area1) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", nome_cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
        break; // Fim do caso 2
        
        case 3: // escolheu PIB
            printf("\n--- Comparando por: PIB ---\n");
            printf("Carta 1 (%s): %.2f bilhões\n", nome_cidade1, pib1);
            printf("Carta 2 (%s): %.2f bilhões\n", nome_cidade2, pib2);
        if (pib1 > pib2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", nome_cidade1);
        } else if (pib2 > pib1) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", nome_cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
        break; // Fim do caso 3
    // caso 4: Comparação por pontos Turísticos
        case 4:
            printf("\n--- Comparando por: Pontos Turísticos ---\n");
            printf("Carta 1 (%s): %d pontos\n", nome_cidade1, pontos_turisticos1);
            printf("Carta 2 (%s): %d pontos\n", nome_cidade2, pontos_turisticos2);
        if (pontos_turisticos1 > pontos_turisticos2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", nome_cidade1);
        } else if (pontos_turisticos2 > pontos_turisticos1) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", nome_cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
        break; // Fim do caso 4

        // caso 5: Comparação por Densidade Populacional (Regra invertida)
        case 5:
            printf("\n--- Comparando por: Densidade Populacional (Menor vence!) ---\n");
            printf("Carta 1 (%s): %.2f hab/KM²\n", nome_cidade1, densidade_populacional1);
            printf("Carta 2 (%s): %.2f hab/KM²\n", nome_cidade2, densidade_populacional2);
        if (densidade_populacional1 < densidade_populacional2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", nome_cidade1);
        } else if (densidade_populacional2 < densidade_populacional1) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", nome_cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
        break; // Fim do caso 5
        // Caso o usuário digite uma opção inválida
        default:
        printf("\nOpção inválida! Por favor, escolha um número de 1 a 5. \n");
        break;
    }
    printf("\n-------- FIM DE JOGO -------\n"); */
   
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}
