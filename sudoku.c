#include <stdio.h>

#define SIZE 9

int game[SIZE][SIZE] = {
    {2, 0, 0,   3, 0, 0,   4, 0, 7},
    {4, 0, 0,   0, 0, 5,   0, 0, 0},
    {7, 0, 0,   0, 0, 1,   9, 0, 0},

    {0, 1, 0,   0, 0, 3,   7, 0, 0},
    {0, 0, 0,   0, 0, 0,   0, 0, 0},
    {9, 0, 0,   0, 2, 0,   6, 0, 0},
    
    {0, 0, 0,   0, 0, 0,   0, 4, 5},
    {0, 9, 0,   5, 0, 0,   0, 6, 0},
    {0, 8, 0,   0, 0, 6,   3, 0, 0}
};


int solution(int row, int column, int number) {
    // Check if the number is already in the row
    for (int i = 0; i < SIZE; i++) {
        if (game[row][i] == number) {
            return 0;
        }
    }

    // Check if the number is already in the column
    for (int i = 0; i < SIZE; i++) {
        if (game[i][column] == number) {
            return 0;
        }
    }

    // Check if the number is in the 3x3 subgrid
    int x0 = (column / 3) * 3;
    int y0 = (row / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game[y0 + i][x0 + j] == number) {
                return 0;
            }
        }
    }

    return 1;
}

void solve() {
    for (int row = 0; row < SIZE; row++) {
        for (int column = 0; column < SIZE; column++) {
            if (game[row][column] == 0) {
                for (int number = 1; number <= 9; number++) {
                    if (solution(row, column, number)) {
                        game[row][column] = number;
                        solve();
                        game[row][column] = 0;
                    }
                }
                return;
            }
        }
    }

    // Print the solved board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", game[i][j]);
        }
        printf("\n");
    }
    printf("More possible solutions\n");
    getchar();
}

int main() {
    solve();
    return 0;
}
