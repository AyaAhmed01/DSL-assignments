#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Dynamic programming sol: recursive, iterative. Time: O(n^2), space: O(n)
// getting path



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

void findPath(stack<int> &path, int maxLen, vector<int> &nums){      // O(n), construct it AFTER finding the longest length and filling the dp
    int remLen = maxLen;
    for(int i = nums.size() - 1; i >= 0 && path.size() < maxLen; i--)
        if(dp[i] == remLen){
            path.push(nums[i]);
            remLen--;
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
    cout<<"path: \n";
    stack<int> path;
    findPath(path, maxLen, seq);
    while(!path.empty()){
        cout<< path.top()<<' ';
        path.pop();
    }
    return 0;
}