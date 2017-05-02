/*
 * starfield.cpp
 * Class implementation for creating starfield objects that scroll
 * through the background of the game
 * Author: Anon
 */

#include "globaldimensions.h"
#include "starfield.h"
#include <vector>

using namespace std;

//Constructor
Starfield::Starfield()
{

}

//Deletes the dynamically allocated pair pointers in the
//vector and then clears the vector
Starfield::~Starfield()
{
    int size = m_starVector.size();
    for (int i = 0; i < size; i++)
    {
        delete m_starVector.at(i);
    }
    m_starVector.clear();
}

//Gets the size of the vector holding the pair pointers
int Starfield::getSize() const
{
    return m_vectorSize;
}

//Gets the colour of the stars in the starfield
QColor Starfield::getColour() const
{
    return m_colour;
}

//Gets the x position of the star at a certain index
int Starfield::getX(int index) const
{
    return m_starVector.at(index)->first;
}

//Gets the y position of the star at a certain index
int Starfield::getY(int index) const
{
    return m_starVector.at(index)->second;
}

//Sets the size of the vector ie number of stars in the starfield
void Starfield::setSize(int size)
{
    m_vectorSize = size;
}

//Sets the size of the colour of the stars in the starfield
void Starfield::setColor(QColor colour)
{
    m_colour = colour;
}

//Sets the speed at which the stars move
void Starfield::setYOffset(int y)
{
    m_yOffset = y;
}

//Creates the vector with pointers to dynamically allocated pairs
//that hold two intergers representing the x coordinate and y coordinate
void Starfield::setVector()
{
    for (int i = 0; i < m_vectorSize; i++)
    {
        int x = rand() % globalWidth; // random int between 0 - globalwidth
        int y = rand() % globalHeight; // random int between 0 - globalheight
        pair<int, int>* newPair = new pair<int, int>(x, y);
        m_starVector.push_back(newPair);
    }
}

//Adds the y offset to the y coordinate of all stars in the starfield
void Starfield::moveStars()
{
    for (int i = 0; i < m_vectorSize; i++)
    {
        m_starVector.at(i)->second += m_yOffset;

        //When the stars get to the bottom of the screen they are
        //reintroduced at the top of the screen
        if (m_starVector.at(i)->second > globalHeight)
        {
            m_starVector.at(i)->second = 0;
        }

    }
}
