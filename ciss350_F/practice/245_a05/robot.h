#ifndef ROBOT_H
#define ROBOT_H

class Robot
{
  public:
    Robot(Robot &r, char name, int x, int y, int energylevel)
        : r_(r), name_(name), x_(x), y_(y), energylevel_(energylevel)
    {}
    
    void print(const Robot &);
    void move_north(Robot &);
    void move_south(Robot &);
    void move_east(Robot &);
    void move_west(Robot &);
    void inc_energylevel(Robot &, int);
    
  private:
    Robot& r_;
    char name_;
    int x_, y_, energylevel_;    
};

#endif
