#include <bits/stdc++.h>
using namespace std;

/*
 * naive implementation of matrix multiplication algorithm.
 * the result is a*b "matrix multiplcation"
*/

vector<vector<int>> naive(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> result;
    for(int r = 0; r < a.size(); r++){            // Iterate the rows of matrix a
        vector<int> new_row;                     // new row to be constructed in result matrix
        for(int c = 0; c < b[0].size(); c++){   // Iterate the columns of matrix b
            int element = 0;                   
            for(int k = 0; k < b.size(); k++){ 
                element += a[r][k] * b[k][c];
            }
            new_row.push_back(element);
        }
        result.push_back(new_row);
    }
    return result;
}
