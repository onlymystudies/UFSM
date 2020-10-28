/*
1
*/

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void One_B(int *vector);
void main() {
    int A[6] = {1, 0, 5, -2, -5, 7}; // (a)
    int *pA = A; // Para que & funcione, tens que declarar

    One_B(pA);
}
void One_D(int *vector) {
    for (int i = 0; i <= 5; i++) {
        //printf("%d\n", vector[i]); // subscript notation; auto variable increment
        printf("%d\n", *vector++); // pointer notation; pointer offset
    }

    free(vector);
    system("pause");
}
void One_C(int *vector) {
    vector[4] = 100;

    One_D(vector);
}
void One_B(int *vector) {
    int total = vector[0] + vector[1] + vector[5];

    printf("Vector sum of the position 0, 1 and 5: %d\n", total);

    One_C(vector);
}

/*
2
*/

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Two_print(int *vector);
void main() {
    int vector[6];
    int *v = vector;

    printf("Insert 6 values for the vector\n");
    for (int i = 0; i <= 5; i++) {
        printf("Value %d:\n", i+1);
        scanf("%d", &v[i]); // subscript notation; auto variable increment
        BufferClear();
    }

    Two_print(v);
}
void Two_print(int *vector) {
    printf("Values read:\n");

    for (int i = 0; i <= 5; i++) {
        printf("%d", vector[i]); // subscript notation; auto variable increment
        //printf("%d", *vector++); // pointer notation; pointer offset
    }

    free(vector);
    system("pause");
}

/*
3
*/

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Three_square(int *vector);
void main() {
    int vector[10];
    int *v = vector;

    for (int i = 1; i <= 10; i++) {
        printf("Value %d:", i);
        scanf("%d", &v[i]);
        BufferClear();
    }

    Three_square(v);
}
void Three_print(int *vector, int *vector2) {
    int i = 1;
    int y = 1;

    printf("\nFirst vector:\n");
    while (i < 11) {
        printf("%d\n", vector[i]);
        i++;
    }

    printf("\nSecond vector:\n");
    while (y < 11) {
        printf("%d\n", vector2[y]);
        y++;
    }

    free(vector);
    system("pause");
}
void Three_square(int *vector) {
    int vector2[10];
    int *v = vector2;
    int i = 1;

    while(i < 11)
    {
        vector2[i] = vector[i] * vector[i];
        i++;
    }

    Three_print(vector, v);
}

/*
4
*/

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void four_values(int *vector);
void main() {
    int vector[8];
    int *v = vector;
    int i = 0;

    while(i < 8) {
        printf("%d value:\n", i+1);
        scanf("%d", &v[i]);
        //scanf("%d", &vector[i]);
        BufferClear();
        i++;
    }

    four_values(v);
}
void four_sum(int *vector, int *values) {
    int sum = 0;
    int value1 = values[0];
    int value2 = values[1];

    sum = vector[value1-1] + vector[value2-1];

    printf("The sum of positions %d and %d of the vector is: %d\n", value1, value2, sum);

    free(vector);
    system("pause");
}
void four_values(int *vector) {
    int values[1];
    int *v = values;

    printf("Insert first value for sum on position in vector:\n");
    scanf("%d", &v[0]);
    BufferClear();
    printf("Insert second value for sum on position in vector:\n");
    scanf("%d", &v[1]);
    BufferClear();

    four_sum(vector, v);
}

/*
5
*/

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void five_pairs(int *vector);
void main() {
    int vector[10];
    int *v = vector;
    int i = 0;

    while(i < 10) {
        printf("%d value:\n", i+1);
        scanf("%d", &v[i]);
        i++;
    }

    five_pairs(v);
}
void five_pairs(int *vector) {
    int total = 0;
    int i = 0;

    while(i < 10) {
        if (vector[i] % 2 == 0) {
            total += 1;
        }
        i++;
    }

    printf("Total pairs: %d\n", total);
    free(vector);
    system("pause");
}

/*
6
*/

#include <stdio.h>
#include <stdlib.h>

