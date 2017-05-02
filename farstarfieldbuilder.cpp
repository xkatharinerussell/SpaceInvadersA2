/*
 * farstarfieldbuilder.cpp
 * Class implementation for building a Starfield with dim stars that scroll slowly
 * by using the Starfield Builder interface and implementing its methods
 * Part of the Builder creational design pattern
 * Author: Anon
 */

#include "farstarfieldbuilder.h"
#include "starfield.h"
#include "starfieldbuilder.h"

//Creates a new Starfield object in dynamic memory
void FarStarfieldBuilder::createStarfield()
{
    m_starfield = new Starfield;
}

//Returns a pointer to a Starfield object
Starfield* FarStarfieldBuilder::getStarfield()
{
    return m_starfield;
}

//Sets the Starfield size
void FarStarfieldBuilder::setSize()
{
    m_starfield->setSize(200);
}

//Sets the Starfield colour
void FarStarfieldBuilder::setColour()
{
    m_starfield->setColor(QColor(100, 100, 100));
}

//Populates the vector with randomised star coordinates
void FarStarfieldBuilder::setVector()
{
    m_starfield->setVector();
}

//Sets the scrolling speed (y offset)
void FarStarfieldBuilder::setYOffset()
{
    m_starfield->setYOffset(1);
}
