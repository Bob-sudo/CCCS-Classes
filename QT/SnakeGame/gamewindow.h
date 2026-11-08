#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtCore>
#include <QtWidgets>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private slots:
    void gameloop();

private:
    Ui::GameWindow *ui;

    enum Direction
    {
        Up,
        Down,
        Left,
        Right,
    };

    QVector<QPoint> snake;
    QPoint food;
    Direction direction;
    QTimer *timer;

    int cellsize;
    int rows;
    int cols;

    bool gameover;

    void moveSnake();
    void spawnFood();
    void checkCollision();

protected:
    void paintEvent(QPaintEvent *) override;
    void keyPressEvent(QKeyEvent *event) override;

};
#endif // GAMEWINDOW_H
