//
//  binaryTree.h
//  BinaryTree
//
//  Created by Whoami on 14/11/12.
//  Copyright (c) 2014年 Whoami. All rights reserved.
//

#ifndef __BinaryTree__binaryTree__
#define __BinaryTree__binaryTree__

#include <stdio.h>
#include "queue.h"

template <class T>
class BinaryTreeNode {
public:
    BinaryTreeNode* leftChild;
    T data;
    BinaryTreeNode* rightChild;
    BinaryTreeNode(){
        leftChild = NULL;
        rightChild = NULL;
    }
};

template <class T>
class BinaryTree {
    BinaryTreeNode<T> *root = NULL;
    
public:
    BinaryTree();                                                   //Fin
    BinaryTree(BinaryTreeNode<T> *lch, BinaryTreeNode<T> *rch, T value);
    ~BinaryTree();
    int getHeight();
    int getSize();
    BinaryTreeNode<T>* getRoot();                                   //Fin
    BinaryTreeNode<T>* leftChild(BinaryTreeNode<T>* current);       //Fin
    BinaryTreeNode<T>* rightChild(BinaryTreeNode<T>* current);      //Fin
    BinaryTreeNode<T>* parent(BinaryTreeNode<T>* current);          //Fin
    BinaryTreeNode<T>* find(const T value);                         //Fin
    T getData(BinaryTreeNode<T>* current);                          //Fin
    bool insert(const T value);
    bool insert(BinaryTreeNode<T>* parent, const T value);
    bool insert(BinaryTreeNode<T>* parent, const T value, bool rightSet);
    bool remove(BinaryTreeNode<T>* current);
    bool remove(T &value);
    bool isEmpty();                                                 //Fin
    void preOrder(Queue<T> &result);                                //Fin
    void inOrder(Queue<T> &result);                                 //Fin
    void postOrder(Queue<T> &result);                               //Doing
    void levelOrder(Queue<T> &result);                              //Fin
};

#endif /* defined(__BinaryTree__binaryTree__) */
