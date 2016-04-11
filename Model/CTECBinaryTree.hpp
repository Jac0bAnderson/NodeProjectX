//
//  CTECBinaryTree.hpp
//  NodeProjectX
//
//  Created by Anderson, Jacob on 4/11/16.
//  Copyright © 2016 Anderson, Jacob. All rights reserved.
//

#ifndef CTECBinaryTree_hpp
#define CTECBinaryTree_hpp

#include "TreeNode.cpp"
template <class Type>
class CTECBinaryTree
{
private:
    TreeNode<Type> * root;
    int height;
    bool balanced;
    bool contains(Type value, CTECBinaryTree<Type> * currentTree);
    
public:
    CTECBinaryTree();
    ~CTECBinaryTree();
    bool insert(const Type& value);
    bool contains(Type value);
    Type remove(const Type& value);
    int getHeight();
    bool isBalanced();
    TreeNode <Type> * getRoot();
    
};
#endif /* CTECBinaryTree_hpp */
