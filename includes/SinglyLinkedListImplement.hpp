#pragma once


template<class T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr) {}

template <class T>
void SinglyLinkedList<T>::insert(Node *previousNode, Node *newNode) {
    if (previousNode == nullptr) {
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }
}

template<class T>

void SinglyLinkedList<T>::remove(Node* previousNode, Node* deleteNode) {
    if(previousNode == nullptr) {
        head = deleteNode->next;
    } else {
        previousNode->next = deleteNode->next;
    }
    delete deleteNode;
}
