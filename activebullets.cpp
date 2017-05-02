/*
 * activebullets.cpp
 * Class implementation for instantiating and moving
 * dynamically allocated bullets
 * Author: Anon
 */

#include "activebullets.h"
#include "bullet.h"

#include <iostream>

using namespace std;

//Constructor
ActiveBullets::ActiveBullets()
{

}

//Desctructor deletes all pointers to dynamically allocated bullet objects
//and clears the vector
ActiveBullets::~ActiveBullets()
{
    int size = m_bulletList.size();
    for (int i = 0; i < size; i++)
    {
        delete m_bulletList.at(i);
    }
    m_bulletList.clear();
}

//Gets empty status of bullet vector
bool ActiveBullets::isEmpty() const
{
    return m_bulletList.empty();
}

//Gets size of bullet vector
int ActiveBullets::getSize() const
{
    return m_bulletList.size();
}

//Gets a pointer to a bullet object at the given index in the vector
Bullet* ActiveBullets::getActiveBullet(int index) const
{
    return m_bulletList.at(index);
}

//Creates a new bullet object at x,y in dynamic memory
void ActiveBullets::addBullet(int xPos, int yPos)
{
    m_bulletList.push_back(new Bullet(xPos, yPos));
}

//Moves all bullets in the vector upwards in the y-axis and frees bullets
//no longer in view
void ActiveBullets::moveAllBullets()
{
    int size = m_bulletList.size();

    for (int i = 0; i < size; i++)
    {
        m_bulletList.at(i)->moveBullet(); //Moves bullets

        if (m_bulletList.at(i)->getY() <= -30)
        {
            delete m_bulletList.at(i); //Free the memory
            m_bulletList.erase(m_bulletList.begin() + i); //Erase the empty position in the vector
            size--;
        }
    }
}
