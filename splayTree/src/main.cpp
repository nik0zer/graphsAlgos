#include <iostream>
#include "splayTree.h"


int main()
{
    std::ofstream fout("1.txt");
    SplayTree::Tree<int>* tree = new SplayTree::Tree<int>();
    SplayTree::Tree<int>* tree1 = new SplayTree::Tree<int>();
    SplayTree::Tree<int>* tree2 = new SplayTree::Tree<int>();
    tree->TestInsert(13);
    tree->TestInsert(11);
    tree->TestInsert(12);
    tree->TestInsert(10);
    tree->TestInsert(16);
    tree->TestInsert(17);
    tree->TestInsert(14);
    
    tree1->TestInsert(5);
    tree1->TestInsert(6);
    tree1->TestInsert(4);
    fout<<std::endl;
    std::ofstream fout1("2.txt");
    tree->GetRoot()->GraphvizPrintStart(fout, "bb");
    
    std::ofstream fout2("3.txt");
    auto pair = tree->Split(16);
    pair.first->GraphvizPrintStart(fout1, "bb");
    pair.second->GraphvizPrintStart(fout2, "bb");
    // pair.first->GraphvizPrintStart(fout1, "AA");
    // pair.second->GraphvizPrintStart(fout2, "CC");
    // fout1<<std::endl;
    // tree1->GetRoot()->GraphvizPrintStart(fout, "AA");
    // tree2->SetRoot(SplayTree::Tree<int>::Merge(tree1->GetRoot(), tree->GetRoot()));
    // tree2->GetRoot()->GraphvizPrintStart(fout2, "cc");
    fout.close();
    fout1.close();
    fout2.close();
    delete tree;
    delete tree1;
    delete tree2;
}