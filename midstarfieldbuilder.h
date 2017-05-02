/*
 * midstarfieldbuilder.h
 * Class header for building a Starfield with medium brightness stars that scroll at a moderate speed
 * by using the Starfield Builder interface and implementing its methods
 * Part of the Builder creational design pattern
 * Author: Anon
 */

#ifndef MIDSTARFIELDBUILDER_H
#define MIDSTARFIELDBUILDER_H

#include "starfieldbuilder.h"

class MidStarfieldBuilder : public StarfieldBuilder
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

#endif // MIDSTARFIELDBUILDER_H
