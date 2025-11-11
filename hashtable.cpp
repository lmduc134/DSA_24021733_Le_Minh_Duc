
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
};

struct HashTable {
    int size;
    Node** table;

    HashTable(int s) {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; i++) table[i] = nullptr;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->key = key;
        newNode->next = nullptr;

        if (!table[index]) {
            table[index] = newNode;
        } else {
            // insert at beginning (chaining)
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* cur = table[i];
            while (cur) {
                cout << cur->key << " -> ";
                cur = cur->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht(10);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(5);
    ht.insert(12);
    ht.display();
    return 0;
}