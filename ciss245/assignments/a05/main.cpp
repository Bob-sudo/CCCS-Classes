// File: main.cpp
// Name: Ethan Graham

#include <iostream>
#include <cstdlib>
#include "Robot.h"
#include "world.h"
#include "PowerStation.h"

void move_robot(Robot r)
{
    srand((unsigned int) time(NULL));
    int dir = rand() % 4;
    if (dir == 0) move_north(r); // North
    else if (dir == 1) move_south(r); // South
    else if (dir == 2) move_east(r); // East
    else if (dir == 3) move_west(r); // West
}

void test_print()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    r_init(r, name, x, y, energylevel);
    print(r);
    return;
}

void test_move_north()
{ 
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    r_init(r, name, x, y, energylevel);
    move_north(r);
    print(r);
    return;
}

void test_move_south()
{ 
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    r_init(r, name, x, y, energylevel);
    move_south(r);
    print(r);
    return;
}

void test_move_east()
{ 
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    r_init(r, name, x, y, energylevel);
    move_east(r);
    print(r);
    return;
}

void test_move_west()
{ 
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    r_init(r, name, x, y, energylevel);
    move_west(r);
    print(r);
    return;
}

void test_inc_energylevel()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    r_init(r, name, x, y, energylevel);
    int i;
    std::cin >> i;
    inc_energylevel(r, i);
    print(r);
    return;
}

void test_dec_energylevel()
{
    char name;
    int x, y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    r_init(r, name, x, y, energylevel);
    int i;
    std::cin >> i;
    dec_energylevel(r, i);
    print(r);
    return;
}

void test_init_and_print_world()
{
    char world[10][10];
    init(world);
    print(world);
}

void test_set()
{
    char world[10][10];
    init(world);
    int x = 0;
    int y = 0;
    char c = ' ';
    std::cin >> x >> y >> c;
    set(world, x, y, c);
    print(world);
}

void test_clear()
{
    char world[10][10];
    init(world);
    print(world);
    int x = 0;
    int y = 0;
    std::cout << '\n' << "Clear World..." << '\n' << '\n';
    clear(world, x, y);
    print(world);
}

void test_occupy()
{
    char world[10][10];
    init(world);
    print(world);
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(is_occupied(world, j, i))
            {
                std::cout << "Is occupied at: " << i << ", " << j << '\n';
            }
            else
            {
                std::cout << "Is unoccupied at: " << i << ", " << j << '\n';
            }
        }
    }
}

void test_init_and_print_power_station()
{
    int x = 0, y = 0;
    int energylevel;
    std::cin >> x >> y >> energylevel;
    PowerStation ps;
    init(ps, x, y, energylevel);
    print(ps);
}

void play()
{
    srand((unsigned int) time(NULL));
        
    // Build World
    char world[10][10];
    init(world);

    // Create PowerStations
    PowerStation ps1, ps2, ps3;
    place_power_station(world, ps1);
    place_power_station(world, ps2);
    place_power_station(world, ps3);

    //build robots
    Robot c, d, r;
    place_robot(world, c, 'c');
    place_robot(world, d, 'd');
    place_robot(world, r, 'r');

    int time = 100;
    while (time > 0)
    {
        print(world);
        
        // Check if robot has found gold
        // If so break
        if(found_gold(world, c))
        {
            std::cout << "c Found Gold!!!" << '\n';
            std::cout << "c energy level: " << c.energylevel << '\n';
            break;
        }
        if(found_gold(world, d))
        {
            std::cout << "d Found Gold!!!" << '\n';
            std::cout << "d energy level: " << d.energylevel << '\n';
            break;
        }
        if(found_gold(world, r))
        {
            std::cout << "r Found Gold!!!" << '\n';
            std::cout << "r energy level: " << r.energylevel << '\n';
            break;
        }

        // Move each robot randomly
        move(world, c, 'c');
        move(world, d, 'd');
        move(world, r, 'r');
        // For each powerstation check which robots are adjacent
        energy_transfer(world, c, ps1);
        energy_transfer(world, d, ps1);
        energy_transfer(world, r, ps1);
        energy_transfer(world, c, ps2);
        energy_transfer(world, d, ps2);
        energy_transfer(world, r, ps2);
        energy_transfer(world, c, ps3);
        energy_transfer(world, d, ps3);
        energy_transfer(world, r, ps3);

        time--;
    }
}

int main()
{
    //int seed;
    //std::cin >> seed;
    //srand(seed);
    
    int option = 0;
    std::cin >> option;
    switch (option)
    {
        case 1:
            test_print();
            break;
        case 2:
            test_move_north();
            break;
        case 3:
            test_move_south();
            break;
        case 4:
            test_move_east();
            break;
        case 5:
            test_move_west();
            break;
        case 6:
            test_inc_energylevel();
            break;
        case 7:
            test_dec_energylevel();
            break;
        case 8:
            test_init_and_print_world();
            break;
        case 9:
            test_set();
            break;
        case 10:
            test_clear();
            break;
        case 11:
            test_occupy();
            break;
        case 12:
            test_init_and_print_power_station();
            break;
        case 13:
            play();
            break;
    }
    
    return 0;
}
