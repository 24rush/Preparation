#include <iostream>
#include "assert.h"

#include "HashTable.h"
#include "SimpleLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
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

    cout << "Stack test" << endl;
    Stack<int> stack;
    stack.Push(5);
    stack.Push(6);
    assert(stack.Pop() == 6);

    cout << "Queue test" << endl;
    Queue<int> queue;
    queue.Enqueue(3);
    queue.Enqueue(6);
    assert(queue.Deque() == 3);

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

    return 0;
}
