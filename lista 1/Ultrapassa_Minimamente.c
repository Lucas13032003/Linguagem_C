#include <stdio.h>
#include <stdlib.h>
// Versão correta!
void ultrapassa_minimamente(int *number, int limit, int index, int size)
{
    if ((index) < size)
    {
        int sum = 0;

        while (sum <= limit && index < size)
        {
                sum += number[index];
                (index)++;
        }

        ultrapassa_minimamente(number, limit, index, size);

        if ((index) < size)
        {
            printf("%d\n", number[index - 1]);
    }
}
}

int main(){
    
    int *number = NULL;
    int numero = 1;
    int capacity = 0;
    int limit, index = 0;

    while (numero != 0)
    {
        capacity++;
        scanf("%d", &numero);
        number = realloc(number, capacity * sizeof(int));
        number[capacity - 1] = numero;
    }

    scanf("%d", &limit);

    ultrapassa_minimamente(number, limit, index, capacity);

    return 0;
}