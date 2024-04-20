#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Struct aluno que recebe os dados do arquivo de entrada
struct Aluno {
    char nome[100];
    char telefone[24];
    char curso[64];
    char situacao[15];
    float nota01;
    float nota02;
    float media;
};

void lerArquivo(FILE *arquivoEntrada, FILE *arquivoSaida); //função para leitura do arquivo de entrada
float calcularMedia(float nota01, float nota02); //função para calcular a média das notas 
void determinarSituacao (struct Aluno *aluno); //função que determina se o aluno está aprovado ou reprovado
void escreverArquivoSaida(struct Aluno *aluno, FILE *arquivoSaida); //função para escrever os dados no arquivo de saída

int main () {
    FILE *arquivoEntrada;
    FILE *arquivoSaida;
    clock_t inicio, fim; // Variáveis para registrar o tempo de início e término da execução do programa.
    double tempoCpu; //variavel para armazenar o tempo de execução

    inicio = clock(); //começar a contagem 
    arquivoEntrada = fopen("DadosEntrada.csv", "r"); //abrir o arquivo de entrada para leitura

    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada \nConfira se o arquivo DadosEntrada.csv esta na pasta output \n");
        exit(1);
    }

    arquivoSaida = fopen("SituacaoFinal.csv", "w"); //abrir o arquivo de saída para escrita

    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        exit(1);
    }

    lerArquivo(arquivoEntrada, arquivoSaida); //chamando a função para leitura do arquivo

    fclose(arquivoEntrada); //fechar o arquivo de entrada
    fclose(arquivoSaida); //fechar o arquivo de saída

    fim = clock(); //finalizar contagem
    tempoCpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC; //calcular o tempo de exeecução pelo processador e transformar em segundos

    printf("Arquivo gerado com sucesso");
    printf("\nTempo de execucao: %lf", tempoCpu);
    
}

void lerArquivo(FILE *arquivoEntrada, FILE *arquivoSaida) {
    struct Aluno aluno;
    char cabecalho[200]; //supor o tamanho do cabeçalho

    fgets(cabecalho, sizeof(cabecalho), arquivoEntrada); // Lendo e descartando o cabeçalho

    // Loop para o arquivo de entrada
    // Os dados são armazenados na struct Aluno e, em seguida, são calculadas a média das notas e determinada a situação de cada aluno.
    // Por fim, os resultados são escritos no arquivo de saída no formato CSV.
    while (fscanf(arquivoEntrada, "%[^,],%[^,],%[^,],%f,%f\n", aluno.nome, aluno.telefone, aluno.curso, &aluno.nota01, &aluno.nota02) == 5)
    {
        aluno.media = calcularMedia(aluno.nota01, aluno.nota02);
        determinarSituacao(&aluno);
        escreverArquivoSaida(&aluno, arquivoSaida);
    }
}
//Função para calcular a média de cada aluno
float calcularMedia(float nota01, float nota02) {
    return (nota01 + nota02) / 2;
}

// Função para determinar a situação do aluno (aprovado ou reprovado) com base na média de suas notas.
// Recebe um ponteiro para uma estrutura Aluno contendo os dados do aluno
void determinarSituacao (struct Aluno *aluno) {
    if (aluno->media >= 7.00) { //Verifica se a média do aluno é maior ou igual a 7.0 (nota mínima para aprovação).
        strcpy(aluno->situacao, "APROVADO") ;
    }else {
        strcpy(aluno->situacao, "REPROVADO") ;
    }
}

// Função para escrever os dados do aluno no arquivo de saída no formato CSV.
// Recebe um ponteiro para uma estrutura Aluno contendo os dados do aluno e um ponteiro para o arquivo de saída.
void escreverArquivoSaida(struct Aluno *aluno, FILE *arquivoSaida) {
    fprintf(arquivoSaida, "%s,%.2f,%s\n", aluno->nome, aluno->media, aluno->situacao);
}