#include <iostream>
using namespace std;

#define size 10

struct Node
{
    int key;
    Node *next;
};

Node* hashTable[size];

void insertData (int data)
{
    int index = data % size;
    int start = index;

     while (hashTable[index] != NULL)
      {
         index = (index + 1) % size;
           if (index == start)
            {
                cout << "Hashtable Overflow." << endl;
                return;
            }
      }

      Node* temp = (Node*) malloc (sizeof(Node));
      temp->key = data;
      temp->next = NULL;
      hashTable[index] = temp;
      
      cout << data << "  Insert at index number. -> " << index << endl;
      return;

 }

 void search (int data)
  {
     int index = data % size;
     int start = index;

      while (hashTable[index] != NULL)
       {
         if (hashTable[index]->key == data)
          {
             cout << data << "  Founded at index. ->" << index << endl;
             return;
          }
          index = (index + 1) % size;
          if (start == index) break;
       }

       cout << "Value not Founded." << endl;
  }

  void display () 
   {
      for (int i = 0; i < size; i++) 
      {
         if (hashTable[i] != NULL) 
          {
            cout << i << "->" << hashTable[i]->key << endl;
          }
         else if (hashTable[i] == NULL) 
          {
            cout << i << "->" << "-1" << endl;
          }
      }
   }

int main ()
 {
     int number, value;

      while (true)
       {
         cout << "1.Insert value." << endl;
         cout << "2.Search value." << endl;
         cout << "3.Display complete table." << endl; 

         cin >> number;

         if (number == 1)
         {
            cout << "Insert value.";
            cin >> value; 
             insertData(value);
         }
         else if (number == 2)
          {
             cout << "search value.";
              cin >> value;
              search(value);
          }
          else if (number == 3) 
          {
            display();
          }
       }
     return 0;
 }
