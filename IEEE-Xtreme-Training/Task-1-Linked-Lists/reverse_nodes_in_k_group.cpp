/*
 * Problem Link https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/
 *
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *new_list = new ListNode();
        ListNode *new_list_head = new_list;
        vector<ListNode *> list_array;
        ListNode *curr = head;
        while (curr != nullptr) {
            //cout << curr->val << endl;
            list_array.push_back(curr);
            curr = curr->next;
        }
        int i;
        for (i = 0; i <= list_array.size()-k; i += k) {
            for (int j = k-1; j >= 0; --j) {
                new_list->next = new ListNode(list_array[i+j]->val);
                new_list = new_list->next;
            }
        }
        for (; i < list_array.size(); ++i) {
            new_list->next = new ListNode(list_array[i]->val);
            new_list = new_list->next;
        }
        return new_list_head->next;
    }
};

ListNode *create_list(vector<int> v) {
    ListNode *l = new ListNode(v[0]);
    ListNode *ptr = l;
    for (int i = 1; i < v.size(); ++i) {
        ptr->next = new ListNode(v[i]);
        ptr = ptr->next;
    }
    return l;
}

int main()
{
    //ListNode *l = create_list({1, 2, 3, 4, 5});
    ListNode *l = create_list({1});
    Solution sol;
    ListNode *result = sol.reverseKGroup(l, 1);
    while (result != nullptr) {
        cout << result->val << endl;
        result = result->next;
    }
}

