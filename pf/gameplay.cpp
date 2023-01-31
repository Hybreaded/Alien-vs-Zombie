#include "helper.h"
#include "setting.h"
#include "gboard.h"
#include "object.h"
#include "gameplay.h"

#include <iostream>
#include <iomanip>
using namespace std;

void Gameplay::displayAttributes(Gameplay& gameplay1)
{
    for (int i = 0; i <= totalZombies; ++i)
    {
        char symbol[]= {' ','>'};
        switch (i)
        {
        case 0:
            cout << symbol[0] << "Alien" << "     :   " <<  "Life  "  << alienLife << ",  Attack   " <<  alienAtk << endl;
            break;
        
        case 1:
            cout << symbol[0] << "Zombie 1" << "  :   " <<  "Life  "  << zombie1Life << ",  Attack   " <<  zombie1Atk << endl;
            break;
        
        case 2:
            cout << symbol[0] << "Zombie 2" << "  :   " <<  "Life  "  << zombie2Life << ",  Attack   " <<  zombie2Atk << endl;
            break;

        case 3:
            cout << symbol[0] << "Zombie 3" << "  :   " <<  "Life  "  << zombie3Life << ",  Attack   " <<  zombie3Atk << endl;
            break;

        case 4:
            cout << symbol[0] << "Zombie 4" << "  :   " <<  "Life  "  << zombie4Life << ",  Attack   " <<  zombie4Atk << endl;
            break;

        case 5: 
            cout << symbol[0] << "Zombie 5" << "  :   " <<  "Life  "  << zombie5Life << ",  Attack   " <<  zombie5Atk << endl;
            break;    
        }
    }
    cout << endl << endl;
    command(gameplay1);
}

void Gameplay::displayBoard(Gameplay& gameplay1)
{
    int numofcharacter = 19;
    int width = (((gameplay1.totalcolumns * 2)+1)-numofcharacter)/2; 

    string space = " ";
    cout << "  ";
    for (int i = 0; i < width ; ++i)
    {
        cout << space;
    }
    cout << ".:Alien Vs Zombie:." <<endl;

    for (int y = gameplay1.totalrows; y > 0; --y) 
    {
        int tempY = gameplay1.totalrows - y;
        cout << setw(4);

        for (int x = 0; x < gameplay1.totalcolumns; ++x) 
        {
            cout << "+-";
        }
        cout << "+" << endl;

        cout << setw(2) << (gameplay1.totalrows - y + 1); 

        for (int x = 0; x < gameplay1.totalcolumns; ++x)
        {
            cout << "|" << gameplay1.game_[tempY][x];
        }
        cout << "|" << endl;
    }    

    cout << setw(4);  
    for (int x = 0; x < gameplay1.totalcolumns; ++x) 
    {
        cout << "+-";
    }
    cout << "+" << endl;
    cout << setw(3);

    for (int x = 0; x < gameplay1.totalcolumns; ++x) 
    {
        int num = ((x+1) / 10);
        cout << " ";
        if (num == 0)
        {
            cout << " ";
        }
        else
        {
            cout << num;
        }
    }
    cout << endl;
    cout << setw(3); 
    
    for (int x = 0; x < gameplay1.totalcolumns; ++x) 
    {
        cout << " " << ((x + 1)) % 10;
    }
    cout << endl;
    cout << endl;

    displayAttributes(gameplay1);
}

void Gameplay::helpcommand(Gameplay& gameplay1)
{
    cout                << endl;
    cout << "Commands"  << endl;
    cout << "1. up      - Move up"                              << endl;
    cout << "2. down    - Move down"                            << endl;
    cout << "3. left    - Move left"                            << endl;
    cout << "4. right   - Move Right"                           << endl;
    cout << "5. arrow   - Change the directions of the arrow"   << endl;
    cout << "6. help    - Display the user commands"            << endl;
    cout << "7. save    - Save the game"                        << endl;
    cout << "8. load    - Load a game"                          << endl;
    cout << "9. quit    - Quit the game"                        << endl;
    
    pf::Pause();
    pf::ClearScreen();
    displayBoard(gameplay1);
}

void Gameplay::moveup(Gameplay& gameplay1)
{
    for (int y = 0; y < gameplay1.totalrows; ++y) 
    {
        for (int x = 0; x < gameplay1.totalcolumns; ++x) 
        {
            if (gameplay1.game_[y][x] == 'A')
            {   
                gameplay1.AlienRowPosition = y; gameplay1.AlienColumnPosition = x;
                break;
            }
        }
    }

    int RowElement = gameplay1.AlienRowPosition - 1; int ColumnElement = gameplay1.AlienColumnPosition;
    Object object;
    if (gameplay1.game_[RowElement][ColumnElement] == 'h')
    {
        object.healthpack(gameplay1.alienLife);
    }
    
    if (gameplay1.game_[RowElement][ColumnElement] == 'p')
    {
        object.pod(/*gameplay1.game_*/ gameplay1.totalrows, gameplay1.totalcolumns, gameplay1.totalZombies, 
                    gameplay1.zombie1Life, gameplay1.zombie2Life, gameplay1.zombie3Life, gameplay1.zombie4Life, gameplay1.zombie5Life);
    }

    if (gameplay1.game_[RowElement][ColumnElement] == 'r')
    {
        object.rock();
    }

    if (gameplay1.game_[RowElement][ColumnElement] == '^')
    {
        object.moveup();
    }

    if (gameplay1.game_[RowElement][ColumnElement] == 'v')
    {
        object.movedown();
    }

    if (gameplay1.game_[RowElement][ColumnElement] == '<')
    {
        object.moveleft();
    }

    if (gameplay1.game_[RowElement][ColumnElement] == '>')
    {
        object.moveright();
    }

    gameplay1.game_[gameplay1.AlienRowPosition][gameplay1.AlienColumnPosition] = '.';
    gameplay1.game_[RowElement][ColumnElement] = 'A';

    pf::Pause();
    pf::ClearScreen();

    displayBoard(gameplay1);
}

void Gameplay::movedown()
{

}

void Gameplay::moveleft()
{

}

void Gameplay::moveright()
{

}

void Gameplay::command(Gameplay& gameplay1)
{
    char ans[10];
    cout << "command >";
    cin >> ans;
    ans[0] = toupper(ans[0]);

    if (ans[0] == 'H')
    {
        helpcommand(gameplay1);
    }

    if (ans[0] == 'U')
    {
        moveup(gameplay1);
    }
    
}