#include "display.h"
#include "./ui_display.h"

#define NOTINVERTED "<span style=\"background-color:#00000000; color:limegreen; font:10pt, B612;\">"
#define INVERTED "<span style=\"background-color:limegreen; color:black; font:10pt, B612;\">"
#define END "</span>"

//<span style="color:limegreen; font:10pt, B612;"> Unselected </span>
//<span style="background-color:limegreen; color:black; font:10pt, B612;"> Selected </span>
Display::Display(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Display)
{
    ui->setupUi(this);
}

void Display::updateText(QString pos, QString text, QString inverted)
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

Display::~Display()
{
    delete ui;
}


