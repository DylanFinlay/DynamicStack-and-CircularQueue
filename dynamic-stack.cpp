#include "dynamic-stack.h"
#include <iostream>

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
    items_ = new StackItem[16];
    size_ = 0;
    init_capacity_ = 16;
    capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int capacity){
    items_ = new StackItem[capacity];
    init_capacity_ = capacity;
    capacity_ = init_capacity_;
    size_ = 0;
}

DynamicStack::~DynamicStack() {
    delete[]items_;
    items_ = nullptr;
}

unsigned int DynamicStack::size() const {
    return size_;
}

bool DynamicStack::empty() const {
    if (size_ == 0)
        return true;
    else
        return false;
}

DynamicStack::StackItem DynamicStack::peek() const {
    if (empty())
        return EMPTY_STACK;
    else
        return items_[size_ - 1];
}

void DynamicStack::push(StackItem value) {
    if(size_ == capacity_)
//Once capacity is reached, the array capacity is doubled to allow more inserts
    {
        std::cout << "Stack cap is reached, size will now be doubled";
        StackItem *temp = new StackItem[2*capacity_];
        capacity_ = 2*capacity_;
        for(int i = 0; i < size_; i++)
        {
            temp[i] = items_[i];
        }
        int *old = items_;
        items_ = temp;
        delete [] old;
        old = nullptr;
        temp = nullptr;
    }

    items_[size_] = value;
    size_++;

}

DynamicStack::StackItem DynamicStack::pop() {
    if (empty())
    {
        return EMPTY_STACK;
    }

    else {
        StackItem value = items_[size_ - 1];
        items_[size_ - 1] = EMPTY_STACK;
        size_--;

        if (size_ <= (capacity_/4) && (capacity_/2 >= init_capacity_))
        {
            std::cout << "Stack capacity is being halved";
            StackItem *temp = new StackItem[capacity_/2];
            capacity_ = capacity_/2;
            for(int i = 0; i < size_; i++)
            {
                temp[i] = items_[i];
            }
            int *old = items_;
            items_ = temp;
            delete [] old;
            old = nullptr;
            temp = nullptr;
        }

        return value;
    }
}

void DynamicStack::print() const {
    if (empty())
    {
        std::cout << "Stack is full ";
        return;
    }

    for (int i = size_ -1; i>=0; i--)
    {
        std:: cout << " " << items_[i] << " ";
    }
    return;
}
