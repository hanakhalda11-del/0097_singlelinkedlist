#include <iostream>
#include <string> 
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
};
class LinkedList
{
private:
    Node *START;

public:
    LinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;
        nodeBaru->next = NULL;

        if (START == NULL || nim < START->noMhs)
        {
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node *current = START;
        Node *previous = NULL;

        while (current != NULL && nim > current->noMhs)
        {
            previous = current;
            current = current->next;
        }

        if (current != NULL && nim == current->noMhs)
        {
            cout << "\nDuplikasi tidak diizinkan!\n";
            delete nodeBaru;
            return;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

