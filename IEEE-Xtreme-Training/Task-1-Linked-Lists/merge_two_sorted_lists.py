'''
    Problem Link https://leetcode.com/problems/merge-two-sorted-lists/submissions/
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        new_list = ListNode()
        curr = new_list
        l1_ptr = l1
        l2_ptr = l2
        while (l1_ptr != None and l2_ptr != None):
            if (l1_ptr.val < l2_ptr.val):
                curr.next = ListNode(val=l1_ptr.val)
                curr = curr.next
                l1_ptr = l1_ptr.next
            else:
                curr.next = ListNode(val=l2_ptr.val)
                curr = curr.next
                l2_ptr = l2_ptr.next

        while (l1_ptr != None):
            curr.next = ListNode(val=l1_ptr.val)
            curr = curr.next
            l1_ptr = l1_ptr.next
                    
        while (l2_ptr != None):
            curr.next = ListNode(val=l2_ptr.val)
            curr = curr.next
            l2_ptr = l2_ptr.next
        
        return new_list.next
