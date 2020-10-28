#include <stdio.h>
#include <stdlib.h>

void clear_buff() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct {
    float ray;
    float argument;
}polar;

union { // union same thing as struct
    float x;
    float y;
}cartesian;

void conversion() {
    cartesian.x = polar.ray * polar.argument;
    cartesian.y = cartesian.x * polar.ray;
}

int main() {
    float aux;

    puts("polar coordinate ray (r):");
    scanf("%f", &polar.ray);
    clear_buff();

    do {
        puts("polar coordinate radians (a):");
        scanf("%f", &aux);
        clear_buff();
        if (aux == 0) {
            puts("Dont use ',' use '.'");
        } else {
            polar.argument = aux;
        }
    } while (aux == 0);

    conversion();

    system("cls");

    printf("Cartesian coordinate X: %f\n", cartesian.x);
    printf("Cartesian coordinate Y: %f\n", cartesian.y);

    system("pause");
}
