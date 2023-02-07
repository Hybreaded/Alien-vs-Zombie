#include "helper.h"
#include "setting.h"
#include "gboard.h"
#include "object.h"
#include "gameplay1.h"
#include "gameplay2.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Gameplay2::displayOnly(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    pf::Pause();
    pf::ClearScreen();
    displayBoard(game_,  totalrows,  totalcolumns);
    displayAttributes( A1,  Z1,  Z2,  Z3,  Z4,  Z5,  totalZombies, alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
}

void Gameplay2::displayBoard(vector<vector<char>>& game_, int& totalrows, int& totalcolumns)
{
    int numofcharacter = 19;
    int width = (((totalcolumns * 2)+1)-numofcharacter)/2; 

    string space = " ";
    cout << "  ";
    for (int i = 0; i < width ; ++i)
    {
        cout << space;
    }
    cout << ".:Alien Vs Zombie:." <<endl;

    for (int y = totalrows; y > 0; --y) 
    {
        int tempY = totalrows - y;
        cout << setw(4);

        for (int x = 0; x < totalcolumns; ++x) 
        {
            cout << "+-";
        }
        cout << "+" << endl;

        cout << setw(2) << (totalrows - y + 1); 

        for (int x = 0; x < totalcolumns; ++x)
        {
            cout << "|" << game_[tempY][x];
        }
        cout << "|" << endl;
    }    

    cout << setw(4);  
    for (int x = 0; x < totalcolumns; ++x) 
    {
        cout << "+-";
    }
    cout << "+" << endl;
    cout << setw(3);

    for (int x = 0; x < totalcolumns; ++x) 
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
    
    for (int x = 0; x < totalcolumns; ++x) 
    {
        cout << " " << ((x + 1)) % 10;
    }
    cout << endl;
    cout << endl;
}

void Gameplay2::displayAttributes(int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& totalZombies,int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    for (int i = 0; i <= totalZombies; ++i)
    {
        char symbol[]= {' ','>'};
        switch (i)
        {
        case 0:
            cout << " "<< symbol[A1] << "Alien" << "     :   " <<  "Life  "  << alienLife << ",  Attack   " <<  alienAtk << endl;
            break;
        
        case 1:
            cout << " "<< symbol[Z1] << "Zombie 1" << "  :   " <<  "Life  "  << zombie1Life << ",  Attack   " <<  zombie1Atk << ",  Range   "<< zombie1Range << endl;
            break;
        
        case 2:
            cout << " "<< symbol[Z2] << "Zombie 2" << "  :   " <<  "Life  "  << zombie2Life << ",  Attack   " <<  zombie2Atk << ",  Range   "<< zombie2Range << endl;
            break;

        case 3:
            cout << " "<< symbol[Z3] << "Zombie 3" << "  :   " <<  "Life  "  << zombie3Life << ",  Attack   " <<  zombie3Atk << ",  Range   "<< zombie3Range << endl;
            break;

        case 4:
            cout << " "<< symbol[Z4] << "Zombie 4" << "  :   " <<  "Life  "  << zombie4Life << ",  Attack   " <<  zombie4Atk << ",  Range   "<< zombie4Range << endl;
            break;

        case 5: 
            cout << " "<< symbol[Z5] << "Zombie 5" << "  :   " <<  "Life  "  << zombie5Life << ",  Attack   " <<  zombie5Atk << ",  Range   "<< zombie5Range << endl;
            break;    
        }
    }
    cout << endl << endl;
}

