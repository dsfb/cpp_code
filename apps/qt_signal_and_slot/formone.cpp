#include "formone.h"
#include "ui_formone.h"

FormOne::FormOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOne)
{
    ui->setupUi(this);
}

FormOne::~FormOne()
{
    delete ui;
}

void FormOne::on_plainTextEdit_textChanged()
{
    emit textChanged(ui->plainTextEdit->toPlainText());
}

void FormOne::setText(QString text)
{
    ui->plainTextEdit->document()->clear();
    ui->plainTextEdit->document()->setPlainText(text);
}
