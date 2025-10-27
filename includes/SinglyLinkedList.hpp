#pragma once
#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

template <class T>
class SinglyLinkedList {
public:
    struct Node {
        T data;
        Node *next;
    };

    Node *head;


public:
    SinglyLinkedList();

    void insert(Node *previousNode, Node *newNode);
    void remove(Node* previousNode, Node * deleteNode);
};

#include "SinglyLinkedListImplement.hpp"

#endif