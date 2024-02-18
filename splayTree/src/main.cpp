#include <iostream>
#include "splayTree.h"

int main()
{
    SplayTree::Tree<int>* tree = new SplayTree::Tree<int>();
    tree->Insert(1);
    std::cout << tree->GetRoot()->GetData() << std::endl;
    std::cout << tree->GetRoot()->RightRotate()->GetData() << std::endl;;
}