#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "CircularLinkedList.h"

template<class T>
CircularLinkedList<T>::CircularLinkedList() : SinglyLinkedList<T>() {}

template<class T>
CircularLinkedList<T>::CircularLinkedList(const T& value) : SinglyLinkedList<T>(value) {}

template<class T>
CircularLinkedList<T>::~CircularLinkedList() { this->clear(); }

template<class T>
ListNode<T>* CircularLinkedList<T>::traverseToTail() const
{
    ListNode<T>* temp = this->head;

    while(temp->next != this->head)
    {
        temp = temp->next;
    }

    return temp;
}

template<class T>
void CircularLinkedList<T>::deleteAt(int index)
{
    this->error_validation(index);

    if(index == 0)
    {
        this->pull();
        return;
    }
    else if(index == (this->size() - 1))
    {
        this->pop();
        return;
    }

    ListNode<T>* temp1 = this->head;
    ListNode<T>* temp2 = nullptr;

    for(; index > 0; index--)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
    delete temp1;

    elementCount--;
}

template<class T>
void CircularLinkedList<T>::pop()
{
    this->error_validation(this->default_validation_index, true, false);

    if(!this->head->next)
    {
        delete this->head;
        this->head = nullptr;
        return;
    }

    ListNode<T>* temp1 = this->head;
    ListNode<T>* temp2 = nullptr;

    while(temp1->next != this->head)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
    delete temp1;

    elementCount--;
}

template<class T>
void CircularLinkedList<T>::pull()
{
    this->error_validation(this->default_validation_index, true, false);

    if(this->head->next == this->head)
    {
        delete this->head;
        this->head = nullptr;
        return;
    }
    
    ListNode<T>* temp = traverseToTail();

    temp->next = this->head->next;
    delete this->head;
    this->head = temp->next;

    elementCount--;
}

template<class T>
void CircularLinkedList<T>::append(const T& newData)
{
    ListNode<T>* newNode = this->createNode(newData);

    if(!this->head)
    {
        this->head = newNode;
        this->head->next = this->head; // Make it circular
        return;
    }

    ListNode<T>* temp = traverseToTail();

    temp->next = newNode;
    newNode->next = this->head;
}

template<class T>
T& CircularLinkedList<T>::tail()
{
    this->error_validation(this->default_validation_index, true, false);

    return traverseToTail()->data;
}

template<class T>
void CircularLinkedList<T>::push(const T& newData)
{
    ListNode<T>* newNode = this->createNode(newData);

    if(!this->head)
    {
        this->head = newNode;
        this->head->next = this->head; // Make it circular
        return;
    }

    ListNode<T>* temp = traverseToTail();

    newNode->next = this->head;
    this->head = newNode;
    temp->next = this->head;
}

template<class T>
void CircularLinkedList<T>::insert(const T& newData, int index)
{
    this->error_validation(index, false);

    if(index == (this->size() - 1))
    {
        this->append(newData);
        return;
    }
    else if (index == 0)
    {
        this->push(newData);
        return;
    }

    ListNode<T>* temp1 = this->head;
    ListNode<T>* temp2 = nullptr;

    ListNode<T>* newNode = this->createNode(newData);

    for(; index > 0; index--)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = newNode;
    newNode->next = temp1;
}

template<class T>
void CircularLinkedList<T>::print() const
{
    if(this->empty())
        return;

    std::cout << "Elements of the list are: ";

    ListNode<T>* temp = this->head;

    do
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while(temp != this->head);

    std::cout << std::endl;
}

template<class T>
void CircularLinkedList<T>::clear() noexcept
{
    if(!this->head)
        return;

    ListNode<T>* temp = this->head;

    do
    {
        ListNode<T>* nextNode = temp->next;
        temp->next = nullptr;

        delete temp;

        temp = nextNode;
    } while(temp != this->head);

    this->head = nullptr;
}

#endif // CIRCULARLINKEDLIST_H