#include "kriegsspieldie.h"

KriegsspielDie::KriegsspielDie()
{

}

void KriegsspielDie::initAsI()
{
    _odds = "1:1";
    _dieNumber = 1;

    // face 1

    _faceList[0].LeftRow1 = 30;
    _faceList[0].LeftRow2 = 20;
    _faceList[0].LeftRow3 = 10;
    _faceList[0].LeftRow4 = 4;

    _faceList[0].RightRow1 = 25;
    _faceList[0].RightRow2 = 15;
    _faceList[0].RightRow3 = 8;
    _faceList[0].RightRow4 = 2;

    _faceList[0].InfantryCasualties = 25;
    _faceList[0].CavalryCasualties = 10;

    _faceList[0].meleeResults = "Defeated";
    _faceList[0].isBlack = true;
    _faceList[0].isFire = true;

    // face 2

    _faceList[1].LeftRow1 = 30;
    _faceList[1].LeftRow2 = 20;
    _faceList[1].LeftRow3 = 10;
    _faceList[1].LeftRow4 = 4;

    _faceList[1].RightRow1 = 25;
    _faceList[1].RightRow2 = 15;
    _faceList[1].RightRow3 = 8;
    _faceList[1].RightRow4 = 2;

    _faceList[1].InfantryCasualties = 30;
    _faceList[1].CavalryCasualties = 12;

    _faceList[1].meleeResults = "Totaly Defeated";
    _faceList[1].isBlack = true;
    _faceList[1].isFire = false;

    // face 3

    _faceList[2].LeftRow1 = 15;
    _faceList[2].LeftRow2 = 10;
    _faceList[2].LeftRow3 = 4;
    _faceList[2].LeftRow4 = 2;

    _faceList[2].RightRow1 = 10;
    _faceList[2].RightRow2 = 6;
    _faceList[2].RightRow3 = 2;
    _faceList[2].RightRow4 = 1;

    _faceList[2].InfantryCasualties = 18;
    _faceList[2].CavalryCasualties = 6;

    _faceList[2].meleeResults = "Routed";
    _faceList[2].isBlack = true;
    _faceList[2].isFire = false;

    // face 4

    _faceList[3].LeftRow1 = 40;
    _faceList[3].LeftRow2 = 25;
    _faceList[3].LeftRow3 = 12;
    _faceList[3].LeftRow4 = 6;

    _faceList[3].RightRow1 = 30;
    _faceList[3].RightRow2 = 17;
    _faceList[3].RightRow3 = 8;
    _faceList[3].RightRow4 = 4;

    _faceList[3].InfantryCasualties = 25;
    _faceList[3].CavalryCasualties = 10;

    _faceList[3].meleeResults = "Defeated";
    _faceList[3].isBlack = false;
    _faceList[3].isFire = false;

    // face 5

    _faceList[4].LeftRow1 = 60;
    _faceList[4].LeftRow2 = 50;
    _faceList[4].LeftRow3 = 25;
    _faceList[4].LeftRow4 = 12;

    _faceList[4].RightRow1 = 50;
    _faceList[4].RightRow2 = 34;
    _faceList[4].RightRow3 = 16;
    _faceList[4].RightRow4 = 8;

    _faceList[4].InfantryCasualties = 30;
    _faceList[4].CavalryCasualties = 12;

    _faceList[4].meleeResults = "Totaly Defeated";
    _faceList[4].isBlack = false;
    _faceList[4].isFire = false;

    // face 6

    _faceList[5].LeftRow1 = 10;
    _faceList[5].LeftRow2 = 6;
    _faceList[5].LeftRow3 = 3;
    _faceList[5].LeftRow4 = 3;

    _faceList[5].RightRow1 = 7;
    _faceList[5].RightRow2 = 4;
    _faceList[5].RightRow3 = 2;
    _faceList[5].RightRow4 = 2;

    _faceList[5].InfantryCasualties = 18;
    _faceList[5].CavalryCasualties = 6;

    _faceList[5].meleeResults = "Routed";
    _faceList[5].isBlack = false;
    _faceList[5].isFire = false;

    _initTable();

}

