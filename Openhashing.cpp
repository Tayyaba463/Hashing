
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int size = 10;
Node HT[10];

void initializing() {
    for (int i = 0; i < size; i++) {
        HT[i].data = -1;
        HT[i].next = NULL;
    }
}

void insertValue(int value) {

    int index = value % size;
    if (HT[index].data == -1) {
        HT[index].data = value;
        return;
    }
   
    Node* temp = (Node*) malloc(sizeof(Node));  
    temp->data = value;
    temp->next = NULL;
    if (HT[index].next == NULL) {
        HT[index].next = temp;
        return;
    }
    Node* current = HT[index].next;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}

void search (int value) {
    
    int index = value % size;

    if (HT[index].data == -1) {
        cout << "Value not found." << endl;
        return;
    }

    Node *current = HT[index].next;

    while (current != NULL) {
        if (HT[index].data == value) {
            cout << "value founded." << endl;
            return;
        }
        if (current->data == value) {
            cout << "Value found.";
            return;
        }
        current->next = current;
    }
}

void displaydata() {

    for (int i = 0; i < size; i++) {
        cout << "Index " << i << "1: ";
        cout << HT[i].data << " ";
        Node* current = HT[i].next;

        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}


int main() {

    int num, value;
     initializing();

    while (true) {

        cout << "\n1. Insert value" << endl;
        cout << "2. Display Data" << endl;
        cout << "3. search data." << endl;
        cout << "4. Exit" << endl;

        cin >> num;

        if (num == 1) {
            cout << "Insert value: ";
            cin >> value;
            insertValue(value);
        }
        else if (num == 2) {
            displaydata();  
        }
        else if (num == 3) {
         cout << "ENter value to search." << endl;
         cin >> value;
         search(value);
        }
        else if (num == 4) {
            cout << "You have successfully exited." << endl;
            break;  
        }
        else {
            cout << "Invalid Option" << endl;
        }
    }
}

