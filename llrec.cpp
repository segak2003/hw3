#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  //base case
  if(head == nullptr) 
  {
    larger = nullptr;
    smaller  = nullptr;
    return;
  }
  
  Node* curr = head;
  head = head -> next;
  curr -> next = nullptr;

  if(curr -> val <= pivot)
  {
    smaller = curr;
    llpivot(head, smaller -> next, larger, pivot);
  }
  else{
    larger = curr;
    llpivot(head, smaller, larger -> next, pivot);
  }
}