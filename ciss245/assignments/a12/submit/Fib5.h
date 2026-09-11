#ifndef FIB5_H
#define FIB5_H

class Fib5
{
  public:
    static Fib5 fib5;
    int operator()(int n) const;
    static int lookup(int n);
    static void resize(int new_size);
  private:
    Fib5();
    Fib5(const Fib5&);

    static void init(int new_size);
    
    static bool is_init;
    static int size;
    static int * table;
};

#endif
