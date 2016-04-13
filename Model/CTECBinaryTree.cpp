//
//  CTECBinaryTree.cpp
//  NodeProjectX
//
//  Created by Anderson, Jacob on 4/11/16.
//  Copyright © 2016 Anderson, Jacob. All rights reserved.
//

#include "CTECBinaryTree.hpp"
using namespace std;
template <class Type>
CTECBinaryTree<Type> :: CTECBinaryTree()
{
    root = nullptr;
    height= 0;
    balanced = true;
    size = 0;
}
template <class Type>
void CTECBinaryTree<Type> :: inorderTraversal(TreeNode<Type> * currentNode)
{
 if(currentNode != nullptr)
 {
     inorderTraversal(currentNode->getLeftChild());
     cout << currentNode -> getValue() <<  " ";
     inorderTraversal(currentNode->getRightChild());
     
 }
}
template <class Type>
void CTECBinaryTree<Type> :: preorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode -> getValue() <<  " ";
        preorderTraversal(currentNode->getLeftChild());
        preorderTraversal(currentNode->getRightChild());
        
    }
}
template <class Type>
void CTECBinaryTree<Type> :: postorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        
        postorderTraversal(currentNode->getLeftChild());
        postorderTraversal(currentNode->getRightChild());
        cout << currentNode -> getValue() <<  " ";
        
    }
}
template <class Type>
int CTECBinaryTree <Type> :: getSize()
{
    
    calculateSize(root);
    return size;
}
template <class Type>
void CTECBinaryTree <Type> :: calculateSize(TreeNode <Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        calculateSize(currentNode -> getLeftChild());
        calculateSize(currentNode -> getRightChild());
        size++;
        
    }
}
template<class Type>
bool CTECBinaryTree <Type> :: contains(Type value)
{
    /*
     is the value in root? - return true else
     If the value is not in the root and is less than root- call contains on leftChild
     Else if the value is not in the root and is greater than root - call contains on right child.
     */
    bool isInTree = false;
    if(root -> getValue == value)
    {
        return true;
    }
    else if (value < root -> getValue())
    {
        isInTree = contains(value, root -> getLeftChild());
    }
    else
    {
        isInTree = contains(value, root -> getRightChild());
    }
    return isInTree;
}
template<class Type>
bool CTECBinaryTree <Type> :: contains(Type value, CTECBinaryTree<Type> * currentTree)
{
    /*
     is the value in root? - return true else
     If the value is not in the root and is less than root- call contains on leftChild
     Else if the value is not in the root and is greater than root - call contains on right child.
     */
    if(currentTree == nullptr)
    {
        return false;
    }
    if(currentTree->getRoot() -> getValue == value)
    {
        return true;
    }
    else if (value < currentTree -> getRroot() -> getValue())
    {
        return  contains(value, currentTree->getRoot-> getLeftChild());
    }
    else
    {
        return contains(value, currentTree = getRoot() -> getRightChild());
    }
    
}
template <class Type>
bool CTECBinaryTree <Type> :: insert(const Type& value)
{
    if(contains(value))
    {
        return false;
    }
    else
    {
        if(value < root->getValue())
        {
            
        }
        else
        {
            
        }
        return true;
    }
}
template <class Type>
void CTECBinaryTree<Type> :: insert(const Type& value, CTECBinaryTree<Type> * currentTree)
{
    
}