void six_bigger(int *vector);
void main() {
    int vector[10];
    int *v = vector;
    int i = 0;

    while(i < 10) {
        printf("%d value:\n", i+1);
        scanf("%d", &v[i]);
        i++;
    }

    six_bigger(v);
}
void six_lowest(int *vector) {
    int i = 0;
    int total = 0;

    while(i < 10) {
        if (i == 0) {
            total = vector[i];
        }
        if (vector[i] < total) {
            total = vector[i];
        }
        i++;
    }

    printf("Lowest number: %d\n", total);

    system("pause");
}
void six_bigger(int *vector) {
    int i = 0;
    int total = 0;

    while(i < 10) {
        if (i == 0) {
            total = vector[i];
        }
        if (vector[i] > total) {
            total = vector[i];
        }
        i++;
    }

    printf("Bigger number: %d\n", total);

    free(vector);
    six_lowest(vector);
}

/*
7
*/

#include <stdio.h>
#include <stdlib.h>

void seven_bigger(int *vector);
void main() {
    int *v = (int *) malloc(10 * sizeof(int));
    int i = 0;

    while(i < 10) {
        printf("%d value:\n", i+1);
        scanf("%d", &v[i]);
        i++;
    }

    seven_bigger(v);
}
void seven_bigger(int *vector) {
    int i = 0;
    int total = 0;
    int position = 0;

    while(i < 10) {
        if (i == 0) {
            total = vector[i];
        }
        if (vector[i] > total) {
            total = vector[i];
            position = i;
        }
        i++;
    }

    printf("Vector:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", *vector++);
        //printf("%d", vector[i]);
    }
    printf("Biggest value %d in position %d\n", total, position + 1);

    free(vector);
    system("pause");
}

/*
8
*/

#include <stdio.h>
#include <stdlib.h>

void eight_reverse(int *vector);
void main() {
    int *v = (int *) malloc(6 * sizeof(int));
    int i = 0;

    while(i < 6) {
        printf("%d value:\n", i + 1);
        scanf("%d", &v[i]);
        i++;
    }

    eight_reverse(v);
}
void eight_reverse(int *vector) {
    int i = 5;

    printf("reverse vector:\n");
    while(i > -1) {
        printf("%d\n", (*(vector+i))); // pointer
        //printf("%d\n", vector[i]); // subscribed
        i--;
    }

    free(vector);
    system("pause");
}

/*
9
*/

#include <stdio.h>
#include <stdlib.h>

void nine_reverse(int *vector);
void main() {
    int *v = (int *) malloc(6 * sizeof(int));
    int aux;
    int i = 0, y = 0;

    do {
        printf("%d value (only pairs):\n", y + 1);
        scanf("%d", &aux);
        if (aux % 2 == 0) {
            v[y] = aux;
            y++;
        } else {
            printf("this number is not pair\n");
        }
    } while(y != 6);

    nine_reverse(v);
}
void nine_reverse(int *vector) {
    int i = 5;

    printf("reverse vector:\n");
    while(i > -1) {
        printf("%d\n", (*(vector+i))); // pointer
        //printf("%d\n", vector[i]); // subscribed
        i--;
    }

    free(vector);
    system("pause");
}

/*
10
*/

#include <stdio.h>
#include <stdlib.h>

void ten_average(int *vector);
void main() {
    int *v = (int *) malloc(15 * sizeof(int));
    int i;

    while(i < 15) {
        printf("%d value:\n", i + 1);
        scanf("%d", &v[i]);
        i++;
    }

    ten_average(v);
}
void ten_average(int *vector) {
    int i = 0;
    int total = 0;

    do {
        total += vector[i];
        i++;
    } while(i != 15);

    printf("average: %d", total/15);
    free(vector);
    system("pause");
}

/*
11
*/

#include <stdio.h>
#include <stdlib.h>

void eleven_calc(int *vector);
void main() {
    int *v = malloc(10 * sizeof(int));
    int i;

    while(i < 10) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        i++;
    }

    eleven_calc(v);
}
void eleven_calc(int *vector) {
    int i = 0;
    int positive = 0, negative = 0;

    while(i < 10) {
        if(vector[i] > 0) {
            positive += vector[i];
        } else {
            negative += 1;
        }
        i++;
    }

    printf("the sum of the positive number is %d and %d negative numbers\n", positive, negative);
    free(vector);
    system("pause");
}

