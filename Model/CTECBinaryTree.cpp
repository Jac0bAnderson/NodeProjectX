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
CTECBinaryTree<Type> :: ~CTECBinaryTree()
{
    while(root != nullptr)
    {
        remove(root);
    }
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
    
    if(root == nullptr)
    {
        isInTree = false;
    }
    else if(root->getValue() == value)
    {
        isInTree = true;
    }
    else if(value < root->getValue())
    {
        isInTree = contains(value,root->getLeftChild());
    }
    else
    {
        isInTree = contains(value, root->getRightChild());
    }
    return isInTree;
}
template<class Type>
bool CTECBinaryTree <Type> :: contains(Type value, TreeNode<Type> * currentTree)
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
    
    if(root->getValue() == value)
    {
        return true;
    }
    else if(value < currentTree->getValue())
    {
        return contains(value, currentTree->getLeftChild());
    }
    else
    {
        return contains(value, currentTree->getRightChild());
    }
}
template <class Type>
bool CTECBinaryTree <Type> :: insert(const Type& value)
{
    TreeNode<Type>* insertedNode = new TreeNode<Type>(value);
    TreeNode<Type>* current;
    TreeNode<Type>* trailingCurrent;
    
    assert(insertedNode != nullptr);
    
    if(contains(value))
    {
        return false;
    }
    else
    {
        if(root == nullptr)
        {
            root = insertedNode;
        }
        else
        {
            current = root;
            
            while(current != nullptr)
            {
                trailingCurrent = current;
                
                if(current->getValue() > value)
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            }
            if(trailingCurrent->getValue() > value)
            {
                trailingCurrent->setLeftChild(insertedNode);
                insertedNode->setParent(trailingCurrent);
            }
            else
            {
                trailingCurrent->setRightChild(insertedNode);
            }
            insertedNode->setParent(trailingCurrent);
        }
        return true;
    }

    }

template<class Type>
void CTECBinaryTree<Type> :: remove(const Type& value)
{
    TreeNode<Type>* current = root;
    TreeNode<Type>* trailing = current;
    
    if(!contains(value))
    {
        return;
    }
    else
    {
        while(current != nullptr && current->getValue() != value)
        {
            trailing = current;
            if(current->getValue() > value)
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        
        if(current == root)
        {
            remove(root);
        }
        else if(trailing->getValue() > value)
        {
            remove(trailing->getLeftChild());
        }
        else
        {
            remove(trailing->getRightChild());
        }        /*
         find the node
         check to see how many child nodes
         if 0 
            delete the node
         else if only left
            replace with left
            deletye the old one
         else if only right
            replac with right
            delete the old one
         else both 
            find LM/RMC
            swap with
            do- left only/right only
         */
         
    }
}
template <class Type>
void CTECBinaryTree<Type> :: remove(TreeNode<Type> * nodeToRemove)
{
    TreeNode<Type>* current;
    TreeNode<Type>* trailing;
    TreeNode<Type>* temp;
    
    if(nodeToRemove == nullptr)
    {
        cerr << "Cannot remove empty node" << endl;
    }
    else if(nodeToRemove->getRightChild() == nullptr && nodeToRemove->getLeftChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = nullptr;
        delete temp;
    }
    else if(nodeToRemove->getRightChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = temp->getLeftChild();
        delete temp;
    }
    else if(nodeToRemove->getLeftChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = temp->getRightChild();
        delete temp;
    }
    else
    {
        current = nodeToRemove->getLeftChild();
        trailing = nullptr;
        
        while(current->getRightChild() != nullptr)
        {
            trailing = current;
            current = current->getRightChild();
        }
        
        nodeToRemove->setValue(current->getValue());
        
        if(trailing == nullptr)
        {
            nodeToRemove->setLeftChild(current->getLeftChild());
        }
        else
        {
            trailing->setRightChild(current->getLeftChild());
        }
        delete current;
    }
}
template <class Type>
void CTECBinaryTree<Type> :: insert(const Type& value, TreeNode<Type> * currentTree)
{
   
    
    }
template <class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getRightMostChild(TreeNode<Type> * leftSubTree)
{
    TreeNode<Type> * rightNode = leftSubTree->getRoot();
    while(rightNode-> getRightChild() != nullptr)
    {
        rightNode = rightNode->getRightChild();
    }
    
    
    return rightNode;
}
template <class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getLeftMostChild(TreeNode<Type> * rightSubTree)
{
    TreeNode<Type> * leftNode = rightSubTree -> getRoot();
    while(leftNode-> getLeftChild() != nullptr)
    {
        leftNode = leftNode -> getLeftChild();
    }
    return leftNode;
}

template <class Type>
TreeNode<Type>* CTECBinaryTree<Type> :: getRoot()
{
    return root;
}
    












