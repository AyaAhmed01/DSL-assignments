#include <iostream>
#include <vector>

using namespace std;

// Dynamic programming sol: recursive, iterative. Time: O(n^2), space: O(n)
// greedy && binary search: O(n*logn)
// sliding window
// getting path solution
// BIT solution

vector<int> dp(3000, -1);

int solveRec(int stIdx, vector<int> &nums){
    if(stIdx >= nums.size())
        return 0;
    if (~dp[stIdx])
        return dp[stIdx];
    dp[stIdx] = 1;        // at least you can take that element only in the sequence
    for(int i = stIdx + 1; i < nums.size(); i++){
        if(nums[i] > nums[stIdx])
            dp[stIdx] = max(dp[stIdx], 1 + solveRec(i, nums));
    }
    return dp[stIdx];
}

int lengthOfLIS(vector<int>& nums) {
    int maxLen = 0;
    for(int i = 0; i < nums.size(); i++){           // first try all possible staring index
        maxLen = max(maxLen, solveRec(i, nums));
    }
    return maxLen;
}

int main(){
    vector<int> v = { 9, 2, 5, 10,3,11};
    cout<< lengthOfLIS(v);
    return 0;
}