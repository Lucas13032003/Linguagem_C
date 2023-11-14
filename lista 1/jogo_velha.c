#include <stdio.h>

// Função para imprimir o tabuleiro
void printBoard(char board[3][3]) {
    printf("\n  1 2 3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se o jogo acabou
int isGameOver(char board[3][3]) {
    // Verifica linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }

    // Verifica diagonais
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    // Verifica empate
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0; // Jogo ainda não acabou
        }
    }

    return -1; // Jogo empatado
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int currentPlayer = 1;
    int row, col;
    int gameState = 0;

    printf("Bem-vindo ao Jogo da Velha!\n");

    do {
        printBoard(board);
        printf("Jogador %d, insira a linha (1-3) e a coluna (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Movimento inválido. Tente novamente.\n");
            continue;
        }

        if (currentPlayer == 1)
            board[row - 1][col - 1] = 'X';
        else
            board[row - 1][col - 1] = 'O';

        gameState = isGameOver(board);

        if (gameState == 1)
            printf("Jogador %d venceu!\n", currentPlayer);
        else if (gameState == -1)
            printf("O jogo empatou!\n");

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    } while (gameState == 0);

    printBoard(board);

    return 0;
}
