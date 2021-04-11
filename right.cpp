#include "right.h"
#include "ui_right.h"
#include "main.h"

Right::Right(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Right)
{
    ui->setupUi(this);
}

void Right::updateText(QString pos, QString text, QString inverted)
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


Right::~Right()
{
    delete ui;
}
