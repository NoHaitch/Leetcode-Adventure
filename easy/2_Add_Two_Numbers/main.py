from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res = ListNode()
        if l1 is None and l2 is None:
            return None
        elif l1 is None:
            res.val = l2.val
            l2 = l2.next
            p = res
            while l2 is not None:
                p.next = ListNode(l2.val)
                l2 = l2.next
                p = p.next
            return res
        elif l2 is None:
            res.val = l1.val
            l1 = l1.next
            p = res
            while l1 is not None:
                p.next = ListNode(l1.val)
                l1 = l1.next
                p = p.next
            return res
        else:
            carry = 0
            sum_val = l1.val + l2.val
            if sum_val > 9:
                carry = sum_val // 10
                sum_val %= 10
            res.val = sum_val
            l1 = l1.next
            l2 = l2.next
            p = res
            while l1 is not None and l2 is not None:
                sum_val = l1.val + l2.val + carry
                if sum_val > 9:
                    carry = sum_val // 10
                    sum_val %= 10
                else:
                    carry = 0
                p.next = ListNode(sum_val)
                l1 = l1.next
                l2 = l2.next
                p = p.next
            while l1 is not None:
                if carry != 0:
                    sum_val = l1.val + carry
                    if sum_val > 9:
                        carry = sum_val // 10
                        sum_val %= 10
                    else:
                        carry = 0
                    p.next = ListNode(sum_val)
                else:
                    p.next = ListNode(l1.val)
                l1 = l1.next
                p = p.next
            while l2 is not None:
                if carry != 0:
                    sum_val = l2.val + carry
                    if sum_val > 9:
                        carry = sum_val // 10
                        sum_val %= 10
                    else:
                        carry = 0
                    p.next = ListNode(sum_val)
                else:
                    p.next = ListNode(l2.val)
                l2 = l2.next
                p = p.next
            if carry != 0:
                p.next = ListNode(carry)
            return res
        return None