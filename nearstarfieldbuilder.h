/*
 * nearstarfieldbuilder.h
 * Class header for building a Starfield with bright stars that scroll quickly
 * by using the Starfield Builder interface and implementing its methods
 * Part of the Builder creational design pattern
 * Author: Anon
 */

#ifndef NEARSTARFIELDBUILDER_H
#define NEARSTARFIELDBUILDER_H

#include "starfieldbuilder.h"

class NearStarfieldBuilder : public StarfieldBuilder
{
public:

    /*
     * Creates a new Starfield object in dynamic memory
     */
    void createStarfield();

    /*
     * Returns a pointer to a Starfield object
     * @return pointer to Starfield
     */
    Starfield* getStarfield();

    /*
     * Sets the Starfield size
     */
    void setSize();

    /*
     * Sets the Starfield colour
     */
    void setColour();

    /*
     * Populates the vector with randomised star coordinates
     */
    void setVector();

    /*
     * Sets the scrolling speed (y offset)
     */
    void setYOffset();
};

#endif // NEARSTARFIELDBUILDER_H
