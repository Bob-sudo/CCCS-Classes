#ifndef FIB3_H
#define FIB3_H

class Fib3
{
  public:
    int operator()(int n);
    static int lookup(int n);
    static void init();
    
  private:
    static int table[20];
    static bool is_init; // check if initialized
};

#endif
