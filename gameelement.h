/*
 * gameelements.h
 * Abstract class for game elements that have an x, y position within
 * the game universe that are considered interactive (ie. not background environment)
 * Author: Anon
 */

#ifndef GAMEELEMENT_H
#define GAMEELEMENT_H

class GameElement
{
public:

    /*
     ***** CONSTRUCTOR *****
     * @param x position, y position of the object
     */
    GameElement(int xPos = -1000,
                int yPos = -1000)
        : m_xPos(xPos)
        , m_yPos(yPos)
    {}

    /*
     ***** VIRTUAL DESTRUCTOR *****
     */
    virtual ~GameElement() {}

    /*
     * Gets the x position of the object
     * @return x position as an int
     */
    virtual int getX() const { return m_xPos; }

    /*
     * Gets the y position of the object
     * @return y position as an int
     */
    virtual int getY() const { return m_yPos; }

protected:
    int m_xPos; //x coordinate
    int m_yPos; //y coordinate
};

#endif // GAMEELEMENT_H
