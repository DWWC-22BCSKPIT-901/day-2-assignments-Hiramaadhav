#include <iostream>
#include <vector>
using namespace std;

// Function to find the majority element
int findMajorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;

    // Phase 1: Find a potential candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1; // No majority element
    }
}

int main() {
    vector<int> nums;
    int n, element;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        nums.push_back(element);
    }

    int result = findMajorityElement(nums);
    if (result != -1) {
        cout << "The majority element is: " << result << endl;
    } else {
        cout << "There is no majority element in the array." << endl;
    }

    return 0;
}
