#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbInfFire_clicked()
{
    InfantryFire::InfantryType type;
    InfantryFire::InfantryRange range;
    bool isAttackCover = ui->cbInfAttCover->isChecked();
    bool isTargetCover = ui->cbInfDefCover->isChecked();

    if (ui->rbInfAttHalfBat->isChecked()) { type = InfantryFire::INF_TYPE_HALF_BAT;  }
    else if (ui->rbInfAttLineInf->isChecked()) { type = InfantryFire::INF_TYPE_SKIRMISH; }
    else { type = InfantryFire::INF_TYPE_JAGER; }

    if (ui->rbInfRange100->isChecked()) { range = InfantryFire::INF_POINT_BLANK; }
    else if (ui->rbInfRange200->isChecked()) { range = InfantryFire::INF_SHORT; }
    else if (ui->rbInfRange300->isChecked()) { range = InfantryFire::INF_MEDIUM; }
    else { range = InfantryFire::INF_LONG; }

    int points = _infFire.attackResult(type, range, isAttackCover, isTargetCover);
    QString dieRef = _infFire.getLastRef();

    ui->lePointsDmg->setText(QString::number(points) + " points");
    ui->leDieRef->setText(dieRef);

}

void MainWindow::on_pbArtilleryFire_clicked()
{
    ArtilleryFire::ArtilleryType type;
    if (ui->rbBat6->isChecked()) { type = ArtilleryFire::ART_TYPE_6; }
    else if (ui->rbBat7->isChecked()) { type = ArtilleryFire::ART_TYPE_7; }
    else if (ui->rbBat10lb->isChecked()) { type = ArtilleryFire::ART_TYPE_10; }
    else { type = ArtilleryFire::ART_TYPE_12; }

    ArtilleryFire::ArtilleryRange range;
    if (ui->rbCanister->isChecked()) { range = ArtilleryFire::ART_CANISTER; }
    else if (ui->rbLow->isChecked()) { range = ArtilleryFire::ART_LOW; }
    else if (ui->rbHigh->isChecked()) { range = ArtilleryFire::ART_HIGH; }
    else { range = ArtilleryFire::ART_RICOCHET; }

    ArtilleryFire::Effect effect;
    if (ui->rbGoodEffect->isChecked()) { effect = ArtilleryFire::GOOD_EFFECT; }
    else { effect = ArtilleryFire::BAD_EFFECT; }

    TargetFactors factors;
    factors.HasCover = ui->cbArtilleryCover->isChecked();
    factors.DeepCover = ui->cbDeepCover->isChecked();
    factors.TwoCol = ui->cbArtillery2Col->isChecked();
    factors.Grenade = ui->cbGrenadeFire->isChecked();
    factors.TwoLines = ui->cbArt2Lines->isChecked();
    factors.Skirmishers = ui->cbArtillerySkirmishers->isChecked();
    factors.Flanking = ui->cbFlanks->isChecked();

    int points = _artFire.attackResult(type, range, effect, factors);
    QString dieRef = _artFire.getLastRef();

    ui->lePointsDmg->setText(QString::number(points) + " points");
    ui->leDieRef->setText(dieRef);

}
