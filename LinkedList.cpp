
// FILE:  LinkedList.cpp

// IMPLEMENTATION FILE FOR CLASS LinkedList

#include "LinkedList.h"

  //pre: val is a real number
  //post: all duplicate nodes with val are deleted from the list.
  //      (i.e. the list can have one node with val)
  void LinkedList :: deleteDuplicates(float val){
  	bool startDelete = false;
  	Node *preNode, *curNode, *nextNode;
  	curNode = head;
  	while (curNode != NULL){
  		if ( (curNode->value == val) && (startDelete == false) ){ //sets startDelete to true and skips the first instance of val
  			startDelete = true;
  			preNode = curNode;
  			curNode = curNode->next;
  		}
  		else if ( (curNode->value == val) && (startDelete == true) && (curNode->next != NULL) ){ //for subsequent instances of val in the middle of the list
  			nextNode = curNode->next;
  			preNode->next = nextNode;
  			delete curNode;
        if (isDuplicate(val)){ 
          deleteDuplicates(val);
        }
        break;
  		}
  		else if ( (curNode->value == val) && (startDelete == true) && (curNode->next == NULL) ){ //for subsequent instanves of val if val is the last node of the list
        preNode->next = NULL; //http://stackoverflow.com/questions/19326017/deleting-the-back-element-in-a-linked-list
        if (curNode != NULL){  
          delete curNode;
        }
        if (isDuplicate(val)){
          deleteDuplicates(val);
        }
        break;
  		}

  		else if ( (curNode->value != val) && (curNode->next != NULL) ){
  			preNode = curNode;
  			curNode = curNode->next;
  		}
  	}	  				
  }

  
 
  // pre: val is a real number
  // post: return true if the list has duplicate nodes with val;
  //       return false otherwise
  bool LinkedList :: isDuplicate(float val){
  	Node *curNode;
  	curNode = head;
  	int count = 0;
  	while (curNode != NULL){
  		if (curNode->value == val){
  			count++;
  		}
  		curNode = curNode->next;
  		if (count > 1){
  			return true;
  		}
  	}	
  	return false;
  }
  
   
  // pre: none
  // post: list l is merged to self.
  void LinkedList :: merge(const LinkedList& l){
    Node *curNode, *nextNode;
    curNode = head;
    while (curNode->next != NULL){
      curNode = curNode->next;
    }

    curNode->next = l.head;
  }

 void LinkedList :: appendNode(float val){
	Node *newNode, *nodePtr;
	newNode = new Node;
	newNode->value = val;
	newNode->next = NULL;
	// If there are no nodes in the list
	// make newNode the first node
	if (!head){
		head = newNode;
	}
	else // Otherwise, insert newNode at end
	{
	// Initialize nodePtr to head of list
		nodePtr = head;
	// Find the last node in the list
		while (nodePtr -> next){
			nodePtr = nodePtr -> next;
		}
	// Insert newNode as the last node
		nodePtr -> next = newNode;
	}
}
	
	// pre: none
	//post: list has been deallocated
	LinkedList :: ~LinkedList()
	{
	   Node *nodePtr, *nextNode;
	   nodePtr = head;
	   while (nodePtr != NULL)
	   {
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		}
	}
	
	
  // pre: none
  // post: list values are printed to console.
  void  LinkedList :: displayList(){
	Node *nodePtr;
	nodePtr = head;
	while (nodePtr)
	{
		cout << nodePtr->value<<endl;
    nodePtr = nodePtr->next;
    }
	
	}
  
	
	
	