/*
12
*/

#include <stdio.h>
#include <stdlib.h>

void twelve_calc(int *vector);
void main() {
    int *v = malloc(5 * sizeof(int));
    int i = 0;

    while(i < 5) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        i++;
    }

    twelve_calc(v);
}
void twelve_calc(int *vector) {
    int biggest = 0;
    int lowest = 0;
    int total = 0;
    int i = 0;

    while(i < 5) {
        if(i == 0) {
            biggest = vector[i];
            lowest = vector[i];
        }
        if(vector[i] > biggest) {
            biggest = vector[i];
        }
        if(vector[i] < lowest) {
            lowest = vector[i];
        }
        total += vector[i];
        i++;
    }

    printf("avg of values: %d\n", total / 5);
    printf("biggest number: %d\n", biggest);
    printf("lowest number: %d\n", lowest);

    free(vector);
    system("pause");
}

/*
13
*/

#include <stdio.h>
#include <stdlib.h>

void thirteen_calc(int *vector);
void main() {
    int *v = malloc(5 * sizeof(int));
    int i = 0;

    while(i < 5) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        i++;
    }

    thirteen_calc(v);
}
void thirteen_calc(int *vector) {
    int bposition = 0;
    int lposition = 0;
    int biggest = 0;
    int lowest = 0;
    int i = 0;

    while(i < 5) {
        if(i == 0) {
            biggest = vector[i];
            lowest = vector[i];
        }
        if(vector[i] > biggest) {
            biggest = vector[i];
            bposition = i;
        }
        if(vector[i] < lowest) {
            lowest = vector[i];
            lposition = i;
        }
        i++;
    }

    printf("biggest number is in position: %d\n", bposition + 1);
    printf("lowest number is in position: %d\n", lposition + 1);

    free(vector);
    system("pause");
}

/*
14
*/

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void fourteen_calc(int *vector);
void main() {
    int *v = malloc(10 * sizeof(int));
    int i = 0;

    while(i < 10) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        BufferClear();
        i++;
    }

    fourteen_calc(v);
}
void fourteen_calc(int *vector) {
    int j;
    for(int i = 0;  i < 10; i++) {
        for(j = i + 1; j < 10; j++){
            if(vector[i] == vector[j]) {
                if(vector[i] != vector[i-1]) {
                    printf("%d is a repeated number \n", vector[i]); // subscribed
                    //printf("%d is a repeated number \n", (*(vector+i))); // pointer
                }
            }
        }
    }

    free(vector);
    system("pause");
}

/*
15
*/

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void fifteen_calc(int *vector);
void main() {
    int *v = malloc(20 * sizeof(int));
    int i = 0;

    while(i < 20) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        BufferClear();
        i++;
    }

    fifteen_calc(v);
}
void fifteen_calc(int *vector) {
    int j;

    for(int i = 0;  i < 20; i++) {
        for(j = i + 1; j < 20; j++){
            if(vector[i] == vector[j]) {
                if(vector[i] != vector[i-1]) {
                    vector[i] = 0;
                }
            }
        }
    }

    for(int x = 0;  x < 20; x++) {
        if(vector[x] != 0) {
            printf("value: %d\n", vector[x]); // subscribed
            //printf("value: %d\n", (*(vector+x))); // pointer
        }
    }

    free(vector);
    system("pause");
}

/*
16
*/

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void sixteen_direct(int *vector);
void sixteen_reverse(int *vector);
void main() {
    int i = 0;
    int menu;
    int *v = malloc(5 * sizeof(int));

    while (i < 5) {
        printf("vector value: %d\n", i + 1);
        scanf("%d", &v[i]);
        BufferClear();
        i++;
    }

    printf ("\n\t [1]  Direct Vector  [2]  Reverse Vector \n");
    printf ("\t [0]  Exit \n");
    scanf("%d", &menu);
    BufferClear();

    while (menu != 3) {
        switch (menu) {
            case 0:
                exit(0);
            case 1:
                sixteen_direct(v);
                break;
            case 2:
                sixteen_reverse(v);
                break;
            default:
                printf("invalid code");
        }
    }

}
void sixteen_reverse(int *vector) {
    int i = 4;
    while(i > -1) {
        printf("value: %d \n", vector[i]);
        //printf("value: %d \n", (*(vector+i)));
        i--;
    }

    free(vector);
    system("pause");
}
void sixteen_direct(int *vector) {
    int i = 0;
    while(i < 5) {
        printf("value: %d \n", vector[i]);
        //printf("value: %d \n", (*(vector+i)));
        i++;
    }

    free(vector);
    system("pause");
}

