// Problem Link : https://leetcode.com/problems/add-two-numbers/
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
// and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int data;
    ListNode *next;
    ListNode(int x){
        data = x;
        next = nullptr;
    }


};
// Traverse the two linked lists in order to add preceding zeros in case a list is having lesser digits than the other one.
// Start from the head node of both lists and call a recursive function for the next nodes.
// Continue it till the end of the lists.
// Creates a node for current digits sum and returns the carry
// // TIME COMPLEXITY O(L)
ListNode *Add_Numbers(ListNode *l1,ListNode *l2){
    if(!l1) return l2;
    if(!l2) return l1;
    int carry = 0;
    ListNode *newhead = new ListNode(0);
    ListNode *temp = newhead;
    while(l1 != nullptr || l2 != nullptr || carry > 0){
       int sum = 0;
       sum += carry;
        if(l1 != nullptr){
            sum += l1->data;
            l1 = l1->next;
        }
        if(l2 != nullptr){
            sum += l2->data;
            l2 = l2->next;
        }
        
        ListNode *n = new ListNode(sum%10);
        temp->next = n;
        temp = temp->next;
        carry = sum/10;


    }
    if(carry > 0){
        ListNode *n = new ListNode(carry);
        temp->next = n;
        temp = temp->next;
    }
    return newhead->next;
}

void printList(ListNode *l1){
    ListNode *temp = l1;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}
int main(){

ListNode *head1 = new ListNode(3);
head1->next = new ListNode(4);
head1->next->next = new ListNode(2);

ListNode *head2 = new ListNode(4);
head2->next = new ListNode(6);
head2->next->next = new ListNode(5);

printList(head1);
cout<<" ";
printList(head2);
cout<<endl;
printList(Add_Numbers(head1,head2));
return 0;
}
