#pragma once
#include <array>
#include <algorithm>


using board = std::array<std::array<int, 9>, 9>;
using boardrow = std::array<int, 9>;
using boardp = std::array<std::array< int, 9>, 9>*;

bool valid(board& b, size_t row, size_t col, int guess);
boardp solve(board tester);
board solve_sudoku(board origboard);