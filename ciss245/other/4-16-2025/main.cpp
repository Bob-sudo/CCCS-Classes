#include <iostream>
#include <string>

class LivingThing
{
public:
    LivingThing(const std::string & name, int x)
        : name_(name), x_(x)
    {}
    void walk()
    {}
private:
    std::string name_;
    int x_;
};

class Man: public LivingThing
{
public:
    Man(std::string name, int x, std::string jobtitle)
        : LivingThing(name, x), jobtitle_(jobtitle)
    {}
    /*
    void walk()
    {
        x_++;
    }
    */
private:
    std::string jobtitle_;
};

class Dog: public LivingThing
{
public:
    Dog(const std::string & name, int x)
    : LivingThing(name, x)
    {}
    /*
    void walk()
    {
        x_--;
    }
    */
private:
    // Man * powner;
};

class P
{
public:
    virtual void f()
    {
        std::cout << "P::f()\n";
    }
};

class C: public P
{
public:
    void f()
    {
        std::cout << "C::f()\n";
    }
};

int main()
{
    Man john("John", 5, "CEO of McDonalds");
    Man tom("Tom", 10, "Software engineer");
    Dog rex("Rex", 8);

    Man * men[2];
    men[0] = new Man("John", 5, "CEO");
    men[1] = new Man("Tom", 10, "Software engineer");

    Dog * dogs[2];
    dogs[0] = new Dog("Rex", 10);
    dogs[1] = new Dog("Goldie", 12);

    P * p = new C();
    p -> f();
    while (1)
    {
        //john.walk();
        //tom.walk();

        //for(int i = 0; i < 2; i++) men[i] -> walk();
        //for(int i = 0; i < 2; i++) dogs[i] -> walk();
        
        rex.walk();

        // *.talk();

        // *.sleep();
        break;
    }

    return 0;
}
