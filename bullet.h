/*
 * bullet.h
 * Class header for a bullet that is a subclass of
 * Game Elements. Each instance is given x,y coordinates relative to
 * the spaceship position at the time of instantiation
 * Author: Anon
 */

#ifndef BULLET_H
#define BULLET_H

#include "gameelement.h"
#include <QPixmap>

class Bullet : public GameElement
{
public:

    /*
     ***** CONSTRUCTOR *****
     * @param x position, y position of the object provided as game element
     * arguments with defaults provided x = -1000, y = -1000
     */
    Bullet(int xPos = -1000, int yPos = -1000);

    /*
     ***** DESTRUCTOR *****
     */
    ~Bullet();

    /*
     * Gets the image of the bullet to be rendered in the game universe
     * @return QPixmap of bullet
     */
    QPixmap getBulletImage() const;

    /*
     * Moves the spaceship in the y axis
     */
    void moveBullet();

private:
    QPixmap m_bulletImage; //image of bullet

};

#endif // BULLET_H
