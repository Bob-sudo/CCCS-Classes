#include <iostream>
#include <cstring>

void longest_common_substring(const char * x, const char * y, char * z)
{
  int x_len = strlen(x);
  int y_len = strlen(y);
  
  int best_len = 0;
  int best_start = 0;
  
  for(int i = 0; i < x_len; i++)
  {
      for(int j = 0; j < y_len; j++)
      {
          int k = 0;
          
          while(i + k < x_len &&
                i + k < y_len &&
                x[i + k] == y[j + k])
          {
              k++;
          }
          
          if (k > best_len)
          {
              best_len = k;
              best_start = i;
          }
      }
  }
  for(int i = 0; i < best_len; i++)
      z[i] = x[best_start + i];
  z[best_len] = '\0';
}

void test(const char * x, const char * y)
{
    char z[1024];
    std::cout << "Test [" << x << "] " << "[" << y << "]: ";
    longest_common_substring(x, y, z);
    std::cout << "[" << x << "] "
              << "[" << y << "] "
              << "[" << z << "]\n";
}

int main()
{
    test("abc", "def");
    test("", "def");
    test("abc", "");
    test("abc", "abc");
    test("abc", "Abc");
    test("Abc", "abc");
    test("abC", "abc");
    test("abc", "abC");
    test("abcd", "AbcD");
    test("AbcD", "abcd");
    test("abcd", "AAAAAAbcD");
    test("AAAAAAbcD", "abcd");
    test("abcd", "AAAAAAbcDDDDDDD");
    test("abcd", "AAAAAAbcDDDDDDD");
    test("AAAAAAbcDDDDDDD", "abcd");
    test("abcd", "AabAabAAabcDDDDDabcdDD");
    test("AabAabAAabcDDDDDabcdDD", "abcd");
    test("abcd", "AabcdAAAabcDDDDDabdDaD");
    test("abcd", "AAAAAAbcDDDDabDDD");
    test("abcd", "AAAAAAbcdDDDDabcDDD");
    test("AAAAAAbcdDDDDabcDDD", "!!!!!!!abcd@@@@@@@");
    test("hello world", "Hello world");
    test("Hello world", "hello world");

    return 0;
}
