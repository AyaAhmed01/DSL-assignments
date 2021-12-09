#include <bits/stdc++.h>
using namespace std;


void quickSort(vector<int> &a, vector<int>::iterator begin, vector<int>::iterator end){
    if (begin < end){
        vector<int>::iterator pivot = partition(a, begin, end);
        quickSort(a, begin, pivot-1);
        quickSort(a, pivot+1, end);
    }
}

vector<int>::iterator partition(vector<int> &a, vector<int>::iterator begin, vector<int>::iterator end){
    // choose pivot as the right most element
    // lastSmall points to the last element from left that is smaller than pivot
    vector<int>::iterator lastSmall = begin - 1,  itr = begin;
    for(itr; itr <= end; itr++){
        if(*itr <= *end){
            lastSmall++;
            swap(*itr, *lastSmall);
        }
    }
    return lastSmall;
}