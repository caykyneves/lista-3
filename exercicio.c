
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
} Produto;

void inicializarEstoque(Produto *estoque, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        estoque[i].codigo = 0;
        strcpy(estoque[i].descricao, "");
        estoque[i].quantidade = 0;
        estoque[i].valor = 0.0;
    }
}

void adicionarProduto(Produto *estoque, int tamanho)
{
    int codigo;
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < tamanho; i++)
    {
        if (estoque[i].codigo == codigo)
        {
            printf("Produto ja cadastrado.\n");
            return;
        }
    }

    for (int i = 0; i < tamanho; i++)
    {
        if (estoque[i].codigo == 0)
        {
            estoque[i].codigo = codigo;
            printf("Digite a descricao: ");
            scanf("%s", estoque[i].descricao);
            printf("Digite a quantidade: ");
            scanf("%d", &estoque[i].quantidade);
            printf("Digite o valor: ");
            scanf("%f", &estoque[i].valor);
            printf("Produto cadastrado com sucesso.\n");
            return;
        }
    }
    printf("Estoque cheio. Nao foi possivel cadastrar o produto.\n");
}

void imprimirRelatorio(Produto *estoque, int tamanho)
{
    printf("\nRelatorio de Produtos:\n");
    printf("Codigo | Descricao | Quantidade | Valor\n");
    for (int i = 0; i < tamanho; i++)
    {
        if (estoque[i].codigo != 0)
        {
            printf("%d | %s | %d | %.2f\n", estoque[i].codigo, estoque[i].descricao, estoque[i].quantidade, estoque[i].valor);
        }
    }
}

void pesquisarProduto(Produto *estoque, int tamanho)
{
    int codigo;
    printf("Digite o codigo do produto a ser pesquisado: ");
    scanf("%d", &codigo);

    for (int i = 0; i < tamanho; i++)
    {
        if (estoque[i].codigo == codigo)
        {
            printf("Codigo: %d | Descricao: %s | Quantidade: %d | Valor: %.2f\n", estoque[i].codigo, estoque[i].descricao, estoque[i].quantidade, estoque[i].valor);
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void removerProduto(Produto *estoque, int tamanho)
{
    int codigo;
    printf("Digite o codigo do produto a ser removido: ");
    scanf("%d", &codigo);

    for (int i = 0; i < tamanho; i++)
    {
        if (estoque[i].codigo == codigo)
        {
            estoque[i].codigo = 0;
            strcpy(estoque[i].descricao, "");
            estoque[i].quantidade = 0;
            estoque[i].valor = 0.0;
            printf("Produto removido do estoque.\n");
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

int main()
{
    int opcao;
    Produto estoque[100];

    inicializarEstoque(estoque, 100);

    do
    {
        printf("\nMenu:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Imprimir Relatorio de Produtos\n");
        printf("3. Pesquisar Produto\n");
        printf("4. Remover Produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionarProduto(estoque, 100);
            break;
        case 2:
            imprimirRelatorio(estoque, 100);
            break;
        case 3:
            pesquisarProduto(estoque, 100);
            break;
        case 4:
            removerProduto(estoque, 100);
            break;
        case 0:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}