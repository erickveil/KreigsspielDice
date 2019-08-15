#ifndef KRIEGSSPIELDIE_H
#define KRIEGSSPIELDIE_H

#include <QString>

#include "randomtable.h"
#include "kriegsspielface.h"

class KriegsspielDie
{
    int _dieNumber;
    QString _odds;
    KriegsspielFace _faceList[6];
    RandomTable<KriegsspielFace> _dieTable;

public:

    KriegsspielDie();

    void initAsI();
    void initAsII();
    void initAsIII();
    void initAsIV();
    void initAsV();

    KriegsspielFace roll();

private:
    void _initTable();
};

#endif // KRIEGSSPIELDIE_H
