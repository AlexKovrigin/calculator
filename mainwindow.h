#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog.h>
#include <null.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button1_1_clicked();

    void on_plus_clicked();

    void on_button1_2_clicked();

    void on_button1_3_clicked();

    void on_button1_4_clicked();

    void on_button1_5_clicked();

    void on_button1_6_clicked();

    void on_button1_7_clicked();

    void on_button1_8_clicked();

    void on_button1_9_clicked();

    void on_button1_10_clicked();

    void on_minus_clicked();

    void on_multiply_clicked();

    void on_devide_clicked();

    void on_equalButton_clicked();

    void on_clearButton_clicked();

    void on_actionAbout_triggered();

    void on_sqrt_clicked();

    void on_cbrt_clicked();

    void on_divideonx_clicked();

    void on_facrorial_clicked();

    void on_square_clicked();

    void on_tenx_clicked();

    void on_xiny_clicked();

    void on_point_clicked();

    void on_backspace_clicked();

    void on_procent_clicked();

    void on_actionExit_triggered();

    void on_cos_clicked();

    void on_acos_clicked();

    void on_sin_clicked();

    void on_asin_clicked();

    void on_tang_clicked();

    void on_atang_clicked();

private:
    Ui::MainWindow *ui;
    double prevSum = 0; // основной промежуточный результат
    int prevOper = 0; // номер операции
    QString s; // строка для вывода окончательного результата
    QString d; // строка для вывода промежуточного результата
    bool first = true; // первый
    bool prevwasSum = false; // был результат
    void AddSym(QString sym); // функция записи цифры
    void Operation(); // арифметические операции
    void SetText(QString str); // функция записи текста
    void AlgebraOper(int oper);
    int factorial(int num);
    bool wasPoint = false;
    QString l;
    QString l1;
    void keyPressEvent(QKeyEvent * event);
    const double pi = 3.14159265358979323846;
};

#endif // MAINWINDOW_H
