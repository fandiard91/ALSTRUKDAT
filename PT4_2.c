#include <stdio.h>
#include <stdlib.h>

void koboImaginaryChess(int i, int j, int size) {
    
    int chessBoard[size][size];
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            chessBoard[row][col] = 0;
        }
    }

    int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                       {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    for (int k = 0; k < 8; k++) {
        int newRow = i + moves[k][0];
        int newCol = j + moves[k][1];

        if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
            chessBoard[newRow][newCol] = 1;
        }
    }

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%d", chessBoard[row][col]);
            if (col < size - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);

    int size = 8;

    koboImaginaryChess(i, j, size);

    return 0;
}
