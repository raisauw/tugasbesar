#include <iostream>
#include<iomanip>
#include <ncurses.h>
#include <queue>
using namespace std;

class Node
{
public:
    string judulBuku;
    string ISBN;
    string namaPenulis;
    Node* next;
    Node* prev;
};

class Perpustakaan
{
public:
    Node* head;
    Node* tail;

    Perpustakaan(){
        head = NULL;
        tail = NULL;
    }

    void push(string judulBuku, string ISBN, string namaPenulis){
        Node* newNode = new Node;
        newNode->judulBuku = judulBuku;
        newNode->ISBN = ISBN;
        newNode->namaPenulis = namaPenulis;
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL)
        {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void hapusbuku(string judulBuku){
        Node* hapus = head;
        while(hapus != NULL){
            if(hapus->judulBuku == judulBuku){
                if(hapus == head){
                    head = hapus->next;
                if(head != NULL)
                    head->prev = NULL;
                } else if(hapus == tail){
                    tail = hapus->prev;
                if(tail != NULL)
                    tail->next = NULL;
                } else {
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
    bool update(string judullama,string ISBNlama,string penulislama,string judulbaru,string ISBNbaru,string penulisbaru) {
       Node* current = head;
        while (current != NULL) {
            if (current->judulBuku == judullama && current->ISBN ==ISBNlama && current->namaPenulis==penulislama) {
                current->judulBuku = judulbaru;
                current->ISBN = ISBNbaru;
                current->namaPenulis = penulisbaru;
                return true;
            }
            current = current->next;
        }
        return false;
        }
    Node* cariBerdasarkanJudul(string JudulDicari) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->judulBuku == JudulDicari) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    // Fungsi untuk mencari buku berdasarkan ISBN
    Node* cariBerdasarkanISBN(string ISBNdicari) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->ISBN == ISBNdicari) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    // Fungsi untuk mencari buku berdasarkan nama penulis
void cariBerdasarkanNamaPenulis(string namaPenulisdicari) {
    Node* temp = head;
    bool found = false;
    while (temp != NULL) {
        if (temp->namaPenulis == namaPenulisdicari) {
            cout << "Judul Buku: " << temp->judulBuku << endl;
            cout << "ISBN: " << temp->ISBN << endl;
            cout << "Nama Penulis: " << temp->namaPenulis << endl << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Tidak ada buku yang ditemukan dengan nama penulis tersebut." << endl;
    }
}
    
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout <<endl<< current->judulBuku << " "<<endl;
            cout << current->ISBN << " "<<endl;
            cout << current->namaPenulis << " "<<endl;

            current = current->next;
            }
        cout << endl;
        }
};

struct pinjam {
    string nama;
    string nim;
    string judul;
    string durasi;
    pinjam* next;
};

pinjam* font, * back, * newNode, * cur, * del;

/* Operasi Linked List */
// Penambahnama antrian
// Menghitung jumlah antrian
int countAntrian() {
    int count = 0;
    cur = font;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}
// Mengecek apakah anterian kosong
bool isEmpty() {
    return font == NULL;
}
void enqueue(string nama,string nim,string judul,string durasi) {
    if (isEmpty()) {
        font = new pinjam();
        font->nama = nama;
        font->nim = nim;
        font->judul= judul;
        font->durasi = durasi;
        font->next = NULL;
        back = font;
    } else {
        newNode = new pinjam();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->judul= judul;
        newNode->durasi = durasi;
        newNode->next = NULL;
        back->next = newNode;
        back = newNode;
    }
}

// Penghapusnama nterian
void dequeue(int posisi) {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    }
    else if (posisi < 1 || posisi > countAntrian()){
        cout << "Posisi Tidak Ada" << endl;
    }
    else {
        if(posisi==1){
        cur = font;
        font = font->next;
        delete cur;
        }
        else{
            pinjam* prev = NULL;
            pinjam* cur = font;
            int count = 1;

            while (count < posisi) {
                prev = cur;
                cur = cur->next;
                count++;
            }

            prev->next = cur->next;
            if (cur == back) {
                back = prev;
            }
            delete cur;
        }
    }
    
    
}

//Menampilkan anterian
void display(int max) {
        for (int i = 1 ; i <= max; i++) {
            if (i <= countAntrian()) {
                 cur = font;
                for (int j = 1; j < i; j++) {
                cur = cur->next;
                }
                cout << i << ". " << setw(5) <<"NAMA  :"<<cur->nama << endl;
                cout <<" " << setw(9) <<"NIM   :"<< cur->nim  << endl;
                cout <<" " << setw(9) <<"JUDUL :"<< cur->judul << endl;
                cout <<" " << setw(9) <<"DURASI:"<< cur->durasi << endl;
                cout <<"========================="<<endl;
            } else {
                 cout << i << ". (kosong)" << endl;
        }
    }
}

// Menghapus semua elemen anterian

int main(){
    Perpustakaan list;
    string nama_peminjam,judul_pinjam,judulBuku, namaPenulis,judullama,penulislama,ISBN,ISBNlama;
    string namaPenulisdicari, JudulDicari,ISBNdicari,Durasi,Nim;
    Node* hasil;
    int Max, pilih, jumlahBuku;

    while (true)
    {
        cout << "Text pembukaan\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Lihat semua Buku\n";
        cout << "3. Ubah Buku\n";
        cout << "4. Hapus Buku\n"; 
        cout << "5. Pinjam Buku\n";
        cout << "6. Cari Buku\n";
        cout << "7. Keluar;";
        cout << "Text Pilih Menu: "; cin >> pilih;
        system("clear");
        switch (pilih)
        {
        case 1:
            cout << "\nJumlah buku yang ingin di input: "; cin >> jumlahBuku;
            cin.ignore();
            for (int i = 0; i < jumlahBuku; i++) {
                cout << "\nBuku " << i+1 << endl;
                cout << "Judul Buku: ";
                getline(cin, judulBuku);
                cout << "ISBN: ";
                getline(cin, ISBN);
                cout << "Nama Penulis: ";
                getline(cin, namaPenulis);

                list.push(judulBuku, ISBN, namaPenulis);
            }
            cin.ignore();
            system("clear");
            break;
        case 2:
            list.display();
            break;
        case 3: 
            int b;
            cout << "Masukan banyak data yang diubah: "; cin >> b;
            for ( int i = 0 ; i < b ; i++){
            cout << "Buku Ke - "<< i+1 <<endl;
            cout << "Data Buku Lama"<<endl;
            cout << "Judul Buku: ";
                cin.ignore();
                getline(cin, judullama);
                cout << "ISBN: ";
                cin >> ISBNlama;
                cout << "Nama Penulis: ";
                cin.ignore();
                getline(cin, penulislama);
            cout << endl;
            cout << "Data Buku Lama";
            cout << "Judul Buku: ";
                cin.ignore();
                getline(cin, judulBuku);
                cout << "ISBN: ";
                cin >> ISBN;
                cout << "Nama Penulis: ";
                cin.ignore();
                getline(cin, namaPenulis);
            bool updated = list.update(judullama,ISBNlama,penulislama,judulBuku,ISBN,namaPenulis);
            
            if (! updated ) {
                cout << "Data not found" << endl;
                }}
            system("clear");
        break;
        
    
        case 4:
            cout << "\nMasukkan buku yang ingin dihapus: ";
            cin.ignore();
            getline(cin, judulBuku);
            list.hapusbuku(judulBuku);
            break;
        case 5 :
            
            int a;
            int n;
            cout << "Masukan Jumlah Maksimal Peminjam : "; cin >> Max;
            do{
            cout << "menu pinjam"<<endl;
            cout << "1. Pinjam"<<endl;
            cout << "2. Buku yang di pinjam"<<endl;
            cout << "3. Hapus peminjam"<<endl;
            cout << "Masukan Pilihan : ";cin >> a;
            system("clear");
            switch (a)
            {
            case 1:
                
                cout << "Masukan banyak peminjam : "; cin >> n;
                cin.ignore();
                for (int i = 1 ; i <= n ; i++){
                cout << "data peminjam ke - "<< i  <<endl;
                cout << "nama peminjam : ";
                getline(cin, nama_peminjam);
                cout << "Nim           : ";
                getline(cin, Nim);
                cout << "judul buku    : ";
                getline(cin, judul_pinjam );
                cout << "Durasi Pinjam : ";
                getline(cin, Durasi);
                enqueue(nama_peminjam,Nim,judul_pinjam,Durasi);
                cout << endl;
                }
                cin.ignore();
                system("clear");
                break;
            case 2 : 
                cout << endl;
                cout << "Daftar Buku Yang Dipinjam" << endl;
                cout << "=========================" << endl;
                display(Max);
                cin.ignore();
                
                break;
            case 3 : 
                cout << "Masukan "<<endl;
            default:
                break;
            }}while(a !=3 );
        break;

        case 6:{
            cout << "Cari berdasarkan\n";
            cout << "1. nama Buku\n";
            cout << "2. ISBN Buku\n"; 
            cout << "3. Penulis Buku\n";

            cin  >> pilih;

            if(pilih==1){
                cout<<"masukkan nama buku: ";
                cin.ignore();
                getline(cin, JudulDicari);
                Node* hasil;
                hasil = list.cariBerdasarkanJudul(JudulDicari);
                if (hasil != NULL) {
                    cout << "Buku dengan judul: "<<JudulDicari<<" ditemukan!"<<endl;
                    cout <<"Data buku"<<endl;
                    cout << "nama buku: "<< hasil->judulBuku << endl;
                    cout << "penulis: "<<hasil->namaPenulis<< endl;
                    cout << "isbn: "<<hasil->ISBN<< endl;
                    } 
                
                else {
                    cout << "Buku tidak ditemukan." << endl;
                }
            }

            else if (pilih==2){
                cout << "\nMasukkan ISBN buku yang ingin dicari: ";
                cin >> ISBNdicari;
                hasil = list.cariBerdasarkanISBN(ISBNdicari);
                if (hasil != NULL) {
                    cout << "Buku dengan ISBN " << ISBNdicari << " ditemukan: " << endl;
                    cout << "Data buku"<<endl;
                    cout << "nama buku: "<< hasil->judulBuku << endl;
                    cout << "penulis: "<<hasil->namaPenulis<< endl;
                    cout << "ISBN: "<<hasil->ISBN<< endl;
                    }
                     
                else {
                    cout << "Buku dengan ISBN " << ISBNdicari << " tidak ditemukan." << endl;
                }
            }

            else if (pilih==3){
                cout << "\nMasukkan nama penulis yang ingin dicari: ";
                cin.ignore();
                getline(cin, namaPenulisdicari);
                list.cariBerdasarkanNamaPenulis(namaPenulisdicari);

            } 
            

            else{
                cout<<"input tidak valid";
            }
            break;}

        case 7: exit (0);

        default:
            cout << "text salah input\n\n";
            break;
        

        }
    }
    return 0;
}
