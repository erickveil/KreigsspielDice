/**
 *infantryfire.h
 * Erick Veil
 * Copyright 2019 Erick Veil
 */
#ifndef INFANTRYFIRE_H
#define INFANTRYFIRE_H

#include <cmath>

#include "kriegsspieldie.h"

/**
 * @brief The InfantryFire class
 * Handles resolving infantry fire.
 */
class InfantryFire
{
    /**
     * @brief _dieI Half battallions, skirmishers and jaggers without cover, all
     * use die I.
     */
    KriegsspielDie _dieI;

    /**
     * @brief _dieII Skirmishers and jaggers firing from cover use die II and
     * do more damage.
     */
    KriegsspielDie _dieII;

    /**
     * @brief _lastRef holds the last roll's instructions for performing the
     * roll yourself with actual dice.
     */
    QString _lastRef;

public:
    enum InfantryRange { INF_POINT_BLANK, INF_SHORT, INF_MEDIUM, INF_LONG };
    enum InfantryType { INF_TYPE_HALF_BAT, INF_TYPE_JAGER, INF_TYPE_SKIRMISH};

    /**
     * @brief InfantryFire
     * Initializes the dice.
     */
    InfantryFire();

    /**
     * @brief attackResult
     * Catchall attack roll that references the other infantry attack methods
     * for results
     *
     * @param type
     * @param range
     * @param isAttackerCover
     * @param isTargetCover
     * @return
     */
    int attackResult(InfantryType type, InfantryRange range,
                     bool isAttackerCover, bool isTargetCover);

    /**
     * @brief halfBatAttack
     * The standard half battalion attack
     * Cover doesn't matter for the attacker in this case
     *
     * @param range
     * @param isTargetCover
     * @return
     */
    int halfBatAttack(InfantryRange range, bool isTargetCover);

    /**
     * @brief skirmisherAttack
     * The standard lineman/rifleman skirmisher attack. Two zugs (half
     * battalion).
     *
     * @param range
     * @param isAttackerCover
     * @param isTargetCover
     * @return
     */
    int skirmisherAttack(InfantryRange range, bool isAttackerCover,
                         bool isTargetCover);

    /**
     * @brief jagerAttack
     * Attack roll for jagers/rangers in a skirmish line. Two zugs (half
     * battalion).
     *
     * @param range
     * @param isAttackerCover
     * @param isTargetCover
     * @return
     */
    int jagerAttack(InfantryRange range, bool isAttackerCover,
                    bool isTargetCover);

    /**
     * @brief getLastRef
     * Returns a string that describes which die to roll and where on that die
     * you will find the value that you are looking for. This is useful when
     * training yourself how to use the dice.
     *
     * @return Returns the location of where to look for the correct result
     */
    QString getLastRef();
};

#endif // INFANTRYFIRE_H
