#include "infowindow.h"
#include "ui_infowindow.h"

infoWindow::infoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoWindow)
{
    ui->setupUi(this);
}

infoWindow::~infoWindow()
{
    delete ui;
}

void infoWindow::on_pushButton_clicked()
{
    infoWindow::hide();
}

