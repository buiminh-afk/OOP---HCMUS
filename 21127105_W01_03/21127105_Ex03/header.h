#pragma once

#include <iostream>

struct Node
{
    int data;
    Node * next = NULL;
};

class LinkedListQueue {
private:
    Node * head;
    Node * tail;
    int capacity, num;
public: 
    void init(int);
    void enqueue(int);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    void clear();
};
