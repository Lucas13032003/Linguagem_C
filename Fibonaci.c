#include <stdio.h>

long int fibonacci(int n) {
    if (n <= 2) {
        return 1;
    } else {
        long int a = 1, b = 1, c;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    long int result = fibonacci(n);

    printf("%ld\n", result);

    return 0;
}
