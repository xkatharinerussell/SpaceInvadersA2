/*
 * nearstarfieldbuilder.cpp
 * Class implementation for building a Starfield with bright stars that scroll quickly
 * by using the Starfield Builder interface and implementing its methods
 * Part of the Builder creational design pattern
 * Author: Anon
 */

#include "nearstarfieldbuilder.h"
#include "starfield.h"
#include "starfieldbuilder.h"

//Creates a new Starfield object in dynamic memory
void NearStarfieldBuilder::createStarfield()
{
    m_starfield = new Starfield;
}

//Returns a pointer to a Starfield object
Starfield* NearStarfieldBuilder::getStarfield()
{
    return m_starfield;
}

//Sets the Starfield size
void NearStarfieldBuilder::setSize()
{
    m_starfield->setSize(50);
}

//Sets the Starfield colour
void NearStarfieldBuilder::setColour()
{
    m_starfield->setColor(QColor(255, 255, 255));
}

//Populates the vector with randomised star coordinates
void NearStarfieldBuilder::setVector()
{
    m_starfield->setVector();
}

//Sets the scrolling speed (y offset)
void NearStarfieldBuilder::setYOffset()
{
    m_starfield->setYOffset(3);
}
