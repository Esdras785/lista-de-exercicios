#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXTO 1000
#define MAX_PALAVRA 100

// Função para limpar os caracteres não alfabéticos de uma palavra
void limpar_palavra(char* palavra) {
    int i = 0, j = 0;
    while (palavra[i]) {
        if (isalpha(palavra[i])) {
            palavra[j++] = tolower(palavra[i]); // Convertendo para minúscula
        }
        i++;
    }
    palavra[j] = '\0';
}

// Função para contar o número total de palavras no texto
int contar_palavras(char texto[]) {
    char* token = strtok(texto, " \n\t\r,.!?;:");
    int contador = 0;
    
    while (token != NULL) {
        contador++;
        token = strtok(NULL, " \n\t\r,.!?;:");
    }
    
    return contador;
}

// Função para contar o número de palavras distintas no texto
int contar_palavras_distintas(char texto[]) {
    char* token = strtok(texto, " \n\t\r,.!?;:");
    char palavras[1000][MAX_PALAVRA];
    int num_distintas = 0;
    
    while (token != NULL) {
        char palavra[MAX_PALAVRA];
        strcpy(palavra, token);
        limpar_palavra(palavra);
        
        int ja_existe = 0;
        for (int i = 0; i < num_distintas; i++) {
            if (strcmp(palavras[i], palavra) == 0) {
                ja_existe = 1;
                break;
            }
        }
        
        if (!ja_existe) {
            strcpy(palavras[num_distintas], palavra);
            num_distintas++;
        }
        
        token = strtok(NULL, " \n\t\r,.!?;:");
    }
    
    return num_distintas;
}

// Função para calcular a média de letras das palavras
double media_letras(char texto[]) {
    char* token = strtok(texto, " \n\t\r,.!?;:");
    int total_letras = 0;
    int total_palavras = 0;
    
    while (token != NULL) {
        total_letras += strlen(token);
        total_palavras++;
        token = strtok(NULL, " \n\t\r,.!?;:");
    }
    
    return total_palavras > 0 ? (double) total_letras / total_palavras : 0.0;
}

// Função para encontrar a maior palavra
char* maior_palavra(char texto[]) {
    char* token = strtok(texto, " \n\t\r,.!?;:");
    char* maior = NULL;
    
    while (token != NULL) {
        if (maior == NULL || strlen(token) > strlen(maior)) {
            maior = token;
        }
        token = strtok(NULL, " \n\t\r,.!?;:");
    }
    
    return maior;
}

// Função para encontrar a menor palavra
char* menor_palavra(char texto[]) {
    char* token = strtok(texto, " \n\t\r,.!?;:");
    char* menor = NULL;
    
    while (token != NULL) {
        if (menor == NULL || strlen(token) < strlen(menor)) {
            menor = token;
        }
        token = strtok(NULL, " \n\t\r,.!?;:");
    }
    
    return menor;
}

// Função para encontrar a palavra mais frequente
char* palavra_mais_frequente(char texto[]) {
    char* token = strtok(texto, " \n\t\r,.!?;:");
    char palavras[1000][MAX_PALAVRA];
    int frequencia[1000] = {0};
    int num_palavras = 0;
    
    while (token != NULL) {
        char palavra[MAX_PALAVRA];
        strcpy(palavra, token);
        limpar_palavra(palavra);
        
        int i;
        for (i = 0; i < num_palavras; i++) {
            if (strcmp(palavras[i], palavra) == 0) {
                frequencia[i]++;
                break;
            }
        }
        
        if (i == num_palavras) {
            strcpy(palavras[num_palavras], palavra);
            frequencia[num_palavras] = 1;
            num_palavras++;
        }
        
        token = strtok(NULL, " \n\t\r,.!?;:");
    }
    
    int max_frequencia = 0;
    int indice_max = 0;
    
    for (int i = 0; i < num_palavras; i++) {
        if (frequencia[i] > max_frequencia) {
            max_frequencia = frequencia[i];
            indice_max = i;
        }
    }
    
    return palavras[indice_max];
}

// Função para encontrar a palavra mais rara
char* palavra_mais_rara(char texto[]) {
    char* token = strtok(texto, " \n\t\r,.!?;:");
    char palavras[1000][MAX_PALAVRA];
    int frequencia[1000] = {0};
    int num_palavras = 0;
    
    while (token != NULL) {
        char palavra[MAX_PALAVRA];
        strcpy(palavra, token);
        limpar_palavra(palavra);
        
        int i;
        for (i = 0; i < num_palavras; i++) {
            if (strcmp(palavras[i], palavra) == 0) {
                frequencia[i]++;
                break;
            }
        }
        
        if (i == num_palavras) {
            strcpy(palavras[num_palavras], palavra);
            frequencia[num_palavras] = 1;
            num_palavras++;
        }
        
        token = strtok(NULL, " \n\t\r,.!?;:");
    }
    
    int min_frequencia = frequencia[0];
    int indice_min = 0;
    
    for (int i = 1; i < num_palavras; i++) {
        if (frequencia[i] < min_frequencia) {
            min_frequencia = frequencia[i];
            indice_min = i;
        }
    }
    
    return palavras[indice_min];
}

int main() {
    char texto[MAX_TEXTO];

    // Solicita que o usuário digite um texto
    printf("Digite o texto (limite 1000 caracteres):\n");
    fgets(texto, sizeof(texto), stdin);

    // Remover o '\n' no final do texto
    texto[strcspn(texto, "\n")] = 0;

    // Chama as funções e exibe os resultados
    printf("Número total de palavras: %d\n", contar_palavras(texto));
    printf("Número de palavras distintas: %d\n", contar_palavras_distintas(texto));
    printf("Média de letras das palavras: %.2f\n", media_letras(texto));
    printf("A maior palavra: %s\n", maior_palavra(texto));
    printf("A menor palavra: %s\n", menor_palavra(texto));
    printf("A palavra mais frequente: %s\n", palavra_mais_frequente(texto));
    printf("A palavra mais rara: %s\n", palavra_mais_rara(texto));

    return 0;
}
