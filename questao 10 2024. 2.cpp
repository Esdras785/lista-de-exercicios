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

// Fun��o para encontrar o ponto m�dio da lista encadeada
Node* ponto_medio(Node* head) {
    if (head == NULL) {
        return NULL;  // Lista vazia
    }

    Node* rapido = head;
    Node* lento = head;

    // O ponteiro r�pido avan�a duas c�lulas por vez e o ponteiro lento uma
    while (rapido != NULL && rapido->next != NULL) {
        lento = lento->next;          // Avan�a o ponteiro lento uma c�lula
        rapido = rapido->next->next;  // Avan�a o ponteiro r�pido duas c�lulas
    }

    return lento;  // O ponteiro lento est� no ponto m�dio
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

// Fun��o para liberar a mem�ria da lista
void liberar_lista(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* lista = NULL;

    // Adicionando elementos � lista
    adicionar_no(&lista, 1);
    adicionar_no(&lista, 2);
    adicionar_no(&lista, 3);
    adicionar_no(&lista, 4);
    adicionar_no(&lista, 5);

    // Imprimindo a lista
    printf("Lista: ");
    imprimir_lista(lista);

    // Encontrando o ponto m�dio
    Node* meio = ponto_medio(lista);
    
    if (meio != NULL) {
        printf("O ponto m�dio da lista tem o valor: %d\n", meio->data);
    } else {
        printf("A lista est� vazia.\n");
    }

    // Liberando a mem�ria
    liberar_lista(lista);

    return 0;
}

