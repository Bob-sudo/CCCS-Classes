#include "gamewindow.h"
#include "./ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    setFixedSize(600, 600); // setting up window size

    setFocusPolicy(Qt::StrongFocus);

    cellsize = 20;
    rows = height() / cellsize;
    cols = width() / cellsize;

    snake.append(QPoint(10,10));

    direction = Right;

    gameover = false;

    spawnFood();

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &GameWindow::gameloop);

    timer->start(100);

}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::gameloop()
{
    if(gameover) return;

    moveSnake();

    checkCollision();

    update();
}

void GameWindow::moveSnake()
{
    QPoint Head = snake.first();
    switch (direction)
    {
    case Up:
        Head.ry()--;
        break;
    case Down:
        Head.ry()++;
        break;
    case Left:
        Head.rx()--;
        break;
    case Right:
        Head.rx()++;
        break;
    }
    snake.prepend(Head);

    if (Head == food)
    {
        spawnFood();
    }
    else
    {
        snake.removeLast();
    }

}

void GameWindow::spawnFood()
{
    int x = QRandomGenerator::global()->bounded(cols);
    int y = QRandomGenerator::global()->bounded(rows);
    food = QPoint(x, y);
}

void GameWindow::checkCollision()
{
    QPoint Head = snake.first();

    if(Head.x() < 0 || Head.y() < 0
        || Head.x() >= cols
        || Head.y() >= rows)
    {
        gameover = true;
        timer->stop();
    }
    for (int i = 1; i < snake.size(); ++i)
    {
        if (Head == snake[i])
        {
            gameover = true;
            timer->stop();
        }
    }
}

void GameWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.fillRect(rect(), Qt::black);

    painter.setBrush(Qt::green);

    for (int i = 0; i < snake.size(); ++i)
    {
        if (i == 0)
        {
            painter.setBrush(QColor(0,255,180));
        }
        else
        {
            painter.setBrush(QColor(0,180,0));
        }

        // Draw Snake
        painter.setPen(Qt::NoPen);

        painter.drawRoundedRect(snake[i].x() * cellsize,
                                snake[i].y() * cellsize,
                                cellsize, cellsize, 5, 5);

        if(gameover)
        {
            painter.setPen(Qt::red);

            painter.setFont(QFont("Arial", 24));

            painter.drawText(rect(), Qt::AlignCenter, "GAME OVER");

            painter.drawText(rect(), Qt::AlignBottom, "Press Space");
        }
    }

    // Draw Food
    painter.setBrush(Qt::red);

    painter.drawEllipse(food.x() * cellsize,
                        food.y() * cellsize,
                        cellsize, cellsize);
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Up:
        if(direction != Down)
            direction = Up;
        break;
    case Qt::Key_Down:
        if(direction != Up)
            direction = Down;
        break;
    case Qt::Key_Left:
        if(direction != Right)
            direction = Left;
        break;
    case Qt::Key_Right:
        if(direction != Left)
            direction = Right;
        break;
    }
}
