#include <iostream>
#include <vector>
using namespace std;

class ListNode{
public:
    int val=1;
    ListNode *next = NULL;
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){return l2;}
        if(l2 == NULL){return l1;}
        ListNode *p1 = l1, *p2 = l2, *p;
        if(p1->val < p2->val){p = p1;p1 = p1->next;}
        else{p=p2;p2 = p2->next;}
        ListNode *head = p;
        while(p1 != NULL && p2 != NULL){
        if(p1->val < p2->val){p->next = p1;p = p1;p1 = p1->next;}
        else{p->next=p2;p=p2;p2 = p2->next;}
        }
        if(p1 == NULL){p->next = p2;}
        else{p->next = p1;}
        return head;
    }
};
int main(){
    ListNode n11,n12,n13,n21,n22,n23;
    n11.val = 1;
    n12.val = 2;
    n13.val = 4;
    n21.val = 1;
    n22.val = 3;
    n23.val = 4;
    n11.next = &n12;
    n12.next = &n13;
    n21.next = &n22;
    n22.next = &n23;
    Solution sol;
    ListNode *res = sol.mergeTwoLists(&n11, &n21);
    while(res != NULL){
        cout<<res->val<<endl;
        res = res->next;
    }

    getchar();
    return 0;
}