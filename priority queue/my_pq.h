#ifndef MY_PQ_H
#define MY_PQ_H

#include <vector>
#include <algorithm>
#include <cmath>

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
            idx = parentIdx(idx);
        }
    }

    void siftDown(int idx){
        int maxIdx = idx;
        while(true){
            int leftIdx = leftChildIdx(idx);
            if(leftIdx < curSize && elements[leftIdx] > elements[maxIdx])
                maxIdx = leftIdx;
            int rightIdx = rightChildIdx(idx);
            if(rightIdx < curSize && elements[rightIdx] > elements[maxIdx])
                maxIdx = rightIdx;
            if(idx != maxIdx){
                swap(elements[maxIdx], elements[idx]);
                idx = maxIdx;
            } else
                break;
        }
    }

public:
    My_PQ(){}

    My_PQ(vector<int> &arr, int mxSize = 1e6){
        maxSize = mxSize;
        curSize = arr.size();
        elements = arr;                 // elements is a COPY of arr, NOT pointing to same vector
        sort(elements.rbegin(), elements.rend());  // sort in descending order
    }

    ~My_PQ(){}

    int extractMax(){
        int result = elements[0];
        elements[0] = elements[curSize - 1];
        curSize--;
        siftDown(0);
        return result;
    }

    int changePriority(int index, int newPriority){
        auto oldP = elements[index];
        elements[index] = newPriority;
        if(oldP > newPriority)
            siftDown(index);
        else
            siftUp(index);
        return oldP;
    }

    int size(){
        return curSize;
    }

    bool empty(){
        return curSize == 0;
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
