#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

bool hasCycle(Node* head) {
    if (head == nullptr) {
        return false;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    // linklist = 3->2->0->-4
    // Set up a cycle at the specified position (pos)
    int pos = 1;
    Node* cycleNode = head;
    while (pos>0) {
        cycleNode = cycleNode->next;
        pos--;
    }
    //cycleNode = 2 
    Node* tail = head; // tail = 3 
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = cycleNode;
    
    // now link list = 3->2->0->-4------->(2)
    bool res =  hasCycle(head);
    
    cout<< "link has loop : " << res << endl;


    return 0;
}
