/*
 * iofile.cpp
 * Class implementation for reading input and writing
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
 */

#include "gameconfiguration.h"
#include "iofile.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <string>

using namespace std;

//Constructor takes a reference to a GameConfiguration object and
//stores it as a local variable
IOFile::IOFile(GameConfiguration &config) : m_config(config)
{

}

//Destructor
IOFile::~IOFile()
{

}

//Opens the config.ini file and reads each line to add to the Game Configuration
//object and then closes the file
void IOFile::readFile()
{
    //Flags to indicate whether all vital information correctly collected from
    //the configuration file
    bool xPosFound = false;
    bool sizeFound = false;


    //Open the configuration file
    QFile file("/Users/katharinerussell/Documents/github/SpaceInvadersA2/configuration/config.ini");

    //Create a string vector to hold spaceship directions
    vector<string> directions;

    //Create a string vector to hold alien movement directions
    vector<string> alienDirect;

    //Check the file exists and is read/writable, if not close QFile and exit with failure
    if (!file.open(QIODevice::ReadWrite))
    {
        cout << "Failed to open configuration file:" << file.fileName().toStdString() << endl;
        cout << "Exit program" << endl;
        file.close();
        exit(EXIT_FAILURE);
    }

    QTextStream in(&file); //File as a text stream to read as input


    //Read each line in the config.ini file
    while (!in.atEnd())
    {
        QString line = in.readLine(); //Read a line as a string

        //When a header eg [<header>] is found, continue to distinguish which header
        if(line.toStdString().find("[") != string::npos && line.toStdString().find("]") != string::npos)
        {

            //The Spaceship header ie [Spaceship]
            if (line.toStdString().find("[Spaceship]") != string::npos)
            {

                //Loop over the values under Spaceship header
                while(!in.atEnd())
                {

                    line = in.readLine();//Read a line as a string

                    //If line contains a ":" delimiter it is a (key, value) pair ie Key:value
                    if (line.toStdString().find(":") != string::npos)
                    {

                        //Split the line by the delimiter ":"
                        QStringList keyValue = line.split(":");

                        //If the key is "Size", the value is saved in the config file
                        //as the Spaceship size
                        if (keyValue.value(0).compare("Size") == 0)
                        {
                            m_config.setSpaceshipSize(keyValue.value(1).toStdString());
                            sizeFound = true;
                            continue;
                        }

                        //If the key is "xPos", the value is saved in the config file
                        //as X position of the Spaceship
                        else if (keyValue.value(0).compare("xPos") == 0)
                        {
                            m_config.setStartingXPos(keyValue.value(1).toInt());
                            xPosFound = true;
                            continue;
                        }

                        //If there is a ":" with a different key, there is a format error
                        else
                        {
                            cout << "Configuration file contains format error:" << file.fileName().toStdString() << endl;
                            cout << "Exit program" << endl;
                            file.close();
                            exit(EXIT_FAILURE);
                        }
                    }

                    //If it is an empty line, it indicates the end of the value set
                    else if (line.toStdString().empty())
                    {
                        break;
                    }

                    //If the line contains anything else, there is a format error
                    else
                    {
                        cout << "Configuration file contains format error:" << file.fileName().toStdString() << endl;
                        cout << "Exit program" << endl;
                        file.close();
                        exit(EXIT_FAILURE);
                    }
                }

            }

            //The Directions header ie [Directions]
            else if (line.toStdString().find("[Directions]") != string::npos)
            {

                while(!in.atEnd())
                {

                    line = in.readLine(); //Read a line as a string

                    //If the line is valid direction ie left, right, shoot
                    //add it to the list of directions
                    if (line.toStdString().find("left") != string::npos
                            || line.toStdString().find("right") != string::npos
                            || line.toStdString().find("shoot") != string::npos)
                    {
                        directions.push_back(line.toStdString());
                    }

                    //If it is an empty line, continue to find more directions
                    else if (line.toStdString().empty())
                    {
                        continue;
                    }

                    //If the line is not a valid direction, there is a format error
                    else
                    {
                        cout << "Configuration file contains format error:" << file.fileName().toStdString() << endl;
                        cout << "Exit program" << endl;
                        file.close();
                        exit(EXIT_FAILURE);
                    }
                }
            }

            //If other headers exist not in the above format ie [spaceship]
            //the config file has a formatting error
            else
            {
                cout << "line4: " << line.toStdString() << endl;
                cout << "Configuration file contains format error:" << file.fileName().toStdString() << endl;
                cout << "Exit program" << endl;
                file.close();
                exit(EXIT_FAILURE);
            }
        }

    }

    //If all values have been successfully collected, save the directions and close the file
    if (xPosFound && sizeFound)
    {
        //Save the directions string vector to the config object
        m_config.setDirections(directions);

        //Close the file
        file.close();
    }

    //If any of the values haven't been successfully collected, config file has a formatting error
    else
    {
        cout << "Configuration file contains format error:" << file.fileName().toStdString() << endl;
        cout << "Exit program" << endl;
        file.close();
        exit(EXIT_FAILURE);
    }

}

//Opens the config.ini file and creates a temp file to copy all the lines from
//original config.ini file except for the xPos:<value> line which is updated to
//reflect the last state of the game before exiting. The config.ini file is then removed
//and the temp file is renamed to become the new config.ini
void IOFile::writeFile(int xPosition)
{

    //Strings that hold the file name which are relative to the makefile in the release build
    QString configName = "/Users/katharinerussell/Documents/github/SpaceInvadersA2/configuration/config.ini";
    QString tempName = "/Users/katharinerussell/Documents/github/SpaceInvadersA2/configuration/temp.ini";

    //Open the configuration file
    QFile file(configName);

    //Create and open the temp file
    QFile temp(tempName);

    //Check the read file and temp file exists and are read/writable, if not close the files and exit with failure
    if (!file.open(QIODevice::ReadWrite) || !temp.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        cout << "Failed to open configuration or temp file:" << file.fileName().toStdString() << endl;
        cout << "Exit program without saving" << endl;
        file.close();
        temp.close();
        exit(EXIT_FAILURE);
    }

    QTextStream read(&file); //Config file as a text stream to read input
    QTextStream write(&temp); //Temp file as a text stream to save output

    //Read each line in the config.ini file and write it to the temp.ini file
    while(!read.atEnd())
    {
        QString line = read.readLine(); //Read a line as a string

        //If line contains the "xPos:___" (key, value) pair, create a new line with give x position
        if (line.toStdString().find("xPos:") != string::npos)
        {
            write << "xPos:" << xPosition << endl;
        }

        //Otherwise copy each line without modification from the config.ini
        else
        {
            write << line << endl;
        }
    }

    file.remove(); //remove original config.ini
    file.close();
    temp.rename("/Users/katharinerussell/Documents/github/SpaceInvadersA2/configuration/config.ini"); //rename temp.ini as config.ini
    temp.close();
}
