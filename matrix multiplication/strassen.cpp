#include <bits/stdc++.h>
#include "naive.cpp"

using namespace std;

/**
 * implement strassen divide and conquer algorithm for matrix multiplication
 * and return the result of a*b "matrix multiplcation".
*/


/* returns a sub matrix of matrix "mat" that is bounded by given row and column indices */
vector<vector<int>> sub_mat(int start_row_idx, int end_row_idx, int start_col_idx, int end_col_idx, vector<vector<int>> &mat){
    int n = mat.size();
    vector<vector<int>> res (n/2, vector<int> (n/2));
    for(int r_idx = start_row_idx; r_idx <= end_row_idx; r_idx++){
        for(int c_idx = start_col_idx; c_idx <= end_col_idx; c_idx++){
            res[r_idx % (n/2)][c_idx % (n/2)] = mat[r_idx][c_idx];
        }
    }
    return res;
}

/* splits matrix "mat" into four equal-size sub matrices and return them*/

array <vector<vector<int>>, 4> split( vector<vector<int>> &mat){
    int n = mat.size();
    array <vector<vector<int>>, 4> splitted_matrices;
    splitted_matrices [0] = sub_mat(0, n/2 - 1, 0 , n/2 - 1, mat);
    splitted_matrices [1] = sub_mat(0, n/2 - 1, n/2 , n - 1, mat);
    splitted_matrices [2] = sub_mat(n/2, n - 1, 0 , n/2 - 1, mat);
    splitted_matrices [3] = sub_mat(n/2, n - 1, n/2, n - 1, mat);
    return splitted_matrices;
}

/* apply summation or subtraction of two matrices based on given parameter "operation" */

vector<vector<int>> sum_or_sub (const vector<vector<int>> &a, const vector<vector<int>> &b, char operation){
    int n = a.size();
    vector<vector<int>> res (n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res[i][j] = a[i][j] + (operation == '-' ? -1 * b[i][j] : b[i][j]);
        }
    }
    return res;
}

/* copy all "sub mat" matrix elements into matrix "mat" 
in region bounded by row indices (start_row, end_row) and column indices (start_col, end_col) in matrix*/

void fill(int start_row, int end_row, int start_col, int end_col, vector<vector<int>> &mat, vector<vector<int>> &sub_mat){
    int n = mat.size();
    for(int r_idx = start_row; r_idx <= end_row; r_idx++){
        for(int c_idx = start_col; c_idx <= end_col; c_idx++){
            mat[r_idx][c_idx] = sub_mat[r_idx % (n/2)][c_idx % (n/2)];
        }
    }
}

/* concatenate sub matrices a, b, c, d together in one matrix with double the size of sub matrices*/

vector<vector<int>> concatenate(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<int>> &c, vector<vector<int>> &d){
    int n = a.size() * 2;                           // result matrix size
    vector<vector<int>> res (n, vector<int> (n));
    fill(0, n/2 - 1, 0, n/2-1, res, a);           
    fill(0, n/2 - 1, n/2 , n - 1, res, b);
    fill(n/2, n - 1, 0 , n/2 - 1, res, c);
    fill(n/2, n - 1, n/2, n - 1, res, d);
    return res;
}

/* strassen algorithm to multiply two matrices of size 2^m */

vector<vector<int>> strassen(vector<vector<int>> mat_a, vector<vector<int>> mat_b){
    if(mat_a.size() <= 2){
        return naive(mat_a, mat_b);
    }

    auto splitted_matrices_a = split(mat_a);  // generate 4 sub-matrices 
    auto splitted_matrices_b = split(mat_b);

    vector<vector<int>> a = splitted_matrices_a[0], b = splitted_matrices_a[1];
    vector<vector<int>> c = splitted_matrices_a[2], d = splitted_matrices_a[3];

    vector<vector<int>> e = splitted_matrices_b[0], f = splitted_matrices_b[1];
    vector<vector<int>> g = splitted_matrices_b[2], h = splitted_matrices_b[3];

    auto p1 = strassen(sum_or_sub(a, d, '+'), sum_or_sub(e, h, '+'));
    auto p2 = strassen(d, sum_or_sub(g, e, '-'));
    auto p3 = strassen(sum_or_sub(a, b, '+'), h);
    auto p4 = strassen(sum_or_sub(b, d, '-'), sum_or_sub(g, h, '+'));
    auto p5 = strassen(a, sum_or_sub(f, h, '-'));
    auto p6 = strassen(sum_or_sub(c, d, '+'), e);
    auto p7 = strassen(sum_or_sub(a, c, '-'), sum_or_sub(e, f, '+'));

    auto C11 = sum_or_sub(sum_or_sub(p1, p2, '+'), sum_or_sub(p3, p4, '+'), '-');
    auto C12 = sum_or_sub(p5, p3, '+');
    auto C21 = sum_or_sub(p6, p2, '+');
    auto C22 = sum_or_sub(sum_or_sub(p5, p1, '+'), sum_or_sub(p6, p7, '-'), '-');

    vector<vector<int>> C = concatenate(C11, C12, C21, C22);
    return C;
}
