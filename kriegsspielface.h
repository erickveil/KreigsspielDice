#ifndef KRIEGSSPIELFACE_H
#define KRIEGSSPIELFACE_H

#include <QString>

class KriegsspielFace
{
public:
    int LeftRow1;
    int LeftRow2;
    int LeftRow3;
    int LeftRow4;

    int RightRow1;
    int RightRow2;
    int RightRow3;
    int RightRow4;

    int InfantryCasualties;
    int CavalryCasualties;

    QString meleeResults;

    bool isBlack;
    bool isFire;

    KriegsspielFace();
};

#endif // KRIEGSSPIELFACE_H
