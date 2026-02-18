#include <iostream>
using namespace std;

#define SIZE 10

struct Node {
    int key;
    Node* next; 
};

Node* hashTable[SIZE];

void insert(int key) {
    int index = key % SIZE;
    int start = index;

    while (hashTable[index] != NULL) {
        index = (index + 1) % SIZE;
        if (index == start) {
            cout << "Hash Table Overflow" << endl;
            return;
        }
    }

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->next = NULL; 
    hashTable[index] = temp;

    cout << key << " inserted at index " << index << endl;
}

void search(int key) {
    int index = key % SIZE;
    int start = index;

    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            cout << key << " found at index " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) break;
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
