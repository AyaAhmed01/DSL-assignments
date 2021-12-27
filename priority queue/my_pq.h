#ifndef MY_PQ_H
#define MY_PQ_H

#include <vector>
using namespace std;

class My_PQ{
private:
    vector<int> elements;
    int maxSize, curSize = 0;

    int leftChildIdx(int idx){
        return idx * 2 + 1;
    }

    int rightChildIdx(int idx){
        return idx * 2 + 2;
    }

    int parentIdx(int idx){
        return floor((idx - 1)/ 2);
    }

    void siftUp(int idx){
        while(idx > 0 && elements[parentIdx(idx)] < elements[idx]){
            swap(elements[parentIdx(idx)], elements[idx]);
            idx = parent(idx);
        }
    }

    void siftDown(int idx){
        int maxIdx = idx;
        while(true){
            int leftIdx = leftChildIdx(idx);
            if(leftIdx < curSize && elements[leftIdx] > elements[maxIdx])
                maxIdx = leftIdx;
            int rightIdx = rightChildIdx(idx);
            if(rightId < curSize && elements[rightIdx] > elements[maxIdx])
                maxIdx = rightIdx;
            if(i != maxIdx){
                swap(elements[maxIdx], elements[idx]);
                i = maxIdx;
            } else
                break;
        }
    }

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
