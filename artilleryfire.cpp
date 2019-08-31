#include "artilleryfire.h"

ArtilleryFire::ArtilleryFire()
{
    _dieIII.initAsIII();
    _dieV.initAsV();
}

int ArtilleryFire::attackResult(ArtilleryFire::ArtilleryType type,
                                ArtilleryFire::ArtilleryRange range,
                                ArtilleryFire::Effect effect,
                                TargetFactors factors)
{
    switch (type) {
    case ART_TYPE_6:
        return fireSixLb(range, effect, factors);
    case ART_TYPE_7:
        return fireSevenLb(range, effect, factors);
    case ART_TYPE_10:
        return fireTenLb(range, effect, factors);
    default:
        return fireTwelveLb(range, effect, factors);
    }

}

int ArtilleryFire::fireTwelveLb(ArtilleryFire::ArtilleryRange range,
                                ArtilleryFire::Effect effect,
                                TargetFactors factors)
{



}

int ArtilleryFire::fireSixLb(ArtilleryFire::ArtilleryRange range,
                             ArtilleryFire::Effect effect,
                             TargetFactors factors)
{
    bool isGoodEffect = effect == GOOD_EFFECT;
    KriegsspielDie die;
    if (isGoodEffect) {
        die = _dieIII;
        _lastRef = "Die III;";
    }
    else {
        die = _dieV;
        _lastRef = "Die V;";
    }

    KriegsspielFace result = die.roll();
    _lastRef += "; Left Col; Row ";

    int basePoints;
    switch (range) {
    case ART_CANISTER:
        basePoints = result.LeftRow1;
        _lastRef += "1";
        break;
    case ART_LOW:
        basePoints = result.LeftRow2;
        _lastRef += "2";
        break;
    case ART_HIGH:
        basePoints = result.LeftRow3;
        _lastRef += "3";
        break;
    default:
        basePoints = result.LeftRow4;
        _lastRef += "4";
    }

    // This is infantry woods, villages, town walls
    // Also read next para, p. 35:
    // No damage: 200 paces wood, villages, towns
    // 1/3 damage: If howitzer fire at those ranges
    // Check cover and range to determine
    int modifiedPoints = 0;
    if (factors.TwoCol) {
        modifiedPoints = basePoints + static_cast<int>(std::round(basePoints * 0.25));

    }
    if (factors.Grenade) {
        modifiedPoints = basePoints + static_cast<int>(std::round(basePoints * 0.33));

    }
    if (factors.Flanking) {
        modifiedPoints = basePoints + static_cast<int>(std::round(basePoints * 0.25));

    }
    if (factors.HasCover) {
        modifiedPoints = basePoints + static_cast<int>(std::round(basePoints * 0.25));

    }
    if (factors.TwoLines) {
        modifiedPoints = basePoints + static_cast<int>(std::round(basePoints * 0.25));

    }
    if (factors.Skirmishers) {
        modifiedPoints = basePoints + static_cast<int>(std::round(basePoints * 0.25));

    }

    return modifiedPoints;
}

int ArtilleryFire::fireSevenLb(ArtilleryFire::ArtilleryRange range,
                               ArtilleryFire::Effect effect,
                               TargetFactors factors)
{

}

int ArtilleryFire::fireTenLb(ArtilleryFire::ArtilleryRange range,
                             ArtilleryFire::Effect effect,
                             TargetFactors factors)
{

}
