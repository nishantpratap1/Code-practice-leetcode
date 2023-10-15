#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m=matrix.size(); // x-axis
        int n=matrix[0].size(); // y-axis
        /* we will start from here  ( sorted matrix row-wise , column-wise)
        1  3  5  7 <--- pointer (from here we will start)
        10 11 16 20
        23 30 34 60
        */
        int i=0;
        int j=n-1; // j = 3 , n =4
        while(i>=0 && i<m && j>=0 && j<n){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target){
                j--;
            }else if(matrix[i][j]<target){
                i++;
            }
        }
        return false;
    }

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    if (searchMatrix(matrix, target)) {
        cout << "Target " << target << " is found in the matrix." << endl;
    } else {
        cout << "Target " << target << " is not found in the matrix." << endl;
    }

    return 0;
}
