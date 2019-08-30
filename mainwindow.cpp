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

}