/*
17
*/

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void seventeen_alloca(int *vector);
void main() {
    int *v = malloc(10 * sizeof(int));
    int i = 0;

    while(i < 10) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        BufferClear();
        i++;
    }

    seventeen_alloca(v);
}
void seventeen_alloca(int *vector) {
    int i = 0;

    while(i < 10) {
        if(vector[i] < 0) {
            vector[i] = 0;
        }
        printf("value: %d\n", (*(vector+i)));
        //printf("value: %d\n", vector[i]);
        i++;
    }

    free(vector);
    system("pause");
}

/*
18
*/

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void eighteen_multi(int *vector, int n);
void main() {
    int *v = malloc(10 * sizeof(int));
    int i = 0;
    int number;

    while(i < 10) {
        printf("value %d:\n", i + 1);
        scanf("%d", &v[i]);
        BufferClear();
        i++;
    }

    printf("number for the multiplication:\n");
    scanf("%d", &number);

    eighteen_multi(v, number);
}
void eighteen_multi(int *vector, int n) {
    int i = 0;
    while(i < 10) {
        vector[i] *= n;
        i++;
    }
    i = 0;
    while(i < 10) {
        printf("value: %d\n", (*(vector+i)));
        //printf("value: %d\n", vector[i]);
        i++;
    }

    free(vector);
    system("pause");
}

/*
19
*/

#include <stdio.h>
#include <stdlib.h>

void nineteen_print(int *vector);
void main() {
    int i = 0;
    int *v = malloc(50 * sizeof(int));

    while (i < 50) {
        v[i] = (i + 5 * i) % (i + 1);
        i++;
    }

    nineteen_print(v);
}
void nineteen_print(int *vector) {
    int i = 0;
    while (i < 50) {
        printf("value: %d\n", vector[i]);
        //printf("value: %d\n", (*(vector+i)));
        i++;
    }

    free(vector);
    system("Pause");
}

/*
20
*/

#include <stdio.h>
#include <stdlib.h>

void twenty_print(int *vector);
void main() {
    int i = 0;
    int number;
    int *v = malloc(10 * sizeof(int));

    while (i < 10) {
        printf("value under 50 above 0:\n");
        scanf("%d", &number);
        if (number > 0 && number < 50) {
            v[i] = number;
        } else {
            printf("this number not correspond the specification");
        }
        i++;
    }

    twenty_print(v);
}
void twenty_print(int *vector) {
    int i = 0;

    while (i < 10) {
        printf("value: %d\n", vector[i]);
        //printf("value: %d\n", (*(vector+i)));
        i++;
    }

    free(vector);
    system("pause");
}

/*
21
*/

#include <stdio.h>
#include <stdlib.h>

void twentyone_sub(int *vector, int *vector2);
void main() {
    int i = 0;
    int *v = malloc(10 * sizeof(int));
    int *v2 = malloc(10 * sizeof(int));

    while (i < 10) {
        printf("vector 1, position %d value:\n", i + 1);
        scanf("%d", &v[i]);
        i++;
    }
    i = 0;
    while (i < 10) {
        printf("vector 2, position %d value:\n", i + 1);
        scanf("%d", &v2[i]);
        i++;
    }

    twentyone_sub(v, v2);
}
void twentyone_sub(int *vector, int *vector2) {
    int *c = malloc(10 * sizeof(int));
    int i = 0;

    while (i < 10) {
        c[i] = vector[i] - vector2[i];
        printf("value: %d\n", c[i]);
        //printf("value: %d\n", *c++)
        i++;
    }

    free(c);
    free(vector);
    free(vector2);
    system("pause");
}

/*
22
*/

#include <stdio.h>
#include <stdlib.h>

