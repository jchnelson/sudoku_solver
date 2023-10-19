#include <array>
#include <algorithm>

#include "sudoku_solver.h"

static bool solved = false;

bool valid(board& b, size_t row, size_t col, int guess)
{
    bool ret = true;
    for (int i = 0; i != 9; ++i)
    {
        if (b[row][i] == guess)
        {
            if (i != col)
                ret = false;
        }
        if (b[i][col] == guess)
        {
            if (i != row)
                ret = false;
        }
        for (int j = 0; j != 9; ++j)
            if ((i != row || j != col) && i / 3 == row / 3 && j / 3 == col / 3)
                if (b[i][j] == guess)
                    ret = false;
        if (!ret)
            break;
    }
    return ret;
}

boardp solve(board tester)
{

    boardp testerp = 0;

    for (size_t i = 0; i != 9; ++i)
    {

        for (size_t j = 0; j != 9; ++j)
        {
            if (tester[i][j] != 0)
                continue;
            for (int guess = 1; guess != 10; ++guess)
            {
                int origval = tester[i][j];
                if (tester[i][j] == 0 && valid(tester, i, j, guess))
                {
                    tester[i][j] = guess;
                    if (all_of(tester.begin(), tester.end(), [](const boardrow& br)
                        { return none_of(br.begin(), br.end(), [](const int& i)
                            {return i == 0; }); }))
                    {
                        solved = true;
                        return new board(tester);
                    }
                    testerp = solve(tester);
                    if (solved)
                        break;
                    else
                        tester[i][j] = origval;
                }
            }
            if (solved)
                break;
            if (tester[i][j] == 0) // no valid move found
            {
                return 0;
            }
        }
        if (solved)
            break;
    }
    return testerp;
}

board solve_sudoku(board origboard)
{
    board gameboard = origboard;
    boardp finalboard = 0;

    while (1)
    {
        for (size_t i = 0; i != 9; ++i)
        {
            for (size_t j = 0; j != 9; ++j)
            {
                for (int guess = 1; guess != 10; ++guess)
                {
                    if (gameboard[i][j] == 0 && valid(gameboard, i, j, guess))
                    {
                        gameboard[i][j] = guess;
                        finalboard = solve(gameboard);
                        // reset to before previous guess and try again
                        if (!solved)
                            gameboard[i][j] = origboard[i][j];
                        else
                            break;
                    }
                    if (solved)
                        break;
                }
                if (solved)
                    break;
            }
            if (solved)
                break;
        }
        if (solved)
            break;
    }

    board ret = *finalboard;
    delete finalboard;
    return ret;
}