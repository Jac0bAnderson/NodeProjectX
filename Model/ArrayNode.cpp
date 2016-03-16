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

	this->value = value;
	this->next = nullptr;
}


template <class Type>
ArrayNode<Type>::ArrayNode(const Type& value, ArrayNode * next) : Node<Type>(value)
{

	this->value = value;
	this->next = next;
}


template <class Type>
 ArrayNode<Type>::~ArrayNode()
{

}

template <class Type>
void ArrayNode<Type> :: setNext(ArrayNode<Type> * next)
{

}

template <class Type>
ArrayNode<Type> * ArrayNode<Type> :: getNext()
{
	return this->next;
}
