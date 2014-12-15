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
#include "stack.h"

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
    BinaryTreeNode(T x){
        leftChild = NULL;
        rightChild = NULL;
        data = x;
    }
};

template <class T>
class BinaryTree {
    BinaryTreeNode<T> *root = NULL;
    
public:
    BinaryTree(){
        root = NULL;
    }
    BinaryTree(BinaryTreeNode<T> *lch, BinaryTreeNode<T> *rch, T value){
        root = new BinaryTreeNode<T>(value);
        root->leftChild = lch;
        root->rightChild = rch;
    }
    ~BinaryTree(){
        remove(root);
    }
    int getHeight();                                                //Fin
    int getSize();                                                  //Fin
    BinaryTreeNode<T>* getRoot();                                   //Fin
    BinaryTreeNode<T>* leftChild(BinaryTreeNode<T>* current);       //Fin
    BinaryTreeNode<T>* rightChild(BinaryTreeNode<T>* current);      //Fin
    BinaryTreeNode<T>* parent(BinaryTreeNode<T>* current);          //Fin
    BinaryTreeNode<T>* find(const T value);                         //Fin
    T getData(BinaryTreeNode<T>* current);                          //Fin
    bool find(const BinaryTreeNode<T>* current);                    //Fin
    bool insert(const T value);                                     //Fin
    bool insert(BinaryTreeNode<T>* parent, const T value);          //Fin
    bool insert(BinaryTreeNode<T>* parent, const T value, bool rightSet);   //Fin
    bool remove(BinaryTreeNode<T>* current);                        //Fin
    bool remove(const T value);                                     //Fin
    bool isEmpty();                                                 //Fin
    void preOrder(Queue<T> &result);                                //Fin
    void inOrder(Queue<T> &result);                                 //Fin
    void postOrder(Queue<T> &result);                               //Fin
    void levelOrder(Queue<T> &result);                              //Fin
};

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
bool BinaryTree<T>::find(const BinaryTreeNode<T>* p){
    Stack<BinaryTreeNode<T>*> path;
    BinaryTreeNode<T>* current = root;
    while (!path.isEmpty() && current->leftChild != NULL) {
        if (current == p) {
            return 1;
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
    if (current == p) {
        return 1;
    }
    return 0;
}

template <class T>
void BinaryTree<T>::preOrder(Queue<T> &result) {
    Stack<BinaryTreeNode<T>*> path;
    BinaryTreeNode<T>* current = root;
    result.makeEmpty();
    while (!path.isEmpty() || current != NULL) {
        result.enQueue(current->data);
        if (current->rightChild != NULL) {
            path.push(current->rightChild);
        }
        if (current->leftChild == NULL) {
            if(!path.pop(current))
                current = NULL;
            continue;
        } else {
            current = current->leftChild;
            continue;
        }
    }
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
                current = path.pop();
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
    Stack<BinaryTreeNode<T>*> path;
    Stack<bool> isLeft;
    BinaryTreeNode<T>* current = root;
    result.makeEmpty();
    do {
        while (current != NULL) {
            path.push(current);
            isLeft.push(1);
            current = current->leftChild;
        }
        bool conti = 1;
        while (conti && !path.isEmpty()) {
            current = path.pop();
            if (isLeft.pop()) {
                path.push(current);
                isLeft.push(0);
                conti = 0;
                current = current->rightChild;
            } else {
                result.enQueue(current->data);
            }
        }
    } while (!path.isEmpty());
    return;
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
        result.enQueue(current->data);
        if (current->leftChild != NULL) {
            path.enQueue(current->leftChild);
        }
        if (current->rightChild != NULL) {
            path.enQueue(current->rightChild);
        }
    }
}

template <class T>
bool BinaryTree<T>::insert(const T value){
    BinaryTreeNode<T> *p = new BinaryTreeNode<T>(value);
    if (root == NULL) {
        root = p;
    }
    else if (root->leftChild == NULL) {
        root->leftChild = p;
    }
    else if (root->rightChild == NULL){
        root->rightChild = p;
    }
    else {
        p->leftChild = root;
        root = p;
    }
    return 1;
}

template <class T>
bool BinaryTree<T>::insert(BinaryTreeNode<T> *parent, const T value){
    if(!find(parent))
        return 0;
    BinaryTreeNode<T>* p = new BinaryTreeNode<T>(value);
    if (parent->leftChild == NULL) {
        parent->leftChild = p;
    }
    else if(parent->rightChild == NULL) {
        parent->rightChild = p;
    }
    else {
        delete p;
        return 0;
    }
    return 1;
}

template <class T>
bool BinaryTree<T>::insert(BinaryTreeNode<T>* parent, const T value, bool rightSet){
    if(!find(parent))
        return 0;
    BinaryTreeNode<T>* p = new BinaryTreeNode<T>(value);
    if (rightSet) {
        if(parent->rightChild == NULL) {
            parent->rightChild = p;
        } else {
            delete p;
            return 0;
        }
    } else {
        if (parent->leftChild == NULL) {
            parent->leftChild = p;
        } else {
            delete p;
            return 0;
        }
    }
    return 1;
}

template <class T>
bool BinaryTree<T>::remove(BinaryTreeNode<T>* current){
    if (!find(current)) {
        return 0;
    }
    Queue<BinaryTreeNode<T>*> result;
    Stack<BinaryTreeNode<T>*> path;
    BinaryTreeNode<T>* p = current;
    while (!path.isEmpty() || p != NULL) {
        result.enQueue(p);
        if (p->rightChild != NULL) {
            path.push(p->rightChild);
        }
        if (p->leftChild == NULL) {
            path.pop(p);
            continue;
        } else {
            p = p->leftChild;
            continue;
        }
    }
    while (!result.isEmpty()) {
        result.deQueue(p);
        delete p;
    }
    return 1;
}

template <class T>
bool BinaryTree<T>::remove(const T value){
    BinaryTreeNode<T>* current = find(value);
    if (current == NULL) {
        return 0;
    }
    Queue<BinaryTreeNode<T>*> result;
    Stack<BinaryTreeNode<T>*> path;
    BinaryTreeNode<T>* p = current;
    while (!path.isEmpty() || p != NULL) {
        result.enQueue(p);
        if (p->rightChild != NULL) {
            path.push(p->rightChild);
        }
        if (p->leftChild == NULL) {
            path.pop(p);
            continue;
        } else {
            p = p->leftChild;
            continue;
        }
    }
    while (!result.isEmpty()) {
        result.deQueue(p);
        delete p;
    }
    return 1;
}

template <class T>
int BinaryTree<T>::getSize() {
    Stack<BinaryTreeNode<T>*> path;
    BinaryTreeNode<T>* p = root;
    int size = 0;
    while (!path.isEmpty() || p != NULL) {
        size++;
        if (p->rightChild != NULL) {
            path.push(p->rightChild);
        }
        if (p->leftChild == NULL) {
            path.pop(p);
            continue;
        } else {
            p = p->leftChild;
            continue;
        }
    }
    return size;
}

template <class T>
int BinaryTree<T>::getHeight() {
    Stack<BinaryTreeNode<T>*> path;
    Stack<int> pathH;
    BinaryTreeNode<T>* p = root;
    int height = 1;
    int max = 0;
    while (!path.isEmpty() || p != NULL) {
        if (height > max) {
            max = height;
        }
        if (p->rightChild != NULL) {
            path.push(p->rightChild);
            pathH.push(height+1);
        }
        if (p->leftChild == NULL) {
            path.pop(p);
            pathH.pop(height);
            continue;
        } else {
            p = p->leftChild;
            height = height+1;
            continue;
        }
    }
    return max;
}
#endif /* defined(__BinaryTree__binaryTree__) */
