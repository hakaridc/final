#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Pega os dados que o formulário enviou
    char *dados = getenv("QUERY_STRING");

    // Abre o arquivo para gravar (append = adiciona no final)
    FILE *arquivo = fopen("usuarios.txt", "a");

    if (arquivo == NULL) {
        printf("Content-type: text/html\n\n");
        printf("<h1>Erro ao abrir o arquivo!</h1>");
        return 1;
    }

    // Se tiver dados grava no arquivo
    if (dados != NULL) {
        fprintf(arquivo, "%s\n", dados);  // grava a linha com os dados
        fprintf(arquivo, "--------------------------\n");
    }

    fclose(arquivo);

    // Cabeçalho obrigatório de CGI + redirecionamento
    printf("Content-type: text/html\n");
    printf("Location: obrigado.html\n\n");

    return 0;
}

//gcc cadastro.c -o cadastro.cgi