#ifndef QTWIDGET_H
#define QTWIDGET_H

#include <QWidget>
#include <QSlider>
#include"QDial"
#include "QScrollBar"
#include "QProgressBar"
#include "QPushButton"

class QtWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QtWidget(QWidget *parent = nullptr);

signals:

public slots:

private slots:
    void up();
    void down();
    void reset();

private:
    QSlider *myQSlider;
    QDial *myQDial;
    QScrollBar *myQScrollBar;
    QProgressBar *myQProgressBar;

    QPushButton *myUpButton;
    QPushButton *myDownButton;
    QPushButton *myResetButton;

};

#endif // QTWIDGET_H
