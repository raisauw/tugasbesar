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
                cout << "Judul Buku  : " << temp->judulBuku << endl;
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
            cout << "=========================" << endl;
        }
        else
        {
            cout << i << ". (kosong)" << endl;
        }
    }
}

int main()
{
    Perpustakaan list;
    string nama_peminjam, judul_pinjam, judulBuku, namaPenulis, judullama, penulislama, ISBN, ISBNlama;
    string namaPenulisdicari, JudulDicari, ISBNdicari, Durasi, Nim;
    Node *hasil;
    int Max=0, pilih, jumlahBuku;

    cout << "\nSELAMAT DATANG DI PERPUSTAKAAN\n";

    while (true)
    {
        cout << "SILAHKAN PILIH MENU YANG TERSEDIA\n\n";
        cout << "=========================\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Lihat semua Buku\n";
        cout << "3. Ubah Buku\n";
        cout << "4. Hapus Buku\n";
        cout << "5. Pinjam Buku\n";
        cout << "6. Cari Buku\n";
        cout << "7. Keluar\n";
        cout << "=========================\n\n";
        cout << "PILIH MENU: ";
        cin >> pilih;
        system("cls");

        switch (pilih)
        {
        case 1:
            cout << "\nJumlah buku yang ingin di input: ";
            cin >> jumlahBuku;
            cin.ignore();
            for (int i = 0; i < jumlahBuku; i++)
            {
                cout << "\nBuku " << i + 1 << endl;
                cout << "Judul Buku  : ";
                getline(cin, judulBuku);
                cout << "ISBN        : ";
                getline(cin, ISBN);
                cout << "Nama Penulis: ";
                getline(cin, namaPenulis);
                list.push(judulBuku, ISBN, namaPenulis);
            }
            cin.ignore();
            system("cls");
            break;

        case 2:
            list.display();
            break;

        case 3:
            int b;
            cout << "Masukan banyak data yang diubah: ";
            cin >> b;
            cin.ignore();
            for (int i = 0; i < b; i++)
            {
                cout << "Buku Ke - " << i + 1 << endl;
                cout << "Data Buku Lama" << endl;
                cout << "Judul Buku: ";
                getline(cin, judullama);
                cout << "ISBN: ";
                getline(cin, ISBNlama);
                cout << "Nama Penulis: ";
                getline(cin, penulislama);
                cout << endl;
                cout << "Data Buku Lama";
                cout << "Judul Buku: ";
                getline(cin, judulBuku);
                cout << "ISBN: ";
                getline(cin, ISBN);
                cout << "Nama Penulis: ";
                getline(cin, namaPenulis);
                bool updated = list.update(judullama, ISBNlama, penulislama, judulBuku, ISBN, namaPenulis);
                cout << endl;
                if (!updated)
                {
                    cout << "Data not found" << endl;
                }
            }
            system("cls");
            break;

        case 4:
            cout << "\nMasukkan buku yang ingin dihapus: ";
            cin.ignore();
            getline(cin, judulBuku);
            list.hapusbuku(judulBuku);
            break;

        case 5:
            int a;
            int n;
            cout << "Masukan Jumlah Maksimal Peminjam : ";
            cin >> Max;
            do
            {
                cout << "menu pinjam" << endl;
                cout << "1. Masukan Data Peminjam" << endl;
                cout << "2. List  Peminjam" << endl;
                cout << "3. Hapus peminjam" << endl;
                cout << "*Tekan 4 untuk ke menu!!"<<endl;
                cout << "Masukan Pilihan : ";
                cin >> a;
                system("cls");

                switch (a)
                {
                case 1:

                    cout << "Masukan banyak peminjam : ";
                    cin >> n;
                    cin.ignore();
                    for (int i = 1; i <= n; i++)
                    {
                        cout << "data peminjam ke - " << i << endl;
                        cout << "nama peminjam : ";
                        getline(cin, nama_peminjam);
                        cout << "Nim           : ";
                        getline(cin, Nim);
                        cout << "judul buku    : ";
                        getline(cin, judul_pinjam);
                        cout << "Durasi Pinjam : ";
                        getline(cin, Durasi);
                        list.hapusbuku(judul_pinjam);
                        enqueue(nama_peminjam, Nim, judul_pinjam, Durasi);
                        cout << endl;
                    }
                    cin.ignore();
                    system("cls");
                    break;

                case 2:
                    cout << endl;
                    cout << "Daftar Buku Yang Dipinjam" << endl;
                    cout << "=========================" << endl;
                    display(Max);
                    cin.ignore();
                    break;

                case 3:
                    dequeue();
                    break;
                default:
                    break;
                }
            }

            while (a != 4);
            break;

        case 6:
        do
        {   system("cls");
            cout << "Cari berdasarkan\n";
            cout << "1. nama Buku\n";
            cout << "2. ISBN Buku\n";
            cout << "3. Penulis Buku\n";
            cout << "4. ke menu utama\n";
            cout << "pilihan anda: ";cin >> pilih;

            if (pilih == 1)
            {
                cout << "masukkan nama buku: ";
                cin.ignore();
                getline(cin, JudulDicari);
                Node *hasil;
                hasil = list.cariBerdasarkanJudul(JudulDicari);
                if (hasil != NULL)
                {
                    cout << "Buku dengan judul: " << JudulDicari << " ditemukan!" << endl;
                    cout << "Data buku" << endl;
                    cout << "nama buku : " << hasil->judulBuku << endl;
                    cout << "penulis   : " << hasil->namaPenulis << endl;
                    cout << "isbn      : " << hasil->ISBN << endl;
                    cout << "=====================================" << endl;
                }
                else
                {
                    cout << "Buku tidak ditemukan." << endl;
                }
                cin.ignore();
            }

            else if (pilih == 2)
            {
                cout << "\nMasukkan ISBN buku yang ingin dicari: ";
                cin >> ISBNdicari;
                hasil = list.cariBerdasarkanISBN(ISBNdicari);
                if (hasil != NULL)
                {
                    cout << "Buku dengan ISBN " << ISBNdicari << " ditemukan: " << endl;
                    cout << "Data buku" << endl;
                    cout << "nama buku: " << hasil->judulBuku << endl;
                    cout << "penulis  : " << hasil->namaPenulis << endl;
                    cout << "ISBN     : " << hasil->ISBN << endl;
                    cout << "=====================================" << endl;
                }
                else
                {
                    cout << "Buku dengan ISBN " << ISBNdicari << " tidak ditemukan." << endl;
                }
                cin.ignore();
                cin.ignore();
            }

            else if (pilih == 3)
            {
                cout << "\nMasukkan nama penulis yang ingin dicari: ";
                cin.ignore();
                getline(cin, namaPenulisdicari);
                list.cariBerdasarkanNamaPenulis(namaPenulisdicari);
                cin.ignore();
            }
            else if (pilih == 4)
            {
                cout << "tekan enter untuk keluar dari menu pencarian";
                cin.ignore();
                cin.ignore();
            }
            else 
            {
                cout << "input tidak valid";
                cin.ignore();
                cin.ignore();
            } 
        }
        while (pilih != 4);
        system("cls");
        break;

        case 7:
            cout << "\nTERIMA KASIH TELAH MENGUNJUNGI PERPUSTAKAAN!\n";
            exit(0);

        default:
            cout << "Input Tidak Valid!\n\n";
            break;
        }
    }
    return 0;
}
