# Sistema de análise de notas

Este código é um programa simples em C que lê dados de um arquivo de entrada no formato CSV, calcula a média das notas dos alunos e determina se eles foram aprovados ou reprovados com base nessa média. Os resultados são escritos em um arquivo de saída no formato CSV.

## Pré-requisitos
Antes de executar o programa, verifique se você tem os seguintes pré-requisitos instalados:

* Compilador C (como GCC) para compilar o código.
* Ter feito o download do arquivo de entrada no formato CSV com os dados dos alunos. Certifique-se de que o arquivo de entrada esteja presente e tenha o nome "DadosEntrada.csv".
* Permissões de escrita no diretório para criar o arquivo de saída "SituacaoFinal.csv".
  
## Funcionalidades
* Leitura de dados de um arquivo CSV.
* Cálculo da média das notas dos alunos.
* Determinação da situação do aluno (aprovado ou reprovado).
* Escrita dos resultados em um arquivo CSV.
* Calcular o tempo de execução do programa

## Estrutura do Projeto
O código está estruturado da seguinte forma:

* Inclusão das bibliotecas necessárias.
* Definição da struct Aluno para armazenar os dados de cada aluno.
* Declaração das funções utilizadas no código.
* Função main, responsável por abrir os arquivos de entrada e saída, chamar as funções de leitura, escrita, fechar os arquivos e calcular o tempo de execução.
* Função lerArquivo, responsável por ler o arquivo de entrada, calcular a média e determinar a situação de cada aluno.
* Função calcularMedia, responsável por calcular a média das notas de um aluno.
* Função determinarSituação, responsável por determinar se o aluno está aprovado ou reprovado com base na média.
* Função escreverArquivoSaida, responsável por escrever os dados no arquivo de saída.

## Formato do Arquivo de Entrada
O arquivo de entrada `DadosEntrada.csv` deve seguir o seguinte formato:


Nome,Telefone,Curso,Nota1,Nota2

Maria,(99) 99999-9999,Engenharia,7.5,8.0

João,(99) 88888-8888,Medicina,6.0,5.5

 
## Formato do Arquivo de Saída
O arquivo de saída "SituacaoFinal.csv" conterá os seguintes resultados:

+ Nome
+ Média
+ Situação (APROVADO ou REPROVADO)

## Tempo de Execução
O tempo de execução do programa será exibido no final da execução. Este tempo inclui o tempo de leitura dos dados, cálculo das médias, determinação das situações e escrita dos resultados no arquivo de saída.

## Considerações finais
Desenvolver este código foi uma experiência valiosa e enriquecedora. Ao longo do processo, foi possivel melhorar as habilidade em programação em C, além de aprender sobre a manipulação de arquivos, o uso de estruturas e a organização de funções em um programa.

Desenvolver este código também ajudou a reforçar a importância da organização e da documentação adequada do código. A clareza na estrutura do programa, nos nomes de variáveis e funções, bem como a inclusão de comentários explicativos, são aspectos essenciais para facilitar a compreensão e manutenção do código no futuro.

Em resumo, este projeto foi uma oportunidade valiosa de aplicar os conhecimentos em estrutura de dados e desenvolver uma solução prática para um problema específico.
