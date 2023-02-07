#include "helper.h"
#include "setting.h"
#include "gboard.h"
#include "object.h"
#include "gameplay1.h"
#include <iostream>
using namespace std;

void Object::healthpack(vector<vector<char>>& game_, char& movementAns, int& AlienLife, int& ARP, int& ACP)
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
}

void Object::pod(vector<vector<char>>& game_ ,int totalrows, int totalcolumns, int totalzombies,
                int& zombie1Life, int& zombie2Life, int& zombie3Life, int& zombie4Life, int& zombie5Life, int movementAns)
{
    Object object;
    int Z1rows; int Z1columns;
    int Z2rows; int Z2columns;
    int Z3rows; int Z3columns;
    int Z4rows; int Z4columns;
    int Z5rows; int Z5columns;

    cout << "Alien finds a pod" << endl;
    for (int y = 0; y < totalrows; ++y) 
    {
        for (int x = 0; x < totalcolumns; ++x) // check Alien position
        {
            if (game_[y][x] == 'A')
            {
                object.Arows = y; object.Acolumns = x;
            }
        }
    }

    switch (movementAns)  //use Alien position to determine pod position
    {
    case 'U':
        object.Podrows = object.Arows - 1; object.Podcolumns = object.Acolumns;
        break;
    case 'D':
        object.Podrows = object.Arows + 1; object.Podcolumns = object.Acolumns;
        break;
    case 'L':
        object.Podrows = object.Arows; object.Podcolumns = object.Acolumns - 1;
        break;
    case 'R':
        object.Podrows = object.Arows; object.Podcolumns = object.Acolumns + 1;
        break; 
    }
    
    vector<int> list;
    for (int i = 0; i < totalzombies; ++i)
    {
       list.push_back(0);
    }
    
    for (int y = 0; y < totalrows; ++y) 
    {
        for (int x = 0; x < totalcolumns; ++x) // check Zombie position
        {
            if (game_[y][x] == '1')
            {    
                Z1rows = y; Z1columns = x;
                object.PandZ1Distance = abs(object.Podrows - Z1rows) + abs(object.Podcolumns - Z1columns);
                list[0] = object.PandZ1Distance;
            } 
            if (game_[y][x] == '2')
            {    
                Z2rows = y; Z2columns = x;
                object.PandZ2Distance = abs(object.Podrows - Z2rows) + abs(object.Podcolumns - Z2columns);
                list[1] = object.PandZ2Distance;    
            }
            if (game_[y][x] == '3')
            {    
                Z3rows = y; Z3columns = x;
                object.PandZ3Distance = abs(object.Podrows - Z3rows) + abs(object.Podcolumns - Z3columns);
                list[2] = object.PandZ3Distance;    
            }
            if (game_[y][x] == '4')
            {    
                Z4rows = y; Z4columns = x;
                object.PandZ4Distance = abs(object.Podrows - Z4rows) + abs(object.Podcolumns - Z4columns);
                list[3] = object.PandZ4Distance;    
            }
            if (game_[y][x] == '5')
            {    
                Z5rows = y; Z5columns = x;
                object.PandZ5Distance = abs(object.Podrows - Z5rows) + abs(object.Podcolumns - Z5columns);
                list[4] = object.PandZ5Distance;    
            }
        }
    }

    int min = list[0]; //find min
    for (int i = 0; i < list.size(); ++i)
    {
        if (list[i] < min)
        {
            min = list[i];
        }                           
    }

    vector<char> random;
    for (int i = 0; i < list.size(); ++i) //check min is what then pushback into the vector "random"
    {
        if (list[i] == min)
        {
            char assign = 'A';
            random.push_back(assign + i);
        }                           
    }

    int randomNum = rand() % random.size();
    char search = random[randomNum];

    switch (search)
    {
    case 'A':
        cout << "Zombie 1 receieves a damage of 10" << endl;
        zombie1Life =  zombie1Life - 10;
        if (zombie1Life > 0)
        {
            cout << "Zombie is still alive" << endl << endl;
        }

        if (zombie1Life == 0)
        {
            cout << "Zombie 1 has been defeated"<< endl;
        }
        break;
    
    case 'B':
        cout << "Zombie 2 receieves a damage of 10" << endl;
        zombie2Life = zombie2Life - 10;
        if (zombie2Life > 0)
        {
            cout << "Zombie is still alive" << endl << endl;
        }

        if (zombie2Life == 0)
        {
            cout << "Zombie 2 has been defeated" << endl;
        }
        break;

    case 'C':
        cout << "Zombie 3 receieves a damage of 10" << endl;
        zombie3Life =  zombie3Life - 10;
        if (zombie3Life > 0)
        {
            cout << "Zombie is still alive" << endl << endl;
        }

        if (zombie3Life == 0)
        {
            cout << "Zombie 3 has been defeated"<< endl;
        }
        break;

    case 'D':
        cout << "Zombie 4 receieves a damage of 10" << endl;
        zombie4Life =  zombie4Life - 10;
        if (zombie4Life > 0)
        {
            cout << "Zombie is still alive" << endl << endl;
        }

        if (zombie4Life == 0)
        {
            cout << "Zombie 4 has been defeated"<< endl;
        }
        break;

    case 'E':
        cout << "Zombie 5 receieves a damage of 10" << endl;
        zombie5Life =  zombie5Life - 10;
        if (zombie5Life > 0)
        {
            cout << "Zombie is still alive" << endl << endl;
        }

        if (zombie5Life == 0)
        {
            cout << "Zombie 5 has been defeated"<< endl;
        }
        break; 
    }
    
}

void Object::rock(vector<vector<char>>& game_, int rowElement, int columnElement)
{
    cout << "Alien stumbles upon a rock" << endl;
    char randomObject[] = {'<','>','^','v','h','p',' '};
    int numofelements = 6;
    int assign = rand() % 6;

    switch (assign)
    {
    case 0:
        cout << "Alien discovers an arrow < beneath the rock" << endl <<endl;
        game_[rowElement][columnElement] = randomObject[assign];
        break;  
    case 1:
        cout << "Alien discovers an arrow > beneath the rock" << endl <<endl;
        game_[rowElement][columnElement] = randomObject[assign];
        break;
    case 2:
        cout << "Alien discovers an arrow ^ beneath the rock" << endl <<endl;
        game_[rowElement][columnElement] = randomObject[assign];
        break;
    case 3:
        cout << "Alien discovers an arrow v beneath the rock" << endl <<endl;
        game_[rowElement][columnElement] = randomObject[assign];
        break;
    case 4:
        cout << "Alien discovers a healthpack beneath the rock" << endl <<endl;
        game_[rowElement][columnElement] = randomObject[assign];
        break;
    case 5:
        cout << "Alien discovers a pod beneath the rock" << endl <<endl;
        game_[rowElement][columnElement] = randomObject[assign];
        break;
    case 6:
        cout << "Alien discovers nothing beneath the rock" << endl <<endl;
        game_[rowElement][columnElement] = randomObject[assign];
        break;
    }
}

void Object::ArrowUp()
{
        cout << "Alien finds an arrow" << endl;
        cout << "Alien attack has increase by 20" << endl;


}

void Object::ArrowDown()
{

}

void Object::ArrowLeft()
{
    
}

void Object::ArrowRight()
{
    
}



