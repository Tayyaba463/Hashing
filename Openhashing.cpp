#include <iostream>
using namespace std;

#define size 10

struct Node
{
    int data = -1;
    Node *next = NULL;
};

Node hashtable[size];

void insertData (int value)
{
   int index = value % size;

   if (hashtable[index].data == -1)
   {
      hashtable[index].data = value;
      return; 
 }

  Node *temp = new Node;
  temp->data = value;
  temp->next = NULL;
  if (hashtable[index].next == NULL)
  {
    hashtable[index].next = temp;
    return;
  }
 else {
  Node *current = hashtable[index].next;

  while (current->next != NULL)
  {
    current = current->next;
  }
  current->next = temp;
}
}

void searchData (int value)
{
    int index = value % size;

    if (hashtable[index].data == -1)
    {
        cout << "The hashtable is missing the value." << endl;
        return;
    }

    Node *current = hashtable[index].next;
    while (current != NULL)
    {
        if (current->data == value)
        {
            cout << "value founded." << endl;
            return;
        }
        current = current->next;
    }

    cout << "Value not Found." << endl; 
}

void display ()
{
   for (int i = 0; i < size; i++)
   {
    cout << "Index -> " << i << "1: ";
    cout << hashtable[i].data << " ";
    Node *current = hashtable[i].next;

    while (current != NULL)
    {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
   }
}

int main() {

    int num, value;

    while (true) {

        cout << "1. Insert." << endl;
        cout << "2. Display." << endl;
        cout << "3. Search." << endl;
        cout << "4. Exit." << endl;

        cin >> num;

        if (num == 1) {
            cout << "Insert value: ";
            cin >> value;
            insertData(value);
        }
        else if (num == 2) {
            display();  
        }
        else if (num == 3) {
         cout << "ENter value to search." << endl;
         cin >> value;
         searchData(value);
        }
        else if (num == 4) {
            cout << "You have successfully exited." << endl;
        }
        else {
            cout << "Invalid Option" << endl;
        }
    }
   return 0;
}



