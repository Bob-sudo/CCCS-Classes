#include "TreeNodev.h"
#include <iostream>
#include <fstream>
#include <string>

void build(TreeNodev<char>* root)
{
    int size = 0;
    std::string word;
    
    std::ifstream fin("words.txt");
    if(!fin)
    {
        std::cerr << "Error opening file" << '\n';
        return;
    }

    while(std::getline(fin, word))
    {
        if(word.empty())
            continue;

        TreeNodev<char>* curr = root;

        for(int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            if(curr->child(index) != NULL)
            {
                curr = curr->child(index);
            }
            else
            {
                size++;
                curr->insert(index, word[i]);
                curr = curr->child(index);
            }
        }
        if(curr->child(26) == NULL)
        {
            curr->insert(26, '*');
        }
    }
    std::cout << size << '\n';
}

void collect_suffix(TreeNodev<char>* node,
             std::string& current,
             std::vector<std::string>& result)
{
    if(node->child(26) != NULL)
    {
        result.push_back(current);
    }

    for(int i = 0; i < 26; ++i)
    {
        TreeNodev<char>* child = node->child(i);
        
        if(child != NULL)
        {
            char letter = 'a' + i;
            
            current.push_back(letter);
            collect_suffix(child, current, result);
            current.pop_back();
        }
    }
}

void search(TreeNodev<char>* root, std::string word)
{
    TreeNodev<char>* curr = root;
    int i = 0;

    while(i < word.size())
    {
        int index = word[i] - 'a';

        // word does not exist
        if(curr->child(index) == NULL)
        {
            std::cout << '?' << word << '\n';
            return;
        }
        
        curr = curr->child(index);

        i++;
    }

    // word does exist
    if(curr->child(26) != NULL)
    {
        std::cout << '*' << word << '\n';
        return;
    }


    // find suffixes
    std::string current;
    std::vector<std::string> result;

    collect_suffix(curr, current, result);

    std::cout << '+' << word << ':';

    for(int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i];

        if(i < result.size() - 1)
            std::cout << ',';
    }

    std::cout << '\n';
}

int main(int argc, char* argv[])
{
    std::string input = argv[1];
    
    TreeNodev<char>* root = new TreeNodev<char>(' ');
    
    build(root);

    search(root, input);
    
    return 0;
}
