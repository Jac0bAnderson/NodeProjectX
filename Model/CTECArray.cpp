/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: jand6944
 */

#include "CTECArray.h"
#include <assert.h>
#include <iostream>

using namespace std;
/**
 * gets the values in the array
 */
template<class Type>
CTECArray<Type>::CTECArray(int size)
{

	this->size = size;
	this->head = nullptr;

	assert(size > 0);

	for (int index = 0; index < size; index++)
	{
		if (head !=  nullptr)
		{
			//We have more than one arrayNode
			ArrayNode<Type> * nextNode = new ArrayNode<Type>();
			nextNode->setNext(head);
			head = nextNode;
		} else
		{
			//this is the first in the array
			ArrayNode<Type> * first = new ArrayNode<Type>();
			head = first;
		}
	}

}

template<class Type>
CTECArray<Type>::~CTECArray()
{
	ArrayNode<Type> * deleteMe = head;
	for (int index = 0; index < size; index++)
	{
		if (deleteMe->getNext() != nullptr)
		{
			head = deleteMe->getNext();
			deleteMe->setNext(nullptr);
		} else
		{
			delete deleteMe->getNext();
			deleteMe = head;
		}
	}
	delete head;
}

template<class Type>
int CTECArray<Type>::getSize()
{
	return this->size;
}

template<class Type>
Type CTECArray<Type>:: get(int position)
{

	//Bounds check for size and negative
	assert(position < size && position < 0);

	ArrayNode<Type> * current = head;
	//Inclusive becase I am inside the bounds :)>
	for (int spot = 0; spot <= position; spot++)
	{

		if (spot != position)
		{
			current = current->getNext();
		} else
		{
			return current->getValue();
		}
	}
    return current->getValue();
}
/**
 1) Assert size is greater than 0.
 2) Declare and init valid return variable.
 3) Reference to head and loop
 4)if there, return index, else go to next.
 5)return index
 */
template <class Type>
int CTECArray<Type> :: indexOf(Type searchValue)
{
    assert(this->size >0);
    
    
    int indexNotFound = -1;
    
    ArrayNode<Type> * current = head;
    
    for(int index = 0; index < this->size; index++)
    {
        if(current->getValue() == searchValue)
        {
            return index;
        }
        else
        {
            current = current->getNext();
        }
    }
    return indexNotFound;
}
template <class Type>
int CTECArray<Type> :: nextIndexOf(int startingIndex, Type searchValue)
{
    assert(this->size >0);
    assert(startingIndex >= 0 && startingIndex < this->size);
    
    int indexNotFound = -1;
     ArrayNode<Type> * current = head;
    for(int index = 0; index < startingIndex; index++)
    {
        current = current->getNext();
    }
   
    
    for(int index = 0; index < this->size; index++)
    {
        if(current->getValue() == searchValue)
        {
            return index;
        }
        else
        {
            current = current->getNext();
        }
    }
    return indexNotFound;
}


template<class Type>
void CTECArray<Type>::set(int position, const Type& value)
{
assert(position < size && position >= 0);

ArrayNode<Type> * current = head;
for (int spot = 0; spot <= position; spot++)
{
	if (spot != position)
	{
		current = current->getNext();
	} else
	{
		current->setValue(value);
	}
}

}
