'''
    Problem Link https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        
        def convert(sorted_list, l, r):
            if (l>r):
                return None
            mid = (l+r)//2
            root = TreeNode(sorted_list[mid])
            root.left = convert(sorted_list, l, mid-1)
            root.right = convert(sorted_list, mid+1, r)
            return root
        
        sorted_list = []
        while (head != None):
            sorted_list.append(head.val)
            head = head.next
        
        root = convert(sorted_list, 0, len(sorted_list)-1)
        return root
            

