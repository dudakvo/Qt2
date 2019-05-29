#include "qtwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

QtWidget::QtWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *lHBoxLayout = new QHBoxLayout;
    QHBoxLayout *lHBoxLayout2 = new QHBoxLayout;
    QHBoxLayout *lHBoxLayout3= new QHBoxLayout;
    QHBoxLayout *lHBoxLayout4= new QHBoxLayout;
    QVBoxLayout *lVBoxLayout = new QVBoxLayout;

    myUpButton = new QPushButton("Up");
    myDownButton = new QPushButton("Down");
    myResetButton = new QPushButton("Reset");

    myQSlider = new QSlider;
    myQSlider->setOrientation(Qt::Horizontal);
    myQSlider->setValue(42);

    myQDial =new QDial;
    myQDial->setRange(0,100);
    myQDial->setValue(42);

    myQScrollBar = new QScrollBar;
    myQScrollBar->setFixedSize(15,100);
    myQScrollBar->setRange(0,100);
    myQScrollBar->setValue(42);

    myQProgressBar = new QProgressBar;
    myQProgressBar->setOrientation(Qt::Horizontal);
    myQProgressBar->setRange(0,100);
    myQProgressBar->setValue(42);

    lHBoxLayout->addWidget(myQProgressBar);

    lHBoxLayout2->addWidget(myQScrollBar);
    lHBoxLayout2->addWidget(myQDial);

    lHBoxLayout->addWidget(myUpButton);
    lHBoxLayout2->addWidget(myDownButton);

    lHBoxLayout3->addWidget(myResetButton);
    lHBoxLayout4->addWidget(myQSlider);

    lVBoxLayout->addLayout(lHBoxLayout);
    lVBoxLayout->addLayout(lHBoxLayout2);
    lVBoxLayout->addLayout(lHBoxLayout3);
    lVBoxLayout->addLayout(lHBoxLayout4);

    connect(myQDial, SIGNAL(valueChanged(int)), myQProgressBar, SLOT(setValue(int)));
    connect(myQDial, SIGNAL(valueChanged(int)), myQScrollBar, SLOT(setValue(int)));
    connect(myQDial, SIGNAL(valueChanged(int)), myQSlider, SLOT(setValue(int)));

    connect(myResetButton, SIGNAL(clicked()), this, SLOT(reset()));
    connect(myUpButton, SIGNAL(clicked()), this, SLOT(up()));
    connect(myDownButton, SIGNAL(clicked()), this, SLOT(down()));

    connect(myQScrollBar, SIGNAL(valueChanged(int)), myQProgressBar, SLOT(setValue(int)));
    connect(myQScrollBar, SIGNAL(valueChanged(int)), myQDial, SLOT(setValue(int)));
    connect(myQDial, SIGNAL(valueChanged(int)), myQSlider, SLOT(setValue(int)));

    connect(myQSlider, SIGNAL(valueChanged(int)), myQProgressBar, SLOT(setValue(int)));
    connect(myQSlider, SIGNAL(valueChanged(int)), myQDial, SLOT(setValue(int)));
    connect(myQSlider, SIGNAL(valueChanged(int)), myQScrollBar, SLOT(setValue(int)));

    setLayout(lVBoxLayout);
    setWindowTitle("My Parent Widget");
}

void QtWidget::up()
{
    int positionValue = myQProgressBar->value();
    if(positionValue!=100)
    {
        myQProgressBar->setValue(positionValue+5);
        myQSlider->setValue(positionValue+5);
        myQDial->setValue(positionValue+5);
        myQScrollBar->setValue(positionValue+5);
    }
}

void QtWidget::down()
{
    int positionValue = myQProgressBar->value();
    if(positionValue!=0)
    {
        myQProgressBar->setValue(positionValue-5);
        myQSlider->setValue(positionValue-5);
        myQDial->setValue(positionValue-5);
        myQScrollBar->setValue(positionValue-5);
    }
}

void QtWidget::reset()
{
    myQProgressBar->setValue(0);
    myQSlider->setValue(0);
    myQDial->setValue(0);
    myQScrollBar->setValue(0);
}
