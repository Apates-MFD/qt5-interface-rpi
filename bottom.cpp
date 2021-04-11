#include "bottom.h"
#include "ui_bottom.h"
#include "main.h"

Bottom::Bottom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bottom)
{
    ui->setupUi(this);
}

void Bottom::updateText(QString pos, QString text, QString inverted)
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

Bottom::~Bottom()
{
    delete ui;
}
