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
