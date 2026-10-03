class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Second half starts after slow
        ListNode* secondHalf = slow->next;

        // Disconnect the two halves
        slow->next = nullptr;

        // Reverse second half
        secondHalf = reverse(secondHalf);

        // Merge
        ListNode* firstHalf = head;

        while (secondHalf != nullptr) {

            ListNode* next1 = firstHalf->next;
            ListNode* next2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = next1;

            firstHalf = next1;
            secondHalf = next2;
        }
    }
};