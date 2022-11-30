#include "valueoutofrange.h"
#include "ui_valueoutofrange.h"

ValueOutOfRange::ValueOutOfRange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ValueOutOfRange)
{
    ui->setupUi(this);
}

ValueOutOfRange::~ValueOutOfRange()
{
    delete ui;
}

void ValueOutOfRange::on_pushButton_clicked()
{
    ValueOutOfRange::hide();
}

