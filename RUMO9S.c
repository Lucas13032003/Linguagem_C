#include <stdio.h>
#include <string.h>

int degree_of_nine(char *number) {
    int len = strlen(number);
    if (len == 1 && number[0] == '9') {
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += number[i] - '0';
    }

    if (sum % 9 == 0) {
        char new_number[1002];
        sprintf(new_number, "%d", sum);
        return 1 + degree_of_nine(new_number);
    }

    return 0;
}

int main() {
    char number[1002];
    while (1) {
        scanf("%s", number);
        if (number[0] == '0' && number[1] == '\0') {
            break;
        }

        int degree = degree_of_nine(number);

        if (degree > 0) {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", number, degree);
        } else {
            printf("%s is not a multiple of 9.\n", number);
        }
    }

    return 0;
}
