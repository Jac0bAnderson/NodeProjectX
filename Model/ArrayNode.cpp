/*
 * ArrayNode.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: jand6944
 */

#include "ArrayNode.h"

/**
 * gets the  value of the nodes
 */
template <class Type>
ArrayNode<Type>::ArrayNode() : Node<Type>()
{

	this->next = nullptr;

}

template <class Type>
ArrayNode<Type>::ArrayNode(const Type& value) : Node<Type>(value)
{

    this->next = nullptr;
    this->setValue(value);
}


template <class Type>
ArrayNode<Type>::ArrayNode(const Type& value, ArrayNode * next) : Node<Type>(value)
{

    this->setValue(value);
	this->next = next;
}


template <class Type>
 ArrayNode<Type>::~ArrayNode()
{

}

template <class Type>
void ArrayNode<Type> :: setNext(ArrayNode<Type> * next)
{
 this->next = next;
}

template <class Type>
ArrayNode<Type> * ArrayNode<Type> :: getNext()
{
	return this->next;
}
