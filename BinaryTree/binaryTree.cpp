//
//  binaryTree.cpp
//  BinaryTree
//
//  Created by Whoami on 14/11/12.
//  Copyright (c) 2014年 Whoami. All rights reserved.
//

#include "binaryTree.h"
#include "stack.h"

template <class T>
BinaryTree<T>::BinaryTree() {
    root == NULL;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getRoot() {
    return root;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::leftChild(BinaryTreeNode<T>* current) {
    return current->leftChild;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::rightChild(BinaryTreeNode<T>* current) {
    return current->rightChild;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::parent(BinaryTreeNode<T>* current){
    BinaryTreeNode<T>* pre = root;
    Stack<BinaryTreeNode<T>*> path;
    while (!path.isEmpty() && pre->leftChild != NULL) {
        if (pre->leftChild == current || pre->rightChild == current) {
            return pre;
        }
        if (pre->rightChild != NULL) {
            path.push(pre->rightChild);
        }
        if (pre->leftChild == NULL) {
            path.pop(pre);
            continue;
        } else {
            pre = pre->leftChild;
            continue;
        }
    }
    return NULL;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::find(const T value){
    Stack<BinaryTreeNode<T>*> path;
    BinaryTreeNode<T>* current = root;
    while (!path.isEmpty() && current->leftChild != NULL) {
        if (current->data == value) {
            return current;
        }
        if (current->rightChild != NULL) {
            path.push(current->rightChild);
        }
        if (current->leftChild == NULL) {
            path.pop(current);
            continue;
        } else {
            current = current->leftChild;
            continue;
        }
    }
    if (current->data == value) {
        return current;
    }
    return NULL;
}

template <class T>
void BinaryTree<T>::preOrder(Queue<T> &result) {
    Stack<BinaryTreeNode<T>*> path;
    BinaryTreeNode<T>* current = root;
    result.makeEmpty();
    while (!path.isEmpty() || current->leftChild != NULL) {
        result.enQueue(current->data);
        if (current->rightChild != NULL) {
            path.push(current->rightChild);
        }
        if (current->leftChild == NULL) {
            path.pop(current);
            continue;
        } else {
            current = current->leftChild;
            continue;
        }
    }
    result.enQueue(current->data);
}

template <class T>
void BinaryTree<T>::inOrder(Queue<T> &result){
    Stack<BinaryTreeNode<T>*> path;
    BinaryTreeNode<T>* current = root;
    result.makeEmpty();
    while (1) {
        if (current->leftChild != NULL) {
            path.push(current);
            current = current->leftChild;
        } else {
            result.enQueue(current->data);
            while (current->rightChild == NULL && !path.isEmpty()) {
                current = path.pop;
                result.enQueue(current->data);
            }
            if (current->rightChild != NULL) {
                current = current->rightChild;
            } else {
                return;
            }
        }
    }
}

template <class T>
void BinaryTree<T>::postOrder(Queue<T> &result){
}

template <class T>
bool BinaryTree<T>::isEmpty(){
    if (root == NULL) {
        return true;
    } else {
        return false;
    }
}

template <class T>
T BinaryTree<T>::getData(BinaryTreeNode<T>* current){
    return current->data;
}

template <class T>
void BinaryTree<T>::levelOrder(Queue<T> &result){
    Queue<BinaryTreeNode<T>*> path;
    result.makeEmpty();
    BinaryTreeNode<T> *current;
    path.enQueue(root);
    while (!path.isEmpty()) {
        path.deQueue(current);
        result.enQueue(current);
        if (current->leftChild != NULL) {
            path.enQueue(current->leftChild);
        }
        if (current->rightChild != NULL) {
            path.enQueue(current->rightChild);
        }
    }
}
