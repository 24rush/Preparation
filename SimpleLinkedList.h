#include <iostream>
using namespace std;

template <typename T>
struct ListItem
{
    T value;
    ListItem* next;
};

template <typename T>
class SimpleLinkedList
{
public:

    SimpleLinkedList() : _listHead(NULL)
    {
    }

    void Insert(T value)
    {
        auto newNode = new ListItem<T>();
        newNode->value = value;
        newNode->next = NULL;

        newNode->next = _listHead;
        _listHead = newNode;
    }

    const ListItem<T>* FirstItem(T value)
    {
        auto p = _listHead;

        while (p)
        {
            if (p->value == value)
            {
                break;
            }

            p = p->next;
        }

        return p;
    }

    void Delete(T value)
    {
        // Handle value to delete is head
        while (_listHead && _listHead->value == value)
        {
            auto *oldHead = _listHead;
            _listHead = _listHead->next;

            delete oldHead;
        }

        if (_listHead == NULL)
            return;

        auto prev = _listHead;
        auto current = _listHead->next;

        while (current)
        {
            if (current->value == value)
            {
                prev->next = current->next;
                delete current;

                current = prev->next;

                continue;
            }

            prev = current;
            current = current->next;
        }
    }

    void Reverse()
    {
        if (_listHead == NULL || _listHead->next == NULL)
            return;

        auto prev = _listHead;
        auto current = _listHead->next;

        _listHead->next = NULL;

        while (current)
        {
            _listHead = current;

            auto temp = current->next;
            current->next = prev;
            prev = current;

            current = temp;
        }
    }

    void Print()
    {
        if (_listHead == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        auto p = _listHead;
        while (p)
        {
            cout << p->value << " ";
            p = p->next;
        }

        cout << endl;
    }

private:
    ListItem<T>* _listHead;
};
