//
//  CTECBinaryTree.hpp
//  NodeProjectX
//
//  Created by Anderson, Jacob on 4/11/16.
//  Copyright © 2016 Anderson, Jacob. All rights reserved.
//

#ifndef CTECBinaryTree_hpp
#define CTECBinaryTree_hpp
#include "../Model/Node.h"
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.h"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.h"
#include "../Model/CTECArray.cpp"
#include "../Model/Timer.h"
#include "../Model/CTECBinaryTree.cpp"
#include "TreeNode.cpp"
template <class Type>
class CTECBinaryTree
{
private:
    TreeNode<Type> * root;
    int size;
    int height;
    bool balanced;
    void insert(const Type& value, CTECBinaryTree<Type> * currentTree);
    bool contains(Type value, CTECBinaryTree<Type> * currentTree);
    void calculateSize(TreeNode <Type> * currentNode);
    TreeNode<Type> * getRightMostChild(CTECBinaryTree * leftSubTree);
    TreeNode<Type> * getLeftMostChild(CTECBinaryTree * rightSubTree);
    void remove(TreeNode<Type> * nodeToRemove);
    void tryTree();
    
    
public:
    CTECBinaryTree();
    ~CTECBinaryTree();
    bool insert(const Type& value);
    bool contains(Type value);
    void remove(const Type& value);
    int getHeight();
    int getSize();
    bool isBalanced();
    TreeNode <Type> * getRoot();
    void inorderTraversal(TreeNode<Type> * currentNode);
    void postorderTraversal(TreeNode<Type> * currentNode);
    void preorderTraversal(TreeNode<Type> * currentNode);
    
};
#endif /* CTECBinaryTree_hpp */
