#include <iostream>
#include "splayTree.h"


int main()
{
    std::ofstream fout("1.txt");
    SplayTree::Tree<int>* tree = new SplayTree::Tree<int>();
    tree->Insert(13);
    tree->Insert(11);
    tree->Insert(12);
    tree->Insert(10);
    tree->Insert(2);
    tree->Insert(3);
    tree->Insert(16);
    tree->Insert(17);
    tree->Insert(14);
    
    tree->Insert(5);
    tree->Insert(6);
    tree->Insert(4);
    fout<<std::endl;
    tree->GetRoot()->GraphvizPrintStart(fout, "bb");
    std::ofstream fout1("2.txt");
    std::ofstream fout3("4.txt");
    
    std::ofstream fout2("3.txt");
    tree->Find(10);
    tree->GetRoot()->GraphvizPrintStart(fout1, "bb");
    tree->Delete(13);
    tree->GetRoot()->GraphvizPrintStart(fout2, "bb");

    tree->Find(14);
    tree->GetRoot()->GraphvizPrintStart(fout3, "bb");
    fout.close();
    fout1.close();
    fout2.close();
    fout3.close();
    delete tree;
}