/**
 * artilleryfire.h
 * Erick Veil
 * 2019-09-02
 * Copyright 2019 Erick Veil
 */
#ifndef ARTILLERYFIRE_H
#define ARTILLERYFIRE_H

#include <cmath>

#include <QDebug>

#include "kriegsspieldie.h"
#include "targetfactors.h"

/**
 * @brief The ArtilleryFire class
 *
 * This class handles artillery fire results.
 *
 * On factors:
 * Note that the rules lists a variety of factors that add X% to the damage
 * dealt. While it would be uncommon for multiple factors to be in place, it
 * is not impossible.
 * It is not defined wheather the percentages compound like interest, nor in
 * what order they would if they did. (Indeed, discrepencies between dice
 * results and table results suggest that the actual results are subjective
 * anyway.)
 * The method I use, is to apply the percent to the principal only, in every
 * instance,then add on the results, so that the values do not compound, and
 * the order of determination does not matter.
 *
 * Notes:
 * 12 lb battery g(9, 13, 31, 50) - b(3, 7, 20, 31) - appears tp be table only?
 * 6 lb battery g(7, 10, 25, 40) Die 3, left col - b(3, 6, 16, 25) Die 5, left col
 * 7 lb howitzer g(10, 12, 20, 30) Die 3, right col - b(3, 8, 12, 20) Die 5, right col
 * two 10 lb Howitzers g(3, 4, 6, 9) - b(1, 2, 4, 6) - appears to be table only?
 */
class ArtilleryFire
{
    /**
     * @brief _dieIII "Good Effect" (clear shots) attacks are rolled on die III.
     */
    KriegsspielDie _dieIII;
    /**
     * @brief _dieV "Bad Effect" attacks are rolled on die V.
     */
    KriegsspielDie _dieV;

    /**
     * @brief _lastRef Holds the instructions of the last roll if it is desired
     * to manually roll on actual dice.
     */
    QString _lastRef;

public:
    enum ArtilleryRange { ART_CANISTER, ART_LOW, ART_HIGH, ART_RICOCHET };
    enum ArtilleryType { ART_TYPE_12, ART_TYPE_6, ART_TYPE_7, ART_TYPE_10 };
    enum Effect { GOOD_EFFECT, BAD_EFFECT };

    ArtilleryFire();

    /**
     * @brief attackResult
     * This is a good entry point for rolling. It will determine which of the
     * other methods to use, based on the artillery type.
     * @param type
     * @param range
     * @param effect
     * @param factors
     * @return
     */
    int attackResult(ArtilleryType type, ArtilleryRange range, Effect effect,
                     TargetFactors factors);

    /**
     * @brief fireTwelveLb
     * @param range
     * @param effect
     * @param factors
     * @return
     */
    int fireTwelveLb(ArtilleryRange range, Effect effect,
                     TargetFactors factors);

    /**
     * @brief fireSixLb
     * @param range
     * @param effect
     * @param factors
     * @return
     */
    int fireSixLb(ArtilleryRange range, Effect effect, TargetFactors factors);

    /**
     * @brief fireSevenLb
     * @param range
     * @param effect
     * @param factors
     * @return
     */
    int fireSevenLb(ArtilleryRange range, Effect effect, TargetFactors factors);

    /**
     * @brief fireTenLb
     * @param range
     * @param effect
     * @param factors
     * @return
     */
    int fireTenLb(ArtilleryRange range, Effect effect, TargetFactors factors);

    /**
     * @brief getLastRef
     * @return A string that lists instructions for rolling this result on
     * actual dicebased on all the factors.
     */
    QString getLastRef();
};

#endif // ARTILLERYFIRE_H
