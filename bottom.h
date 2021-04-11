#ifndef BOTTOM_H
#define BOTTOM_H

#include <QWidget>

namespace Ui {
class Bottom;
}

class Bottom : public QWidget
{
    Q_OBJECT

public:
    explicit Bottom(QWidget *parent = nullptr);
    ~Bottom();

private:
    Ui::Bottom *ui;

public slots:
    void updateText(QString pos, QString text, QString inverted);
};

#endif // BOTTOM_H
