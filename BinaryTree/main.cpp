//
//  main.cpp
//  BinaryTree
//
//  Created by Whoami on 14/11/12.
//  Copyright (c) 2014年 Whoami. All rights reserved.
//

#include <iostream>
#include "binaryTree.h"
#include "queue.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int *array;
    int size;
    cout << "Please input size: ";
    cin >> size;
    array = new int[size];
    cout << "Please input data:" << endl;
    for (int i=0; i<size; i++) {
        cin >> array[i];
    }
    BinaryTree<int> tree;
    Queue<int> result;
    for (int i=0; i<size; i++) {
        tree.insert(array[i]);
    }
    tree.preOrder(result);
    while (!result.isEmpty()) {
        int x;
        result.deQueue(x);
        cout << x << ' ';
    }
    cout << endl;
    tree.inOrder(result);
    while (!result.isEmpty()) {
        int x;
        result.deQueue(x);
        cout << x << ' ';
    }
    cout << endl;
    tree.postOrder(result);
    while (!result.isEmpty()) {
        int x;
        result.deQueue(x);
        cout << x << ' ';
    }
    cout << endl;
    tree.levelOrder(result);
    while (!result.isEmpty()) {
        int x;
        result.deQueue(x);
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
