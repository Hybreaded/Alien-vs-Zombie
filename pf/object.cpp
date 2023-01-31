#include "helper.h"
#include "setting.h"
#include "gboard.h"
#include "object.h"
#include "gameplay.h"
#include <iostream>
using namespace std;

int Object::healthpack(int& AlienLife)
{
        cout << "Alien finds a health pack" << endl;

        if (AlienLife == 100)
        {
            cout << "Alien's health is already full, hence no increas on hp" << endl;
        }

        if (AlienLife >= 80 && AlienLife < 100)
        {   
            AlienLife = 100;
            cout << "Alien has full health now" << endl;
        }

        if (AlienLife <80)
        {
            AlienLife = AlienLife + 20;
            cout << "Alien's health is increased by 20, now alien have total of" << AlienLife << " HP" << endl;
        }

        return AlienLife;
}

void Object::pod(/*vector<vector<char>>& game_*/ int totalrows, int totalcolumns, int totalzombies,
                int& zombie1Life, int& zombie2Life, int& zombie3Life, int& zombie4Life, int& zombie5Life)
{
    int Arows; int Acolumns;
    int Z1rows; int Z1columns;
    int Z2rows; int Z2columns;
    int Z3rows; int Z3columns;
    int Z4rows; int Z4columns;
    int Z5rows; int Z5columns;

    cout << "Test  :  " ;

    /*cout << "Alien finds a pod" << endl;
    for (int y = 0; y < totalrows; ++y) 
    {
        for (int x = 0; x < totalcolumns; ++x) 
        {
            
            if (game_[y][x] == 'A')
            {   
                Arows = y; Acolumns = x;
                break;
            }

            if (game_[y][x] == '1')
            {   
                Z1rows = y; Z1columns = x;
                break;
            }

            if (game_[y][x] == '2')
            {   
                Z2rows = y; Z2columns = x;
                break;
            }

            if (game_[y][x] == '3')
            {   
                Z3rows = y; Z3columns = x;
                break;
            }

            if (game_[y][x] == '4')
            {   
                Z4rows = y; Z4columns = x;
                break;
            }

            if (game_[y][x] == '5')
            {   
                Z5rows = y; Z5columns = x;
                break;
            }
        }
    }

    double AandZ1Distance = abs(Arows - Z1rows) + abs(Acolumns - Z1columns);
    double AandZ2Distance = abs(Arows - Z2rows) + abs(Acolumns - Z2columns);
    double AandZ3Distance = abs(Arows - Z3rows) + abs(Acolumns - Z3columns);
    double AandZ4Distance = abs(Arows - Z4rows) + abs(Acolumns - Z4columns);
    double AandZ5Distance = abs(Arows - Z5rows) + abs(Acolumns - Z5columns);

    double list[] = {AandZ1Distance, AandZ2Distance, AandZ3Distance, AandZ4Distance, AandZ5Distance};
    double min = list[0];
    for (int i = 0; i < 5; ++i)
    {
        if (list[i] < min)
        {
            min = list[i];
        }                           
    }

    if (AandZ1Distance == min)
    {
        cout << "Zombie 1 receieves a damage of 10" << endl;
        zombie1Life =  zombie1Life - 20;
        if (zombie1Life > 0)
        {
            cout << "Zombie is still alive";
        }

        if (zombie1Life == 0)
        {
            cout << "Zombie 1 has been defeated";
        }
    }

    if (AandZ1Distance == min)
    {
        cout << "Zombie 1 receieves a damage of 10" << endl;
        zombie1Life =  zombie1Life - 20;
        if (zombie1Life > 0)
        {
            cout << "Zombie is still alive";
        }

        if (zombie1Life == 0)
        {
            cout << "Zombie 1 has been defeated";
        }

    }if (AandZ2Distance == min)
    {
        cout << "Zombie 2 receieves a damage of 10" << endl;
        zombie2Life =  zombie2Life - 20;
        if (zombie2Life > 0)
        {
            cout << "Zombie is still alive";
        }

        if (zombie2Life == 0)
        {
            cout << "Zombie 2 has been defeated";
        }

    }if (AandZ3Distance == min)
    {
        cout << "Zombie 3 receieves a damage of 10" << endl;
        zombie3Life =  zombie3Life - 20;
        if (zombie3Life > 0)
        {
            cout << "Zombie is still alive";
        }

        if (zombie3Life == 0)
        {
            cout << "Zombie 3 has been defeated";
        }

    }if (AandZ4Distance == min)
    {
        cout << "Zombie 4 receieves a damage of 10" << endl;
        zombie4Life =  zombie4Life - 20;
        if (zombie4Life > 0)
        {
            cout << "Zombie is still alive";
        }

        if (zombie4Life == 0)
        {
            cout << "Zombie 4 has been defeated";
        }

    }if (AandZ5Distance == min)
    {
        cout << "Zombie 5 receieves a damage of 10" << endl;
        zombie5Life =  zombie5Life - 20;
        if (zombie5Life > 0)
        {
            cout << "Zombie is still alive";
        }

        if (zombie5Life == 0)
        {
            cout << "Zombie 5 has been defeated";
        }
    }*/
}

void Object::rock()
{
    cout << "Alien stumbles upon a rock" << endl;
    char randomObject[] = {'<','>','^','v','h','p'};
    int numofelements = 6;
    int assign = rand() % 6;
        

    switch (assign)
    {
    case 0:
        cout << "Alien discovers a arrow < beneath the rock" << endl;
        break;  
        
    case 1:
        cout << "Alien discovers a arrow > beneath the rock" << endl;
        break;

    case 2:
        cout << "Alien discovers a arrow ^ beneath the rock" << endl;
        break;

    case 3:
        cout << "Alien discovers a arrow v beneath the rock" << endl;
        break;

    case 4:
        cout << "Alien discovers a arrow healthpack beneath the rock" << endl;
        break;

    case 5:
        cout << "Alien discovers a arrow pod beneath the rock" << endl;
        break;
        }

        //temp_[][] =  randomObject[assign];
}

void Object::moveup()
{
        cout << "Alien finds an arrow" << endl;
        cout << "Alien attack has increase by 20" << endl;


}

void Object::movedown()
{

}

void Object::moveleft()
{

}

void Object::moveright()
{

}

