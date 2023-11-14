long int memo[81];

long int fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }

    if (memo[n] != 0) {
        return memo[n];
    } else {
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return memo[n];
    }
}