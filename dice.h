/**
 * dice.h
 * Erick Veil
 * 2019-09-02
 * Copyright 2019 Erick Veil
 */
#ifndef DICE_H
#define DICE_H


#include <QtGlobal>
#include <QDateTime>

/**
 * @brief The Dice class
 * This class allow selecting random numbers based on rolling dice.
 * Multiple dice can be rolled, preserving any probability bell curve in the
 * recults.
 */
class Dice
{
public:

    /**
     * @brief Dice
     */
    Dice();

    /**
     * @brief randomNumber
     * @param min
     * @param max
     * @return A single random number between min and max.
     */
    static int randomNumber(int min, int max);

    /**
     * @brief roll
     * @param number Number of dice to roll
     * @param sides Number of sides on each die
     * @param mod Added to the final roll total.
     * @return result of one or more dice
     */
    static int roll(int number, int sides, int mod = 0);

};

#endif // DICE_H
