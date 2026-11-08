#include "window.h"
#include "./ui_window.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);

    setFixedSize(600, 600); // setting up window size

    setFocusPolicy(Qt::StrongFocus);

    cellsize = 20;
    rows = height() / cellsize;
    cols = width() / cellsize;

    color = Red;
}

void Window::loop()
{

}

void Window::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(rect(), Qt::black);

    for(int i = 0; i < gate.size(); i++)
    {
        if(hasgate)
        {
            painter.fillRect(rect(), Qt::red);

            painter.setPen(Qt::NoPen);
        }
    }
}

void Window::keyPressEvent(QKeyEvent *event)
{
    switch(event)
    {
    case Qt::Key_1:
        color = Red;
        break;
    case Qt::Key_2:
        color = Yellow;
        break;
    case Qt::Key_3:
        color = Blue;
        break;
    case Qt::Key_4:
        color = Green;
        break;
    }
}

Window::~Window()
{
    delete ui;
}

void Window::place_gate()
{
    QPoint center = mapFromGlobal(QCursor::pos());

    painter.drawRoundedRect(gate[i].x() * width / 2,
                            gate[i].y() * height / 2,
                            width, height, 5, 5);

    hasgate = true;

    update();
}
