#ifndef LEFT_H
#define LEFT_H

#include <QWidget>

namespace Ui {
class Left;
}

class Left : public QWidget
{
    Q_OBJECT

public:
    explicit Left(QWidget *parent = nullptr);
    ~Left();

private:
    Ui::Left *ui;

public slots:
    void updateText(QString pos, QString text, QString inverted);
};



#endif // LEFT_H
