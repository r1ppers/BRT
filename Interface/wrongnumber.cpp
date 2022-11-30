#include "wrongnumber.h"
#include "ui_wrongnumber.h"

WrongNumber::WrongNumber(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WrongNumber)
{
    ui->setupUi(this);
}

WrongNumber::~WrongNumber()
{
    delete ui;
}

void WrongNumber::on_pushButton_clicked()
{
    WrongNumber::hide();
}

