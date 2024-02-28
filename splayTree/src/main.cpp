#include <iostream>
#include "splayTree.h"


int main()
{
    std::ofstream fout("1.txt");
    SplayTree::Tree<int>* tree = new SplayTree::Tree<int>();
    SplayTree::Tree<int>* tree1 = new SplayTree::Tree<int>();
    SplayTree::Tree<int>* tree2 = new SplayTree::Tree<int>();
    tree->Insert(13);
    tree->Insert(11);
    tree->Insert(12);
    tree->Insert(10);
    tree->Insert(16);
    tree->Insert(17);
    tree->Insert(14);
    
    tree1->Insert(5);
    tree1->Insert(6);
    tree1->Insert(4);
    fout<<std::endl;
    std::ofstream fout1("2.txt");
    tree->GetRoot()->GraphvizPrintStart(fout, "bb");
    
    std::ofstream fout2("3.txt");
    tree->Find(12);
    tree->GetRoot()->GraphvizPrintStart(fout1, "bb");
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