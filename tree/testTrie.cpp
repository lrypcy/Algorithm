#include "trie.h"
#include <iostream>
int main()
{
    auto temp=new Trie();
    temp->insert("jsjls");
    std::cout<<temp->search("sjfas");
    std::cout<<temp->search("jsjls");
}
