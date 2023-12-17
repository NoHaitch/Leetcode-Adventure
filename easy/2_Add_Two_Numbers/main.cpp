#include <stdlib.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        if(l1 == NULL && l2 == NULL){
            return NULL;
        } else if(l1 == NULL){
            res->val = l2->val;
            l2 = l2->next;
            ListNode* p = res;
            while(l2 != NULL){
                p->next = new ListNode(l2->val);
                l2 = l2->next;   
                p = p->next;
            }
            return res;
        } else if(l2 == NULL){
            res->val = l1->val;
            l1 = l1->next;
            ListNode* p = res;
            while(l1 != NULL){
                p->next = new ListNode(l1->val);
                l1 = l1->next;   
                p = p->next;
            }
            return res;
        } else{
            int sum = l1->val + l2->val;
            int carry = 0;
            if(sum > 9){
                carry = sum / 10;
                sum %= 10;
            } else{
                carry = 0;
            }
            res->val = sum;
            l1 = l1->next;
            l2 = l2->next;
            ListNode* p = res;
            while(l1 != NULL && l2 != NULL){
                sum = l1->val + l2->val + carry;
                if(sum > 9){
                    carry = sum / 10;
                    sum %= 10;
                } else{
                    carry = 0;
                }
                p->next = new ListNode(sum);
                l1 = l1->next;
                l2 = l2->next;
                p = p->next;
            }
            while(l1 != NULL){
                if(carry != 0){
                    sum = l1->val + carry;
                    if(sum > 9){
                        carry = sum / 10;
                        sum %= 10;
                    } else{
                        carry = 0;
                    }
                    p->next = new ListNode(sum);
                } else{
                    p->next = new ListNode(l1->val);
                }
                l1 = l1->next;   
                p = p->next;
            }
            while(l2 != NULL){
                if(carry != 0){
                    sum = l2->val + carry;
                    if(sum > 9){
                        carry = sum / 10;
                        sum %= 10;
                    } else{
                        carry = 0;
                    }
                    p->next = new ListNode(sum);
                } else{
                    p->next = new ListNode(l2->val);
                }
                l2 = l2->next;   
                p = p->next;
            }
            if(carry != NULL){
                p->next = new ListNode(carry);
            }
            return res;
        }
        return NULL;
    }
};