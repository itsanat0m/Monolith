#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QLabel>

class QLabel;
class window : public QWidget
{
    Q_OBJECT

public:
    explicit window(QWidget *parent = nullptr);
    ~window();

public:
    QLabel *textBox;

};
#endif // WINDOW_H
