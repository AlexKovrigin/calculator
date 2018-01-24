#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->txtRes->setAlignment(Qt::AlignRight);
    //ui->lblRes->setAlignment(Qt::AlignRight);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Operation() // функция выполнения арифметических действий
{
    double cur = ui->txtRes->toPlainText().toDouble(); // получение текущего значения
    //double cur = prevSum;

    if(first) // если первый
    {
        first = false;
        prevSum = cur; // присваиваем
        d = QString::number(prevSum); // выводим промежуточный результат
        SetText(d);
        prevwasSum = true;
        wasPoint = false;
        return;
    }
    if(prevwasSum)
        return;

    if(prevOper == 1) // если надо было в предыдущей операции сложить - складываем
        prevSum += cur;
    else if(prevOper == 2) // вычесть - вычитаем
        prevSum -= cur;
    else if(prevOper == 3) // умножить - умножаем
        prevSum *= cur;
    else if (prevOper == 4)
    {
       /* if(cur == 0)
        {
            Null i;
            i.show();
            //on_clearButton_clicked();
            return;
        }*/
        prevSum /= cur; // делить - делим
    }
    else
        prevSum = pow(prevSum, cur); // если возвести в степень
    //!!!
    d = QString::number(prevSum); // выводим промежуточный результат
    SetText(d);

    prevwasSum = true; // был результат
    wasPoint = false; // можно ставить точку
}

void MainWindow::AddSym(QString sym)
{
    if(prevwasSum) // если в прошлый раз был результат, то удаляем
    {
        SetText("");
        prevwasSum = false;
    }
    QString str = ui->txtRes->toPlainText(); // считываем
    str += sym; // обрабатываем

    SetText(str);
}

void MainWindow::SetText(QString str)
{
    ui->txtRes->setText(str); // выводим
    ui->txtRes->setAlignment(Qt::AlignRight);

}
int MainWindow::factorial(int num)
{
    if(num == 1) // делаем рекурсивную функцию
        return 1;
    if(num < 0) { // если num отрицательное
        num = 0 - num;
        return (0 - (factorial(num-1) * num));
    }
    return (factorial(num - 1) * num);
}
void MainWindow::on_button1_1_clicked()
{
    AddSym("1");
}

void MainWindow::on_plus_clicked() // операция плюс
{
    Operation();
    prevOper = 1;
}

void MainWindow::on_button1_2_clicked()
{
    AddSym("2");
}

void MainWindow::on_button1_3_clicked()
{
    AddSym("3");
}

void MainWindow::on_button1_4_clicked()
{
    AddSym("4");
}

void MainWindow::on_button1_5_clicked()
{
    AddSym("5");
}

void MainWindow::on_button1_6_clicked()
{
    AddSym("6");
}

void MainWindow::on_button1_7_clicked()
{
    AddSym("7");
}

void MainWindow::on_button1_8_clicked()
{
    AddSym("8");
}

void MainWindow::on_button1_9_clicked()
{
    AddSym("9");
}

void MainWindow::on_button1_10_clicked()
{
    AddSym("0");
}

void MainWindow::on_minus_clicked() // операция минус
{
    Operation();
    prevOper = 2;
}

void MainWindow::on_multiply_clicked() // операция умножить
{
    Operation();
    prevOper = 3;
}

void MainWindow::on_devide_clicked() // операция поделить
{
    Operation();
    prevOper = 4;
}

void MainWindow::on_equalButton_clicked() // кнопка равно
{
    double cur = ui->txtRes->toPlainText().toDouble(); // считываем
    if(prevOper == 1) // если надо было сложить, складываем
    {
        prevSum += cur;
        s = QString::number(prevSum);
    }
    else if(prevOper == 2) // вычесть, вычитаем
    {
        prevSum -= cur;
        s = QString::number(prevSum);
    }
    else if (prevOper == 3) // умножить, умножаем
    {
        prevSum *= cur;
        s = QString::number(prevSum);
    }
    else if(prevOper == 4) // поделить, делим
    {
       /* if(cur == 0)
        {
            Null i;
            i.exec();
            on_clearButton_clicked();
            return;
        }*/
        prevSum /= cur;
        s = QString::number(prevSum);
    }
    else if (prevOper == 5) // возвести в степень
    {
        prevSum = pow(prevSum, cur);
        s = QString::number(prevSum);
    }
    else // если нажали второй раз, то просто обнуляем
    {
        s = "";
    }
    SetText(s);


    prevwasSum = true;
    first = true;
    prevSum = 0;
    wasPoint = false;
}

void MainWindow::on_clearButton_clicked()
{
    first = true; // первый
    prevSum = 0;
    SetText(""); // очистка
}



