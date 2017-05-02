/*
 * universe.cpp
 * Class implementation for game universe that is a subclass of QDialog.
 * The universe dialog creates a game configuration objects, a spaceship object, an
 * active bullets object and three starfields that scroll through the background.
 * Every 20msec the frame is refreshed showing the movement of these game elements
 * and background objects. The instructions for movement are within saved to the
 * GameConfiguration object by the IOFile object that also saves the last x coordinate
 * of the spaceship back to the config.ini file in the destructor.
 * Author: Anon
 */

#include "iofile.h"
#include "farstarfieldbuilder.h"
#include "gameconfiguration.h"
#include "globaldimensions.h"
#include "midstarfieldbuilder.h"
#include "nearstarfieldbuilder.h"
#include "starfieldbuilder.h"
#include "starfieldcreator.h"
#include "universe.h"
#include <QKeyEvent>
#include <QTimer>


namespace universe { //start namespace

    //Constructor has a default QWidget value of nullptr
    Universe::Universe(QWidget *parent) : QDialog(parent)
    {
        //READ CONFIG FILE
        //Create a file processing object to read and write to the config object
        IOFile iofile(m_config);

        //Read the config file
        iofile.readFile();


        //CREATE AND ADJUST SPACESHIP
        //Pointer to an instance of a spaceship object
        int xPosition = m_config.getStartingXPos();
        int yPosition = globalHeight - globalPadding;
        string size = m_config.getSpaceshipSize();
        m_spaceship = new Spaceship(xPosition, yPosition, size);

        //Adjust y position for spaceship height
        int adjustY = -1 * m_spaceship->getSpaceshipImage().height();
        m_spaceship->moveSpaceshipY(adjustY);


        //CREATE SCROLLING STARS
        //initialise background stars
        StarfieldBuilder *builder1 = new FarStarfieldBuilder;
        StarfieldCreator creator1(builder1);
        m_farStarfield = creator1.createStarfield();

        //initialise midground stars
        StarfieldBuilder *builder2 = new MidStarfieldBuilder;
        StarfieldCreator creator2(builder2);
        m_midStarfield = creator2.createStarfield();

        //initialise foreground stars
        StarfieldBuilder *builder3 = new NearStarfieldBuilder;
        StarfieldCreator creator3(builder3);
        m_nearStarfield = creator3.createStarfield();

        //delete builders to free memory
        delete builder1;
        delete builder2;
        delete builder3;


        //BACKGROUND SETUP
        setStyleSheet("background-color: #000000;");
        this->resize(globalWidth, globalHeight);
        update();

        //TIMER SETUP
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
        timer->start(20); //20msec
    }

    //Destructor saves the last x coordinate of the spaceship to config.ini
    //and deletes the spaceship and starfield to free memory
    Universe::~Universe()
    {
        IOFile iofile(m_config);
        iofile.writeFile(m_spaceship->getX());
        delete m_spaceship;
        delete m_farStarfield;
        delete m_midStarfield;
        delete m_nearStarfield;
    }

