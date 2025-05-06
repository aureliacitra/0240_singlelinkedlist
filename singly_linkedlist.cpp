#include <iostream>
#include <string.h>
using namespace std;

class node 
{
public : 
    int nomhs;
    node *next;
};

class linkedlist 
{
    node *start ;

public: 
    linkedlist ()
    {
        start = NULL;
    }

    void addnode()
    {
        int nim;
        cout << "\nmasukkan nomor mahasiswa: ";
        cin >> nim;

        node *nodebaru = new node;
        nodebaru -> nomhs = nim;

        if (start == NULL || nim <= start -> nomhs)
        {
            if ((start != NULL) && (nim == start -> nomhs))
            {
                cout<< "\nduplikat nomhs tidak diijinkan\n";
                return;
            }
            nodebaru -> next = start;
            start = nodebaru;
            return;
        }
        node *previous = start;
        node *current = start;

        while ((current != NULL ) && (nim >= current -> nomhs))
        {
            if (nim == current -> nomhs)
            {
                cout << "\nduplikat nomhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current -> next;
        }

        nodebaru -> next = current;
        previous -> next = nodebaru;
    }

    bool listempty()
    {
        return (start == NULL);
    }

    bool search(int nim, node **previous, node **current)
    {
        *previous = start;
        *current = start;
        while ((*current != NULL) && (nim != (*current) -> nomhs))
        {
            *previous = *current;
            *current = (*current)->next;
         }

         return (*current != NULL);
    }

    bool delnode(int nim)
    {
        node *current, *previous;
        if (!search(nim, &previous, &current))
            return false;

        if (current == start)
            start = start->next;
        else    previous -> next = current -> next;

        delete current;
        return true;
    }

    void traverse()
    {
        if (listempty())
        {
            cout<< "\nlist kosongan\n";
        }
        else
        {
            cout << "\ndata di dalam list adalah:\n";
            node *currentnode = start;
            while (currentnode != NULL)
            {
                cout << currentnode -> nomhs << endl;
                currentnode = currentnode -> next;
            }
            cout << endl;
        }
    }
};

int main ()
{
    linkedlist mhs;
    int nim;
    char ch;
    while (1)
    {
        cout << endl
            << "menu";
        cout << endl
             << "1. menambah data kedalam list" << endl;
        cout << "2. menghapus data dari dalam list" << endl;
        cout << "3. menampilkan semua data dari dalam list" << endl;
        cout << "4. mencari data dalam list" << endl;
        cout << "5. keluar" << endl;
        cout << endl
            << "masukkan pilihan (1-5): ";

        cin >> ch;
        switch (ch)
        {
            case '1' :
        {
            mhs.addnode();
        }
        
        break;

        case '2':{
            if (mhs.listempty())
            {
                cout << endl
                    << "list kosong" << endl;
                    break;
            }
            cout << endl    
                << "\nmasukkan no mahasiswa yang akan di hapus : ";
            cin >> nim;
            if (mhs.delnode(nim) == false)
                cout << endl
                    << "data tidak ditemukan" << endl;
                else 
                cout <<  endl   
                    << "data dengan nomor mahasiswa" << nim << "berhasil dihapus " << endl;
                    break;
        }
        
        case '3':
        {
            mhs.traverse();
            break;
        }
        
        case '4':
        {
            if (mhs.listempty() == true)
            {
                cout << "\nlist kososng\n";
                break;
            }
            node *previous, *current;
            cout << endl
                << "masukkan no mahasiswa yang dicari : ";
            cin >> nim;
            if (mhs.search(nim, &previous, &current)== false)
                cout << endl
                    << "data tidak ditemukan " << endl;
                else
                {
                    cout << endl    
                        << "data ditemukan" << endl;
                    cout << "\nno mahasiswa : " << current->nomhs << endl;
                    cout << "\n";
                }
                break;
        }
       
        case '5':
        {
            exit(0);
        }
        break;
        default:
        {
            cout << "pilihan salah !." << endl;
        }
        break;
    }
}
}