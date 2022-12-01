#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_insertButton_clicked();

    void on_insertRadioButton_toggled(bool checked);

    void on_removeRadioButton_toggled(bool checked);

    void on_horizontalScrollBar_valueChanged(int value);

    void on_lineEdit_editingFinished();

    void on_verticalScrollBar_valueChanged(int value);

    void on_pushButton_clicked();

    void on_radioButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent*) override;

    //void DrawCircle(int radius, QColor color, QPainter* painter);
};
#endif // MAINWINDOW_H
