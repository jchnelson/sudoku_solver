#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QDebug>

#include "sudoku_solver.h"

#include <array>

using fieldarray = std::array<std::array<QLineEdit*, 9>, 9>;

void make_board(fieldarray fields)
{
    board origboard;
    for (int i = 0; i != 9; ++i)
    {
        for (int j = 0; j != 9; ++j)
        {
            origboard[i][j] = fields[i][j]->text().toInt();
        }
    }
    
    board finalboard = solve_sudoku(origboard);
    
    for (int i = 0; i != 9; ++i)
    {
        for (int j = 0; j != 9; ++j)
        {
            fields[i][j]->setText(QString::number(finalboard[i][j]));
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    QWidget* bigboss = new QWidget(&w);
    w.setCentralWidget(bigboss);
    QGridLayout* glayout = new QGridLayout();
    bigboss->setLayout(glayout);
    
    board origboard{};
    fieldarray fields; 
    
    for (int i = 0; i != 9; ++i)
    {
        for (int j = 0; j != 9; ++j)
        {
            auto bob = new QLineEdit(QString::number(origboard[i][j]));
            fields[i][j] = bob;
            bob->setMaximumWidth(20);
            glayout->addWidget(bob, i, j);
        }
    }
    QPushButton* solve_button = new QPushButton("Solve Sudoku");
    glayout->addWidget(solve_button, 9, 2, 1, 5);
    
    QObject::connect(solve_button, &QPushButton::clicked, [=] () {
        make_board(fields);
    });
    
    w.show();
    return a.exec();
}
