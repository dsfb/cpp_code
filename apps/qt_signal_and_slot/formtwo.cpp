#include "formtwo.h"
#include "ui_formtwo.h"

FormTwo::FormTwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTwo)
{
    ui->setupUi(this);
}

FormTwo::~FormTwo()
{
    delete ui;
}

void FormTwo::on_plainTextEdit_textChanged()
{
    emit textChanged(ui->plainTextEdit->toPlainText());
}

void FormTwo::setText(QString text)
{
    ui->plainTextEdit->document()->clear();
    ui->plainTextEdit->document()->setPlainText(text);
}
