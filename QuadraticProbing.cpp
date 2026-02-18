#include <iostream>
#include <stdlib.h>
using namespace std;

#define SIZE 10

struct Node {
    int key;
    Node* next; 
};

Node* hashTable[SIZE] = {NULL};

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < SIZE && hashTable[(index + i * i) % SIZE] != NULL) {
        i++;
    }

    if (i == SIZE) {
        cout << "Hash Table Overflow" << endl;
        return;
    }

    int finalIndex = (index + i * i) % SIZE;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->next = NULL; 
    hashTable[finalIndex] = temp;

    cout << key << " inserted at index " << finalIndex << endl;
}

void search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < SIZE && hashTable[(index + i * i) % SIZE] != NULL) {
        int finalIndex = (index + i * i) % SIZE;
        if (hashTable[finalIndex]->key == key) {
            cout << key << " found at index " << finalIndex << endl;
            return;
        }
        i++;
    }

    cout << key << " not found in hash table" << endl;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL)
            cout << i << " -> " << hashTable[i]->key << endl;
        else
            cout << i << " -> " << "-1" << endl;
    }
}

int main() {
    int choice, key;

    while (true) {
        cout << "1.Insert." << endl;
        cout << "2.Search." << endl;
        cout << "3.Display-ALL." << endl;
        cout << "4.Exit." << endl;

        cin >> choice;

        if (choice == 1) {
            cout << "Enter key to insert: ";
            cin >> key;
            insert(key);
        }
        else if (choice == 2) {
            cout << "Enter key to search: ";
            cin >> key;
            search(key);
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            cout << "Exiting program." << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL) free(hashTable[i]);
    }

    return 0;
}