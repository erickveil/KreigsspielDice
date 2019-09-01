#ifndef ARTILLERYFIRE_H
#define ARTILLERYFIRE_H

#include <cmath>

#include <QDebug>

#include "kriegsspieldie.h"
#include "targetfactors.h"

/**
 * @brief The ArtilleryFire class
 * 12 lb battery g(9, 13, 31, 50) - b(3, 7, 20, 31) - appears tp be table only?
 * 6 lb battery g(7, 10, 25, 40) Die 3, left col - b(3, 6, 16, 25) Die 5, left col
 * 7 lb howitzer g(10, 12, 20, 30) Die 3, right col - b(3, 8, 12, 20) Die 5, right col
 * two 10 lb Howitzers g(3, 4, 6, 9) - b(1, 2, 4, 6) - appears to be table only?
 */
class ArtilleryFire
{
    KriegsspielDie _dieIII;
    KriegsspielDie _dieV;
    QString _lastRef;

public:
    enum ArtilleryRange { ART_CANISTER, ART_LOW, ART_HIGH, ART_RICOCHET };
    enum ArtilleryType { ART_TYPE_12, ART_TYPE_6, ART_TYPE_7, ART_TYPE_10 };
    enum Effect { GOOD_EFFECT, BAD_EFFECT };
    ArtilleryFire();

    int attackResult(ArtilleryType type, ArtilleryRange range, Effect effect,
                     TargetFactors factors);

    int fireTwelveLb(ArtilleryRange range, Effect effect,
                     TargetFactors factors);

    int fireSixLb(ArtilleryRange range, Effect effect, TargetFactors factors);

    int fireSevenLb(ArtilleryRange range, Effect effect, TargetFactors factors);

    int fireTenLb(ArtilleryRange range, Effect effect, TargetFactors factors);

    QString getLastRef();
};

#endif // ARTILLERYFIRE_H
