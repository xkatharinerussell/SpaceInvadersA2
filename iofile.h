/*
 * iofile.h
 * Class header for reading input and writing
 * output to the config.ini file with the Game Configuration settings.
 * The config.ini file is presumed to have the following format:
 *
 ***** config.ini *****
 * [Spaceship]
 * Size:<string value of "tiny"/"normal"/"large"/"giant">
 * xPos:<integer value>
 * <empty line>
 * [Directions]
 * <string value of "left"/"right"/"shoot">
 * <string value of "left"/"right"/"shoot">
 * <string value of "left"/"right"/"shoot">
 * ...
 * ...
 * ...
 * <string value of "left"/"right"/"shoot">
 ***** /config.ini *****
 *
 * Author: Anon
 */

#ifndef IOFILE_H
#define IOFILE_H

#include "gameconfiguration.h"
#include <iostream>
#include <QFile>
#include <string>

class IOFile
{
public:

    /*
     ***** CONSTRUCTOR *****
     * @param reference to a Game Configuration object to hold the values
     * of size, starting x position and list of directions from the config.ini
     * file
     */
    IOFile(GameConfiguration &config);

    /*
     ***** DESTRUCTOR *****
     */
    ~IOFile();

    /*
     * Opens the config.ini file and reads each line to add to the Game Configuration
     * object and then closes the file
     */
    void readFile();

    /*
     * Opens the config.ini file and creates a temp file to copy all the lines from
     * original config.ini file except for the xPos:<value> line which is updated to
     * reflect the last state of the game before exiting. The config.ini file is then removed
     * and the temp file is renamed to become the new config.ini
     * @param integer value of last x position of spaceship
     */
    void writeFile(int xPosition);

private:
        GameConfiguration &m_config; //reference to GameConfiguration object

};

#endif // IOFILE_H
