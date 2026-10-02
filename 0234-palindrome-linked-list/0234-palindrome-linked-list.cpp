/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool palindrome(vector<int>& list) {
        int i = 0, j = list.size() - 1;

        while (i < j) {
            if (list[i] != list[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        vector<int> list;

        ListNode* temp = head;

        while (temp != nullptr) {
            list.push_back(temp->val);
            temp = temp->next;
        }

        if (palindrome(list))
            return true;
        return false;
    }
};