void twentytwo_vec(int *vector, int *vector2);
void main() {
    int i = 0;
    int *a = malloc(10 * sizeof(int));
    int *b = malloc(10 * sizeof(int));

    while (i < 10) {
        printf("vector 1, position %d value:\n", i + 1);
        scanf("%d", &a[i]);
        i++;
    }
    i = 0;
    while (i < 10) {
        printf("vector 2, position %d value:\n", i + 1);
        scanf("%d", &b[i]);
        i++;
    }

    twentytwo_vec(a, b);
}
void twentytwo_vec(int *vector, int *vector2) {
    int *v = malloc(10 * sizeof(int));
    int i = 0;

    while (i < 10) {
        if (i % 2 == 0) {
            v[i] = vector[i];
        } else {
            v[i] = vector2[i];
        }
        i++;
    }
    i = 0;
    while (i < 10) {
        printf("Value: %d\n", v[i]);
        //printf("Value: %d\n", *vector++);
        i++;
    }

    free(v);
    free(vector);
    free(vector2);
    system("pause");
}

/*
23
*/

#include <stdio.h>
#include <stdlib.h>

void twentythree_scalar(int *vector, int *vector2);
void main() {
    int i = 0;
    int *a = malloc(5 * sizeof(int));
    int *b = malloc(5 * sizeof(int));

    while (i < 5) {
        printf("vector 1, position %d value:\n", i + 1);
        scanf("%d", &a[i]);
        i++;
    }
    i = 0;
    while (i < 5) {
        printf("vector 2, position %d value:\n", i + 1);
        scanf("%d", &b[i]);
        i++;
    }

    twentythree_scalar(a, b);
}
void twentythree_scalar(int *vector, int *vector2) {
    int i = 0;
    int scalar = 0;

    while (i < 5) {
        scalar += vector[i] * vector2[i];
        i++;
    }

    i = 0;
    printf("vector 1:\n");
    while (i < 5) {
        printf("[");
        printf("%d", vector[i]);
        //printf("%d", *vector++);
        printf("]");
        i++;
    }
    i = 0;
    printf("\nvector 2:\n");
    while (i < 5) {
        printf("[");
        printf("%d", vector2[i]);
        //printf("%d", *vector2++);
        printf("]");
        i++;
    }

    printf("\nscalar product: %d\n", scalar);

    free(vector);
    free(vector2);
    system("pause");
}

/*
24
*/

#include <stdio.h>
#include <stdlib.h>

void BufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void twentyfour_search(int *vector, int *vector2);
void main() {
    int *number = malloc(10 * sizeof(int));
    int *height = malloc(10 * sizeof(int));
    int i = 0;

    while (i < 10) {
        printf("student %d, number:\n", i + 1);
        scanf("%d", &number[i]);
        BufferClear();
        printf("student %d, height:\n", i + 1);
        scanf("%d", &height[i]);
        BufferClear();
        i++;
    }

    twentyfour_search(number , height);
}
void twentyfour_search(int *vector, int *vector2) {
    int i = 0;
    int higher;
    int hnumber;
    int lower;
    int lnumber;


    while (i < 10) {
        if (i == 0) {
            lower = vector2[i];
            higher = vector2[i];
        }

        if (vector2[i] > higher) {
            higher = vector2[i];
            hnumber = vector[i];
        }
        if (vector2[i] < lower) {
            lower = vector2[i];
            lnumber = vector[i];
        }

        i++;
    }


    printf("the higher student is %d, %d\n", hnumber, higher);
    printf("the lower student is %d, %d\n", lnumber, lower);

    free(vector);
    free(vector2);
    system("pause");
}

