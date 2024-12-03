#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contato {
    char nome[100];
    char telefone[20];
    char email[100];
    struct Contato *proximo;
} Contato;

typedef struct {
    Contato *inicio;
    int tamanho;
} ListaContatos;

// Função para inicializar a lista
void inicializarLista(ListaContatos *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

// Função para criar um novo contato
Contato *criarContato(const char *nome, const char *telefone, const char *email) {
    Contato *novo = (Contato *)malloc(sizeof(Contato));
    if (!novo) {
        printf("Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(novo->nome, nome, sizeof(novo->nome));
    strncpy(novo->telefone, telefone, sizeof(novo->telefone));
    strncpy(novo->email, email, sizeof(novo->email));
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->telefone[sizeof(novo->telefone) - 1] = '\0';
    novo->email[sizeof(novo->email) - 1] = '\0';
    novo->proximo = NULL;
    return novo;
}

// Função para inserir um contato na lista
void inserirContato(ListaContatos *lista, const char *nome, const char *telefone, const char *email) {
    Contato *novo = criarContato(nome, telefone, email);
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    printf("\nContato inserido com sucesso!\n");
}

// Função para buscar um contato por nome
Contato *buscarContato(ListaContatos *lista, const char *nome) {
    Contato *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Função para remover um contato por nome
int removerContato(ListaContatos *lista, const char *nome) {
    Contato *atual = lista->inicio, *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                lista->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            lista->tamanho--;
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0;
}

// Funções para atualizar os dados do contato
void atualizarNome(Contato *contato, const char *novoNome) {
    strncpy(contato->nome, novoNome, sizeof(contato->nome));
    contato->nome[sizeof(contato->nome) - 1] = '\0';
}

void atualizarTelefone(Contato *contato, const char *novoTelefone) {
    strncpy(contato->telefone, novoTelefone, sizeof(contato->telefone));
    contato->telefone[sizeof(contato->telefone) - 1] = '\0';
}

void atualizarEmail(Contato *contato, const char *novoEmail) {
    strncpy(contato->email, novoEmail, sizeof(contato->email));
    contato->email[sizeof(contato->email) - 1] = '\0';
}

// Função para exibir todos os contatos
void exibirContatos(ListaContatos *lista) {
    Contato *atual = lista->inicio;

    if (atual == NULL) {
        printf("\nA lista de contatos está vazia!\n");
        return;
    }

    printf("\nLista de Contatos:\n");
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("Telefone: %s\n", atual->telefone);
        printf("Email: %s\n\n", atual->email);
        atual = atual->proximo;
    }
}

// Função para liberar a memória da lista
void liberarLista(ListaContatos *lista) {
    Contato *atual = lista->inicio;

    while (atual != NULL) {
        Contato *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
    lista->tamanho = 0;
}

// Menu de interface
void menu() {
    printf("\n===== AGENDA DE CONTATOS =====\n");
    printf("1. Inserir Contato\n");
    printf("2. Remover Contato\n");
    printf("3. Buscar Contato\n");
    printf("4. Atualizar Contato\n");
    printf("5. Exibir Contatos\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    ListaContatos lista;
    inicializarLista(&lista);

    int opcao;
    char nome[100], telefone[20], email[100];

    do {
        menu();
        scanf("%d", &opcao);
        getchar(); // Limpar buffer

        switch (opcao) {
            case 1:
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n'
                printf("Telefone: ");
                fgets(telefone, sizeof(telefone), stdin);
                telefone[strcspn(telefone, "\n")] = '\0';
                printf("Email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';

                inserirContato(&lista, nome, telefone, email);
                break;

            case 2:
                printf("Nome do contato a remover: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                if (removerContato(&lista, nome)) {
                    printf("\nContato removido com sucesso!\n");
                } else {
                    printf("\nContato não encontrado!\n");
                }
                break;

            case 3:
                printf("Nome do contato a buscar: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                Contato *contato = buscarContato(&lista, nome);
                if (contato != NULL) {
                    printf("\nContato encontrado:\n");
                    printf("Nome: %s\n", contato->nome);
                    printf("Telefone: %s\n", contato->telefone);
                    printf("Email: %s\n", contato->email);
                } else {
                    printf("\nContato não encontrado!\n");
                }
                break;

            case 4:
                printf("Nome do contato a atualizar: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                contato = buscarContato(&lista, nome);
                if (contato != NULL) {
                    printf("1. Atualizar Nome\n");
                    printf("2. Atualizar Telefone\n");
                    printf("3. Atualizar Email\n");
                    printf("Escolha uma opção: ");
                    int opcaoAtualizar;
                    scanf("%d", &opcaoAtualizar);
                    getchar();

                    switch (opcaoAtualizar) {
                        case 1:
                            printf("Novo Nome: ");
                            fgets(nome, sizeof(nome), stdin);
                            nome[strcspn(nome, "\n")] = '\0';
                            atualizarNome(contato, nome);
                            printf("\nNome atualizado com sucesso!\n");
                            break;

                        case 2:
                            printf("Novo Telefone: ");
                            fgets(telefone, sizeof(telefone), stdin);
                            telefone[strcspn(telefone, "\n")] = '\0';
                            atualizarTelefone(contato, telefone);
                            printf("\nTelefone atualizado com sucesso!\n");
                            break;

                        case 3:
                            printf("Novo Email: ");
                            fgets(email, sizeof(email), stdin);
                            email[strcspn(email, "\n")] = '\0';
                            atualizarEmail(contato, email);
                            printf("\nEmail atualizado com sucesso!\n");
                            break;

                        default:
                            printf("\nOpção inválida!\n");
                            break;
                    }
                } else {
                    printf("\nContato não encontrado!\n");
                }
                break;

            case 5:
                exibirContatos(&lista);
                break;

            case 6:
                printf("\nEncerrando o programa...\n");
                liberarLista(&lista);
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}

