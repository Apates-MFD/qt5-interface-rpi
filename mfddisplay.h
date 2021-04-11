#ifndef MFDDISPLAY_H
#define MFDDISPLAY_H

#include <QWidget>

namespace Ui {
class MFDDisplay;
}

class MFDDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit MFDDisplay(QWidget *parent = nullptr);
    virtual ~MFDDisplay();

private:
    Ui::MFDDisplay *ui;

public slots:
    void updateText(QString pos, QString text, QString inverted);

};

#endif // MFDDISPLAY_H
