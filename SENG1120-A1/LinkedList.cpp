// LinkedList.cpp file
// Created by Keeylan Hume, C3320396
// SENG1120 Assignment 1



#include "LinkedList.h"
#include <sstream>
typedef string data_type;

//Default constructor
LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    current = NULL;
    length = 0;
}
//Destructor for the linkedlist
LinkedList::~LinkedList() {
        Node* temp = head;
        while(temp != NULL) {
            Node *nextNode = temp->getNext();
            delete temp;
            temp = nextNode;
        }
}

//picks words seperated by a space via the input string and stores in individual nodes
void LinkedList::add(const data_type &newData) {
    data_type data = newData;
    istringstream iss(newData);
    data_type token;

    while(getline(iss, token, ' ')){
        // If its the first node in the linkedlist
        if(length == 0){
            Node::data_type data = token;
            Node* node = new Node(token);
            head = node;
            tail = node;
            current = node;
        }
        //If the LinkedList has more then 1 node
        else{
            data_type data = token;
            Node* node = new Node(token);
            node->setPrev(tail);
            tail->setNext(node);
            tail = node;
        }
        length++;
    }
}

int LinkedList::getLength() const{
    return length;
}

const data_type LinkedList::getData(){
    data_type data = current->getData();
    current = current->getNext();
    return data;
}

void LinkedList::resetCurrent() {
    current = head;
}

//Overloaded operator to join lists together
LinkedList& LinkedList::operator += (const LinkedList& l2){
    Node* temp = l2.head;
    while(temp != NULL){
        //temp->setData(temp->getData());
        this->add(temp->getData());
        temp = temp->getNext();
    }
    delete temp;
    return *this;
}

// NOTE** the remove function doesnt factor in case sensitive words. To test deleting the head node it needs a lowercase t
void LinkedList::remove(data_type data) {
    for (current = head; current != NULL; current = current->getNext()) {
        // Runs if the data passed in matches the data of the current node pointed too
         if(current->getData() == data) {
             // If the node is the head of the list
             if (current == head) {
                 // If the list only has 1 node
                 if(current == head && current == tail){
                     this->head = NULL;
                     this->tail = NULL;
                     length--;
                     delete current;
                     break;
                 }
                 // If the list has more than 1 node and the data matches the head node
                 else {
                     this->head = this->head->getNext();
                     this->head->setPrev(NULL);
                     current = head;
                     length--;
                 }
             }
             // If the node has nodes either side of it
             else if (current->getNext() != NULL && current->getPrev() != NULL) {
                 current->getPrev()->setNext(current->getNext());
                 current->getNext()->setPrev(current->getPrev());
                 delete current;
                 current = head;
                 length--;

               // If the node is the tail of the list
             } else if (current == tail) {
                 this->tail = this->tail->getPrev();
                 this->tail->setNext(NULL);
                 current = head;
                 length--;
                 break;
             }
         }
    }
}

int LinkedList::count( data_type data) {
    int count = 0;
    for(current = head; current != NULL; current = current->getNext()){
        if(current->getData() == data){
            count++;
        }
    }
    return count;
}

// Overloaded operator to print the data from nodes in the LinkedList
ostream& operator << (ostream& os, LinkedList& list) {
    list.resetCurrent();
    for (int i = 0; i < list.getLength(); i++) {
        os << list.getData() << " ";
    }

    return os;
}