void KriegsspielDie::initAsII()
{
    _odds = "3:2";
    _dieNumber = 2;

    // face 1

    _faceList[0].LeftRow1 = 20;
    _faceList[0].LeftRow2 = 10;
    _faceList[0].LeftRow3 = 5;
    _faceList[0].LeftRow4 = 3;

    _faceList[0].RightRow1 = 25;
    _faceList[0].RightRow2 = 5;
    _faceList[0].RightRow3 = 3;
    _faceList[0].RightRow4 = 1;

    _faceList[0].InfantryCasualties = -1;
    _faceList[0].CavalryCasualties = -1;

    _faceList[0].meleeResults = "reroll";
    _faceList[0].isBlack = false;
    _faceList[0].isFire = false;

    // face 2

    _faceList[1].LeftRow1 = 20;
    _faceList[1].LeftRow2 = 10;
    _faceList[1].LeftRow3 = 5;
    _faceList[1].LeftRow4 = 3;

    _faceList[1].RightRow1 = 25;
    _faceList[1].RightRow2 = 5;
    _faceList[1].RightRow3 = 3;
    _faceList[1].RightRow4 = 1;

    _faceList[1].InfantryCasualties = 18;
    _faceList[1].CavalryCasualties = 6;

    _faceList[1].meleeResults = "Routed";
    _faceList[1].isBlack = true;
    _faceList[1].isFire = true;

    // face 3

    _faceList[2].LeftRow1 = 40;
    _faceList[2].LeftRow2 = 25;
    _faceList[2].LeftRow3 = 15;
    _faceList[2].LeftRow4 = 8;

    _faceList[2].RightRow1 = 30;
    _faceList[2].RightRow2 = 20;
    _faceList[2].RightRow3 = 10;
    _faceList[2].RightRow4 = 6;

    _faceList[2].InfantryCasualties = 18;
    _faceList[2].CavalryCasualties = 6;

    _faceList[2].meleeResults = "Routed";
    _faceList[2].isBlack = true;
    _faceList[2].isFire = true;

    // face 4

    _faceList[3].LeftRow1 = 40;
    _faceList[3].LeftRow2 = 25;
    _faceList[3].LeftRow3 = 15;
    _faceList[3].LeftRow4 = 8;

    _faceList[3].RightRow1 = 30;
    _faceList[3].RightRow2 = 20;
    _faceList[3].RightRow3 = 10;
    _faceList[3].RightRow4 = 6;

    _faceList[3].InfantryCasualties = 25;
    _faceList[3].CavalryCasualties = 10;

    _faceList[3].meleeResults = "Defeated";
    _faceList[3].isBlack = false;
    _faceList[3].isFire = false;

    // face 5

    _faceList[4].LeftRow1 = 60;
    _faceList[4].LeftRow2 = 40;
    _faceList[4].LeftRow3 = 25;
    _faceList[4].LeftRow4 = 12;

    _faceList[4].RightRow1 = 50;
    _faceList[4].RightRow2 = 30;
    _faceList[4].RightRow3 = 20;
    _faceList[4].RightRow4 = 10;

    _faceList[4].InfantryCasualties = 30;
    _faceList[4].CavalryCasualties = 12;

    _faceList[4].meleeResults = "Totaly Defeated";
    _faceList[4].isBlack = false;
    _faceList[4].isFire = false;

    // face 6

    _faceList[5].LeftRow1 = 20;
    _faceList[5].LeftRow2 = 10;
    _faceList[5].LeftRow3 = 5;
    _faceList[5].LeftRow4 = 3;

    _faceList[5].RightRow1 = 25;
    _faceList[5].RightRow2 = 5;
    _faceList[5].RightRow3 = 3;
    _faceList[5].RightRow4 = 1;

    _faceList[5].InfantryCasualties = 18;
    _faceList[5].CavalryCasualties = 6;

    _faceList[5].meleeResults = "Routed";
    _faceList[5].isBlack = false;
    _faceList[5].isFire = false;

    _initTable();

}

