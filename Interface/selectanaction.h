#ifndef SELECTANACTION_H
#define SELECTANACTION_H

#include <QDialog>

namespace Ui {
class SelectAnAction;
}

class SelectAnAction : public QDialog
{
    Q_OBJECT

public:
    explicit SelectAnAction(QWidget *parent = nullptr);
    ~SelectAnAction();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SelectAnAction *ui;
};

#endif // SELECTANACTION_H
