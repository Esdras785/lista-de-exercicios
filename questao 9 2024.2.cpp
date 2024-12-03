#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um nó da lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* criar_no(int data) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = data;
    novo->next = NULL;
    return novo;
}

// Função para adicionar um nó no final da lista
void adicionar_no(Node** head, int data) {
    Node* novo = criar_no(data);
    if (*head == NULL) {
        *head = novo;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novo;
    }
}

// Função para liberar a memória da lista
void liberar_lista(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Função para imprimir a lista (opcional, para testes)
void imprimir_lista(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Função iterativa para verificar se duas listas são iguais
int listas_iguais_iterativa(Node* lista1, Node* lista2) {
    // Enquanto ambos os ponteiros não forem NULL
    while (lista1 != NULL && lista2 != NULL) {
        // Se os dados dos nós forem diferentes, as listas não são iguais
        if (lista1->data != lista2->data) {
            return 0;  // Falso
        }
        lista1 = lista1->next;
        lista2 = lista2->next;
    }
    
    // Se ambas as listas chegaram ao final simultaneamente, elas são iguais
    // Caso contrário, uma lista terminou antes da outra
    return lista1 == NULL && lista2 == NULL;
}

// Função recursiva para verificar se duas listas são iguais
int listas_iguais_recursiva(Node* lista1, Node* lista2) {
    // Caso base: se ambos os ponteiros forem NULL, as listas são iguais
    if (lista1 == NULL && lista2 == NULL) {
        return 1;  // Verdadeiro
    }
    
    // Se um dos ponteiros for NULL, as listas não são iguais
    if (lista1 == NULL || lista2 == NULL) {
        return 0;  // Falso
    }
    
    // Compara os dados do nó atual e chama recursivamente para os próximos nós
    if (lista1->data != lista2->data) {
        return 0;  // Falso
    }
    
    return listas_iguais_recursiva(lista1->next, lista2->next);
}

int main() {
    Node* lista1 = NULL;
    Node* lista2 = NULL;
    
    // Adicionando elementos à lista 1
    adicionar_no(&lista1, 1);
    adicionar_no(&lista1, 2);
    adicionar_no(&lista1, 3);
    
    // Adicionando elementos à lista 2
    adicionar_no(&lista2, 1);
    adicionar_no(&lista2, 2);
    adicionar_no(&lista2, 3);
    
    // Verificando se as listas são iguais
    if (listas_iguais_iterativa(lista1, lista2)) {
        printf("As listas são iguais (versão iterativa).\n");
    } else {
        printf("As listas são diferentes (versão iterativa).\n");
    }

    if (listas_iguais_recursiva(lista1, lista2)) {
        printf("As listas são iguais (versão recursiva).\n");
    } else {
        printf("As listas são diferentes (versão recursiva).\n");
    }

    // Liberando a memória
    liberar_lista(lista1);
    liberar_lista(lista2);
    
    return 0;
}

