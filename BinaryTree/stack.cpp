//
//  stack.cpp
//  Stack
//
//  Created by Whoami on 14/11/12.
//  Copyright (c) 2014年 Whoami. All rights reserved.
//

#include "stack.h"

template <class T>
bool Stack<T>::push(const T x) {
    StackNode<T> *p= new StackNode<T>(x);
    if (top == NULL){
        top = p;
    } else {
        p->pre = top;
        top = p;
    }
    return true;
}

template <class T>
T Stack<T>::pop(){
    if (top == NULL) {
        return NULL;
    } else {
        T x = top->data;
        StackNode<T> *tmp = top;
        top = top->pre;
        delete tmp;
        return x;
    }
}

template <class T>
bool Stack<T>::pop(T& x){
    if (top == NULL) {
        return false;
    } else {
        x = top->data;
        StackNode<T> *tmp = top;
        top = top->pre;
        delete tmp;
        return true;
    }
}

template <class T>
T Stack<T>::getTop(T& x){
    x = top->data;
    return top->data;
}

template <class T>
bool Stack<T>::isEmpty(){
    if (top == NULL) {
        return true;
    } else {
        return false;
    }
}

template <class T>
int Stack<T>::getSize(){
    int size = 0;
    StackNode<T> *tmp = top;
    while (tmp != NULL) {
        tmp = tmp->pre;
        size++;
    }
    return size;
}