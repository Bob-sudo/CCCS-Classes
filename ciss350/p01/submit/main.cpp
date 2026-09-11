/****************************************************************************
 Yihsiang Liow
 Copyright
 ****************************************************************************/
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <chrono>

#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"

#include "Ball.h"
#include "QuadTree.h"

void build_tree(Node* node)
{
    node->topLeft.x_ = 0;
    node->topLeft.y_ = 0;
    node->bottomRight.x_ = W;
    node->bottomRight.y_ = H;
}

bool collision(const Ball& a, const Ball& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double distSquared = dx * dx + dy * dy;

    double r = a.radius + b.radius;

    return distSquared < r * r;
}

void pair_collision(std::vector<Ball*>& balls, int num)
{
    for(int i = 0; i < num; i++)
        {
            for(int j = i + 1; j < num; j++)
            {
                if(collision(*balls[i], *balls[j]))
                {
                    // bounce balls if they collide
                    balls[i]->collideWith(*balls[j]);
                    balls[i]->collided = true;
                    balls[j]->collided = true;
                }
            }
        }
}

void quad_collision(Node* node)
{
    if(node == NULL) return;

    if(!node->balls.empty())
    {
        pair_collision(node->balls, node->balls.size());
    }
    else
    {
        quad_collision(node->NE);
        quad_collision(node->NW);
        quad_collision(node->SE);
        quad_collision(node->SW);
    }
}

void main_prog()
{
    Surface surface(W, H);
    Event event;
    Keyboard kbd(event);
    double FPS = 0.0;

    // ----------- Balls ----------- //
    
    int NUM_BALLS = 100;
    std::vector<Ball*> balls;
    
    for(int i = 0; i < NUM_BALLS; i++)
    {
        balls.push_back(new Ball());
    }

    // ----------------------------- //
 
    
    // ---------- QuadTree --------- //

    QuadTree quad;
    quad.root_ = new Node();

    // ----------------------------- //

    bool quad_compare = true;

    // make window
    while(1)
    {
        // start FPS timer
        clock_t start = clock();
        
        // Process all inputs
        if (event.poll())
        {
            if (event.type() == QUIT) break;
            else if (event.type() == KEYDOWN || event.type() == KEYUP)
            {
                kbd.update(event);
            }

            if(kbd.keypressed(SPACE)) quad_compare = !quad_compare;
        }
        if (kbd.keypressed(LEFTARROW))
        {
            NUM_BALLS -= 10;
            if(NUM_BALLS <= 0)
                NUM_BALLS = 1;
        }
        else if (kbd.keypressed(DOWNARROW))
        {
            NUM_BALLS -= 100;
            if(NUM_BALLS <= 0)
                NUM_BALLS = 1;
        }
        else if (kbd.keypressed(RIGHTARROW))
            NUM_BALLS += (NUM_BALLS == 1 ? 9 : 10);
        else if (kbd.keypressed(UPARROW))
            NUM_BALLS += (NUM_BALLS == 1 ? 99 : 100);
        
        // update number of balls
        
        // Increase balls
        while(balls.size() < NUM_BALLS)
        {
            balls.push_back(new Ball());
        }

        // Decrease balls
        while(balls.size() > NUM_BALLS)
        {
            delete balls.back();
            balls.pop_back();
        }

        // Draw background
        surface.lock();
        surface.fill(BLACK);

        // Move/Bounce Balls
        for(int i = 0; i < NUM_BALLS; i++)
        {
            balls[i]->move();
            balls[i]->bounce(W, H);
        }

        if(quad_compare)
        {
            // Delete tree
            quad.clear();

            // Rebuild tree
            quad.root_ = new Node();
        
            // insert balls into nodes
            for(int i = 0; i < NUM_BALLS; i++)
            {
                quad.insert(quad.root_, balls[i], 0);
            }

            // Draw quadtree borders
            drawNode(quad.root_, surface);
        }

        // Reset all collisions to false
        for(int i = 0; i < NUM_BALLS; i++)
        {
            balls[i]->collided = false;
        }

        // Check if any balls collide

        // Pairwise Collision
        if(!quad_compare)
            pair_collision(balls, NUM_BALLS);

        // QuadTree Collision
        if(quad_compare)
            quad_collision(quad.root_);

        // Draw Balls
        for(int i = 0; i < NUM_BALLS; i++)
        {
            if (balls[i]->collided)
            {
                surface.put_circle(balls[i]->x,
                                   balls[i]->y,
                                   balls[i]->radius,
                                   255, 0, 0);
            }
            else
            {
                surface.put_circle(balls[i]->x,
                                   balls[i]->y,
                                   balls[i]->radius,
                                   255, 255, 255);
            }
        }

        // Ball Counter
        surface.put_text("Balls:", 500, 0, 0, 255, 17, "fonts/FreeSansBold.ttf", 20);
        surface.put_text(std::to_string(NUM_BALLS).c_str(), 560, 0, 0, 255, 17, "fonts/FreeSansBold.ttf", 20);

        // FPS counter
        surface.put_text("FPS:", 200, 0, 0, 255, 17, "fonts/FreeSansBold.ttf", 20);
        surface.put_text(std::to_string((int)FPS).c_str(), 260, 0, 0, 255, 17, "fonts/FreeSansBold.ttf", 20);
        
        // Show everything on the screen
        surface.unlock();
        surface.flip();

        // End timer
        clock_t end = clock();
        double time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC; // ms
        
        if (time > 0.1)
        {
            double frameFPS = 1000.0 / time;
            FPS = frameFPS;
        }
    }

    // castration
    for(int i = 0; i < NUM_BALLS; i++)
    {
        delete balls[i];
    }
}

int main(int argc, char* argv[])
{
    std::cout << "hello world" << '\n';

    main_prog();
    
    return 0;
}
