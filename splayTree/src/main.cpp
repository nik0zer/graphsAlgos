#include <iostream>
#include "splayTree.h"

int main()
{
    SplayTree::Tree<int>* tree = new SplayTree::Tree<int>();
    tree->TestInsert(1);
    tree->TestInsert(-1);
    tree->TestInsert(-2);
    tree->TestInsert(0);
    tree->TestInsert(2);
    tree->GetRoot()->PrintPreOrderDFS();
    std::shared_ptr<SplayTree::Node<int>> new_root = tree->GetRoot()->RightRotate();
    std::cout<<std::endl;
    new_root->PrintPreOrderDFS();
    std::cout<<std::endl;
    auto new_new_root = new_root->_right_node->_left_node;
    new_new_root->Splay();
    std::cout<<"AAAAA"<<std::endl;
    // new_new_root->PrintPreOrderDFS();
    delete tree;
}