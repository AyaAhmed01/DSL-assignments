#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// greedy with binary search: time O(n*logn): https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)
// patience sort algorithm: https://www.youtube.com/watch?v=22s1xxRvy28
// find path in O(N * logN)


int lengthOfLIS(vector<int>& nums) {
    vector<int> seq;
    for(auto e : nums){
        if(seq.empty() || e > seq[seq.size() - 1])
            seq.push_back(e);
        else{                                                   // when the new e can't extend the seq
            auto it = lower_bound(seq.begin(), seq.end(), e);  // get first ele bigger/ equal e and replace it with e greedily
            *it = e;
        }
    }
    return seq.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> seq(n);
    for (auto &ele : seq)
        cin >> ele;
    int maxLen = lengthOfLIS(seq);
    cout << "length " << maxLen << endl;
    return 0;
}