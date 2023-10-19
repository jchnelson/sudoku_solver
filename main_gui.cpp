#include <iostream>
#include "sudoku_solver.h"

using std::cout;


int main()
{
    board origboard{
        boardrow{1,0,0,0,0,0,0,0,0},
        boardrow{0,7,0,4,1,0,2,8,0},
        boardrow{9,0,8,2,0,0,4,0,0},
        boardrow{0,0,1,0,0,0,0,0,0},
        boardrow{0,0,0,0,0,0,0,9,1},
        boardrow{0,6,0,0,0,5,3,0,0},
        boardrow{3,0,0,0,8,9,0,7,2},
        boardrow{0,0,5,0,0,2,0,0,0},
        boardrow{0,0,0,0,4,0,0,5,0},
            };

    board finalboard = solve_sudoku(origboard);

    for (size_t i = 0; i != 9; ++i)
    {
        for (size_t j = 0; j != 9; ++j)
        {
            cout << (finalboard)[i][j];
        }
        cout << '\n';
    }
    cout << "\n\n";

}