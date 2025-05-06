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

   