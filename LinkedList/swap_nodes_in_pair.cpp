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

//  recursive
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* first = head;
        ListNode* sec = head->next;

        first->next = swapPairs(sec->next);
        sec->next = first; 

        return sec;
    }
};

// iterative

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
    ListNode* swapPairs(ListNode* head) {

        if(!head || !head->next) return head; 
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while(prev->next && prev->next->next){
            ListNode* first = prev->next;
            ListNode* sec = prev->next->next;

            prev->next = sec;
            first->next = sec->next;
            sec->next = first;

            prev = first;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};