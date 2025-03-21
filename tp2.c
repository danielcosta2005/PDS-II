#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[100];
    int numeroRegistro;
} Professor;

typedef struct {
    char nome[100];
    int numeroRegistro;
    int notas[3];
} Aluno;

typedef struct {
    char codigo[10];
    char nome[100];
    Aluno alunos[6];
    int quantidadeAlunos;
} Turma;

typedef struct {
    Professor professor;
    Turma turmas[2];
    int quantidadeTurmas;
} SistemaEscola;

void removeContraN(char *str) {
    str[strlen(str)-1] = '\0';
    while(str[strlen(str) - 1] == ' ') {
        str[strlen(str)-1] = '\0';
    }
}

void carregarDados(char *nomeArquivo, SistemaEscola *sistema) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo==NULL) {
        perror("Falha ao abrir o arquivo de entrada");
        exit (EXIT_FAILURE);
    }

    fgets((*sistema).professor.nome, 100, arquivo);
    removeContraN((*sistema).professor.nome);//tirar o \n

    fscanf(arquivo, "%d", &(*sistema).professor.numeroRegistro);
    fgetc (arquivo);// remove o caractere de nova linha

    fscanf(arquivo, "%d", &(*sistema).quantidadeTurmas);
    fgetc(arquivo);

    for (int i = 0; i < (*sistema).quantidadeTurmas; i++) {

        fgets((*sistema).turmas[i].nome, 100, arquivo);
        removeContraN ((*sistema).turmas[i].nome);

        fgets((*sistema).turmas[i].codigo, 10, arquivo);
        removeContraN((*sistema).turmas[i].codigo);
    }

    for (int i = 0; i < (*sistema).quantidadeTurmas; i++) {
        fscanf(arquivo, "%d", &(*sistema).turmas[i].quantidadeAlunos);
        for (int j = 0; j < (*sistema).turmas[i].quantidadeAlunos; j++) {
            fgetc(arquivo); 

            fgets((*sistema).turmas[i].alunos[j].nome, 100, arquivo);
            removeContraN((*sistema).turmas[i].alunos[j].nome);

            fscanf(arquivo, "%d", &(*sistema).turmas[i].alunos[j].numeroRegistro);

            for (int k = 0; k < 3; k++) {
                (*sistema).turmas[i].alunos[j].notas[k] = 0;//todos começam com 0
            }
        }

    }
    fclose(arquivo);
}

void exibirInfoProfessor(SistemaEscola *sistema) {
    printf("Professor %s\n", (*sistema).professor.nome);
    printf("Registro numero %d\n", (*sistema).professor.numeroRegistro);

    for (int i = 0; i < (*sistema).quantidadeTurmas; i++) {
        printf("Turma %d: %s - %s, %d alunos\n",i+1, (*sistema).turmas[i].codigo, (*sistema).turmas[i].nome, (*sistema).turmas[i].quantidadeAlunos);
    }
}

void exibirInfoAluno(SistemaEscola *sistema, int matriculaAluno, char *codigoTurma) {
    for (int i = 0; i < (*sistema).quantidadeTurmas; i++) {
        if (strcmp((*sistema).turmas[i].codigo, codigoTurma) == 0) {
            for (int j = 0; j < (*sistema).turmas[i].quantidadeAlunos; j++) {
                if ((*sistema).turmas[i].alunos[j].numeroRegistro == matriculaAluno) {
                    Aluno aluno = (*sistema).turmas[i].alunos[j];
                    printf("Aluno: %s\n", aluno.nome);
                    printf("Matricula: %d\n", aluno.numeroRegistro);
                    for (int k = 0; k < 3; k++) {
                        printf("Prova %d: %d ", k + 1, aluno.notas[k]);
                        if (k < 2) {
                            printf("/ ");
                        }
                    }

int notaFinal = (aluno.notas[0] + aluno.notas[1] + aluno.notas[2]) / 3;
char conceito;

if (notaFinal >= 90) {
    conceito = 'A';
} else if (notaFinal >= 80) {
    conceito = 'B';
} else if (notaFinal >= 70) {
    conceito = 'C';
} else if (notaFinal >= 60) {
    conceito = 'D';
} else if (notaFinal >= 40) {
    conceito = 'E';
} else {
    conceito = 'F';
}

                    printf("\nNota Final: %d - Conceito %c\n", notaFinal, conceito);
                }
            }
        }
    }
}

