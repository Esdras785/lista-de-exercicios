#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do n� da �rvore bin�ria
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Fun��o para criar um novo n�
Node* novo_no(int data) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = data;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

// Fun��o para trocar as sub�rvores esquerda e direita de um n�
void espelho(Node* raiz) {
    if (raiz == NULL) {
        return;  // Caso a �rvore esteja vazia
    }

    // Troca as sub�rvores esquerda e direita
    Node* temp = raiz->left;
    raiz->left = raiz->right;
    raiz->right = temp;

    // Recursivamente aplica a fun��o nas sub�rvores esquerda e direita
    espelho(raiz->left);
    espelho(raiz->right);
}

// Fun��o para imprimir a �rvore em ordem (in-order traversal)
void imprimir_inorder(Node* raiz) {
    if (raiz == NULL) {
        return;
    }
    imprimir_inorder(raiz->left);
    printf("%d ", raiz->data);
    imprimir_inorder(raiz->right);
}

// Fun��o principal
int main() {
    // Criando uma �rvore bin�ria de exemplo
    Node* raiz = novo_no(1);
    raiz->left = novo_no(2);
    raiz->right = novo_no(3);
    raiz->left->left = novo_no(4);
    raiz->left->right = novo_no(5);
    raiz->right->left = novo_no(6);
    raiz->right->right = novo_no(7);

    printf("�rvore original (em ordem): ");
    imprimir_inorder(raiz);
    printf("\n");

    // Obter o espelho da �rvore
    espelho(raiz);

    printf("�rvore ap�s espelho (em ordem): ");
    imprimir_inorder(raiz);
    printf("\n");

    return 0;
}

