#include <iostream>
using namespace std;

// Definition of the linked list node
struct ListNode {
    int value;
    ListNode* next;

    // Constructor for creating a new node
    ListNode(int val) : value(val), next(nullptr) {}
};

// Function to reverse the linked list
ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* nextNode = current->next; // Store the next node
        current->next = prev;              // Reverse the current node's pointer
        prev = current;                    // Move prev to the current node
        current = nextNode;                // Move to the next node
    }

    return prev; // New head of the reversed list
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to create a linked list from an array of values
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

int main() {
    int n, value;
    vector<int> values;

    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        values.push_back(value);
    }

    // Create the linked list
    ListNode* head = createLinkedList(values);

    cout << "Original linked list: ";
    printList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    cout << "Reversed linked list: ";
    printList(head);

    return 0;
}