void Gameplay2::Zombie1Start(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    A1 = 0, Z1 = 1;
    displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
    Zombie1movement(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies, alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
}

void Gameplay2::Zombie2Start(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    Z1 = 0, Z2 = 1;
    displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
    Zombie2movement(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies, alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);    
}

void Gameplay2::Zombie3Start(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    Z2 = 0, Z3 = 1;
    displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
    Zombie3movement(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies, alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
}

void Gameplay2::Zombie4Start(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    Z3 = 0, Z4 = 1;
    displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
    Zombie4movement(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies, alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
}

void Gameplay2::Zombie5Start(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    Z4 = 0, Z5 = 1;
    displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
    Zombie5movement(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies, alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
}

void Gameplay2::Zombie1movement(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    for (int y = 0; y < totalrows; ++y)
    {
        for (int x = 0; x < totalcolumns; ++x)
        {
            switch (game_[y][x])
            {
            case 'A':
                ARP = y; ACP = x;
                break;           
            case '1':
                Z1Row = y; Z1Column = x;
                break;
            }
        } 
    }

    int i = 1;
    while (i > 0)
    {
        char choice[]={'U','D','L','R'};
        int numofchoice = 4;
        char result = choice[rand() % numofchoice];
        switch (result)
        {
        case 'U':
            if (Z1Row - 1 == -1)
            {
                continue;
            }
            if (game_[Z1Row - 1][Z1Column] == 'A'||
                game_[Z1Row - 1][Z1Column] == '2'||
                game_[Z1Row - 1][Z1Column] == '3'||
                game_[Z1Row - 1][Z1Column] == '4'||
                game_[Z1Row - 1][Z1Column] == '5')
            {
                continue;
            }
            game_[Z1Row - 1][Z1Column] = '1';
            game_[Z1Row][Z1Column] = ' ';
            Z1Row = Z1Row - 1;
            cout << "Zombie 1 moves up" << endl << endl;
            i = 0;
            break;
           
        case 'D':
            if (Z1Row + 1 == totalrows) 
            {
                continue;
            }
            if (game_[Z1Row + 1][Z1Column] == 'A'||
                game_[Z1Row + 1][Z1Column] == '2'||
                game_[Z1Row + 1][Z1Column] == '3'||
                game_[Z1Row + 1][Z1Column] == '4'||
                game_[Z1Row + 1][Z1Column] == '5')
            {
                continue;
            }
            game_[Z1Row + 1][Z1Column] = '1';
            game_[Z1Row][Z1Column] = ' ';
            Z1Row = Z1Row + 1;
            cout << "Zombie 1 moves down" << endl << endl;
            i = 0;
            break;

        case 'L':
            if (Z1Column -1 == -1)
            {
                continue;
            }
            if (game_[Z1Row][Z1Column - 1] == 'A'||
                game_[Z1Row][Z1Column - 1] == '2'||
                game_[Z1Row][Z1Column - 1] == '3'||
                game_[Z1Row][Z1Column - 1] == '4'||
                game_[Z1Row][Z1Column - 1] == '5')
            {
                continue;
            }
            game_[Z1Row][Z1Column - 1] = '1';
            game_[Z1Row][Z1Column] = ' ';
            Z1Column = Z1Column - 1;
            cout << "Zombie 1 moves left" << endl << endl;
            i = 0;
            break;

        case 'R':
            if (Z1Column + 1 == totalcolumns)
            {
                continue;
            }
            if (game_[Z1Row][Z1Column + 1] == 'A'||
                game_[Z1Row][Z1Column + 1] == '2'||
                game_[Z1Row][Z1Column + 1] == '3'||
                game_[Z1Row][Z1Column + 1] == '4'||
                game_[Z1Row][Z1Column + 1] == '5')
            {
                continue;
            }
            game_[Z1Row][Z1Column + 1] = '1';
            game_[Z1Row][Z1Column] = ' ';
            Z1Column = Z1Column + 1;
            cout << "Zombie 1 moves right" << endl << endl;
            i = 0;
            break;
        }

        displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range); 
        int Z1andADistance = abs(Z1Row - ARP) + abs(Z1Column - ACP);
        cout << "for checking distance and range : " <<Z1andADistance << " "<< zombie1Range<<endl;

        if (zombie1Range >= Z1andADistance)
        {
            cout << "Zombie 1 attacks Alien."<<endl;
            cout << "Alien receives a damage of " << zombie1Atk <<"."<< endl << endl;
            alienLife = alienLife - zombie1Atk;
        }
        
        if (zombie1Range < Z1andADistance)
        {
            cout << "Zombie 1 is unable to attack Alien."<<endl;
            cout << "Alien is too far"<< endl << endl;
        }
    }
}

void Gameplay2::Zombie2movement(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    int Z2Row, Z2Column;
    for (int y = 0; y < totalrows; ++y)
    {
        for (int x = 0; x < totalcolumns; ++x)
        {
            switch (game_[y][x])
            {
            case 'A':
                ARP = y; ACP = x;
                break;           
            case '2':
                Z2Row = y; Z2Column = x;
                break;
            }
        } 
    }

    int i = 1;
    while (i > 0)
    {
        char choice[]={'U','D','L','R'};
        int numofchoice = 4;
        char result = choice[rand() % numofchoice];
        switch (result)
        {
        case 'U':
            if (Z2Row - 1 == -1)
            {
                continue;
            }
            if (game_[Z2Row - 1][Z2Column] == 'A'||
                game_[Z2Row - 1][Z2Column] == '1'||
                game_[Z2Row - 1][Z2Column] == '3'||
                game_[Z2Row - 1][Z2Column] == '4'||
                game_[Z2Row - 1][Z2Column] == '5')
            {
                continue;
            }
            game_[Z2Row - 1][Z2Column] = '2';
            game_[Z2Row][Z2Column] = ' ';
            Z2Row = Z2Row - 1;
            cout << "Zombie 2 moves up" << endl << endl;
            i = 0;
            break;
           
        case 'D':
            if (Z2Row + 1 == totalrows) 
            {
                continue;
            }
            if (game_[Z2Row + 1][Z2Column] == 'A'||
                game_[Z2Row + 1][Z2Column] == '1'||
                game_[Z2Row + 1][Z2Column] == '3'||
                game_[Z2Row + 1][Z2Column] == '4'||
                game_[Z2Row + 1][Z2Column] == '5')
            {
                continue;
            }
            game_[Z2Row + 1][Z2Column] = '2';
            game_[Z2Row][Z2Column] = ' ';
            Z2Row = Z2Row + 1;
            cout << "Zombie 2 moves down" << endl << endl;
            i = 0;
            break;

        case 'L':
            if (Z2Column -1 == -1)
            {
                continue;
            }
            if (game_[Z2Row][Z2Column - 1] == 'A'||
                game_[Z2Row][Z2Column - 1] == '1'||
                game_[Z2Row][Z2Column - 1] == '3'||
                game_[Z2Row][Z2Column - 1] == '4'||
                game_[Z2Row][Z2Column - 1] == '5')
            {
                continue;
            }
            game_[Z2Row][Z2Column - 1] = '2';
            game_[Z2Row][Z2Column] = ' ';
            Z2Column = Z2Column - 1;
            cout << "Zombie 2 moves left" << endl << endl ;
            i = 0;
            break;

        case 'R':
            if (Z2Column + 1 == totalcolumns)
            {
                continue;
            }
            if (game_[Z2Row][Z2Column + 1] == 'A'||
                game_[Z2Row][Z2Column + 1] == '1'||
                game_[Z2Row][Z2Column + 1] == '3'||
                game_[Z2Row][Z2Column + 1] == '4'||
                game_[Z2Row][Z2Column + 1] == '5')
            {
                continue;
            }
            game_[Z2Row][Z2Column + 1] = '2';
            game_[Z2Row][Z2Column] = ' ';
            Z2Column = Z2Column + 1;
            cout << "Zombie 2 moves right" << endl << endl;
            i = 0;
            break;
        }

        displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range); 
        int Z2andADistance = abs(Z2Row - ARP) + abs(Z2Column - ACP);
        cout << "for checking distance and range : " <<Z2andADistance << " "<< zombie2Range<<endl;
        if (zombie2Range >= Z2andADistance)
        {
            cout << "Zombie 2 attacks Alien."<<endl;
            cout << "Alien receives a damage of " << zombie2Atk <<"."<< endl << endl;
            alienLife = alienLife - zombie2Atk;
        }
        
        if (zombie2Range < Z2andADistance)
        {
            cout << "Zombie 2 is unable to attack Alien."<<endl;
            cout << "Alien is too far"<< endl << endl;
        }
    }
}

void Gameplay2::Zombie3movement(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    int Z3Row, Z3Column;
    for (int y = 0; y < totalrows; ++y)
    {
        for (int x = 0; x < totalcolumns; ++x)
        {
            switch (game_[y][x])
            {
            case 'A':
                ARP = y; ACP = x;
                break;           
            case '3':
                Z3Row = y; Z3Column = x;
                break;
            }
        } 
    }

    int i = 1;
    while (i > 0)
    {
        char choice[]={'U','D','L','R'};
        int numofchoice = 4;
        char result = choice[rand() % numofchoice];
        switch (result)
        {
        case 'U':
            if (Z3Row - 1 == -1)
            {
                continue;
            }
            if (game_[Z3Row - 1][Z3Column] == 'A'||
                game_[Z3Row - 1][Z3Column] == '2'||
                game_[Z3Row - 1][Z3Column] == '1'||
                game_[Z3Row - 1][Z3Column] == '4'||
                game_[Z3Row - 1][Z3Column] == '5')
            {
                continue;
            }
            game_[Z3Row - 1][Z3Column] = '3';
            game_[Z3Row][Z3Column] = ' ';
            Z3Row = Z3Row - 1;
            cout << "Zombie 3 moves up" << endl << endl;
            i = 0;
            break;
           
        case 'D':
            if (Z3Row + 1 == totalrows) 
            {
                continue;
            }
            if (game_[Z3Row + 1][Z3Column] == 'A'||
                game_[Z3Row + 1][Z3Column] == '2'||
                game_[Z3Row + 1][Z3Column] == '1'||
                game_[Z3Row + 1][Z3Column] == '4'||
                game_[Z3Row + 1][Z3Column] == '5')
            {
                continue;
            }
            game_[Z3Row + 1][Z3Column] = '3';
            game_[Z3Row][Z3Column] = ' ';
            Z3Row = Z3Row + 1;
            cout << "Zombie 3 moves down" << endl << endl;
            i = 0;
            break;

        case 'L':
            if (Z3Column -1 == -1)
            {
                continue;
            }
            if (game_[Z3Row][Z3Column - 1] == 'A'||
                game_[Z3Row][Z3Column - 1] == '2'||
                game_[Z3Row][Z3Column - 1] == '1'||
                game_[Z3Row][Z3Column - 1] == '4'||
                game_[Z3Row][Z3Column - 1] == '5')
            {
                continue;
            }
            game_[Z3Row][Z3Column - 1] = '3';
            game_[Z3Row][Z3Column] = ' ';
            Z3Column = Z3Column - 1;
            cout << "Zombie 3 moves left" << endl << endl;
            i = 0;
            break;

        case 'R':
            if (Z3Column + 1 == totalcolumns)
            {
                continue;
            }
            if (game_[Z3Row][Z3Column + 1] == 'A'||
                game_[Z3Row][Z3Column + 1] == '2'||
                game_[Z3Row][Z3Column + 1] == '1'||
                game_[Z3Row][Z3Column + 1] == '4'||
                game_[Z3Row][Z3Column + 1] == '5')
            {
                continue;
            }
            game_[Z3Row][Z3Column + 1] = '3';
            game_[Z3Row][Z3Column] = ' ';
            Z3Column = Z3Column + 1;
            cout << "Zombie 3 moves right" << endl << endl;
            i = 0;
            break;
        }

        displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range); 
        int Z3andADistance = abs(Z3Row - ARP) + abs(Z3Column - ACP);
        cout << "for checking distance and range : " <<Z3andADistance << " "<< zombie3Range<<endl;
        if (zombie3Range >= Z3andADistance)
        {
            cout << "Zombie 3 attacks Alien."<<endl;
            cout << "Alien receives a damage of " << zombie1Atk <<"."<< endl << endl;
            alienLife = alienLife - zombie1Atk;
        }
        
        if (zombie3Range < Z3andADistance)
        {
            cout << "Zombie 3 is unable to attack Alien."<<endl;
            cout << "Alien is too far"<< endl << endl;
        }
    }
}

void Gameplay2::Zombie4movement(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    int Z4Row, Z4Column;
    for (int y = 0; y < totalrows; ++y)
    {
        for (int x = 0; x < totalcolumns; ++x)
        {
            switch (game_[y][x])
            {
            case 'A':
                ARP = y; ACP = x;
                break;           
            case '4':
                Z4Row = y; Z4Column = x;
                break;
            }
        } 
    }

    int i = 1;
    while (i > 0)
    {
        char choice[]={'U','D','L','R'};
        int numofchoice = 4;
        char result = choice[rand() % numofchoice];
        switch (result)
        {
        case 'U':
            if (Z4Row - 1 == -1)
            {
                continue;
            }
            if (game_[Z4Row - 1][Z4Column] == 'A'||
                game_[Z4Row - 1][Z4Column] == '2'||
                game_[Z4Row - 1][Z4Column] == '3'||
                game_[Z4Row - 1][Z4Column] == '1'||
                game_[Z4Row - 1][Z4Column] == '5')
            {
                continue;
            }
            game_[Z4Row - 1][Z4Column] = '4';
            game_[Z4Row][Z4Column] = ' ';
            Z4Row = Z4Row - 1;
            cout << "Zombie 4 moves up" << endl << endl;
            i = 0;
            break;
           
        case 'D':
            if (Z4Row + 1 == totalrows) 
            {
                continue;
            }
            if (game_[Z4Row + 1][Z4Column] == 'A'||
                game_[Z4Row + 1][Z4Column] == '2'||
                game_[Z4Row + 1][Z4Column] == '3'||
                game_[Z4Row + 1][Z4Column] == '1'||
                game_[Z4Row + 1][Z4Column] == '5')
            {
                continue;
            }
            game_[Z4Row + 1][Z4Column] = '4';
            game_[Z4Row][Z4Column] = ' ';
            Z4Row = Z4Row + 1;
            cout << "Zombie 4 moves down" << endl << endl;
            i = 0;
            break;

        case 'L':
            if (Z4Column -1 == -1)
            {
                continue;
            }
            if (game_[Z4Row][Z4Column - 1] == 'A'||
                game_[Z4Row][Z4Column - 1] == '2'||
                game_[Z4Row][Z4Column - 1] == '3'||
                game_[Z4Row][Z4Column - 1] == '1'||
                game_[Z4Row][Z4Column - 1] == '5')
            {
                continue;
            }
            game_[Z4Row][Z4Column - 1] = '4';
            game_[Z4Row][Z4Column] = ' ';
            Z4Column = Z4Column - 1;
            cout << "Zombie 4 moves left" << endl << endl;
            i = 0;
            break;

        case 'R':
            if (Z4Column + 1 == totalcolumns)
            {
                continue;
            }
            if (game_[Z4Row][Z4Column + 1] == 'A'||
                game_[Z4Row][Z4Column + 1] == '2'||
                game_[Z4Row][Z4Column + 1] == '3'||
                game_[Z4Row][Z4Column + 1] == '1'||
                game_[Z4Row][Z4Column + 1] == '5')
            {
                continue;
            }
            game_[Z4Row][Z4Column + 1] = '4';
            game_[Z4Row][Z4Column] = ' ';
            Z4Column = Z4Column + 1;
            cout << "Zombie 4 moves right" << endl << endl;
            i = 0;
            break;
        }

        displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range); 
        int Z4andADistance = abs(Z4Row - ARP) + abs(Z4Column - ACP);
        cout << "for checking distance and range : " <<Z4andADistance << " "<< zombie4Range<<endl;
        if (zombie4Range >= Z4andADistance)
        {
            cout << "Zombie 4 attacks Alien."<<endl;
            cout << "Alien receives a damage of " << zombie1Atk <<"."<< endl << endl;
            alienLife = alienLife - zombie1Atk;
        }
        
        if (zombie4Range < Z4andADistance)
        {
            cout << "Zombie 4 is unable to attack Alien."<<endl;
            cout << "Alien is too far"<< endl << endl;
        }
    }
}