void KriegsspielDie::initAsIII()
{
    _odds = "2:1";
    _dieNumber = 3;

    // face 1

    _faceList[0].LeftRow1 = 40;
    _faceList[0].LeftRow2 = 25;
    _faceList[0].LeftRow3 = 10;
    _faceList[0].LeftRow4 = 7;

    _faceList[0].RightRow1 = 30;
    _faceList[0].RightRow2 = 20;
    _faceList[0].RightRow3 = 12;
    _faceList[0].RightRow4 = 10;

    _faceList[0].InfantryCasualties = 18;
    _faceList[0].CavalryCasualties = 6;

    _faceList[0].meleeResults = "Routed";
    _faceList[0].isBlack = true;
    _faceList[0].isFire = true;

    // face 2

    _faceList[1].LeftRow1 = 20;
    _faceList[1].LeftRow2 = 10;
    _faceList[1].LeftRow3 = 6;
    _faceList[1].LeftRow4 = 5;

    _faceList[1].RightRow1 = 30;
    _faceList[1].RightRow2 = 20;
    _faceList[1].RightRow3 = 12;
    _faceList[1].RightRow4 = 10;

    _faceList[1].InfantryCasualties = 18;
    _faceList[1].CavalryCasualties = 6;

    _faceList[1].meleeResults = "Routed";
    _faceList[1].isBlack = true;
    _faceList[1].isFire = true;

    // face 3

    _faceList[2].LeftRow1 = 20;
    _faceList[2].LeftRow2 = 10;
    _faceList[2].LeftRow3 = 6;
    _faceList[2].LeftRow4 = 5;

    _faceList[2].RightRow1 = 15;
    _faceList[2].RightRow2 = 12;
    _faceList[2].RightRow3 = 8;
    _faceList[2].RightRow4 = 6;

    _faceList[2].InfantryCasualties = 30;
    _faceList[2].CavalryCasualties = 12;

    _faceList[2].meleeResults = "Totaly Defeated";
    _faceList[2].isBlack = false;
    _faceList[2].isFire = true;

    // face 4

    _faceList[3].LeftRow1 = 30;
    _faceList[3].LeftRow2 = 20;
    _faceList[3].LeftRow3 = 8;
    _faceList[3].LeftRow4 = 6;

    _faceList[3].RightRow1 = 20;
    _faceList[3].RightRow2 = 15;
    _faceList[3].RightRow3 = 9;
    _faceList[3].RightRow4 = 7;

    _faceList[3].InfantryCasualties = 25;
    _faceList[3].CavalryCasualties = 10;

    _faceList[3].meleeResults = "Defeated";
    _faceList[3].isBlack = false;
    _faceList[3].isFire = false;

    // face 5

    _faceList[4].LeftRow1 = 20;
    _faceList[4].LeftRow2 = 15;
    _faceList[4].LeftRow3 = 6;
    _faceList[4].LeftRow4 = 3;

    _faceList[4].RightRow1 = 15;
    _faceList[4].RightRow2 = 12;
    _faceList[4].RightRow3 = 8;
    _faceList[4].RightRow4 = 6;

    _faceList[4].InfantryCasualties = 18;
    _faceList[4].CavalryCasualties = 6;

    _faceList[4].meleeResults = "Routed";
    _faceList[4].isBlack = false;
    _faceList[4].isFire = false;

    // face 6

    _faceList[5].LeftRow1 = 20;
    _faceList[5].LeftRow2 = 10;
    _faceList[5].LeftRow3 = 5;
    _faceList[5].LeftRow4 = 3;

    _faceList[5].RightRow1 = 25;
    _faceList[5].RightRow2 = 5;
    _faceList[5].RightRow3 = 3;
    _faceList[5].RightRow4 = 1;

    _faceList[5].InfantryCasualties = 18;
    _faceList[5].CavalryCasualties = 6;

    _faceList[5].meleeResults = "Routed";
    _faceList[5].isBlack = false;
    _faceList[5].isFire = false;

    _initTable();

}

