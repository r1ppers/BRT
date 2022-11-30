#include "selectanaction.h"
#include "ui_selectanaction.h"

SelectAnAction::SelectAnAction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectAnAction)
{
    ui->setupUi(this);
}

SelectAnAction::~SelectAnAction()
{
    delete ui;
}

void SelectAnAction::on_pushButton_clicked()
{
    SelectAnAction::hide();
}

