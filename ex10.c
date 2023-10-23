#include<stdio.h>
#include<stdlib.h>

/*5. Escrever um programa em "C" que solicita as notas das duas provas feitas por
cada um dos alunos de uma turma (as notas tem de estar no intervalo [0 10]) e
imprime para cada um a média das notas. O programa deve parar
imediatamente após ter sido digitado o valor 50 para a nota da primeira prova.*/

int main() {
    float n1, n2;
    int alunos = 0;
    float media;

    while (1) {
        printf("Digite a primeira Nota: ");
        scanf("%f", &n1); 

        if (n1 == 50) {
            break; 
        }

        if (n1 < 0 || n1 > 10) {
            printf("Nota fora do intervalo [0, 10].\n");
            continue; 
        }

        printf("Digite a segunda Nota: ");
        scanf("%f", &n2); 

        if (n2 < 0 || n2 > 10) {
            printf("Nota fora do intervalo [0, 10].\n");
            continue; 
        }

        media = (n1 + n2) / 2;
        printf("A media é: %.2f\n", media); 
        alunos++;
    }

    if (alunos == 0) {
        printf("Nenhum aluno processado.\n"); 
    } else {
        printf("Número de alunos processados: %d\n", alunos); 
    }

    return 0;
}