/*
25
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = malloc(100 * sizeof(int));
    int number, i = 0;

    while (i < 100) {
        do {
            printf("%d Digite um numero:\n", i + 1);
            scanf("%d", &number);

            if (number % 7 != 0) {
                printf("O numero nao e multiplo de 7 ");
                if (number % 10 != 7) {
                    printf("e o numero nao termina com 7\n");
                } else {
                    printf("mas termina com 7\n");
                    v[i] = number;
                    i++;
                }
            }
            else {
                v[i] = number;
                i++;
            }

        } while (number % 7 != 0 || number % 10 != 7);
    }
    
    system("pause");
}

/*
26
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n= 10, m = 0;
    double soma = 1;
    int *v = malloc(n * sizeof(int));

    for (int j = 0; j < n; ++j) {
        printf("Valor %d\n", j + 1);
        scanf("%d", &v[j]);
        m += v[j]; // media
        soma += pow(v[j] - m, 2); // soma
    }

    printf("desvio padrao %f\n", sqrt(soma / n));

    system("pause");
}

/*
27
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = malloc(10 * sizeof(int));
    int resultado;

    for (int j = 0; j < 10; ++j) {
        printf("Numero %d:\n", j + 1);
        scanf("%d", &v[j]);
    }

    system("cls");

    for (int k = 0; k < 10; ++k) {
        resultado = 0;
        for (int i = 2; i <= v[k] / 2; i++) {
            if (v[k] % i == 0) {
                resultado++;
            }
        }
        if (resultado == 0) {
            printf("%d e um numero primo ", v[k]);
            printf("e esta na posicao %d\n", k);
        } else
            printf("%d nao e um numero primo\n", v[k]);
    }

    system("pause");
}

/*
28
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *v = malloc(10 * sizeof(int));
    int *v1 = malloc(10 * sizeof(int)); // impares
    int *v2 = malloc(10 * sizeof(int)); // pares

    int pares = 0, impares = 0;

    for (int j = 0; j < 10; ++j) {

        printf("Numero %d:\n", j + 1);
        scanf("%d", &v[j]);
    }

    system("cls");

    for (int i = 0; i < 10; i++) {

        if (v[i] % 2 == 0) {
            v2[i] = v[i];
            v1[i] = 0;

            ++pares;
        } else {
            v1[i] = v[i];
            v2[i] = 0;
            ++impares;
        }
    }

    puts("V1 IMPARES");
    for (int i = 0; i < 10; i++)
        if (v1[i] != 0)
            printf("%d\n", v1[i]);

    puts("V2 PARES");
    for (int i = 0; i < 10; i++)
        if (v2[i] != 0)
            printf("%d\n", v2[i]);

    system("pause");
}

/*
29
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *v = malloc(6 * sizeof(int));
    int *v1 = malloc(6 * sizeof(int)); // impares
    int *v2 = malloc(6 * sizeof(int)); // pares

    int pares = 0, impares = 0;

    for (int j = 0; j < 10; ++j) {

        printf("Numero %d:\n", j + 1);
        scanf("%d", &v[j]);
    }

    system("cls");

    for (int i = 0; i < 6; i++) {

        if (v[i] % 2 == 0) {
            v2[i] = v[i];
            v1[i] = 0;

            ++pares;
        } else {
            v1[i] = v[i];
            v2[i] = 0;
            ++impares;
        }
    }

    puts("V1 IMPARES");
    printf("Numero total de impares: %d\n", impares);
    for (int i = 0; i < 6; i++)
        if (v1[i] != 0)
            printf("%d\n", v1[i]);

    puts("V2 PARES");
    printf("Numero total de pares: %d\n", pares);
    for (int i = 0; i < 6; i++)
        if (v2[i] != 0)
            printf("%d\n", v2[i]);

    system("pause");
}

/*
30
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *v = malloc(10 * sizeof(int));
    int *v2 = malloc(10 * sizeof(int));
    int *v3 = malloc(20 * sizeof(int));

    for (int i = 0; i < 10; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%d", &v[i]);

    }

    system("cls");

    puts("VETOR 2");
    for (int j = 0; j < 10; ++j) {
        printf("Numero %d:\n", j + 1);
        scanf("%d", &v2[j]);
    }

    int impar = 0, par = 0;

    for (int i = 0; i < 20; ++i) {
        if (i % 2 == 0) {
            v3[i] = v[par];
            par++;
        }
        else {
            v3[i] = v2[impar];
            impar++;
        }
    }

    for (int i = 0; i < 20; ++i) {
        for (int j = i + 1; j < 20; ++j) {
            if (v3[i] == v3[j])
                v3[i] = 0;
        }
    }

    system("cls");

    puts("VETOR 3");
    int i = 0;
    while (i < 20) {
        if (v3[i] != 0) {
            printf("%d\n", v3[i]);
        }
        i++;
    }

    system("pause");
}

/*
31
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *v = malloc(10 * sizeof(int));
    int *v2 = malloc(10 * sizeof(int));
    int *v3 = malloc(20 * sizeof(int));
    int vetor2 = 0;

    for (int i = 0; i < 10; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%d", &v[i]);

    }

    system("cls");

    puts("VETOR 2");
    for (int j = 0; j < 10; ++j) {
        printf("Numero %d:\n", j + 1);
        scanf("%d", &v2[j]);
    }

    for (int i = 0; i < 10; ++i) {
        v3[i] = v[i];
        if (i == 0) {
            for (int j = 10; j < 20; ++j) {
                v3[j] = v2[vetor2];
                vetor2++;
            }
        }
    }

    for (int i = 0; i < 20; ++i) {
        for (int j = i + 1; j < 20; ++j) {
            if (v3[i] == v3[j])
                v3[j] = 0;
        }
    }

    system("cls");

    puts("VETOR 3");
    int i = 0;
    while (i < 20) {
        if (v3[i] != 0) {
            printf("%d\n", v3[i]);
        }
        i++;
    }

    system("pause");
}

/*
32
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int aux = 0, uniao = 5;
    int a = 0;
    int *x = malloc(5 * sizeof(int));
    int *y = malloc(5 * sizeof(int));
    int vsoma[5];
    int vproduto[5];
    int vdiferenca[5] = {0,0,0,0,0};
    int vintersecao[5] = {0,0,0,0,0};
    int vuniao[10] = {0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < 5; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%d", &x[i]);

    }

    system("cls");

    puts("VETOR 2");
    for (int j = 0; j < 5; ++j) {
        printf("Numero %d:\n", j + 1);
        scanf("%d", &y[j]);
    }

    system("cls");

    for (int i = 0; i < 5; ++i) {
        vsoma[i] = x[i] + y[i]; // Soma entre x e y
        vproduto[i] = x[i] * y[i]; // Produto entre x e y
    }

    for (int i = 0; i < 5; ++i) { // Diferenca entre x e y
        for (int j = 0; j < 5; ++j) {
            if (x[i] != y[j])
                vdiferenca[i] = x[i];
            else
                vdiferenca[i] = 0;
        }
    }

    for (int i = 0; i < 5; ++i) { // Intersecao entre x e y
        for (int j = 0; j < 5; ++j) {
            if (x[i] == y[j])
                vintersecao[i] = x[i];
        }
    }

    for (int i = 0; i < 5; ++i) { // Uniao entre x e y
        vuniao[i] = x[i];
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (y[i] !=  x[j])
                vuniao[uniao] = y[i];
        }
        uniao++;
    }

    puts("Soma entre x e y:");
    while (a < 5) {
        printf("%d\n", vsoma[a]);
        a++;
    }

    a = 0;
    puts("Produto entre x e y:");
    while (a < 5) {
        printf("%d\n", vproduto[a]);
        a++;
    }

    a = 0;
    puts("Diferenca entre x e y:");
    while (a < 5) {
        if (vdiferenca[a] != 0) {
            printf("%d\n", vdiferenca[a]);
        }
        a++;
    }

    a = 0;
    puts("interesecao entre x e y:");
    while (a < 5) {
        if (vintersecao[a] != 0) {
            printf("%d\n", vintersecao[a]);
        }
        a++;
    }

    a = 0;
    puts("Uniao entre x e y:");
    while (a < 10) {
        if (vuniao[a] != 0) {
            printf("%d\n", vuniao[a]);
        }
        a++;
    }

    system("pause");
}

/*
33
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int j;
    int *v = malloc(15 * sizeof(int));

    for (int i = 0; i < 15; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%d", &v[i]);
    }

    system("cls");

    for (int i = 0; i < 15; ++i) {
        if (v[i] == 0) {
            j = i;
            while (j < 14) {
                v[j] = v[j + 1];
                v[j + 1] = 0;
                j++;
            }
        }
    }

    j = 0;
    while (j < 15) {
        if (v[j] != 0) {
            printf("%d\n", v[j]);
        }
        j++;
    }

    system("pause");
}

/*
34
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int l = 0, igual;
    int *v = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; ++i) {
        do {
            igual = 0;

            printf("Numero %d:\n", i + 1);
            scanf("%d", &v[i]);

            if (i > 0)
                for (int j = 0; j < i; ++j) {
                    for (int k = j+1; k < i+1; ++k) {
                        if (v[j] == v[k]) {
                            igual++;
                        }
                    }
                }

            if (igual > 0)
                puts("Numero ja digitado");

        } while (igual > 0);
    }

    system("cls");

    puts("vetor:");
    while (l < 10) {
        printf("%d\n", v[l]);
        l++;
    }

    system("pause");
}

/*
35
*/

