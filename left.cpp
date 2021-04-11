#include "left.h"
#include "ui_left.h"
#include "main.h"

Left::Left(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Left)
{
    ui->setupUi(this);
}

void Left::updateText(QString pos, QString text, QString inverted)
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

Left::~Left()
{
    delete ui;
}
