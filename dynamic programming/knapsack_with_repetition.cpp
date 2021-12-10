#include <iostream>
#include <vector>

using namespace std;

// reference: https://www.youtube.com/watch?v=3zZcS43UKiA
/* since there is no restrictions on whether the element is already taken or not (you could repeat), the only parameter
   that define a state is the current weight.
   if answer of weight u is v(u), then v(u) = max(vi + v(u - wi)), for i [1, n]. The sub-problem is v(u - wi)
   O(n * W)
   */


int maxValueItr(vector<int> &weight, vector<int> &val, int totalCap){          // bottom-up solution O(totalCap * n)
    int n = val.size() - 1;
    vector<int> dp(totalCap + 1, 0);                              // state parameters: total available capacity
    for(int w = 1; w <= totalCap; w++){
        for(int i = 1; i <= n; i++){
            if(w >= weight[i])
                dp[w] = max(dp[w], val[i] + dp[w-weight[i]]);
        }
    }
    return dp[totalCap];
}

int maxValRec(vector<int> &dp, vector<int> &weight, vector<int> &val, int cap){
    if(cap == 0)
        return 0;
    if(dp[cap] == -1)
        dp[cap] = 0;
        for(int i = 1; i < val.size(); i++){
            if(cap >= weight[i])
                dp[cap] = max(dp[cap], val[i] + maxValRec(dp, weight, val, cap - weight[i]));
        }
    return dp[cap];
}

int main(){
    int n, totalC;
    cin>>n>>totalC;
    vector<int> w(n + 1, 0), v(n + 1, 0);
    for(int i = 1; i <= n; i++)
        cin>>w[i];
    for(int i = 1; i <= n; i++)
        cin>>v[i];
    // iterative sol
    cout<<maxValueItr(w, v, totalC)<<endl;

    // recursion sol
    vector<int> dp(totalC + 1, -1);
    cout<<maxValRec(dp, w, v, totalC);

    return 0;
}

