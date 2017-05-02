/*
 * starfieldcreator.cpp
 * Class implementation for creating different types of Starfield objects
 * using the builders for starfields with variations in common attributes.
 * Part of the Builder creational design pattern.
 * Author: Anon
 */

#include "starfieldcreator.h"

//Constructor takes a pointer to a starfieldbuilder
//and saves it as a member variable to build a specific type of
//starfield
StarfieldCreator::StarfieldCreator(StarfieldBuilder* builder)
    : m_builder(builder)
{

}

//Returns a Starfield pointer to a specialised starfield allocated to heap memory
Starfield* StarfieldCreator::createStarfield()
{
    m_builder->createStarfield();
    m_builder->setSize();
    m_builder->setColour();
    m_builder->setYOffset();
    m_builder->setVector();
    return m_builder->getStarfield();
}
