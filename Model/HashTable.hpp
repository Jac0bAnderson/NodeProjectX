//
//  HashTable.hpp
//  NodeProjectX
//
//  Created by Anderson, Jacob on 5/5/16.
//  Copyright © 2016 Anderson, Jacob. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp
template <class Type>
class HashTable
{
private:
    int capacity;
    double efficiencyPercentage;
    int size;
    Type * internalStorage;
    void updateSize();
    int findPosition(const Type& value);
    int handleCollision(const Type& value);
public:
    HashTable();
    ~HashTable();
    void add(const Type& value);
    bool remove(const Type value);
    bool contains(const Type& value);
    
};
#endif /* HashTable_hpp */

