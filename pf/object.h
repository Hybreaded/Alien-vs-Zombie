#ifndef PF_OBJECT_H
#define PF_OBJECT_H
#include <vector>
using namespace std;

class Object
{
    public:
    int alienhealth;
    vector<vector<char>> temp;
    
    int healthpack(Object& object1);
    void pod(Object& object1);
    void rock(Object& object1);
    void moveup();
    void movedown();
    void moveleft();
    void moveright();

    private:
    int healthpack_ = 20;
    int zombierange_ = 3;

};

#endif