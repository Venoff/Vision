#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QFileDialog>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->importerBilledeButton->connect(ui->importerBilledeButton, SIGNAL(clicked(bool)), this, SLOT(importerBillede()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::importerBillede()
{
    qDebug() << "Test " << QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).join(""), tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));

    qDebug() << "Filename " << fileName;
}
