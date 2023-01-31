#ifndef PF_OBJECT_H
#define PF_OBJECT_H
#include <vector>

class Object
{
    public:
    int healthpack(int& AlienLife);
    void pod(/*vector<vector<char>>& game_,*/ int totalrows, int totalcolumns, int totalzombies,
            int& zombie1Life, int& zombie2Life, int& zombie3Life, int& zombie4Life, int& zombie5Life);
    void rock();
    void moveup();
    void movedown();
    void moveleft();
    void moveright();
};

#endif