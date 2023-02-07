#include "helper.h"
#include "setting.h"
#include "gboard.h"
#include "object.h"
#include "gameplay1.h"
#include "gameplay2.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

Gameplay::Gameplay()
{
    alienLife = alienLife_; alienAtk = alienAtk_;
    A1 = A1_; Z1 = Z1_; Z2 = Z2_; Z3 = Z3_; Z4 = Z4_; Z5 = Z5_;
    Astatus = Astatus_;  Z1status = Z1status_; Z2status = Z2status_; Z3status = Z3status_; Z4status = Z4status_; Z5status = Z5status_ ;
}

void Gameplay::AlienStart(Gameplay& gameplay1)
{
    pf::ClearScreen();
    A1 = 1, Z1 = 0, Z2 = 0, Z3 = 0, Z4 = 0, Z5 = 0;
    displayBoard(gameplay1);
    displayAttributes(gameplay1);
    command(gameplay1);
}

void Gameplay::displayOnly(Gameplay& gameplay1)
{
    pf::Pause();
    pf::ClearScreen();
    displayBoard(gameplay1);
    displayAttributes(gameplay1);
}

void Gameplay::displayBoard(Gameplay& gameplay1)
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

void Gameplay::displayAttributes(Gameplay& gameplay1)
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

void Gameplay::command(Gameplay& gameplay1)
{
    char ans[5];
    cout <<endl <<"command >";
    cin >> ans;
    for (int i = 0; i < strlen(ans); ++i) //change ans to upper
    {
        ans[i] = toupper(ans[i]);
    }

    char help[] = "HELP";
    char up[] = "UP"; char down[] = "DOWN"; char left[] = "LEFT"; char right[] = "RIGHT";
    char arrow[] = "ARROW"; char save[] = "SAVE"; char load[]= "LOAD" ; char quit[]= "QUIT";
    
    switch (ans[0]) 
    {
    case 'H':
        for (int i = 0; i < strlen(help); ++i)
        {
            if (strlen(ans) != strlen(help) || ans[i] != help[i])
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        movementAns = ans[0]; 
        helpCommand(gameplay1);
        break;
        
    case 'U':
        for (int i = 0; i < strlen(up); ++i)
        {
            if (strlen(ans) != strlen(up) || ans[i] != up[i] )
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        movementAns = ans[0]; 
        movement(gameplay1);
        break;

    case 'D':
        for (int i = 0; i < strlen(down); ++i)
        {
            if (strlen(ans) != strlen(down) || ans[i] != down[i])
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        movementAns = ans[0]; 
        movement(gameplay1);
        break;

    case 'L':
        for (int i = 0; i < strlen(left); ++i)
        {
            if (strlen(ans) != strlen(left) || ans[i] != left[i])
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        movementAns = ans[0]; 
        movement(gameplay1);
        break;

    case 'R':
        for (int i = 0; i < strlen(right); ++i)
        {
            if (strlen(ans) != strlen(right) || ans[i] != right[i])
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        movementAns = ans[0];
        movement(gameplay1);
        break;

    case 'A':
        if (strlen(ans) != strlen(arrow))
        {
            cout << "Please enter correct characters"<< endl << endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        for (int i = 0; i < strlen(arrow); ++i)
        {
            //cout << "char ans = " << ans[i] << " char arrow = "<< arrow[i]<<endl; 
            if (ans[i] != arrow[i])
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        arrowChange(gameplay1);
        break;

    case 'T' :
        return;
        break;
        
    default:
        cout << "Please enter correct characters"<< endl << endl;
        pf::Pause();
        AlienStart(gameplay1);
    }
}

void Gameplay::helpCommand(Gameplay& gameplay1)
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
    AlienStart(gameplay1);
}

void Gameplay::movement(Gameplay& gameplay1)
{
    for (int y = 0; y < totalrows; ++y)  //search 'A' index
    {
        for (int x = 0; x < totalcolumns; ++x) 
        {
            if (game_[y][x] == 'A')
            {   
                ARP = y; ACP = x;
                break;
            }
        }
    }

    switch (movementAns) //This gameplay1.movementAns is the user enter the command like Up down left right 
    {
    case 'U':
        boarderCheck(gameplay1);  //if pass means can move
        cout << "Alien move up"<< endl << endl;
        RowElement = ARP - 1; ColumnElement = ACP; //the "RowElement" and "ColumnElement" are the index of the next element
        elementCheck(gameplay1); //call function to check element by using the index created above this line
        moving(gameplay1); //call function to change the index of A to the entered direction
        stopCheck(gameplay1); //refresh board and check whether have hit boarder or not|| if hit, zombie turn.
        break;

    case 'D':
        boarderCheck(gameplay1);
        cout << "Alien move down"<< endl << endl;
        RowElement = ARP + 1; ColumnElement = ACP;
        elementCheck(gameplay1);
        moving(gameplay1);
        stopCheck(gameplay1);
        break;

    case 'L':
        boarderCheck(gameplay1);
        cout << "Alien move left"<< endl << endl;
        RowElement = ARP ; ColumnElement = ACP - 1;
        elementCheck(gameplay1);
        moving(gameplay1);
        stopCheck(gameplay1);
        break;

    case 'R':
        boarderCheck(gameplay1);
        cout << "Alien move right"<< endl << endl;
        RowElement = ARP; ColumnElement = ACP + 1;
        elementCheck(gameplay1);
        moving(gameplay1);
        stopCheck(gameplay1);
        break;     
    }
}

void Gameplay::boarderCheck(Gameplay& gameplay1)
{
    //cout <<endl<< "For Testing Alien y and x " << gameplay1.ARP << " "<< gameplay1.ACP<<endl<<endl;
    switch (movementAns) 
    {
    case 'U':
        if (ARP - 1 == -1)
        {
            cout << "You can't move up, u have reach the boarder."<< endl;
            pf::Pause();
            AlienStart(gameplay1);
        }     
        break;

    case 'D':
        if (ARP + 1 == totalrows)
        {
            cout << "You can't move down, u have reach the boarder."<< endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        break;

    case 'L':
        if (ACP - 1 == -1)
        {
            cout << "You can't move left, u have reach the boarder."<< endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        break;

    case 'R':
       if (ACP + 1 == totalcolumns)
        {
            cout << "You can't move right, u have reach the boarder."<< endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        break;
    }
}
 
void Gameplay::elementCheck(Gameplay& gameplay1)
{
    Object object;
    nextElement = game_[RowElement][ColumnElement];
    switch (nextElement)  //check the element 
    {
    case 'h':
        object.healthpack(game_, movementAns, alienLife, ARP, ACP);
        
        break;
    case 'p':
        object.pod(game_ ,totalrows, totalcolumns, totalZombies, 
                    zombie1Life, zombie2Life, zombie3Life, zombie4Life, zombie5Life, movementAns);
       
        break;
    case 'r':
        object.rock(game_, RowElement, ColumnElement);
        displayOnly(gameplay1);
        cout << "Alien's turn ends, The trails has reset"<< endl<< endl;
        trailReset(gameplay1);
        ZombieCheck(gameplay1);
        break;
    case '^':
        object.ArrowUp();
        
        break;
    case 'v':
        object.ArrowDown();
        
        break;
    case '<':
        object.ArrowLeft();
        
        break;
    case '>':
        object.ArrowRight();
        
        break;
    case ' ':
        moving(gameplay1);
        break;
    case '.':
        moving(gameplay1);
        break;

    default:
        alienATKzombie(gameplay1);
        break;
    }
    
}

void Gameplay::moving(Gameplay& gameplay1)

{
    game_[RowElement][ColumnElement] = 'A';
    game_[ARP][ACP] = '.';
}

void Gameplay::stopCheck(Gameplay& gameplay1)
{
    displayOnly(gameplay1);
    switch (movementAns) 
    {
    case 'U':
       if (ARP - 1 == 0 )
        {
            cout << "Alien hit the boarder."<<endl;
            cout << "Alien turn's end. The trail is reset." << endl << endl;
            trailReset(gameplay1);
            ZombieCheck(gameplay1);
        }
        break;

    case 'D':
        if (ARP + 1 == (totalrows - 1) )
        {
            cout << "Alien hit the boarder."<<endl;
            cout << "Alien turn's end. The trail is reset." << endl << endl;
            trailReset(gameplay1);
            ZombieCheck(gameplay1);
        }
        break;
        
    case 'L':
        if (ACP - 1 == 0 )
        {
            cout << "Alien hit the boarder."<<endl;
            cout << "Alien turn's end. The trail is reset." << endl << endl;
            trailReset(gameplay1);
            ZombieCheck(gameplay1);
        }
        break;
        
    case 'R':
       if (ACP + 1 == (totalcolumns - 1) )
        {
            cout << "Alien hit the boarder."<<endl;
            cout << "Alien turn's end. The trail is reset." << endl << endl;
            trailReset(gameplay1);
            ZombieCheck(gameplay1);
        }
        break;
    }
    AlienStart(gameplay1);
}

void Gameplay::trailReset(Gameplay& gameplay1)
{
    for (int y = 0; y < totalrows; ++y)
    {
        for (int x = 0; x < totalcolumns; ++x) 
        {
            char elements[] = {' ',' ',' ','<','>','^','v','h','p','r'};
            int numeoflements = 10;
            if (game_[y][x] == '.')
            {   
                int random = rand() % numeoflements;
                game_[y][x] = elements[random];
            }
        }
    }
}

void Gameplay::arrowChange(Gameplay& gameplay1)

{
    int newRow, newColumn; char newDirection[5] ;
    cout << "Enter Row, Column and Direction: ";
    cin >> newRow >> newColumn >> newDirection;

    for (int i = 0; i < strlen(newDirection); ++i) //chg upper case
    {
        newDirection[i] = toupper(newDirection[i]);
    }
    
    if(newRow < 0 || newRow > totalrows || newColumn < 0 || newColumn > totalcolumns) //check range
    {
        cout << "Please enter correct range"<< endl << endl;
        pf::Pause();
        AlienStart(gameplay1);
    }
    
    newRow = newRow - 1; newColumn = newColumn - 1; //to get vector base index
    char up[] = "UP"; char down[] = "DOWN"; char left[] = "LEFT"; char right[] = "RIGHT";

    switch (newDirection[0])
    {
    case 'U':
        for(int i = 0 ; i < strlen(newDirection); ++i)
        {   
            if (strlen(newDirection) != strlen(up) || newDirection[i] != up[i]) //check character correct/not
            {
                cout << "Please enter correct direction"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        if (game_[newRow][newColumn] != '^' && game_[newRow][newColumn] != 'v' && game_[newRow][newColumn] != '<' && game_[newRow][newColumn] != '>') 
        {
            cout << "There's no arrow in this place" <<endl <<endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        cout << "Arrow " << game_[newRow][newColumn] << " has switch to ^" << endl;
        game_[newRow][newColumn] = '^';
        pf::Pause();
        AlienStart(gameplay1);
        break;

    case 'D':
        for(int i = 0 ; i < strlen(newDirection); ++i)
        {   
            if (strlen(newDirection) != strlen(down) || newDirection[i] != down[i])
            {
                cout << "Please enter correct direction"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        if (game_[newRow][newColumn] != '^' && game_[newRow][newColumn] != 'v' && game_[newRow][newColumn] != '<' && game_[newRow][newColumn] != '>')
        {
            cout << "There's no arrow in this place" << endl <<endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        cout << "Arrow " << game_[newRow][newColumn] << " has switch to <" << endl;
        game_[newRow][newColumn] = 'v';
        pf::Pause();
        AlienStart(gameplay1);
        break;

    case 'L':
        for(int i = 0 ; i < strlen(newDirection); ++i)
        {   
            if (strlen(newDirection) != strlen(left) || newDirection[i] != left[i])
            {
                cout << "Please enter correct direction"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        if (game_[newRow][newColumn] != '^' && game_[newRow][newColumn] != 'v' && game_[newRow][newColumn] != '<' && game_[newRow][newColumn] != '>')
        {
            cout << "There's no arrow in this place" << endl <<endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        cout << "Arrow " << game_[newRow][newColumn] << " has switch to <" << endl;
        game_[newRow][newColumn] = '<';
        pf::Pause();
        AlienStart(gameplay1);
        break;

    case 'R':
        for(int i = 0 ; i < strlen(newDirection); ++i)
        {   
            if (strlen(newDirection) != strlen(right) || newDirection[i] != right[i])
            {
                cout << "Please enter correct direction"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        if (game_[newRow][newColumn] != '^' && game_[newRow][newColumn] != 'v' && game_[newRow][newColumn] != '<' && game_[newRow][newColumn] != '>')
        {
            cout << "There's no arrow in this place" << endl <<endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        cout << "Arrow " << game_[newRow][newColumn] << " has switch to >" << endl;
        game_[newRow][newColumn] = '>';
        pf::Pause();
        AlienStart(gameplay1);
        break; 

    default:
        cout << "Please enter correct value and direction"<< endl << endl;
        pf::Pause();
        AlienStart(gameplay1);
        break;
    }
    
}

void Gameplay::alienATKzombie(Gameplay& gameplay1)
{
    switch (nextElement)
    {
    case '1':
        cout << "Alien attack zombie 1." << endl;
        if (alienAtk == 0)
        {
            cout << "Alien has 0 attack. No damage inflicts to the zombie 1 "<<endl;
            cout << "Zombie 1 is still alive" <<endl;
        }
        if (alienAtk >= 20)
        {
            cout << "Zombie 1 receives a damage of "<< alienAtk <<endl;
            if (zombie1Life > 20)
            {
                zombie1Life = zombie1Life - alienAtk;
                cout << "Zombie 1 is still alive" <<endl;
            }
            if (zombie1Life <= 20)
            {
                zombie1Life = 0;
                Z1status = 'd';
                moving(gameplay1);
                pf::Pause();
                stopCheck(gameplay1);
            }
        }
        break;

    case '2':
        cout << "Alien attack zombie 2." << endl;
        if (alienAtk == 0)
        {
            cout << "Alien has 0 attack. No damage inflicts to the zombie 2 "<<endl;
            cout << "Zombie 2 is still alive" <<endl;
        }
        if (alienAtk >= 20)
        {
            cout << "Zombie 2 receives a damage of "<< alienAtk <<endl;
            if (zombie2Life > 20)
            {
                zombie2Life = zombie2Life - alienAtk;
                cout << "Zombie 2 is still alive" <<endl;
            }
            if (zombie1Life <= 20)
            {
                zombie2Life = 0;
                Z2status = 'd';
                moving(gameplay1);
                pf::Pause();
                stopCheck(gameplay1);
            }
        }
        break;

    case '3':
        cout << "Alien attack zombie 3." << endl;
        if (alienAtk == 0)
        {
            cout << "Alien has 0 attack. No damage inflicts to the zombie 3 "<<endl;
            cout << "Zombie 3 is still alive" <<endl;
        }
        if (alienAtk >= 20)
        {
            cout << "Zombie 3 receives a damage of "<< alienAtk <<endl;
            if (zombie3Life > 20)
            {
                zombie3Life = zombie3Life - alienAtk;
                cout << "Zombie 3 is still alive" <<endl;
            }
            if (zombie3Life <= 20)
            {
                zombie3Life = 0;
                Z3status = 'd';
                moving(gameplay1);
                pf::Pause();
                stopCheck(gameplay1);
            }
        }
        break;

    case '4':
        cout << "Alien attack zombie 4." << endl;
        if (alienAtk == 0)
        {
            cout << "Alien has 0 attack. No damage inflicts to the zombie 4 "<<endl;
            cout << "Zombie 4 is still alive" <<endl;
        }
        if (alienAtk >= 20)
        {
            cout << "Zombie 4 receives a damage of "<< alienAtk <<endl;
            if (zombie4Life > 20)
            {
                zombie4Life = zombie4Life - alienAtk;
                cout << "Zombie 4 is still alive" <<endl;
            }
            if (zombie4Life <= 20)
            {
                zombie4Life = 0;
                Z4status = 'd';
                moving(gameplay1);
                pf::Pause();
                stopCheck(gameplay1);
            }
        }
        break;
        
    case '5':
        cout << "Alien attack zombie 5." << endl;
        if (alienAtk == 0)
        {
            cout << "Alien has 0 attack. No damage inflicts to the zombie 5 "<<endl;
            cout << "Zombie 5 is still alive" <<endl;
        }
        if (alienAtk >= 20)
        {
            cout << "Zombie 5 receives a damage of "<< alienAtk <<endl;
            if (zombie5Life > 20)
            {
                zombie5Life = zombie5Life - alienAtk;
                cout << "Zombie 5 is still alive" <<endl;
            }
            if (zombie5Life <= 20)
            {
                zombie5Life = 0;
                Z5status = 'd';
                cout << "Zombie 5 has been defeated."<<endl;
                moving(gameplay1);
                pf::Pause();
                stopCheck(gameplay1);
            }
        }
        break;
    }
    displayOnly(gameplay1);
    cout<< "Alien turns end, the trail has reset." << endl;
    trailReset(gameplay1);
    ZombieCheck(gameplay1);
}

void Gameplay::ZombieCheck(Gameplay& gameplay1)
{
    Gameplay2 gameplay2;
    for (int i = 1; i <= totalZombies; ++i)
    {
        switch (i)
        {
        case 1:
            gameplay2.Zombie1Start(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies,
                                alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range,
                                zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
            break;
        case 2:
            gameplay2.Zombie2Start(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies,
                                alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range,
                                zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
            break;
        case 3:
            gameplay2.Zombie3Start(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies,
                                alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range,
                                zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
            break;
        case 4:
            gameplay2.Zombie4Start(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies,
                                alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range,
                                zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
            break;
        case 5:
            gameplay2.Zombie5Start(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies,
                                alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range,
                                zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
            break;
        }
    }
    pf::Pause();
    AlienStart(gameplay1);
}

