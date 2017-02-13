//
//  main.cpp
//  LinkedList
//
//  Created by Rakesh Kothari on 13/02/17.
//  Copyright © 2017 Anil Kothari. All rights reserved.
//

#include <iostream>
#include "String"

using namespace std;

class Node{
    int data;

    Node *nextNode;
public:

    void setNextNode(Node *node){
        nextNode = node;
    }
    Node* getNextNode(){return nextNode;}

    void setData(int d){
        data = d;
    }
    int getData(){return data;}
};


class List {
    Node *head;
    
public:
    List(){head = NULL;}
    void appendData(int data);
    void displayList();
    void popLastNode();
};



void List :: appendData(int data){
    
    Node *tempNode = new Node();
    tempNode->setData(data);
    tempNode->setNextNode(NULL);
    
    Node *iteratorPtr = head;
    
    
    if (iteratorPtr != NULL) {
        
        while (iteratorPtr->getNextNode() != NULL) {
            iteratorPtr = iteratorPtr->getNextNode();
        }
        
        iteratorPtr->setNextNode(tempNode);
        
    }else{
        head = tempNode;
    }
    
    
}

void List:: displayList(){
    
    Node *iteratorPtr = head;
    int index = 0;
    
    if (iteratorPtr == NULL) {
         cout << "Empty List"<<endl;
        return;
    }
        do {
            index++;
            cout << "Element in linked list at index " << to_string(index)<< " is "<<iteratorPtr->getData()<<endl;;
            iteratorPtr = iteratorPtr->getNextNode();
            
        }while (iteratorPtr != NULL);
        
    
 }

void List:: popLastNode(){
    Node *iteratorPtr = head;
    Node *secondLastNode ;

    if (iteratorPtr == NULL ) {
        cout << "Empty List"<<endl;
        return;
    }else{
        secondLastNode = iteratorPtr->getNextNode();
    }
   
    if (secondLastNode == NULL){
        head = NULL;
        return;
    }
    
    
    while (secondLastNode->getNextNode() != NULL) {
        secondLastNode = secondLastNode->getNextNode();
        iteratorPtr = iteratorPtr->getNextNode();
    }
    
    iteratorPtr->setNextNode(NULL);//() = NULL;
    
}



int main(int argc, const char * argv[]) {
    
     int ch;
    int number;
    
    List list = *new List();
    
    
    while (ch != 'e') {
        cout<< "-------------------------------------"<<endl;
        cout<< "Enter 1 to append data in list"<<endl;
        cout<< "Enter 2 to end the program"<<endl;
        cout<< "Enter 3 to display data in list"<<endl;
        cout<< "Enter 4 to pop last element"<<endl;
        cout<< "-- -----------------------------------"<<endl;

        cin >> ch;
        
        
        switch (ch) {
            case 1:
                cout<< "Enter data(Integer) : ";
                cin >> number;
                 list.appendData(number);
                break;
            case 3:
                list.displayList();
                break;
            case 2:
                exit(0);
                break;
            case 4:
                list.popLastNode();
                break;
            default:
                break;
        }
    }
    
    return 0;
}
