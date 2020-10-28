#include <stdio.h>
#include <stdlib.h>

void cb() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct Vector {
    float x;
    float y;
    float z;
};
struct Vector r;

float calc(float *v, float *v2, float *r3);
int main() {
    int i = 0;

    float *v = malloc(5 * sizeof(float));
    float *v2 = malloc(5 * sizeof(float));
    float *r3 = malloc(5 * sizeof(float));

    while (i < 5) {
        printf("vector 1, value %d:\n", i + 1);
        scanf("%f", &v[i]);
        cb();
        i++;
    }

    system("cls");

    i = 0;
    while (i < 5) {
        printf("vector 2, value %d:\n", i + 1);
        scanf("%f", &v2[i]);
        cb();
        i++;
    }

    system("cls");

    i = 0;
    while (i < 5) {
        printf("vector 3, value %d:\n", i + 1);
        scanf("%f", &r3[i]);
        cb();
        i++;
    }

    system("cls");

    calc(v, v2, r3);

    printf("\nVector 1:\n");
    i = 0;
    while (i < 5) {
        printf("%.2f\n", v[i]);
        i++;
    }
    printf("Total: %.2f\n", r.x);

    printf("\nVector 2:\n");
    i = 0;
    while (i < 5) {
        printf("%.2f\n", v2[i]);
        i++;
    }
    printf("Total: %.2f\n", r.y);

    printf("\nVector 3:\n");
    i = 0;
    while (i < 5) {
        printf("%.2f\n", r3[i]);
        i++;
    }
    printf("Total R(ao cubo): %.2f\n", r.z);

    system("pause");
}
float calc(float *v, float *v2, float *r3) {
    float total = 0, total2 = 0, total3 = 0;
    for (int i = 0; i < 4; i++) {
        total += v[i];
        total2 += v2[i];
        total3 += r3[i];
    }
    r.x = total;
    r.y = total2;
    r.z = total3 + total + total2;
}
