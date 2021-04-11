#ifndef TOP_H
#define TOP_H

#include <QWidget>

namespace Ui {
class Top;
}

class Top : public QWidget
{
    Q_OBJECT

public:
    explicit Top(QWidget *parent = nullptr);
    ~Top();

private:
    Ui::Top *ui;

public slots:
    void updateText(QString pos, QString text, QString inverted);
};
#endif // TOP_H
