#ifndef FORMONE_H
#define FORMONE_H

#include <QWidget>

namespace Ui {
class FormOne;
}

class FormOne : public QWidget
{
    Q_OBJECT

public:
    explicit FormOne(QWidget *parent = nullptr);
    ~FormOne();

signals:
    void textChanged(QString text);

private slots:
    void on_plainTextEdit_textChanged();

public slots:
    void setText(QString text);

private:
    Ui::FormOne *ui;
};

#endif // FORMONE_H