void KriegsspielDie::initAsIV()
{
    _odds = "3:1";
    _dieNumber = 4;

    // face 1

    _faceList[0].LeftRow1 = -1;
    _faceList[0].LeftRow2 = -1;
    _faceList[0].LeftRow3 = -1;
    _faceList[0].LeftRow4 = -1;

    _faceList[0].RightRow1 = -1;
    _faceList[0].RightRow2 = -1;
    _faceList[0].RightRow3 = -1;
    _faceList[0].RightRow4 = -1;

    _faceList[0].InfantryCasualties = 25;
    _faceList[0].CavalryCasualties = 10;

    _faceList[0].meleeResults = "Defeated";
    _faceList[0].isBlack = true;
    _faceList[0].isFire = false;

    // face 2

    _faceList[1].LeftRow1 = -1;
    _faceList[1].LeftRow2 = -1;
    _faceList[1].LeftRow3 = -1;
    _faceList[1].LeftRow4 = -1;

    _faceList[1].RightRow1 = -1;
    _faceList[1].RightRow2 = -1;
    _faceList[1].RightRow3 = -1;
    _faceList[1].RightRow4 = -1;

    _faceList[1].InfantryCasualties = 18;
    _faceList[1].CavalryCasualties = 6;

    _faceList[1].meleeResults = "Routed";
    _faceList[1].isBlack = true;
    _faceList[1].isFire = false;

    // face 3

    _faceList[2].LeftRow1 = -1;
    _faceList[2].LeftRow2 = -1;
    _faceList[2].LeftRow3 = -1;
    _faceList[2].LeftRow4 = -1;

    _faceList[2].RightRow1 = -1;
    _faceList[2].RightRow2 = -1;
    _faceList[2].RightRow3 = -1;
    _faceList[2].RightRow4 = -1;

    _faceList[2].InfantryCasualties = 30;
    _faceList[2].CavalryCasualties = 12;

    _faceList[2].meleeResults = "Totaly Defeated";
    _faceList[2].isBlack = true;
    _faceList[2].isFire = false;

    // face 4

    _faceList[3].LeftRow1 = -1;
    _faceList[3].LeftRow2 = -1;
    _faceList[3].LeftRow3 = -1;
    _faceList[3].LeftRow4 = -1;

    _faceList[3].RightRow1 = -1;
    _faceList[3].RightRow2 = -1;
    _faceList[3].RightRow3 = -1;
    _faceList[3].RightRow4 = -1;

    _faceList[3].InfantryCasualties = -1;
    _faceList[3].CavalryCasualties = -1;

    _faceList[3].meleeResults = "reroll";
    _faceList[3].isBlack = false;
    _faceList[3].isFire = false;

    // face 5

    _faceList[4].LeftRow1 = -1;
    _faceList[4].LeftRow2 = -1;
    _faceList[4].LeftRow3 = -1;
    _faceList[4].LeftRow4 = -1;

    _faceList[4].RightRow1 = -1;
    _faceList[4].RightRow2 = -1;
    _faceList[4].RightRow3 = -1;
    _faceList[4].RightRow4 = -1;

    _faceList[4].InfantryCasualties = -1;
    _faceList[4].CavalryCasualties = -1;

    _faceList[4].meleeResults = "reroll";
    _faceList[4].isBlack = false;
    _faceList[4].isFire = false;

    // face 6

    _faceList[5].LeftRow1 = -1;
    _faceList[5].LeftRow2 = -1;
    _faceList[5].LeftRow3 = -1;
    _faceList[5].LeftRow4 = -1;

    _faceList[5].RightRow1 = -1;
    _faceList[5].RightRow2 = -1;
    _faceList[5].RightRow3 = -1;
    _faceList[5].RightRow4 = -1;

    _faceList[5].InfantryCasualties = 18;
    _faceList[5].CavalryCasualties = 6;

    _faceList[5].meleeResults = "Routed";
    _faceList[5].isBlack = false;
    _faceList[5].isFire = false;

    _initTable();

}

