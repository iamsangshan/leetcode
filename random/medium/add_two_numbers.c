/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*

   You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode *temp = NULL;
    int sum = 0;
    static int carry = 0;
    
    /* both num are proceessed or both nums are empty */
    if (!l1 && !l2) {
        if (carry) {
            temp = malloc(sizeof(struct ListNode));
            temp->val = carry;
            temp->next = NULL;
            carry = 0;
        }
        return temp;
    }
    
    temp = malloc(sizeof(struct ListNode));
    
    /* one of the num is done */
    if (!l1 || !l2) {
        if (l1) sum = l1->val + carry;
        if (l2) sum = l2->val + carry;
    } else {
        /* Add each node of l1 and l2 */
        sum = l1->val + l2->val + carry;
    }
    
    if (sum < 10) 
        carry = 0;
    else {
        sum = sum % 10;
        carry = 1;
    }
    
    temp->val = sum;
    
    if (l1 && l2)
        temp->next = addTwoNumbers(l1->next, l2->next);
    else if (l1)
        temp->next = addTwoNumbers(l1->next, NULL);
    else
        temp->next = addTwoNumbers(NULL, l2->next);
    
    return temp;
}
