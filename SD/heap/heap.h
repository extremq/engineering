#include <iostream>
#define MAX_DEPTH 16

class max_heap {
private:
    int array[1 << MAX_DEPTH + 1] = { 0 };
    int _size;
public:
    max_heap () {
        this->_size = 0;
    }

    int size() {
        return this->_size;
    }

    int max() {
        if (this->_size > 0) 
            return this->array[1];
        
        std::cout << "Error: max_heap empty!\n";
        return -1;
    }

    void push(int key) {
        this->array[++this->_size] = key;

        int iter = this->_size;
        while((iter >> 1) > 0 && (this->array[iter] > this->array[iter >> 1])) {
            std::swap(this->array[iter], this->array[iter >> 1]);

            iter = iter >> 1;
        }
    }

    int pop() {
        if (this->_size == 0) {
            std::cout << "Error: max_heap empty!\n";
            return -1;
        }

        int ret = this->array[1];
        std::swap(this->array[this->_size--], this->array[1]);        

        int parent = 1, child = 2;
        while(child <= this->_size) {
            if (child + 1 <= this->_size && this->array[child] < this->array[child + 1])
                ++child;

            if (this->array[parent] < this->array[child]) {
                std::swap(this->array[parent], this->array[child]);
                parent = child;
                child = child << 1;
            }
            else break;
        }

        return ret;
    }

private:
    void _print() {
        for(int i = 1; i <= this->_size; ++i)
            std::cout << this->array[i] << ' ';
        std::cout << '\n';
    }
};
