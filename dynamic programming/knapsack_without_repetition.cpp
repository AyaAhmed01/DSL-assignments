#include <iostream>
#include <vector>

using namespace std;

int maxValue(vector<int> &weight, vector<int> &val, int totalCap){                        // bottom-up solution O(totalCap * n)
    int n = val.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int> (totalCap + 1, 0));     // state parameters: total available capacity, curr idx to take or leave
    for(int i = 1; i <= n; i++){
        for(int c = 1; c <= totalCap; c++){
            dp[i][c] = dp[i-1][c];                                          // leave element at idx i
            if(c >= weight[i])
                dp[i][c] = max(dp[i][c], val[i] + dp[i-1][c-weight[i]]);  // pick element at idx i
        }
    }
    int ans = 0;
    for(int i = 0; i <= totalCap; i++)
        ans = max(ans, dp[n][i]);

    return ans;
}

int main(){
    int totalC, n;
    cin>>n>>totalC;
    vector<int> w(n + 1, 0), v(n + 1, 0);
    for(int i = 1; i <= n; i++)
        cin>>w[i];
    for(int i = 1; i <= n; i++)
        cin>>v[i];
    cout<<maxValue(w, v, totalC);
    return 0;
}

