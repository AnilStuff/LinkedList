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
    
    //Appending the data in the linked list
    void appendData(int data);
    
    //Displaying the linked list
    void displayList();
    
    //Removing the last node of the linked list
    void popLastNode();
    
    //Removing the node of the linked list which contains the data
    void popNodeWithData(int data);
    
    // -1 if not found in the location
    int getNodeValueAtLocation(int Location);
    
    // TO find if data exists in the linked list
    bool isNodeFoundWithData(int data);
    
    // To get the location of particular node data
    int getLocationValueAtNodeValue(int value);
    
    // To insert a node after node data
    void insertNodeAfterNodeData(int existingValue, int newValue);
    
    //To get middle element of the list
    int getMiddleElement();
};


int List::getMiddleElement(){
    
    Node *n1 = head;
    Node *n2 = head;

    
    while (n1 !=NULL) {
        n1 = n1->getNextNode();
        
        if (n1!= NULL) {
            n1 = n1->getNextNode();
            n2 = n2->getNextNode();
        }
    }

    return n2->getData();
    
}

void List :: insertNodeAfterNodeData(int existingValue, int newValue){
    Node *tempNode = new Node();
    tempNode->setData(newValue);
    tempNode->setNextNode(NULL);
    
    
    Node *iteratorPtr = head;
    
    
    while (iteratorPtr != NULL) {
        
        if (iteratorPtr->getData() == existingValue) {
//            Node *node = iteratorPtr->getNextNode();
            tempNode->setNextNode(iteratorPtr->getNextNode());
            iteratorPtr->setNextNode(tempNode);
            iteratorPtr = tempNode;

        }else{
            iteratorPtr = iteratorPtr->getNextNode();
        }
        
    }
    
    
}
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
            cout << "Element in linked list at index " << iteratorPtr<< to_string(index)<< " is "<<iteratorPtr->getData()<<endl;
            index++;
            iteratorPtr = iteratorPtr->getNextNode();
            
        }while (iteratorPtr != NULL);
        
    
 }

bool List::isNodeFoundWithData(int data){
    Node *iteratorPtr = head;
    if (iteratorPtr == NULL) {
        cout << "Empty List"<<endl;
        return false;
    }
    
    while (iteratorPtr != NULL) {
        if (iteratorPtr ->getData() == data) {
            return true;
        }
       iteratorPtr = iteratorPtr->getNextNode();
    }
    return false;
}

void List::popNodeWithData(int data){
    Node *current = head;
    Node *prev = NULL ;
    
    if (current == NULL ) {
        cout << "Empty List"<<endl;
        return;
    }
    if (current->getNextNode() == NULL) {
        delete current;
        head = NULL;
        return;
    }
    else if (current->getData() == data){
        prev = current;
        head = head->getNextNode();
    }
    
    else{
    
        do{
            prev = current;

            if (current->getData() == data) {
                break;
            }
             current = current->getNextNode();
            
        }while (current->getData() != data);
    
     
        
    }
    prev->setNextNode(current->getNextNode());
    
    delete current;
    
}


int List:: getNodeValueAtLocation(int Location){
    Node *iteratorPtr = head;
    int Loc = 0;
    
    if (iteratorPtr == NULL) {
        cout<<"List is empty"<<endl;
        return -1;
    }
    
    while (iteratorPtr != NULL) {
        if (Loc == Location) {
            return   iteratorPtr->getData();
        }
        iteratorPtr = iteratorPtr->getNextNode();
        Loc++;
    }
    
    return -1;
 }

int List:: getLocationValueAtNodeValue(int value){
    Node *iteratorPtr = head;
    int Loc = 0;
    
    while (iteratorPtr != NULL) {
        if (value == iteratorPtr->getData()) {
            return Loc  ;
        }
        iteratorPtr = iteratorPtr->getNextNode();
        Loc++;
    }
    
    return -1;
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
    int existingValue,newValue;

    List list = *new List();
    
    list.appendData(13);
    list.appendData(532);
    list.appendData(23);
    list.appendData(52);
    list.appendData(522);
    list.appendData(522);
    list.displayList();

    while (ch != 9) {
        cout<< "------------------------------------------------"<<endl;
        cout<< "Enter 1 to append data in list"<<endl;
        cout<< "Enter 2 to get value at particular location"<<endl;
        cout<< "Enter 3 to display data in list"<<endl;
        cout<< "Enter 4 to pop last element"<<endl;
        cout<< "Enter 5 to pop specific element"<<endl;
        cout<< "Enter 6 to search specific element in list"<<endl;
        cout<< "Enter 7 to insert specific element at location in list"<<endl;
        cout<< "Enter 8 to Find middle element of list"<<endl;
        cout<< "Enter 9 to exit"<<endl;
        cout<< "-- ----------------------------------------------"<<endl;

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
                cout<<"Enter Location which needs to be found : ";
                cin>>number;
                cout << "Node value at location "<<number<<"is"<<list.getNodeValueAtLocation(number)<<endl;
                break;
            case 4:
                list.popLastNode();
                break;
            case 5:
                cout<< "Enter data(Integer) : ";
                cin >> number;
                list.popNodeWithData(number);
                break;
            case 6:
                cout<< "Enter data(Integer) : ";
                cin >> number;
                
                if (list.isNodeFoundWithData(number)) {
                    cout<<"Number Found in list at location "<<list.getLocationValueAtNodeValue(number)<<endl;
                }else{
                    cout<<"Data not present in list";
                }
            break;
                
            case 7:
                cout<<"Enter existing value, new value";
                cin>>existingValue;
                cin>>newValue;
                list.insertNodeAfterNodeData(existingValue, newValue);
                break;
                
            case 8:{
                cout<<"Middle Element is  "<<list.getMiddleElement()<<endl;
            }
            break;
            case 9:
                exit(0);
                break;
        }
    }
    
    return 0;
}
