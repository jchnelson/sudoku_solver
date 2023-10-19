#include <iostream>
#include "sudoku_solver.h"

using std::cout;


int main()
{
    board origboard{
        boardrow{0,0,0,0,0,0,2,0,0},
        boardrow{0,8,0,0,0,7,0,9,0},
        boardrow{6,0,2,0,0,0,5,0,0},
        boardrow{0,7,0,0,6,0,0,0,0},
        boardrow{0,0,0,9,0,1,0,0,0},
        boardrow{0,0,0,0,2,0,0,4,0},
        boardrow{0,0,5,0,0,0,6,0,3},
        boardrow{0,9,0,4,0,0,0,7,0},
        boardrow{0,0,6,0,0,0,0,0,0},
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