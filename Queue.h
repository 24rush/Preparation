#pragma once

#include <iostream>
using namespace std;

template <typename T>
struct QueueItem
{
    T value;
    QueueItem* next;
};

template <typename T>
class Queue
{
public:
    Queue() : _queueBegin(NULL), _queueEnd(NULL)
    {

    }

    void Enqueue(T value)
    {
        auto newItem = new QueueItem<T>();
        newItem->value = value;
        newItem->next = NULL;

        if (_queueBegin == NULL)
        {
            _queueBegin = _queueEnd = newItem;
        }
        else
        {
            _queueEnd->next = newItem;
            _queueEnd = newItem;
        }
    }

    T Deque()
    {
        if (_queueBegin == NULL)
            throw std::exception();

        auto valDeque = _queueBegin->value;
        auto oldBegin = _queueBegin;
        _queueBegin = _queueBegin->next;

        delete oldBegin;

        if (_queueBegin == NULL)
        {
            _queueEnd = NULL;
        }

        return valDeque;
    }

    T Peek()
    {
        if (_queueBegin == NULL)
           throw std::exception();

        return _queueBegin->value;
    }

    bool Empty()
    {
        return _queueBegin == NULL;
    }

    void Print()
    {
        if (_queueBegin == NULL)
            cout << "Queue is empty" << endl;

        auto p = _queueBegin;
        while (p)
        {
            cout << p->value << " ";
            p = p->next;
        }

        cout << endl;
    }

private:
    QueueItem<T>* _queueBegin;
    QueueItem<T>* _queueEnd;
};
