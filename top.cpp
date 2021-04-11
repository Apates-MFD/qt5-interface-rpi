#include "top.h"
#include "ui_top.h"
#include "main.h"

Top::Top(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Top)
{
    ui->setupUi(this);
}

void Top::updateText(QString pos, QString text, QString inverted)
{
    QString labelIdent = "label_";
    labelIdent.append(pos);
    QLabel* label = this->findChild<QLabel*>(labelIdent);
    QString fullText = "";

    if(label == NULL) return;

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

Top::~Top()
{
    delete ui;
}
