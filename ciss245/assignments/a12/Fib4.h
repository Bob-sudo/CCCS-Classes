#ifndef FIB4_H
#define FIB4_H

class Fib4
{
  public:
    Fib4();
    Fib4(int new_size);
    int operator()(int n);
    static int lookup(int n);
    
  private:
    static int * table;
    static bool is_init; // check if initialized
    static void init(int new_size);
    static int size;
};

#endif
