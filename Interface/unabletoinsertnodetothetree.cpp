#include "unabletoinsertnodetothetree.h"
#include "ui_unabletoinsertnodetothetree.h"

UnableToInsertNodeToTheTree::UnableToInsertNodeToTheTree(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UnableToInsertNodeToTheTree)
{
    ui->setupUi(this);
}

UnableToInsertNodeToTheTree::~UnableToInsertNodeToTheTree()
{
    delete ui;
}

void UnableToInsertNodeToTheTree::on_pushButton_clicked()
{
    UnableToInsertNodeToTheTree::hide();
    //QApplication::exit();
}