#include <stdio.h>
#include <stdlib.h>

union numbers {
    unsigned int a;
    unsigned int b;
}nmbr;

void clear_buff() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int input() {
    do {
        puts("First Number:");
        scanf("%d", &nmbr.a);
        clear_buff();
        if (nmbr.a > 10000)
            puts("number over 10000");
    } while (nmbr.a > 10000);

    do {
        puts("Second Number:");
        scanf("%d", &nmbr.b);
        clear_buff();
        if (nmbr.b > 10000)
            puts("number over 10000");
    } while (nmbr.b > 10000);
}

unsigned int count(unsigned int i) {
    unsigned int ret=1;
    while (i/=10) ret++;
    return ret;
}

int main() {
    input();

    unsigned int auxa = count(nmbr.a);
    char *v = malloc(auxa * sizeof(char));

    unsigned int sum = auxa;

    printf("First vector it has %d positions\n", auxa);

    while (auxa--) {
        v[auxa]=nmbr.a%10;
        nmbr.a/=10;
    }

    unsigned int auxb = count(nmbr.b);
    char vectorb[auxa];

    printf("Second vector it has %d positions\n", auxb);

    sum += auxb;

    while (auxb--) {
        vectorb[auxb]=nmbr.b%10;
        nmbr.b/=10;
    }

    v =  realloc(v, (sum * sizeof(char)));

    printf("New vector it has %d positions\n", sum);

    system("pause");
}