void Gameplay2::Zombie5movement(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    int Z5Row, Z5Column;
    for (int y = 0; y < totalrows; ++y)
    {
        for (int x = 0; x < totalcolumns; ++x)
        {
            switch (game_[y][x])
            {
            case 'A':
                ARP = y; ACP = x;
                break;           
            case '5':
                Z5Row = y; Z5Column = x;
                break;
            }
        } 
    }

    int i = 1;
    while (i > 0)
    {
        char choice[]={'U','D','L','R'};
        int numofchoice = 4;
        char result = choice[rand() % numofchoice];
        switch (result)
        {
        case 'U':
            if (Z5Row - 1 == -1)
            {
                continue;
            }
            if (game_[Z5Row - 1][Z5Column] == 'A'||
                game_[Z5Row - 1][Z5Column] == '2'||
                game_[Z5Row - 1][Z5Column] == '3'||
                game_[Z5Row - 1][Z5Column] == '4'||
                game_[Z5Row - 1][Z5Column] == '1')
            {
                continue;
            }
            game_[Z5Row - 1][Z5Column] = '5';
            game_[Z5Row][Z5Column] = ' ';
            Z5Row = Z5Row - 1;
            cout << "Zombie 5 moves up" << endl << endl;
            i = 0;
            break;
           
        case 'D':
            if (Z5Row + 1 == totalrows) 
            {
                continue;
            }
            if (game_[Z5Row + 1][Z5Column] == 'A'||
                game_[Z5Row + 1][Z5Column] == '2'||
                game_[Z5Row + 1][Z5Column] == '3'||
                game_[Z5Row + 1][Z5Column] == '4'||
                game_[Z5Row + 1][Z5Column] == '1')
            {
                continue;
            }
            game_[Z5Row + 1][Z5Column] = '5';
            game_[Z5Row][Z5Column] = ' ';
            Z5Row = Z5Row + 1;
            cout << "Zombie 5 moves down" << endl << endl;
            i = 0;
            break;

        case 'L':
            if (Z5Column -1 == -1)
            {
                continue;
            }
            if (game_[Z5Row][Z5Column - 1] == 'A'||
                game_[Z5Row][Z5Column - 1] == '2'||
                game_[Z5Row][Z5Column - 1] == '3'||
                game_[Z5Row][Z5Column - 1] == '4'||
                game_[Z5Row][Z5Column - 1] == '1')
            {
                continue;
            }
            game_[Z5Row][Z5Column - 1] = '5';
            game_[Z5Row][Z5Column] = ' ';
            Z5Column = Z5Column - 1;
            cout << "Zombie 5 moves left" << endl << endl;
            i = 0;
            break;

        case 'R':
            if (Z5Column + 1 == totalcolumns)
            {
                continue;
            }
            if (game_[Z5Row][Z5Column + 1] == 'A'||
                game_[Z5Row][Z5Column + 1] == '2'||
                game_[Z5Row][Z5Column + 1] == '3'||
                game_[Z5Row][Z5Column + 1] == '4'||
                game_[Z5Row][Z5Column + 1] == '1')
            {
                continue;
            }
            game_[Z5Row][Z5Column + 1] = '5';
            game_[Z5Row][Z5Column] = ' ';
            Z5Column = Z5Column + 1;
            cout << "Zombie 5 moves right" << endl << endl;
            i = 0;
            break;
        }

        displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range); 
        int Z5andADistance = abs(Z5Row - ARP) + abs(Z5Column - ACP);
        cout << "for checking distance and range : " <<Z5andADistance << " "<< zombie5Range<<endl;
        if (zombie5Range >= Z5andADistance)
        {
            cout << "Zombie 5 attacks Alien."<<endl;
            cout << "Alien receives a damage of " << zombie1Atk <<"."<< endl << endl;
            alienLife = alienLife - zombie1Atk;
        }
        
        if (zombie5Range < Z5andADistance)
        {
            cout << "Zombie 5 is unable to attack Alien."<<endl;
            cout << "Alien is too far"<< endl << endl;
        }
    }
}
