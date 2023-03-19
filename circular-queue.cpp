#include "circular-queue.h"
#include <iostream>

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    items_ = new QueueItem[16];
    size_ = 0;
    capacity_ = 16;
    head_ = 0;
    tail_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity) {
    items_ = new QueueItem[capacity];
    size_ = 0;
    capacity_ = capacity;
    head_ = 0;
    tail_ = 0;
}

CircularQueue::~CircularQueue() {
    delete[]items_;
    items_ = nullptr;
}

unsigned int CircularQueue::size() const {
    return size_;
}

bool CircularQueue::empty() const {
    if (size_ == 0)
        return true;
    else
        return false;
}

bool CircularQueue::full() const {
    if (size_ == capacity_)
        return true;
    else
        return false;
}

CircularQueue::QueueItem CircularQueue::peek() const {
    if (empty())
        return EMPTY_QUEUE;
    else
        return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value) {
    if (full())
    {
        return false;
    }

    items_[tail_] = value;
    tail_ ++;
    size_ ++;

    if (tail_ == capacity_)
    {
        tail_ = 0;
    }

    return true;

}

CircularQueue::QueueItem CircularQueue::dequeue() {
    if (empty())
    {
        return EMPTY_QUEUE;
    }

    QueueItem temp = items_[head_];
    items_[head_] = EMPTY_QUEUE;
    head_ ++;
    size_ --;

    if (head_ == capacity_)
    {
        head_ = 0;
    }

    return temp;
}

void CircularQueue::print() const {
//PROPER PRINT
    if (empty())
    {
        std::cout << "Stack is full ";
        return;
    }

    if (tail_ <= head_)
    {
        for (int i = head_; i < capacity_; i++)
        {
            std:: cout << " " << items_[i] << " ";
        }

        for (int i = 0; i < tail_; i++)
        {
            std:: cout << " " << items_[i] << " ";
        }
        return;
    }

    for (int i = head_; i < tail_; i++)
    {
        std:: cout << " " << items_[i] << " ";
    }


//TEST PRINT
//    for (int i = 0; i < 5; i++)
//    {
//        std:: cout << " " << items_[i] << " ";
//    }
//
//    return;
}
