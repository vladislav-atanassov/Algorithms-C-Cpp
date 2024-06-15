#pragma once

#include <iostream>
#include <new>
#include "SinglyLinkedList.h"

template<class T>
class CircularLinkedList : public SinglyLinkedList<T>
{
public: 
    // Constructors
    CircularLinkedList();
    
    CircularLinkedList(const T& value);
    
    ~CircularLinkedList();
    
    // Functions
    void append(const T& newData);
    
    void push(const T& newData);
    
    void insert(const T& newData, int index);
    
    void pop();
    
    void pull();
    
    void deleteAt(int index);
    
    T& tail();
    
    void print() const;
    
    void clear() noexcept;

protected:
    int elementCount = 0;
    ListNode<T>* traverseToTail() const;
};

#include "CircularLinkedList.cpp"