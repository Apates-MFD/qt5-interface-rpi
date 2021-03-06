#ifndef RIGHT_H
#define RIGHT_H

#include <QWidget>

namespace Ui {
class Right;
}

class Right : public QWidget
{
    Q_OBJECT

public:
    explicit Right(QWidget *parent = nullptr);
    ~Right();

private:
    Ui::Right *ui;

public slots:
    void updateText(QString pos, QString text, QString inverted);
};


#endif // RIGHT_H
