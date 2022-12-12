#include "header.h"

using namespace std;

void LinkedListQueue::init(int cap) {
    capacity = cap;
    head = tail = NULL;
    num = 0;
}

void LinkedListQueue::enqueue(int x) {
    if (isFull()) return;
    num++;
    Node * t = new Node;
    t->data = x;
    if (tail == NULL) {
        head = tail = t;
        return;
    } else {
        tail->next = t;
        tail = t;
    }
}

int LinkedListQueue::dequeue() {
    int x;
    if (head == NULL) 
        return 0;
    Node * t = head;
    head = head ->next;
    if (head == NULL)
        tail == NULL;
    num--;
    x = t->data;
    delete t;
    return x;
}

int LinkedListQueue::peek() {
    return head->data;
}

bool LinkedListQueue::isEmpty() {
    return num == 0;
}

bool LinkedListQueue::isFull() {
    return num >= capacity;
}

void LinkedListQueue::clear() {
    while (!isEmpty()) 
        dequeue();
}

