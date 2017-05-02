/*
 * activebullets.h
 * Class header for instantiating and moving dynamically allocated bullets
 * Author: Anon
 */

#ifndef ACTIVEBULLETS_H
#define ACTIVEBULLETS_H

#include "bullet.h"
#include <vector>

using namespace std;

class ActiveBullets
{
public:

    /*
     ***** CONSTRUCTOR *****
     */
    ActiveBullets();

    /*
     ***** DESTRUCTOR *****
     * Frees all memory allocated to bullet objects in vector
     * and clears vector
     */
    ~ActiveBullets();

    /*
     * Gets empty status of bullet vector
     * @return bool is true if vector is empty, false if not empty
     */
    bool isEmpty() const;

    /*
     * Gets size of bullet vector
     * @return integer of vector size
     */
    int getSize() const;

    /*
     * Gets a pointer to a bullet object at the given index in the vector
     * @return Pointer to bullet object
     */
    Bullet* getActiveBullet(int index) const;

    /*
     * Creates a new bullet object at x,y in dynamic memory
     * @params integer x and y position of new bullet
     */
    void addBullet(int xPos, int yPos);

    /*
     * Moves all bullets in the vector upwards in the y-axis and frees bullets
     * no longer in view
     */
    void moveAllBullets();

private:
    vector<Bullet*> m_bulletList; //vector of pointers to bullet objects
};

#endif // ACTIVEBULLETS_H
