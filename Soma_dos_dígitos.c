#include <stdio.h>

long int somaDigitos(long int n) {
    if (n < 10) {
        return n;
    } else {
        return n % 10 + somaDigitos(n / 10);
    }
}

int main() {
    long int n;
    scanf("%ld", &n);
    
    if(n < 0) {
        return 0;
    } else {
        printf("%ld\n", somaDigitos(n));
    }
    
    return 0;
}