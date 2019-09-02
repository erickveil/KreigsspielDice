/**
 * kriegsspieldie.h
 * Erick Veil
 * 2019-09-02
 * Copyright 2019 Erick Veil
 */
#ifndef KRIEGSSPIELDIE_H
#define KRIEGSSPIELDIE_H

#include <QString>

#include "randomtable.h"
#include "kriegsspielface.h"

/**
 * @brief The KriegsspielDie class
 * A die is a table of KriegspielFace objects.
 * The die can be rolled, and the result obtained from the resulting face.
 * Each die has six faces.
 * The dice are each defined by their number (I - V) and thier odds. The odds
 * are used in hand-to-hand combat when comparing the number of attackers v
 * defenders.
 *
 * The die must be initialized before use.
 * There are 5 inititializers, one for each die.
 */
class KriegsspielDie
{
    int _dieNumber;
    QString _odds;
    KriegsspielFace _faceList[6];
    RandomTable<KriegsspielFace> _dieTable;

public:

    /**
     * @brief KriegsspielDie
     * The constructor only creates the object. It does not initialize the die.
     */
    KriegsspielDie();

    /**
     * @brief initAsI
     */
    void initAsI();

    /**
     * @brief initAsII
     */
    void initAsII();

    /**
     * @brief initAsIII
     */
    void initAsIII();

    /**
     * @brief initAsIV
     */
    void initAsIV();

    /**
     * @brief initAsV
     */
    void initAsV();

    /**
     * @brief roll
     * @return The result of the roll.
     */
    KriegsspielFace roll();

private:
    void _initTable();
};

#endif // KRIEGSSPIELDIE_H
