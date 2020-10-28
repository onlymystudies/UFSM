/*
1
*/

#include <stdio.h>
#include <stdlib.h>

void one_bigger(int **matrix);
void main() {
    int **m; // pointer to pointer matrix

    m = malloc(4 * sizeof(int *));

    for(int i = 0; i < 4; i++) {
        m[i] = malloc(4 * sizeof(int));
    }

    for(int line = 0; line < 4; line++) {
        for(int column = 0; column < 4; column++) {
            printf("line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
        }
    }

    one_bigger(m);
}
void one_bigger(int **matrix) {
    for (int i = 0; i < 4; i++) {
        for (int y = 0; y < 4; y++) {
            if (matrix[i][y] > 10) {
                printf("%d\n", matrix[i][y]);
            }
        }
    }

    free(matrix);
    system("pause");
}

/*
2
*/

#include <stdio.h>
#include <stdlib.h>

void two_print(int **matrix);
void main() {
    int **m;

    m = malloc(5 * sizeof(int *));

    for(int i = 0; i < 5; i++) {
        m[i] = malloc(5 * sizeof(int));
    }

    for(int line = 0; line < 5; line++) {
        for(int column = 0; column < 5; column++) {
            if (line == column) {
                m[line][column] = 1;
            } else {
                m[line][column] = 0;
            }
        }
    }

    two_print(m);
}
void two_print(int **matrix) {
    for(int line = 0; line < 5; line++) {
        for (int column = 0; column < 5; column++) {
            printf("%d ", *(*(matrix + line) + column)); // pointer arithmetic
            //printf("%d ", matrix[line][column]); // // subscribed
        }
        printf("\n");
    }

    free(matrix);
    system("pause");
}

/*
3
*/

#include <stdio.h>
#include <stdlib.h>

void three_print(int **matrix);
void main() {
    int **m;
    m = malloc(4 * sizeof(int *));

    for(int i = 0; i < 4; i++) {
        m[i] = malloc(4 * sizeof(int));
    }

    for(int line = 0; line < 4; line++) {
        for(int column = 0; column < 4; column++) {
            m[line][column] = line + column;
        }
    }

    three_print(m);
}
void three_print(int **matrix) {
    for(int line = 0; line < 4; line++) {
        for (int column = 0; column < 4; column++) {
            printf("%d ", *(*(matrix + line) + column)); // pointer
            //printf("%d ", matrix[line][column]); // // subscribed

        }
        printf("\n");
    }

    free(matrix);
    system("pause");
}

/*
4
*/

#include <stdio.h>
#include <stdlib.h>

void four_printf(int **matrix);
void main() {
    int **m;
    int tline = 0;
    int tcolumn = 0;
    m = malloc(4 * sizeof(int *));

    for(int i = 0; i < 4; i++) {
        m[i] = malloc(4 * sizeof(int));
    }

    for(int line = 0; line < 4; line++) {
        for(int column = 0; column < 4; column++) {
            printf("line %d column %d value:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
            if (line == 0 && column == 0) {
                tline = line;
                tcolumn = column;
            }
            if (m[line][column] > tline) {
                tline = line;
            }
            if (m[line][column] > tcolumn) {
                tcolumn = column;
            }
        }
    }

    printf("highest value position:\n");
    printf("line %d column %d\n\n", tline + 1, tcolumn + 1);

    four_printf(m);
}
void four_printf(int **matrix) {
    for(int line = 0; line < 4; line++) {
        for (int column = 0; column < 4; column++) {
            printf("%d ", *(*(matrix + line) + column)); // pointer
            //printf("%d ", matrix[line][column]); // subscribed
        }
        printf("\n");
    }

    free(matrix);
    system("pause");
}

/*
5
*/

#include <stdio.h>
#include <stdlib.h>

void five_print(int **matrix, int value);
void main() {
    int **m;
    int value;

    m = malloc(5 * sizeof(int *));

    for(int i = 0; i < 5; i++) {
        m[i] = malloc(5 * sizeof(int));
    }

    for(int line = 0; line < 5; line++) {
        for (int column = 0; column < 5; column++) {
            printf("line %d column %d value:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
        }
    }

    printf("search value:\n");
    scanf("%d", &value);

    five_print(m, value);
}
void five_print(int **matrix, int value) {
    int pLine = 0, pColumn = 0;

    for(int sLine = 0; sLine < 5; sLine++) {
        for (int sColumn = 0; sColumn < 5; sColumn++) {
            if(matrix[sLine][sColumn] == value) {
                pLine++;
                pColumn++;
            }
        }
    }
    if(pLine == 0 && pColumn == 0){
        printf("value not found\n");
    } else {
        printf("the value is in the line %d column %d\n", pLine, pColumn);
    }

    free(matrix);
    system("pause");
}

/*
6
*/

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void six_highest(int **matrix, int **matrix2);
void main() {
    int **m;
    m = malloc(4 * sizeof(int *));

    for(int i = 0; i < 4; i++) {
        m[i] = malloc(4 * sizeof(int));
    }

    for(int line = 0; line < 4; line++) {
        for(int column = 0; column < 4; column++) {
            printf("matrix 1 line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
            BufferClear();
        }
    }

    int **m2;
    m2 = malloc(4 * sizeof(int *));

    for(int i = 0; i < 4; i++) {
        m2[i] = malloc(4 * sizeof(int));
    }

    for(int line = 0; line < 4; line++) {
        for(int column = 0; column < 4; column++) {
            printf("matrix 2 line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m2[line][column]);
            BufferClear();
        }
    }

    six_highest(m, m2);
}
void six_highest(int **matrix, int **matrix2) {
    int **high;
    high = malloc(4 * sizeof(int *));

    for(int i = 0; i < 4; i++) {
        high[i] = malloc(4 * sizeof(int));
    }

    for(int line = 0; line < 4; line++) {
        for(int column = 0; column < 4; column++) {
            if(matrix[line][column] > matrix2[line][column]) {
                high[line][column] = matrix[line][column];
            } else {
                high[line][column] = matrix2[line][column];
            }
        }
    }
    for(int line = 0; line < 4; line++) {
        for (int column = 0; column < 4; column++) {
            printf("%d ", *(*(high + line) + column)); // pointer
            //printf("%d ", high[line][column]); // subscribed
        }
        printf("\n");
    }

    free(high);
    free(matrix);
    free(matrix2);
    system("pause");
}

/*
7
*/

#include <stdio.h>
#include <stdlib.h>

void seven_print(int **matrix);
void main() {
    int **m;

    m = malloc(10 * sizeof(int *));

    for(int i = 0; i < 10; i++) {
        m[i] = malloc(10 * sizeof(int));
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(i < j) {
                m[i][j] = 2 * i + 7 * j - 2;
            }
            if(i == j) {
                m[i][j] = 3 * (i * i) - 1;
            }
            if(i > j) {
                m[i][j] = 4 * (i * i * i) - 5 * (j * j) + 1;
            }
        }
    }

    seven_print(m);
}
void seven_print(int **matrix) {
    for(int line = 0; line < 4; line++) {
        for (int column = 0; column < 4; column++) {
            printf("%d ", *(*(matrix + line) + column)); //pointer
            //printf("%d ", matrix[line][column]); // subscribed
        }
        printf("\n");
    }

    free(matrix);
    system("pause");
}

/*
8
*/

#include <stdio.h>
#include <stdlib.h>

void eight_sum(int **matrix);
void main() {
    int **m;

    m = malloc(3 * sizeof(int *));

    for(int i = 0; i < 3; i++) {
        m[i] = malloc(3 * sizeof(int));
    }

    for(int line = 0; line < 3; line++) {
        for(int column = 0; column < 3; column++) {
            printf("line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
        }
    }

    eight_sum(m);
}
void eight_sum(int **matrix) {
    int total = 0;

    for(int line = 0; line < 3; line++) {
        for(int column = 0; column < 3; column++) {
            if(line != column && line != 2 && matrix[line][column] != matrix[1][0]) {
                total += matrix[line][column];
            }
        }
    }

    for(int pline = 0; pline < 3; pline++) {
        for (int pcolumn = 0; pcolumn < 3; pcolumn++) {
            printf("%d ", matrix[pline][pcolumn]); // subscribed
            //printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    printf("The sum of the values above the main diagonal is: %d\n", total);

    free(matrix);
    system("pause");
}

/*
9
*/

#include <stdio.h>
#include <stdlib.h>

void nine_sum(int **matrix);
void main() {
    int **m;

    m = malloc(3 * sizeof(int *));

    for(int i = 0; i < 3; i++) {
        m[i] = malloc(3 * sizeof(int));
    }

    for(int line = 0; line < 3; line++) {
        for(int column = 0; column < 3; column++) {
            printf("line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
        }
    }

    nine_sum(m);
}
void nine_sum(int **matrix) {
    int total = 0;

    for(int line = 0; line < 3; line++) {
        for(int column = 0; column < 3; column++) {
            if(line != column && line != 0 && matrix[line][column] != matrix[1][2]) {
                total += matrix[line][column];
            }
        }
    }

    for(int pline = 0; pline < 3; pline++) {
        for (int pcolumn = 0; pcolumn < 3; pcolumn++) {
            //printf("%d ", matrix[pline][pcolumn]); // subscribed
            printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    printf("The sum of the values below the main diagonal is: %d\n", total);

    free(matrix);
    system("pause");
}

/*
10
*/

#include <stdio.h>
#include <stdlib.h>

void ten_sum(int **matrix);
void main() {
    int **m;

    m = malloc(3 * sizeof(int *));

    for(int i = 0; i < 3; i++) {
        m[i] = malloc(3 * sizeof(int));
    }

    for(int line = 0; line < 3; line++) {
        for(int column = 0; column < 3; column++) {
            printf("line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
        }
    }

    ten_sum(m);
}
void ten_sum(int **matrix) {
    int total = 0;

    for(int line = 0; line < 3; line++) {
        for(int column = 0; column < 3; column++) {
            if(line == column) {
                total += matrix[line][column];
            }
        }
    }

    for(int pline = 0; pline < 3; pline++) {
        for (int pcolumn = 0; pcolumn < 3; pcolumn++) {
            //printf("%d ", matrix[pline][pcolumn]); // subscribed
            printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    printf("The sum of the values below the main diagonal is: %d\n", total);

    free(matrix);
    system("pause");
}

/*
11
*/

#include <stdio.h>
#include <stdlib.h>

void eleven_calc(int **matrix) {
    int total = 0;
    int column = 2;

    for (int line = 0; line < 3; line++) {
        total += matrix[line][column];
        column--;
    }

    for(int pline = 0; pline < 3; pline++) {
        for (int pcolumn = 0; pcolumn < 3; pcolumn++) {
            //printf("%d ", matrix[pline][pcolumn]); // subscribed
            printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    printf("The total of the secondary diagonal line is: %d\n", total);
    system("pause");
}

void main() {
    int **m;

    m = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        m[i] = malloc(3 * sizeof(int));
    }

    for (int line = 0; line < 3; line++) {
        for (int column = 0; column < 3; column++) {
            printf("line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
        }
        system("cls");
    }

    eleven_calc(m);
}

/*
12
*/

#include <stdio.h>
#include <stdlib.h>

void twelve_calc(int **matrix) {
    int total = 0;

    for (int line = 0; line < 3; line++) {
        for (int column = 0; column < 3; column++) {
            total += matrix[line][column];
        }
    }

    for(int pline = 0; pline < 3; pline++) {
        for (int pcolumn = 0; pcolumn < 3; pcolumn++) {
            //printf("%d ", matrix[pline][pcolumn]); // subscribed
            printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    puts("\ntransposed:\n");

    int pline2 = 0;
    for (int pcolumn2 = 0; pcolumn2 < 3; pcolumn2++) {
        //printf("%d ", matrix[pline][pcolumn]); // subscribed
        printf("%d ", *(*(matrix + pline2) + pcolumn2)); // pointer
        printf("%d ", matrix[1][pcolumn2]);
        printf("%d", matrix[2][pcolumn2]);
        printf("\n");
    }

    printf("The total of the transpose is: %d\n", total);
    system("pause");
}

void main() {
    int **m;

    m = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        m[i] = malloc(3 * sizeof(int));
    }

    for (int line = 0; line < 3; line++) {
        for (int column = 0; column < 3; column++) {
            printf("line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
        }
        system("cls");
    }

    twelve_calc(m);
}

/*
13
*/

#include <stdio.h>
#include <stdlib.h>

void thirteen_calc(int **matrix) {
    for (int pline = 0; pline < 4; pline++) {
        for (int pcolumn = 0; pcolumn < 4; pcolumn++) {
            //printf("%d ", matrix[pline][pcolumn]); // subscribed
            printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    puts("\ntriangular:\n");

    for (int pline = 0; pline < 4; pline++) {
        for (int pcolumn = 0; pcolumn < 4; pcolumn++) {
            if (pline == 0 && pcolumn == 1) {
                matrix[pline][pcolumn] = 0;
            }
            if (pline == 0 && pcolumn == 2) {
                matrix[pline][pcolumn] = 0;
            }
            if (pline == 0 && pcolumn == 3) {
                matrix[pline][pcolumn] = 0;
            }
            if (pline == 1 && pcolumn == 2) {
                matrix[pline][pcolumn] = 0;
            }
            if (pline == 1 && pcolumn == 3) {
                matrix[pline][pcolumn] = 0;
            }
            if (pline == 2 && pcolumn == 3) {
                matrix[pline][pcolumn] = 0;
            }
        }
    }

    for (int pline = 0; pline < 4; pline++) {
        for (int pcolumn = 0; pcolumn < 4; pcolumn++) {
            //printf("%d ", matrix[pline][pcolumn]); // subscribed
            printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    system("pause");
}

void main() {
    int **m;
    int number = 1;

    m = malloc(4 * sizeof(int *));

    for (int i = 0; i < 4; ++i) {
        m[i] = malloc(4 * sizeof(int));
    }

    for (int line = 0; line < 4; line++) {
        for (int column = 0; column < 4; column++) {
            m[line][column] = number;
            number++;
        }
        system("cls");
    }

    thirteen_calc(m);
}

/*
14
*/

#include <stdio.h>
#include <stdlib.h>

void generate(int **matrix);
void print(int **matrix) {
    for (int pline = 0; pline < 5; pline++) {
        for (int pcolumn = 0; pcolumn < 5; pcolumn++) {
            //printf("%d ", matrix[pline][pcolumn]); // subscribed
            printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    int new = 0;
    printf("[1] New generate\n");
    scanf("%d", &new);

    if (new != 0) {
        generate(matrix);
    }

    system("pause");
}
int number = 0;

void generate(int **matrix) {

    if (number == 100 || number > 100) {
        printf("Number exceeded\n");
        system("pause");
    }

    for (int line = 0; line < 5; line++) {
        for (int column = 0; column < 5; column++) {
            matrix[line][column] = number;
            number++;
        }
        system("cls");
    }

    print(matrix);
}

void main() {
    int **m;

    m = malloc(5 * sizeof(int *));

    for (int i = 0; i < 5; ++i) {
        m[i] = malloc(5 * sizeof(int));
    }

    generate(m);

    print(m);
}

/*
15
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int resultado[5] = {0,0,0,0,0};

    char **m;
    char v[10] = {'a','b','c','d','a','b','c','d','a','b'};

    m = malloc(5 * sizeof(char *)); // 5 alunos

    for (int i = 0; i < 5; ++i) { // 10 questoes
        m[i] = malloc(10 * sizeof(char));
    }

    for (int i = 0; i < 5; ++i) {
        printf("Aluno %d\n", i + 1);
        for (int j = 0; j < 10; ++j) {
            printf("Questao %d:\n", j + 1);
            scanf("%s", &m[i][j]);
        }
        system("cls");
    }

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 10; ++j)
            if (m[i][j] == v[j])
                resultado[i]++;

    for (int i = 0; i < 5; ++i) {
        printf("Aluno %d\n", i + 1);
        printf("%d pontos\n", resultado[i]);
        puts("===================");
    }

    system("pause");
}

/*
16
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float resultado[3] = {0,0,0};
    float soma = 0;
    char matricula[3][64];
    char **m;
    char v[10] = {'a','b','c','d','e','a','b','c','d','e'};

    m = malloc(3 * sizeof(char *)); // 5 alunos

    for (int i = 0; i < 3; ++i) {
        m[i] = malloc(10 * sizeof(char)); // 10 questoes
    }

    for (int i = 0; i < 3; ++i) {
        printf("Aluno %d\n", i + 1);
        printf("Matricula:\n");
        scanf("%s", &matricula[i]);

        for (int j = 0; j < 10; ++j) {
            printf("Questao %d:\n", j + 1);
            scanf("%s", &m[i][j]);
        }
        system("cls");
    }

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 10; ++j)
            if (m[i][j] == v[j])
                resultado[i]++;

    for (int i = 0; i < 3; ++i) {
        printf("Aluno %d\n", i + 1);
        printf("Matricula %s\n", matricula[i]);
        puts("Respostas:");
        for (int j = 0; j < 10; ++j)
            printf("%c\n", m[i][j]);
        printf("%.2f pontos\n", resultado[i]);
        puts("===================");
    }

    for (int i = 0; i < 3; ++i)
        if (resultado[i] != 0)
            soma += resultado[i];

    printf("Percentual de aprovador: %.2f%%\n", (soma / 30) * 100);

    system("pause");
}

/*
17
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int piornota, piornota1 = 0, piornota2 = 0, piornota3 = 0;
    int **m;

    m = malloc(10 * sizeof(int *)); // 10 alunos

    for (int i = 0; i < 10; ++i) {
        m[i] = malloc(3 * sizeof(int)); // 3 Provas
    }

    for (int i = 0; i < 10; ++i) {
        printf("Aluno: %d\n", i + 1);
        for (int j = 0; j < 3; ++j) {
            printf("Prova %d:\n", j + 1);
            scanf("%d", &m[i][j]);
        }
        system("cls");
    }

    for (int i = 0; i < 10; ++i) {
        piornota = 10;
        for (int j = 0; j < 3; ++j) {
            if (m[i][j] < piornota)
                piornota = m[i][j];
        }

        if (piornota == m[i][0]) {
            piornota1++;
        }

        if (piornota == m[i][1] && piornota != m[i][0]) {
            piornota2++;
        }

        if (piornota == m[i][2] && piornota != m[i][1] && piornota != m[i][0]) {
            piornota3++;
        }
    }

    printf("Piores notas na prova 1: %d aluno(s)\n", piornota1);
    printf("Piores notas na prova 2: %d aluno(s)\n", piornota2);
    printf("Piores notas na prova 3: %d aluno(s)\n", piornota3);

    system("pause");
}

/*
18
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int w = 0;
    int **m;
    int vector[3] = {0,0,0};

    m = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        m[i] = malloc(3 * sizeof(int));
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("coluna %d:\n", i + 1);
            scanf("%d", &m[i][j]);
        }
        system("cls");
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            vector[i] += m[i][j];
        }
    }

    printf("vetor final:\n");
    while (w < 3) {
        printf("%d\n", vector[w]);
        w++;
    }

    system("pause");
}

/*
19
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int maiornota = 0, matricula, medianotasfinais = 0;
    int **m;

    m = malloc(5 * sizeof(int *));

    for (int i = 0; i < 5; ++i) {
        m[i] = malloc(4 * sizeof(int));
    }

    for (int i = 0; i < 5; ++i) {
        printf("Estudante %d\n", i + 1);
        puts("Numero de matricula:");
        scanf("%d", &m[i][0]);
        puts("Media das provas:");
        scanf("%d", &m[i][1]);
        puts("Media dos trabalhos:");
        scanf("%d", &m[i][2]);
        m[i][3] = (m[i][1] + m[i][2]) / 2;
        medianotasfinais += m[i][3];
        system("cls");
    }

    for (int i = 0; i < 5; ++i) {
        if (m[i][3] > maiornota) {
            maiornota = m[i][3];
            matricula = i;
        }
    }

    printf("Maior media final: %d\n", m[matricula][3]);
    printf("Matricula: %d\n", m[matricula][0]);
    printf("Soma media notas final: %d\n", medianotasfinais);
    system("pause");
}

/*
20
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float soma = 0, media = 0;
    float **m;

    m = malloc(3 * sizeof(float *));

    for (int i = 0; i < 3; ++i) {
        m[i] = malloc(6 * sizeof(float));
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            printf("Numero linha %d coluna %d:\n", i + 1, j + 1);
            scanf("%f", &m[i][j]);
        }
        system("cls");
    }

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 6; ++j) {
            if (i % 2 != 0) {
                soma += m[i][j]; // A
            }

            if (j == 2 || j == 4) {
                media += m[i][j]; // B
            }

            if (j == 6) {
                m[i][j] = m[i][1] + m[i][2]; // C
            }
        }

    system("cls");

    printf("Soma :%.2f\n", soma);

    printf("Media :%.2f\n", media/6);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            printf("%.f  ", m[i][j]);
        }
        printf("\n");
    }

    system("pause");
}

/*
21
*/

#include <stdio.h>
#include <stdlib.h>

void menu(float **m, float **m2);

void d(float **m, float **m2) {
    system("cls");

    puts("matriz 1");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%.f\t", m[i][j]);
        }
        printf("\n");
    }

    puts("matriz 2");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%.f\t", m2[i][j]);
        }
        printf("\n");
    }

    int retorna;
    printf("[0] Retornar\n[1] Sair\n");
    scanf("%d", &retorna);
    if (retorna == 0)
        menu(m, m2);
    else
        exit(0);
}

void c(float **m, float **m2) {
    system("cls");

    float aux;

    puts("Constante para as duas matrizes");
    scanf("%f", &aux);

    m[0][0] = aux;
    m2[0][0] = aux;

    puts("Adicionado com sucesso!");

    int retorna;
    printf("[0] Retornar\n[1] Sair\n");
    scanf("%d", &retorna);
    if (retorna == 0)
        menu(m, m2);
    else
        exit(0);
}


void b(float **m, float **m2) {
    system("cls");

    float **m3;

    m3 = malloc(2 * sizeof(float *));

    for (int i = 0; i < 2; ++i) {
        m3[i] = malloc(2 * sizeof(float));
    }

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            m3[i][j] = m[i][j] - m2[i][j];

    puts("Subtraido com sucesso!");

    int retorna;
    printf("[0] Retornar\n[1] Sair\n");
    scanf("%d", &retorna);
    if (retorna == 0)
        menu(m, m2);
    else
        exit(0);
}

void a(float **m, float **m2) {
    system("cls");

    float **m3;

    m3 = malloc(2 * sizeof(float *));

    for (int i = 0; i < 2; ++i) {
        m3[i] = malloc(2 * sizeof(float));
    }

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            m3[i][j] = m[i][j] + m2[i][j];

    puts("Somado com sucesso!");

    int retorna;
    printf("[0] Retornar\n[1] Sair\n");
    scanf("%d", &retorna);
    if (retorna == 0)
        menu(m, m2);
    else
        exit(0);
}



void menu(float **m, float **m2) {
    system("cls");

    int menu = 0;

    puts("(1) Soma as duas matrizes");
    puts("(2) Subtrair a primeira matriz da segunda");
    puts("(3) Adicionar uma constante as duas matrizes");
    puts("(4) Imprimir as matrizes");
    scanf("%d", &menu);

    while (menu != 5) {
        switch (menu) {
            case 1:
                a(m, m2);
                break;
            case 2:
                b(m, m2);
                break;
            case 3:
                c(m, m2);
                break;
            case 4:
                d(m, m2);
                break;
            default:
                printf("Nao existe\n");
        }
    }

}

int main() {
    float **m;
    float **m2;

    m = malloc(2 * sizeof(float *));

    m2 = malloc(2 * sizeof(float *));

    for (int i = 0; i < 2; ++i) {
        m[i] = malloc(2 * sizeof(float));
    }

    for (int i = 0; i < 2; ++i) {
        m2[i] = malloc(2 * sizeof(float));
    }

    puts("Matriz 1:");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("Numero linha %d coluna %d:\n", i + 1, j + 1);
            scanf("%f", &m[i][j]);
        }
        system("cls");
    }

    puts("Matriz 2:");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("Numero linha %d coluna %d:\n", i + 1, j + 1);
            scanf("%f", &m2[i][j]);
        }
        system("cls");
    }

    menu(m, m2);
}

/*
22
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int **a;

    a = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        a[i] = malloc(3 * sizeof(int));
    }

    puts("Matriz A");
    for (int i = 0; i < 3; ++i) {
        printf("linha %d\n", i + 1);
        for (int j = 0; j < 3; ++j) {
            printf("coluna %d: \n", j + 1);
            scanf("%d", &a[i][j]);
        }
        system("cls");
    }

    system("cls");

    int **b;

    b = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        b[i] = malloc(3 * sizeof(int));
    }

    puts("Matriz B");
    for (int i = 0; i < 3; ++i) {
        printf("linha %d\n", i + 1);
        for (int j = 0; j < 3; ++j) {
            printf("coluna %d: \n", j + 1);
            scanf("%d", &b[i][j]);
        }
        system("cls");
    }

    system("cls");

    int **c;

    c = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        c[i] = malloc(3 * sizeof(int));
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }

    puts("Matriz C");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    system("pause");
}

/*
23
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int **a;

    a = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        a[i] = malloc(3 * sizeof(int));
    }

    puts("Matriz A");
    for (int i = 0; i < 3; ++i) {
        printf("linha %d\n", i + 1);
        for (int j = 0; j < 3; ++j) {
            printf("coluna %d: \n", j + 1);
            scanf("%d", &a[i][j]);
        }
        system("cls");
    }

    system("cls");

    int **a2;

    a2 = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        a2[i] = malloc(3 * sizeof(int));
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            a2[i][j] = a[i][j] * a[i][j];
        }
    }

    system("cls");

    puts("Matriz A2");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t", a2[i][j]);
        }
        printf("\n");
    }

    system("pause");
}

/*
25
*/

#include <stdio.h>
#include <stdlib.h>

int posicao(int **a);
int valores(int **a);
void nova_jogada(int **a);

struct posicao {
    int linha;
    int coluna;
}p;

void colocar(int **a, int aux) {
    a[p.linha][p.coluna] = aux;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    nova_jogada(a);
}

void nova_jogada(int **a) {
    int new;
    printf("[1] Nova jogada\n[0] Sair\n");
    scanf("%d", &new);
    if (new == 1)
        posicao(a);
    else
        exit(0);
}

int valores(int **a) {
    int aux;
    puts("[-1] X");
    puts("[1] O");
    scanf("%d", &aux);

    colocar(a, aux);
}

int posicao(int **a) {
    puts("Linha:");
    scanf("%d", &p.linha);

    puts("Coluna:");
    scanf("%d", &p.coluna);

    valores(a);
}

int main() {
    int **a;

    a = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        a[i] = malloc(3 * sizeof(int));
    }

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            a[i][j] = 0;

    posicao(a);

    system("pause");
}