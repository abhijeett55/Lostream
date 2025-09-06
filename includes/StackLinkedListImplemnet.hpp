#pragma once 

template <class T>
void StackLinkedList<T>::push(Node *newNode) {
    newNode->next = head;
    head = newNode;
}

template<class T>
typename StackLinkedList<T>::Node* StackLinkedList<T>::pop() {
    if(!head) return;
    Node *top = head;
    head = head->next;
    top->next = nullptr;
}

