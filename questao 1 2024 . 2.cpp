#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para verificar se L1 está ordenada
bool estaOrdenada(int L1[], int n) {
    bool crescente = true, decrescente = true;
    for (int i = 0; i < n - 1; i++) {
        if (L1[i] > L1[i + 1])
            crescente = false;
        if (L1[i] < L1[i + 1])
            decrescente = false;
    }
    return crescente || decrescente;
}

// Função para copiar L1 em L2
void copiarLista(int L1[], int n, int L2[]) {
    for (int i = 0; i < n; i++) {
        L2[i] = L1[i];
    }
}

// Função para copiar L1 em L2, eliminando elementos repetidos
int copiarSemRepetidos(int L1[], int n, int L2[]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        bool encontrado = false;
        for (int j = 0; j < k; j++) {
            if (L1[i] == L2[j]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            L2[k++] = L1[i];
        }
    }
    return k;
}

// Função para inverter L1 em L2
void inverterLista(int L1[], int n, int L2[]) {
    for (int i = 0; i < n; i++) {
        L2[i] = L1[n - 1 - i];
    }
}

// Função para inverter L1 na própria L1
void inverterListaInplace(int L1[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = L1[i];
        L1[i] = L1[n - 1 - i];
        L1[n - 1 - i] = temp;
    }
}

// Função para intercalar L1 e L2 gerando L3
int intercalarListas(int L1[], int n1, int L2[], int n2, int L3[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (L1[i] < L2[j]) {
            L3[k++] = L1[i++];
        } else {
            L3[k++] = L2[j++];
        }
    }
    while (i < n1) L3[k++] = L1[i++];
    while (j < n2) L3[k++] = L2[j++];
    return k;
}

// Função para gerar L2 com contagem de elementos
typedef struct {
    int elem;
    int count;
} Registro;

int gerarContagem(int L1[], int n, Registro L2[]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        bool encontrado = false;
        for (int j = 0; j < k; j++) {
            if (L2[j].elem == L1[i]) {
                L2[j].count++;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            L2[k].elem = L1[i];
            L2[k].count = 1;
            k++;
        }
    }
    return k;
}

// Função para eliminar todas as ocorrências de um elemento em L1
int eliminarElemento(int L1[], int n, int elemento) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (L1[i] != elemento) {
            L1[k++] = L1[i];
        }
    }
    return k;
}

// Função para encontrar elementos que aparecem mais e menos vezes
void elementosMaisMenosFrequentes(int L1[], int n) {
    Registro contagens[n];
    int k = gerarContagem(L1, n, contagens);

    int maxCount = 0, minCount = n;
    for (int i = 0; i < k; i++) {
        if (contagens[i].count > maxCount)
            maxCount = contagens[i].count;
        if (contagens[i].count < minCount)
            minCount = contagens[i].count;
    }

    printf("Elementos que aparecem mais vezes (x%d): ", maxCount);
    for (int i = 0; i < k; i++) {
        if (contagens[i].count == maxCount)
            printf("%d ", contagens[i].elem);
    }
    printf("\nElementos que aparecem menos vezes (x%d): ", minCount);
    for (int i = 0; i < k; i++) {
        if (contagens[i].count == minCount)
            printf("%d ", contagens[i].elem);
    }
    printf("\n");
}

// Programa principal para testes
int main() {
    int L1[] = {1, 2, 2, 3, 4, 4, 5};
    int n1 = sizeof(L1) / sizeof(L1[0]);
    int L2[100], L3[200];

    printf("L1 está ordenada? %s\n", estaOrdenada(L1, n1) ? "Sim" : "Não");

    copiarLista(L1, n1, L2);
    printf("Cópia de L1 em L2: ");
    for (int i = 0; i < n1; i++) printf("%d ", L2[i]);
    printf("\n");

    int n2 = copiarSemRepetidos(L1, n1, L2);
    printf("Cópia de L1 em L2 sem repetidos: ");
    for (int i = 0; i < n2; i++) printf("%d ", L2[i]);
    printf("\n");

    inverterLista(L1, n1, L2);
    printf("L1 invertida em L2: ");
    for (int i = 0; i < n1; i++) printf("%d ", L2[i]);
    printf("\n");

    inverterListaInplace(L1, n1);
    printf("L1 invertida na própria L1: ");
    for (int i = 0; i < n1; i++) printf("%d ", L1[i]);
    printf("\n");

    int L1_sorted[] = {1, 3, 5}, L2_sorted[] = {2, 4, 6};
    int n1_sorted = 3, n2_sorted = 3;
    int n3 = intercalarListas(L1_sorted, n1_sorted, L2_sorted, n2_sorted, L3);
    printf("Intercalando L1 e L2 em L3: ");
    for (int i = 0; i < n3; i++) printf("%d ", L3[i]);
    printf("\n");

    Registro L2_registros[100];
    int k = gerarContagem(L1, n1, L2_registros);
    printf("Contagem de elementos: ");
    for (int i = 0; i < k; i++) printf("(%d, %d) ", L2_registros[i].elem, L2_registros[i].count);
    printf("\n");

    int elemento = 4;
    n1 = eliminarElemento(L1, n1, elemento);
    printf("L1 sem o elemento %d: ", elemento);
    for (int i = 0; i < n1; i++) printf("%d ", L1[i]);
    printf("\n");

    elementosMaisMenosFrequentes(L1, n1);

    return 0;
}

