#include <iostream>
#include "AVL.h"

int main() {
    AVL<int> tree;

    tree.insert(9);
    tree.insert(7);
    tree.insert(5);
    tree.insert(3);
    tree.insert(6);
    tree.insert(8);
    tree.insert(10);
    tree.insert(12);
    tree.insert(14);
    tree.insert(15);
    tree.insert(11);
    tree.print();
    tree.indent();
}
