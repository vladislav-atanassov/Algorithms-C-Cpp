#pragma once

#include <iostream>
#include <new>

// Node class to represent
// a node of the linked list.
template<class T>
class ListNode 
{
public:
    T data;
    ListNode<T>* next;
  
    // Constructors
    ListNode();
    
	ListNode(const T& value);
};

// Linked list iterator
template<class T>
class SinglyLinkedListIterator
{
public:
    SinglyLinkedListIterator(ListNode<T>* startNode);

    // Operators
	SinglyLinkedListIterator& operator++();
    
	T& operator*();
    
	bool operator==(const SinglyLinkedListIterator& other) const;
    
	bool operator!=(const SinglyLinkedListIterator& other) const;

private:
    ListNode<T>* current; 
};

// Linked list class
template<class T>
class SinglyLinkedList
{
public:
    // Constructors and destructor
	SinglyLinkedList();
    
	SinglyLinkedList(const T& value);
    
	~SinglyLinkedList();

    // Functions
	ListNode<T>* createNode(const T& value);
    
	void append(const T& data);
    
	void push(const T& data);
    
	void insert(const T& data, int index);
    
	void pop();
    
	void pull();
    
	void deleteAt(int index);
    
	int size() const;
    
	bool empty() const;
    
	void print() const;
    
	T& tail();
    
	T& operator[](int index);
	
	void clear() noexcept;
	
	// Iterator functions
	SinglyLinkedListIterator<T> begin() const;
    
	SinglyLinkedListIterator<T> end() const;

	// Sorting functions
	ListNode<T>* insertionSort();

	template <typename Compare>
	void insertionSort(Compare comp);

protected:
    ListNode<T>* head;
    int elementCount;

    static constexpr short default_validation_index = -1;
    void error_validation(int index = default_validation_index,
			bool if_empty = true, bool if_out_of_range = true) const;
};

#include "SinglyLinkedList.cpp"