void inserirAluno(SistemaEscola *sistema, char *nomeAluno, int matriculaAluno, char *codigoTurma){
    for (int i=0; i<(*sistema).quantidadeTurmas; i++){
        if (strcmp((*sistema).turmas[i].codigo, codigoTurma)==0){
            if ((*sistema).turmas[i].quantidadeAlunos<6){
                Aluno aluno;

                strcpy(aluno.nome, nomeAluno);
                aluno.numeroRegistro=matriculaAluno;
                for (int j = 0; j < 3; ++j) {
                    aluno.notas[j] = 0;
                }

                (*sistema).turmas[i].alunos[(*sistema).turmas[i].quantidadeAlunos]=aluno;
                (*sistema).turmas[i].quantidadeAlunos++;
            }

            else {
                printf ("Turma cheia.\n");
            }
        }
    }
}

void lancarNotas(SistemaEscola *sistema, int matriculaAluno, char *codigoTurma, int notas[3]){
    for (int i=0; i<(*sistema).quantidadeTurmas; i++){
        if (strcmp((*sistema).turmas[i].codigo, codigoTurma)==0){
            for (int j=0; j<(*sistema).turmas[i].quantidadeAlunos; j++){
                if ((*sistema).turmas[i].alunos[j].numeroRegistro==matriculaAluno){
                    for (int k=0; k<3; k++){
                        (*sistema).turmas[i].alunos[j].notas[k]=notas[k];
                    }
                }
            }
        }
    }
}

void exibirInfoTurma(SistemaEscola *sistema, char *codigoTurma){
    for (int i=0; i<(*sistema).quantidadeTurmas; i++){
        if (strcmp((*sistema).turmas[i].codigo, codigoTurma)==0){
            printf ("Informacoes da turma %s - %s:\n", codigoTurma, (*sistema).turmas[i].nome);
            printf("%d alunos\n", (*sistema).turmas[i].quantidadeAlunos);

            for (int j=0; j<(*sistema).turmas[i].quantidadeAlunos; j++){
                printf ("Aluno: %s\n", (*sistema).turmas[i].alunos[j].nome);
                printf ("Matricula: %d\n", (*sistema).turmas[i].alunos[j].numeroRegistro);
            }
        }
    }
}

void exibirSituacaoTurma(SistemaEscola *sistema, char *codigoTurma){
    for (int i=0; i<(*sistema).quantidadeTurmas; i++){
        if (strcmp((*sistema).turmas[i].codigo, codigoTurma)==0){
            printf ("Situacao na Turma %s - %s\n", codigoTurma, (*sistema).turmas[i].nome);

            for (int j=0; j<(*sistema).turmas[i].quantidadeAlunos; j++){
                printf ("Aluno: %s\n", (*sistema).turmas[i].alunos[j].nome);
                printf ("Matricula: %d\n", (*sistema).turmas[i].alunos[j].numeroRegistro);

                int notaFinal=((*sistema).turmas[i].alunos[j].notas[0]+(*sistema).turmas[i].alunos[j].notas[1]+(*sistema).turmas[i].alunos[j].notas[2])/3;
                char conceito;

                if (notaFinal >= 90) {
    conceito = 'A';
} else if (notaFinal >= 80) {
    conceito = 'B';
} else if (notaFinal >= 70) {
    conceito = 'C';
} else if (notaFinal >= 60) {
    conceito = 'D';
} else if (notaFinal >= 40) {
    conceito = 'E';
} else {
    conceito = 'F';
}

printf ("Nota Final: %d - Conceito %c\n", notaFinal, conceito);

if (notaFinal>=60){
    printf ("Situacao: Aprovado");
}
else if (notaFinal<60 && notaFinal>=40){
    printf ("Situacao: Exame Especial");
}
else {
    printf ("Situacao: Reprovado");
}
printf ("\n");
            }
        }
    }
}

