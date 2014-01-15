#pragma once

template <typename T>
class Heap
{
public:
    Heap() : _size(0)
    {
        memset(_elements, 0, sizeof(_elements));
    }

    void Insert(T value)
    {
        if (_size >= HEAP_SIZE)
            throw std::exception();
        else
        {
            _size++;
            _elements[_size] = value;

            bubble_up(_size);
        }
    }

    T ExtractHead()
    {
        if (_size == 0)
            throw std::exception();

        T head = _elements[1];

        _elements[1] = _elements[_size];
        _size--;

        bubble_down(1);

        return head;
    }

    void Print()
    {
        for (int i = 1; i < _size + 1; i++)
            cout << _elements[i] << " ";
        cout << endl;
    }

private:
    static const int HEAP_SIZE = 128;
    T _elements[HEAP_SIZE + 1];

    int _size;

    int parent(int position)
    {
        if (position == 1) return -1;
        return position / 2;
    }

    int child(int position)
    {
        return 2 * position;
    }

    T remove_root()
    {
        if (_size == 0)
            throw std::exception();

        T rootValue = _elements[1];

        _elements[1] = _elements[_size];
        _size--;

        bubble_down(1);

        return rootValue;
    }

    void bubble_down(int position)
    {
        int childPos = child(position);

        if (childPos > _size)
            return;

        int minPos = childPos;

        for (int i = 0; i <= 1; i++)
        {
            if (childPos + i <= _size)
            {
                if (_elements[childPos + i] < _elements[minPos])
                {
                    minPos = childPos + i;
                }
            }
        }

        if (minPos != position)
        {
            swap(position, minPos);
            bubble_down(minPos);
        }
    }

    void swap(int p1, int p2)
    {
        T tmp = _elements[p1];
        _elements[p1] = _elements[p2];
        _elements[p2] = tmp;
    }

    void bubble_up(int position)
    {
        if (parent(position) == -1) return;

        if (_elements[parent(position)] > _elements[position])
        {
            swap(position, parent(position));

            bubble_up(parent(position));
        }
    }
};
