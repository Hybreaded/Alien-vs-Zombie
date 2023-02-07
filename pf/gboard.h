#include <iostream>
#include <vector>

#ifndef PF_GBOARD_H
#define PF_GBOARD_H

class Gboard
{
    public:
    int numeoflements;
    int grows, gcolumns, gzombies;
    std::vector<std::vector<char>> board_;
    void element(Gboard& board1);
    void elementAlien(Gboard& board1);
    void elementZombie(Gboard& board1);
    void displayboard(Gboard& board1);

    private:
    int grows_, gcolumns_, gzombies_;
};

#endif