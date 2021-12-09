#include <bits/stdc++.h>
#include "quicksort.cpp"
using namespace std;


// performs heapsort on the given range of elements
void heapSort(vector<int>::iterator begin, vector<int>::iterator end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
}

void insertionSort(vector<int> &a, vector<int>::iterator begin, vector<int>::iterator end){
    vector<int>::iterator outerI, innerI;
    for(outerI = begin; outerI <= end; outerI++){
        for(innerI = begin; innerI < outerI; innerI++){
            if(*innerI > *outerI)
                swap(*innerI, *outerI);
        }
    }
}

void introSort(vector<int> &a, vector<int>::iterator begin, vector<int>::iterator end, int max_depth){
    int length = end - begin;
    if (length <= 16)
        insertionSort(a, begin, end);
    
    if(max_depth == 0)
        heapSort(begin, end);
    else{
        auto pivot = partition(a, begin, end);
        introSort(a, begin, pivot - 1, max_depth - 1);
        introSort(a, pivot + 1, end, max_depth - 1);
    }
}