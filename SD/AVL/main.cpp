#include <iostream>
#include "AVL.h"

int main() {
    AVL<int> tree;

    int n;
    std::cin >> n;
    while(n--) {
        int x;
        std::cin >> x;
        std::cout << "-------\n";
        tree.insert(x);
        tree.indent();
        std::cout << "-------\n";
        
    }
}
