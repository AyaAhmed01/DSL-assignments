#include <iostream>
#include <vector>
using namespace std;


int naive_counting_inversions(vector<int> &a){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a.size(); j++){
            if(a[i] > a[j])
                cnt++;
        }
    }
    return cnt;
}
