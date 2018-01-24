#ifndef NULL_H
#define NULL_H

#include <QDialog>

namespace Ui {
class Null;
}

class Null : public QDialog
{
    Q_OBJECT

public:
    explicit Null(QWidget *parent = 0);
    ~Null();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Null *ui;
};

#endif // NULL_H
