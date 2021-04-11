#ifndef SUBDISPLAY_H
#define SUBDISPLAY_H

#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class Subdisplay; }
QT_END_NAMESPACE
class Subdisplay
{
    Q_OBJECT

public:
    Subdisplay(QWidget *parent = nullptr);
    ~Subdisplay();

private:
    Ui::Subdisplay *ui;
};

#endif // SUBDISPLAY_H
