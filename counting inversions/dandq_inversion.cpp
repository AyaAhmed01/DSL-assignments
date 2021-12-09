#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countSubInv(vector<int>::iterator st, vector<int>::iterator ed){
    if(ed - st <= 1)
        return 0;

    auto mid = st + (ed - st)/2;
    int cnt = countSubInv(st, mid) + countSubInv(mid, ed);

    // count inversions in current st, mid, ed
    for(auto firstHalfI = st, secHalfI = mid; firstHalfI != mid; firstHalfI++){
        while(*firstHalfI > *secHalfI && secHalfI != ed)
            secHalfI++;
        cnt+= secHalfI - mid;
    }

    // sort the whole consecutive seq in place
    inplace_merge(st, mid, ed);
    return cnt;
}

int dandq_counting_inversions(vector<int> &nums){
    return countSubInv(nums.begin(), nums.end());
}