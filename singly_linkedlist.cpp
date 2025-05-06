#include <iostream>
#include <string.h>
using namespace std;

class Node
{
   public:
   int noMhs;
   Node *next;
};

class Linkedlist
{
    Node *START = NULL;

    public:
    Linkedlist()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomer Mahasiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if((START != NULL) && (nim == START->noMhs))
            {
              cout << "\nDuplikasi noMhs tidak diijinkan\n";
              return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }
        Node *previous = START;
        Node *current = START;

      

