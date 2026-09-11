#include <iostream>

char coin_toss()
{
    return (rand() % 2 == 0 ? 'H' : 'T');
}

int coin_toss_avg(int len[], const int SIZE)
{
    int total_len;
    for(int i = 0; i < SIZE; i++)
    {
        total_len += len[i];
    }
    return total_len / SIZE;
}

int die_roll()
{
    return rand() % 6 + 1;
}

char robot_dir()
{
    if(rand() % 4 == 0)
        return 'N';
    if(rand() % 4 == 1)
        return 'E';
    if(rand() % 4 == 2)
        return 'S';
    else
        return 'W';
    
}

int main()
{
    //COIN TOSS
    
    std::cout << "COIN TOSS: " << '\n';
    
    srand((unsigned int) time(NULL));
    int count = 0;
    
    while(count < 3)
    {
        char coin = coin_toss();
        std::cout << coin << ' ';
        if(coin == 'H')
            ++count; 
        else
            count = 0;
    }
    std::cout << '\n';

    //AVG TRIPLE HEAD COIN TOSS

    std::cout << "AVG # OF TOSSES FOR # HEADS IN A ROW: " << '\n';
    const int SIZE = 1000;
    int len[SIZE] = {0};
    for(int i = 0; i < SIZE; i++)
    {
        count = 0;
        while(count < 3)
        {
            char coin = coin_toss();
            if(coin == 'H')
                ++count;
            else
                count = 0;
            len[i] += 1;
        }
    }
    std::cout << coin_toss_avg(len, SIZE) << '\n';

    //DIE ROLL

    std::cout << "DIE ROLL: " << '\n';

    count = 0;
    while(count < 10)
    {
        int die = die_roll();
        std::cout << die << ' ';
        ++count;
    }
    std::cout << '\n';

    //GAMBLING GAME
    
    std::cout << "YOU'RE GAMBLING AGAIN AREN'T YOU?" << '\n'
              << "WELL, ASSUMING YOU ALREADY KNOW THE RULES" << '\n'
              << "HERE'S HOW MUCH MONEY YOU WOULD EARN ON AVG:" << '\n';
    
    double money_earned = 0;
    for(int i = 0; i < SIZE; i++)
    {
        --money_earned;
        int die = die_roll();
        if(die % 2 == 1)
        {
            if(die == 1)
                money_earned += 2;
            else
                money_earned -= 0.5;
        }
        else
        {
            if(die == 2)
                ++money_earned;
            else
                money_earned -= 0.75;  
        }   
    }
    std::cout << "TOTAL MONEY EARNED: " << '$' << money_earned << '\n';
    std::cout << "AVG EARNINGS PER ROUND: "
              << '$' << money_earned / SIZE << '\n';

    //GAMBLING GAME (TWEAKED RULES)
    std::cout << "WE TWEAKED THE RULES A LITTLE BIT" << '\n'
              << "MAYBE YOU'LL WIN THIS TIME" << '\n';

    money_earned = 0;
    for(int i = 0; i < SIZE * 10; i++)
    {
        --money_earned;
        int die = die_roll();
        if(die % 2 == 1)
        {
            if(die == 1)
                money_earned += 2;
            else
            {
                char coin = coin_toss();
                (coin == 'H' ? ++money_earned : --money_earned);
            }
        }
        else
        {
            //reroll
            int temp_die = die_roll();
            if(temp_die == die)
                money_earned += 3;
            else
                (temp_die % 2 == 0 ? money_earned -= 0.5 : money_earned -= 0.1);
        }   
    }
    std::cout << "TOTAL MONEY EARNED: " << '$' << money_earned << '\n';
    std::cout << "AVG EARNINGS PER ROUND: "
              << '$' << money_earned / (SIZE * 10)<< '\n';

    //MOVING ROBOT

    std::cout << "MOVING ROBOT: " << '\n';

    int steps = 0;
    std::cin >> steps;
    for(int i = 0; i < steps; i++)
    {
        char robot = robot_dir();
        std::cout << robot << ' ';
    }
    std::cout << '\n';
    
    
    return 0;
}

