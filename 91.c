#include <stdio.h>

int f91(int n) {
    if (n >= 101) {
        return n - 10;
    } else {
        return f91(f91(n + 11));
    }
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break; // Encerra a entrada se n for igual a 0
        }

        int result = f91(n);
        printf("f91(%d) = %d\n", n, result);
    }

    return 0;
}
