
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

    int child(int position) { return 2 * position; }

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

    }

    void bubble_up(int position)
    {
        if (parent(position) == -1) return;

        if (_elements[parent(position)] < _elements[position])
        {
            T tmp = _elements[parent(position)];
            _elements[parent(position)] = _elements[position];
            _elements[position] = tmp;

            bubble_up(parent(position));
        }
    }
};