/*
36
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int w = 0;
    float aux;
    float *v = malloc(10 * sizeof(float));

    for (int i = 0; i < 10; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%f", &v[i]);
    }

    for (int i = 0; i < 10; ++i) { // ORDENACAO
        for (int j = i; j < 10; ++j) {
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    system("cls");

    puts("vetor:");
    while (w < 10) {
        printf("%.2f\n", v[w]);
        w++;
    }

    system("pause");
}

/*
37
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int w = 0;
    int aux;
    int *v = malloc(11 * sizeof(int));

    for (int i = 0; i < 11; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < 6; ++i) { // ORDENACAO CRESCENTE
        for (int j = i; j < 6; ++j) {
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    for (int i = 6; i < 11; ++i) { // ORDENACAO DECRESCENTE
        for (int j = i; j < 11; ++j) {
            if (v[i] < v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    system("cls");

    puts("vetor:");
    while (w < 11) {
        printf("%d\n", v[w]);
        w++;
    }

    system("pause");
}

/*
38
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int w = 0;
    int aux;
    int *v = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; ++i) {
        printf("Numero %d:\n", i + 1);
        scanf("%d", &v[i]);

        for (int f = 0; f < i; ++f) // ORDENACAO CRESCENTE
            for (int j = f; j < i + 1; ++j)
                if (v[f] > v[j]) {
                    aux = v[f];
                    v[f] = v[j];
                    v[j] = aux;
                }
    }

    system("cls");

    puts("vetor:");
    while (w < 10) {
        printf("%d\n", v[w]);
        w++;
    }

    system("pause");
}

/*
39
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, coef = 0;

    printf("digite um inteiro n: \n");
    scanf("%d", &n);

    for (int i = 0; i < n + 1; i++){

        for (int j = 0; j < i; j++){
            if (i == 0 || j == 0)
                coef = 1;
            else
                coef = coef * ( i - j + 1) / j ;

            printf("%d ", coef);
        }

        printf("\n");
    }

    system("pause");
}
