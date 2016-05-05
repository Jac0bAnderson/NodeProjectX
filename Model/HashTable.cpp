//
//  HashTable.cpp
//  NodeProjectX
//
//  Created by Anderson, Jacob on 5/5/16.
//  Copyright © 2016 Anderson, Jacob. All rights reserved.
//

#include "HashTable.hpp"

template <class Type>
HashTable<Type> ::  HashTable()
{
    this-> capacity = 10;
    this-> efficiencyPercentage = .667;
    this-> size = 0;
    this-> internalStorage = new Type(capacity);
}
template <class Type>
HashTable<Type> :: ~HashTable<Type>()
{
    delete [] internalStorage;
}
template <class Type>
int HashTable<Type> :: getSize()
{
    return this -> size();
}
template <class Type>
void HashTable<Type> :: add(const Type& value)
{
    if(!contains(value))
    {
        int positionToInsert = findPosition(value);
        
        if(internalStorage[positionToInsert] != nullptr)
        {
            while(internalStorage [positionToInsert] != nullptr)
            {
                positionToInsert = (positionToInsert +1) % size;
            }
            internalStorage[positionToInsert] = value;
        }
        else
        {
            internalStorage[positionToInsert] = value;
        }
    }
}