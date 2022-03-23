'''
    Problem Link https://leetcode.com/problems/swap-nodes-in-pairs/submissions/
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def rec(node):
            if (node and node.next != None):
                next_node = node.next
                curr_node = node
                curr_node.next = next_node.next
                next_node.next = curr_node
                curr_node.next = rec(curr_node.next)
            else:
                return node
            return next_node
        head = rec(head)
        return head
                
            
            
