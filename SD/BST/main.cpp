#include <iostream>
#include "BST.h"

int main()
{
    BST<int> tree;

    tree.insert(30);
    tree.insert(20);
    tree.insert(38);
    tree.insert(10);
    tree.insert(35);
    tree.insert(25);
    tree.insert(42);
    tree.insert(35);
    tree.insert(40);

    tree.print(tree.root);
    std::cout << '\n';
    std::cout << tree.search(40) << '\n';
    std::cout << tree.search(29) << '\n';
    std::cout << tree.max() << '\n';
    std::cout << tree.min() << '\n';
}

