
#include "HashTable.h"

HashTable::HashTable()
{
    _hashTable = new HashTableEntry*[HASH_SIZE];
    memset(_hashTable, 0, sizeof(HashTableEntry*) * HASH_SIZE);
}

HashTable::~HashTable()
{
    delete[] _hashTable;
}

void HashTable::Put(const char* key, int value)
{
    if (key == NULL) return;

    auto addEntry = [] (const char* key, int value)
    {
        auto *hashEntry = new HashTableEntry();
        hashEntry->key = strdup((const char*)key);
        hashEntry->value = value;

        return hashEntry;
    };

    HashTableEntry** hashEntry = getArrayHashEntryForKey(key);

    if (*hashEntry == NULL)
    {
        *hashEntry = addEntry(key, value);
    }
    else
    {
        // Collision
        auto chainHashEntry = getChainHashEntryForKey(key, *hashEntry);

        if (chainHashEntry == NULL)
        {
            auto newEntry = addEntry(key, value);

            newEntry->pNext = (*hashEntry)->pNext;
            (*hashEntry)->pNext = newEntry;
        }
        else
        {
            chainHashEntry->value = value;
        }
    }
}

int HashTable::Get(const char* key)
{
    if (key == NULL) return -1;

    HashTableEntry** hashEntry = getArrayHashEntryForKey(key);

    if (*hashEntry == NULL)
    {
        cout << "Key not found" << endl;
        return -1;
    }
    else
    {
        if ((*hashEntry)->pNext != NULL)
        {
            auto hashEntryByKey = getChainHashEntryForKey(key, *hashEntry);

            if (hashEntryByKey != NULL)
            {
                return hashEntryByKey->value;
            }
        }
        else
        {
            return (*hashEntry)->value;
        }

        return -1;
    }
}

HashTableEntry** HashTable::getArrayHashEntryForKey(const void* key)
{
    int hash = getHash(key, strlen((const char*)key));

    size_t index = hash % HASH_SIZE;

    return &_hashTable[index];
}

HashTableEntry* HashTable::getChainHashEntryForKey(const void* key, HashTableEntry* bucketEntry)
{
    auto itBucketEntries = bucketEntry;

    while (itBucketEntries != NULL)
    {
        if (strcmp(itBucketEntries->key, (const char*)key) == 0)
        {
            break;
        }

        itBucketEntries = itBucketEntries->pNext;
    }

    return itBucketEntries;
}

int HashTable::getHash(const void* key, size_t len)
{
    const char* p = (const char*) key;
    int hash = 0;

    for (size_t i = 0; i < len; i++)
    {
        hash = 33 * hash ^ p[i];
    }

    return hash;
}
