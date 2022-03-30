#include <iostream>
#include <queue>
#include <exception>

namespace yakub {
    class Queue {
        int capacity;
        int* mem;
        int elements;

        int first;
    public:
        Queue()
            : capacity(10), mem(new int[10]), elements(0), first(0)
        {
        }
        ~Queue() {
        }

        void push(int x) {
            if (elements == capacity)
            {
                int* newMem = new int[capacity + 10];
                for(int i=0, j=first; i<elements; i++, j++){
                    int copyFrom = j % capacity;
                    newMem[i] = mem[copyFrom];
                }
                delete[] mem;
                mem = newMem;
                capacity += 10;
                first = 0;
            }
            int insertion_location = (first + elements) % capacity;
            mem[insertion_location] = x;
            elements++;
        }

        bool empty(){
            return elements == 0;
        }
        void pop() {
            if (elements!=empty()) {
                first = (first + 1) % capacity;
            }
            else
            {
                throw std::runtime_error("called on an empty queue");
            }
        }
        int front(){
            if(elements=empty()) {
            throw std::runtime_error("the function is called on an empty queue");
            }
            return mem[first];
        }
        

    };
};


int main() {
 

}
