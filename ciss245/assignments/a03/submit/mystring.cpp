// File: mystring.cpp
// Name: Ethan Graham

#include "mystring.h"
#include <iostream>

int str_len(char x[])
{
    int len = 0;
    while (x[len] != '\0')
    {
        ++len;
    }

    return len;
}

void str_cat(char x[], char y[])
{
    int xlen = str_len(x);
    int ylen = str_len(y);

    for (int i = 0; i <= ylen; ++i)
    {
        x[xlen + 1] = y[i];
    }

    return;
}

int str_cmp(char x[], char y[])
{
    if (str_len(x) == str_len(y))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void str_cpy(char x[], char y[])
{
    for (int i = 0; i < 1024; i++)
    {
        x[i] = y[i];
    }
}

int str_chr(char x[], char c)
{
    int count = 0;
    
    while(count < 1024 && x[count] != '\0')
    {
        if(x[count] == c)
        {
            return count;
        }
        else count++;
    }

    return -1;
}

int str_str(char x[], char y[])
{
    int xlen = str_len(x);
    int ylen = str_len(y);

    if (ylen == 0)
    {
        return 0;
    }

    for (int i = 0; i <= xlen - ylen; ++i)
    {
        int j = 0;
        
        while (j < ylen && x[i + j] == y[j])
        {
            ++j;
        }
        
        if (j == ylen)
        {
            return i;
        }
    }

    return -1;
}

void str_lower(char x[], char y[])
{
    int i = 0;
    while (y[i] != '\0')
    {
        if (y[i] >= 'A' && y[i] <= 'Z')
        {
            x[i] = y[i] + ('a' - 'A');
        }
        else
        {
            x[i] = y[i];
        }
        ++i;
    }
}

bool str_tok(char x[], char y[], char delimiters[])
{
    int n = 0;
    x[0] = '\0';
    
    while(n < 1024)
    {
        // Check if there is a delimiter
        for(int i = 0; i < 1024; i++)
        {
            // If not delimiter, put y value in x
            // Need to make more efficiant
            if(y[n] != delimiters[i] && y[n] != delimiters[i + 1] && y[n] != delimiters[i + 2] && y[n] != '\0')
            {
                x[n] = y[n];
            }
            // If there is delimiter, move everthing else forward, return true
            else if(y[n] == delimiters[i] && y[n] > '\0')
            {
                for(int j = 0; j < 1024; j++)
                {
                    y[j] = y[j + n + 1];
                }
                return true;
            }
        }
        n++;
    }
    return false;
}

void str_rstrip(char x[])
{
    int end = 0;

    while(x[end] != '\0')
        end++;
    
    while(x[--end] == ' ' || x[end] == '.');

    x[end + 1] = '\0';
}

void str_capitalize(char x[])
{
    x[0] += 'A';
}

