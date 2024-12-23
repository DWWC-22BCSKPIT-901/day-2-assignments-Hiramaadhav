#include <iostream>
#include <vector>
using namespace std;

// Function to generate Pascal's Triangle up to the given number of rows
vector<vector<int>> generatePascalsTriangle(int numRows) {
    vector<vector<int>> triangle;

    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1); // Initialize a row with 1s

        for (int j = 1; j < i; ++j) {
            // Calculate the value based on the previous row
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row); // Add the row to the triangle
    }

    return triangle;
}

// Function to print Pascal's Triangle
void printPascalsTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    int numRows;

    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;

    vector<vector<int>> triangle = generatePascalsTriangle(numRows);

    cout << "Pascal's Triangle:" << endl;
    printPascalsTriangle(triangle);

    return 0;
}
