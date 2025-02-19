#include <stdio.h>
#include <string.h>

#define TAMANHO_MAXIMO 100000

void substituir_e_remover(char *resultado);

void gerar_fractal_i(char *resultado, int estagio) {
    if (estagio == 0) {
        strcpy(resultado, "F");
        return;
    }

    char temporario[TAMANHO_MAXIMO];
    gerar_fractal_i(temporario, estagio - 1);

    int tamanho_resultado = 0;
    resultado[0] = '\0';

    for (int i = 0; temporario[i] != '\0'; i++) {
        if (temporario[i] == 'F') {
            if (tamanho_resultado + 15 < TAMANHO_MAXIMO) {
                strcat(resultado, "F-F+F+FF-F-F+F");
                tamanho_resultado += 15;
            } else {
                resultado[0] = '\0';
                return;
            }
        } else {
            if (tamanho_resultado + 1 < TAMANHO_MAXIMO) {
                strncat(resultado, &temporario[i], 1);
                tamanho_resultado++;
            } else {
                resultado[0] = '\0';
                return;
            }
        }
    }
}

void gerar_fractal_ii(char *resultado, int estagio) {
    if (estagio == 0) {
        strcpy(resultado, "X");
        return;
    }

    const char *regra_x = "-YF+XFX+FY-";
    const char *regra_y = "+XF-YFY-FX+";

    char temporario[TAMANHO_MAXIMO];
    gerar_fractal_ii(temporario, estagio - 1);

    resultado[0] = '\0';

    for (int i = 0; temporario[i] != '\0'; i++) {
        if (temporario[i] == 'X') {
            strcat(resultado, regra_x);
        } else if (temporario[i] == 'Y') {
            strcat(resultado, regra_y);
        } else {
            strncat(resultado, &temporario[i], 1);
        }
    }
}

void gerar_fractal_iii(char *resultado, int estagio) {
    if (estagio == 0) {
        strcpy(resultado, "X");
        return;
    }

    const char *regra_x = "XFYFX+F+YFXFY-F-XFYFX";
    const char *regra_y = "YFXFY-F-XFYFX+F+YFXFY";

    char temporario[TAMANHO_MAXIMO];
    gerar_fractal_iii(temporario, estagio - 1);

    resultado[0] = '\0';

    for (int i = 0; temporario[i] != '\0'; i++) {
        if (temporario[i] == 'X') {
            strcat(resultado, regra_x);
        } else if (temporario[i] == 'Y') {
            strcat(resultado, regra_y);
        } else {
            strncat(resultado, &temporario[i], 1);
        }
    }
}

void substituir_e_remover(char *resultado) {
    char final_resultado[TAMANHO_MAXIMO];
    int index = 0;
    for (int i = 0; resultado[i] != '\0'; i++) {
        if (resultado[i] != 'X' && resultado[i] != 'Y' && resultado[i] != 'P' && resultado[i] != 'Q') {
            final_resultado[index++] = resultado[i];
        }
    }
    final_resultado[index] = '\0';
    strcpy(resultado, final_resultado);
}

int main() {
    int estagio;
    printf("estagio 1, 2, 3 ou 4");
    scanf("%d", &estagio);

    if (estagio < 0 || estagio > 4) {
        return 1;
    }

    char resultado_i[TAMANHO_MAXIMO];
    char resultado_ii[TAMANHO_MAXIMO];
    char resultado_iii[TAMANHO_MAXIMO];

    gerar_fractal_i(resultado_i, estagio);
    gerar_fractal_ii(resultado_ii, estagio);
    gerar_fractal_iii(resultado_iii, estagio);

    substituir_e_remover(resultado_ii);
    substituir_e_remover(resultado_iii);

    FILE *arquivo_i = fopen("i.txt", "w");
    if (arquivo_i == NULL) {
        return 1;
    }
    fprintf(arquivo_i, "%s\n", resultado_i);
    fclose(arquivo_i);

    FILE *arquivo_ii = fopen("ii.txt", "w");
    if (arquivo_ii == NULL) {
        return 1;
    }
    fprintf(arquivo_ii, "%s\n", resultado_ii);
    fclose(arquivo_ii);

    FILE *arquivo_iii = fopen("iii.txt", "w");
    if (arquivo_iii == NULL) {
        return 1;
    }
    fprintf(arquivo_iii, "%s\n", resultado_iii);
    fclose(arquivo_iii);

    printf("fractais salvos em i.txt, ii.tx e iii.txt.\n");
    return 0;
}
