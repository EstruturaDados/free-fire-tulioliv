#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura para representar um item
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

int main() {
    struct Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n📦 MENU DA MOCHILA\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                if (totalItens < MAX_ITENS) {
                    printf("Nome do item: ");
                    fgets(mochila[totalItens].nome, sizeof(mochila[totalItens].nome), stdin);
                    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = '\0';

                    printf("Tipo do item: ");
                    fgets(mochila[totalItens].tipo, sizeof(mochila[totalItens].tipo), stdin);
                    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = '\0';

                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);
                    getchar();

                    totalItens++;
                    printf("✅ Item adicionado com sucesso!\n");
                } else {
                    printf("⚠️ Mochila cheia! Remova um item antes de adicionar outro.\n");
                }
                break;

            case 2: {
                char nomeRemover[30];
                printf("Digite o nome do item a remover: ");
                fgets(nomeRemover, sizeof(nomeRemover), stdin);
                nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                int encontrado = 0;
                for (int i = 0; i < totalItens; i++) {
                    if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                        for (int j = i; j < totalItens - 1; j++) {
                            mochila[j] = mochila[j + 1];
                        }
                        totalItens--;
                        encontrado = 1;
                        printf("🗑️ Item removido com sucesso!\n");
                        break;
                    }
                }
                if (!encontrado) {
                    printf("❌ Item não encontrado.\n");
                }
                break;
            }

            case 3:
                if (totalItens == 0) {
                    printf("📭 Mochila vazia.\n");
                } else {
                    printf("\n📋 ITENS NA MOCHILA:\n");
                    printf("%-30s %-20s %-10s\n", "Nome", "Tipo", "Quantidade");
                    for (int i = 0; i < totalItens; i++) {
                        printf("%-30s %-20s %-10d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }
                }
                break;

            case 4:
                printf("👋 Encerrando o programa...\n");
                break;

            default:
                printf("⚠️ Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
