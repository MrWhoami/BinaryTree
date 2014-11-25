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


#endif /* defined(__Stack__stack__) */
