/*
 * LC 206: Reverse a singly linked list
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* cur = head;
        head = reverseList(head->next);
        cur->next->next = cur;
        cur->next = NULL;
        return head;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        
        ListNode* res = new ListNode(-1);
        res->next = head;
        head = head->next;
        res->next->next = NULL;
        
        while (head){
            ListNode* cur = head;
            head = head->next;
            ListNode* tmp = res->next;
            res->next = cur;
            cur->next = tmp;
        }
        return res->next;
    }
};

/*
 * LC 92: Reverse a linked list from position m to n. Do it in-place and in one-pass.
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return NULL;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* pre, *front, *last;
        for (int i = 1; i < m; i++) cur = cur->next;
        pre = cur;
        last = cur->next;
        for (int i = m; i <= n; i++){
            cur = pre->next;
            pre->next = cur->next;
            cur->next = front;
            front = cur;
        }
        cur = pre->next;
        pre->next = front;
        last->next = cur;
        return dummy->next;
    }
};