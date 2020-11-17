#include <stdio.h>
#include <stdlib.h>

int recFibonacci(int n) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else
        return recFibonacci(n - 1) + recFibonacci(n - 2);
}

int main(void) {
    printf("%d\n", recFibonacci(4));
    system("pause");
}