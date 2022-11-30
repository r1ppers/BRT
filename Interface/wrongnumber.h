#ifndef WRONGNUMBER_H
#define WRONGNUMBER_H

#include <QDialog>

namespace Ui {
class WrongNumber;
}

class WrongNumber : public QDialog
{
    Q_OBJECT

public:
    explicit WrongNumber(QWidget *parent = nullptr);
    ~WrongNumber();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WrongNumber *ui;
};

#endif // WRONGNUMBER_H
