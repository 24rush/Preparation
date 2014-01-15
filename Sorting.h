#include "Queue.h"
#include "Heap.h"

template <typename T>
void merge(T* array, size_t low, size_t middle, size_t high)
{
    Queue<int> bufferLeft;
    Queue<int> bufferRight;

    for (size_t i = low; i <= middle; i++) bufferLeft.Enqueue(array[i]);
    for (size_t i = middle+1; i <= high; i++) bufferRight.Enqueue(array[i]);

    int idx = low;
    while (!bufferLeft.Empty() && !bufferRight.Empty())
    {
        if (bufferLeft.Peek() <= bufferRight.Peek())
            array[idx++] = bufferLeft.Deque();
        else
            array[idx++] = bufferRight.Deque();
    }

    while (!bufferLeft.Empty()) array[idx++] = bufferLeft.Deque();
    while (!bufferRight.Empty()) array[idx++] = bufferRight.Deque();
}

template <typename T>
void MergeSort(T* array, size_t low, size_t high)
{
    if (low < high)
    {
        size_t middle = (low + high) / 2;

        MergeSort(array, low, middle);
        MergeSort(array, middle+1, high);

        merge(array, low, middle, high);
    }
}

template <typename T>
void SelectionSort(T* array, size_t length)
{
    if (length == 0 || !array)
        return;

    T tmpSwap = 0;
    size_t idxMin = -1;

    for (size_t i = 0; i < length - 1; i++)
    {
        idxMin = i;
        for (size_t usIdx = i + 1; usIdx < length; usIdx++)
        {
            if (array[usIdx] < array[idxMin])
            {
                idxMin = usIdx;
            }
        }

        tmpSwap = array[i];
        array[i] = array[idxMin];
        array[idxMin] = tmpSwap;
    }
}

template <typename T>
void HeapSort(T* array, size_t length)
{
    if (length <= 1)
        return;

    Heap<T> heap;

    for (size_t i = 0; i < length; i++)
    {
        heap.Insert(array[i]);
    }

    for (size_t i = 0; i < length; i++)
    {
        array[i] = heap.ExtractHead();
    }
}
