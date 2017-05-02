/*
 * spaceship.h
 * Class header for a spaceship that is a subclass of
 * Game Elements. It has a x, y coordinates and an image (.png) that is
 * able to vary by size (as per configuration) and colour (as selected
 * during game play)
 * Author: Anon
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "gameelement.h"
#include <string>
#include <QPixmap>

using namespace std;

class Spaceship : public GameElement
{
public:

    /*
     ***** CONSTRUCTOR *****
     * @param x position, y position of the object provided as game element
     * arguments and a string for the size from the configuration file
     * with defaults provided x = -1000, y = -1000, size = "normal"
     */
    Spaceship(int xPos = -1000,
              int yPos = -1000,
              string size = "normal");

    /*
     ***** DESTRUCTOR *****
     */
    ~Spaceship();

    /*
     * Gets the image of the spaceship to be rendered in the game universe
     * @return QPixmap of spaceship
     */
    QPixmap getSpaceshipImage() const;

    /*
     * Moves the spaceship in the x axis
     * @param moveX is an integer added to the x position
     */
    void moveSpaceshipX(int moveX);

    /*
     * Moves the spaceship in the y axis
     * @param moveY is an integer added to the y position
     */
    void moveSpaceshipY(int moveY);

    /*
     * Updates the colour of the spaceship (1 = red, 2 = blue, 3 = purple, 4 = green)
     * @param key is an integer used to select a colour
    */
    void updateSpaceshipColour(int key);

private:
    string m_size; //spaceship size from configuration file
    QPixmap m_spaceshipImage; //image rendered in the game universe
    QPixmap m_spaceshipImage_RED; //red spaceship - key 1
    QPixmap m_spaceshipImage_BLUE; //blue spaceship - key 2
    QPixmap m_spaceshipImage_PURPLE; //purple spaceship - key 3
    QPixmap m_spaceshipImage_GREEN; //green spaceship - key 4
};

#endif // SPACESHIP_H
