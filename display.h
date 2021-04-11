#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Display; }
QT_END_NAMESPACE

class Display : public QWidget
{
    Q_OBJECT

public:
    Display(QWidget *parent = nullptr);
    ~Display();

private:
    Ui::Display *ui;

public slots:
    void updateText(QString pos, QString text, QString inverted);
};
#endif // DISPLAY_H