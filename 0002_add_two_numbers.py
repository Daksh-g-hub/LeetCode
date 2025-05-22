# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy_head = ListNode(0)
        current = dummy_head
        carry = 0

        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            total = val1 + val2 + carry

            carry = total // 10
            current.next = ListNode(total % 10)
            current = current.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy_head.next

# Helper to create a linked list from a Python list
def create_linked_list(lst):
    dummy = ListNode()
    current = dummy
    for val in lst:
        current.next = ListNode(val)
        current = current.next
    return dummy.next

# Helper to print linked list as a list
def print_linked_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next
    print(result)

# Example usage:
l1 = create_linked_list([2, 4, 3])  # Represents 342
l2 = create_linked_list([5, 6, 4])  # Represents 465

sol = Solution()
result = sol.addTwoNumbers(l1, l2)  # Should be 807 -> [7, 0, 8]

print_linked_list(result)  # Output: [7, 0, 8]
