//
//  queue.cpp
//  Stack
//
//  Created by Whoami on 14/11/12.
//  Copyright (c) 2014年 Whoami. All rights reserved.
//

#include "queue.h"

template <class T>
bool Queue<T>::enQueue(const T x){
    QueueNode<T> *p = new QueueNode<T>(x);
    if (rear == NULL) {
        front = p;
        rear = p;
    } else {
        rear->next = p;
        rear = p;
    }
    return true;
}

template <class T>
bool Queue<T>::deQueue(T &x){
    if(front == NULL) {
        return false;
    } else {
        x = front->data;
        if (front->next == NULL) {
            delete front;
            front = NULL;
            rear = NULL;
        } else {
            QueueNode<T> *tmp = front;
            front = front->next;
            delete tmp;
        }
        return true;
    }
}

template <class T>
T Queue<T>::getFront(){
    return front->data;
}

template <class T>
bool Queue<T>::getFront(T &x){
    x = front->data;
    return 1;
}

template <class T>
bool Queue<T>::isEmpty(){
    if (front == NULL) {
        return true;
    } else {
        return false;
    }
}

template <class T>
bool Queue<T>::isFull(){
    return false;
}

template <class T>
int Queue<T>::getSize(){
    int size = 0;
    QueueNode<T> *tmp = front;
    while (tmp != NULL) {
        tmp = tmp->next;
        size++;
    }
    return size;
}

template <class T>
void Queue<T>::makeEmpty(){
    T tmp;
    while (front != NULL) {
        deQueue(tmp);
    }
    front = NULL;
    rear = NULL;
}