#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    char dp[50];
    float preco;
} Produto;

typedef struct No {
    Produto produto;
    struct No *esquerda, *direita;
} No;

No* criarNo(Produto produto) {
    No *novoNo = (No*)malloc(sizeof(No));
    (*novoNo).produto = produto;
    (*novoNo).esquerda = NULL;
    (*novoNo).direita = NULL;
    return novoNo;
}

No* inserir(No *raiz, Produto produto) {
    if (raiz == NULL) {
        return criarNo(produto);
    }

    if (produto.id < (*raiz).produto.id) {
        (*raiz).esquerda = inserir((*raiz).esquerda, produto);
    } else if (produto.id > (*raiz).produto.id) {
        (*raiz).direita = inserir((*raiz).direita, produto);
    }

    return raiz;
}

No* carregarDados(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    No *raiz = NULL;
    Produto produto;

    while (fscanf(arquivo, "%d %s %s %f", &produto.id, produto.nome, produto.dp, &produto.preco) != EOF) {
        raiz = inserir(raiz, produto); 
    }

    fclose(arquivo);
    return raiz;
}

void procurarPorID(No *raiz, int idProcurado) {
    if (raiz == NULL) {
        printf("Produto nao encontrado!\n");
        return;
    }

    printf("(%s) %s - R$ %.2f\n", (*raiz).produto.dp, (*raiz).produto.nome, (*raiz).produto.preco);

    if (idProcurado < (*raiz).produto.id) {
        procurarPorID((*raiz).esquerda, idProcurado);
    } else if (idProcurado > (*raiz).produto.id) {
        procurarPorID((*raiz).direita, idProcurado);
    }
}


void procurarPorDp(No *raiz, char *departamento) {
    if (raiz == NULL) {
        return;
    }

    procurarPorDp((*raiz).esquerda, departamento);

    if (strcmp((*raiz).produto.dp, departamento) == 0) {
        printf("(%s) %s - R$ %.2f\n", (*raiz).produto.dp, (*raiz).produto.nome, (*raiz).produto.preco);
    }

    procurarPorDp((*raiz).direita, departamento);
}

int departamentoExiste(No *raiz, char *departamento) {
    if (raiz == NULL) {
        return 0;
    }

    if (strcmp((*raiz).produto.dp, departamento) == 0) {
        return 1;
    }

    if (departamentoExiste((*raiz).esquerda, departamento) || departamentoExiste((*raiz).direita, departamento)) {
        return 1;
    }

    return 0;
}

No* inserirProduto(No *raiz) {
    Produto novoProduto;
    scanf("%d %s %s %f", &novoProduto.id, novoProduto.nome, novoProduto.dp, &novoProduto.preco);
    return inserir(raiz, novoProduto);
}

int filtroPreco(No *raiz, float precoMax) {
    if (raiz == NULL) {
        return 0;
    }

    int encontrado = 0;

    encontrado += filtroPreco((*raiz).esquerda, precoMax);

    if ((*raiz).produto.preco <= precoMax) {
        printf("(%s) %s - R$ %.2f\n", (*raiz).produto.dp, (*raiz).produto.nome, (*raiz).produto.preco);
        encontrado = 1;
    }

    encontrado += filtroPreco((*raiz).direita, precoMax);

    return encontrado;
}

void liberarArvore(No *raiz) {
    if (raiz == NULL) {
        return;
    }

    liberarArvore((*raiz).esquerda);
    liberarArvore((*raiz).direita);
    free(raiz);
}

No* inserirPorPreco(No *raiz, Produto produto) {
    if (raiz == NULL) {
        return criarNo(produto);
    }

    if (produto.preco < (*raiz).produto.preco) {
        (*raiz).esquerda = inserirPorPreco((*raiz).esquerda, produto);
    } else {
        (*raiz).direita = inserirPorPreco((*raiz).direita, produto);
    }

    return raiz;
}

No* reordenarPorPreco(No *raizAntiga, No *novaRaiz) {
    if (raizAntiga == NULL) {
        return novaRaiz;
    }

    novaRaiz = inserirPorPreco(novaRaiz, (*raizAntiga).produto);
    novaRaiz = reordenarPorPreco((*raizAntiga).esquerda, novaRaiz);
    novaRaiz = reordenarPorPreco((*raizAntiga).direita, novaRaiz);

    return novaRaiz;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    No *raiz = carregarDados(argv[1]);

    if (raiz == NULL) {
        return 1;
    }

    No *raizPorPreco = NULL;
    raizPorPreco = reordenarPorPreco(raiz, raizPorPreco);  

    int idProcurado, opcao;
    char departamento[50];
    float precoMax;

    printf("1 - Procurar por ID\n");
    printf("2 - Procurar por Departamento\n");
    printf("3 - Inserir Produto\n");
    printf("4 - Filtrar por Preco\n");
    printf("5 - Sair\n");

    do {
        scanf("%d", &opcao);
        if (opcao == 1) {
            scanf("%d", &idProcurado);
            procurarPorID(raiz, idProcurado);
        } else if (opcao == 2) {
            scanf("%s", departamento);
            if (departamentoExiste(raiz, departamento)) {
                procurarPorDp(raiz, departamento);
            } else {
                printf("Departamento vazio!\n");
            }
        } else if (opcao == 3) {
            raiz = inserirProduto(raiz);
            raizPorPreco = reordenarPorPreco(raiz, NULL);  
        } else if (opcao == 4) {
            scanf("%f", &precoMax);
            if (!filtroPreco(raizPorPreco, precoMax)) {
                printf("Sem resultados para o filtro!\n");
            }
        }
    } while (opcao != 5);

    liberarArvore(raiz);
    liberarArvore(raizPorPreco);

    return 0;
}
