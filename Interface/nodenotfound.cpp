#include "nodenotfound.h"
#include "ui_nodenotfound.h"

nodeNotFound::nodeNotFound(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nodeNotFound)
{
    ui->setupUi(this);
}

nodeNotFound::~nodeNotFound()
{
    delete ui;
}

void nodeNotFound::on_pushButton_clicked()
{
    nodeNotFound::hide();
}

