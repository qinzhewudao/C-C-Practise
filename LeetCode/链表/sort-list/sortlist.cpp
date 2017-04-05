/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
  ���㣺
  1. ����ָ�룻2. �鲢����
  ���⾭�䣬��Ҫ�������ա�
  ���Ӷȷ���:
             T(n)            ��� n/2, �鲢 n/2 ��һ����n/2 + n/2 = n
            /    \           �����������ƣ�
          T(n/2) T(n/2)      һ���� n/2*2 = n
         /    \  /     \
        T(n/4) ...........   һ���� n/4*4 = n
 
       һ����logn�㣬�ʸ��Ӷ��� O(nlogn)
 */
class Solution {
public:
ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;//head Ϊ�ջ���ֻ��headһ��Ԫ��
         
        ListNode* p = head, *q = head->next;  //��Ϊ*q = head,�ͻᱨ�����б�ֻ���������ʱ��������ѭ��
        while(q && q->next) {                 //����ָ���п���ߵ���ͷ
            p = p->next;
            q = q->next->next;
        }
         
        ListNode* right = sortList(p->next);   //����Ϊ��������
        p->next = NULL;                         //�Ͽ�
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