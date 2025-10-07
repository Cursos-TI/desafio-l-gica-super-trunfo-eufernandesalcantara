#include <stdio.h>
#include <locale.h> // biblioteca para poder usar acentos do portugues


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

    // seção de entrada de dados 

    printf("----Desafio Super Trunfo Logíca----\n");
    printf("----       Nível Novato      ----\n\n");

    // Cadastro das Cartas:

    // cadastro da carta 1 
    printf("-----Cadastro da Carta 1 -----\n");
    printf("Digite uma Letra de 'A' a 'H' : ");
    scanf(" %c", &estado_letra1);
    printf("Digite um número de 01 a 04 (ex: A01, H04) : ");
    scanf("%s", codigo_carta1);
    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade1);
    printf("Difite o número de habitantes da cidade:");
    scanf("%lu", populacao1);
    printf("Digite a Área da cidade (em KM²):");
    scanf("%f", &area1);
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
    printf("Difite o número de habitantes da cidade:");
    scanf("%lu", populacao2);
    printf("Digite a Área da cidade (em KM²):");
    scanf("%f", &area2;
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
    printf("Código: %c%s\n", nome_cidade1);
    
    
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
