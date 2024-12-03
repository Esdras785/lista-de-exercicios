#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um n� da lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fun��o para criar um novo n�
Node* criar_no(int data) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = data;
    novo->next = NULL;
    return novo;
}

// Fun��o para adicionar um n� no final da lista
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

// Fun��o para liberar a mem�ria da lista
void liberar_lista(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Fun��o para imprimir a lista (opcional, para testes)
void imprimir_lista(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fun��o iterativa para verificar se duas listas s�o iguais
int listas_iguais_iterativa(Node* lista1, Node* lista2) {
    // Enquanto ambos os ponteiros n�o forem NULL
    while (lista1 != NULL && lista2 != NULL) {
        // Se os dados dos n�s forem diferentes, as listas n�o s�o iguais
        if (lista1->data != lista2->data) {
            return 0;  // Falso
        }
        lista1 = lista1->next;
        lista2 = lista2->next;
    }
    
    // Se ambas as listas chegaram ao final simultaneamente, elas s�o iguais
    // Caso contr�rio, uma lista terminou antes da outra
    return lista1 == NULL && lista2 == NULL;
}

// Fun��o recursiva para verificar se duas listas s�o iguais
int listas_iguais_recursiva(Node* lista1, Node* lista2) {
    // Caso base: se ambos os ponteiros forem NULL, as listas s�o iguais
    if (lista1 == NULL && lista2 == NULL) {
        return 1;  // Verdadeiro
    }
    
    // Se um dos ponteiros for NULL, as listas n�o s�o iguais
    if (lista1 == NULL || lista2 == NULL) {
        return 0;  // Falso
    }
    
    // Compara os dados do n� atual e chama recursivamente para os pr�ximos n�s
    if (lista1->data != lista2->data) {
        return 0;  // Falso
    }
    
    return listas_iguais_recursiva(lista1->next, lista2->next);
}

int main() {
    Node* lista1 = NULL;
    Node* lista2 = NULL;
    
    // Adicionando elementos � lista 1
    adicionar_no(&lista1, 1);
    adicionar_no(&lista1, 2);
    adicionar_no(&lista1, 3);
    
    // Adicionando elementos � lista 2
    adicionar_no(&lista2, 1);
    adicionar_no(&lista2, 2);
    adicionar_no(&lista2, 3);
    
    // Verificando se as listas s�o iguais
    if (listas_iguais_iterativa(lista1, lista2)) {
        printf("As listas s�o iguais (vers�o iterativa).\n");
    } else {
        printf("As listas s�o diferentes (vers�o iterativa).\n");
    }

    if (listas_iguais_recursiva(lista1, lista2)) {
        printf("As listas s�o iguais (vers�o recursiva).\n");
    } else {
        printf("As listas s�o diferentes (vers�o recursiva).\n");
    }

    // Liberando a mem�ria
    liberar_lista(lista1);
    liberar_lista(lista2);
    
    return 0;
}

