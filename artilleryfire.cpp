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
    bool isGoodEffect = effect == GOOD_EFFECT;

    RandomTable<int> crt;
    _lastRef = "CRT";

    int basePoints;
    switch (range) {
    case ART_CANISTER:
        crt.addEntry(isGoodEffect? 50 : 31);
        crt.addEntry(isGoodEffect? 50 : 31);
        crt.addEntry(isGoodEffect? 25 : 37);
        crt.addEntry(isGoodEffect? 38 : 25);
        crt.addEntry(isGoodEffect? 25 : 15);
        crt.addEntry(isGoodEffect? 71 : 15);
        break;
    case ART_LOW:
        crt.addEntry(isGoodEffect? 31 : 20);
        crt.addEntry(isGoodEffect? 31 : 20);
        crt.addEntry(isGoodEffect? 13 : 25);
        crt.addEntry(isGoodEffect? 25 : 18);
        crt.addEntry(isGoodEffect? 19 : 10);
        crt.addEntry(isGoodEffect? 50 : 10);
        break;
    case ART_HIGH:
        crt.addEntry(isGoodEffect? 13 : 7);
        crt.addEntry(isGoodEffect? 13 : 7);
        crt.addEntry(isGoodEffect? 8 : 10);
        crt.addEntry(isGoodEffect? 10 : 6);
        crt.addEntry(isGoodEffect? 8 : 5);
        crt.addEntry(isGoodEffect? 22 : 5);
        break;
    default:
        crt.addEntry(isGoodEffect? 9 : 3);
        crt.addEntry(isGoodEffect? 9 : 3);
        crt.addEntry(isGoodEffect? 6 : 5);
        crt.addEntry(isGoodEffect? 8 : 2);
        crt.addEntry(isGoodEffect? 6 : 1);
        crt.addEntry(isGoodEffect? 12 : 1);
    }

    basePoints = crt.getRollTableEntry();

    int modifiedPoints = basePoints;
    int pointsMod = 0;
    if (factors.TwoCol) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }
    if (factors.DeepCover) {
        _lastRef = "No losses when cover is 200 paces wide.";
        return 0;
    }
    if (factors.Grenade) {
        _lastRef += "Grenades form howitzers only.";
        return 0;
    }
    if (factors.Flanking) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }
    if (factors.HasCover) {
        modifiedPoints = static_cast<int>(std::round(basePoints * 0.5));
        _lastRef += "; Half damage";
    }
    if (factors.TwoLines) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }
    if (factors.Skirmishers) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }

    return modifiedPoints + pointsMod;
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
    _lastRef += " Left Col; Row ";

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

    int modifiedPoints = basePoints;
    int pointsMod = 0;
    if (factors.TwoCol) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }
    if (factors.DeepCover) {
        _lastRef = "No losses when cover is 200 paces wide.";
        return 0;
    }
    if (factors.Grenade) {
        _lastRef += "Grenades form howitzers only.";
        return 0;
    }
    if (factors.Flanking) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }
    if (factors.HasCover) {
        modifiedPoints = static_cast<int>(std::round(basePoints * 0.5));
        _lastRef += "; Half damage";
    }
    if (factors.TwoLines) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }
    if (factors.Skirmishers) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }

    return modifiedPoints + pointsMod;
}

int ArtilleryFire::fireSevenLb(ArtilleryFire::ArtilleryRange range,
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
    _lastRef += " Right Col; Row ";

    int basePoints;
    switch (range) {
    case ART_CANISTER:
        basePoints = result.RightRow1;
        _lastRef += "1";
        break;
    case ART_LOW:
        basePoints = result.RightRow2;
        _lastRef += "2";
        break;
    case ART_HIGH:
        basePoints = result.RightRow3;
        _lastRef += "3";
        break;
    default:
        basePoints = result.RightRow4;
        _lastRef += "4";
    }

    int modifiedPoints = basePoints;
    int pointsMod = 0;
    if (factors.TwoCol) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }
    if (factors.DeepCover) {
        modifiedPoints = static_cast<int>(std::round(basePoints / 3));
        _lastRef += "; 1/3 damage";
    }
    if (factors.Grenade) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.33));
        _lastRef += "; +33%";
    }
    if (factors.Flanking) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }
    if (factors.HasCover) {
        modifiedPoints = static_cast<int>(std::round(basePoints * 0.5));
        _lastRef += "; Half damage";
    }
    if (factors.TwoLines) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }
    if (factors.Skirmishers) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }

    return modifiedPoints + pointsMod;

}

int ArtilleryFire::fireTenLb(ArtilleryFire::ArtilleryRange range,
                             ArtilleryFire::Effect effect,
                             TargetFactors factors)
{
    bool isGoodEffect = effect == GOOD_EFFECT;

    RandomTable<int> crt;
    _lastRef = "CRT";

    int basePoints;
    switch (range) {
    case ART_CANISTER:
        crt.addEntry(isGoodEffect? 9 : 6);
        crt.addEntry(isGoodEffect? 10 : 6);
        crt.addEntry(isGoodEffect? 5 : 8);
        crt.addEntry(isGoodEffect? 6 : 5);
        crt.addEntry(isGoodEffect? 5 : 2);
        crt.addEntry(isGoodEffect? 13 : 2);
        break;
    case ART_LOW:
        crt.addEntry(isGoodEffect? 6 : 4);
        crt.addEntry(isGoodEffect? 7 : 5);
        crt.addEntry(isGoodEffect? 4 : 5);
        crt.addEntry(isGoodEffect? 5 : 2);
        crt.addEntry(isGoodEffect? 4 : 2);
        crt.addEntry(isGoodEffect? 9 : 1);
        break;
    case ART_HIGH:
        crt.addEntry(isGoodEffect? 4 : 2);
        crt.addEntry(isGoodEffect? 5 : 3);
        crt.addEntry(isGoodEffect? 2 : 3);
        crt.addEntry(isGoodEffect? 3 : 2);
        crt.addEntry(isGoodEffect? 2 : 1);
        crt.addEntry(isGoodEffect? 5 : 2);
        break;
    default:
        crt.addEntry(isGoodEffect? 3 : 1);
        crt.addEntry(isGoodEffect? 2 : 1);
        crt.addEntry(isGoodEffect? 1 : 2);
        crt.addEntry(isGoodEffect? 2 : 1);
        crt.addEntry(isGoodEffect? 1 : 0);
        crt.addEntry(isGoodEffect? 4 : 0);
    }

    basePoints = crt.getRollTableEntry();

    int modifiedPoints = basePoints;
    int pointsMod = 0;
    if (factors.TwoCol) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }
    if (factors.DeepCover) {
        modifiedPoints = static_cast<int>(std::round(basePoints / 3));
        _lastRef += "; 1/3 damage";
    }
    if (factors.Grenade) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.33));
        _lastRef += "; +33%";
    }
    if (factors.Flanking) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }
    if (factors.HasCover) {
        modifiedPoints = static_cast<int>(std::round(basePoints * 0.5));
        _lastRef += "; Half damage";
    }
    if (factors.TwoLines) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }
    if (factors.Skirmishers) {
        pointsMod += static_cast<int>(std::round(basePoints * 0.25));
        _lastRef += "; +25%";
    }

    return modifiedPoints + pointsMod;
}

QString ArtilleryFire::getLastRef()
{
    return _lastRef;
}
