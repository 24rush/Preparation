
#include <cstring>
#include <iostream>
using namespace std;

struct HashTableEntry
{
    int value;
    char* key;
    HashTableEntry* pNext;

    HashTableEntry()
    {
        key = NULL;
        value = -1;
        pNext = NULL;
    }
};

class HashTable
{
 public:
    HashTable();
    ~HashTable();

    void Put(const char* key, int value);
    int Get(const char* key);

 private:
    static const int HASH_SIZE = 127;
    HashTableEntry** _hashTable;

    int getHash(const void* key, size_t len);
    HashTableEntry** getArrayHashEntryForKey(const void* key);
    HashTableEntry* getChainHashEntryForKey(const void* key, HashTableEntry* bucketEntry);
};
