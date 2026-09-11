#ifndef INTPOINTER_H
#define INTPOINTER_H

class IntPointer
{
  public:
    IntPointer();
    int dereference() const;
    int operator*() const;
    int & operator*();
  private:
    int * p_;
};

#endif