    //Paints the graphics in the dialog
    void Universe::paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);

        //PAINT STARS
        //Paint background starfield
        painter.setPen(QPen(m_farStarfield->getColour(), 1));
        for (int i = 0; i < m_farStarfield->getSize(); i++)
        {
            painter.drawPoint(QPoint(m_farStarfield->getX(i), m_farStarfield->getY(i)));
        }

        //Paint midground starfield
        painter.setPen(QPen(m_midStarfield->getColour(), 1));
        for (int i = 0; i < m_midStarfield->getSize(); i++)
        {
            painter.drawPoint(QPoint(m_midStarfield->getX(i), m_midStarfield->getY(i)));
        }

        //Paint foreground starfield
        painter.setPen(QPen(m_nearStarfield->getColour(), 1));
        for (int i = 0; i < m_nearStarfield->getSize(); i++)
        {
            painter.drawPoint(QPoint(m_nearStarfield->getX(i), m_nearStarfield->getY(i)));
        }

        //PAINT ACTIVE BULLETS
        //Draw any active bullets using the object (x, y) coordinates
        if (!m_bullets.isEmpty()) {
            int size = m_bullets.getSize();

            for(int i = 0; i < size; i++)
            {
                Bullet *currentBullet = m_bullets.getActiveBullet(i);
                painter.drawPixmap(currentBullet->getX(), currentBullet->getY(), currentBullet->getBulletImage());
            }

        }

        //PAINT SPACESHIP
        //Draw the spaceship using the object (x, y) coordinates
        painter.drawPixmap(m_spaceship->getX(), m_spaceship->getY(), m_spaceship->getSpaceshipImage());

    }

    //Responds to keys pressed during the game
    void Universe::keyPressEvent(QKeyEvent *event)
    {
        //Red spaceship if '1' is pressed
        if (event->key() == Qt::Key_1)
        {
            m_spaceship->updateSpaceshipColour(1);
        }

        //Blue spaceship if '2' is pressed
        else if (event->key() == Qt::Key_2)
        {
            m_spaceship->updateSpaceshipColour(2);
        }

        //Purple spaceship if '3' is pressed
        else if (event->key() == Qt::Key_3)
        {
            m_spaceship->updateSpaceshipColour(3);
        }

        //Green spaceship if '4' is pressed
        else if (event->key() == Qt::Key_4)
        {
            m_spaceship->updateSpaceshipColour(4);
        }
    }

    //Alters the coordinates of objects active in the dialog
    //and updates the frame
    void Universe::nextFrame()
    {

        int numOfDirections = int(m_config.getDirections().size());
        int xMax = globalWidth - globalPadding - m_spaceship->getSpaceshipImage().width() - 1;
        int xMin = globalPadding;

        //If there are more instructions to read, continue to read instructions
        if (m_directionsIndex < numOfDirections)
        {
            m_readingInstructions = true;
        }

        //Else, read no further instructions and use default movements
        else
        {
            m_readingInstructions = false;
        }


        //READING CONFIGURATION DIRECTIONS - provided in config.ini
        //If reading instructions has been set to true
        if (m_readingInstructions)
        {

            string instruction = m_config.getDirections().at(m_directionsIndex);

            //SHOOT BULLET AND FOLLOW NEXT INSTRUCTION
            if (instruction.compare("shoot") == 0)
            {
                int bulletX = m_spaceship->getX() + (m_spaceship->getSpaceshipImage().width() / 2) - 10;
                int bulletY = m_spaceship->getY();
                m_bullets.addBullet(bulletX, bulletY);

                //If shoot wasn't the last instruction, find the next ship movement instruction
                if ((m_directionsIndex + 1) < numOfDirections)
                {
                    m_directionsIndex++;
                    instruction = m_config.getDirections().at(m_directionsIndex);
                }

            }

            //MOVE SPACESHIP RIGHT
            if (instruction.compare("right") == 0)
            {
                if (m_spaceship->getX() <= xMax)
                {
                    m_spaceship->moveSpaceshipX(m_spaceshipMover);
                }
            }

            //MOVE SPACESHIP LEFT
            else if (instruction.compare("left") == 0)
            {
                if (m_spaceship->getX() >= xMin)
                {
                    m_spaceship->moveSpaceshipX(m_spaceshipMover * -1);
                }
            }

            //The pixel interval is the length of pixels the ship can travel across in the x-axis,
            //divided by 10. Each left/right instruction will move the ship across a tenth of this space.
            int pixelInterval = int((globalWidth - (globalPadding * 2) - m_spaceship->getSpaceshipImage().width()) / 10);

            //The spaceship moves by 5px each update, so to move across a pixel interval within
            //one timestep, divide by 5.
            int timestep = pixelInterval / 5;

            //If the timestep is a factor of the number of updates, read a new instruction
            if ((m_timestepCounter % timestep == 0))
            {
                m_directionsIndex++;
            }

            m_timestepCounter++;
        }

        //USING DEFAULT MOVEMENT - sweeping back and forth
        //If no longer reading instructions, continue default movement
        else
        {
            //MOVE SPACESHIP
            if (m_spaceship->getX() >= xMax)
            {
                m_spaceshipMover *= -1;
            }
            else if (m_spaceship->getX() <= xMin)
            {
                m_spaceshipMover *= -1;
            }
            m_spaceship->moveSpaceshipX(m_spaceshipMover);

            //SHOOT BULLET EVERY 200 PIXELS
            if (m_spaceship->getX() % 200 == 0)
            {
                int bulletX = m_spaceship->getX() + (m_spaceship->getSpaceshipImage().width() / 2) - 10;
                int bulletY = m_spaceship->getY();
                m_bullets.addBullet(bulletX, bulletY);
            }
        }


        //Increment all active bullets if there are any in action
        if (!m_bullets.isEmpty())
        {
            m_bullets.moveAllBullets();
        }


        //Move all the starfields
        m_farStarfield->moveStars();
        m_midStarfield->moveStars();
        m_nearStarfield->moveStars();

        //update the frame
        update();

    }
} //end namespace
