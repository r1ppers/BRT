#ifndef UNABLETOINSERTNODETOTHETREE_H
#define UNABLETOINSERTNODETOTHETREE_H

#include <QDialog>

namespace Ui {
class UnableToInsertNodeToTheTree;
}

class UnableToInsertNodeToTheTree : public QDialog
{
    Q_OBJECT

public:
    explicit UnableToInsertNodeToTheTree(QWidget *parent = nullptr);
    ~UnableToInsertNodeToTheTree();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UnableToInsertNodeToTheTree *ui;
};

#endif // UNABLETOINSERTNODETOTHETREE_H
