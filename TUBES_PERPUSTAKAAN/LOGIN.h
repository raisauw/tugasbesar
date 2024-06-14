
#include <cstring>
using namespace std;

const int TABLE_SIZE = 100; // Ukuran tabel hash

class HashTable {
private:
    struct HashNode {
        char* key;
        char* value;
        HashNode* next;
    };

    HashNode* table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    unsigned long hashFunction(const char* str) {
        unsigned long hash = 0;
        for (int j = 0; str[j]; ++j) {
            hash += str[j];
        }
        return hash % TABLE_SIZE;
    }

    void insert(const char* key, const char* value) {
        unsigned long index = hashFunction(key);
        HashNode* newNode = new HashNode;
        newNode->key = new char[strlen(key) + 1];
        newNode->value = new char[strlen(value) + 1];
        strcpy(newNode->key, key);
        strcpy(newNode->value, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    const char* search(const char* key) {
        unsigned long index = hashFunction(key);
        HashNode* current = table[index];
        while (current) {
            if (strcmp(current->key, key) == 0) {
                return current->value;
            }
            current = current->next;
        }
        return "Not found";
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashNode* current = table[i];
            while (current) {
                HashNode* temp = current;
                current = current->next;
                delete[] temp->key;
                delete[] temp->value;
                delete temp;
            }
        }
    }
};
