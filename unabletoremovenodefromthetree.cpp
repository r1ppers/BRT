#include "unabletoremovenodefromthetree.h"
#include "ui_unabletoremovenodefromthetree.h"

UnableToRemoveNodeFromTheTree::UnableToRemoveNodeFromTheTree(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UnableToRemoveNodeFromTheTree)
{
    ui->setupUi(this);
}

UnableToRemoveNodeFromTheTree::~UnableToRemoveNodeFromTheTree()
{
    delete ui;
}

void UnableToRemoveNodeFromTheTree::on_pushButton_clicked()
{
    UnableToRemoveNodeFromTheTree::hide();
}

