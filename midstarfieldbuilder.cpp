/*
 * midstarfieldbuilder.cpp
 * Class implementation for building a Starfield with medium brightness stars that scroll at a moderate speed
 * by using the Starfield Builder interface and implementing its methods
 * Part of the Builder creational design pattern
 * Author: Anon
 */

#include "midstarfieldbuilder.h"
#include "starfield.h"
#include "starfieldbuilder.h"

//Creates a new Starfield object in dynamic memory
void MidStarfieldBuilder::createStarfield()
{
    m_starfield = new Starfield;
}

//Returns a pointer to a Starfield object
Starfield* MidStarfieldBuilder::getStarfield()
{
    return m_starfield;
}

//Sets the Starfield size
void MidStarfieldBuilder::setSize()
{
    m_starfield->setSize(100);
}

//Sets the Starfield colour
void MidStarfieldBuilder::setColour()
{
    m_starfield->setColor(QColor(200, 200, 200));
}

//Populates the vector with randomised star coordinates
void MidStarfieldBuilder::setVector()
{
    m_starfield->setVector();
}

//Sets the scrolling speed (y offset)
void MidStarfieldBuilder::setYOffset()
{
    m_starfield->setYOffset(2);
}
