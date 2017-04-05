/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
  考点：
  1. 快慢指针；2. 归并排序。
  此题经典，需要消化吸收。
  复杂度分析:
             T(n)            拆分 n/2, 归并 n/2 ，一共是n/2 + n/2 = n
            /    \           以下依此类推：
          T(n/2) T(n/2)      一共是 n/2*2 = n
         /    \  /     \
        T(n/4) ...........   一共是 n/4*4 = n
 
       一共有logn层，故复杂度是 O(nlogn)
 */
class Solution {
public:
ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;//head 为空或者只有head一个元素
         
        ListNode* p = head, *q = head->next;  //改为*q = head,就会报错，当列表只有两个结点时会陷入死循环
        while(q && q->next) {                 //快慢指针中快的走到尽头
            p = p->next;
            q = q->next->next;
        }
         
        ListNode* right = sortList(p->next);   //划分为左右两半
        p->next = NULL;                         //断开
        ListNode* left = sortList(head);
         
        return merge(left, right);
    }
         
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode dummy(0);
        ListNode *p = &dummy;
        while(left && right) {
            if(left->val < right->val) {
                p->next = left;
                left = left->next;
            }
            else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if (left) p->next = left;
        if (right) p->next = right;
        return dummy.next;
    }
};