void exportarDados(SistemaEscola *sistema, char *nomeArquivoSaida) {
    FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");

    if (arquivoSaida == NULL) {
        perror("Falha ao abrir o arquivo de saida");
        exit (EXIT_FAILURE);
    }

    fprintf(arquivoSaida, "DADOS EXPORTADOS\n\n");
    fprintf(arquivoSaida, "Professor %s - Registro %d\n\n", (*sistema).professor.nome, (*sistema).professor.numeroRegistro);
    
    for (int i = 0; i < (*sistema).quantidadeTurmas; ++i) {
        
        fprintf(arquivoSaida, "Turma %s - %s\n", (*sistema).turmas[i].codigo, (*sistema).turmas[i].nome);

        for (int j = 0; j < (*sistema).turmas[i].quantidadeAlunos; ++j) {
            
            int notaFinal = ((*sistema).turmas[i].alunos[j].notas[0] + (*sistema).turmas[i].alunos[j].notas[1] + (*sistema).turmas[i].alunos[j].notas[2]) / 3;
            char conceito;
            char situacao[50];

            if (notaFinal >= 90) {
                conceito = 'A';
            } else if (notaFinal >= 80) {
                conceito = 'B';
            } else if (notaFinal >= 70) {
                conceito = 'C';
            } else if (notaFinal >= 60) {
                conceito = 'D';
            } else if (notaFinal >= 40) {
                conceito = 'E';
            } else {
                conceito = 'F';
            }

            if (notaFinal >= 60) {
                strcpy(situacao, "Aprovado");
            } else if (notaFinal >= 40) {
                strcpy(situacao, "Exame Especial");
            } else {
                strcpy(situacao, "Reprovado");
            }

            fprintf(arquivoSaida, "Aluno: %s\n", (*sistema).turmas[i].alunos[j].nome);
            fprintf(arquivoSaida, "Matricula: %d\n", (*sistema).turmas[i].alunos[j].numeroRegistro);
            fprintf(arquivoSaida, "Nota Final: %d - Conceito %c - %s\n", notaFinal, conceito, situacao);
        }
        if ((*sistema).quantidadeTurmas==2 && i<1){
            fprintf(arquivoSaida, "\n");
        }
    }
    fclose(arquivoSaida);
}

int main(int argc, char **argv){
    if (argc != 3) {
        return 1;
    }

    SistemaEscola sistema;
    carregarDados(argv[1], &sistema);
    
    int opcao;
    char codigoTurma[10];
    int matriculaAluno;
    char nomeAluno[100];
    int notas[3];

    printf("1 - Informacoes do Professor\n");
        printf("2 - Informacoes do Aluno\n");
        printf("3 - Inserir Aluno\n");
        printf("4 - Lancar Notas\n");
        printf("5 - Informacoes da Turma\n");
        printf("6 - Situacao dos Alunos\n");
        printf("7 - Exportar Dados\n");
    
    do {
        scanf("%d", &opcao);
        getchar();  // Limpa o buffer de entrada
        
        if (opcao == 1) {
            exibirInfoProfessor(&sistema);
        } else if (opcao == 2) {
            scanf("%d", &matriculaAluno);
            getchar();  
            fgets(codigoTurma, sizeof(codigoTurma), stdin);
            removeContraN(codigoTurma);
            exibirInfoAluno(&sistema, matriculaAluno, codigoTurma);
        } else if (opcao == 3) {
            fgets(nomeAluno, sizeof(nomeAluno), stdin);
            removeContraN(nomeAluno);
            scanf("%d", &matriculaAluno);
            getchar(); 
            fgets(codigoTurma, sizeof(codigoTurma), stdin);
            removeContraN(codigoTurma);
            inserirAluno(&sistema, nomeAluno, matriculaAluno, codigoTurma);
        } else if (opcao == 4) {
            scanf("%d", &matriculaAluno);
            while(getchar() != '\n');  
            fgets(codigoTurma, sizeof(codigoTurma), stdin);
            removeContraN(codigoTurma);
            scanf ("%d %d %d", &notas[0], &notas[1], &notas[2]);
            lancarNotas(&sistema, matriculaAluno, codigoTurma, notas);
        } else if (opcao == 5) {
            fgets(codigoTurma, sizeof(codigoTurma), stdin);
            removeContraN(codigoTurma);
            exibirInfoTurma(&sistema, codigoTurma);
        } else if (opcao == 6) {
            fgets(codigoTurma, sizeof(codigoTurma), stdin);
            removeContraN(codigoTurma);
            exibirSituacaoTurma(&sistema, codigoTurma);
        } else if (opcao == 7) {
            exportarDados(&sistema, argv[2]);
        }
    } while (opcao != 7);
    
    return 0;
}
