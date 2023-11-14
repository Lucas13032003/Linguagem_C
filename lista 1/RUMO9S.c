#include <stdio.h>
#include <string.h>

int main() {
    char num[1001];
    int degree = 0;
    
    while (1) {
        scanf("%s", num);
        if (num[0] == '0') {
            break;
        }
        
        int len = strlen(num);
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += num[i] - '0';
        }
        
        if (sum % 9 == 0) {
            degree = 1;
            int tempSum = sum;
            while (tempSum != 9) {
                tempSum = 0;
                while (sum > 0) {
                    tempSum += sum % 10;
                    sum /= 10;
                }
                sum = tempSum;
                degree++;
            }
            printf("%s is a multiple of 9 and has 9-degree %d.\n", num, degree);
        } else {
            printf("%s is not a multiple of 9.\n", num);
        }
    }
    
    return 0;
}