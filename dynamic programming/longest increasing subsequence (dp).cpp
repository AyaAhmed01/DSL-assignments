#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Dynamic programming sol: recursive, iterative. Time: O(n^2), space: O(n)
// getting path
// greedy && binary search: O(n*logn)
// sliding window
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

void solveItr(vector<int> &nums){                // here the dp index is the index where the seq END
    fill(dp.begin(), dp.end(), 1);        // initially ending at any pos gives 1 length seq
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i])
                dp[i] = max(dp[i], 1 + dp[j]); // nums[j] is the element before the last element (nums[i]) in sequence
        }
    }
}



int lengthOfLIS(vector<int>& nums) {
    int maxLen = 0;
    // solve rec
    for(int i = 0; i < nums.size(); i++){           // first try all possible staring index
        maxLen = max(maxLen, solveRec(i, nums));
    }

    // solve itr
    solveItr(nums);
    for(int i = 0; i < nums.size(); i++)
        maxLen = max(maxLen, dp[i]);

    return maxLen;
}

int main(){
    int n;
    cin>>n;
    vector<int> seq (n);
    for(auto &ele : seq)
        cin>>ele;
    int maxLen = lengthOfLIS(seq);
    cout<< "length " << maxLen <<endl;

    // find path
    stack<int> path;
    findPath(path, maxLen, n);
    while(!path.empty()){
        cout<< path.top()<<' ';
        path.pop();
    }
    return 0;
}