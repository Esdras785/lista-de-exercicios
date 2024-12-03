#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da árvore binária
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* novo_no(int data) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = data;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

// Função para trocar as subárvores esquerda e direita de um nó
void espelho(Node* raiz) {
    if (raiz == NULL) {
        return;  // Caso a árvore esteja vazia
    }

    // Troca as subárvores esquerda e direita
    Node* temp = raiz->left;
    raiz->left = raiz->right;
    raiz->right = temp;

    // Recursivamente aplica a função nas subárvores esquerda e direita
    espelho(raiz->left);
    espelho(raiz->right);
}

// Função para imprimir a árvore em ordem (in-order traversal)
void imprimir_inorder(Node* raiz) {
    if (raiz == NULL) {
        return;
    }
    imprimir_inorder(raiz->left);
    printf("%d ", raiz->data);
    imprimir_inorder(raiz->right);
}

// Função principal
int main() {
    // Criando uma árvore binária de exemplo
    Node* raiz = novo_no(1);
    raiz->left = novo_no(2);
    raiz->right = novo_no(3);
    raiz->left->left = novo_no(4);
    raiz->left->right = novo_no(5);
    raiz->right->left = novo_no(6);
    raiz->right->right = novo_no(7);

    printf("Árvore original (em ordem): ");
    imprimir_inorder(raiz);
    printf("\n");

    // Obter o espelho da árvore
    espelho(raiz);

    printf("Árvore após espelho (em ordem): ");
    imprimir_inorder(raiz);
    printf("\n");

    return 0;
}

