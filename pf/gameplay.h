#ifndef PF_GAMEPLAY_H
#define PF_GAMEPLAY_H
#include <vector>
using namespace std;

class Gameplay
{
    public:
    int alienLife, alienAtk;
    int totalrows, totalcolumns, totalZombies;

    int AlienRowPosition, AlienColumnPosition;

    int zombie1Life,  zombie1Atk, zombie1Range;
    int zombie2Life,  zombie2Atk, zombie2Range;
    int zombie3Life,  zombie3Atk, zombie3Range;
    int zombie4Life,  zombie4Atk, zombie4Range;
    int zombie5Life,  zombie5Atk, zombie5Range;

    void helpcommand(Gameplay& gameplay1);
    void command(Gameplay& gameplay1);
    void moveup(Gameplay& gameplay1);
    void movedown();
    void moveleft();
    void moveright();

    vector<vector<char>> game_;
    void displayBoard(Gameplay& gameplay1);
    void displayAttributes(Gameplay& gameplay1);

    private:
    int alienLife_ = 100, alienAtk_ = 0;
};

#endif