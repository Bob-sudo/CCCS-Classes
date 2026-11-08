#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

#include <QtCore>
#include <QtWidgets>
#include <QtGui>

#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

    void place_gate();

private slots:
    void loop();

private:
    Ui::Window *ui;

    enum Color
    {
        Red,
        Yellow,
        Blue,
        Green,
    };

    QVector<QPoint> gate;
    QRect gaterect;
    bool hasgate;
    Color color;


    int cellsize;
    int rows;
    int cols;

protected:
    void paintEvent(QPaintEvent *) override;
    void keyPressEvent(QKeyEvent *event) override;

};
#endif // WINDOW_H
