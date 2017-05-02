/*
 * universe.h
 * Class header for game universe that is a subclass of QDialog.
 * The universe dialog creates a game configuration objects, a spaceship object, an
 * active bullets object and three starfields that scroll through the background.
 * Every 20msec the frame is refreshed showing the movement of these game elements
 * and background objects. The instructions for movement are within saved to the
 * GameConfiguration object by the IOFile object that also saves the last x coordinate
 * of the spaceship back to the config.ini file in the destructor.
 * Author: Anon
 */

#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "activebullets.h"
#include "gameconfiguration.h"
#include "globaldimensions.h"
#include <QDialog>
#include <QPainter>
#include <QPixmap>
#include "spaceship.h"
#include "starfield.h"

namespace universe { //start namespace

    class Universe : public QDialog
    {

        Q_OBJECT
        GameConfiguration m_config; //Holds the config.ini settings
        Starfield *m_farStarfield;
        Starfield *m_midStarfield;
        Starfield *m_nearStarfield;
        Spaceship *m_spaceship;
        ActiveBullets m_bullets;
        int m_spaceshipMover = 5; //Moves the spaceship by 5px at a time
        int m_timestepCounter = 0; //Keeps track of the number of frames
        int m_directionsIndex = 0; //Keeps track of how many instructions have been read
        bool m_readingInstructions = true; //Instructions are read when this is true

    public:

        /*
         ***** Constructor *****
         * Constructor has a default QWidget value of nullptr
         * @param QWidget
         */
        Universe(QWidget *parent = nullptr);

        /*
         ***** Destructor *****
         * Destructor saves the last x coordinate of the spaceship to config.ini
         * and deletes the spaceship and starfield to free memory
         */
        ~Universe();

    protected:

        /*
         * Paints the graphics in the dialog
         */
        void paintEvent(QPaintEvent *event);

        /*
         * Responds to keys pressed during the game
         */
        void keyPressEvent(QKeyEvent *event);

    public slots:

        /*
         * Alters the coordinates of objects active in the dialog
         * and updates the frame
         */
        void nextFrame();
    };

} //end namspace

#endif // UNIVERSE_H
