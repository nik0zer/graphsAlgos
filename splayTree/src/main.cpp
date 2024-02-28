#include <iostream>
#include "splayTree.h"


int main()
{
    std::ofstream fout("1.txt");
    SplayTree::Tree<int>* tree = new SplayTree::Tree<int>();
    tree->TestInsert(3);
    tree->TestInsert(1);
    tree->TestInsert(2);
    tree->TestInsert(0);
    tree->TestInsert(5);
    tree->TestInsert(6);
    tree->TestInsert(4);
    tree->GetRoot()->GraphvizPrintStart(fout, "aa");
    fout<<std::endl;
    std::ofstream fout1("2.txt");
    auto new_root = tree->Find(4);
    new_root->GraphvizPrintStart(fout1, "bb");
    fout1<<std::endl;
    fout.close();
    fout1.close();
    delete tree;
}