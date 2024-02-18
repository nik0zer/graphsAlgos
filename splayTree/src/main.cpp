#include <iostream>
#include "splayTree.h"

int main()
{
    SplayTree::Tree<int>* tree = new SplayTree::Tree<int>();
    tree->Insert(1);
    std::cout << tree->GetRoot() << std::endl;
}