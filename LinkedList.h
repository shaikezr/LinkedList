
// File: LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

class LinkedList {
  private:
      struct Node {
          float value;
          Node *next;
      };
      Node *head; // head pointer

  public:
     LinkedList(){head = NULL;} // constructor

	  //pre: val is a real number
	  //post: all duplicate nodes with val are deleted from the list.
	  //      (i.e. the list can have one node with val)
	  void deleteDuplicates(float val);
  
 
	  // pre: val is a real number
	  // post: return true if the list has duplicate nodes with val;
	  //       return false otherwise
	  bool isDuplicate(float val);
  
      
      // pre: none
      // post: list is merged to "this" list.
       void merge(const LinkedList& list);
      
      
       ~LinkedList(); //destructor
       
       // pre: none
      // post: list values are printed to console.
      void displayList();

      //pre: val is a real number
      //post: a new node with value equal to 
      //      val has been appended to the list.
      void appendNode(float val);
    

  };  // END LINKEDLIST


#endif
