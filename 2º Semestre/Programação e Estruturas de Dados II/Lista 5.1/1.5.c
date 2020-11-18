#include <stdio.h>
#include <stdlib.h>

int recMultiPonten(int k, int n) {
    if (n == 0)
        return 1;
    else
        return k * recMultiPonten(k, n-1);
}

int main(void) {
    int k, n;
    printf("Numero k:\n");
    scanf("%d", &k);
    printf("Numero n:\n");
    scanf("%d", &n);
    printf("resultado: %d\n", recMultiPonten(k, n));
    system("pause");
}