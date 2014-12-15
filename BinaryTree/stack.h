//
//  stack.h
//  Stack
//
//  Created by Whoami on 14/11/2.
//  Copyright (c) 2014年 Whoami. All rights reserved.
//

#ifndef __Stack__stack__
#define __Stack__stack__
#include <stdio.h>

template <class T>
class StackNode {
public:
    T data;
    StackNode<T> *pre;
    StackNode(){
        pre = NULL;
    }
    StackNode(T x){
        data= x;
        pre = NULL;
    }
};

template <class T>
class Stack {
private:
    StackNode<T> *top;
public:
    Stack(){                    //Create/Delete a new Stack.
        top = NULL;
    }
    ~Stack(){
        while (top != NULL) {
            pop();
        }
    }
    bool push(const T x);       //Push into the Stack.
    T pop();                    //Pop out of the Stack.
    bool pop(T& x);
    T getTop(T& x);             //Get the top of the Stack.
    bool isEmpty();             //Judge the Stack whether it is empty/full or not.
    bool isFull(){
        return false;
    }
    int getSize();              //Count how many datas are in the Stack.
};

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
#endif /* defined(__Stack__stack__) */
