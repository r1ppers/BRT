#ifndef NODENOTFOUND_H
#define NODENOTFOUND_H

#include <QDialog>

namespace Ui {
class nodeNotFound;
}

class nodeNotFound : public QDialog
{
    Q_OBJECT

public:
    explicit nodeNotFound(QWidget *parent = nullptr);
    ~nodeNotFound();

private slots:
    void on_pushButton_clicked();

private:
    Ui::nodeNotFound *ui;
};

#endif // NODENOTFOUND_H
