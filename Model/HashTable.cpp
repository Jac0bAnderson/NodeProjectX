//
//  HashTable.cpp
//  NodeProjectX
//
//  Created by Anderson, Jacob on 5/5/16.
//  Copyright © 2016 Anderson, Jacob. All rights reserved.
//

#include "HashTable.hpp"

template <class Type>
HashTable<Type>::HashTable()
{
    this->capacity = 10;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->internalStorage = new HashNode<Type>[capacity];
}

template <class Type>
int HashTable<Type>::getSize()
{
    return this->size;
}

template <class Type>
HashTable<Type>::~HashTable<Type>()
{
    delete [] internalStorage;
}

template <class Type>
void HashTable<Type>::add(HashNode<Type> * currentNode)
{
    if(!conatins(currentNode))
    {
        if(this->size/this->capacity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        int insertPosition = findPosition(currentNode);
        
        if(internalStorage[insertPosition] != nullptr)
        {
            while (internalStorage[insertPosition] != nullptr)
            {
                insertPosition = (insertPosition + 1) % capacity;
            }
            internalStorage[insertPosition] = currentNode;
        }
        else
        {
            internalStorage[insertPosition] = currentNode;
        }
    }
}

template <class Type>
int HashTable<Type>::findPosition(HashNode<Type> currentNode)
{
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}