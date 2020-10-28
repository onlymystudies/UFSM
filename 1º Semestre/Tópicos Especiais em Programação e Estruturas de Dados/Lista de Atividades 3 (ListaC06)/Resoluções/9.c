#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void clear_buff() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct {
    float z;
    float w;
}complex;

struct calculations{
    float sum;
    float subtraction;
    float product;
    float module;
};
struct calculations cl;

void calc() {
    cl.sum = complex.z + complex.w;

    cl.subtraction = complex.z - complex.w;

    cl.product = complex.z * complex.w;

    double aux;
    aux = pow(complex.z, 2) + pow(complex.w, 2);
    sqrt(aux);
    cl.module = aux;
}

int main() {
    printf("Real number: ");
    scanf("%f", &complex.z);
    clear_buff();

    printf("imaginary number: ");
    scanf("%f", &complex.w);

    calc();

    system("cls");
    printf("Sum: %.2f\n", cl.sum);
    printf("Subtraction: %.2f\n", cl.subtraction);
    printf("Product: %.2f\n", cl.product);
    printf("Module: %.2f\n", cl.module);

    system("pause");
}