void MainWindow::on_actionAbout_triggered()
{
    Dialog z; // открываем окно о нас
    z.exec();
}
void MainWindow::AlgebraOper(int oper) // алгебр. опер., то есть которые вычисляются только с одним параметром
{

    Operation(); // проводим предыдущую операцию
    first = true;
    if(oper == 1) // квадр. корень
        prevSum = sqrt(prevSum);
    else if (oper == 2) // куб. корень
        prevSum = cbrt(prevSum);
    else if(oper == 3) // 1 / x
        prevSum = 1 / prevSum;
    else if(oper == 4) // факториал
        prevSum = factorial(prevSum);
    else if (oper == 5) // квадрат
        prevSum = pow(prevSum, 2);
    else if (oper == 6) // 10 в степени x
        prevSum = pow(10, prevSum);
    else if (oper == 7) // процент
        prevSum /= 100;
    else if(oper == 8) // косинус
        prevSum = cos(prevSum * pi / 180.0);
    else if(oper == 9) // арккосинус
        prevSum = acos(prevSum) * 180.0 / pi;
    else if(oper == 10) // синус
        prevSum = sin(prevSum * pi / 180.0);
    else if(oper == 11) // арксинус
        prevSum = asin(prevSum) * 180.0 / pi;
    else if(oper == 12) // тангенс
        prevSum = tan(prevSum * pi / 180.0);
    else if(oper == 13) // арктангенс
        prevSum = atan(prevSum) * 180.0 / pi;
    s = QString::number(prevSum);
    SetText(s);
}

void MainWindow::on_sqrt_clicked()
{
    AlgebraOper(1); // вызов операции
}

void MainWindow::on_cbrt_clicked()
{
    AlgebraOper(2);// вызов операции
}

void MainWindow::on_divideonx_clicked()
{
    AlgebraOper(3);// вызов операции
}

void MainWindow::on_facrorial_clicked()
{
    AlgebraOper(4);// вызов операции
}

void MainWindow::on_square_clicked()
{
    AlgebraOper(5);// вызов операции
}

void MainWindow::on_tenx_clicked()
{
    AlgebraOper(6);// вызов операции
}

void MainWindow::on_point_clicked() // точка
{
    double cur = ui->txtRes->toPlainText().toDouble();
    if(wasPoint || prevwasSum) // если уже была, то не можем еще одну ставить
        return;
    s = QString::number(cur);
    s += ".";// добавляем точку
    SetText(s);
    wasPoint = true;
}

void MainWindow::on_backspace_clicked() // удаление
{

    l = ui->txtRes->toPlainText();

    if(!l.length()) // если там уже ничего нет, то удалить не можем
        return;
    if(l[l.length() - 1] == '.') // если то, что мы хотим удалить точка, то значит, что можно ставитьь точку
        wasPoint = false;
    for(int i = 0; i < l.length() - 1; i++) // перезапись
    {
        l1[i] = l[i];
    }
    SetText(l1);
    l1 = ""; // обнуление
}

void MainWindow::on_xiny_clicked()
{
    Operation();
    prevOper = 5;
}
void MainWindow::keyPressEvent(QKeyEvent * event) // ввод с клавиатуры
{
    if(event->key() == Qt::Key_1)
        on_button1_1_clicked();
    else if(event->key() == Qt::Key_2)
        on_button1_2_clicked();
    else if(event->key() == Qt::Key_3)
        on_button1_3_clicked();
    else if(event->key() == Qt::Key_4)
        on_button1_4_clicked();
    else if(event->key() == Qt::Key_5)
        on_button1_5_clicked();
    else if(event->key() == Qt::Key_6)
        on_button1_6_clicked();
    else if(event->key() == Qt::Key_7)
        on_button1_7_clicked();
    else if(event->key() == Qt::Key_8)
        on_button1_8_clicked();
    else if(event->key() == Qt::Key_9)
        on_button1_9_clicked();
    else if(event->key() == Qt::Key_0)
        on_button1_10_clicked();
    else if(event->key() == Qt::Key_Plus)
        on_plus_clicked();
    else if(event->key() == 45)
        on_minus_clicked();
    else if(event->key() == 42)
        on_multiply_clicked();
    else if(event->key() == Qt::Key_Slash)
        on_devide_clicked();
    else if(event->key() == Qt::Key_Equal)
        on_equalButton_clicked();
    else if(event->key() == 46)
        on_point_clicked();
    else if(event->key() == Qt::Key_Backspace)
        on_backspace_clicked();
    else if(event->key() == Qt::Key_C)
        on_clearButton_clicked();
    else if(event->key() == 33)
        on_facrorial_clicked();
    /*else { // For debug only!
        s = QString::number(event->key());
        SetText(s);
    }*/
}

void MainWindow::on_procent_clicked()
{
    AlgebraOper(7);
}

void MainWindow::on_actionExit_triggered() // выход
{
    exit(1);
}

void MainWindow::on_cos_clicked()
{
    AlgebraOper(8);
}

void MainWindow::on_acos_clicked()
{
    AlgebraOper(9);
}

void MainWindow::on_sin_clicked()
{
    AlgebraOper(10);
}

void MainWindow::on_asin_clicked()
{
    AlgebraOper(11);
}

void MainWindow::on_tang_clicked()
{
    AlgebraOper(12);
}

void MainWindow::on_atang_clicked()
{
    AlgebraOper(13);
}
