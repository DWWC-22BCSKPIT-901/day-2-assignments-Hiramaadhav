#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted lists
vector<int> mergeSortedLists(const vector<int>& list1, const vector<int>& list2) {
    vector<int> mergedList;
    int i = 0, j = 0;

    // Merge the lists
    while (i < list1.size() && j < list2.size()) {
        if (list1[i] < list2[j]) {
            mergedList.push_back(list1[i]);
            i++;
        } else {
            mergedList.push_back(list2[j]);
            j++;
        }
    }

    // Add remaining elements from list1
    while (i < list1.size()) {
        mergedList.push_back(list1[i]);
        i++;
    }

    // Add remaining elements from list2
    while (j < list2.size()) {
        mergedList.push_back(list2[j]);
        j++;
    }

    return mergedList;
}

int main() {
    int n1, n2, element;

    // Input first sorted list
    cout << "Enter the number of elements in the first sorted list: ";
    cin >> n1;
    vector<int> list1;
    cout << "Enter the elements of the first sorted list: ";
    for (int i = 0; i < n1; ++i) {
        cin >> element;
        list1.push_back(element);
    }

    // Input second sorted list
    cout << "Enter the number of elements in the second sorted list: ";
    cin >> n2;
    vector<int> list2;
    cout << "Enter the elements of the second sorted list: ";
    for (int i = 0; i < n2; ++i) {
        cin >> element;
        list2.push_back(element);
    }

    // Merge the two sorted lists
    vector<int> mergedList = mergeSortedLists(list1, list2);

    // Output the merged list
    cout << "Merged sorted list: ";
    for (int num : mergedList) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
