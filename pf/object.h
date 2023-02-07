#ifndef PF_OBJECT_H
#define PF_OBJECT_H
#include <vector>

class Object
{
    public:
    int Podrows, Podcolumns;
    int Arows, Acolumns;
    int PandZ1Distance; 
    int PandZ2Distance;
    int PandZ3Distance;
    int PandZ4Distance;
    int PandZ5Distance;

    void healthpack(std::vector<std::vector<char>>& game_ ,char& movementAns, int& AlienLife, int& ARP, int& ACP);
    void pod(std::vector<std::vector<char>>& game_ ,int totalrows, int totalcolumns, int totalzombies,
            int& zombie1Life, int& zombie2Life, int& zombie3Life, int& zombie4Life, int& zombie5Life, int movementAns);
    void rock(std::vector<std::vector<char>>& game_, int rowElement, int columnElement);
    void ArrowUp();
    void ArrowDown();
    void ArrowLeft();
    void ArrowRight();
    
};

#endif