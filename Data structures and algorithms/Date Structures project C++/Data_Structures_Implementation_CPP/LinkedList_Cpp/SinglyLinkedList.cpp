#ifndef SINGLYLINKEDLIST_CPP
#define SINGLYLINKEDLIST_CPP

#include "SinglyLinkedList.h"

// ListNode definitions
template<class T>
ListNode<T>::ListNode() : data(0), next(nullptr) {}

template<class T>
ListNode<T>::ListNode(const T& value) : data(value), next(nullptr) {}

// SinglyLinkedListIterator definitions
template<class T>
SinglyLinkedListIterator<T>::SinglyLinkedListIterator(ListNode<T>* startNode) : current(startNode) {}

template<class T>
SinglyLinkedListIterator<T>& SinglyLinkedListIterator<T>::operator++()
{
    if(current)
    {
        current = current->next;
    }
    return *this;
}

template<class T>
T& SinglyLinkedListIterator<T>::operator*()
{
    if(current)
    {
        return current->data;
    }
    throw std::out_of_range("Iterator is at end or list is empty");
}

template<class T>
bool SinglyLinkedListIterator<T>::operator==(const SinglyLinkedListIterator& other) const
{
    return current == other.current;
}

template<class T>
bool SinglyLinkedListIterator<T>::operator!=(const SinglyLinkedListIterator& other) const
{
    return !(*this == other);
}

template<class T>
SinglyLinkedListIterator<T> SinglyLinkedList<T>::begin() const
{
    return SinglyLinkedListIterator<T>(head);
}

template<class T>
SinglyLinkedListIterator<T> SinglyLinkedList<T>::end() const
{
    return SinglyLinkedListIterator<T>(nullptr);
}

// SinglyLinkedList definitions
template<class T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), elementCount(0) {}

template<class T>
SinglyLinkedList<T>::SinglyLinkedList(const T& value) : head(createNode(value)), elementCount(1) {}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() { clear(); }

template<class T>
int SinglyLinkedList<T>::size() const { return elementCount; }

template<class T>
bool SinglyLinkedList<T>::empty() const { return !head; }

template<class T>
void SinglyLinkedList<T>::error_validation(int index, bool if_empty, bool if_out_of_range) const
{
	try
	{
		// Check for not passed index variable
		if(index == default_validation_index && (if_empty && if_out_of_range))
		{
			throw std::invalid_argument("Index variable not passed or -1 (Default value for index)");
		}

    	if(if_empty && SinglyLinkedList<T>::empty())
    	{
    	    throw std::runtime_error("List is empty");
    	}
	
		if(if_out_of_range && (index < 0 || index >= elementCount))
    	{
    	    throw std::out_of_range("Index out of range");
    	}
	}
	catch(const std::invalid_argument& inv_arg)
	{
		std::cerr << "Invalid agrument: " << inv_arg.what() << '\n';
	}
	catch(const std::runtime_error& e)
	{
	    std::cerr << "Runtime error: " << e.what() << '\n';
	}
	catch(const std::out_of_range& e)
	{
	    std::cerr << "Out of range exception: " << e.what() << '\n';
	}
}

template<class T>
void SinglyLinkedList<T>::deleteAt(int index)
{
	// Check for error cases
	this->error_validation(index);

	// Check if another function could be used
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

	ListNode<T> *temp1 = head;
	ListNode<T> *temp2 = nullptr;

	temp1 = head;

	// Traverse the list
	for(;index > 0; index--) 
	{
	    temp2 = temp1;
	    temp1 = temp1->next;
	}

	// Change the next pointer
	// of the previous node.
	// head -> node -> temp2 -> temp1 -> node
	//                   ^        |
	//                   |________|
	
	// Deletes at the wanted position
	temp2->next = temp1->next;
	
    delete temp1;

	elementCount--;
}

template<class T>
void SinglyLinkedList<T>::pop()
{
	this->error_validation(default_validation_index, true, false);
	elementCount--;

	if(!head->next) 
	{
		delete head;
		head = nullptr;
		return;
	}

	ListNode<T>* temp1 = head;
	ListNode<T>* temp2 = nullptr;

	// Traverse the list
	while(temp1->next)
	{
		temp2 = temp1;
		temp1 = temp1->next;
	}

	// Delete the last element
	temp2->next = nullptr;

	delete temp1;
}

template<class T>
void SinglyLinkedList<T>::pull() 
{
	this->error_validation(default_validation_index, true, false);

	ListNode<T>* temp = head;

	// Delete the head
	head = head->next;
	temp->next = nullptr;

	delete temp;
}

template <class T>
ListNode<T>* SinglyLinkedList<T>::createNode(const T& value)
{
    ListNode<T>* newNode = nullptr;

    try
    {	
		// Allocate memory and call the 
		// parameterized constructor of ListNode
        newNode = new ListNode<T>(value);
    }
    catch(const std::bad_alloc& bad_al)
    {
        std::cerr << "std::bad_alloc caught: " << bad_al.what() << '\n';
        return nullptr;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return nullptr;
    }

	this->elementCount++;
    return newNode;
}

