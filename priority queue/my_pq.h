#ifndef MY_PQ_H
#define MY_PQ_H

#include <vector>
using namespace std;

class My_PQ{
private:
    vector<int> elements;
    int maxSize, curSize = 0;


public:
    My_PQ(){}

    My_PQ(vector<int> arr, int maxSize = 1e6){}

    int extractMax(){
        int result = elements[0];
        elements[0] = elements[curSize - 1];
        curSize--;
        siftDown(0);
    }

    int changePriority(int index, int newPriority){
        auto oldP = elements[index];
        elements[index] = newPriority;
        if(oldP > newPriority)
            siftDown(index);
        else
            siftUp(index);
    }

    int peek(){
        return elements[0];
    }

    void insert(int value) throw (int){
        if(curSize == maxSize)
            throw maxSize;
        elements[curSize] = value;
        siftUp(curSize++);
    }

    void remove(int index){  // change prior to -inf, then sift down
        elements[index] = INT_MAX;
        siftUp(index);
        extractMax();
    }
};

#endif