void KriegsspielDie::initAsV()
{
    _odds = "4:1";
    _dieNumber = 5;

    // face 1

    _faceList[0].LeftRow1 = 25;
    _faceList[0].LeftRow2 = 16;
    _faceList[0].LeftRow3 = 6;
    _faceList[0].LeftRow4 = 3;

    _faceList[0].RightRow1 = 20;
    _faceList[0].RightRow2 = 12;
    _faceList[0].RightRow3 = 8;
    _faceList[0].RightRow4 = 3;

    _faceList[0].InfantryCasualties = 25;
    _faceList[0].CavalryCasualties = 10;

    _faceList[0].meleeResults = "Defeated";
    _faceList[0].isBlack = true;
    _faceList[0].isFire = false;

    // face 2

    _faceList[1].LeftRow1 = 25;
    _faceList[1].LeftRow2 = 16;
    _faceList[1].LeftRow3 = 6;
    _faceList[1].LeftRow4 = 3;

    _faceList[1].RightRow1 = 20;
    _faceList[1].RightRow2 = 12;
    _faceList[1].RightRow3 = 8;
    _faceList[1].RightRow4 = 3;

    _faceList[1].InfantryCasualties = 25;
    _faceList[1].CavalryCasualties = 10;

    _faceList[1].meleeResults = "Defeated";
    _faceList[1].isBlack = true;
    _faceList[1].isFire = false;

    // face 3

    _faceList[2].LeftRow1 = 30;
    _faceList[2].LeftRow2 = 20;
    _faceList[2].LeftRow3 = 8;
    _faceList[2].LeftRow4 = 4;

    _faceList[2].RightRow1 = 25;
    _faceList[2].RightRow2 = 15;
    _faceList[2].RightRow3 = 10;
    _faceList[2].RightRow4 = 5;

    _faceList[2].InfantryCasualties = 30;
    _faceList[2].CavalryCasualties = 12;

    _faceList[2].meleeResults = "Totaly Defeated";
    _faceList[2].isBlack = true;
    _faceList[2].isFire = false;

    // face 4

    _faceList[3].LeftRow1 = 20;
    _faceList[3].LeftRow2 = 15;
    _faceList[3].LeftRow3 = 5;
    _faceList[3].LeftRow4 = 2;

    _faceList[3].RightRow1 = 15;
    _faceList[3].RightRow2 = 8;
    _faceList[3].RightRow3 = 7;
    _faceList[3].RightRow4 = 4;

    _faceList[3].InfantryCasualties = 18;
    _faceList[3].CavalryCasualties = 6;

    _faceList[3].meleeResults = "Routed";
    _faceList[3].isBlack = true;
    _faceList[3].isFire = false;

    // face 5

    _faceList[4].LeftRow1 = 12;
    _faceList[4].LeftRow2 = 8;
    _faceList[4].LeftRow3 = 4;
    _faceList[4].LeftRow4 = 1;

    _faceList[4].RightRow1 = 8;
    _faceList[4].RightRow2 = 6;
    _faceList[4].RightRow3 = 5;
    _faceList[4].RightRow4 = 2;

    _faceList[4].InfantryCasualties = 18;
    _faceList[4].CavalryCasualties = 6;

    _faceList[4].meleeResults = "Routed";
    _faceList[4].isBlack = false;
    _faceList[4].isFire = false;

    // face 6

    _faceList[5].LeftRow1 = 12;
    _faceList[5].LeftRow2 = 8;
    _faceList[5].LeftRow3 = 4;
    _faceList[5].LeftRow4 = 1;

    _faceList[5].RightRow1 = 8;
    _faceList[5].RightRow2 = 6;
    _faceList[5].RightRow3 = 5;
    _faceList[5].RightRow4 = 2;

    _faceList[5].InfantryCasualties = -1;
    _faceList[5].CavalryCasualties = -1;

    _faceList[5].meleeResults = "reroll";
    _faceList[5].isBlack = false;
    _faceList[5].isFire = false;

    _initTable();

}

KriegsspielFace KriegsspielDie::roll()
{
    return _dieTable.getRollTableEntry();
}

void KriegsspielDie::_initTable()
{
    _dieTable.addEntry(_faceList[0]);
    _dieTable.addEntry(_faceList[1]);
    _dieTable.addEntry(_faceList[2]);
    _dieTable.addEntry(_faceList[3]);
    _dieTable.addEntry(_faceList[4]);
    _dieTable.addEntry(_faceList[5]);

}

