#include <iostream>
using namespace std;

template <typename T>
struct StackItem
{
    T value;
    StackItem* next;
};

template <typename T>
class Stack
{
public:
    Stack() : _stackTop(NULL)
    {

    }

    void Push(T value)
    {
        auto newItem = new StackItem<T>();
        newItem->value = value;
        newItem->next = _stackTop;

        _stackTop = newItem;
    }

    T Pop()
    {
        if (!_stackTop)
            throw std::exception();

        auto valToPop = _stackTop->value;

        auto oldTop = _stackTop;
        _stackTop = _stackTop->next;
        delete oldTop;

        return valToPop;
    }

private:
    StackItem<T>* _stackTop;
};

