/*
 * gameconfiguration.h
 * Class header for setting and getting the game
 * configuration settings from the config.ini file including the
 * starting x position, size and directions of the spaceship
 * Author: Anon
 */

#ifndef GAMECONFIGURATION_H
#define GAMECONFIGURATION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class GameConfiguration
{
public:

    /*
     ***** CONSTRUCTOR *****
     */
    GameConfiguration();

    /*
     ***** DESTRUCTOR *****
     */
    ~GameConfiguration();

    /*
     * Gets the spaceship size as specified in config.ini
     * @return string of size as "tiny", "normal", "large", "giant"
     */
    string getSpaceshipSize() const;

    /*
     * Gets the starting x position spaceship as specified in config.ini
     * @return integer of spaceship starting x coordinate
     */
    int getStartingXPos() const;

    /*
     * Gets the vector of directions for the spaceship as specified in config.ini
     * @return vector of strings containing directions
     */
    vector<string> getDirections() const;

    /*
     * Sets the spaceship size as specified in config.ini
     * @param string of size as "tiny", "normal", "large", "giant"
     */
    void setSpaceshipSize(string size);

    /*
     * Sets the starting x position spaceship as specified in config.ini
     * @param integer of spaceship starting x coordinate
     */
    void setStartingXPos(int xPos);

    /*
     * Sets the vector of directions for the spaceship as specified in config.ini
     * @param reference to vector of strings containing directions
     */
    void setDirections(vector<string> &directions);

private:
    string m_spaceshipSize; //spaceship size
    int m_startingXPos; //spaceship starting x coordinate
    vector<string> m_directions; //vector of directions as strings
};

#endif // GAMECONFIGURATION_H
