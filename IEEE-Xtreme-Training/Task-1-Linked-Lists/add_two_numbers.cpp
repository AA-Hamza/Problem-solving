/*
 * Problem Link https://leetcode.com/problems/add-two-numbers/submissions/
 * 
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *new_list = new ListNode;
        ListNode *curr = new_list;
        
        int carry = 0;
        ListNode *l1_ptr, *l2_ptr;
        l1_ptr = l1;
        l2_ptr = l2;
        while (l1_ptr != nullptr and l2_ptr != nullptr) {
            int addition = l1_ptr->val + l2_ptr->val + carry;
            int last_digit = addition % 10;
            carry = (addition-last_digit)/10;
            addition = last_digit;
            
            curr->next = new ListNode(addition);
            curr = curr->next;
            l1_ptr = l1_ptr->next;
            l2_ptr = l2_ptr->next;
        }
        
        while (l1_ptr != nullptr) {
            int addition = l1_ptr->val + carry;
            int last_digit = addition % 10;
            carry = (addition-last_digit)/10;
            addition = last_digit;
            
            curr->next = new ListNode(addition);
            curr = curr->next;
            l1_ptr = l1_ptr->next;
        }
        
        while (l2_ptr != nullptr) {
            int addition = l2_ptr->val + carry;
            int last_digit = addition % 10;
            carry = (addition-last_digit)/10;
            addition = last_digit;
            
            curr->next = new ListNode(addition);
            curr = curr->next;
            l2_ptr = l2_ptr->next;
        }
        if (carry) {
            curr->next = new ListNode(carry);
        }
        return new_list->next;
    }
};
