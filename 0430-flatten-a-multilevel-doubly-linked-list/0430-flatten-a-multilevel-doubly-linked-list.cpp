/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        if (head == nullptr)
            return head;

        Node* curr = head;

        while (curr != nullptr) {
            if (curr->child == nullptr) {
                curr = curr->next;
                continue;
            }

            Node* next = curr->next;
            curr->next = curr->child;
            curr->child->prev = curr;

            Node* temp = curr->child;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = next;

            if (next != nullptr) {
                next->prev = temp;
            }

            curr->child = nullptr;

            curr = curr->next;
        }

        return head;
    }
};