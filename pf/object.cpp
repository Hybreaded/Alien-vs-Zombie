#include "helper.h"
#include "setting.h"
#include "gboard.h"
#include "object.h"
#include <iostream>
using namespace std;

int Object::healthpack(Object& object1)
{
    cout << "Alien finds a health pack" << endl;
    cout << "Alien's life has increased by 20" <<endl;

    if (object1.alienhealth == 100)
    {
        cout << "Alien's health is already full, hence no increas on hp" << endl;
        return object1.alienhealth;
    }

    if (object1.alienhealth >= 80)
    {   
        object1.alienhealth = 100;
        cout << "Alien has full health now" << endl;
        return object1.alienhealth;
    }

    if (object1.alienhealth <80)
    {
        object1.alienhealth = object1.alienhealth + healthpack_;
        cout << "Alien's health is increased by 20, now alien have total of" << object1.alienhealth << " HP" << endl;
        return object1.alienhealth;
    }   
    return 0;
}

void Object::pod(Object& object1)
{
    cout << "Alien finds a pod" << endl;
    

}

void Object::rock(Object& object1)
{
    
}

void Object::moveup()
{

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
