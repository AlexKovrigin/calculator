#include "null.h"
#include "ui_null.h"

Null::Null(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Null)
{
    ui->setupUi(this);
}

Null::~Null()
{
    delete ui;
}

void Null::on_pushButton_clicked()
{
    exit(1);
}
