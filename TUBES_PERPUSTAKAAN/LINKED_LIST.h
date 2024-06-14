#include <iostream>
#include <iomanip>
#include <conio.h>
#include <queue>
using namespace std;
class Node
{
public:
    string judulBuku;
    string ISBN;
    string namaPenulis;

    Node *next;
    Node *prev;
};

class Perpustakaan
{
public:
    Node *head;
    Node *tail;

    Perpustakaan()
    {
        head = NULL;
        tail = NULL;
    }

    void push(string judulBuku, string ISBN, string namaPenulis)
    {
        Node *newNode = new Node;
        newNode->judulBuku = judulBuku;
        newNode->ISBN = ISBN;
        newNode->namaPenulis = namaPenulis;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }

    void hapusbuku(string judulBuku)
    {
        Node *hapus = head;

        while (hapus != NULL)
        {
            if (hapus->judulBuku == judulBuku)
            {
                if (hapus == head)
                {
                    head = hapus->next;
                    if (head != NULL)
                        head->prev = NULL;
                }
                else if (hapus == tail)
                {
                    tail = hapus->prev;
                    if (tail != NULL)
                        tail->next = NULL;
                }
                else
                {
                    hapus->prev->next = hapus->next;
                    hapus->next->prev = hapus->prev;
                }
                delete hapus;
                return;
            }
            hapus = hapus->next;
        }
        cout << "Buku tidak ditemukan\n";
    }

    bool update(string judullama, string ISBNlama, string penulislama, string judulbaru, string ISBNbaru, string penulisbaru)
    {
        Node *current = head;

        while (current != NULL)
        {
            if (current->judulBuku == judullama && current->ISBN == ISBNlama && current->namaPenulis == penulislama)
            {
                current->judulBuku = judulbaru;
                current->ISBN = ISBNbaru;
                current->namaPenulis = penulisbaru;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    Node *cariBerdasarkanJudul(string JudulDicari)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->judulBuku == JudulDicari)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    Node *cariBerdasarkanISBN(string ISBNdicari)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->ISBN == ISBNdicari)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void cariBerdasarkanNamaPenulis(string namaPenulisdicari)
    {
        Node *temp = head;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->namaPenulis == namaPenulisdicari)
            {
                cout <<endl<< "Judul Buku  : " << temp->judulBuku << endl;
                cout << "ISBN        : " << temp->ISBN << endl;
                cout << "Nama Penulis: " << temp->namaPenulis << endl;
                cout << "=====================================" << endl;
                cout << endl;
                found = true;
            }
            temp = temp->next;
        }

        if (!found)
        {
            cout << "Tidak ada buku yang ditemukan dengan nama penulis tersebut." << endl;
        }
    }

    void display()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << endl; 
            cout <<"Judul Buku  :"<< current->judulBuku << " " << endl;
            cout <<"ISBN        :" <<current->ISBN << " " << endl;
            cout <<"Nama Penulis:" <<current->namaPenulis << " " << endl;
            cout << "=====================================" << endl;

            current = current->next;
        }
        cout << endl;
    }
};