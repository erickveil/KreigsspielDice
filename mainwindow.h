#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "infantryfire.h"
#include "artilleryfire.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    InfantryFire _infFire;
    ArtilleryFire _artFire;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbInfFire_clicked();

    void on_pbArtilleryFire_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
