#include "heap.h"	

void build_heap(int arr[], int n);
void retro(int arr[], int n, int i);
void heapsort(int arr[], int& n);

void remove(int arr[], int& n)
{
    while (n) {
        std::swap(arr[1], arr[n]);
        --n;
        retro(arr, n, 1);
    }
}

void build_heap(int arr[], int n)
{
    for (int i = n / 2; i >= 1; --i)
        retro(arr, n, i);
}

void retro(int arr[], int n, int i)
{
    int parent = i;
    int child = i * 2;

    while (child <= n)
    {
        if ((child + 1 <= n) && (arr[child] < arr[child + 1]))
            ++child;

        if (arr[child] > arr[parent])
        {
            std::swap(arr[child], arr[parent]);
            parent = child;
            child = child * 2;
        }
        else break;
    }
}

void heapsort(int arr[], int& n)
{
    build_heap(arr, n);
    remove(arr, n);
}

int main()
{
    int arr[1 << MAX_DEPTH + 1];
    int n, cn;
    
    std::cin >> n;
    cn = n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> arr[i];
    }

    heapsort(arr, cn);

    for (int i = 1; i <= n; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    /* 
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
    */

    return 0;
}
