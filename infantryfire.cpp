#include "infantryfire.h"

InfantryFire::InfantryFire()
{
    _dieI.initAsI();
    _dieII.initAsII();
}

int InfantryFire::attackResult(InfantryFire::InfantryType type, InfantryFire::InfantryRange range, bool isAttackerCover, bool isTargetCover)
{
    switch (type) {
    case INF_TYPE_HALF_BAT:
        return halfBatAttack(range, isTargetCover);
    case INF_TYPE_SKIRMISH:
        return skirmisherAttack(range, isAttackerCover, isTargetCover);
    default:
        return jagerAttack(range, isAttackerCover, isTargetCover);
    }
}

int InfantryFire::halfBatAttack(InfantryFire::InfantryRange range, bool isTargetCover)
{
    KriegsspielFace result = _dieI.roll();
    _lastRef = "Die I; Left Col; Row ";

    int points;
    switch(range) {
    case INF_LONG:
        points = result.LeftRow4;
        _lastRef += "4";
        break;
    case INF_MEDIUM:
        points = result.LeftRow3;
        _lastRef += "3";
        break;
    case INF_SHORT:
        points = result.LeftRow2;
        _lastRef += "2";
        break;
    default:
        points = result.LeftRow1;
        _lastRef += "1";
    }

    if (isTargetCover) {
        points = static_cast<int>( std::round(points / 2) );
        _lastRef += "; damage halved";
    }
    return points;
}

int InfantryFire::skirmisherAttack(InfantryFire::InfantryRange range, bool isAttackerCover, bool isTargetCover)
{
    KriegsspielDie die;
    if (!isAttackerCover) {
        die = _dieI;
        _lastRef = "Die I; Right Col; Row ";
    }
    else {
        die = _dieII;
        _lastRef = "Die II; Right Col; Row ";
    }
    KriegsspielFace result = die.roll();

    int points;

    switch(range) {
    case INF_LONG:
        points = result.RightRow4;
        _lastRef += "4";
        break;
    case INF_MEDIUM:
        points = result.RightRow3;
        _lastRef += "3";
        break;
    case INF_SHORT:
        points = result.RightRow2;
        _lastRef += "2";
        break;
    default:
        points = result.RightRow1;
        _lastRef += "1";
    }

    if (isTargetCover) {
        points = static_cast<int>( std::round(points / 2) );
        _lastRef += "; damage halved";
    }
    return points;
}

int InfantryFire::jagerAttack(InfantryFire::InfantryRange range, bool isAttackerCover, bool isTargetCover)
{
    KriegsspielDie die;
    if (!isAttackerCover) {
        die = _dieI;
        _lastRef = "Die I; Right Col; Row ";
    }
    else {
        die = _dieII;
        _lastRef = "Die II; Left Col; Row ";
    }

    KriegsspielFace result = die.roll();

    int points;

    if (!isAttackerCover) {
        switch(range) {
        case INF_LONG:
            points = result.RightRow4;
            _lastRef += "4";
            break;
        case INF_MEDIUM:
            points = result.RightRow3;
            _lastRef += "3";
            break;
        case INF_SHORT:
            points = result.RightRow2;
            _lastRef += "2";
            break;
        default:
            points = result.RightRow1;
            _lastRef += "1";
        }
    }
    else {
        switch(range) {
        case INF_LONG:
            points = result.LeftRow4;
            _lastRef += "4";
            break;
        case INF_MEDIUM:
            points = result.LeftRow3;
            _lastRef += "3";
            break;
        case INF_SHORT:
            points = result.LeftRow2;
            _lastRef += "2";
            break;
        default:
            points = result.LeftRow1;
            _lastRef += "1";
        }
    }

    if (isTargetCover) {
        points = static_cast<int>( std::round(points / 2) );
        _lastRef += "; damage halved";
    }
    return points;

}

QString InfantryFire::getLastRef()
{
    return _lastRef;

}
