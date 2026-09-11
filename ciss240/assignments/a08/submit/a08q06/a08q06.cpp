//File: a08q06.cpp
//Name: Ethan Graham

#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int longest_seq = 0, current_seq = 0, prev_digit = -1, digit, longest_length = 0, current_length = 0, temp = n;             

    while (temp > 0)
    {
        digit = temp % 10;
        temp /= 10;

        //reverse the sequence
        if (prev_digit == -1 || digit == prev_digit - 1)
        {
            current_seq = digit + current_seq * 10;
            current_length++;
        }
        else
        {
            //longest sequence
            if (current_length > longest_length)
            {
                longest_seq = current_seq;
                longest_length = current_length;
            }
            //Reset current sequence
            current_seq = digit;
            current_length = 1;
        }

        prev_digit = digit;
    }

    //Final comparison
    if (current_length > longest_length)
    {
        longest_seq = current_seq;
        longest_length = current_length;
    }

    //display in correct order
    int reversed_seq = 0;
    while (longest_seq > 0)
    {
        reversed_seq = reversed_seq * 10 + longest_seq % 10;
        longest_seq /= 10;
    }

    std::cout << reversed_seq << std::endl;

    return 0;
}
