#include <iostream>
#include <iomanip>
#include <conio.h>
#include <queue>
#include "linked_list.h"
#include "queue.h"
#include "login.h"
using namespace std;

int main()
{
    Perpustakaan list;
    string nama_peminjam, judul_pinjam, judulBuku, namaPenulis, judullama, penulislama, ISBN, ISBNlama;
    string namaPenulisdicari, JudulDicari, ISBNdicari, Durasi, Nim;
    Node *hasil;
    HashTable hash_table;
    int Max=10, pilih, jumlahBuku;
    char username[100];
    char password[100];
        hash_table.insert("Ervan", "2311102206");
        hash_table.insert("Adit", "2311102207");
        hash_table.insert("Raifanka", "2311102205");
        hash_table.insert("Abi", "2311102208");
        login :
        cout << "====================================="<<endl;       
        cout << "|           Silahkan Login          |" <<endl;
        cout << "====================================="<<endl;
        cout << "| Masukan username : ";
        cin  >> username;
        cout << "====================================="<<endl;
        cout << "| Masukan password : ";
        cin  >> password;
        cout << "====================================="<<endl;
        const char *result = hash_table.search(username);
        if (strcmp(result, password)==0){
            cout << "===================="<<endl;
            cout << "|   login sukses  |"<<endl;
            cout << "===================="<<endl;
            cin.ignore();
            cin.ignore();
            system("cls");

           
            while (true)
                {
                cout << endl;
                cout << "====================================="<<endl;
                cout << "|  SELAMAT DATANG DI PERPUSTAKAAN   |"<<endl;
                cout << "====================================="<<endl;
                cout << "| SILAHKAN PILIH MENU YANG TERSEDIA |"<<endl;
                cout << "====================================="<<endl;
                cout << "|1. Tambah Buku "<<setw(21)<< "|"<<endl;
                cout << "|2. Lihat semua Buku "<<setw(16)<< "|"<<endl;
                cout << "|3. Ubah Buku "<<setw(23)<< "|"<<endl;
                cout << "|4. Hapus Buku "<<setw(22)<< "|"<<endl;
                cout << "|5. Pinjam Buku "<<setw(21)<< "|"<<endl;
                cout << "|6. Cari Buku "<<setw(23)<< "|"<<endl;
                cout << "|7. Keluar "<<setw(26)<< "|"<<endl;
                cout << "====================================="<<endl;
                cout << "PILIH MENU: ";
                cin >> pilih;
                system("cls");

                switch (pilih)
                {
                case 1:
                    cout << "====================================="<<endl;
                    cout << "Jumlah Buku Yang Akan Diinput : ";
                    cin >> jumlahBuku;
                    cout << "====================================="<<endl;
                    cin.ignore();
                    for (int i = 0; i < jumlahBuku; i++)
                    {
                        cout << "| Buku " << i + 1 << endl;
                        cout << "| Judul Buku  : ";
                        getline(cin, judulBuku);
                        cout << "| ISBN        : ";
                        getline(cin, ISBN);
                        cout << "| Nama Penulis: ";
                        getline(cin, namaPenulis);
                        cout << "====================================="<<endl;
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
                    cout << "====================================="<<endl;
                    cout << "| Masukan banyak data yang diubah: ";
                    cin >> b;
                    cout << "====================================="<<endl;
                    cin.ignore();
                    for (int i = 0; i < b; i++)
                    {
                        cout << "| Buku Ke - " << i + 1 << endl;
                        cout << "| Data Buku Lama" << endl;
                        cout << "| Judul Buku: ";
                        getline(cin, judullama);
                        cout << "| ISBN: ";
                        getline(cin, ISBNlama);
                        cout << "| Nama Penulis: ";
                        getline(cin, penulislama);
                         cout << "====================================="<<endl;
                        cout << "| Data Buku Baru";
                        cout << "| Judul Buku: ";
                        getline(cin, judulBuku);
                        cout << "| ISBN: ";
                        getline(cin, ISBN);
                        cout << "| Nama Penulis: ";
                        getline(cin, namaPenulis);
                        cout << "====================================="<<endl;
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
                    cout << "====================================="<<endl;
                    cout << "Masukkan buku yang ingin dihapus: ";
                    cin.ignore();
                    getline(cin, judulBuku);
                    cout << "====================================="<<endl;
                    list.hapusbuku(judulBuku);
                    break;

                case 5:
                    int a;
                    int n;
                    do
                    {
                        cout << "=========================="<<endl;
                        cout << "|       MENU PINJAM      |" << endl;
                        cout << "=========================="<<endl;
                        cout << "|1. Masukan Data Peminjam|"<< endl;
                        cout << "|2. List  Peminjam" <<setw(8)<<"|"<< endl;
                        cout << "|3. Layani peminjam" <<setw(7)<<"|" << endl;
                        cout << "|*Tekan 4 untuk ke menu!!|"<<endl;
                        cout << "=========================="<<endl;
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
                                cout << "====================================="<<endl;
                                cout << "|      Data Peminjam Ke - " << i <<"         |"<< endl;
                                cout << "====================================="<<endl;
                                cout << "| Nama Peminjam : ";
                                getline(cin, nama_peminjam);
                                cout << "| Nim           : ";
                                getline(cin, Nim);
                                cout << "| Judul buku    : ";
                                getline(cin, judul_pinjam);
                                cout << "| Durasi Pinjam : ";
                                getline(cin, Durasi);
                                cout << "====================================="<<endl;
                                list.hapusbuku(judul_pinjam);
                                enqueue(nama_peminjam, Nim, judul_pinjam, Durasi);
                                cout << endl;
                            }
                            cin.ignore();
                            system("cls");
                            break;

                        case 2:
                            cout << endl;
                            cout << "====================================="<<endl;
                            cout << "|     Daftar Anterian Peminjam      |" << endl;
                            cout << "====================================="<<endl;
                            display(Max);
                            cin.ignore();
                            break;

                        case 3:
                            dequeue();
                            cout << "====================================="<<endl;
                            cout << "|      Anterian Sudah Dilayani      |"<<endl;
                            cout << "====================================="<<endl;
                            cin.ignore();
                            cin.ignore();
                            break;
                        default:
                            break;
                        }
                    }

                    while (a != 4);
                    break;

                case 6:
                do
                { system("cls");
                    cout << "====================================="<<endl;
                    cout << "|           Cari berdasarkan        |"<<endl;
                    cout << "====================================="<<endl;
                    cout << "|1. nama Buku"<<setw(23)<<"|"<<endl;
                    cout << "|2. ISBN Buku"<<setw(23)<<"|"<<endl;
                    cout << "|3. Penulis Buku"<<setw(20)<<"|"<<endl;
                    cout << "|4. Ke Menu Utama"<<setw(19)<<"|"<<endl;
                    cout << "====================================="<<endl;
                    cout<<"pilihan anda: ";cin >> pilih;

                    if (pilih == 1)
                    {
                        cout << "masukkan nama buku: ";
                        cin.ignore();
                        getline(cin, JudulDicari);
                        Node *hasil;
                        hasil = list.cariBerdasarkanJudul(JudulDicari);
                        if (hasil != NULL)
                        {
                            cout << "Buku dengan judul: " << JudulDicari << " ditemukan!" << endl<<endl;
                            cout << "Data Buku" << endl;
                            cout << "Nama Buku : " << hasil->judulBuku << endl;
                            cout << "Penulis   : " << hasil->namaPenulis << endl;
                            cout << "ISBN      : " << hasil->ISBN << endl;
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
                            cout << "Buku dengan ISBN " << ISBNdicari << " ditemukan: " << endl<<endl;
                            cout << "Data Buku" << endl;
                            cout << "Nama Buku: " << hasil->judulBuku << endl;
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
                        cin.ignore();
                    }
                    else if (pilih == 4)
                    {
                        cout<<"harap tekan tombol enter untuk keluar dari menu pencarian";
                        cin.ignore();
                        cin.ignore();
                    }
                    else
                    {
                        cout<<"Input Tidak Valid";
                        cin.ignore();
                        cin.ignore();
                    }
                }
                while (pilih !=4);
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
        }else{
            cout<<"login gagal"<<endl;
            cin.ignore();
            cin.ignore();
            system("cls");
            goto login;
        }
    
    return 0;
}
