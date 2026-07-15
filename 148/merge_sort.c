/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Computes length of list and cuts it in half
 * First half stays in _list_
 * Second half goes in _*second_
 */
void splitList(struct ListNode *list, struct ListNode **second) {
    int len = 0;
    struct ListNode *curr = list;
    while (curr != NULL) {
        curr = curr->next;
        len++;
    }

    int half = len / 2 - 1;
    int count = 0;
    while (count < half) {
        list = list->next;
        count++;
    }
    *second = list->next;
    list->next = NULL;
}

struct ListNode *merge(struct ListNode *first, struct ListNode *second) {
    if (first == NULL && second == NULL)
        return NULL;
    
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    struct ListNode *merged = first->val < second->val ? first : second;
    
    struct ListNode *itMerged = merged;
    struct ListNode *itFirst = first;
    struct ListNode *itSecond = second;
    if (merged == itFirst) itFirst = itFirst->next;
    else if (merged == itSecond) itSecond = itSecond->next;

    while (itFirst != NULL && itSecond != NULL) {
        if (itFirst->val < itSecond->val) {
            itMerged->next = itFirst;
            itFirst = itFirst->next;
        }
        else {
            itMerged->next = itSecond;
            itSecond = itSecond->next;
        }
        itMerged = itMerged->next;
    }

    while (itFirst != NULL) {
        itMerged->next = itFirst;
        itMerged = itMerged->next;
        itFirst = itFirst->next;
    }

    while (itSecond != NULL) {
        itMerged->next = itSecond;
        itMerged = itMerged->next;
        itSecond = itSecond->next;
    }

    return merged;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *first = head;
    struct ListNode *second = NULL;
    splitList(first, &second);

    struct ListNode *sortedFirst = sortList(first);
    struct ListNode *sortedSecond = sortList(second);
    
    return merge(sortedFirst, sortedSecond);
}
