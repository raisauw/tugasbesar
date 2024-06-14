#include <iostream>
#include <iomanip>
#include <conio.h>
#include <queue>
using namespace std;
struct pinjam
{
    string nama;
    string nim;
    string judul;
    string durasi;
    pinjam *next;
};

pinjam *font, *back, *newNode, *cur, *del;

int countAntrian()
{
    int count = 0;
    cur = font;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    return count;
}

bool isEmpty()
{
    return font == NULL;
}

void enqueue(string nama, string nim, string judul, string durasi)
{
    if (isEmpty())
    {
        font = new pinjam();
        font->nama = nama;
        font->nim = nim;
        font->judul = judul;
        font->durasi = durasi;
        font->next = NULL;
        back = font;
    }
    else
    {
        newNode = new pinjam();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->judul = judul;
        newNode->durasi = durasi;
        newNode->next = NULL;
        back->next = newNode;
        back = newNode;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        cur = font;
        font = font->next;
        delete cur;
    }
}

void display(int max)
{
    for (int i = 1; i <= max; i++)
    {
        if (i <= countAntrian())
        {
            cur = font;
            for (int j = 1; j < i; j++)
            {
                cur = cur->next;
            }
            cout << i << ". " << setw(5) << "NAMA  :" << cur->nama << endl;
            cout << " " << setw(9) << "NIM   :" << cur->nim << endl;
            cout << " " << setw(9) << "JUDUL :" << cur->judul << endl;
            cout << " " << setw(9) << "DURASI:" << cur->durasi << endl;
             cout << "====================================="<<endl;
        }
        else
        {
            cout << i << ". (kosong)" << endl;
        }
    }
}
