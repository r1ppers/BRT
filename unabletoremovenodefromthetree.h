#ifndef UNABLETOREMOVENODEFROMTHETREE_H
#define UNABLETOREMOVENODEFROMTHETREE_H

#include <QDialog>

namespace Ui {
class UnableToRemoveNodeFromTheTree;
}

class UnableToRemoveNodeFromTheTree : public QDialog
{
    Q_OBJECT

public:
    explicit UnableToRemoveNodeFromTheTree(QWidget *parent = nullptr);
    ~UnableToRemoveNodeFromTheTree();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UnableToRemoveNodeFromTheTree *ui;
};

#endif // UNABLETOREMOVENODEFROMTHETREE_H
