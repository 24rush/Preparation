#include <iostream>
#include <stdio.h>
#include "assert.h"

#include "HashTable.h"
#include "SimpleLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "BinarySearchTree.h"

#include "Sorting.h"
#include "Heap.h"

using namespace std;

void HashTableTest()
{
    cout << "Hash table test" << endl;
    HashTable hashTable;

    hashTable.Put("Alin", 1);
    assert(hashTable.Get("Alin") == 1);

    hashTable.Put("Alin", 2);
    assert(hashTable.Get("Alin") == 2);

    hashTable.Put("Alin1", 1);
    assert(hashTable.Get("Alin1") == 1);

    assert(hashTable.Get("Alin3") == -1);
    assert(hashTable.Get("") == -1);
    assert(hashTable.Get(NULL) == -1);
}

void SimpleLinkedListTest()
{
    cout << "Simple linked list test" << endl;
    SimpleLinkedList<int> intList;

    intList.Insert(3);
    intList.Insert(3);
    intList.Insert(4);
    intList.Insert(4);
    intList.Insert(8);
    intList.Insert(8);

    intList.Delete(-1);
    auto elem = intList.FirstItem(8);
    assert(elem->value == 8);

    intList.Print();
    intList.Reverse();
    intList.Print();
}

void StackTest()
{
    cout << "Stack test" << endl;
    Stack<int> stack;
    stack.Push(5);
    stack.Push(6);
    assert(stack.Pop() == 6);
}

void QueueTest()
{
    cout << "Queue test" << endl;
    Queue<int> queue;
    queue.Enqueue(3);
    queue.Enqueue(6);
    assert(queue.Deque() == 3);
    assert(queue.Deque() == 6);
}

void BinarySearchTreeTest()
{
    cout << "Binary search tree" << endl;
    BinarySearchTree<int> searchTree;
    searchTree.Insert(3);
    searchTree.Insert(6);
    searchTree.Insert(1);
    searchTree.Insert(2);
    searchTree.Insert(1);
    searchTree.Insert(9);
    searchTree.Insert(8);
    searchTree.Insert(5);

    cout << "Min: " << searchTree.Minimum() << endl;
    assert(searchTree.Search(-1) == NULL);
    assert(searchTree.Search(9)->value == 9);

    searchTree.Delete(3);

    searchTree.Print();
}

void SortingTest()
{
    cout << "Sorting " << endl;
    int a[] = {5, 3, 1, 2, 4, 0};

    SelectionSort(a, sizeof(a) / sizeof(a[0]));
    MergeSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);

    for (size_t i = 0; i < 6; i++) cout << a[i] << " ";
    cout << endl;
}

void HeapTest()
{
    cout << "Heap test" << endl;

    Heap<int> heap;

    heap.Insert(1);
    heap.Insert(2);
    heap.Insert(3);
    heap.Insert(6);
    heap.Insert(8);
    heap.Insert(9);

    heap.Print();
}

int main()
{
    HashTableTest();

    SimpleLinkedListTest();

    StackTest();

    QueueTest();

    BinarySearchTreeTest();

    SortingTest();

    HeapTest();

    getchar();
    return 1;
}
