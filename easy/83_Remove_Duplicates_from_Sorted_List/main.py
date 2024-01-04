from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        root = head
        prev = head
        curr = head.next
        
        while curr:
            if prev.val == curr.val:
                curr = curr.next
                if not curr:
                    prev.next = None
            else:
                prev.next = curr
                prev = curr
                curr = curr.next

        return head