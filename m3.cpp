#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the maximum area
int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        // Calculate the area formed by the two pointers
        int width = right - left;
        int current_area = min(height[left], height[right]) * width;
        max_area = max(max_area, current_area);

        // Move the pointer pointing to the shorter line
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    int n;
    cout << "Enter the number of heights: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights: ";
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    int result = maxArea(height);
    cout << "The maximum water that can be contained is: " << result << endl;

    return 0;
}
