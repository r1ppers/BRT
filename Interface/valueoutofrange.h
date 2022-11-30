#ifndef VALUEOUTOFRANGE_H
#define VALUEOUTOFRANGE_H

#include <QDialog>

namespace Ui {
class ValueOutOfRange;
}

class ValueOutOfRange : public QDialog
{
    Q_OBJECT

public:
    explicit ValueOutOfRange(QWidget *parent = nullptr);
    ~ValueOutOfRange();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ValueOutOfRange *ui;
};

#endif // VALUEOUTOFRANGE_H
