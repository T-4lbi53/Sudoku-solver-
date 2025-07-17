🧠 Overview of the Algorithm: Backtracking

The main idea:

    Find an empty cell (a 0 in your 2D array).

    Try filling it with digits from 1 to 9.

    If a digit doesn’t violate Sudoku rules (i.e., not in the same row, column, or 3x3 box), tentatively place it.

    Recursively attempt to solve the rest of the board.

    If a solution fails, backtrack (undo the choice), and try the next number.

    If a full valid board is reached, it gets printed.

🔍 Detailed Line-by-Line Breakdown

#include <stdio.h>

    Purpose: Includes the standard input/output library, needed for functions like printf() and getchar().

#define SIZE 9

    Purpose: Defines a constant SIZE as 9. Sudoku is played on a 9×9 grid, so this makes the code easier to maintain and modify.


int game[SIZE][SIZE] = 

{
    {2, 0, 0, 3, 0, 0, 4, 0, 7},
    
    {4, 0, 0, 0, 0, 5, 0, 0, 0},
    
    {7, 0, 0, 0, 0, 1, 9, 0, 0},
    
    {0, 1, 0, 0, 0, 3, 7, 0, 0},
    
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    
    {9, 0, 0, 0, 2, 0, 6, 0, 0},
    
    {0, 0, 0, 0, 0, 0, 0, 4, 5},
    
    {0, 9, 0, 5, 0, 0, 0, 6, 0},
    
    {0, 8, 0, 0, 0, 6, 3, 0, 0}
};

    Purpose: This is the initial unsolved Sudoku grid.

    0 represents empty cells.

    It's a 2D array of 9x9 integers.

    You can change this to solve different puzzles.

int solution(int row, int column, int number)

    Purpose: Checks whether placing number at position (row, column) is valid.

    Returns 1 (true) if it’s valid, else 0.

✅ Row Check

    for (int i = 0; i < SIZE; i++) {
        if (game[row][i] == number) {
            return 0;
        }
    }

    Loops over all cells in the same row.

    If number is already in that row, return false.

✅ Column Check

    for (int i = 0; i < SIZE; i++) {
        if (game[i][column] == number) {
            return 0;
        }
    }

    Loops over the same column.

    If number is already in the column, return false.

✅ 3x3 Box Check

    int x0 = (column / 3) * 3;
    int y0 = (row / 3) * 3;

    Determines the top-left corner of the 3x3 subgrid containing (row, column).

    column / 3 gives which column box it's in, multiplied by 3 to get starting index (e.g., columns 0–2 → 0, columns 3–5 → 3).

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game[y0 + i][x0 + j] == number) {
                return 0;
            }
        }
    }

    Scans the 3x3 grid to see if the number already exists.

✅ All checks passed

    return 1;

    It's safe to place number here.

🧠 Core of the Solver: Backtracking

void solve()

    Recursive function that attempts to solve the board.

    This is the backtracking logic.

Step 1: Find an empty cell

    for (int row = 0; row < SIZE; row++) {
        for (int column = 0; column < SIZE; column++) {
            if (game[row][column] == 0) {

    Loop through every cell of the board.

    Find the first empty cell (value 0).

Step 2: Try numbers 1–9

                for (int number = 1; number <= 9; number++) {
                    if (solution(row, column, number)) {
                        game[row][column] = number;
                        solve();
                        game[row][column] = 0;
                    }
                }
                return;

    Try placing each number from 1 to 9.

    If solution() says it’s valid:

        Temporarily place the number.

        Recurse (solve()) to continue solving the board.

        If that path fails, backtrack by resetting it to 0 (undo the choice).

    💡 return; after trying all numbers ensures that if no valid number can be placed, the function returns to a previous call (backtrack).

Step 3: Solution Found

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", game[i][j]);
        }
        printf("\n");
    }
    printf("More possible solutions\n");
    getchar();

    If no empty cells remain, it means the board is completely filled.

    Prints the solved board.

    getchar() pauses so user can view the result.

    Since no return happens after this, the function continues to search for other solutions if they exist.

int main() {
    solve();
    return 0;
}

    Entry point of the program.

    Simply calls solve() to start solving the board.
