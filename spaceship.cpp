/*
 * spaceship.cpp
 * Class implementation for a spaceship that is a subclass of
 * Game Elements. It has a x, y coordinates and an image (.png) that is
 * able to vary by size (as per configuration) and colour (as selected
 * during game play)
 * Author: Anon
 */

#include "gameelement.h"
#include "spaceship.h"
#include <iostream>

using namespace std;

//Constructor loads images of spaceship  in red, blue, purple and green and scales for size
Spaceship::Spaceship(int xPos,
                     int yPos,
                     string size)
    : GameElement(xPos, yPos)
    , m_size(size)
{

    //String of file names relative to the makefile in the release build
    QPixmap tempShip_RED(":/images/SpaceshipRed.png");
    QPixmap tempShip_BLUE(":/images/SpaceshipBlue.png");
    QPixmap tempShip_PURPLE(":/images/SpaceshipPurple.png");
    QPixmap tempShip_GREEN(":/images/SpaceshipGreen.png");


    //Tiny spaceship is scaled to 40px by 40px
    if (size.compare("tiny") == 0)
    {
        m_spaceshipImage = tempShip_RED.scaled(QSize(40,40));
        m_spaceshipImage_RED = tempShip_RED.scaled(QSize(40,40));
        m_spaceshipImage_BLUE = tempShip_BLUE.scaled(QSize(40,40));
        m_spaceshipImage_PURPLE = tempShip_PURPLE.scaled(QSize(40,40));
        m_spaceshipImage_GREEN = tempShip_GREEN.scaled(QSize(40,40));
    }

    //Normal spaceship is scaled to 50px by 50px
    else if (size.compare("normal") == 0)
    {
        m_spaceshipImage = tempShip_RED.scaled(QSize(50,50));
        m_spaceshipImage_RED = tempShip_RED.scaled(QSize(50,50));
        m_spaceshipImage_BLUE = tempShip_BLUE.scaled(QSize(50,50));
        m_spaceshipImage_PURPLE = tempShip_PURPLE.scaled(QSize(50,50));
        m_spaceshipImage_GREEN = tempShip_GREEN.scaled(QSize(50,50));
    }

    //Large spaceship is scaled to 60px by 60px
    else if (size.compare("large") == 0)
    {
        m_spaceshipImage = tempShip_RED.scaled(QSize(60,60));
        m_spaceshipImage_RED = tempShip_RED.scaled(QSize(60,60));
        m_spaceshipImage_BLUE = tempShip_BLUE.scaled(QSize(60,60));
        m_spaceshipImage_PURPLE = tempShip_PURPLE.scaled(QSize(60,60));
        m_spaceshipImage_GREEN = tempShip_GREEN.scaled(QSize(60,60));
    }

    //Giant spaceship is scaled to 70px by 70px
    else if (size.compare("giant") == 0)
    {
        m_spaceshipImage = tempShip_RED.scaled(QSize(70,70));
        m_spaceshipImage_RED = tempShip_RED.scaled(QSize(70,70));
        m_spaceshipImage_BLUE = tempShip_BLUE.scaled(QSize(70,70));
        m_spaceshipImage_PURPLE = tempShip_PURPLE.scaled(QSize(70,70));
        m_spaceshipImage_GREEN = tempShip_GREEN.scaled(QSize(70,70));
    }

    //Default is normal, 50px by 50px
    else
    {
        m_spaceshipImage = tempShip_RED.scaled(QSize(50,50));
        m_spaceshipImage_RED = tempShip_RED.scaled(QSize(50,50));
        m_spaceshipImage_BLUE = tempShip_BLUE.scaled(QSize(50,50));
        m_spaceshipImage_PURPLE = tempShip_PURPLE.scaled(QSize(50,50));
        m_spaceshipImage_GREEN = tempShip_GREEN.scaled(QSize(50,50));
    }
}

//Desctructor
Spaceship::~Spaceship()
{

}

//Gets the image of the spaceship to be rendered in the game universe
QPixmap Spaceship::getSpaceshipImage() const
{
    return m_spaceshipImage;
}

//Moves the spaceship in the x axis
void Spaceship::moveSpaceshipX(int moveX)
{
    m_xPos += moveX;
}

//Moves the spaceship in the y axis
void Spaceship::moveSpaceshipY(int moveY)
{
    m_yPos += moveY;
}

//Updates the colour of the spaceship (1 = red, 2 = blue, 3 = purple, 4 = green)
void Spaceship::updateSpaceshipColour(int key)
{
    if (key == 1)
    {
        m_spaceshipImage = m_spaceshipImage_RED;
    }
    else if (key == 2)
    {
        m_spaceshipImage = m_spaceshipImage_BLUE;
    }
    else if (key == 3)
    {
        m_spaceshipImage = m_spaceshipImage_PURPLE;
    }
    else if (key == 4)
    {
        m_spaceshipImage = m_spaceshipImage_GREEN;
    }
}


