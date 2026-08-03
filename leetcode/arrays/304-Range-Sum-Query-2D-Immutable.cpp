#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> prefSum;
    NumMatrix(vector<vector<int>>& matrix) {
        prefSum = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        
        prefSum[0][0] = matrix[0][0];

        int sum = matrix[0][0];
        for (int row = 1; row < matrix.size(); row++) {
            sum += matrix[row][0];
            prefSum[row][0] = sum;
        }

        sum = matrix[0][0];
        for (int col = 1; col < matrix[0].size(); col++) {
            sum += matrix[0][col];
            prefSum[0][col] = sum;
        }

        for (int row = 1; row < matrix.size(); row++) {
            for (int col = 1; col < matrix[0].size(); col++) {
                prefSum[row][col] = matrix[row][col] + prefSum[row-1][col] + prefSum[row][col-1] - prefSum[row-1][col-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = prefSum[row2][col2];
        int top = row1-1 < 0 ? 0 : prefSum[row1-1][col2];
        int left = col1-1 < 0 ? 0 : prefSum[row2][col1-1];
        int topLeft = row1-1 < 0 || col1-1< 0 ? 0 : prefSum[row1-1][col1-1];
        return total - top - left + topLeft;
    }
};



int main() {
    vector<vector<int>> a ={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    NumMatrix b = NumMatrix(a);
    for (auto i: b.prefSum) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}