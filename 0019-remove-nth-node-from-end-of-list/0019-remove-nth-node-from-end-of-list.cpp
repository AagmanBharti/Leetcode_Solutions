class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        if (n == len) {
            ListNode* deleteNode = head;
            head = head->next;
            delete deleteNode;
            return head;
        }

        temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;

            if (count == len - n) {
                ListNode* deleteNode = temp->next;

                temp->next = temp->next->next;

                delete deleteNode;
                break;
            }

            temp = temp->next;
        }

        return head;
    }
};