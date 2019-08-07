#ifndef FORMTWO_H
#define FORMTWO_H

#include <QWidget>

namespace Ui {
class FormTwo;
}

class FormTwo : public QWidget
{
    Q_OBJECT

public:
    explicit FormTwo(QWidget *parent = nullptr);
    ~FormTwo();

signals:
    void textChanged(QString text);

private slots:
    void on_plainTextEdit_textChanged();

public slots:
    void setText(QString text);

private:
    Ui::FormTwo *ui;
};

#endif // FORMTWO_H
