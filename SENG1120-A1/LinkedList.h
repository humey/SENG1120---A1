//LinkedList.h file
// Created by Keeylan Hume, C3320396
// SENG1120 Assignment 1

#ifndef SENG1120_LINKEDLIST_H
#define SENG1120_LINKEDLIST_H

#include "Node.h"

using namespace std;

class LinkedList {
public:
typedef string data_type;
    //pre-condition - constructor
    //post-condition - sets values to NULL
    LinkedList();

    //pre-condition - destructor
    //post-condition - While head is not null goes though and deletes all nodes in LinkedList
    ~LinkedList();

    //pre-condition - Sends in the string from LinkedListDemo.cpp, provides an istringstream to manipulate the string
    //                and pull each word to store into a new node. If the LinkedList length is 0 the new node will
    //                be a head, else the node will be adding on as a tail
    //post-condition - updates length by 1 for each node added
    void add(const data_type &newData);

    //pre-condition - returns length of linkedlist
    //post-condition - returns length of linkedlist
    int getLength() const;

    //pre-condition - Stores the data from the current pointers node into data_type data and returns that data
    //post-condition - moves current pointer to next node
    const data_type getData();

    //pre-condition - resetting current pointer back to head node
    //post-condition - resetting current pointer back to head node
    void resetCurrent();

    /*
     * pre-condition - Operator overloader for concatenating LinkedList2 with LinkedList1, creates a temp pointer
     *                 to LinkedList2 head node, iterates through temp while it is not null adding temp data to tail of
     *                 LinkedList1
     * post-condition - Returns reference to LinkedList1
     */
    LinkedList& operator += (const LinkedList& l2);

    //pre-condition - Iterates over the LinkedList and finds the node data with data_type data thats provided
    //post-condition - deletes node respectively if its either the head/tail or middle nodes.
    void remove(data_type data);

    //pre-condition - Passes in data location, iterates over list
    //post-condition - increments count when data matches current and returns count
    int count(data_type data);

private:
    //Node pointers
    Node* head;
    Node* tail;
    Node* current;
    // Length of the LinkedList
    int length;
};

// pre-condition - Overloaded operator
// post-condition - Prints out all the data tokens in each node listed in the LinkedList
ostream& operator << (ostream& os, LinkedList& list);

#endif //SENG1120_LINKEDLIST_H
