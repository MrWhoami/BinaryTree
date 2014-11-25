//
//  queue.h
//  Queue
//
//  Created by Whoami on 14/11/9.
//  Copyright (c) 2014年 Whoami. All rights reserved.
//

#ifndef Queue_queue_h
#define Queue_queue_h
#include <stdio.h>

template<class T>
class QueueNode {
public:
    T data;
    QueueNode<T> *next;
    QueueNode(){
        next = NULL;
    }
    QueueNode(T x){
        data = x;
        next = NULL;
    }
};

template<class T>
class Queue{
    QueueNode<T> *front;
    QueueNode<T> *rear;
public:
    Queue(){                    //Create/Delete a new Queue.
        front = NULL;
        rear = NULL;
    }
    ~Queue(){
        T tmp;
        while (front != NULL) {
            deQueue(tmp);
        }
    }
    bool enQueue(const T x);    //Input a data.
    bool deQueue(T &x);         //Output a data.
    bool getFront(T &x);           //Get the data of the front.
    T getFront();
    bool isEmpty();             //Judge whether it is empty/full or not.
    bool isFull();
    int getSize();              //Get the size of the Queue.
    void makeEmpty();           //Make the queue empty.
};

#endif
