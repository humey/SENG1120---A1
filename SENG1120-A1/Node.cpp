//Node.cpp file
// Created by Keeylan Hume, C3320396
// SENG1120 Assignment 1

#include "Node.h"
#include <cstdlib>
#include <string>

using namespace std;

typedef string data_type;

Node::Node(data_type &newData) {
    data = newData;
    next = NULL;
    prev = NULL;
}

void Node::setData(data_type &newData) {
    data = newData;
}

data_type Node::getData() const{
    return data;
}

Node* Node::getNext() const{
    return next;
}

void Node::setNext(Node *nextLink) {
    next = nextLink;
}

Node* Node::getPrev() const{
    return prev;
}

void Node::setPrev(Node *prevLink) {
    prev = prevLink;
}