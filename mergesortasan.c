#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "simpleCSVsorter.h"

  
  // sorts LL 
  
void MergeSort (Node** headRef){
    Node* head = *headRef;
    Node* a;
    Node* b;

    if((head == NULL) || (head->next == NULL)){
      return;
    }
  // split head into 'a' 'b'
    FrontBackSplit(head, &a, &b);
    
    MergeSort(&a);
    MergeSort(&b);
    
    *headRef = SortedMerge(a, b);
}
    
Node* SortedMerge(Node* a, Node* b){ 
  Node* result = NULL; 
  int cmp=0;
  
  if (a == NULL) 
    return(b); 
  else if (b == NULL) 
    return(a);
      
  cmp = strcmp(a->data, b->data);
 
  if(cmp <= 0){
    result=a;
    result->next=SortedMerge(a->next, b);
  }else{
    result=b;
    result->next=SortedMerge(a, b->next);
  }
  return(result);
}
      
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef){
      Node* fast;
      Node* slow;
      slow = source;
      fast = source->next;
      
      while(fast != NULL){
        fast = fast->next;
        if(fast != NULL)
        {
          slow = slow->next;
          fast = fast->next;
        }
      
      //assign the front and back to a and b
      *frontRef = source;
      *backRef = slow->next;
      slow->next = NULL;
    }

  }

