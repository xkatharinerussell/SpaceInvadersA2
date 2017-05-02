/*
 * farstarfieldbuilder.h
 * Class header for building a Starfield with dim stars that scroll slowly
 * by using the Starfield Builder interface and implementing its methods.
 * Part of the Builder creational design pattern
 * Author: Anon
 */

#ifndef FARSTARFIELDBUILDER_H
#define FARSTARFIELDBUILDER_H

#include "starfieldbuilder.h"

class FarStarfieldBuilder : public StarfieldBuilder
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

#endif // FARSTARFIELDBUILDER_H
