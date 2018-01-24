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
void MainWindow::Operation() // ������� ���������� �������������� ��������
{
    double cur = ui->txtRes->toPlainText().toDouble(); // ��������� �������� ��������
    //double cur = prevSum;

    if(first) // ���� ������
    {
        first = false;
        prevSum = cur; // �����������
        d = QString::number(prevSum); // ������� ������������� ���������
        SetText(d);
        prevwasSum = true;
        wasPoint = false;
        return;
    }
    if(prevwasSum)
        return;

    if(prevOper == 1) // ���� ���� ���� � ���������� �������� ������� - ����������
        prevSum += cur;
    else if(prevOper == 2) // ������� - ��������
        prevSum -= cur;
    else if(prevOper == 3) // �������� - ��������
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
        prevSum /= cur; // ������ - �����
    }
    else
        prevSum = pow(prevSum, cur); // ���� �������� � �������
    //!!!
    d = QString::number(prevSum); // ������� ������������� ���������
    SetText(d);

    prevwasSum = true; // ��� ���������
    wasPoint = false; // ����� ������� �����
}

void MainWindow::AddSym(QString sym)
{
    if(prevwasSum) // ���� � ������� ��� ��� ���������, �� �������
    {
        SetText("");
        prevwasSum = false;
    }
    QString str = ui->txtRes->toPlainText(); // ���������
    str += sym; // ������������

    SetText(str);
}

void MainWindow::SetText(QString str)
{
    ui->txtRes->setText(str); // �������
    ui->txtRes->setAlignment(Qt::AlignRight);

}
int MainWindow::factorial(int num)
{
    if(num == 1) // ������ ����������� �������
        return 1;
    if(num < 0) { // ���� num �������������
        num = 0 - num;
        return (0 - (factorial(num-1) * num));
    }
    return (factorial(num - 1) * num);
}
void MainWindow::on_button1_1_clicked()
{
    AddSym("1");
}

void MainWindow::on_plus_clicked() // �������� ����
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

void MainWindow::on_minus_clicked() // �������� �����
{
    Operation();
    prevOper = 2;
}

void MainWindow::on_multiply_clicked() // �������� ��������
{
    Operation();
    prevOper = 3;
}

void MainWindow::on_devide_clicked() // �������� ��������
{
    Operation();
    prevOper = 4;
}

void MainWindow::on_equalButton_clicked() // ������ �����
{
    double cur = ui->txtRes->toPlainText().toDouble(); // ���������
    if(prevOper == 1) // ���� ���� ���� �������, ����������
    {
        prevSum += cur;
        s = QString::number(prevSum);
    }
    else if(prevOper == 2) // �������, ��������
    {
        prevSum -= cur;
        s = QString::number(prevSum);
    }
    else if (prevOper == 3) // ��������, ��������
    {
        prevSum *= cur;
        s = QString::number(prevSum);
    }
    else if(prevOper == 4) // ��������, �����
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
    else if (prevOper == 5) // �������� � �������
    {
        prevSum = pow(prevSum, cur);
        s = QString::number(prevSum);
    }
    else // ���� ������ ������ ���, �� ������ ��������
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
    first = true; // ������
    prevSum = 0;
    SetText(""); // �������
}



void MainWindow::on_actionAbout_triggered()
{
    Dialog z; // ��������� ���� � ���
    z.exec();
}
void MainWindow::AlgebraOper(int oper) // ������. ����., �� ���� ������� ����������� ������ � ����� ����������
{

    Operation(); // �������� ���������� ��������
    first = true;
    if(oper == 1) // �����. ������
        prevSum = sqrt(prevSum);
    else if (oper == 2) // ���. ������
        prevSum = cbrt(prevSum);
    else if(oper == 3) // 1 / x
        prevSum = 1 / prevSum;
    else if(oper == 4) // ���������
        prevSum = factorial(prevSum);
    else if (oper == 5) // �������
        prevSum = pow(prevSum, 2);
    else if (oper == 6) // 10 � ������� x
        prevSum = pow(10, prevSum);
    else if (oper == 7) // �������
        prevSum /= 100;
    else if(oper == 8) // �������
        prevSum = cos(prevSum * pi / 180.0);
    else if(oper == 9) // ����������
        prevSum = acos(prevSum) * 180.0 / pi;
    else if(oper == 10) // �����
        prevSum = sin(prevSum * pi / 180.0);
    else if(oper == 11) // ��������
        prevSum = asin(prevSum) * 180.0 / pi;
    else if(oper == 12) // �������
        prevSum = tan(prevSum * pi / 180.0);
    else if(oper == 13) // ����������
        prevSum = atan(prevSum) * 180.0 / pi;
    s = QString::number(prevSum);
    SetText(s);
}

void MainWindow::on_sqrt_clicked()
{
    AlgebraOper(1); // ����� ��������
}

void MainWindow::on_cbrt_clicked()
{
    AlgebraOper(2);// ����� ��������
}

void MainWindow::on_divideonx_clicked()
{
    AlgebraOper(3);// ����� ��������
}

void MainWindow::on_facrorial_clicked()
{
    AlgebraOper(4);// ����� ��������
}

void MainWindow::on_square_clicked()
{
    AlgebraOper(5);// ����� ��������
}

void MainWindow::on_tenx_clicked()
{
    AlgebraOper(6);// ����� ��������
}

void MainWindow::on_point_clicked() // �����
{
    double cur = ui->txtRes->toPlainText().toDouble();
    if(wasPoint || prevwasSum) // ���� ��� ����, �� �� ����� ��� ���� �������
        return;
    s = QString::number(cur);
    s += ".";// ��������� �����
    SetText(s);
    wasPoint = true;
}

void MainWindow::on_backspace_clicked() // ��������
{

    l = ui->txtRes->toPlainText();

    if(!l.length()) // ���� ��� ��� ������ ���, �� ������� �� �����
        return;
    if(l[l.length() - 1] == '.') // ���� ��, ��� �� ����� ������� �����, �� ������, ��� ����� �������� �����
        wasPoint = false;
    for(int i = 0; i < l.length() - 1; i++) // ����������
    {
        l1[i] = l[i];
    }
    SetText(l1);
    l1 = ""; // ���������
}

void MainWindow::on_xiny_clicked()
{
    Operation();
    prevOper = 5;
}
void MainWindow::keyPressEvent(QKeyEvent * event) // ���� � ����������
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

void MainWindow::on_actionExit_triggered() // �����
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
