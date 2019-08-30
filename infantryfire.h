#ifndef INFANTRYFIRE_H
#define INFANTRYFIRE_H

#include <cmath>

#include "kriegsspieldie.h"

class InfantryFire
{
    KriegsspielDie _dieI;
    KriegsspielDie _dieII;

    QString _lastRef;

public:
    enum InfantryRange { INF_POINT_BLANK, INF_SHORT, INF_MEDIUM, INF_LONG };
    enum InfantryType { INF_TYPE_HALF_BAT, INF_TYPE_JAGER, INF_TYPE_SKIRMISH};
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
