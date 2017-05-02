/*
 * starfieldcreator.h
 * Class header for creating different types of Starfield objects
 * using the builders for starfields with variations in common attributes.
 * Part of the Builder creational design pattern.
 * Author: Anon
 */

#ifndef STARFIELDCREATOR_H
#define STARFIELDCREATOR_H

#include "farstarfieldbuilder.h"
#include "midstarfieldbuilder.h"
#include "starfield.h"
#include "starfieldbuilder.h"

class StarfieldCreator
{
public:

    /*
     ***** Constructor *****
     * Constructor takes a pointer to a starfieldbuilder
     * and saves it as a member variable to build a specific type of
     * starfield
     * @param pointer to a builder object that uses the starfieldbuilder interface
     */
    StarfieldCreator(StarfieldBuilder* builder);

    /*
     * Returns a Starfield pointer to a specialised starfield allocated to heap memory
     */
    Starfield* createStarfield();

private:
    StarfieldBuilder* m_builder; //pointer to a type of starfieldbuilder
};

#endif // STARFIELDCREATOR_H
