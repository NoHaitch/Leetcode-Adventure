
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // // Solution with dealocatation
    // ListNode* deleteDuplicates(ListNode* head) {
    //     if (head == nullptr || head->next == nullptr) {
    //         return head;
    //     }

    //     ListNode* root = head;  
    //     ListNode* prev = head;
    //     ListNode* curr = head->next;

    //     while (curr != nullptr) {
    //         if (curr->val == prev->val) {
    //             ListNode* toDelete = curr;
    //             curr = curr->next;
    //             delete toDelete;  
    //             prev->next = curr; 

    //             if (curr == nullptr) {
    //                 prev->next = nullptr; 
    //             }
    //         } else {
    //             prev = curr;
    //             curr = curr->next;
    //         }
    //     }

    //     return root; 
    // }

    // Solution Without dealocatation
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr  ||  head->next == nullptr){
            return head;
        }

        ListNode* root = head;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr != nullptr){
            if(curr->val == prev->val){
                curr = curr->next;
                if(curr == nullptr){
                    prev->next = nullptr;
                }
            }
            else{
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        return root;
    }
};