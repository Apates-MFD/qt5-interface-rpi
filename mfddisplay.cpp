#include "mfddisplay.h"
#include "ui_display.h"

#define NOTINVERTED "<span style=\"background-color:#00000000; color:limegreen; font:10pt, B612;\">"
#define INVERTED "<span style=\"background-color:limegreen; color:black; font:10pt, B612;\">"
#define END "</span>"

MFDDisplay::MFDDisplay(QWidget *parent) : QWidget(parent), ui(new Ui::MFDDisplay)
{
    ui->setupUi(this);
}

void MFDDisplay::updateText(QString pos, QString text, QString inverted)
{
    QString labelIdent = "label_";
    labelIdent.append(pos);
    QLabel* label = this->findChild<QLabel*>(labelIdent);
    QString fullText = "";

    if(inverted.compare("true") == 0)
    {
        fullText.append(INVERTED);
    }
    else {
         fullText.append(NOTINVERTED);
    }

    fullText.append(text);
    fullText.append(END);
    label->setText(fullText);
}

MFDDisplay::~MFDDisplay()
{
    delete ui;
}
