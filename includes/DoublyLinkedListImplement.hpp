#pragma once

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {}


template <class T>
void DoublyLinkedList<T>::insert(Node *previousNode, Node *newNode) {
    if (previousNode == nullptr) {
        if (head != nullptr) {
            newNode->next = head;
            newNode->next->previous = newNode;
        } else {
            newNode->next = nullptr;
        }
        head = newNode;
        head->previous = nullptr;
    } else {
        newNode->next = previousNode->next;
        if(newNode->next != nullptr) {
            newNode->next->previous = newNode;
        }
        previousNode->next = newNode;
        newNode->previous = previousNode;
    }
}


template<class T>
void DoublyLinkedList<T>::remove(Node *deleteNode) {
    if(deleteNode == nullptr) return;

    if(deleteNode->previous == nullptr) {
        if (deleteNode->next == nullptr) {
            head = nullptr;
        } else {
            head = deleteNode->next;
            head->previous = nullptr;
        }
    } else {
        if (deleteNode->next == nullptr) {
            deleteNode->previous->next = nullptr;
        } else {
            deleteNode->previous->next = deleteNode->next;
            deleteNode->next->previous = deleteNode->previous;
        }
    }

    delete deleteNode;
}

