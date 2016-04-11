//
//  TreeNode.cpp
//  NodeProjectX
//
//  Created by Anderson, Jacob on 4/11/16.
//  Copyright © 2016 Anderson, Jacob. All rights reserved.
//

#include "TreeNode.hpp"

template <class Type>
TreeNode<Type> :: TreeNode() : Node<Type>()
{
    this -> leftChild = nullptr;
    this ->rightChild = nullptr;
    this -> parent = nullptr;
}
template <class Type>
TreeNode<Type> :: TreeNode(const Type & value) : Node<Type>(value)
{
    this -> leftChild = nullptr;
    this ->rightChild = nullptr;
    this -> parent = nullptr;
    
    this -> setValue(value);

}
template <class Type>
TreeNode<Type> :: TreeNode(const Type & value , TreeNode<Type> * parent) : Node<Type>(value)
{
    this -> leftChild = nullptr;
    this ->rightChild = nullptr;
   
    
    this -> setValue(value);
    this-> setParent(parent);
    
}

