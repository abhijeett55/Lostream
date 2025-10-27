#pragma once
#ifndef STACKLINKEDLIST_HPP
#define STACKLINKEDLIST_HPP

template <class T>

class StackLinkedList {
public:
    struct Node {
        T data;
        Node *next;
    };

    Node *head;

public:
    StackLinkedList() = default;
    StackLinkedList(StackLinkedList &stackedLinkedList) = delete;
    void push(Node* newNode);
    Node *pop();
};

#include "StackLinkedListImplement.hpp"

#endif