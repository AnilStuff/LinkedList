//
//  DoublyLinkedList.cpp
//  LinkedList
//
//  Created by Anil Kothari on 14/02/17.
//  Copyright © 2017 Anil Kothari. All rights reserved.
//

#include <iostream>

class Node{
    int data;
    Node *nextNode;
    Node *prevNode;
public:
    Node* getPrevNode(){return prevNode;}
    Node* getNextNode(){return nextNode;}
    int getData(){return data;}
    
    void setPrevNode(Node *n){prevNode = n;}
    void setNextNode(Node *n){nextNode = n;}
    void setDataValue(int d){data = d;}
};


class DList{
    Node *head;
    
public:
    DList(){head = NULL;}
    
};



