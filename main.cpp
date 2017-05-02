/*
 * main.cpp
 * Main runs the program by creating a Universe object and
 * showing it
 * Author: Anon
 */

#include "dialog.h"
#include "universe.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Creates a new Universe object
    universe::Universe w;

    //Starts the Universe dialog
    w.show();

    return a.exec();
}
