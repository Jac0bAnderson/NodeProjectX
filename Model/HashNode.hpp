//
//  HashNode.hpp
//  NodeProjectX
//
//  Created by Anderson, Jacob on 5/9/16.
//  Copyright © 2016 Anderson, Jacob. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_hpp
#include <iostream>
template <class Type>
class HashNode
{
private:
    int key;
    Type value;
public:
    HashNode(int key, const Type& value);
    void setKey(int key);
    void setValue(const Type value);
    int getKey();
    Type getValue();};

#endif /* HashNode_hpp */
