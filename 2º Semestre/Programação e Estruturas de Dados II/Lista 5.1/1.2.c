#include <stdio.h>
#include <stdlib.h>

int recInverter(int n) {
    if (n <= 0)
        return n;
    printf("%d", n % 10);
    return recInverter(n / 10);
}

int main(void) {
    recInverter(321);
    system("pause");
}