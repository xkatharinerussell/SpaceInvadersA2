/*
 * starfield.h
 * Class header for creating starfield objects that scroll
 * through the background of the game
 * Author: Anon
 */

#ifndef STARFIELD_H
#define STARFIELD_H

#include <QColor>
#include <vector>

using namespace std;

class Starfield
{
public:

    /*
     ***** Constructor *****
     */
    Starfield();

    /*
     ***** Destructor *****
     * Deletes the dynamically allocated pair pointers in the
     * vector and then clears the vector
     */
    ~Starfield();

    /*
     * Gets the size of the vector holding the pair pointers
     * @return integer of vector size
     */
    int getSize() const;

    /*
     * Gets the colour of the stars in the starfield
     * @return QColor of stars
     */
    QColor getColour() const;

    /*
     * Gets the x position of the star at a certain index
     * @return integer of x position of star
     */
    int getX(int index) const;

    /*
     * Gets the y position of the star at a certain index
     * @return integer of y position of star
     */
    int getY(int index) const;

    /*
     * Sets the size of the vector ie number of stars in the starfield
     * @param integer of the size
     */
    void setSize(int size);

    /*
     * Sets the size of the colour of the stars in the starfield
     * @param QColor of colour
     */
    void setColor(QColor colour);

    /*
     * Sets the speed at which the stars move
     * @param integer of rate at which stars scroll downwards
     */
    void setYOffset(int y);

    /*
     * Creates the vector with pointers to dynamically allocated pairs
     * that hold two intergers representing the x coordinate and y coordinate
     */
    void setVector();

    /*
     * Adds the y offset to the y coordinate of all stars in the starfield
     */
    void moveStars();

private:
    int m_vectorSize; //number of stars
    int m_yOffset; //rate the stars scroll downwards
    QColor m_colour; //colour of the stars
    vector<pair<int, int>*> m_starVector; //vector holds pointers to pair coordinates <int x, int y>

};

#endif // STARFIELD_H