template<class T>
void SinglyLinkedList<T>::append(const T& data)
{
	// Create the new Node.
	ListNode<T>* newNode = this->createNode(data);

	// If first assign to head
	if(!head) 
    {
		head = newNode;
		return;
	}
	
	ListNode<T>* temp = head;

	// Traverse until the end of list
	while(temp->next) 
    {
		temp = temp->next;
	}

	// Insert at the last position

	// head -> node -> /newNode/ -> nullptr
	//                   ^
	//                   |
	//         newNode----

	temp->next = newNode;
}

template<class T>
void SinglyLinkedList<T>::push(const T& data)
{
	// Create the new Node.
	ListNode<T>* newNode = this->createNode(data);

	// /newNode/ -> head -> node -> nullptr
	// 	   ^
	// 	   |
	// 	   ----- newNode

	// Insert at the first position
    newNode->next = head;
    head = newNode;
}

template<class T>
void SinglyLinkedList<T>::insert(const T& data, int index)
{
	// Check for error case
	this->error_validation(index, false);

	// Check if another function could be used
	if(index == (this->size() - 1))
	{
		this->append(data);
		return;
	}
	else if(index == 0)
	{
		this->push(data);
		return;
	}

	ListNode<T> *temp1 = head;
	ListNode<T> *temp2 = nullptr;

	// Create the new Node.
	ListNode<T>* newNode = this->createNode(data);
	
	// Traverse the list
	for(;index > 0; index--) 
	{
	    temp2 = temp1;
	    temp1 = temp1->next;
	}

	// head -> node -> temp2 -> /newNode/ -> temp1
	//                           	^
	//                           	|
	//                           	---newNode
	
	// Inserts at the wanted positon
	temp2->next = newNode;
	newNode->next = temp1;
} 

template<class T>
T& SinglyLinkedList<T>::tail()
{
	// Check for error cases
	this->error_validation(default_validation_index, true, false);

	ListNode<T>* temp = head;
	
	// Traverse the list
	while(temp->next)
	{
		temp = temp->next;
	}

	return temp->data;
}

template<class T>
T& SinglyLinkedList<T>::operator[](int index)
{
	// Check for error cases
	this->error_validation(index);

	// Check if another functionallity could be used
	if(index == 0)
	{
		return head->data;
	}
	else if(index == (this->size() - 1))
	{
		return this->tail();
	}

	ListNode<T>* temp = head;

	// Traverse the list
	for(;index > 0; index--)
	{
		temp = temp->next;
	}
	
	return temp->data;
}

template<class T>
ListNode<T>* SinglyLinkedList<T>::insertionSort()
{
    if(head == nullptr || head->next == nullptr)
	{
        return head;
	}

    ListNode<T>* sortedHead = nullptr; // Initialize sorted list as empty

    while(head != nullptr)
    {
        ListNode<T>* current = head;
        head = head->next;

        if(sortedHead == nullptr || current->data < sortedHead->data)
        {
            // Insert at the beginning of the sorted list
            current->next = sortedHead;
            sortedHead = current;
        }
        else
        {
            ListNode<T>* temp = sortedHead;
            while(temp->next != nullptr && current->data >= temp->next->data)
            {
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }
    }

    head = sortedHead; // Update head to point to the sorted list
    return head;
}

template<class T>
template<typename Compare>
void SinglyLinkedList<T>::insertionSort(Compare comp) 
{
    if(head == nullptr || head->next == nullptr)
        return;

    ListNode<T>* sortedHead = nullptr; // Initialize sorted list as empty

    while(head != nullptr) 
	{
        ListNode<T>* current = head;
        head = head->next;

        if(sortedHead == nullptr || 
			comp(current->data, sortedHead->data)) 
		{
            // Insert at the beginning of the sorted list
            current->next = sortedHead;
            sortedHead = current;
        } 
		else 
		{
            ListNode<T>* temp = sortedHead;

            while(temp->next != nullptr && 
					!comp(current->data, temp->next->data)) 
			{
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }
    }

    head = sortedHead; // Update head to point to the sorted list
}

template<class T>
void SinglyLinkedList<T>::print() const
{
	if(this->empty())
		return;

	std::cout << "Elements of the list are: ";;

	// Traverse the list
	for(auto& item : *this)
	{
		std::cout << item << " ";
	}

	std::cout << std::endl;
}

template<class T>
void SinglyLinkedList<T>::clear() noexcept
{
    ListNode<T>* temp = head;

    while(temp)
    {
        ListNode<T>* next = temp->next;
        temp->next = nullptr;

        delete temp;

        temp = next;
    }
	
    head = nullptr;
}

#endif // SINGLYLINKEDLIST_CPP