#pragma once
#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

template <class T>
class DoublyLinkedList {
public:
    struct Node {
        T data;
        Node*p revious;
        Node* next;
    };
    Node *head;

public:
    DoublyLinkedList();

    void insert(Node *previousNode, Node *newNode);
    void remove(Node* deleteNode);

private:
    DoublyLinkedList(DoublyLinkedList &doublyLinekdList);
};



#include "DoublyLinkedListImplement.hpp"

#endif