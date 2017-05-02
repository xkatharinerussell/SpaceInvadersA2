/*
 * gameconfiguration.cpp
 * Class implementation for setting and getting the game
 * configuration settings from the config.ini file including the
 * starting x position, size and directions of the spaceship
 * Author: Anon
 */

#include "gameconfiguration.h"
#include <iostream>
#include <string>

using namespace std;

//CONSTRUCTOR
GameConfiguration::GameConfiguration()
{

}

//DESCTRUCTOR
GameConfiguration::~GameConfiguration()
{

}

//Gets the spaceship size as specified in config.ini
string GameConfiguration::getSpaceshipSize() const
{
    return m_spaceshipSize;
}

//Gets the starting x position spaceship as specified in config.ini
int GameConfiguration::getStartingXPos() const
{
    return m_startingXPos;
}

//Gets the vector of directions for the spaceship as specified in config.ini
vector<string> GameConfiguration::getDirections() const
{
    return m_directions;
}

//Sets the spaceship size as specified in config.ini
void GameConfiguration::setSpaceshipSize(string size)
{
    m_spaceshipSize = size;
}

//Sets the starting x position spaceship as specified in config.ini
void GameConfiguration::setStartingXPos(int xPos)
{
    m_startingXPos = xPos;
}

//Sets the vector of directions for the spaceship as specified in config.ini
void GameConfiguration::setDirections(vector<string> &directions)
{
    //Copies all the direction strings from the referenced string vector to
    //the config string vector
    for (int i = 0; i < directions.size(); i++)
    {
        m_directions.push_back(directions[i]);
    }
}
