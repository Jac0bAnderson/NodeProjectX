//
//  HashTable.cpp
//  NodeProjectX
//
//  Created by Anderson, Jacob on 5/5/16.
//  Copyright © 2016 Anderson, Jacob. All rights reserved.
//

#include "HashTable.hpp"
#include "Cmath"
template <class Type>
HashTable<Type>::HashTable()
{
    this->capacity = 10;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->internalStorage = new HashNode<Type>[capacity];
     this->tableStorage = new CTECList<HashNode <Type>>[capacity];
}
template <class Type>
int HashTable<Type>::getSize()
{
    return this->size;
}
template <class Type>
void HashTable<Type> :: addToTable(HashNode <Type> currentNode)
{
    if(this->tableSize/this-> tableCapacity >= this-> efficiencyPercentage)
    {
        updateTableCapacity();
    }
    int positionToInsert = findPosition(currentNode);
    if(tableStorage[positionToInsert] == nullptr)
    {
        CTECList<HashNode<Type>> hashList;
        tableStorage[positionToInsert] = hashList;
        hashList.addEnd(currentNode);
    }
    else
    {
        tableStorage[positionToInsert].addEnd(currentNode);
    }
}
template <class Type>
HashTable<Type>::~HashTable<Type>()
{
    delete [] internalStorage;
    delete [] tableStorage;
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
        int positionToInsert = findPosition(currentNode);
        
        if(internalStorage[positionToInsert] != nullptr)
        {
            while (internalStorage[positionToInsert] != nullptr)
            {
                //insertPosition = (insertPosition + 1) % capacity;
                positionToInsert = handleCollision(currentNode);
            }
            
        }
        
            internalStorage[positionToInsert] = currentNode;
        
    }
}

template <class Type>
int HashTable<Type>::findPosition(HashNode<Type> currentNode)
{
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}
template <class Type>
int HashTable<Type> :: getNextPrime()
{
    int nextPrime = (capacity *  2 )+ 1;
    while(!isPrime (nextPrime))
    {
        nextPrime++;
    }
    return nextPrime;
    
}

template <class Type>
void HashTable<Type> :: updateSize()
{
    int updatedCapacity = getNextPrime();
    HashTable<Type> * updatedStorage = new HashTable<Type> [updatedCapacity];
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedPosition = findPosition(internalStorage[index]);
            updatedStorage[updatedPosition] = internalStorage[index];
        }
    }
    
    internalStorage = updatedStorage;
}
template <class Type>
bool HashTable<Type>:: isPrime(int candidateNumber)
{
    bool isPrime = true;
    if(candidateNumber <= 1)
    {
        return false;
    }
    else if(candidateNumber == 2 || candidateNumber == 3)
    {
        isPrime = true;
    }
    else if(candidateNumber % 2 == 0)
    {
        isPrime = false;
    }
    else
    {
        for(int next = 3; next <= sqrt(candidateNumber) +1; next += 2)
        {
            if(candidateNumber % next == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}
template <class Type>
bool HashTable<Type> :: contains(HashNode<Type>  currentNode)
{
    bool isInTable = false;
    int index =findPosition(currentNode);
    while(internalStorage[index] != nullptr && !isInTable)
    {
        if(internalStorage[index].getValue() == currentNode.getValue())
        {
            isInTable = true;
        }
        index = (index + 1) % capacity;
        
    }
    return isInTable;
}
template <class Type>
bool HashTable<Type> :: remove(HashNode<Type>  currentNode)
{
    bool wasRemoved= false;
    if(contains(currentNode))
    {
        int index = findPosition(currentNode);
        while(internalStorage[index] != nullptr && !wasRemoved)
        {
            if(internalStorage[index].getValue() == currentNode.getValue())
            {
                wasRemoved = true;
                internalStorage[index] = nullptr;
                size--;
            }
            else
            {
                index = (index + 1) % capacity;
            }
        }
    }
    return wasRemoved;
}
template <class Type>
int HashTable<Type> :: handleCollision(HashNode<Type>  * currentNode)
{
    int reHashedPosition = findPosition(currentNode);
    int random = rand();
    reHashedPosition = (random + (reHashedPosition * reHashedPosition))  % capacity;
    return reHashedPosition;
}

template <class Type>
void HashTable <Type> :: updateTableCapacity()
{
    int updatedCapacity = getNextPrime();
    CTECList<HashNode<Type>> * updatedTable = new CTECList<HashNode<Type>> [updatedCapacity];
    int oldTableCapacity = updatedCapacity;
    oldTableCapacity = updatedCapacity;
    for(int index = 0; index < oldTableCapacity; index++)
    {
        
        if(tableStorage[index] != nullptr)
        {
            CTECList<HashNode<Type>> temp = tableStorage[index];
            
            for(int innerIndex = 0; innerIndex < tableStorage[index].getSize(); innerIndex++)
            {
                int updatedTablePosition = findPosition(temp.get(index));
                if(updatedTable[updatedTablePosition] == nullptr)
                {
                    CTECList<HashNode<Type>> updatedList;
                    updatedList.addEnd(temp.get(index));
                }
                else
                {
                    updatedTable[updatedTablePosition].addEnd(temp.get(index));
                }
            }
        }
    }
        
        
    tableStorage = updatedTable;
    
    
}



