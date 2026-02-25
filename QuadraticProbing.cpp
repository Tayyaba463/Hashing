#include <iostream>
using namespace std;

#define size 11

struct Node
{
    int data;
    Node* next;
};


Node* hashtable[size];

void insertData (int value)
{
    int originalIndex = value % size;
    int index = originalIndex;
    int i  = 0;

    while (i < size && hashtable[index] != NULL) 
     {
        index = (originalIndex + i * i) % size;

        if (hashtable[index] == NULL)
        break;

        i++;
     }
     if (i == size)
     {
        cout << "Hashtable Overflow." << endl;
        return;
     }

     Node* temp  = (Node*) malloc (sizeof(Node));
     temp->data = value;
     temp->next = NULL;
     hashtable[index] = temp;
   }
  
void search (int value)   
{
   int originaLindex = value % size;
   int index = originaLindex;
   int i = 0;
   
    while (i < size && hashtable[index] != NULL)
    {
       if (hashtable[index]->data == value)
      {
         cout << "Value founded Successfully." << endl;
         return;
      }
       i++;
      index = (originaLindex + i * i) % size;
    
    }

   cout << "Value not present in table." << endl;
}

void display ()
{
   for (int i = 0; i < size; i++)
   {
      cout << i << " -> ";
      if (hashtable[i] == NULL)
      {
         cout << "-1 ";
      }

      if (hashtable[i] != NULL)
      {
         cout << hashtable[i]->data << " ";
      }
      cout << endl;
   }
}

int main ()
{
   int num, value;

   while (true) {
 
      cout << "1. Insert Value. " << endl;
      cout << "2. Search Value. " << endl;
      cout << "3. Display All Values. " << endl;
      cout << "4.Exit." << endl;

      cin >> num;

      if (num == 1)
      {
         cout << "Enter value to insert. ";
         cin >> value; 
            insertData(value);
      }

      else if (num == 2)
      {
         cout << "Enter value to search. ";
         cin >> value;
         search(value); 
      }

      else if (num == 3)
      {
         display();
      }
      else if (num == 4)
      {
         cout << "Exited Successfully." << endl;
      }

      cout << "Enter Wrong Choice." << endl;
   }
 return 0;
}

