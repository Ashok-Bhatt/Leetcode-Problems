# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteNode(self, node):
        
        previous = None
        while (node.next is not None):
            previous = node
            node.val = node.next.val
            node = node.next
        
        previous.next = None