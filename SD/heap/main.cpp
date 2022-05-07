#include "heap.h"

int main()
{
    max_heap tree;

    for(int i = 0; i < 5; ++i) {
        int x;
        std::cin >> x;
        tree.push(x);    
    }
    
    std::cout << "max " <<  tree.max() << '\n';
    for(int i = 0; i < 5; ++i) {
        int x;
        tree.pop();
        std::cout << "max " <<  tree.max() << '\n';
    }

    return 0;
}
