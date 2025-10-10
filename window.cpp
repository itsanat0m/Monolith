#include "window.h"
#include <QLabel>

window::window(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(1000, 700);

    QLabel *textBox = new QLabel(this);
    textBox -> setTextFormat(Qt::RichText);
    textBox -> setText("<p>our text box.</p><h1>testing md</h1>");
}

window::~window() {}
