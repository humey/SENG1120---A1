//Node.h file
// Created by Keeylan Hume, C3320396
// SENG1120 Assignment 1

#ifndef SENG1120_NODE_H
#define SENG1120_NODE_H

#include <cstdlib>
#include <string>

using namespace std;


class Node {
public:

  typedef string data_type;  

        //constructor adding data
        Node(data_type &newData);

        //Pre-condition - Sets next node
        //Post-condition - Sets next node
        void setNext(Node* nextLink);

        //Pre-condition - Sets prev node
        //Post-condition - Sets prev node
        void setPrev(Node* prevLink);

        //Pre-condition - Sets data
        //Post-condition - Sets data
        void setData(data_type& newData);

        //Pre-condition - Returns data
        //Post-condition - Returns data
        data_type getData() const;

        //Pre-condition - Returns next node
        //Post-condition - Returns next node
        Node* getNext() const;

        //Pre-condition - Returns prev node
        //Post-condition - Returns prev node
        Node* getPrev() const;

private:
    // Holds data
    data_type data;
    //Next node and Prev node pointers
    Node* next;
    Node* prev;
};

#endif //SENG1120_NODE_H
