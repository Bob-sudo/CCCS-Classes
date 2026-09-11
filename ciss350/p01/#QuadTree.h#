#ifndef QUADTREE_H
#define QUADTREE_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Ball.h"
#include "Surface.h"

struct Point
{
    double x_, y_;
    
    Point(double x, double y)
    {
        x_ = x;
        y_ = y;
    }
    Point()
    {
        x_ = 0;
        y_ = 0;
    }
};

class Node
{
  public:
    Node(Node* p = NULL)
    {
        Parent = p;
        NE = NULL;
        NW = NULL;
        SW = NULL;
        SE = NULL;
        topLeft.x_ = 0;
        topLeft.y_ = 0;
        bottomRight.x_ = W;
        bottomRight.y_ = H;
        divided = false;
    }

    bool contains(Ball*);
    void subdivide();
    bool isLeaf();

    void clear(Node*);
    
    Point topLeft;
    Point bottomRight;

    bool divided;
    std::vector<Ball*> balls;

    Node* Parent;
    Node* NE;
    Node* NW;
    Node* SW;
    Node* SE;
};

std::ostream & operator<<(std::ostream &, const Node &);
void print_inorder(const Node*);

class QuadTree
{
  public:
    QuadTree()
        : root_(NULL)
    {}

    ~QuadTree()
    {
        clear();
    }
    
    void insert(Node*, Ball*, int);
    void clear();

    Node* root_;
    const int capacity = 8;
    const int max_height = 8;
};

void print_inorder(const QuadTree &);

void drawNode(Node*, Surface&);

#endif
