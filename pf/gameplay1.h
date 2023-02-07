#ifndef PF_GAMEPLAY1_H
#define PF_GAMEPLAY1_H
#include <vector>

class Gameplay
{
    public:
    Gameplay();
    int alienLife, alienAtk;
    int totalrows, totalcolumns, totalZombies;
    char movementAns;
    int RowElement, ColumnElement;

    int ARP, ACP;
    char nextElement;
    int newY, newX;
    int A1, Z1, Z2, Z3, Z4, Z5;
    int meetZombieY, meetZombieX;
    char Astatus, Z1status, Z2status, Z3status, Z4status, Z5status;

    int Z1Row, Z1Column;
    int Z2Row, Z2Column;
    int Z3Row, Z3Column;
    int Z4Row, Z4Column;
    int Z5Row, Z5Column;

    int zombie1Life, zombie1Atk, zombie1Range;
    int zombie2Life, zombie2Atk, zombie2Range;
    int zombie3Life, zombie3Atk, zombie3Range;
    int zombie4Life, zombie4Atk, zombie4Range;
    int zombie5Life, zombie5Atk, zombie5Range;

    void AlienStart(Gameplay& gameplay1);
    void ZombieCheck(Gameplay& gameplay1);

    void displayBoard(Gameplay& gameplay1);
    void displayAttributes(Gameplay& gameplay1);
    void command(Gameplay& gameplay1);
    void helpCommand(Gameplay& gameplay1);
    void movement(Gameplay& gameplay1);
    void boarderCheck(Gameplay& gameplay1);
    void elementCheck(Gameplay& gameplay1);
    void moving(Gameplay& gameplay1);
    void stopCheck(Gameplay& gameplay1);
    void arrowChange(Gameplay& gameplay1);
    void alienATKzombie(Gameplay& gameplay1);
 
    std::vector<std::vector<char>> game_;
    void displayOnly(Gameplay& gameplay1);
    void trailReset(Gameplay& gameplay1);
    
    private:
    int alienLife_ = 100, alienAtk_ = 0;
    int A1_ = 0, Z1_ = 0, Z2_ = 0, Z3_ = 0, Z4_ = 0, Z5_ = 0;
    char Astatus_ = 'a', Z1status_ = 'a', Z2status_ = 'a', Z3status_ = 'a', Z4status_ = 'a', Z5status_ = 'a'; // 'a' means alive

};

#endif
