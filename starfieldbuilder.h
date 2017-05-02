/*
 * starfieldbuilder.h
 * Interface header for declaring methods required to build different types of Starfield objects
 * using the Builder creational design pattern. All methods are pure virtual and need to be
 * implemented by the specific Starfield builders that use the interface.
 * Author: Anon
 */

#ifndef STARFIELDBUILDER_H
#define STARFIELDBUILDER_H

#include "starfield.h"

class StarfieldBuilder
{
public:

    virtual void createStarfield() = 0;

    virtual Starfield* getStarfield() = 0;

    virtual void setSize() = 0;

    virtual void setColour() = 0;

    virtual void setVector() = 0;

    virtual void setYOffset() = 0;

protected:
    Starfield* m_starfield; //pointer to a Starfield object
};

#endif // STARFIELDBUILDER_H
